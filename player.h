#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"
#include <vector>

enum class PlayerState {
    playing,
    stood,
    busted,
    blackjack
};

class Player
{
public:
    Player(std::string name = "Player");

    int getScore(void) const;
    void addCard(const Card& card);
    void stand(void);
    void resetHand(void);
    virtual void playTurn(Deck& deck);
    std::string getName(void) const;
    PlayerState getState(void) const;
    const std::vector<Card>& getHand(void) const;

protected:
    std::string name;
    std::vector<Card> hand;
    PlayerState state;

    void updateState(void);
};

#endif // PLAYER_H
