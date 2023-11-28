#include <iostream>

enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,

};

enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,
};

class Card
{
public:
  CardRank rank;
  CardSuit suit;

  int getValue() const
  {
    switch (rank)
    {
    case CardRank::RANK_2:
      return 2;
    case CardRank::RANK_3:
      return 3;
    case CardRank::RANK_4:
      return 4;
    case CardRank::RANK_5:
      return 5;
    case CardRank::RANK_6:
      return 6;
    case CardRank::RANK_7:
      return 7;
    case CardRank::RANK_8:
      return 8;
    case CardRank::RANK_9:
      return 9;
    case CardRank::RANK_10:
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING:
      return 10;
    case CardRank::RANK_ACE:
      return 11;
    default:
      return 0;
    }
  }
};

class Deck
{
public:
  const int AMONT_OF_CARDS = 52;

  void shuffle()
  {
  }
};

class Hand
{
public:
  void addCard(bool isCroupier)
  {
  }

  void hit()
  {
  }

  void stand()
  {
  }

  void doubleDown()
  {
  }

  void surrender()
  {
  }
};

class BlackJack
{
};
