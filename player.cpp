#include "player.h"

using namespace std;

Player::Player(string name):name(name) {
    resetHand();
}


int Player::getScore() const
{
    int total = 0;
    int numAces = 0;

    for(auto &card:hand){
        total += card.getValue();
        if(card.getRank() == Rank::Ace){
            numAces++;
        }
    }

    // Aces can double as 1's and 11's so if score is over 21,
    // try reducing aces by 10 one at a time
    while(total > 21 && numAces > 0){
        total -= 10;
        numAces--;
    }

    return total;
}

void Player::addCard(const Card& card){
    hand.push_back(card);
    updateState();
}

void Player::stand(){
    state = PlayerState::stood;
}

void Player::resetHand(){
    hand.clear();
    state = PlayerState::playing;
}

string Player::getName() const
{
    return name;
}

PlayerState Player::getState() const
{
    return state;
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

void Player::updateState(){
    int score = getScore();
    if(score == 21 && hand.size() == 2)
        state = PlayerState::stood;
    else if(score > 21)
        state = PlayerState::busted;
    else
        state = PlayerState::playing;
}
