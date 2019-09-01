/*
 * CardDeckTest.cpp
 *
 *  Created on: Apr 11, 2018
 *      Author: Ben
 */

#include "CardDeck.h"
//#include "CardDeckInputTest.h"
#include "Exceptions.h"
#include "MtmTst.h"

#include <cstdlib>	/* srand, rand */
#include <cassert>
#include <ctime>	/* time */
#include <vector>

using mtm::CardWrongArgsException;
using mtm::CardDeckIsEmptyException;
using std::endl;
using std::vector;


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
static bool checkAllComparisons(CardDeck first, CardDeck second, bool hasLessCards, bool hasSameCards) {
    if (hasLessCards) {
        if (!(first < second)) return false;
        if ((second < first)) return false;

        if (!(first <= second)) return false;
        if ((second <= first)) return false;

        if ((first > second)) return false;
        if (!(second > first)) return false;

        if ((first >= second)) return false;
        if (!(second >= first)) return false;

        if (!(first != second)) return false;
        if (!(second != first)) return false;

        if ((first == second)) return false;
        if ((second == first)) return false;
    }
    if (hasSameCards) {
        if ((first < second)) return false;
        if ((second < first)) return false;

        if (!(first <= second)) return false;
        if (!(second <= first)) return false;

        if ((first > second)) return false;
        if ((second > first)) return false;

        if (!(first >= second)) return false;
        if (!(second >= first)) return false;

        if (compareDecks(first, second)) {
            if ((first != second)) return false;
            if ((second != first)) return false;

            if (!(first == second)) return false;
            if (!(second == first)) return false;
        } else {
            if (!(first != second)) return false;
            if (!(second != first)) return false;

            if ((first == second)) return false;
            if ((second == first)) return false;
        }
    }

    return true;
}

