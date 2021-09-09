#include <iostream>

using namespace std;

int main() 
{
    double a, b;

    cout << "Enter sets of two numbers" << endl;

    while (cin >> a >> b) {
        cout << "Thanks, I got " << a << " " << b << endl;

        if (a == b) {
            cout << "They are equal" << endl;
        } else {
            cout << "Smaller is: " << (a < b ? a : b) << endl
                << "Larger is: " << (a > b ? a : b) << endl;

            if (abs(a - b) < 1.0/100) {
                cout << "They are *almost* equal" << endl;
            }
        }

        cout << "Next?" << endl;
    }

    return 0;
}
