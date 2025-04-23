#include "student.hpp"

#include <iostream>
#include <cassert>

void test_student_creation() {
    Student s("1241234222", "s1222223", "John Allenasdf");
    assert(s.get_balance() == 100.0f);
    assert(s.get_name() == "John");
}

int main() {
    test_student_creation();
    std::cout << "All tests passed!\n";
    return 0;
}