bool cardDeckFullTest() {
    CardDeck deck;
    for (Card::Suit suit : {Card::Heart, Card::Diamond, Card::Club, Card::Spade}) {
        for (int i = 1; i <= 10; ++i) {
            deck += Card(suit, i);
        }
        for (char c : {'j','q','k'}) {
            deck += Card(suit, c);
        }
    }

    compareDecks(deck, CardDeck::getFullDeck());

    CardDeck::getFullDeck().draw();
    ASSERT_EQUALS(Card(Card::Spade, 'K'), CardDeck::getFullDeck().top());

    return true;
}
//#pragma region cardDeckInput
DEFINE_INPUT_TEST(cardDeckInput)
    CardDeck deck;
    CardDeck temp;
    // Test 1
    input >> deck;
    temp.clear();
    ASSERT_EQUALS(true, compareDecks(deck, temp));
    // Test 2
    ASSERT_THROW(CardWrongArgsException, input >> deck);
    temp.clear();
    ASSERT_EQUALS(true, compareDecks(deck, temp));
    // Test 3
    input >> deck;
    temp.clear();
    temp += Card(Card::Heart, 'J');
    ASSERT_EQUALS(true, compareDecks(deck, temp));
    // Test 4
    ASSERT_THROW(CardWrongArgsException, input >> deck);
    temp.clear();
    ASSERT_EQUALS(true, compareDecks(deck, temp));
    // Test 5
    ASSERT_THROW(CardWrongArgsException, input >> deck);
    temp.clear();
    temp += Card(Card::Diamond, 'k');
    ASSERT_EQUALS(true, compareDecks(deck, temp));

    ASSERT_EQUALS(true, inputTest6(input, deck, temp));
    ASSERT_EQUALS(true, inputTest7(input, deck, temp));
    ASSERT_EQUALS(true, inputTest8(input, deck, temp));
    ASSERT_EQUALS(true, inputTest9(input, deck, temp));
    ASSERT_EQUALS(true, inputTest10(input, deck, temp));
    ASSERT_EQUALS(true, inputTest11(input, deck, temp));
    ASSERT_EQUALS(true, inputTest12(input, deck, temp));
    ASSERT_EQUALS(true, inputTest13(input, deck, temp));
    ASSERT_EQUALS(true, inputTest14(input, deck, temp));
    ASSERT_EQUALS(true, inputTest15(input, deck, temp));
    ASSERT_EQUALS(true, inputTest16(input, deck, temp));
    ASSERT_EQUALS(true, inputTest17(input, deck, temp));
    ASSERT_EQUALS(true, inputTest18(input, deck, temp));
    ASSERT_EQUALS(true, inputTest19(input, deck, temp));
    ASSERT_EQUALS(true, inputTest20(input, deck, temp));
    ASSERT_EQUALS(true, inputTest21(input, deck, temp));
    ASSERT_EQUALS(true, inputTest22(input, deck, temp));
    ASSERT_EQUALS(true, inputTest23(input, deck, temp));
    ASSERT_EQUALS(true, inputTest24(input, deck, temp));
    ASSERT_EQUALS(true, inputTest25(input, deck, temp));
    ASSERT_EQUALS(true, inputTest26(input, deck, temp));
    ASSERT_EQUALS(true, inputTest27(input, deck, temp));
    ASSERT_EQUALS(true, inputTest28(input, deck, temp));
    ASSERT_EQUALS(true, inputTest29(input, deck, temp));
    ASSERT_EQUALS(true, inputTest30(input, deck, temp));
    ASSERT_EQUALS(true, inputTest31(input, deck, temp));
    ASSERT_EQUALS(true, inputTest32(input, deck, temp));
    ASSERT_EQUALS(true, inputTest33(input, deck, temp));
    ASSERT_EQUALS(true, inputTest34(input, deck, temp));
    ASSERT_EQUALS(true, inputTest35(input, deck, temp));
    ASSERT_EQUALS(true, inputTest36(input, deck, temp));
    ASSERT_EQUALS(true, inputTest37(input, deck, temp));
    ASSERT_EQUALS(true, inputTest38(input, deck, temp));
    ASSERT_EQUALS(true, inputTest39(input, deck, temp));
    ASSERT_EQUALS(true, inputTest40(input, deck, temp));
    ASSERT_EQUALS(true, inputTest41(input, deck, temp));
    ASSERT_EQUALS(true, inputTest42(input, deck, temp));
    ASSERT_EQUALS(true, inputTest43(input, deck, temp));
    ASSERT_EQUALS(true, inputTest44(input, deck, temp));
    ASSERT_EQUALS(true, inputTest45(input, deck, temp));
    ASSERT_EQUALS(true, inputTest46(input, deck, temp));
    ASSERT_EQUALS(true, inputTest47(input, deck, temp));
    ASSERT_EQUALS(true, inputTest48(input, deck, temp));
    ASSERT_EQUALS(true, inputTest49(input, deck, temp));
    ASSERT_EQUALS(true, inputTest50(input, deck, temp));
    ASSERT_EQUALS(true, inputTest51(input, deck, temp));
    ASSERT_EQUALS(true, inputTest52(input, deck, temp));
    ASSERT_EQUALS(true, inputTest53(input, deck, temp));
    ASSERT_EQUALS(true, inputTest54(input, deck, temp));
    ASSERT_EQUALS(true, inputTest55(input, deck, temp));
    ASSERT_EQUALS(true, inputTest56(input, deck, temp));
    ASSERT_EQUALS(true, inputTest57(input, deck, temp));
    ASSERT_EQUALS(true, inputTest58(input, deck, temp));
    ASSERT_EQUALS(true, inputTest59(input, deck, temp));
    ASSERT_EQUALS(true, inputTest60(input, deck, temp));
    ASSERT_EQUALS(true, inputTest61(input, deck, temp));
    ASSERT_EQUALS(true, inputTest62(input, deck, temp));
    ASSERT_EQUALS(true, inputTest63(input, deck, temp));
    ASSERT_EQUALS(true, inputTest64(input, deck, temp));
    ASSERT_EQUALS(true, inputTest65(input, deck, temp));
    ASSERT_EQUALS(true, inputTest66(input, deck, temp));
    ASSERT_EQUALS(true, inputTest67(input, deck, temp));
    ASSERT_EQUALS(true, inputTest68(input, deck, temp));
    ASSERT_EQUALS(true, inputTest69(input, deck, temp));
    ASSERT_EQUALS(true, inputTest70(input, deck, temp));
    ASSERT_EQUALS(true, inputTest71(input, deck, temp));
    ASSERT_EQUALS(true, inputTest72(input, deck, temp));
    ASSERT_EQUALS(true, inputTest73(input, deck, temp));
    ASSERT_EQUALS(true, inputTest74(input, deck, temp));
    ASSERT_EQUALS(true, inputTest75(input, deck, temp));
    ASSERT_EQUALS(true, inputTest76(input, deck, temp));
    ASSERT_EQUALS(true, inputTest77(input, deck, temp));
    ASSERT_EQUALS(true, inputTest78(input, deck, temp));
    ASSERT_EQUALS(true, inputTest79(input, deck, temp));
    ASSERT_EQUALS(true, inputTest80(input, deck, temp));
    ASSERT_EQUALS(true, inputTest81(input, deck, temp));
    ASSERT_EQUALS(true, inputTest82(input, deck, temp));
    ASSERT_EQUALS(true, inputTest83(input, deck, temp));
    ASSERT_EQUALS(true, inputTest84(input, deck, temp));
    ASSERT_EQUALS(true, inputTest85(input, deck, temp));
    ASSERT_EQUALS(true, inputTest86(input, deck, temp));
    ASSERT_EQUALS(true, inputTest87(input, deck, temp));
    ASSERT_EQUALS(true, inputTest88(input, deck, temp));
    ASSERT_EQUALS(true, inputTest89(input, deck, temp));
    ASSERT_EQUALS(true, inputTest90(input, deck, temp));
    ASSERT_EQUALS(true, inputTest91(input, deck, temp));
    ASSERT_EQUALS(true, inputTest92(input, deck, temp));
    ASSERT_EQUALS(true, inputTest93(input, deck, temp));
    ASSERT_EQUALS(true, inputTest94(input, deck, temp));
    ASSERT_EQUALS(true, inputTest95(input, deck, temp));
    ASSERT_EQUALS(true, inputTest96(input, deck, temp));
    ASSERT_EQUALS(true, inputTest97(input, deck, temp));
    ASSERT_EQUALS(true, inputTest98(input, deck, temp));
    ASSERT_EQUALS(true, inputTest99(input, deck, temp));
    ASSERT_EQUALS(true, inputTest100(input, deck, temp));
    ASSERT_EQUALS(true, inputTest101(input, deck, temp));
    ASSERT_EQUALS(true, inputTest102(input, deck, temp));
    ASSERT_EQUALS(true, inputTest103(input, deck, temp));
    ASSERT_EQUALS(true, inputTest104(input, deck, temp));
    ASSERT_EQUALS(true, inputTest105(input, deck, temp));
    ASSERT_EQUALS(true, inputTest106(input, deck, temp));
    ASSERT_EQUALS(true, inputTest107(input, deck, temp));
    ASSERT_EQUALS(true, inputTest108(input, deck, temp));
    ASSERT_EQUALS(true, inputTest109(input, deck, temp));
    ASSERT_EQUALS(true, inputTest110(input, deck, temp));
    ASSERT_EQUALS(true, inputTest111(input, deck, temp));
    ASSERT_EQUALS(true, inputTest112(input, deck, temp));
    ASSERT_EQUALS(true, inputTest113(input, deck, temp));
    ASSERT_EQUALS(true, inputTest114(input, deck, temp));
    ASSERT_EQUALS(true, inputTest115(input, deck, temp));
    ASSERT_EQUALS(true, inputTest116(input, deck, temp));
    ASSERT_EQUALS(true, inputTest117(input, deck, temp));
    ASSERT_EQUALS(true, inputTest118(input, deck, temp));
    ASSERT_EQUALS(true, inputTest119(input, deck, temp));
    ASSERT_EQUALS(true, inputTest120(input, deck, temp));
    ASSERT_EQUALS(true, inputTest121(input, deck, temp));
    ASSERT_EQUALS(true, inputTest122(input, deck, temp));
    ASSERT_EQUALS(true, inputTest123(input, deck, temp));
    ASSERT_EQUALS(true, inputTest124(input, deck, temp));
    ASSERT_EQUALS(true, inputTest125(input, deck, temp));
    ASSERT_EQUALS(true, inputTest126(input, deck, temp));
    ASSERT_EQUALS(true, inputTest127(input, deck, temp));
    ASSERT_EQUALS(true, inputTest128(input, deck, temp));
    ASSERT_EQUALS(true, inputTest129(input, deck, temp));
    ASSERT_EQUALS(true, inputTest130(input, deck, temp));
    ASSERT_EQUALS(true, inputTest131(input, deck, temp));
    ASSERT_EQUALS(true, inputTest132(input, deck, temp));
    ASSERT_EQUALS(true, inputTest133(input, deck, temp));
    ASSERT_EQUALS(true, inputTest134(input, deck, temp));
    ASSERT_EQUALS(true, inputTest135(input, deck, temp));
    ASSERT_EQUALS(true, inputTest136(input, deck, temp));
    ASSERT_EQUALS(true, inputTest137(input, deck, temp));
    ASSERT_EQUALS(true, inputTest138(input, deck, temp));
    ASSERT_EQUALS(true, inputTest139(input, deck, temp));
    ASSERT_EQUALS(true, inputTest140(input, deck, temp));
    ASSERT_EQUALS(true, inputTest141(input, deck, temp));
    ASSERT_EQUALS(true, inputTest142(input, deck, temp));
    ASSERT_EQUALS(true, inputTest143(input, deck, temp));
    ASSERT_EQUALS(true, inputTest144(input, deck, temp));
    ASSERT_EQUALS(true, inputTest145(input, deck, temp));
    ASSERT_EQUALS(true, inputTest146(input, deck, temp));
    ASSERT_EQUALS(true, inputTest147(input, deck, temp));
    ASSERT_EQUALS(true, inputTest148(input, deck, temp));
    ASSERT_EQUALS(true, inputTest149(input, deck, temp));
    ASSERT_EQUALS(true, inputTest150(input, deck, temp));
    ASSERT_EQUALS(true, inputTest151(input, deck, temp));
    ASSERT_EQUALS(true, inputTest152(input, deck, temp));
    ASSERT_EQUALS(true, inputTest153(input, deck, temp));
    ASSERT_EQUALS(true, inputTest154(input, deck, temp));
    ASSERT_EQUALS(true, inputTest155(input, deck, temp));
    ASSERT_EQUALS(true, inputTest156(input, deck, temp));
    ASSERT_EQUALS(true, inputTest157(input, deck, temp));
    ASSERT_EQUALS(true, inputTest158(input, deck, temp));
    ASSERT_EQUALS(true, inputTest159(input, deck, temp));
    ASSERT_EQUALS(true, inputTest160(input, deck, temp));
    ASSERT_EQUALS(true, inputTest161(input, deck, temp));
    ASSERT_EQUALS(true, inputTest162(input, deck, temp));
    ASSERT_EQUALS(true, inputTest163(input, deck, temp));
    ASSERT_EQUALS(true, inputTest164(input, deck, temp));
    ASSERT_EQUALS(true, inputTest165(input, deck, temp));
    ASSERT_EQUALS(true, inputTest166(input, deck, temp));
    ASSERT_EQUALS(true, inputTest167(input, deck, temp));
    ASSERT_EQUALS(true, inputTest168(input, deck, temp));
    ASSERT_EQUALS(true, inputTest169(input, deck, temp));
    ASSERT_EQUALS(true, inputTest170(input, deck, temp));
    ASSERT_EQUALS(true, inputTest171(input, deck, temp));
    ASSERT_EQUALS(true, inputTest172(input, deck, temp));
    ASSERT_EQUALS(true, inputTest173(input, deck, temp));
    ASSERT_EQUALS(true, inputTest174(input, deck, temp));
    ASSERT_EQUALS(true, inputTest175(input, deck, temp));
    ASSERT_EQUALS(true, inputTest176(input, deck, temp));
    ASSERT_EQUALS(true, inputTest177(input, deck, temp));
    ASSERT_EQUALS(true, inputTest178(input, deck, temp));
    ASSERT_EQUALS(true, inputTest179(input, deck, temp));
    ASSERT_EQUALS(true, inputTest180(input, deck, temp));
    ASSERT_EQUALS(true, inputTest181(input, deck, temp));
    ASSERT_EQUALS(true, inputTest182(input, deck, temp));
    ASSERT_EQUALS(true, inputTest183(input, deck, temp));
    ASSERT_EQUALS(true, inputTest184(input, deck, temp));
    ASSERT_EQUALS(true, inputTest185(input, deck, temp));
    ASSERT_EQUALS(true, inputTest186(input, deck, temp));
    ASSERT_EQUALS(true, inputTest187(input, deck, temp));
    ASSERT_EQUALS(true, inputTest188(input, deck, temp));
    ASSERT_EQUALS(true, inputTest189(input, deck, temp));
    ASSERT_EQUALS(true, inputTest190(input, deck, temp));
    ASSERT_EQUALS(true, inputTest191(input, deck, temp));
    ASSERT_EQUALS(true, inputTest192(input, deck, temp));
    ASSERT_EQUALS(true, inputTest193(input, deck, temp));
    ASSERT_EQUALS(true, inputTest194(input, deck, temp));
    ASSERT_EQUALS(true, inputTest195(input, deck, temp));
    ASSERT_EQUALS(true, inputTest196(input, deck, temp));
    ASSERT_EQUALS(true, inputTest197(input, deck, temp));
    ASSERT_EQUALS(true, inputTest198(input, deck, temp));
    ASSERT_EQUALS(true, inputTest199(input, deck, temp));
    ASSERT_EQUALS(true, inputTest200(input, deck, temp));
    ASSERT_EQUALS(true, inputTest201(input, deck, temp));
    ASSERT_EQUALS(true, inputTest202(input, deck, temp));
    ASSERT_EQUALS(true, inputTest203(input, deck, temp));
    ASSERT_EQUALS(true, inputTest204(input, deck, temp));
    ASSERT_EQUALS(true, inputTest205(input, deck, temp));
    ASSERT_EQUALS(true, inputTest206(input, deck, temp));
    ASSERT_EQUALS(true, inputTest207(input, deck, temp));
    ASSERT_EQUALS(true, inputTest208(input, deck, temp));
    ASSERT_EQUALS(true, inputTest209(input, deck, temp));
    ASSERT_EQUALS(true, inputTest210(input, deck, temp));
    ASSERT_EQUALS(true, inputTest211(input, deck, temp));
    ASSERT_EQUALS(true, inputTest212(input, deck, temp));
    ASSERT_EQUALS(true, inputTest213(input, deck, temp));
    ASSERT_EQUALS(true, inputTest214(input, deck, temp));
    ASSERT_EQUALS(true, inputTest215(input, deck, temp));
    ASSERT_EQUALS(true, inputTest216(input, deck, temp));
    ASSERT_EQUALS(true, inputTest217(input, deck, temp));
    ASSERT_EQUALS(true, inputTest218(input, deck, temp));
    ASSERT_EQUALS(true, inputTest219(input, deck, temp));
    ASSERT_EQUALS(true, inputTest220(input, deck, temp));
    ASSERT_EQUALS(true, inputTest221(input, deck, temp));
    ASSERT_EQUALS(true, inputTest222(input, deck, temp));
    ASSERT_EQUALS(true, inputTest223(input, deck, temp));
    ASSERT_EQUALS(true, inputTest224(input, deck, temp));
    ASSERT_EQUALS(true, inputTest225(input, deck, temp));
    ASSERT_EQUALS(true, inputTest226(input, deck, temp));
    ASSERT_EQUALS(true, inputTest227(input, deck, temp));
    ASSERT_EQUALS(true, inputTest228(input, deck, temp));
    ASSERT_EQUALS(true, inputTest229(input, deck, temp));
    ASSERT_EQUALS(true, inputTest230(input, deck, temp));
    ASSERT_EQUALS(true, inputTest231(input, deck, temp));
    ASSERT_EQUALS(true, inputTest232(input, deck, temp));
    ASSERT_EQUALS(true, inputTest233(input, deck, temp));
    ASSERT_EQUALS(true, inputTest234(input, deck, temp));
    ASSERT_EQUALS(true, inputTest235(input, deck, temp));
    ASSERT_EQUALS(true, inputTest236(input, deck, temp));
    ASSERT_EQUALS(true, inputTest237(input, deck, temp));
    ASSERT_EQUALS(true, inputTest238(input, deck, temp));
    ASSERT_EQUALS(true, inputTest239(input, deck, temp));
    ASSERT_EQUALS(true, inputTest240(input, deck, temp));
    ASSERT_EQUALS(true, inputTest241(input, deck, temp));
    ASSERT_EQUALS(true, inputTest242(input, deck, temp));
    ASSERT_EQUALS(true, inputTest243(input, deck, temp));
    ASSERT_EQUALS(true, inputTest244(input, deck, temp));
    ASSERT_EQUALS(true, inputTest245(input, deck, temp));
    ASSERT_EQUALS(true, inputTest246(input, deck, temp));
    ASSERT_EQUALS(true, inputTest247(input, deck, temp));
    ASSERT_EQUALS(true, inputTest248(input, deck, temp));
    ASSERT_EQUALS(true, inputTest249(input, deck, temp));
    ASSERT_EQUALS(true, inputTest250(input, deck, temp));
    ASSERT_EQUALS(true, inputTest251(input, deck, temp));
    ASSERT_EQUALS(true, inputTest252(input, deck, temp));
    ASSERT_EQUALS(true, inputTest253(input, deck, temp));
    ASSERT_EQUALS(true, inputTest254(input, deck, temp));
    ASSERT_EQUALS(true, inputTest255(input, deck, temp));
    ASSERT_EQUALS(true, inputTest256(input, deck, temp));
    ASSERT_EQUALS(true, inputTest257(input, deck, temp));
    ASSERT_EQUALS(true, inputTest258(input, deck, temp));
    ASSERT_EQUALS(true, inputTest259(input, deck, temp));
    ASSERT_EQUALS(true, inputTest260(input, deck, temp));
    ASSERT_EQUALS(true, inputTest261(input, deck, temp));
    ASSERT_EQUALS(true, inputTest262(input, deck, temp));
    ASSERT_EQUALS(true, inputTest263(input, deck, temp));
    ASSERT_EQUALS(true, inputTest264(input, deck, temp));
    ASSERT_EQUALS(true, inputTest265(input, deck, temp));
    ASSERT_EQUALS(true, inputTest266(input, deck, temp));
    ASSERT_EQUALS(true, inputTest267(input, deck, temp));
    ASSERT_EQUALS(true, inputTest268(input, deck, temp));
    ASSERT_EQUALS(true, inputTest269(input, deck, temp));
    ASSERT_EQUALS(true, inputTest270(input, deck, temp));
    ASSERT_EQUALS(true, inputTest271(input, deck, temp));
    ASSERT_EQUALS(true, inputTest272(input, deck, temp));
    ASSERT_EQUALS(true, inputTest273(input, deck, temp));
    ASSERT_EQUALS(true, inputTest274(input, deck, temp));
    ASSERT_EQUALS(true, inputTest275(input, deck, temp));
    ASSERT_EQUALS(true, inputTest276(input, deck, temp));
    ASSERT_EQUALS(true, inputTest277(input, deck, temp));
    ASSERT_EQUALS(true, inputTest278(input, deck, temp));
    ASSERT_EQUALS(true, inputTest279(input, deck, temp));
    ASSERT_EQUALS(true, inputTest280(input, deck, temp));
    ASSERT_EQUALS(true, inputTest281(input, deck, temp));
    ASSERT_EQUALS(true, inputTest282(input, deck, temp));
    ASSERT_EQUALS(true, inputTest283(input, deck, temp));
    ASSERT_EQUALS(true, inputTest284(input, deck, temp));
    ASSERT_EQUALS(true, inputTest285(input, deck, temp));
    ASSERT_EQUALS(true, inputTest286(input, deck, temp));
    ASSERT_EQUALS(true, inputTest287(input, deck, temp));
    ASSERT_EQUALS(true, inputTest288(input, deck, temp));
    ASSERT_EQUALS(true, inputTest289(input, deck, temp));
    ASSERT_EQUALS(true, inputTest290(input, deck, temp));
    ASSERT_EQUALS(true, inputTest291(input, deck, temp));
    ASSERT_EQUALS(true, inputTest292(input, deck, temp));
    ASSERT_EQUALS(true, inputTest293(input, deck, temp));
    ASSERT_EQUALS(true, inputTest294(input, deck, temp));
    ASSERT_EQUALS(true, inputTest295(input, deck, temp));
    ASSERT_EQUALS(true, inputTest296(input, deck, temp));
    ASSERT_EQUALS(true, inputTest297(input, deck, temp));
    ASSERT_EQUALS(true, inputTest298(input, deck, temp));
    ASSERT_EQUALS(true, inputTest299(input, deck, temp));
    ASSERT_EQUALS(true, inputTest300(input, deck, temp));
    ASSERT_EQUALS(true, inputTest301(input, deck, temp));
    ASSERT_EQUALS(true, inputTest302(input, deck, temp));
    ASSERT_EQUALS(true, inputTest303(input, deck, temp));
    ASSERT_EQUALS(true, inputTest304(input, deck, temp));
    ASSERT_EQUALS(true, inputTest305(input, deck, temp));
    ASSERT_EQUALS(true, inputTest306(input, deck, temp));
    ASSERT_EQUALS(true, inputTest307(input, deck, temp));
    ASSERT_EQUALS(true, inputTest308(input, deck, temp));
    ASSERT_EQUALS(true, inputTest309(input, deck, temp));
    ASSERT_EQUALS(true, inputTest310(input, deck, temp));
    ASSERT_EQUALS(true, inputTest311(input, deck, temp));
    ASSERT_EQUALS(true, inputTest312(input, deck, temp));
    ASSERT_EQUALS(true, inputTest313(input, deck, temp));
    ASSERT_EQUALS(true, inputTest314(input, deck, temp));
    ASSERT_EQUALS(true, inputTest315(input, deck, temp));
    ASSERT_EQUALS(true, inputTest316(input, deck, temp));
    ASSERT_EQUALS(true, inputTest317(input, deck, temp));
    ASSERT_EQUALS(true, inputTest318(input, deck, temp));
    ASSERT_EQUALS(true, inputTest319(input, deck, temp));
    ASSERT_EQUALS(true, inputTest320(input, deck, temp));
    ASSERT_EQUALS(true, inputTest321(input, deck, temp));
    ASSERT_EQUALS(true, inputTest322(input, deck, temp));
    ASSERT_EQUALS(true, inputTest323(input, deck, temp));
    ASSERT_EQUALS(true, inputTest324(input, deck, temp));
    ASSERT_EQUALS(true, inputTest325(input, deck, temp));
    ASSERT_EQUALS(true, inputTest326(input, deck, temp));
    ASSERT_EQUALS(true, inputTest327(input, deck, temp));
    ASSERT_EQUALS(true, inputTest328(input, deck, temp));
    ASSERT_EQUALS(true, inputTest329(input, deck, temp));
    ASSERT_EQUALS(true, inputTest330(input, deck, temp));
    ASSERT_EQUALS(true, inputTest331(input, deck, temp));
    ASSERT_EQUALS(true, inputTest332(input, deck, temp));
    ASSERT_EQUALS(true, inputTest333(input, deck, temp));
    ASSERT_EQUALS(true, inputTest334(input, deck, temp));
    ASSERT_EQUALS(true, inputTest335(input, deck, temp));
    ASSERT_EQUALS(true, inputTest336(input, deck, temp));
    ASSERT_EQUALS(true, inputTest337(input, deck, temp));
    ASSERT_EQUALS(true, inputTest338(input, deck, temp));
    ASSERT_EQUALS(true, inputTest339(input, deck, temp));
    ASSERT_EQUALS(true, inputTest340(input, deck, temp));
    ASSERT_EQUALS(true, inputTest341(input, deck, temp));
    ASSERT_EQUALS(true, inputTest342(input, deck, temp));
    ASSERT_EQUALS(true, inputTest343(input, deck, temp));
    ASSERT_EQUALS(true, inputTest344(input, deck, temp));
    ASSERT_EQUALS(true, inputTest345(input, deck, temp));
    ASSERT_EQUALS(true, inputTest346(input, deck, temp));
    ASSERT_EQUALS(true, inputTest347(input, deck, temp));
    ASSERT_EQUALS(true, inputTest348(input, deck, temp));
    ASSERT_EQUALS(true, inputTest349(input, deck, temp));
    ASSERT_EQUALS(true, inputTest350(input, deck, temp));
    ASSERT_EQUALS(true, inputTest351(input, deck, temp));
    ASSERT_EQUALS(true, inputTest352(input, deck, temp));
    ASSERT_EQUALS(true, inputTest353(input, deck, temp));
    ASSERT_EQUALS(true, inputTest354(input, deck, temp));
    ASSERT_EQUALS(true, inputTest355(input, deck, temp));
    ASSERT_EQUALS(true, inputTest356(input, deck, temp));
    ASSERT_EQUALS(true, inputTest357(input, deck, temp));
    ASSERT_EQUALS(true, inputTest358(input, deck, temp));
    ASSERT_EQUALS(true, inputTest359(input, deck, temp));
    ASSERT_EQUALS(true, inputTest360(input, deck, temp));
    ASSERT_EQUALS(true, inputTest361(input, deck, temp));
    ASSERT_EQUALS(true, inputTest362(input, deck, temp));
    ASSERT_EQUALS(true, inputTest363(input, deck, temp));
    ASSERT_EQUALS(true, inputTest364(input, deck, temp));
    ASSERT_EQUALS(true, inputTest365(input, deck, temp));
    ASSERT_EQUALS(true, inputTest366(input, deck, temp));
    ASSERT_EQUALS(true, inputTest367(input, deck, temp));
    ASSERT_EQUALS(true, inputTest368(input, deck, temp));
    ASSERT_EQUALS(true, inputTest369(input, deck, temp));
    ASSERT_EQUALS(true, inputTest370(input, deck, temp));
    ASSERT_EQUALS(true, inputTest371(input, deck, temp));
    ASSERT_EQUALS(true, inputTest372(input, deck, temp));
    ASSERT_EQUALS(true, inputTest373(input, deck, temp));
    ASSERT_EQUALS(true, inputTest374(input, deck, temp));
    ASSERT_EQUALS(true, inputTest375(input, deck, temp));
    ASSERT_EQUALS(true, inputTest376(input, deck, temp));
    ASSERT_EQUALS(true, inputTest377(input, deck, temp));
    ASSERT_EQUALS(true, inputTest378(input, deck, temp));
    ASSERT_EQUALS(true, inputTest379(input, deck, temp));
    ASSERT_EQUALS(true, inputTest380(input, deck, temp));
    ASSERT_EQUALS(true, inputTest381(input, deck, temp));
    ASSERT_EQUALS(true, inputTest382(input, deck, temp));
    ASSERT_EQUALS(true, inputTest383(input, deck, temp));
    ASSERT_EQUALS(true, inputTest384(input, deck, temp));
    ASSERT_EQUALS(true, inputTest385(input, deck, temp));
    ASSERT_EQUALS(true, inputTest386(input, deck, temp));
    ASSERT_EQUALS(true, inputTest387(input, deck, temp));
    ASSERT_EQUALS(true, inputTest388(input, deck, temp));
    ASSERT_EQUALS(true, inputTest389(input, deck, temp));
    ASSERT_EQUALS(true, inputTest390(input, deck, temp));
    ASSERT_EQUALS(true, inputTest391(input, deck, temp));
    ASSERT_EQUALS(true, inputTest392(input, deck, temp));
    ASSERT_EQUALS(true, inputTest393(input, deck, temp));
    ASSERT_EQUALS(true, inputTest394(input, deck, temp));
    ASSERT_EQUALS(true, inputTest395(input, deck, temp));
    ASSERT_EQUALS(true, inputTest396(input, deck, temp));
    ASSERT_EQUALS(true, inputTest397(input, deck, temp));
    ASSERT_EQUALS(true, inputTest398(input, deck, temp));
    ASSERT_EQUALS(true, inputTest399(input, deck, temp));
    ASSERT_EQUALS(true, inputTest400(input, deck, temp));
    ASSERT_EQUALS(true, inputTest401(input, deck, temp));
    ASSERT_EQUALS(true, inputTest402(input, deck, temp));
    ASSERT_EQUALS(true, inputTest403(input, deck, temp));
    ASSERT_EQUALS(true, inputTest404(input, deck, temp));
    ASSERT_EQUALS(true, inputTest405(input, deck, temp));
    ASSERT_EQUALS(true, inputTest406(input, deck, temp));
    ASSERT_EQUALS(true, inputTest407(input, deck, temp));
    ASSERT_EQUALS(true, inputTest408(input, deck, temp));
    ASSERT_EQUALS(true, inputTest409(input, deck, temp));
    ASSERT_EQUALS(true, inputTest410(input, deck, temp));
    ASSERT_EQUALS(true, inputTest411(input, deck, temp));
    ASSERT_EQUALS(true, inputTest412(input, deck, temp));
    ASSERT_EQUALS(true, inputTest413(input, deck, temp));
    ASSERT_EQUALS(true, inputTest414(input, deck, temp));
    ASSERT_EQUALS(true, inputTest415(input, deck, temp));
    ASSERT_EQUALS(true, inputTest416(input, deck, temp));
    ASSERT_EQUALS(true, inputTest417(input, deck, temp));
    ASSERT_EQUALS(true, inputTest418(input, deck, temp));
    ASSERT_EQUALS(true, inputTest419(input, deck, temp));
    ASSERT_EQUALS(true, inputTest420(input, deck, temp));
    ASSERT_EQUALS(true, inputTest421(input, deck, temp));
    ASSERT_EQUALS(true, inputTest422(input, deck, temp));
    ASSERT_EQUALS(true, inputTest423(input, deck, temp));
    ASSERT_EQUALS(true, inputTest424(input, deck, temp));
    ASSERT_EQUALS(true, inputTest425(input, deck, temp));
    ASSERT_EQUALS(true, inputTest426(input, deck, temp));
    ASSERT_EQUALS(true, inputTest427(input, deck, temp));
    ASSERT_EQUALS(true, inputTest428(input, deck, temp));
    ASSERT_EQUALS(true, inputTest429(input, deck, temp));
    ASSERT_EQUALS(true, inputTest430(input, deck, temp));
    ASSERT_EQUALS(true, inputTest431(input, deck, temp));
    ASSERT_EQUALS(true, inputTest432(input, deck, temp));
    ASSERT_EQUALS(true, inputTest433(input, deck, temp));
    ASSERT_EQUALS(true, inputTest434(input, deck, temp));
    ASSERT_EQUALS(true, inputTest435(input, deck, temp));
    ASSERT_EQUALS(true, inputTest436(input, deck, temp));
    ASSERT_EQUALS(true, inputTest437(input, deck, temp));
    ASSERT_EQUALS(true, inputTest438(input, deck, temp));
    ASSERT_EQUALS(true, inputTest439(input, deck, temp));
    ASSERT_EQUALS(true, inputTest440(input, deck, temp));
    ASSERT_EQUALS(true, inputTest441(input, deck, temp));
    ASSERT_EQUALS(true, inputTest442(input, deck, temp));
    ASSERT_EQUALS(true, inputTest443(input, deck, temp));
    ASSERT_EQUALS(true, inputTest444(input, deck, temp));
    ASSERT_EQUALS(true, inputTest445(input, deck, temp));
    ASSERT_EQUALS(true, inputTest446(input, deck, temp));
    ASSERT_EQUALS(true, inputTest447(input, deck, temp));
    ASSERT_EQUALS(true, inputTest448(input, deck, temp));
    ASSERT_EQUALS(true, inputTest449(input, deck, temp));
    ASSERT_EQUALS(true, inputTest450(input, deck, temp));
    ASSERT_EQUALS(true, inputTest451(input, deck, temp));
    ASSERT_EQUALS(true, inputTest452(input, deck, temp));
    ASSERT_EQUALS(true, inputTest453(input, deck, temp));
    ASSERT_EQUALS(true, inputTest454(input, deck, temp));
    ASSERT_EQUALS(true, inputTest455(input, deck, temp));
    ASSERT_EQUALS(true, inputTest456(input, deck, temp));
    ASSERT_EQUALS(true, inputTest457(input, deck, temp));
    ASSERT_EQUALS(true, inputTest458(input, deck, temp));
    ASSERT_EQUALS(true, inputTest459(input, deck, temp));
    ASSERT_EQUALS(true, inputTest460(input, deck, temp));
    ASSERT_EQUALS(true, inputTest461(input, deck, temp));
    ASSERT_EQUALS(true, inputTest462(input, deck, temp));
    ASSERT_EQUALS(true, inputTest463(input, deck, temp));
    ASSERT_EQUALS(true, inputTest464(input, deck, temp));
    ASSERT_EQUALS(true, inputTest465(input, deck, temp));
    ASSERT_EQUALS(true, inputTest466(input, deck, temp));
    ASSERT_EQUALS(true, inputTest467(input, deck, temp));
    ASSERT_EQUALS(true, inputTest468(input, deck, temp));
    ASSERT_EQUALS(true, inputTest469(input, deck, temp));
    ASSERT_EQUALS(true, inputTest470(input, deck, temp));
    ASSERT_EQUALS(true, inputTest471(input, deck, temp));
    ASSERT_EQUALS(true, inputTest472(input, deck, temp));
    ASSERT_EQUALS(true, inputTest473(input, deck, temp));
    ASSERT_EQUALS(true, inputTest474(input, deck, temp));
    ASSERT_EQUALS(true, inputTest475(input, deck, temp));
    ASSERT_EQUALS(true, inputTest476(input, deck, temp));
    ASSERT_EQUALS(true, inputTest477(input, deck, temp));
    ASSERT_EQUALS(true, inputTest478(input, deck, temp));
    ASSERT_EQUALS(true, inputTest479(input, deck, temp));
    ASSERT_EQUALS(true, inputTest480(input, deck, temp));
    ASSERT_EQUALS(true, inputTest481(input, deck, temp));
    ASSERT_EQUALS(true, inputTest482(input, deck, temp));
    ASSERT_EQUALS(true, inputTest483(input, deck, temp));
    ASSERT_EQUALS(true, inputTest484(input, deck, temp));
    ASSERT_EQUALS(true, inputTest485(input, deck, temp));
    ASSERT_EQUALS(true, inputTest486(input, deck, temp));
    ASSERT_EQUALS(true, inputTest487(input, deck, temp));
    ASSERT_EQUALS(true, inputTest488(input, deck, temp));
    ASSERT_EQUALS(true, inputTest489(input, deck, temp));
    ASSERT_EQUALS(true, inputTest490(input, deck, temp));
    ASSERT_EQUALS(true, inputTest491(input, deck, temp));
    ASSERT_EQUALS(true, inputTest492(input, deck, temp));
    ASSERT_EQUALS(true, inputTest493(input, deck, temp));
    ASSERT_EQUALS(true, inputTest494(input, deck, temp));
    ASSERT_EQUALS(true, inputTest495(input, deck, temp));
    ASSERT_EQUALS(true, inputTest496(input, deck, temp));
    ASSERT_EQUALS(true, inputTest497(input, deck, temp));
    ASSERT_EQUALS(true, inputTest498(input, deck, temp));
    ASSERT_EQUALS(true, inputTest499(input, deck, temp));
    ASSERT_EQUALS(true, inputTest500(input, deck, temp));
    ASSERT_EQUALS(true, inputTest501(input, deck, temp));
    ASSERT_EQUALS(true, inputTest502(input, deck, temp));
    ASSERT_EQUALS(true, inputTest503(input, deck, temp));
    ASSERT_EQUALS(true, inputTest504(input, deck, temp));
    ASSERT_EQUALS(true, inputTest505(input, deck, temp));
    ASSERT_EQUALS(true, inputTest506(input, deck, temp));
    ASSERT_EQUALS(true, inputTest507(input, deck, temp));
    ASSERT_EQUALS(true, inputTest508(input, deck, temp));
    ASSERT_EQUALS(true, inputTest509(input, deck, temp));
    ASSERT_EQUALS(true, inputTest510(input, deck, temp));
    ASSERT_EQUALS(true, inputTest511(input, deck, temp));
    ASSERT_EQUALS(true, inputTest512(input, deck, temp));
    ASSERT_EQUALS(true, inputTest513(input, deck, temp));
    ASSERT_EQUALS(true, inputTest514(input, deck, temp));
    ASSERT_EQUALS(true, inputTest515(input, deck, temp));
    ASSERT_EQUALS(true, inputTest516(input, deck, temp));
    ASSERT_EQUALS(true, inputTest517(input, deck, temp));
    ASSERT_EQUALS(true, inputTest518(input, deck, temp));
    ASSERT_EQUALS(true, inputTest519(input, deck, temp));
    ASSERT_EQUALS(true, inputTest520(input, deck, temp));
    ASSERT_EQUALS(true, inputTest521(input, deck, temp));
    ASSERT_EQUALS(true, inputTest522(input, deck, temp));

    /*
    int testNum = 6;
    std::ofstream ofs("temp.txt");
    while (!input.eof()) {
        input >> deck;
        //ofs << "ASSERT_EQUALS(true, inputTest" << testNum << "(input, deck, temp));" << endl;

        ofs << "bool inputTest" << testNum
            << "(std::iostream& input, CardDeck& deck, CardDeck& temp) {" << endl;
        ofs << "	input >> deck;" << endl;
        ofs << "	ASSERT_EQUALS(" << deck.size() << ", deck.size());" << endl;
        ofs << "	temp.clear();" << endl;
        deck.reverse();
        while (!deck.isEmpty()) {
            Card card = deck.draw();
            ofs << "	temp += Card(Card::";
            ofs << card.suitName() << ", " << card.ctorInitilizer() << ");" << endl;
        }
        ofs << "	ASSERT_EQUALS(true, compareDecks(deck, temp));" << endl;
        ofs << "	return true;" << endl;
        ofs << '}' << endl << endl;

        testNum++;
    }
    */
    return true;
}
//#pragma endregion cardDeckInput

