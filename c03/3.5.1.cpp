#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;

    string p = "";

    string c;

    while (cin >> c) {
        ++n;
        if (p == c) {
            cout << "repeated word: " << c << " at " << n << endl;
        }
        p = c;
    }
}
