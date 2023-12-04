#pragma once
#include <vector>
#include <string>
using namespace std;

enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    HEART, DIAMOND, CLUB, SPADE
};


class Card {
private:
    Rank rank;
    Suit suit;
    string cardName;
public:
    Card();
    Card(Rank r, Suit s);
    Rank GetRank();
    Suit GetSuit();
    string GetName();
    bool IsFace();
};

class Deck {
private:
    vector<Card> deck;
public:
    Deck();
    void ResetDeck();
    Card PullCard();
    void Shuffle();
};



