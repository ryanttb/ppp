// https://app.coderpad.io/9QQFQYPF

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

enum CardSuit {
  Spades,
  Clubs,
  Hearts,
  Diamonds
};

const vector<string> CARD_SUITS = {"Spades", "Clubs", "Hearts", "Diamonds"};

enum CardValue {
  Ace, King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five, Four, Three, Two
};

const vector<string> CARD_VALUES = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};

struct Card {
  Card(CardValue aValue, CardSuit aSuit) : value{aValue}, suit{aSuit} { }

  friend std::ostream& operator<<(std::ostream& os, Card& c) {
    os << c.toString();
    return os;
  }

  CardValue value;
  CardSuit suit;

  string toString() {
    return CARD_VALUES[value] + " of " + CARD_SUITS[suit];
  }
};

typedef vector<Card> Deck;

class CardShuffler {
public:
  CardShuffler(Deck d) : _deck{d} {}

  void shuffle() {
    Deck d;
    
    size_t i{0};
    for (Card c : _deck) {
      if (i % 2 == 0) {
        d.insert(d.begin(), c);
      } else {
        d.push_back(c);
      }
      ++i;
    }

    _deck = d;
  }

  void printDeck(std::ostream& os) {
    printDeck(os, _deck);
  }

private:

  void printDeck(std::ostream& os, Deck d) {
    for (Card c : d) {
      os << c << endl;
    }
  }

  Deck _deck;
};


// To execute C++, please define "int main()"
int main() {
  Card c{CardValue::Ace, CardSuit::Spades};

  Deck d{
    {CardValue::Ace, CardSuit::Spades},
    {CardValue::Five, CardSuit::Hearts},
    {CardValue::Seven, CardSuit::Clubs},
    {CardValue::Queen, CardSuit::Diamonds}
  };

  CardShuffler cs{d};
  cs.printDeck(cout);

  cs.shuffle();

  cs.printDeck(cout);

  return 0;
}
