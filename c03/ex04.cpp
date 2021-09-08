#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Two integers, plz:" << endl;

    int val1 {0}, val2 {0};

    cin >> val1 >> val2;

    cout << "sizeof(val1): " << sizeof(val1) << " bytes" << endl;

    cout << "That's " << val1 << " & " << val2 << endl
        << "min: " << min(val1, val2) << endl
        << "max: " << max(val1, val2) << endl
        << "sum: " << val1 + val2 << endl
        << "difference: " << val2 - val1 << endl
        << "product: " << val1 * val2 << endl
        << "ratio: " << val1 / val2 << endl;

    cout << "Two floats, plz:" << endl;

    double dbl1 {0}, dbl2 {0};

    cin >> dbl1 >> dbl2;

    cout << "sizeof(dbl1): " << sizeof(dbl1) << " bytes" << endl;

    cout << "That's " << dbl1 << " & " << dbl2 << endl
        << "min: " << min(dbl1, dbl2) << endl
        << "max: " << max(dbl1, dbl2) << endl
        << "sum: " << dbl1 + dbl2 << endl
        << "difference: " << dbl2 - dbl1 << endl
        << "product: " << dbl1 * dbl2 << endl
        << "ratio: " << dbl1 / dbl2 << endl;

    return 0;
}
