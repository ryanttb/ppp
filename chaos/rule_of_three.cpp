#include <string>
#include <iostream>

class Person {
    public:
        std::string name;
        int age;
        Person() : name("Unknown"), age(23) {
            std::cout << "Default constructor called" << std::endl;
        }

        explicit Person(const std::string& name, int age) : name(name), age(age) {
            std::cout << "Constructor called" << std::endl;
        }

        ~Person() {
            std::cout << "Destructor called" << std::endl;
        }

        Person(const Person& other) : name(other.name), age(other.age) {
            std::cout << "Copy constructor called" << std::endl;
        }

        Person& operator=(const Person& other) {
            std::cout << "Copy assignment operator called" << std::endl;
            name = other.name;
            age = other.age;
            return *this;
        }
};

int main() {
    Person p1("John", 20);
    Person p2(p1);
    p2 = p1;
	std::cout << p1.name << " " << p1.age << std::endl;
	std::cout << p2.name << " " << p2.age << std::endl;
    return 0;
}