#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter your name and age" << endl;
    string first_name = "Nobody";
    double age = 0.0;
    cin >> first_name;
    cin >> age;
    cout << "Ohai " << first_name << " (age: " << age * 12.0 << " months)!! <3" << endl;
    return 0;
}
