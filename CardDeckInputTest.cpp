#include "CardDeckInputTest.h"
#include "MtmTst.h"

static bool compareDecks(CardDeck deck1, CardDeck deck2, bool withTop, bool withEmpty) {
	if (deck1.size() != deck2.size()) {
		return false;
	}
	while ((withEmpty && !deck1.isEmpty()) || (!withEmpty && deck1.size() > 0)) {
		if (deck2.isEmpty() || deck2.size() <= 0) {
			return false;
		}
		if (withTop && (deck1.top() != deck2.top())) {
			return false;
		}
		const Card& card1 = deck1.draw();
		const Card& card2 = deck2.draw();
		if (card1 != card2) {
			return false;
		}
	}
	if (!deck2.isEmpty() || deck2.size() != 0) {
		return false;
	}
	return true;
}

bool compareDecks(CardDeck deck1, CardDeck deck2) {
	if (!compareDecks(deck1, deck2, false, false))
		return false;
	if (!compareDecks(deck1, deck2, false, true))
		return false;
	if (!compareDecks(deck1, deck2, true, false))
		return false;
	if (!compareDecks(deck1, deck2, true, true))
		return false;
	return true;
}

bool inputTest6(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest7(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest8(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest9(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest10(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest11(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest12(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest13(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest14(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest15(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest16(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest17(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest18(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest19(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest20(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest21(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest22(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest23(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest24(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest25(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest26(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest27(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest28(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest29(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest30(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest31(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest32(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest33(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest34(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest35(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest36(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest37(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest38(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest39(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest40(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest41(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest42(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest43(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest44(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest45(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest46(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest47(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest48(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest49(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest50(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest51(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest52(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest53(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest54(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest55(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest56(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest57(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest58(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest59(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest60(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest61(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest62(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest63(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest64(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest65(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest66(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest67(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest68(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest69(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest70(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest71(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest72(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest73(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest74(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest75(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest76(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest77(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest78(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest79(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest80(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest81(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest82(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest83(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest84(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest85(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest86(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest87(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest88(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest89(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest90(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest91(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest92(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest93(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest94(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest95(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest96(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest97(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest98(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest99(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest100(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest101(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest102(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest103(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest104(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest105(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest106(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest107(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest108(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest109(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest110(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest111(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest112(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest113(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest114(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest115(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest116(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest117(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest118(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest119(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest120(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest121(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest122(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest123(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest124(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest125(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest126(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest127(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest128(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest129(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest130(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest131(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest132(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest133(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest134(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest135(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest136(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest137(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest138(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest139(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest140(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest141(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest142(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest143(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest144(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest145(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest146(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest147(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest148(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest149(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest150(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest151(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest152(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest153(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest154(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest155(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest156(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest157(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest158(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest159(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest160(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest161(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest162(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest163(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest164(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest165(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest166(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest167(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest168(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest169(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest170(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest171(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest172(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest173(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest174(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest175(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest176(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest177(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest178(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest179(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest180(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest181(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest182(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest183(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest184(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest185(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest186(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest187(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest188(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest189(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest190(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest191(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest192(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest193(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest194(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest195(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest196(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest197(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest198(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest199(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest200(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest201(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest202(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest203(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest204(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest205(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest206(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest207(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest208(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest209(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest210(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest211(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest212(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest213(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest214(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest215(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest216(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest217(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest218(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest219(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest220(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest221(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest222(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest223(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest224(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest225(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest226(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest227(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest228(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest229(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest230(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest231(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest232(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest233(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest234(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest235(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest236(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest237(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest238(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest239(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest240(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest241(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest242(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest243(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest244(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest245(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest246(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest247(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest248(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest249(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest250(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest251(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest252(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest253(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest254(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest255(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest256(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest257(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest258(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest259(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest260(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest261(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest262(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest263(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest264(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest265(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest266(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest267(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest268(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest269(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest270(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest271(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest272(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest273(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest274(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest275(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest276(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest277(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest278(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest279(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest280(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest281(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest282(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest283(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest284(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest285(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest286(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest287(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest288(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest289(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest290(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest291(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest292(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest293(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest294(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest295(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest296(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest297(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest298(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest299(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest300(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest301(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest302(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest303(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest304(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest305(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest306(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest307(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest308(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest309(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest310(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest311(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest312(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest313(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest314(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest315(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest316(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(17, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest317(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(13, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest318(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest319(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest320(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest321(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest322(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest323(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest324(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest325(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest326(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest327(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest328(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest329(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest330(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest331(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest332(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest333(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest334(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest335(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest336(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest337(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest338(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(14, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest339(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest340(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest341(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(11, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest342(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest343(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest344(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest345(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest346(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(19, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest347(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest348(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(10, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest349(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest350(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest351(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest352(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest353(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest354(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest355(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest356(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(13, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest357(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest358(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest359(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest360(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest361(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest362(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(14, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest363(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest364(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest365(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest366(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest367(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest368(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest369(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest370(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest371(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest372(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest373(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest374(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest375(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest376(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest377(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest378(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest379(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest380(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest381(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest382(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest383(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest384(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(16, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest385(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(19, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest386(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest387(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest388(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest389(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(11, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest390(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(20, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest391(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest392(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest393(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest394(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest395(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest396(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(28, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest397(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest398(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest399(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(19, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest400(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(10, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest401(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest402(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest403(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest404(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest405(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest406(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest407(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest408(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest409(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest410(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest411(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(13, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest412(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest413(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest414(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest415(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest416(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest417(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest418(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest419(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest420(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest421(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest422(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(14, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest423(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest424(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest425(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest426(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest427(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(22, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest428(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest429(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest430(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest431(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest432(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(10, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest433(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(13, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest434(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest435(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest436(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest437(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(43, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest438(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest439(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest440(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(28, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest441(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest442(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest443(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest444(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest445(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest446(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(24, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest447(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest448(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(13, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest449(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest450(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest451(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest452(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(32, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest453(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(10, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest454(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest455(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest456(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(25, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest457(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(11, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest458(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest459(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(10, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest460(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest461(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest462(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest463(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest464(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest465(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest466(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(23, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest467(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(3, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest468(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(14, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest469(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest470(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(45, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest471(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest472(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest473(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest474(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(41, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest475(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest476(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(29, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest477(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(40, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest478(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest479(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest480(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest481(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(28, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest482(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest483(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest484(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest485(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest486(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(28, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest487(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest488(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest489(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(30, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest490(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(5, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest491(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(8, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest492(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(7, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest493(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(21, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest494(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(9, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest495(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(12, deck.size());
	temp.clear();
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest496(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(58, deck.size());
	temp.clear();
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest497(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(51, deck.size());
	temp.clear();
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest498(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(28, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest499(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(18, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest500(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(15, deck.size());
	temp.clear();
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest501(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(22, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest502(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(4, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 10);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest503(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(6, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest504(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(16, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest505(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(54, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest506(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(85, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 3);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest507(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(47, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest508(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(22, deck.size());
	temp.clear();
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest509(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(45, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 'J');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest510(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(66, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 5);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest511(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(23, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Diamond, 'K');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest512(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(11, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest513(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(90, deck.size());
	temp.clear();
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Spade, 1);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 'Q');
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest514(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(2, deck.size());
	temp.clear();
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest515(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(39, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 1);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest516(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(103, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Diamond, 7);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 4);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest517(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(92, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Spade, 5);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 3);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 1);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Heart, 10);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Diamond, 'Q');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 2);
	temp += Card(Card::Heart, 5);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 8);
	temp += Card(Card::Club, 1);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 3);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Diamond, 8);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest518(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(21, deck.size());
	temp.clear();
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Club, 1);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Heart, 7);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 6);
	temp += Card(Card::Heart, 8);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Spade, 'J');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Club, 5);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest519(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(17, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 'K');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 9);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 1);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Spade, 7);
	temp += Card(Card::Club, 6);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest520(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(23, deck.size());
	temp.clear();
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 'Q');
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 'K');
	temp += Card(Card::Club, 'J');
	temp += Card(Card::Heart, 3);
	temp += Card(Card::Heart, 9);
	temp += Card(Card::Diamond, 'J');
	temp += Card(Card::Heart, 2);
	temp += Card(Card::Club, 5);
	temp += Card(Card::Heart, 6);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Heart, 4);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Diamond, 5);
	temp += Card(Card::Diamond, 3);
	temp += Card(Card::Club, 2);
	temp += Card(Card::Spade, 8);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 'J');
	temp += Card(Card::Heart, 'K');
	temp += Card(Card::Club, 2);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest521(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(26, deck.size());
	temp.clear();
	temp += Card(Card::Club, 4);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 6);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Spade, 10);
	temp += Card(Card::Club, 6);
	temp += Card(Card::Club, 'K');
	temp += Card(Card::Diamond, 4);
	temp += Card(Card::Diamond, 9);
	temp += Card(Card::Diamond, 8);
	temp += Card(Card::Club, 'Q');
	temp += Card(Card::Diamond, 2);
	temp += Card(Card::Spade, 4);
	temp += Card(Card::Club, 10);
	temp += Card(Card::Spade, 'Q');
	temp += Card(Card::Club, 10);
	temp += Card(Card::Club, 3);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Club, 4);
	temp += Card(Card::Diamond, 10);
	temp += Card(Card::Spade, 9);
	temp += Card(Card::Club, 7);
	temp += Card(Card::Heart, 7);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}

bool inputTest522(std::istream& input, CardDeck& deck, CardDeck& temp) {
	input >> deck;
	ASSERT_EQUALS(1, deck.size());
	temp.clear();
	temp += Card(Card::Club, 9);
	ASSERT_EQUALS(true, compareDecks(deck, temp));
	return true;
}