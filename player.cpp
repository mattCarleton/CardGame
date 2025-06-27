#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string name):name(name), state(PlayerState::playing) {
    resetHand();
}

// Return total score of cards in players hand as int
int Player::getScore() const
{
    int total = 0;
    int numAces = 0;

    for (auto &card:hand){
        total += card.getValue();
        if(card.getRank() == Rank::Ace){
            numAces++;
        }
    }

    // Aces can double as 1's and 11's so if score is over 21,
    // try reducing aces by 10 one at a time to lower the score
    while (total > 21 && numAces > 0){
        total -= 10;
        numAces--;
    }

    return total;
}

// Add a given card to players hand
void Player::addCard(const Card& card){
    hand.push_back(card);
    updateState();
}

// Player chooses to stand
void Player::stand(){
    state = PlayerState::stood;
}

// Clear player hand and state
void Player::resetHand(){
    hand.clear();
    state = PlayerState::playing;
}

// Turn logic for the player, prints current score to screen and allows player
// to choose between hit and stand
void Player::playTurn(Deck &deck)
{
    cout << "***" << name << "'s turn***" << endl;

    // Display current hand and score
    cout << "Current hand:" << endl;
    for (const auto &card:hand)
        cout << card.toString() << " ";
    cout << endl;
    cout << "Current score: " << getScore() << endl;

    while (state == PlayerState::playing) {
        // Get next action from user
        string input;
        cout << "\nWould you like to hit or stand? (h/s)" << endl;
        // loop until valid input
        while (true){
            getline(cin, input);
            if (input == "h"){
                addCard(deck.drawCard());
                // Display current hand and score
                cout << "\nCurrent hand:" << endl;
                for (const auto &card:hand)
                    cout << card.toString() << " ";
                cout << endl;
                cout << "Current score: " << getScore() << endl;
                break;
            }
            else if (input == "s"){
                stand();
                break;
            }
            else {
                cout << "Please enter a valid letter (h=hit, s=stand)" << endl;
            }
        }
    }

    // Player is no longer playing at this point so must either be stood,
    // busted, or blackjack
    switch (state){
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

// Set player state between blackjack, busted, and still playing based on score
void Player::updateState(){
    int score = getScore();
    if (score == 21 && hand.size() == 2)
        state = PlayerState::blackjack;
    else if (score > 21)
        state = PlayerState::busted;
    else
        state = PlayerState::playing;
}
