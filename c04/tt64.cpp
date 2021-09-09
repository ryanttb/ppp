#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> words;

    vector<string> disliked {"namespace", "disliked"};

    for (string word; cin >> word; ) {
        words.push_back(word);
    }

    cout << words.size() << " words" << endl;

    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i - 1] != words[i]) {
            if (find(disliked.begin(), disliked.end(), words[i]) != disliked.end()) {
                cout << "BLEEP" << endl;
            } else {
                cout << words[i] << endl;
            }
        }
    }

    return 0;
}
