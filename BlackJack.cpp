/*
 * BlackJack.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: Ben
 */

#include "BlackJack.h"

BlackJack::BlackJack(const CardDeck& deck) :
		_possiblePlayers(map<int, Player*>()), _gameDeck(deck)
{
}

BlackJack::~BlackJack()
{
	for (map<int, Player*>::iterator iter = _possiblePlayers.begin();
			iter != _possiblePlayers.end(); ++iter)
	{
		delete (*iter).second;
	}
}

void BlackJack::reloadDeck(const CardDeck& deck)
{
	_gameDeck.clear();
	_gameDeck += deck;
}

bool BlackJack::playerInCasino(int id, map<int, Player*>::iterator begin,
		map<int, Player*>::iterator end)
{
	bool res = false;
	for (map<int, Player*>::iterator iter = begin; iter != end; iter++)
	{
		if (iter->first == id)
		{
			res = true;
			break;
		}
	}
	return res;
}

bool BlackJack::playerInRound(int id, list<int>::iterator begin,
		list<int>::iterator end)
{
	bool res = false;
	while (begin != end)
	{
		if (*(begin++) == id)
		{
			res = true;
			break;
		}
	}
	return res;
}
void BlackJack::addPlayer(int id, PlayerStrategy strategy, int budget)
{
	map<int, Player*>::iterator begin = _possiblePlayers.begin();
	map<int, Player*>::iterator end = _possiblePlayers.end();

	if (BlackJack::playerInCasino(id, begin, end))
	{
		throw PlayerAlreadytExistException();
	}
	else if (strategy == BlackJack::PlayerStrategy::CASINO)
	{
		std::pair<int, Player*> temp(id, new CasinoPlayer(id, budget));
		_possiblePlayers.insert(temp);
	}
	else
	{
		std::pair<int, Player*> temp(id, new CalculatedPlayer(id, budget));
		_possiblePlayers.insert(temp);
	}

}

void BlackJack::joinGame(int id)
{
	if (!playerInCasino(id, _possiblePlayers.begin(), _possiblePlayers.end()))
	{
		throw PlayerDoesNotExistException();
	}
	if (!playerInRound(id, _playersInGame.begin(), _playersInGame.end()))
	{
		_playersInGame.push_back(id);
	}
}

