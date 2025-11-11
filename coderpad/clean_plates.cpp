#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

enum PlateType : int {
  FLOWER,
  GREEN,
  BLUE
};

class PlateSorter {
public:
  void listPlates() {
    for (auto& plateTypeIdx : plateTypeIndexes) {
      cout << plateNames[plateTypeIdx.first] << ": " << plateTypeIdx.second << endl;
    }
    
    for (PlateType p : plates) {
      cout << plateNames[p] << ", ";
    }
    cout << endl;
  }

  /**
   * \brief   return index of insert and whether or not plates were reversed
   */
  pair<int, bool> sortPlate(PlateType p) {
    cout << "sortPlate p: " << plateNames[p] << endl;
    int plateIdx = plateTypeIndexes[p];
    plates.insert(plates.begin() + plateIdx, p);
    for (auto& plateTypeIdx : plateTypeIndexes) {
      if (plateTypeIdx.second > plateIdx) {
        plateTypeIdx.second += 1;
      }
    }
    return make_pair(plateIdx, false);
  }

private:
  map<PlateType, int> plateTypeIndexes{{FLOWER, 0}, {GREEN, 1}, {BLUE, 2}};
  vector<PlateType> plates{FLOWER, GREEN, BLUE};
  map<PlateType, string> plateNames{{FLOWER, "F"}, {GREEN, "G"}, {BLUE, "B"}};
};

// To execute C++, please define "int main()"
int main() {
  PlateSorter ps;

  ps.listPlates();

  ps.sortPlate(FLOWER);

  ps.listPlates();

  return 0;
}
