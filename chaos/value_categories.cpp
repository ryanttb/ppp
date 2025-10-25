#include <iostream>
#include <utility>

using namespace std;

int main() {
	int lValue = 2000;
	cout << "lValue: " << lValue << endl;

	int rValueAssignment = lValue + 1;
	cout << "rValueAssignment: " << rValueAssignment << endl;

	// pure rValue (temporary) value, no output. Not assignable.
	lValue + rValueAssignment;
	cout << "pure rValue (temporary) value, no output: " << lValue + rValueAssignment << endl;

	// Xvalue example using std::move
	int xValue = 42;
	cout << "Original xValue: " << xValue << endl;
	
	// std::move converts lvalue to xvalue (expiring xvalue)
	int movedValue = std::move(xValue);
	cout << "After std::move - xValue: " << xValue << ", movedValue: " << movedValue << endl;
	
	// xValue is now in a moved-from state (implementation defined)
	// It's still accessible but its value is unspecified

    return 0;
}