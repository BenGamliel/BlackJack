/*
 * Card.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: Ben
 */

#include "Card.h"
#include "Exceptions.h"
#include <string>

using mtm::CardWrongArgsException;
using std::string;




static Card::Suit charToSuit(char suit)
{
	if(suit=='h'||suit=='H')
		return Card::Heart;
	else if(suit=='d'||suit=='D')
		return Card::Diamond;
	else if(suit=='c'||suit=='C')
		return Card::Club;
	else if(suit=='s'||suit=='S')
		return Card::Spade;
	else
		throw CardWrongArgsException();

}

Card::Card(Suit suit, int value)
{
	_suit=suit;
	if ((value <= 10) && (value > 1))
	{

		_value=value;
		_drawing=Number;
	}
	else if (value == 1)
	{
		_drawing = Ace;
		_value = 1;
	}
	else
	{
		throw CardWrongArgsException();
	}

}
Card::Card(Suit suit, char drawing) :
		_suit(suit), _value(0)
{
	if ((drawing == 'j') || (drawing == 'J'))
	{
		_drawing = Prince;
		_value = 11;
	}
	else if ((drawing == 'q') || (drawing == 'Q'))
	{
		_drawing = Queen;
		_value = 12;
	}
	else if ((drawing == 'k') || (drawing == 'K'))
	{
		_drawing = King;
		_value = 13;
	}
	else if ((drawing == 'a' )|| (drawing == 'A'))
	{
		_drawing = Ace;
		_value = 1;
	}
	else
	{
		throw CardWrongArgsException();
	}
}

Card::Card(const Card& card)
{
	this->_drawing = card._drawing;
	this->_suit = card._suit;
	this->_value = card._value;

}

Card& Card::operator=(const Card &card)
{
	if (this == &card)
	{
		return *this;
	}
	else
	{
		this->_drawing = card._drawing;
		this->_suit = card._suit;
		this->_value = card._value;
	}
	return *this;
}

bool Card::operator==(const Card& card) const
{

	if ((cardValue(*this) != cardValue(card)) || (card._suit != this->_suit))
	{
		return false;
	}
	return true;
}
bool Card::operator!=(const Card& card) const
{
	return !(*this == card);
}
int Card::cardValue(const Card& card) const
{
	if (card._drawing == Number)
	{
		if (card._value == 1)
		{
			return 14;
		}
		return card._value;
	}
	return card._drawing;
}

istream& operator>>(istream& is,Card& obj){
	string input;
	is>>input;
	int len=input.size();
	Card::Suit newSuit=charToSuit(input[len-1]);
	if(len<2||len>3){
		throw CardWrongArgsException();
	}
	if(len==2){
		if((input[0]>='A'&&input[0]<='Z') || (input[0]>='a'&&input[0]<='z')){
			obj=Card(newSuit,input[0]);
		}
		else{
			int newValue=input[0]-'0';
			if(!(newValue<=9||newValue>=1)){
				throw CardWrongArgsException();
			}
			obj=Card(newSuit,newValue);
			return is;
		}
	}
	else{
		if(input[0]!='1' || input[1]!='0')
			throw CardWrongArgsException();

			obj=Card(newSuit,10);
	}
	return is;
}

