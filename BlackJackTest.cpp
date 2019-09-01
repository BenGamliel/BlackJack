#include "BlackJack.h"
#include "Exceptions.h"
#include "MtmTst.h"

#include <cstdlib>	/* srand, rand */
#include <ctime>	/* time */

using mtm::PlayerAlreadytExistException;
using mtm::PlayerDoesNotExistException;
using mtm::NotEnoughCardsException;

bool blackJackPlayerAddTest() {

	CardDeck initialDeck = CardDeck::getFullDeck() * 2;

	BlackJack bj(initialDeck);
	bj.addPlayer(1, BlackJack::CASINO, 10);
	bj.addPlayer(2, BlackJack::CASINO, 0);
	bj.addPlayer(3, BlackJack::CASINO, -10);
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(2, BlackJack::CALCULATED, 10));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(3, BlackJack::CALCULATED, 0));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(1, BlackJack::CALCULATED, -10));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(3, BlackJack::CASINO, 10));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(1, BlackJack::CASINO, 0));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(2, BlackJack::CASINO, -10));

	BlackJack bj2(initialDeck);
	bj2.addPlayer(1, BlackJack::CALCULATED, 10);
	bj2.addPlayer(2, BlackJack::CALCULATED, 0);
	bj2.addPlayer(3, BlackJack::CALCULATED, -10);
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(2, BlackJack::CALCULATED, 10));
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(3, BlackJack::CALCULATED, 0));
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(1, BlackJack::CALCULATED, -10));
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(3, BlackJack::CASINO, 10));
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(1, BlackJack::CASINO, 0));
	ASSERT_THROW(PlayerAlreadytExistException, bj2.addPlayer(2, BlackJack::CASINO, -10));

	bj.addPlayer(-1, BlackJack::CASINO, 20);
	bj.addPlayer(0, BlackJack::CASINO, 30);
	bj.joinGame({ 1, 2 });
	bj.joinGame(-1);

	bj.playRound();

	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(1, BlackJack::CALCULATED, 10));
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(-1, BlackJack::CALCULATED, -10));

	bj.leaveGame(2);
	ASSERT_THROW(PlayerAlreadytExistException, bj.addPlayer(2, BlackJack::CALCULATED, 10));

	return true;
}

