#include "deck_test.h"
#include <QtTest>
#include "../deck.h"

void DeckTest::testDeckGenerate(){
    Deck deck;
    QVERIFY(!deck.isEmpty());
}

void DeckTest::testShuffler(){
    Deck deck1;
    Deck deck2;
    QVERIFY(deck1.getDeckAsString() != deck2.getDeckAsString());
}

void DeckTest::testDraw(){
    Deck deck;
    int originalSize = DECK_SIZE;
    QVERIFY(deck.numRemainingCards() == originalSize);
    Card c = deck.drawCard();
    QVERIFY(deck.numRemainingCards() == originalSize-1);
}
