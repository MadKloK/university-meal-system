#include <iostream>
#include "models/admin.hpp"
#include "models/student.hpp"   // if you have a derived class

int main() {
    std::cout << "Program started!\n";

    // Example: create a Student object and print info
    Student s("Alice", "Brown", "1234567890", "alice@email.com", "pw");
    s.print();  // Calls the overridden print() method

    return 0;
}
