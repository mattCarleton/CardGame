#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
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

    int getScore() const;
    void addCard(const Card& card);
    void stand();
    void resetHand();
    std::string getName() const;
    PlayerState getState() const;
    const std::vector<Card>& getHand() const;

protected:
    std::string name;
    std::vector<Card> hand;
    PlayerState state = PlayerState::playing;

    void updateState();
};

#endif // PLAYER_H
