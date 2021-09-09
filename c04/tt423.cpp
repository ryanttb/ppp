#include <iostream>

using namespace std;

int main()
{
    for (int i = 'a'; i <= 'z'; ++i) {
        cout << char(i) << '\t' << i << endl;
    }

    for (int i = 'A'; i <= 'Z'; ++i) {
        cout << char(i) << '\t' << i << endl;
    }

    return 0;
}
