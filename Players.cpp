/*
 * Players.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Ben
 */

#include "Players.h"

void Player::updatePlayerBudget(int amount)
{
	if (((int) playerDeckSize() == 2) && ((int) playerDeckValue() == BJ))
	{
		_budget += (int)(amount / 2);
	}
	_budget += amount;
}

bool CalculatedPlayer::calculatedPlayerHasAce() const
{

	return this->_hand.deckContainsAce();
}

Player::PlayerMove BasicPlayer::playerChoise(const Card& dealerCard) const
{
	if (playerDeckValue() < (unsigned) 17)
		return HIT;
	else
		return STAND;
}

Player::PlayerMove CalculatedPlayer::playerChoise(const Card& DealerCard) const
{
	int value = _hand.value();
	int dealerValue = DealerCard.cardValue();
	if (_hand.deckContainsAce() && _hand.isBasicHandValue())
	{
		if (value > 18
				|| (value == 18
						&& (dealerValue == 2 || dealerValue == 7
								|| dealerValue == 8)))
		{
			return STAND;
		}
		else
		{
			return HIT;
		}
	}
	else
	{
		if (((value <= 16) && (value >= 13) && (dealerValue <= 6)
				&& (dealerValue >= 2))
				|| ((value == 12) && (dealerValue >= 4) && (dealerValue <= 6))
				|| (value >= 17))
		{
			return STAND;
		}
		else
		{
			return HIT;
		}
	}
}
