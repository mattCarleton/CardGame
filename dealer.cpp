#include "dealer.h"

Dealer::Dealer(std::string name):Player(name) {}

void Dealer::playTurn(Deck& deck)
{
    // Dealer plays until either blackjack, busted, or stood
    while(getScore()<17 && getState() == PlayerState::playing)
        addCard(deck.drawCard());

    if (getState() == PlayerState::playing)
        stand();
}
