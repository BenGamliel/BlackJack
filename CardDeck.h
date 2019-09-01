/*
 * CardDeck.h
 *
 *  Created on: Apr 3, 2018
 *      Author: Ben
 */
#ifndef CARDDECK_H
#define CARDDECK_H

#include "Card.h"
#include "Exceptions.h"
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>
using std::list;
using std::istream;
using std::ostream;
using namespace std;
using namespace mtm;

class CardDeck
{
public:
	//default constractor
	CardDeck()=default;
	//default destractor
	~CardDeck() = default;
	//copyConstractor for CardDeck
	CardDeck(const CardDeck& deck)
	{
		for (int i = 0; i < 14; i++)
		{
			_heart[i] = 0;
			_club[i] = 0;
			_spade[i] = 0;
			_dimonad[i] = 0;
		}
		*this += deck;
	}

	//this static func return a fullDeck orginasied by in an order
	// Heart-Ace to King
	//Diamond-Ace to King
	//Club-Ace to King
	//Space-Ace to King
	static CardDeck getFullDeck();

	//Card Constructor - creates a CardDeck from a given card
	//@param card - to construct into a CardDeck
	//@return CardDeck containing single card
	CardDeck(const Card& card);

	//this function returns the top card in the Deck
	//if the Deck is empty
	//Throw CardDeckIsEmptyException
	Card draw();

	//this function returns a Copy of the Top card in the Deck
	//if the Deck is Empty
	//Throw CardDeckIsEmptyException
	const Card& top() const;

	//this function returns an unsigned int that reprasent the number of cards
	//in the Deck
	 int getDecksize() const
	{
		return _cards.size();
	}
	unsigned size() const
	{
		return _cards.size();
	}

	//boolian function
	//if the Deck is Empty return true else false
	bool isEmpty() const;

	//this function clears all given cards in the Deck
	//void
	void clear()
	{
		_cards.clear();
		for (int i=1;i<14;i++){
			_heart[i]=0;
			_club[i]=0;
			_spade[i]=0;
			_dimonad[i]=0;
		}
	}
	CardDeck& getCards()
	{
		return *this;
	}

	//* needs to make a full convert from a single Card to a Deck

	//returns unsigned int for the whole Deck
	//a normal Crad- number of card
	//Royal Famliy-10
	//Ace value will be calculated via the next furmola
	//Deck-SUM/21 if than add the value of Ace 1\11 the minimum value will
	//detemin the value of the Ace
	unsigned int value() const;

	unsigned int getHandValue() const
	{
		return this->value();
	}

	bool isBasicHandValue() const;

	//operator overload- = equal operator for CardDeck Class
	CardDeck& operator=(const CardDeck& deck);

	//operator overload- += puts the new  CardDeck ontop of the "old" Deck
	CardDeck& operator+=(const CardDeck& deck);
	//operator overload- += puts the new  card ontop of the "old" Deck
	CardDeck& operator+=(const Card& card);



	//operator overload- <= return int if the LH Deck is true contains or equal to RH
	//deck else return false
	friend bool operator<=(const CardDeck& LHdeck,const CardDeck& RHdeck);





	//operator overload- == returns ture if the RH Deck is euqal and cards
	//appear in the same order to LH deck
	//else returns false
	friend bool operator==(const CardDeck& LHdeck,const CardDeck& RHdeck) ;

	//operator overload- != returns false if the RH Deck is euqal and cards
	//appear in the same order to to LH deck
	//else returns true
	bool operator!=(const CardDeck& deck) const;

	//operator overload- < return int if the LH Deck is true contains  RH
	//int represent how meny cards to add to be equal
	friend bool operator<(const CardDeck& LHdeck,const CardDeck& RHdeck);

	//operator overload- >> input cards for a existing Deck
	//the input format is a string example: " 3 KD 10H 2C "
	//put 3 new cards a king Dimoand 10 Heart and 2 club
	//can assume the int is an unsigned number
	//if the input format is incorrect
	//throw CardWorngArgsException
	friend istream& operator>>(istream& input, CardDeck& deck);

	//operator overload- OutPut operator for CardDeck Class
	friend std::ostream& operator<<(std::ostream& output, const CardDeck& deck);
	//this function returns true if current deck holds an Ace card of any kind
	//else return false
	bool deckContainsAce()const;

private:
	list<Card> _cards;
	int _heart[14]={0};
	int _dimonad[14]={0};
	int _club[14]={0};
	int _spade[14]={0};
};
//operator overload- + returns a new CardDeck LeftDeck is below Right Deck
CardDeck operator +(const CardDeck& LHdeck,const CardDeck& RHdeck);
//operator overload + for a given Card and a CardDeck
CardDeck operator+(CardDeck& deck,const Card& card);

//operator overload- * returns just like + operator but muiltiply by the
//given number
CardDeck operator*(const CardDeck& deck,unsigned int n);
CardDeck operator*(unsigned int n,const CardDeck& deck);

//operator overload => return int if the RH Deck is contains or euqal to LH
//int represent how meny cards to add to be equal
bool operator>=(const CardDeck& LHdeck,const CardDeck& RHdeck);

CardDeck& operator+=(const CardDeck& deck,const Card& card);



//operator overload- > return int if the RH Deck is contains  LH
//deck else return false
bool operator>(const CardDeck& LHdeck,const CardDeck& RHdeck);

#endif
