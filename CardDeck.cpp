/*
 * CardDeck.cpp
 *
 *  Created on: Apr 3, 2018
 *      Author: Ben
 */

#include "CardDeck.h"
#include "Exceptions.h"
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;
using namespace mtm;

static string cardToString(const Card& card)
{
	int value = card.cardValue();
	Card::Suit suit = card.cardSuit();
	std::ostringstream oss;
	switch (value)
	{
	case (11):oss << 'J';break;
	case (12):oss << 'Q';break;
	case (13):oss << 'K';break;
	default:oss << value;break;
	}
	switch (suit)
	{
	case (Card::Heart):oss <<'H';break;
	case (Card::Diamond):oss <<'D';break;
	case (Card::Club):oss <<'C';break;
	case (Card::Spade):oss <<'S';break;
	}
	return oss.str();
}


CardDeck::CardDeck(const Card& card){
	for (int i = 0; i < 14; i++)
	{
		_heart[i] = 0;
		_club[i] = 0;
		_spade[i] = 0;
		_dimonad[i] = 0;
	}
	switch(card.cardSuit()){
	case Card::Club:
		_club[card.cardValue()]++; break;
	case Card::Diamond:
		_dimonad[card.cardValue()]++; break;
	case Card::Heart:
		_heart[card.cardValue()]++; break;
	default:
		_spade[card.cardValue()]++; break;
	}
	_cards.push_back(card);
}

CardDeck CardDeck::getFullDeck()
{
	CardDeck fullDeck;
	for (int suit=Card::Spade;suit>=Card::Heart;suit--){
		for (int cardValue=13;cardValue>=1;cardValue--){
			switch(cardValue){
			case 13:
				fullDeck._cards.push_back(Card((Card::Suit)suit,'k'));break;
			case 12:
				fullDeck._cards.push_back(Card((Card::Suit)suit,'q'));break;
			case 11:
				fullDeck._cards.push_back(Card((Card::Suit)suit,'j'));break;
			default:
				fullDeck._cards.push_back(Card((Card::Suit)suit,cardValue));break;
			}
		}
	}
	for (int k = 1; k < 14; k++)
	{
		fullDeck._heart[k] = 1;
		fullDeck._club[k] = 1;
		fullDeck._spade[k] = 1;
		fullDeck._dimonad[k] = 1;
	}
	return fullDeck;
}


bool CardDeck::isEmpty() const
{
	return this->_cards.empty();
}

unsigned int CardDeck::value() const
{
	unsigned int aces = 0;
	unsigned int sum = 0;
	int cardValue;
	double lhSum=0,rhSum=0;

	for (list<Card>::const_iterator iter = _cards.begin(); iter != _cards.end();
			iter++)
	{
		cardValue = iter->cardValue();
		if (cardValue == 1 || cardValue == 14)
		{
			aces++;
		}
		else if (cardValue < 11)
		{
			sum += cardValue;
		}
		else
		{
			sum += 10;
		}
	}
	lhSum =(sum + (1 * aces));
	lhSum/=21;
	rhSum = (sum + (11 * aces));
	rhSum/=21;
	lhSum=ceil(lhSum);
	rhSum=ceil(rhSum);
	int biggerSum=sum+(11*aces),smallerSum=sum+(1*aces);
	int temp=smallerSum;
	if (lhSum < rhSum)
	{
		while((aces>=2) && (biggerSum%21>=1)&&(biggerSum%21<11)){
			 smallerSum+=10;
			 aces--;
		}
		return smallerSum>21?temp:smallerSum;
	}
	return sum + (11 * aces);
}

bool CardDeck::isBasicHandValue() const
{
	unsigned int aces = 0;
	unsigned int sum = 0;
	int cardValue;
	double lhSum=0,rhSum=0;
	for (list<Card>::const_iterator iter = _cards.begin(); iter != _cards.end();
			iter++)
	{
		cardValue = iter->cardValue();
		if (cardValue == 1 || cardValue == 14)
		{
			aces++;
		}
		else if (cardValue < 11)
		{
			sum += cardValue;
		}
		else
		{
			sum += 10;
		}
	}
	bool result=false;
	lhSum =(sum + (1 * aces));
	lhSum/=21;
	rhSum = (sum + (11 * aces));
	rhSum/=21;
	lhSum=ceil(lhSum);
	rhSum=ceil(rhSum);
	int smallerSum=sum+(1*aces);
	if (lhSum < rhSum)
	{
		if((aces>=2) && (smallerSum%21==1)){
			 result=true;
		}
		else if(aces>=1 && smallerSum%21>=1 && smallerSum%21<=11){
			result=true;
		}
	}

	 return result;
}
Card CardDeck::draw()
{
	Card temp =top();
	_cards.pop_front();
	switch(temp.cardSuit()){
	case Card::Club:
		_club[temp.cardValue()]--; break;
	case Card::Diamond:
		_dimonad[temp.cardValue()]--; break;
	case Card::Heart:
		_heart[temp.cardValue()]--; break;
	default:
		_spade[temp.cardValue()]--; break;
	}
	return temp;
}