DEFINE_INPUT_TEST(casinoStrategyTest)
	CardDeck deck;
	input >> deck;
	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));

	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(97, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(93, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(95, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(103, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(105, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(106, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(105, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(103, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(91, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(107, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(106, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(108, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(109, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(110, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(109, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(111, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(110, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(112, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(113, bj.getBalance(1));

	return true;
}

DEFINE_INPUT_TEST(calculatedStrategyTest)
	CardDeck deck;
	input >> deck;
	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CALCULATED, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));

	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(80, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(61, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(61, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(43, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(60, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(59, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(77, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(58, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(76, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(57, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(39, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(64, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(46, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(46, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(29, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(45, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(62, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(89, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(108, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(128, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(149, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(182, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(205, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(229, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(204, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(180, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(157, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(135, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(156, bj.getBalance(1));
	ASSERT_THROW(NotEnoughCardsException, bj.playRound());
	return true;
}

bool playerBlackJackTest() {
	CardDeck deck = CardDeck::getFullDeck();
	// win
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 'J') + Card(Card::Club, 10) + Card(Card::Spade, 'A'));
	// both have blackjack
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 'J') + Card(Card::Club, 'A') + Card(Card::Spade, 'A'));
	// lose once before blackjack
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// both have blackjack
	deck += (Card(Card::Heart, 1) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 'A'));
	// lose twice before blackjack
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// both have blackjack
	deck += (Card(Card::Heart, 1) + Card(Card::Diamond, 'A') + Card(Card::Club, 'Q') + Card(Card::Spade, 'K'));
	// blackjack vs 20
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 'A') + Card(Card::Club, 'Q') + Card(Card::Spade, 'J'));
	// blackjack vs 12 potential bust (next card is J)
	deck += (Card(Card::Heart, 2) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 'A'));
	// lose once before blackjack
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// blackjack vs 10 potential 21 (next card is A)
	deck += (Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 7) + Card(Card::Spade, 1));
	// lose twice before blackjack
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// blackjack vs 10 potential 21 (next card is A)
	deck += (Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 7) + Card(Card::Spade, 1));
	// lose three times before blackjack
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));

	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(97, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(93, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(105, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(108, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(107, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(110, bj.getBalance(1));
	bj.playRound(); 
	ASSERT_EQUALS(111, bj.getBalance(1));
	bj.playRound(); 
	ASSERT_EQUALS(111, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(110, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(108, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(108, bj.getBalance(1)); 
	bj.playRound(); 
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(104, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(116, bj.getBalance(1));

	bj.reloadDeck(deck);
	bj.addPlayer(2, BlackJack::CALCULATED, 100);
	bj.leaveGame(1);
	ASSERT_EQUALS(100, bj.getBalance(2));
	bj.joinGame(2);
	ASSERT_EQUALS(100, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(80, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(61, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(43, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(68, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(50, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(33, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(57, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(40, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(64, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(89, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(89, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(71, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(54, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(54, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(38, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(38, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(60, bj.getBalance(2));

	return true;
}

bool playerNotBlackJack21noAceTest() {
	CardDeck deck = CardDeck::getFullDeck();
	// win
	deck += (Card(Card::Diamond, 5) + Card(Card::Heart, 'K') + Card(Card::Diamond, 6) + Card(Card::Club, 10) + Card(Card::Spade, 'Q'));
	// lose - casino has blackjack (optional 21)
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 6) + Card(Card::Club, 'A') + Card(Card::Spade, 5));
	// tie (21 - no ace)
	deck += (Card(Card::Heart, 8) + Card(Card::Spade, 9) + Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// tie (21 - with ace)
	deck += (Card(Card::Heart, 7) + Card(Card::Heart, 1) + Card(Card::Spade, 9) + Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// lose twice
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// win against bust
	deck += (Card(Card::Heart, 6) + Card(Card::Heart, 5) + Card(Card::Heart, 9) + Card(Card::Diamond, 6) + Card(Card::Club, 7) + Card(Card::Spade, 'K'));

	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));
	
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(94, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));

	bj.reloadDeck(deck);
	bj.addPlayer(2, BlackJack::CALCULATED, 100);
	bj.leaveGame(1);
	ASSERT_EQUALS(100, bj.getBalance(2));
	bj.joinGame(2);
	ASSERT_EQUALS(100, bj.getBalance(2));

	bj.playRound();
	ASSERT_EQUALS(120, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(60, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(2));

	return true;
}

bool playerNotBlackJack21withAceTest() {
	CardDeck deck = CardDeck::getFullDeck();
	// win
	deck += (Card(Card::Diamond, 5) + Card(Card::Diamond, 1) + Card(Card::Heart, 'K') + Card(Card::Diamond, 7) + Card(Card::Club, 10) + Card(Card::Spade, 8));
	// lose - casino has blackjack (optional 21)
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 1) + Card(Card::Club, 'A') + Card(Card::Spade, 2));
	// tie (21 - no ace)
	deck += (Card(Card::Heart, 8) + Card(Card::Spade, 8) + Card(Card::Spade, 1) + Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// tie (21 - with ace)
	deck += (Card(Card::Heart, 7) + Card(Card::Heart, 1) + Card(Card::Spade, 8) + Card(Card::Spade, 1) + Card(Card::Heart, 3) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// lose twice
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	deck += (Card(Card::Diamond, 'K') + Card(Card::Heart, 5) + Card(Card::Diamond, 2) + Card(Card::Club, 5) + Card(Card::Spade, 10));
	// win against bust
	deck += (Card(Card::Heart, 6) + Card(Card::Heart, 5) + Card(Card::Heart, 1) + Card(Card::Heart, 9) + Card(Card::Diamond, 5) + Card(Card::Club, 7) + Card(Card::Spade, 'K'));

	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));

	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(94, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));

	bj.reloadDeck(deck);
	bj.addPlayer(2, BlackJack::CALCULATED, 100);
	bj.leaveGame(1);
	ASSERT_EQUALS(100, bj.getBalance(2));
	bj.joinGame(2);
	ASSERT_EQUALS(100, bj.getBalance(2));

	bj.playRound();
	ASSERT_EQUALS(120, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(79, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(60, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(2));

	return true;
}

bool playerStandTest() {
	CardDeck deck = CardDeck::getFullDeck();
	// win (caisno stands)
	deck += (Card(Card::Heart, 7) + Card(Card::Diamond, 10) + Card(Card::Club, 10) + Card(Card::Spade, 8));
	// lose - casino has blackjack
	deck += (Card(Card::Heart, 10) + Card(Card::Diamond, 10) + Card(Card::Club, 'A') + Card(Card::Spade, 8));
	// lose - casino has blackjack
	deck += (Card(Card::Heart, 1) + Card(Card::Diamond, 10) + Card(Card::Club, 'K') + Card(Card::Spade, 8));
	// tie (19 - caisno no ace)
	deck += (Card(Card::Heart, 4) + Card(Card::Spade, 6) + Card(Card::Spade, 1) + Card(Card::Heart, 5) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// tie (19 - caisno with ace)
	deck += (Card(Card::Heart, 3) + Card(Card::Heart, 1) + Card(Card::Spade, 6) + Card(Card::Spade, 1) + Card(Card::Heart, 5) + Card(Card::Diamond, 'J') + Card(Card::Club, 'Q') + Card(Card::Spade, 2));
	// lose caisno has 21, no blackjack (with ace)
	deck += (Card(Card::Diamond, 1) + Card(Card::Diamond, 8) + Card(Card::Heart, 2) + Card(Card::Diamond, 2) + Card(Card::Club, 8) + Card(Card::Spade, 10));
	// lose caisno has 21, no blackjack (no ace)
	deck += (Card(Card::Diamond, 6) + Card(Card::Diamond, 5) + Card(Card::Diamond, 8) + Card(Card::Heart, 8) + Card(Card::Diamond, 2) + Card(Card::Club, 2) + Card(Card::Spade, 10));
	// win against bust
	deck += (Card(Card::Heart, 6) + Card(Card::Heart, 4) + Card(Card::Heart, 9) + Card(Card::Diamond, 5) + Card(Card::Club, 7) + Card(Card::Spade, 'K'));
	// win against bust
	deck += (Card(Card::Heart, 6) + Card(Card::Heart, 4) + Card(Card::Heart, 1) + Card(Card::Heart, 9) + Card(Card::Diamond, 5) + Card(Card::Club, 7) + Card(Card::Spade, 'K'));
	// lose with stand
	deck += (Card(Card::Heart, 4) + Card(Card::Heart, 3) + Card(Card::Heart, 1) + Card(Card::Heart, 9) + Card(Card::Diamond, 5) + Card(Card::Club, 7) + Card(Card::Spade, 'K'));

	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame(1);
	ASSERT_EQUALS(100, bj.getBalance(1));

	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(95, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(87, bj.getBalance(1));
	bj.playRound();
	ASSERT_EQUALS(103, bj.getBalance(1));

	bj.reloadDeck(deck);
	bj.addPlayer(2, BlackJack::CALCULATED, 100);
	bj.leaveGame(1);
	ASSERT_EQUALS(100, bj.getBalance(2));
	bj.joinGame(2);
	ASSERT_EQUALS(100, bj.getBalance(2));
	
	bj.playRound();
	ASSERT_EQUALS(80, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(119, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(78, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(59, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(41, bj.getBalance(2));
	bj.playRound();
	ASSERT_EQUALS(58, bj.getBalance(2));
	return true;
}

bool joinLeaveTest() {
	BlackJack bj(CardDeck::getFullDeck() * 10);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	bj.addPlayer(2, BlackJack::CASINO, 200);
	bj.addPlayer(6, BlackJack::CALCULATED, 600);
	bj.addPlayer(7, BlackJack::CALCULATED, 700);

	ASSERT_THROW(PlayerDoesNotExistException, bj.joinGame({ 1, 5, 6 }));
	bj.playRound();
	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	bj.joinGame({ 6, 1 });
	ASSERT_THROW(PlayerDoesNotExistException, bj.joinGame({ 1, 5, 6 }));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(620, bj.getBalance(6));
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));
	ASSERT_EQUALS(599, bj.getBalance(6));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(579, bj.getBalance(6));
	bj.leaveGame(1);
	ASSERT_EQUALS(101, bj.getBalance(1));
	bj.playRound();
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(618, bj.getBalance(6));
	bj.leaveGame({ 1, 6 });
	bj.playRound();
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(618, bj.getBalance(6));
	bj.joinGame({ 1, 6 });
	bj.playRound();
	ASSERT_EQUALS(102, bj.getBalance(1));
	ASSERT_EQUALS(638, bj.getBalance(6));
	bj.joinGame({ 7, 2 });
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(201, bj.getBalance(2));
//	ASSERT_EQUALS(659, bj.getBalance(6));//TODO here player lost but still got the money
	ASSERT_EQUALS(617, bj.getBalance(6));//TODO replacment here
	ASSERT_EQUALS(720, bj.getBalance(7));
	return true;
}

bool richestTest() {
	CardDeck emptyDeck;
	BlackJack bj(emptyDeck);
	bj.addPlayer(1, BlackJack::CALCULATED, 100);
	bj.addPlayer(2, BlackJack::CALCULATED, 200);

	BlackJack bj2(emptyDeck);
	bj2.addPlayer(1, BlackJack::CALCULATED, 200);
	bj2.addPlayer(2, BlackJack::CALCULATED, 100);
	ASSERT_EQUALS(1, bj2.getRichest());

	BlackJack bj3(emptyDeck);
	bj3.addPlayer(1, BlackJack::CALCULATED, 200);
	bj3.addPlayer(2, BlackJack::CALCULATED, 200);
	bj3.addPlayer(3, BlackJack::CALCULATED, 100);
	ASSERT_EQUALS(1, bj3.getRichest());

	BlackJack bj4(emptyDeck);
	bj4.addPlayer(1, BlackJack::CALCULATED, 200);
	bj4.addPlayer(2, BlackJack::CALCULATED, 100);
	bj4.addPlayer(3, BlackJack::CALCULATED, 200);
	ASSERT_EQUALS(1, bj4.getRichest());

	BlackJack bj5(emptyDeck);
	bj5.addPlayer(1, BlackJack::CALCULATED, 100);
	bj5.addPlayer(2, BlackJack::CALCULATED, 200);
	bj5.addPlayer(3, BlackJack::CALCULATED, 200);
	ASSERT_EQUALS(2, bj5.getRichest());

	BlackJack bj6(emptyDeck);
	bj6.addPlayer(1, BlackJack::CALCULATED, -100);
	bj6.addPlayer(2, BlackJack::CALCULATED, -200);
	ASSERT_EQUALS(1, bj6.getRichest());

	BlackJack bj7(emptyDeck);
	bj7.addPlayer(1, BlackJack::CALCULATED, -200);
	bj7.addPlayer(2, BlackJack::CALCULATED, -100);
	ASSERT_EQUALS(2, bj7.getRichest());

	BlackJack bj8(emptyDeck);
	bj8.addPlayer(2, BlackJack::CALCULATED, -200);
	bj8.addPlayer(1, BlackJack::CALCULATED, -100);
	ASSERT_EQUALS(1, bj8.getRichest());

	BlackJack bj9(emptyDeck);
	bj9.addPlayer(2, BlackJack::CALCULATED, -100);
	bj9.addPlayer(1, BlackJack::CALCULATED, -200);
	ASSERT_EQUALS(2, bj9.getRichest());

	return true;
}

DEFINE_INPUT_TEST(multiPlayerTest)
	CardDeck deck;
	input >> deck;
	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	bj.addPlayer(2, BlackJack::CASINO, 100);
	bj.addPlayer(3, BlackJack::CALCULATED, 100);
	bj.addPlayer(4, BlackJack::CALCULATED, 100);
	bj.joinGame({ 1, 2, 3, 4 });
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	ASSERT_EQUALS(99, bj.getBalance(2));
	ASSERT_EQUALS(80, bj.getBalance(3));
	ASSERT_EQUALS(80, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(99, bj.getBalance(1));
	ASSERT_EQUALS(101, bj.getBalance(2));
	ASSERT_EQUALS(61, bj.getBalance(3));
	ASSERT_EQUALS(99, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(101, bj.getBalance(1));
	ASSERT_EQUALS(100, bj.getBalance(2));
	ASSERT_EQUALS(43, bj.getBalance(3));
	ASSERT_EQUALS(79, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(100, bj.getBalance(1));
	ASSERT_EQUALS(98, bj.getBalance(2));
	ASSERT_EQUALS(60, bj.getBalance(3));
	ASSERT_EQUALS(60, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(98, bj.getBalance(1));
	ASSERT_EQUALS(94, bj.getBalance(2));
	ASSERT_EQUALS(42, bj.getBalance(3));
	ASSERT_EQUALS(42, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(94, bj.getBalance(1));
	ASSERT_EQUALS(94, bj.getBalance(2));
	ASSERT_EQUALS(25, bj.getBalance(3));
	ASSERT_EQUALS(25, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(86, bj.getBalance(1));
	ASSERT_EQUALS(86, bj.getBalance(2));
	ASSERT_EQUALS(9, bj.getBalance(3));
	ASSERT_EQUALS(9, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(110, bj.getBalance(1));
	ASSERT_EQUALS(70, bj.getBalance(2));
	ASSERT_EQUALS(-6, bj.getBalance(3));
	ASSERT_EQUALS(31, bj.getBalance(4));
	bj.playRound();
	ASSERT_EQUALS(111, bj.getBalance(1));
	ASSERT_EQUALS(102, bj.getBalance(2));
	ASSERT_EQUALS(8, bj.getBalance(3));
	ASSERT_EQUALS(47, bj.getBalance(4));

	return true;
}

bool blackJackExample() {
	CardDeck deck;
	BlackJack bj(deck);
	bj.addPlayer(1, BlackJack::CASINO, 100);
	bj.addPlayer(2, BlackJack::CALCULATED, 100);
	ASSERT_THROW(PlayerDoesNotExistException, bj.joinGame(3));
	bj.joinGame({ 1, 2 });
	ASSERT_THROW(NotEnoughCardsException, bj.playRound());
	bj.reloadDeck(CardDeck::getFullDeck());
	bj.playRound();
	ASSERT_EQUALS(120, bj.getBalance(2));
	ASSERT_EQUALS(2, bj.getRichest());
	bj.leaveGame({ 1, 2 });

	return true;
}

bool blackJackTest(int testNum) {
	if (testNum == 0) {
		RUN_TEST(blackJackExample);
		RUN_TEST(blackJackPlayerAddTest);
		RUN_TEST(casinoStrategyTest);
		RUN_TEST(calculatedStrategyTest);
		RUN_TEST(playerBlackJackTest);
		RUN_TEST(playerNotBlackJack21noAceTest);
		RUN_TEST(playerNotBlackJack21withAceTest);
		RUN_TEST(playerStandTest);
		RUN_TEST(joinLeaveTest);
		RUN_TEST(richestTest);
		RUN_TEST(multiPlayerTest);
	}
	else {
		switch (testNum) {
		case 1:
			RUN_TEST(blackJackExample);
			break;
		case 2:
			RUN_TEST(blackJackPlayerAddTest);
			break;
		case 3:
			RUN_TEST(casinoStrategyTest);
			break;
		case 4:
			RUN_TEST(calculatedStrategyTest);
			break;
		case 5:
			RUN_TEST(playerBlackJackTest);
			break;
		case 6:
			RUN_TEST(playerNotBlackJack21noAceTest);
			break;
		case 7:
			RUN_TEST(playerNotBlackJack21withAceTest);
			break;
		case 8:
			RUN_TEST(playerStandTest);
			break;
		case 9:
			RUN_TEST(joinLeaveTest);
			break;
		case 10:
			RUN_TEST(richestTest);
			break;
		case 11:
			RUN_TEST(multiPlayerTest);
			break;
		}
	}

	return true;
}
