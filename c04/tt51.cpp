#include <iostream>

using namespace std;

int square(int x)
{
    int result {0};

    for (int c = 0; c < x; ++c) {
        result += x;
    }

    return result;
}

int main()
{
    int i {0};

    while (i < 100) {
        cout << i << '\t' << square(i) << endl;
        ++i;
    }

    return 0;
}
