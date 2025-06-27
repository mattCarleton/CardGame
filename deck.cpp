#include "deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <chrono>

using namespace std;

Deck::Deck(): currentIndex(0) {
    reset();
}

// Rearrange card vector to simulate shuffling
void Deck::shuffle()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(cards), std::end(cards), default_random_engine(seed));
    currentIndex = 0;
}

// For resetting deck to inital state
void Deck::reset()
{
    cards.clear();

    for (Suit suit : suits) {
        for (Rank rank : ranks) {
            cards.emplace_back(rank, suit);
        }
    }

    shuffle();
    currentIndex = 0;
}

// Return the next card from the deck as Card object
Card Deck::drawCard()
{
    if (isEmpty())
        throw std::out_of_range("Deck is empty");

    if (currentIndex >= cards.size())
        throw std::out_of_range("Card index beyond deck size");

    return cards[currentIndex++];

}

// Return if deck has no cards left as bool
bool Deck::isEmpty()
{
    return currentIndex >= cards.size();
}

// Return number of cards left in deck as int
int Deck::numRemainingCards(){
    return cards.size() - currentIndex;
}

// Return entire remaining deck contents as string
std::string Deck::getDeckAsString(){
    std::string deckString = "";
    for (size_t tempIndex=currentIndex; tempIndex<cards.size(); tempIndex++){
        deckString += cards[tempIndex].toString();
        deckString += "\n";
    }
    return deckString;
}




















