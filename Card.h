#ifndef CARD_H
#define CARD_H
#include <string>

enum class Rank {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};


static const Rank ranks[13] = {
    Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six, Rank::Seven,
    Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King, Rank::Ace
};

static const Suit suits[4] = {
    Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades
};


class Card
{
    public:
        Card(Rank rank, Suit suit);

        Rank getRank() const { return rank; }
        Suit getSuit() const { return suit; }

        std::string toString() const;

    private:
        Rank rank;
        Suit suit;

};

#endif // CARD_H
