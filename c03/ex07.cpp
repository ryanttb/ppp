#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Some strings, plz!" << endl;

    vector<string> values;
    string input;
    while (cin >> input) {
        values.push_back(input);
    }

    cout << values.size() << " strings, huh?" << endl;

    sort(values.begin(), values.end());

    for (const auto &i: values) {
        cout << i << ", ";
    }

    cout << endl;

    return 0;
}

