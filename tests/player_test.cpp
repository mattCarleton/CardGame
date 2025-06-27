#include "player_test.h"
#include <QtTest>
#include "../player.h"

using namespace std;

void PlayerTest::testPlayerCreation()
{
    string name = "Matt";
    Player player(name);
    QVERIFY(player.getName() == name);
}

void PlayerTest::testPlayerAdd()
{
    Player player;
    Card card(Rank::Five, Suit::Spades);
    QVERIFY(player.getHand().size() == 0);
    player.addCard(card);
    QVERIFY(player.getHand().size() == 1);
}

void PlayerTest::testPlayerDraw()
{
    Player player;
    Deck deck;
    player.addCard(deck.drawCard());
    QVERIFY(deck.numRemainingCards()==DECK_SIZE-1);
    QVERIFY(player.getHand().size() == 1);
}

void PlayerTest::testPlayerStand()
{
    Player player;
    QVERIFY(player.getState() == PlayerState::playing);
    player.stand();
    QVERIFY(player.getState() == PlayerState::stood);

}

void PlayerTest::testPlayerScore()
{
    Player player;
    Card c1(Rank::Five, Suit::Diamonds);
    Card c2(Rank::Four, Suit::Diamonds);
    player.addCard(c1);
    player.addCard(c2);
    QVERIFY(player.getScore() == c1.getValue() + c2.getValue());
}

void PlayerTest::testAce(){
    Player player;
    Card c1(Rank::Seven,Suit::Clubs);
    Card c2(Rank::Nine,Suit::Spades);
    player.addCard(c1);
    player.addCard(c2);
    QVERIFY(player.getScore() == c1.getValue() + c2.getValue());
    Card c3(Rank::Ace, Suit::Spades);
    player.addCard(c3);
    QVERIFY(player.getScore() == c1.getValue() + c2.getValue() + c3.getValue() - 10);
}

void PlayerTest::testBlackjack(){
    Player player;
    Card c1(Rank::Queen, Suit::Clubs);
    Card c2(Rank::Ace, Suit::Hearts);
    player.addCard(c1);
    player.addCard(c2);
    QVERIFY(player.getScore() == c1.getValue() + c2.getValue());
    QVERIFY(player.getState() == PlayerState::blackjack);
}

















