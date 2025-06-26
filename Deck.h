#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

#define DECK_SIZE 52

class Deck
{
    public:
        Deck();
        void shuffle();
        void reset();
        Card drawCard();
        bool isEmpty();
        std::string getDeckAsString();
        int numRemainingCards();

    private:
        std::vector<Card> cards;
        size_t currentIndex;
};

#endif // DECK_H
