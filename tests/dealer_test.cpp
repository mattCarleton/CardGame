#include "dealer_test.h"
#include  "../dealer.h"
#include "../deck.h"
#include "../card.h"
#include <QTest>

void DealerTest::testAutoHit()
{
    Dealer dealer;
    Deck deck;
    Card c1(Rank::Six,Suit::Diamonds);
    Card c2(Rank::Nine,Suit::Spades);
    dealer.addCard(c1);
    dealer.addCard(c2);
    QVERIFY(dealer.getScore() == c1.getValue() + c2.getValue());
    // dealer total here is <17 so must hit
    dealer.playTurn(deck);
    QVERIFY(dealer.getHand().size() > 2);
    QVERIFY(dealer.getScore() > c1.getValue() + c2.getValue());
}

void DealerTest::testAutoStand()
{
    Dealer dealer;
    Deck deck;
    Card c1(Rank::King,Suit::Diamonds);
    Card c2(Rank::Nine,Suit::Spades);
    dealer.addCard(c1);
    dealer.addCard(c2);
    QVERIFY(dealer.getScore() == c1.getValue() + c2.getValue());
    // dealer total here is >17 so must stand
    dealer.playTurn(deck);
    QVERIFY(dealer.getState() == PlayerState::stood);
    QVERIFY(dealer.getHand().size() == 2);
    QVERIFY(dealer.getScore() == c1.getValue() + c2.getValue());
}
