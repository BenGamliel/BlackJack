/*
 * BlackJack.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Ben
 */

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "Players.h"
#include "Exceptions.h"
#include "CardDeck.h"
#include <map>
#include <vector>
#include <list>

using std::vector;
using std::map;
using std::istream;
using std::ostream;
using namespace std;
using namespace mtm;

class BlackJack
{
public:
	enum PlayerStrategy
	{
		CASINO, CALCULATED
	};
	////default constractor gets a CardDeck
	BlackJack(const CardDeck& deck);
	//default destractor
	~BlackJack();
	//changes the corrent Deck with a given deck
	void reloadDeck(const CardDeck& deck);
	//add a player to the casino
	//int id is the player id, playerStrategy , int budget- player's budget
	//if the player is already in the system throw PlayerAlreadyExsitExcpetion
	//@param int id-player id
	//@param PlayerStrategy strategy- players strategy
	//@param in budget-player's budget
	void addPlayer(int id, PlayerStrategy strategy, int budget);
	//add a player to next round with a given id
	//if the player doesnot exist throw PlayerDoesNotExistException
	//if the player is already going to be in the next round, nothing happen
	//the player will play in the next round until ext func will stop it
	//@param int id-player id
	void joinGame( int id);
	//same function only for a "bunch" of players
	// if one player does not exist all the players wont join the next round
	// and throw PlayerDoesNotExistException
	//@param int id- player id
	void joinGame(const vector<int>& id);
	//removes a given player by id from next round
	//if player id does not exist throw PlayerDoesNotExistException
	//if the player isnt going to be in the next round nothing happen
	//@param vector<int> id-players id
	void leaveGame(int id);
	//removes all players with the given id in the vector
	//if one of the player doesnt exist throw PlayerDoesNotExistExecption
	//and doesnt remove any of the other players in the vector
	//@param int id-player id
	void leaveGame(const vector<int>& id);
	//plays a round in the game
	//if in the given deck not all of the posibale cards appear
	//throw NotEnoughCardsException
	//if there are no players in the game nothing happens
	//@param vector<int> id-players id
	void playRound();
	//return the corrent sum of the asking player
	//if there is no player with the given id throw PlayerDoesNotExistException
	//@paran int id-player id
	int getBalance(int id);
	//return the id of a player with the highest balance in the casino
	//if there are more than one with the same balance return player
	//with the lower id number
	//if there are no players in the casino throw NoPlayersException
	int getRichest()const;
	//check if the player is already in the possiblePlayers list
	//@return true-else return false
	bool playerInCasino(int id,map<int,Player*>::iterator begin,
			map<int,Player*>::iterator end);

	bool playerInRound(int id, list<int>::iterator begin,
			list<int>::iterator end);

	Card startRound();

	void endRound();
private:
	map<int, Player*> _possiblePlayers;
	Dealer _dealer;
	CardDeck _gameDeck;
	list<int> _playersInGame;

	//this function deal Cards from gameDeck to all the players in this round
	//@param const list<int>& players-players id in this round
	//@return void
	void dealCards( list<int> &players);
	//this function deals a card to all the players orderd by the first
	//player to join and etc than deal a card to the Dealer
	//and repeat.
	//@return the exposed card(first) that was dealt to the dealer
	Card StartTheRound();
	//this function will "check" all players card value
	//the players with card value greater than 21 -lose
	//player with less than 21 and higher than the dealer -win
	//players with BJ win unless the dealer has a BJ which means noting will
	//be done and the rest loss
	//if the player has a equal value to the dealer-nothing will happen
	void endTheRound();
	//this function check players status- if the player STAND or has
	//card value greater than 21 (lost) are removed from the
	//players list corrently in this round
	//@param list<int>& remainingPlayers in the current round
	//@param Card& dealerCard- the corrently exposed dealer's card
	void correntRemainingPlayers(list<int>& remainingPlayers, Card& dealerCard);
};


#endif /* BLACKJACK_H_ */
