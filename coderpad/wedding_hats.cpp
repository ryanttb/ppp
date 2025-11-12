// https://app.coderpad.io/HKH7RPGP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> HAT_STYLES = {"Bowler", "Flat Cap", "Top Hat", "Benie"};
const vector<string> HAT_COLORS = {"Black", "Brown", "White", "Green"};

struct Hat {
  Hat(const string& s, const string& c) : style{s}, color{c} { }

  string toString() const {
    return color + " " + style;
  }

  string style;
  string color;
  bool used{false};
};
inline ostream& operator<<(ostream& os, const Hat& h) {
  os << h.toString();
  return os;
}

struct Guest {
  Guest(string n) : name{n} { }
  ~Guest() {}

  Guest(const Guest&) = delete;
  Guest& operator=(Guest&) = delete;

  string toString() const {
    return name + (sawMeIn ? " saw me in: " + sawMeIn->toString() : " didn't see me");
  }

  string name;
  Hat* sawMeIn{nullptr};
};

struct Wedding {
  string toString() const {
    string ret = name;
    for (auto g : guests) {
      ret += "\n\t" + g->toString();
    }
    return ret;
  }

  string name;
  vector<Guest*> guests;
};

vector<Hat*> hatsSeen(const vector<Guest*> guestsQ) {
  vector<Hat*> hats;
  for (auto g : guestsQ) {
    if (g->sawMeIn) {
      hats.push_back(g->sawMeIn);
    }
  }
  return hats;
}

int main() {
  vector<Hat> hats;

  for (const auto& style : HAT_STYLES) {
    for (const auto& color : HAT_COLORS) {
      hats.push_back(Hat(style, color));
    }
  }

  cout << "Hats" << endl;

  for (const auto& h : hats) {
    cout << h << endl;
  }
  cout << endl;

  Guest guests[]{
    {"Bob Dole"},
    {"Sam Raimi"},
    {"Timothy Olephant"},
    {"Cilian Murphy"},
    {"Laura Morrison-Westphal"}
  };

  cout << "Guests:" << endl;

  for (const auto& g : guests) {
    cout << g.toString() << endl;
  }

  cout << endl;

  cout << "Weddings:" << endl;

  vector<Wedding> weddings = {
    {"W1", {&guests[0]}},
    {"W2", {&guests[1]}},
    {"W3", {&guests[2], &guests[0]}},
    {"W4", {&guests[1], &guests[3]}},
    {"W5", {&guests[4], &guests[0], &guests[1]}}
  };

  for (auto& w : weddings) {
    cout << w.name << endl;
    auto hatsUsed = hatsSeen(w.guests);
    cout << "\thatsUsed.size: " << hatsUsed.size() << endl;; 
    int nextHat = hatsUsed.size();
    cout << "\tnextHat: " << hats[nextHat] << endl;

    for (auto& g : w.guests) {
      g->sawMeIn = &hats[nextHat];
      hats[nextHat].used = true;
    }
  }


  for (const auto& g : guests) {  
    cout << g.toString() << endl;
  }

  int hatsCount{0};
  for (const auto& h : hats) {
    if (h.used) {
      ++hatsCount;
    }
  }
  cout << "Hats used: " << hatsCount << endl;

  return 0;
}
