// https://app.coderpad.io/7CH436CF

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

class Item {
public:
  string toString() const {
    return name + " (" + to_string(value) + "g)";
  }

  string toShape() const {
    string ret;
    for (int h{0}; h < height; ++h) {
      for (int w{0}; w < width; ++w) {
        ret += icon;
      }
      ret += "\n";
    }
    return ret;
  }

  string name;
  string icon;
  int width;
  int height;
  int value;
};

/**
 * \brief   comparison of Items by value or, if necessary, size
 */
inline bool operator<(const Item& a, const Item& b) {
  if (a.value < b.value) {
    return true;
  } else if (a.width < b.width) {
    return true;
  } else if (a.height < b.height) {
    return true;
  } else {
    return false;
  }
}


struct StoredItem {
  const Item& item;
  int x;
  int y;
};

class Inventory {
public:
  Inventory(int w, int h) : width{w}, height{h} {

  }

  string toString() {
    string ret(width * height, '.');
    
    // split rows
    ostringstream oss;
    for (int y{0}; y < height; ++y) {
      oss << ret.substr(height * y, width) << endl;
    }
    
    return oss.str();
  }

  bool canFit(const Item& i) const {
    cout << "canFit i: " << i.toString() << endl;
    if (i.width > width || i.height > height) {
      return false;
    } else {
      return true;
    }
  }

  bool insert(const Item& i) {
    return true;
  }

  int width;
  int height;

private:
  list<StoredItem> _inv;
};

int main() {
  vector<Item> items {
    {"Unobsidian Armor","@", 2, 3, 540},
    {"Potion of Potionentiality", "O", 1, 1, 30},
    {"Palindromic Sword o'Drows", "^", 1, 3, 120},
    {"Jeweled Dog Draught Excluder", "-", 3, 1, 150},
    {"Spartan Shield", "#", 2, 2, 300},
    {"Wardrobe of Infinite Lions", "&", 20, 10, 1337}
  };

  sort(items.begin(), items.end());

  for (const Item& item : items) {
    cout << item.toString() << endl;
    cout << item.toShape() << endl << endl;
  }

  for (auto it = items.rbegin(); it != items.rend(); ++it) {
    cout << it->toString() << endl;
  }

  Inventory inv{5, 4};

  cout << inv.toString() << endl;

  cout << inv.canFit(*(items.end() - 1)) << endl;

  return 0;
}
