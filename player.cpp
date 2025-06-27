#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string name):name(name), state(PlayerState::playing) {
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

void Player::playTurn(Deck &deck)
{
    cout << "***Player " << name << "'s turn***" << endl;
    while (getState() == PlayerState::playing) {
        // Display current hand and score
        cout << "Current hand:" << endl;
        for(const auto &card:hand)
            cout << card.toString() << " ";
        cout << endl;
        cout << "Current score: " << getScore() << endl;

        // Get next action from user
        string input = "";
        cout << "Would you like to hit or stand? (h/s)" << endl;
        while(input != "h" && input != "s"){
            cin >> input;
            if(input == "h")
                addCard(deck.drawCard());
            else if(input == "s")
                stand();
            else
                cout << "Please enter a valid letter (h=hit, s=stand)" << endl;
        }
    }

    switch(getState()){
    case PlayerState::stood:
        cout << "Standing" << endl;
        break;
    case PlayerState::busted:
        cout << "Busted!" << endl;
        break;
    case PlayerState::blackjack:
        cout << "Blackjack!" << endl;
        break;
    default:
        break;
    }
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
        state = PlayerState::blackjack;
    else if(score > 21)
        state = PlayerState::busted;
    else
        state = PlayerState::playing;
}
