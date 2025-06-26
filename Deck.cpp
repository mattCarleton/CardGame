#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>
#include <chrono>

using namespace std;

Deck::Deck(): currentIndex(0) {
    reset();
}

void Deck::shuffle()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(cards), std::end(cards), default_random_engine(seed));
    currentIndex = 0;
}

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

Card Deck::drawCard()
{
    if(isEmpty())
        throw std::out_of_range("Deck is empty");

    return cards[currentIndex++];

}

bool Deck::isEmpty()
{
    return currentIndex >= cards.size();
}

int Deck::numRemainingCards(){
    return cards.size() - currentIndex;
}

std::string Deck::getDeckAsString(){
    std::string deckString = "";
    for(size_t tempIndex=currentIndex; tempIndex<cards.size(); tempIndex++){
        deckString += cards[tempIndex].toString();
        deckString += "\n";
    }
    return deckString;
}




















