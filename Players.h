/*
 * Players.h
 *
 *  Created on: Apr 9, 2018
 *      Author: Ben
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include "CardDeck.h"
//constant parameters
const  int initCasinoPlayerBet = 1;
const  int initCalculatedPlayerBet = 20;
const  int BJ = 21;

class BasicPlayer
{
protected:
	CardDeck _hand;
public:
	enum PlayerMove
	{
		HIT, STAND
	};
	//defualt constarctor
	BasicPlayer()=default;
	//virtual destractor for heritage
	virtual ~BasicPlayer()=default;
	//@return player Deck Value
	//calculated by given function the CardDeck
	unsigned int playerDeckValue() const
	{
		return _hand.value();
	}
	//@return unsigned int-for number of cards in deck
	unsigned int playerDeckSize() const
	{
		return _hand.getDecksize();
	}
	//clear all cards from player's hand
	void playerClearDeck()
	{
		_hand.getCards().clear();
	}
	//add to a given player a new card to deck
	//@param const Card& card-card to be added
	void playerAddCard(const Card& card)
	{
		CardDeck temp(card);
		_hand+=temp;
	}
	//this function returns the player's decision for the next move
	//depending on his  cards value and dealer exposed card
	//virtual function for heritage class's
	//@return PlayerMove
	virtual PlayerMove playerChoise(const Card& DealerCard)const;
};

//Class Dealer is drived from Class Player
//just a separate class to distinguish the dealer
class Dealer: public BasicPlayer
{
public:
	// defualt constructor for dealer
	//player id and player initial budget initialized by the value 0

	Dealer() : BasicPlayer(){}

	/* Destructor*/
	 ~ Dealer() throw() {}

};


class Player: public BasicPlayer
{
protected:
	int _id;
	int _budget;
	int _currentBet;

	//protected member function
	//@param int gievn amount to add/remove from corrent player budget
	//if the player have BJ the amound is incresed by 50%
	void updatePlayerBudget(int amount);

public:
	//defualt constractor for player init obj with a basic class constractor
	//constrctor gets int id,int player budget,int correntbet
	Player(int id, int budget, int currentBet) :
			_id(id), _budget(budget), _currentBet(currentBet){}

	//virtual destractor for heritage
	virtual ~Player() throw() {}

	//inlineFunctions geter
	int playerGetBudget() const
	{
		return _budget;
	}
	int playerGetId() const
	{
		return _id;
	}
	//virtual functions for diffrent player Type (CASINO\CALCULATED)
	virtual void lose()=0;
	virtual void win()=0;
	virtual void leave()=0;

};

class CasinoPlayer : public Player{
public:
	//defualt constactor for CasinoPlayer
	//init by given player id & budget
	//init bet is a const (initCasinoPlayerBet)
	CasinoPlayer(int id, int budget) :
			Player(id, budget, initCasinoPlayerBet){}


	//default destractor
	~CasinoPlayer() throw() {}

	//when a CasinoPlayer loss he doubles his current bet
	//any given bet is subtracted from player budget
	void lose() override {
		_budget-=_currentBet;
		_currentBet*=2;
	}
	//when a CasinoPlayer wins a round the current bet will be set to
	//default value(initCasinoPlayerBet)
	//if the corrent hand is a BJ the amound is icreased by 50%
	void win() override {
		updatePlayerBudget(_currentBet);
		_currentBet=1;
	}
	//sets defualt value for currentbet to a CasinoPlayer
	void leave() override
	{
		_currentBet = 1;
	}
};

class CalculatedPlayer: public Player
{
public:
	//defualt constactor for CalculatedPlayer
	//init by given player id & budget
	//init bet is a const (initCalculatedPlayerBet)
	CalculatedPlayer(int id, int budget) :
			Player(id, budget, 20)
	{
	}
	//default destracor
	~CalculatedPlayer() throw() {}
	//for a claculatedPlayer each time the player loss
	//the currentbet value decreases by 1 when 1 is the limit
	//each bet is subtracted from a players budget
	void lose() override {
		updatePlayerBudget(-_currentBet);
//		_budget-=_currentBet;
		if(_currentBet>1)
			_currentBet-=1;
	}
	//for a claculatedPlayer each time the player wins
	//the currentbet value increases by 1
	//each bet is added to a players budget
	//if the Player has a BJ an additional 50% value is added
	void win() override{
		updatePlayerBudget(_currentBet);
//		_budget+=_currentBet;
		_currentBet+=1;
	}
	void leave() override{
	    _currentBet=20;//TODO changed here (was empty)
		return;
	}
	//this func checks if the player currentley has a Ace in his hand
	//@return bool- true if he has a Ace else false;
	bool calculatedPlayerHasAce()const;
	//the following function is calculated by the next statments and input
	//divided to two parts, player has a Ace or not
	//case(Ace)
	//if the Ace value is 11 and total value is 18 or greater than the player
	// will STAND else the player will HIT
	//if the Ace value is 1 and total value is 12 && dealer's card is
	//(4||5||6) or the total value is 13-16 and dealer has (2-6) or
	//player hand value is 17 or greater the player will STAND
	//else the player will HIT
	//@param Card&- is the dealers card
	//@return HIT/STAND
	PlayerMove playerChoise(const Card& DealerCard)const;
};
#endif /* PLAYERS_H_ */
