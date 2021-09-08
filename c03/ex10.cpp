#include <algorithm>
#include <cfloat>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> OPERATORS {"+", "plus", "-", "minus", "*", "mul", "/", "div", "h", "help"};

void print_ops()
{
    cout << "Operators are: ";
    for (const auto &o: OPERATORS) {
        cout << o << ", ";
    }

    cout << endl;
}

int main() 
{
    cout << "Operator and two operands, plz:" << endl;

    string operation;
    double val1 {-DBL_MAX}, val2 {-DBL_MAX};

    cin >> operation >> val1 >> val2;

    if (find(OPERATORS.begin(), OPERATORS.end(), operation) == OPERATORS.end()) {
        cerr << "Unknown operator" << endl;
        print_ops();
        exit(1);

    }

    if (operation != "h" && operation != "help") {
        cout << val1 << " " << operation << " " << val2 << " = ";
    }

    if (operation == "+" || operation == "plus") {
        cout << val1 + val2 << endl;
    } else if (operation == "-" || operation == "minus") {
        cout << val1 - val2 << endl;
    } else if (operation == "*" || operation == "mul") {
        cout << val1 * val2 << endl;
    } else if (operation == "/" || operation == "div") {
        cout << val1 / val2 << endl;
    } else {
        print_ops();
    }

    return 0;
}