DEFINE_INPUT_TEST(cardDeckOutput)
    CardDeck deck;

    //std::stringstream sstrm;
    //ostream& os = sstrm;
    ostream& os = std::cout;

    input >> deck;
    os << deck << endl;

    ASSERT_THROW(CardWrongArgsException, input >> deck);
    os << deck << endl;

    input >> deck;
    os << deck << endl;

    ASSERT_THROW(CardWrongArgsException, input >> deck);
    os << deck << endl;

    ASSERT_THROW(CardWrongArgsException, input >> deck);
    os << deck << endl;

    while (!input.eof()) {
        input >> deck;
        os << deck << endl;
    }

    os << deck << endl;

    return true;
}

// one test for draw, top, size, isEmpty, clear
bool cardDeckBasicActions() {
    CardDeck deck;
    ASSERT_EQUALS(true, deck.isEmpty());
    ASSERT_EQUALS(0, deck.size());
    ASSERT_THROW(CardDeckIsEmptyException, deck.top());
    ASSERT_THROW(CardDeckIsEmptyException, deck.draw());
    Card  top = CardDeck::getFullDeck().top();
    ASSERT_EQUALS(Card(Card::Spade,'K'), top);

    deck += (Card(Card::Diamond, 'Q') + top + top + Card(Card::Club, 7));
    ASSERT_EQUALS(Card(Card::Club, 7), deck.top());
    deck.draw();
    Card card = deck.draw();
    ASSERT_EQUALS(2, deck.size());
    ASSERT_EQUALS(deck.top(), card);
    ASSERT_EQUALS(false, deck.isEmpty());
    ASSERT_EQUALS(false, CardDeck::getFullDeck().isEmpty());
    CardDeck::getFullDeck().clear();
    ASSERT_EQUALS(false, CardDeck::getFullDeck().isEmpty());
    deck.clear();
    ASSERT_EQUALS(0, deck.size());
    ASSERT_EQUALS(true, deck.isEmpty());
    deck += Card(Card::Diamond, 10);
    ASSERT_EQUALS(1, deck.size());
    ASSERT_EQUALS(false, deck.isEmpty());
    ASSERT_EQUALS(Card(Card::Diamond, 10), deck.top());
    deck += Card(Card::Diamond, 9);
    ASSERT_EQUALS(2, deck.size());
    ASSERT_EQUALS(false, deck.isEmpty());
    ASSERT_EQUALS(Card(Card::Diamond, 9), deck.top());

    return true;
}

