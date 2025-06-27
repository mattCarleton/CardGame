#ifndef CARD_GAME_H
#define CARD_GAME_H

#include "deck.h"
#include "player.h"
#include "dealer.h"

class CardGame
{
public:
    CardGame(std::string name = "Player");
    void play(void);
    void dealInitalHand(void);
    void showHands(void);
    void selectWinner(void);

private:
    Deck deck;
    Dealer dealer;
    Player player;
};

#endif // CARD_GAME_H
