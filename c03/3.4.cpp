#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{
    cout << "please enter a number" << endl;

    int n = 0;

    cin >> n;

    cout << "n: " << n << endl
        << "n+1: " << n + 1 << endl
        << "nx3: " << n * 3 << endl
        << "2n: " << n + n << endl
        << "n^2: " << n * n << endl
        << "half n: " << n / 2 << endl
        << "n % 2: " << n % 2 << endl
        << "square root n: " << sqrt(n) << endl;

    return 0;
}

