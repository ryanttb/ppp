#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Some integers, plz!" << endl;

    vector<int> values;
    int input;
    while (cin >> input) {
        values.push_back(input);
    }

    cout << values.size() << " number, huh?" << endl;

    sort(values.begin(), values.end());

    for (const auto &i: values) {
        cout << i << ", ";
    }

    cout << endl;

    return 0;
}