const Card& CardDeck::top() const
{
	if (this->_cards.size() == 0)
		throw CardDeckIsEmptyException();
	return this->_cards.front();
}
CardDeck& CardDeck::operator +=(const CardDeck& deck)
{
	_cards.insert(_cards.begin(),deck._cards.begin(),deck._cards.end());

	for (int i = 1; i < 14; i++)
	{
		_heart[i] += deck._heart[i];
		_club[i] += deck._club[i];
		_spade[i] += deck._spade[i];
		_dimonad[i] += deck._dimonad[i];
	}
	return *this;
}

CardDeck& operator+=(const CardDeck& deck,const Card& card){
	CardDeck temp(card);
	return temp+=deck;
}

CardDeck& CardDeck::operator+=(const Card& card){
	if(card.cardSuit()==Card::Heart){
		this->_heart[card.cardValue()]++;
	}
	if(card.cardSuit()==Card::Club){
		this->_club[card.cardValue()]++;
	}
	if(card.cardSuit()==Card::Spade){
		this->_spade[card.cardValue()]++;
	}
	else{
		this->_dimonad[card.cardValue()]++;
	}
	_cards.push_front(card);
	return *this;
}

CardDeck operator +(const CardDeck& LHdeck,const CardDeck& RHdeck)
{
	CardDeck temp=LHdeck;
	temp+=RHdeck;
	return temp;
}

CardDeck operator +( CardDeck& deck,const Card& card)
{
	CardDeck temp(card);
	temp+=deck;
	return temp;
}

CardDeck operator*(const CardDeck& deck,const unsigned int n)
{
	CardDeck temp=deck;
	if(n==0){
		temp.clear();
		return temp;
	}

	for ( unsigned int i = 1; i < n; i++)
	{
		temp+=deck;
	}
	return temp;
}

CardDeck operator*(const unsigned int n,const CardDeck& deck){
	return deck*n;
}
bool operator<=(const CardDeck& LHdeck,const CardDeck& RHdeck)
{
	for (int i = 1; i < 14; i++)
	{
		if (RHdeck._heart[i] - LHdeck._heart[i] < 0)
			return false;

		if (RHdeck._club[i] - LHdeck._club[i] < 0)
			return false;

		if (RHdeck._spade[i] - LHdeck._spade[i] < 0)
			return false;

		if (RHdeck._dimonad[i] - LHdeck._dimonad[i] < 0)
			return false;
	}
	return true;
}

bool operator<(const CardDeck& LHdeck,const CardDeck& RHdeck)
{
	if(!(LHdeck.size()<RHdeck.size())){
		return false;
	}
	for (int i = 1; i < 14; i++)
	{

		if (RHdeck._heart[i] < LHdeck._heart[i])
			return false;

		if (RHdeck._club[i] < LHdeck._club[i])
			return false;

		if (RHdeck._spade[i] < LHdeck._spade[i])
			return false;

		if (RHdeck._dimonad[i] < LHdeck._dimonad[i])
			return false;
	}
	return true;
}

bool operator>=(const CardDeck& LHdeck,const CardDeck& RHdeck)
{
	return RHdeck<=LHdeck;
}

bool operator>(const CardDeck& LHdeck,const CardDeck& RHdeck)
{

	return RHdeck<LHdeck;
}

bool operator==(const CardDeck& LHdeck,const CardDeck& RHdeck)
{
	bool res = true;

	if (LHdeck._cards.size() != RHdeck._cards.size())
		return false;
	list<Card>::const_iterator Lh = LHdeck._cards.begin();
	list<Card>::const_iterator Rh = RHdeck._cards.begin();
	for (unsigned int i = 0; i < RHdeck._cards.size(); i++)
	{
		if (*Lh != *Rh)
		{
			res = false;
			break;
		}
	}
	return res;
}

bool CardDeck::operator!=(const CardDeck& deck) const
{
	return !(*this == deck);
}



CardDeck& CardDeck::operator=(const CardDeck& deck)
{
	if(this==&deck){
		return *this;
	}
	this->clear();
	return *this+=deck;

}

bool CardDeck::deckContainsAce() const
{
	bool res = false;
	if ((_club[1] >= 1) || (_dimonad[1] >= 1) || (_heart[1] >= 1)
			|| (_spade[1] >= 1))
	{
		res = true;
	}
	return res;
}

istream& operator>>(istream& input, CardDeck& cardDeck)
{
	int length;
	cardDeck.clear();
	input >> length;
	Card tempCard(Card::Diamond, 1);
	for (int i = 0; i < length; i++)
	{
		input >> tempCard;
		cardDeck._cards.push_front(tempCard);
	}
	return input;
}

ostream& operator<<(std::ostream& output, const CardDeck& deck)
{
	output << deck.getDecksize();
	for (list<Card>::const_iterator iter = deck._cards.begin();
			iter != deck._cards.end(); iter++)
	{
		output << " " << cardToString(*iter);
	}
	return output;
}

