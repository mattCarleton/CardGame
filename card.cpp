#include "card.h"
using namespace std;

Card::Card(Rank r, Suit s): rank(r), suit(s){}

int Card::getValue() const
{
    switch(rank){
    case Rank::Jack:
    case Rank::Queen:
    case Rank::King:
        return 10;
    case Rank::Ace:
        return 11; // aces are handled as 1's if needed in player class
    default:
        return static_cast<int>(rank);
    }

    return 0;

}

std::string Card::toString() const {
    string out = "";

    switch(rank){
    case Rank::Two: out += "2"; break;
    case Rank::Three: out += "3"; break;
    case Rank::Four: out += "4"; break;
    case Rank::Five: out += "5"; break;
    case Rank::Six: out += "6"; break;
    case Rank::Seven: out += "7"; break;
    case Rank::Eight: out += "8"; break;
    case Rank::Nine: out += "9"; break;
    case Rank::Ten: out += "10"; break;
    case Rank::Jack: out += "J"; break;
    case Rank::Queen: out += "Q"; break;
    case Rank::King: out += "K"; break;
    case Rank::Ace: out += "A"; break;
    default: out += "?"; break;
    }

    switch(suit){
    case Suit::Hearts: out += "♥"; break;
    case Suit::Diamonds: out += "♦"; break;
    case Suit::Clubs: out += "♣"; break;
    case Suit::Spades: out += "♠"; break;
    default: out += "?"; break;
    }

    return out;
}
