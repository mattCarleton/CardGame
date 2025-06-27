#ifndef PLAYCARDGAME_H
#define PLAYCARDGAME_H

#include "deck.h"
#include "player.h"
#include "dealer.h"

class PlayCardGame
{
public:
    PlayCardGame(void);
    void dealInitalHand(void);
    void selectWinner(void);
    void playGame(void);
    void showHands(void);

private:
    Deck deck;
    Player player;
    Dealer dealer;
};

#endif // PLAYCARDGAME_H
