/*
 * Card.h
 *
 *  Created on: Apr 1, 2018
 *      Author: Ben
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include "Exceptions.h"
#include <fstream>

using std::istream;
using std::ostream;

typedef enum
{
	Prince = 11, Queen, King, Ace, Number = 0
} Royal;


class Card
{
public:
	enum Suit
	{Heart, Diamond, Club, Spade};
private:
	Suit _suit;
	int _value;
	Royal _drawing;
public:

	//defualt constractor
	Card();
	//// Constructs a new Card with the specified data.
	//
	// @param _suit : the _suit of the Card.
	// @param _value : the _value of the Card.
	// if param isnt legal throw CardWrongArgsExceptio
	//
	Card(Suit suit, int value);
	//// Constructs a new Card with the specified data.
	//
	// @param _suit : the _suit of the Card.
	// @param _drawing : the _drawing of the Card.
	// if param isnt legal throw CardWrongArgsExceptio
	//
	Card(Suit suit, char identier);
	//default CopyConstractornre
	//
	Card(const Card& card);
	//default destractor
	~Card()=default ;
	//Assignment operation
	Card& operator=(const Card& card);
	// input opertator OverLoad
	// legal input is a string length 2-3 while the last char is a
	// 'H' 'D' 'C' 'S'
	// start of input is a number(1-10),or a char
	// 'J' 'Q' 'K' 'A'
	// if param isnt legal throw CardWrongArgsExceptio
	friend istream& operator>>(istream& input, Card& card);
//	overloaing opertaor ==
//	return true if Cards are equal
//	else return false

	bool operator==(const Card& card) const;
	//overloaing opertaor =!
	//return false if Cards are equal
	//else return true
	bool operator!=(const Card& card) const;
	int cardValue(const Card& card) const;
	int cardValue() const
	{
		return this->_value;
	}
	Suit cardSuit() const
	{
		return this->_suit;
	}
	Royal cardDrawing() const
	{
		return this->_drawing;
	}

};

#endif // CARD_H
