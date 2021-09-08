#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const vector<int> PENNY_VALUES {1, 5, 10, 25, 50};

    const vector<string> DENOMS_SINGULAR {"penny", "nickel", "dime", "quarter", "half dollar"};
    const vector<string> DENOMS_PLURAL {"pennies", "nickels", "dimes", "quarters", "half dollars"};
    
    vector<int> counts;
    
    for (const auto &d: DENOMS_PLURAL) {
        cout << "How many " << d << " do you have? ";
        int c;
        cin >> c;
        counts.push_back(c);
    }

    cout << endl;

    double total = 0;
    for (int i = 0; i < PENNY_VALUES.size(); ++i) {
        cout << counts[i] << " ";
        if (counts[i] == 1) {
            cout << DENOMS_SINGULAR[i];
        } else {
            cout << DENOMS_PLURAL[i];
        }
        cout << endl;
        total += PENNY_VALUES[i] * counts[i];
    }

    cout << "total: $" << fixed << setprecision(2) << total / 100 << endl;

    return 0;
}

