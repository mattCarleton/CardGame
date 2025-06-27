#include "card_test.h"
#include "../card.h"
#include <QtTest>

void CardTest::testSimpleCard(){
    Card card(Rank::Six, Suit::Diamonds);
    QVERIFY(card.getRank() == Rank::Six);
    QVERIFY(card.getSuit() == Suit::Diamonds);
    QVERIFY(card.toString() == "6♦");
}

