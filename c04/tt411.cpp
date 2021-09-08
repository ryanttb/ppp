#include <iostream>
#include <map>

using namespace std;

//const map<char, double> CONVERSIONS = { {'y', 0.0091}, {'k', 0.114833}, {'p', 1.37785} };

int main()
{
    cout << "Welcome to Currency to USD, valid currency values are Yen (y), Krone (k), and Pound (p)" << endl << endl;

    double amount {0};
    char from {' '};

    cout << "What amount should I convert? ";
    cin >> amount;

    cout << "From which currency (y, k, p): ";
    cin >> from;

    double conversion = 1.0;

    if (from == 'y') {
        conversion = 0.0091;
    } else if (from == 'k') {
        conversion = 0.114833;
    } else if (from == 'p') {
        conversion = 1.37785;
    } else {
        cerr << "Unknown unit" << endl;
        exit(1);
    }

    double amount_usd = amount * conversion;

    cout << amount << from << " is " << amount_usd << " USD" << endl;

    return 0;
}

