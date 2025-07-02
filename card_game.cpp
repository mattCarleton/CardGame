#include "card_game.h"
#include <iostream>
using namespace std;

CardGame::CardGame(string name):dealer("Dealer"), player(name) {}

// Main sequence for a game
void CardGame::play(void)
{
    deck.reset();
    player.resetHand();
    dealer.resetHand();

    dealInitalHand();

    player.playTurn(deck);
    dealer.playTurn(deck);

    showHands();
    selectWinner();
}

// Deal 2 cards to each player, show one card from dealers hand
void CardGame::dealInitalHand(void)
{
    player.addCard(deck.drawCard());
    dealer.addCard(deck.drawCard());

    player.addCard(deck.drawCard());
    dealer.addCard(deck.drawCard());

    cout << dealer.getName() << " shows:" << endl;
    cout << dealer.getHand().front().toString() << "\n" << endl;
}

// Prints both players hands to console
void CardGame::showHands(void)
{
    cout << "\n-------------------------------\n" << endl;
    cout << dealer.getName() << "'s hand: " << endl;
    for(const auto &card:dealer.getHand()){
        cout << card.toString() << " ";
    }
    cout << endl;
    cout << "Score: " << dealer.getScore() << endl;

    cout << "\n" << player.getName() << "'s hand: " << endl;
    for(const auto &card:player.getHand()){
        cout << card.toString() << " ";
    }
    cout << endl;
    cout << "Score: " << player.getScore() << endl;
}

// Determines winner based on player and dealers totals
void CardGame::selectWinner(void)
{
    PlayerState pState = player.getState();
    PlayerState dState = dealer.getState();

    cout << endl;

    // If both player and dealer have blackjack, no winner
    if (pState == PlayerState::blackjack && dState == PlayerState::blackjack){
        cout << "\033[33m" << "Both " << dealer.getName() << " and " << player.getName()
        << " have blackjack! No Winner" << "\033[0m" << endl;
        return;
    }

    // If player has blackjack and dealer doesnt, player wins
    if (pState == PlayerState::blackjack && dState != PlayerState::blackjack){
        cout << "\033[32m" << player.getName() << " wins with blackjack!" << "\033[0m" << endl;
        return;
    }

    // If dealer has blackjack and player doesnt, dealer wins
    if (pState != PlayerState::blackjack && dState == PlayerState::blackjack){
        cout << "\033[31m" << dealer.getName() << " wins with blackjack!" << "\033[0m" << endl;
        return;
    }

    // If player busted, player loses no matter dealers hand
    if (pState == PlayerState::busted){
        cout << "\033[31m" << player.getName() << " busted! " << dealer.getName()
             << " wins!" << "\033[0m" << endl;
        return;
    }

    // If player didnt bust and dealer did, player wins
    if(pState != PlayerState::busted && dState == PlayerState::busted){
        cout << "\033[32m" << dealer.getName() << " busted! " << player.getName()
             << " wins!" << "\033[0m" << endl;
        return;
    }   

    // If both player and dealer stand, highest score wins (possibility of tie)
    if (pState == PlayerState::stood && dState == PlayerState::stood){
        if (player.getScore() == dealer.getScore()){
            cout << "\033[33mPush! No winner" << "\033[0m" << endl;
            return;
        } else if (player.getScore() > dealer.getScore()){
            cout << "\033[32m" << player.getName() << " wins with " << player.getScore() << "\033[0m" << endl;
            return;
        } else{
            cout << "\033[31m" << dealer.getName() << " wins with " << dealer.getScore() << "\033[0m" << endl;
            return;
        }
    }

    cout << "Game ended unexpectedly. No winner" << endl;
}