void BlackJack::joinGame(const vector<int>& id)
{
	int size = id.size();
	for (int i = 0; i < size; i++)
	{
		if (!playerInCasino(id[i], _possiblePlayers.begin(),
				_possiblePlayers.end()))
		{
			throw PlayerDoesNotExistException();
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (!playerInRound(id[i], _playersInGame.begin(), _playersInGame.end()))
		{
			_playersInGame.push_back(id[i]);
		}
	}
}

void BlackJack::leaveGame(int id)
{
	if (!playerInCasino(id, _possiblePlayers.begin(), _possiblePlayers.end()))
	{
		throw PlayerDoesNotExistException();
	}
	if (!playerInRound(id, _playersInGame.begin(), _playersInGame.end()))
	{
		return;
	}
    for (map<int, Player*>::iterator iter = _possiblePlayers.begin(); iter != _possiblePlayers.end(); iter++)
    {
        if(iter->first==id){
            iter->second->leave();
        }
    }

	_playersInGame.remove(id);

}

void BlackJack::leaveGame(const vector<int>& id){
    int size=id.size();
    	for (int i = 0; i < size; i++)
	{
		if (!playerInCasino(id[i], _possiblePlayers.begin(),
				_possiblePlayers.end()))
		{
			throw PlayerDoesNotExistException();
		}
	}
    	for(int i=0;i<size;i++){
    	    this->leaveGame(id[i]);
    	}
}

//void BlackJack::leaveGame(const vector<int>& id)
//{
//	int size = id.size();
//	for (int i = 0; i < size; i++)
//	{
//		if (!playerInCasino(id[i], _possiblePlayers.begin(),
//				_possiblePlayers.end()))
//		{
//			throw PlayerDoesNotExistException();
//		}
//	}
//	for (int i = 0; i < size; i++)
//	{
//		if (playerInRound(id[i], _playersInGame.begin(), _playersInGame.end()))
//		{
//			_playersInGame.remove(id[i]);
//		}
//	}
//}

int BlackJack::getBalance(int id)
{

	if (!playerInCasino(id, _possiblePlayers.begin(), _possiblePlayers.end()))
	{
		throw PlayerDoesNotExistException();
	}
	return (*_possiblePlayers[id]).playerGetBudget();
}

int BlackJack::getRichest() const
{
	if (_possiblePlayers.empty())
	{
		throw NoPlayersException();
	}
	map<int, Player*>::const_iterator iter = _possiblePlayers.begin();
	Player* max = ((*iter).second);
	int maxBudget = max->playerGetBudget();
	int maxId = max->playerGetId();
	while (iter != _possiblePlayers.end())
	{
		Player* current = ((*iter).second);
		if (current->playerGetBudget() > maxBudget)
		{
			max = ((*iter).second);
			maxBudget = max->playerGetBudget();
			maxId = max->playerGetId();
		}
		++iter;
	}
	return maxId;
}

void BlackJack::dealCards(list<int> &players)
{
	list<int>::iterator iter = players.begin();
	while (iter != players.end())
	{
		Player& playerToDeal = *_possiblePlayers[*iter];
		playerToDeal.playerAddCard(_gameDeck.draw());
		++iter;
	}
}

Card BlackJack::startRound()
{
	dealCards(_playersInGame);
	Card dealerCard = _gameDeck.draw();
	_dealer.playerAddCard(dealerCard);
	dealCards(_playersInGame);
	_dealer.playerAddCard(_gameDeck.draw());
	return dealerCard;
}

void BlackJack::playRound()
{
	if (!(_gameDeck.getFullDeck() <= _gameDeck))
	{
		throw NotEnoughCardsException();
	}
	else if (_playersInGame.empty())
	{
		return;
	}
	Card dealerCard = startRound();
	if ((int) _dealer.playerDeckValue() == BJ)
	{
		endRound();
		return;
	}
	list<int> remainingPlayers = _playersInGame;
	while (remainingPlayers.size() != 0)
	{
		correntRemainingPlayers(remainingPlayers, dealerCard);
		dealCards(remainingPlayers);
	}

	bool dealerNeedsToPlay = false;
	list<int>::iterator playersItertor;
//	for (playersItertor = remainingPlayers.begin();
//			playersItertor != remainingPlayers.end(); ++playersItertor)
//	{
	    for (playersItertor = _playersInGame.begin();
			playersItertor != _playersInGame.end(); ++playersItertor)
	{
		Player& currentPlayer = *_possiblePlayers[*playersItertor];
		if ((int) currentPlayer.playerDeckValue() < BJ
				|| ((int) currentPlayer.playerDeckValue() == BJ
						&& (int) currentPlayer.playerDeckSize() > 2))
		{
			dealerNeedsToPlay = true;
			break;
		}
	}

	if (dealerNeedsToPlay)
	{
		while (_dealer.playerChoise(dealerCard) != Player::STAND)
		{
			_dealer.playerAddCard(_gameDeck.draw());
		}
	}
	endRound();
}

void BlackJack::endRound()
{
	int dealerHandValue = _dealer.playerDeckValue();
	int correntPlayerHandValue;
	unsigned int correntPlayerDeckSize;
	list<int>::iterator iter = _playersInGame.begin();
	while (iter != _playersInGame.end())
	{
		Player& currentPlayer = *_possiblePlayers[*iter];
		correntPlayerHandValue = currentPlayer.playerDeckValue();
		correntPlayerDeckSize = currentPlayer.playerDeckSize();
		if (correntPlayerHandValue > BJ)
		{
			currentPlayer.lose();
		}
		else if (dealerHandValue > BJ)
		{
			currentPlayer.win();
		}
		else
		{
			if (dealerHandValue > correntPlayerHandValue)
			{
				currentPlayer.lose();
			}
			else if (dealerHandValue < correntPlayerHandValue)
			{
				currentPlayer.win();
			}
			else if ((correntPlayerDeckSize == 2)
					&& (correntPlayerHandValue == BJ)
					&& (_dealer.playerDeckSize() > 2))
			{
				currentPlayer.win();
			}
		}
		currentPlayer.playerClearDeck();
		++iter;
	}
	_dealer.playerClearDeck();
}


void BlackJack::correntRemainingPlayers(list<int>& remainingPlayers,
		Card& dealerCard)
{
	for (list<int>::iterator playersItertor = remainingPlayers.begin();
			playersItertor != remainingPlayers.end();)
	{
		Player& currentPlayer = *_possiblePlayers[*playersItertor];
		if (((int) currentPlayer.playerDeckValue() >= BJ)
				|| (currentPlayer.playerChoise(dealerCard) == Player::STAND))
		{
			remainingPlayers.erase(playersItertor);
			playersItertor = remainingPlayers.begin();
		}
		else
		{
			++playersItertor;
		}
	}

}
