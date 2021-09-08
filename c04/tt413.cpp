#include <iostream>
#include <map>

using namespace std;

int main()
{
    cout << "Welcome to Currency to USD, valid currency values are Yen (y), Krone (k), Pound (p), and Yuan (c)" << endl << endl;

    double amount {0};
    char from {' '};

    cout << "What amount should I convert? ";
    cin >> amount;

    cout << "From which currency (y, k, p, c): ";
    cin >> from;

    double conversion = 1.0;

    switch (from) {
        case 'y':
        conversion = 0.0091;
        break;

        case 'k':
        conversion = 0.114833;
        break;

        case 'p':
        conversion = 1.37785;
        break;

        case 'c':
        conversion = 0.15;
        break;

        default:
            cerr << "Unknown unit" << endl;
            exit(1);
    }

    double amount_usd = amount * conversion;

    cout << amount << from << " is " << amount_usd << " USD" << endl;

    return 0;
}

