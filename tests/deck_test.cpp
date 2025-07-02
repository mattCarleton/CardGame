#include "deck_test.h"
#include <QtTest>
#include "../deck.h"

void DeckTest::testDeckGenerate(void){
    Deck deck;
    QVERIFY(!deck.isEmpty());
}

void DeckTest::testShuffler(void){
    Deck deck1;
    Deck deck2;
    // Insanely low chance of this being true
    QVERIFY(deck1.getDeckAsString() != deck2.getDeckAsString());
}

void DeckTest::testDraw(void){
    Deck deck;
    int originalSize = DECK_SIZE;
    QVERIFY(deck.numRemainingCards() == originalSize);
    Card c = deck.drawCard();
    QVERIFY(deck.numRemainingCards() == originalSize-1);
}
