#ifndef CARD_H
#define CARD_H
#include <string>

enum class Rank {
    Two = 2,
    Three, //3
    Four, //4
    Five, //5
    Six, //6
    Seven, //7
    Eight, //8
    Nine, //9
    Ten, //10
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
        int getValue() const;

        std::string toString() const;

    private:
        Rank rank;
        Suit suit;

};

#endif // CARD_H
