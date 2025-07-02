#ifndef DEALER_H
#define DEALER_H
#include "player.h"

class Dealer : public Player
{
public:
    Dealer(std::string name = "Dealer");
    void playTurn(Deck& deck) override;
};

#endif // DEALER_H
