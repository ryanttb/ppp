#include <iostream>
#include <utility>
#include <memory>

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

	// Smart pointer examples
	cout << "\n--- Smart Pointer Examples ---" << endl;
	
	// unique_ptr example - exclusive ownership
	unique_ptr<int> uniquePtr = make_unique<int>(100);
	cout << "unique_ptr value: " << *uniquePtr << endl;
	
	// unique_ptr can be moved (transfers ownership)
	unique_ptr<int> anotherUnique = move(uniquePtr);
	cout << "After move - uniquePtr is null: " << (uniquePtr == nullptr) << endl;
	cout << "anotherUnique value: " << *anotherUnique << endl;
	
	// shared_ptr example - shared ownership
	shared_ptr<int> sharedPtr1 = make_shared<int>(200);
	shared_ptr<int> sharedPtr2 = sharedPtr1; // shared ownership
	cout << "shared_ptr1 use_count: " << sharedPtr1.use_count() << endl;
	cout << "shared_ptr2 use_count: " << sharedPtr2.use_count() << endl;
	cout << "Both point to same value: " << (*sharedPtr1 == *sharedPtr2) << endl;
	
	// When sharedPtr2 goes out of scope, use_count decreases
	// When use_count reaches 0, the object is automatically deleted

    return 0;
}