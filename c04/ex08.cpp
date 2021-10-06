#include <cmath>

#include <iostream>

using namespace std;

int main() 
{
    double grains = 0;
    bool shown_thousand = false;
    bool shown_million = false;

    for (int i = 0; i < 64; ++i) {
        auto add = pow(2.0, i);
        cout << "Square " << i+1 << ": adding " << add << " grains of rice." << endl;
        grains += add;
        cout << "\tThe current total is " << grains << " grains." << endl;

        if (grains >= 1000 && !shown_thousand) {
            cout << "\t" << i+1 << " squares needed for at least one thousand grains of rice." << endl;
            shown_thousand = true;
        } else if (grains >= 1000000 && !shown_million) {
            cout << "\t" << i+1 << " squares needed for at least one million grains of rice." << endl;
            shown_million = true;
        }
    }


    return 0;
}
