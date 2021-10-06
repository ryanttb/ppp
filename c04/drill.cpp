#include <cfloat>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    // values in meters
    double min_seen {DBL_MAX}, max_seen{DBL_MIN};

    cout << "Enter some values and their units (cm, m, in, ft) " << endl;

    vector<double> all_seen;

    double n;
    string n_unit;
    double sum_meters {0};

    while (cin >> n >> n_unit) {
        cout << "Got " << n << n_unit;

        auto n_meters = n;

        if (n_unit == "m") {
        } else if (n_unit == "cm") {
            n_meters = n / 100;
        } else if (n_unit == "in") {
            n_meters = n * 2.54 / 100;
        } else if (n_unit == "ft") {
            n_meters = n * 12 * 2.54 / 100;
        } else {
            cout << endl << "Unit not supported" << endl;
            continue;
        }

        //cout << "n_meters: " << n_meters << ", min_seen: " << min_seen << ", max_seen: " << max_seen << endl;

        all_seen.push_back(n_meters);
        sum_meters += n_meters;

        if (n_meters < min_seen) {
            cout << " (smallest so far)";
            min_seen = n_meters;
        }

        if (n_meters > max_seen) {
            cout << " (largest so far)";
            max_seen = n_meters;
        }

        cout << endl << "Next?" << endl;
    }

    cout << endl
        << "Smallest: " << min_seen << "m" << endl
        << "Largest: " << max_seen << "m" << endl
        << "Sum: " << sum_meters << "m" << endl;

    cout << endl;

    sort(all_seen.begin(), all_seen.end());

    for (const auto d : all_seen) {
        cout << d << "m, ";
    }

    cout << endl;

    return 0;
}
