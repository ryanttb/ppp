#include <iostream>

using namespace std;

int main()
{
    char i {'a'};

    while (i <= 'z') {
        cout << i << '\t' << int(i) << endl;
        ++i;
    }

    return 0;
}
