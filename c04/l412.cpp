#include <iostream>

using namespace std;

int main()
{
    constexpr double CM_PER_IN = 2.54;

    double length = 1;

    char unit = 'a';

    cout << "Please enter a length and a unit (c or i)" << endl;

    cin >> length >> unit;

    switch (unit) {
    case 'i':
        cout << length << "in = " << CM_PER_IN * length << "cm" << endl;
        break;
    case 'c':
        cout << length << "cm = " << length / CM_PER_IN << "incm" << endl;
        break;
    default:
        cout << "Don't know " << unit << endl;
        break;
    }

    return 0;
}
