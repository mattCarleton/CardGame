#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

#define DECK_SIZE 52

class Deck
{
    public:
        Deck(void);
        void shuffle(void);
        void reset(void);
        Card drawCard(void);
        bool isEmpty(void);
        std::string getDeckAsString(void);
        int numRemainingCards(void);

    private:
        std::vector<Card> cards;
        size_t currentIndex;
};

#endif // DECK_H
