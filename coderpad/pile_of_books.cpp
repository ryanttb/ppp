#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<string> books = {
    "Harry Potter and the Prisoner of Azkaban",
    "Gone With the Wind",
    "Frankenstein or The Modern Prometheus",
    "Band of Brothers",
    "The Caves of Steel",
    "The Grapes of Wrath",
    "Ubik"
  };

  int beginIdx = 0;
  int endIdx = books.size() - 1;

  int pivot{-1};

  while (pivot == -1) {
    int offset = (endIdx - beginIdx)/2;
    int curIdx = beginIdx + offset;
    cout << "beginIdx: " << beginIdx << ", endIdx: " << endIdx << ", curIdx: " << curIdx << endl;

    if (curIdx == beginIdx) {
      pivot = curIdx;
    } else if (endIdx - beginIdx == 2) {
      pivot = beginIdx + (books[beginIdx] < books[endIdx] ? 0 : 1);
    } else if (books[curIdx] < books[beginIdx]) {
      beginIdx = curIdx;
    } else {
      endIdx = curIdx + 1;
    }
  }

  cout << "pivot: " << pivot << endl;

  return 0;
}