DEFINE_INPUT_TEST(cardDeckValueTest)
    CardDeck deck;
    ASSERT_EQUALS(0, deck.value());
    Card ace = Card(Card::Heart, 1);
    ASSERT_EQUALS(0, deck.value());
    for (int i = 2; i <= 10; ++i) {
        Card card = Card(Card::Diamond, i);
        ASSERT_EQUALS((unsigned)i, (deck + card).value());
    }
    for (char c : {'K','Q','J'}) {
        Card card = Card(Card::Diamond, c);
        ASSERT_EQUALS(10, (deck + card).value());
    }
    for (int i = 11; i <= 21; i++) {
        deck += ace;
        ASSERT_EQUALS((unsigned)i, deck.value());
    }
    for (int i = 12; i <= 21; ++i) {
        deck += ace;
        ASSERT_EQUALS((unsigned)i, deck.value());
    }
    deck += ace;
    ASSERT_EQUALS(42, deck.value());
    deck += ace;
    ASSERT_EQUALS(33, deck.value());

    deck.clear();
    deck += ace;
    deck += Card(Card::Club, 'K');
    deck += Card(Card::Club, 'Q');
    deck += Card(Card::Club, 'J');
    deck += Card(Card::Club, 5);
    deck += Card(Card::Club, 6);

    ASSERT_EQUALS(42, deck.value());

    deck.draw();
    deck += Card(Card::Club, 7);
    ASSERT_EQUALS(53, deck.value());

    deck.draw();
    deck += Card(Card::Club, 6);
    deck += ace;
    ASSERT_EQUALS(63, deck.value());

    deck += ace;
    ASSERT_EQUALS(54, deck.value());

    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(42, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(10, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(2, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(3, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(9, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(20, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(3, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(40, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(20, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(9, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(10, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(38, deck.value());
    input >> deck;
    ASSERT_EQUALS(13, deck.value());
    input >> deck;
    ASSERT_EQUALS(20, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(12, deck.value());
    input >> deck;
    ASSERT_EQUALS(20, deck.value());
    input >> deck;
    ASSERT_EQUALS(42, deck.value());
    input >> deck;
    ASSERT_EQUALS(34, deck.value());
    input >> deck;
    ASSERT_EQUALS(10, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(4, deck.value());
    input >> deck;
    ASSERT_EQUALS(39, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(41, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(31, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(26, deck.value());
    input >> deck;
    ASSERT_EQUALS(14, deck.value());
    input >> deck;
    ASSERT_EQUALS(76, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(11, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(19, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(16, deck.value());
    input >> deck;
    ASSERT_EQUALS(21, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(20, deck.value());
    input >> deck;
    ASSERT_EQUALS(78, deck.value());
    input >> deck;
    ASSERT_EQUALS(18, deck.value());
    input >> deck;
    ASSERT_EQUALS(40, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(5, deck.value());
    input >> deck;
    ASSERT_EQUALS(15, deck.value());
    input >> deck;
    ASSERT_EQUALS(54, deck.value());
    input >> deck;
    ASSERT_EQUALS(58, deck.value());
    input >> deck;
    ASSERT_EQUALS(41, deck.value());
    input >> deck;
    ASSERT_EQUALS(17, deck.value());
    input >> deck;
    ASSERT_EQUALS(181, deck.value());
    input >> deck;
    ASSERT_EQUALS(63, deck.value());
    input >> deck;
    ASSERT_EQUALS(83, deck.value());
    input >> deck;
    ASSERT_EQUALS(105, deck.value());
    input >> deck;
    ASSERT_EQUALS(208, deck.value());
    input >> deck;
    ASSERT_EQUALS(103, deck.value());
    input >> deck;
    ASSERT_EQUALS(124, deck.value());

    /*
    std::ofstream ofs("temp.txt");
    while (!input.eof()) {
        ofs << "input >> deck;" << endl;;
        input >> deck;
        ofs << "ASSERT_EQUALS(" << deck.value() << ", deck.value());" << endl;
    }

    CardDeck aces = (Card(Card::Heart, 1) + Card(Card::Diamond, 1) + Card(Card::Club, 1) + Card(Card::Spade, 1));
    std::ofstream ofs("temp.txt");
    for (int i = 1; i <= 99; ++i) {
        CardDeck deck = randomDeck(i,aces,i - i % 10);
        if (!deck.isEmpty()) {
            ofs << deck << endl;
        }
        deck = randomDeck(i, aces, 90 - (i - i % 10));
        if (!deck.isEmpty()) {
            ofs << deck << endl;
        }
    }
    */

    return true;
}

DEFINE_INPUT_TEST(cardDeckComparisonTest)
    ASSERT_EQUALS(true, checkAllComparisons(CardDeck(), CardDeck(), false, true));
    CardDeck singleCardDeck = Card(Card::Spade, 7);
    CardDeck doubleCardDeck = (singleCardDeck + singleCardDeck);

    ASSERT_EQUALS(true, checkAllComparisons(singleCardDeck, singleCardDeck, false, false));
    ASSERT_EQUALS(true, checkAllComparisons(CardDeck(), doubleCardDeck, true, false));
    ASSERT_EQUALS(true, checkAllComparisons(singleCardDeck, doubleCardDeck, true, false));
    ASSERT_EQUALS(true, checkAllComparisons(doubleCardDeck, doubleCardDeck, false, true));

    CardDeck first;
    CardDeck second;

    while (!input.eof()) {
        std::string inputStr;
        input >> inputStr;
        if (inputStr == "<=:") {
            input >> inputStr;
            assert(inputStr == "STRICT:");
            bool strict;
            input >> strict;
            for (int i = 0; i < 2; ++i) {
                input >> first;
                input >> second;
                ASSERT_EQUALS(true, checkAllComparisons(first, second, strict, !strict));
            }
        } else {
            assert(inputStr == "!=:");
            input >> first;
            input >> second;
            ASSERT_EQUALS(true, checkAllComparisons(first, second, false, false));
        }
    }
    /*
    std::ofstream decksOfs("temp.txt");

    srand((unsigned)time(NULL));

    CardDeck deck;

    while (deck.size() < 10) {
        deck = randomDeck(90);
    }
    decksOfs << deck << endl;
    for (int i = 5; i <= 95; i+=3) {
        for (int j = i; j <= 95; j += 3) {
            bool isStrict = randomParitalDecks(deck, &first, &second, i, j);
            if (first.isEmpty() && second.isEmpty()) {
                j -= 3;
                continue;
            }
            decksOfs << "<=: STRICT: ";
            decksOfs << isStrict << endl;
            decksOfs << first << endl;
            decksOfs << second << endl;
            first.shuffle();
            second.shuffle();
            decksOfs << first << endl;
            decksOfs << second << endl;
        }
    }

    for (int i = 0; i < 10; i++) {
        first = randomDeck((i + 1) * 10 - 1);
        second = randomDeck((i+1)*10-1);
        if (first.isEmpty() || second.isEmpty()) {
            i--;
            continue;
        }
        decksOfs << "!=:" << endl;
        decksOfs << first << endl;
        decksOfs << second << endl;
    }
    */
    return true;
}
/*
static void generateCombinations(const CardDeck& first, const CardDeck& second,
	std::ostream& in, std::ostream& out) {
	in << '+' << endl;
	in << first << endl;
	in << second << endl;
	out << (first + second) << endl;
	in << '+' << endl;
	in << second << endl;
	in << first << endl;
	out << (second + first) << endl;
	in << '+' << endl;
	in << first << endl;
	in << first << endl;
	out << (first + first) << endl;
	in << '+' << endl;
	in << second << endl;
	in << second << endl;
	out << (second + second) << endl;
}

static void generateThreeCombinations(CardDeck first, CardDeck second,
	CardDeck third, std::ostream& in, std::ostream& out) {
	in << "+3" << endl;
	in << first << endl;
	in << second << endl;
	in << third << endl;
	out << (first + second + third) << endl;
	in << "+=3" << endl;
	in << first << endl;
	in << second << endl;
	in << third << endl;
	out << (first + second + third) << endl;
	out << (second) << endl;
	out << (third) << endl;

	out << (first) << endl;
	out << (second + third) << endl;
	out << (third + first) << endl;

	out << (first + second + third + third + first) << endl;
	out << (second + third + third + first) << endl;
	out << (third + first) << endl;
}
*/
DEFINE_INPUT_TEST(cardDeckArithmeticOperatorsTest)

    //std::stringstream sstrm;
    //ostream& os = sstrm;
    ostream& os = std::cout;
    while (!input.eof()) {
        std::string op;
        input >> op;
        CardDeck first;
        CardDeck second;
        CardDeck third;
        if (op == "+") {
            input >> first;
            input >> second;
            os << (first + second) << endl;
        }
        else if (op == "+3") {
            input >> first;
            input >> second;
            input >> third;
            os << (first + second + third) << endl;
        }
        else if (op == "+=3") {
            input >> first;
            input >> second;
            input >> third;
            CardDeck firstCopy = first;
            first += second;
            first += third;
            os << (first) << endl;
            os << (second) << endl;
            os << (third) << endl;
            first = firstCopy;
            second += third;
            third += first;
            os << (first) << endl;
            os << (second) << endl;
            os << (third) << endl;

            first += (second += third);
            os << (first) << endl;
            os << (second) << endl;
            os << (third) << endl;
        } else if (op == "*") {
            input >> first;
            os << 0 * first << endl << first * 0 << endl;
            os << 1 * first << endl << first * 1 << endl;
            os << 2 * first << endl << first * 2 << endl;
            os << 3 * first << endl << first * 3 << endl;
        } else {
            os << "unexpected op: " << op << endl;
        }
    }
    /*
    std::ofstream decksOfs("temp.txt");
    std::ofstream outOfs("output/cardDeckArithmeticOperatorsTest.out");
    srand((unsigned)time(NULL));
    CardDeck first;
    CardDeck second;
    decksOfs << '+' << endl;
    decksOfs << first << endl;
    decksOfs << second << endl;
    outOfs << (first + second) << endl;
    for (int i = 10; i <= 99; i += 4) {
        second = randomDeck(i);

        if (second.isEmpty()) {
            i -= 4;
            continue;
        }
        generateCombinations(first, second, decksOfs, outOfs);
    }
    for (int i = 20; i <= 99; i+=3) {
        for (int j = 20; j <= 99; j+=3) {
            first = randomDeck(i);
            second = randomDeck(j);
            CardDeck third = randomDeck(max(i,j));

            if (first.isEmpty() || second.isEmpty() || third.isEmpty()) {
                j-=3;
                continue;
            }
            generateThreeCombinations(first, second, third, decksOfs, outOfs);
        }
    }
    decksOfs << '*' << endl;
    decksOfs << CardDeck() << endl;
    for (int i = 0; i < 8; ++i) {
        outOfs << 0 << endl;
    }
    for (int i = 20; i <= 99; i += 5) {
        first = randomDeck(i);

        if (first.isEmpty()) {
            i -= 5;
            continue;
        }
        decksOfs << '*' << endl;
        decksOfs << first << endl;
        outOfs << CardDeck() << endl << CardDeck() << endl;
        outOfs << first * 1 << endl << 1 * first << endl;
        outOfs << first * 2 << endl << 2 * first << endl;
        outOfs << first * 3 << endl << 3 * first << endl;
    }
    */

    return true;
}

DEFINE_INPUT_TEST(cardDeckExample)
    CardDeck emptyDeck;
    CardDeck fullDeck = CardDeck::getFullDeck();
    Card kingSpade = fullDeck.draw();
    ASSERT_EQUALS(kingSpade, Card(Card::Spade, 'K'));
    ASSERT_EQUALS(Card(Card::Spade, 'Q'), fullDeck.top());
    ASSERT_THROW(CardDeckIsEmptyException, emptyDeck.top());
    unsigned expecetdSize = 51;
    ASSERT_EQUALS(expecetdSize, fullDeck.size());
    ASSERT_EQUALS(true, emptyDeck.isEmpty());
    CardDeck singleCardDeck = kingSpade;
    singleCardDeck.clear();
    Card twoDiamond(Card::Diamond, 2);
    singleCardDeck = twoDiamond;
    unsigned expectedValue = 2;
    ASSERT_EQUALS(expectedValue, singleCardDeck.value());
    singleCardDeck += kingSpade;
    ASSERT_EQUALS(kingSpade, singleCardDeck.top());
    CardDeck newDeck;
    input >> newDeck;
    ASSERT_EQUALS(Card(Card::Club,4), newDeck.top());
    std::cout << newDeck * 2 << endl;
    CardDeck first;
    CardDeck second;
    input >> first;
    input >> second;
    std::cout << first + second << endl;

    CardDeck smallDeck = Card(Card::Diamond, 7) + Card(Card::Diamond, 10);
    ASSERT_EQUALS(true, smallDeck < fullDeck);
    ASSERT_EQUALS(true, smallDeck <= fullDeck);
    ASSERT_EQUALS(true, fullDeck > smallDeck);
    ASSERT_EQUALS(true, fullDeck >= smallDeck);
    ASSERT_EQUALS(true, fullDeck != smallDeck);
    ASSERT_EQUALS(false, fullDeck == smallDeck);

    return true;
}

bool cardDeckTest(int testNum) {
    if (testNum == 0) {
        RUN_TEST(cardDeckExample);
        RUN_TEST(cardDeckFullTest);
        RUN_TEST(cardDeckInput);
        RUN_TEST(cardDeckOutput);
        RUN_TEST(cardDeckBasicActions);
        RUN_TEST(cardDeckValueTest);
        RUN_TEST(cardDeckComparisonTest);
        RUN_TEST(cardDeckArithmeticOperatorsTest);
    }
    else {
        switch (testNum) {
            case 1:
                RUN_TEST(cardDeckExample);
                break;
            case 2:
                RUN_TEST(cardDeckFullTest);
                break;
            case 3:
                RUN_TEST(cardDeckInput);
                break;
            case 4:
                RUN_TEST(cardDeckOutput);
                break;
            case 5:
                RUN_TEST(cardDeckBasicActions);
                break;
            case 6:
                RUN_TEST(cardDeckValueTest);
                break;
            case 7:
                RUN_TEST(cardDeckComparisonTest);
                break;
            case 8:
                RUN_TEST(cardDeckArithmeticOperatorsTest);
                break;
        }
    }

    return true;
}
