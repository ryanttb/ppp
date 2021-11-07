#include <iostream>

using namespace std;

int main() {
    void* pv1 = new int; // can convert to void* without cast
    cout << "pv1 is " << pv1 << endl;

    *static_cast<int*>(pv1) = 23; // must cast to use
    cout << "the content of pv1 is " << *static_cast<int*>(pv1) << endl;

    delete static_cast<int*>(pv1); // must cast to delete

    return 0;
}

