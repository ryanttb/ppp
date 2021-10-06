#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> temps;

    cout << "Enter some numbers" << endl;

    for (double temp; cin >> temp; ) {
        temps.push_back(temp);
    }

    double sum {0};

    for (double x : temps) {
        sum += x;
    }

    // returns early
    if (temps.size() == 0) {
        cout << "No numbers" << endl;
        return 0;
    }

    cout << "Average: " << sum / temps.size() << endl;

    sort(temps.begin(), temps.end());

    cout << "Fake Median: " << temps[temps.size() / 2] << endl;

    if (temps.size() % 2 == 1) {
        cout << "Real Median: " << temps[(temps.size() - 1) / 2] << endl;
    } else {
        double before = temps[(temps.size() - 1) / 2];
        double after = temps[temps.size() / 2];
        cout << "Real Median: " << (before + after) / 2 << endl;
    }

    return 0;
}
