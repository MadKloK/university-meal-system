#include <iostream>
#include <cassert>

#include "student.hpp"
#include "user.hpp"
#include "meal.hpp"


void test_student_creation() {
    Student stu("John", "Allen", "1241234222", "john@example.com", "hashed_pass");

    // basic fields
    assert(stu.get_name() == "John");
    assert(stu.get_last_name() == "Allen");
    assert(stu.get_student_id() == "1241234222");
    assert(stu.get_email() == "john@example.com");

    // defaults
    assert(stu.get_balance() == 0.0f);   // or 100.0f if you change default
    assert(stu.get_is_active() == false);

    std::cout << "[OK] Student creation test passed\n";
}

void test_student_setters() {
    Student stu("Jane", "Doe", "987654", "jane@uni.edu", "hashed_pw");

    stu.set_balance(200.5f);
    stu.set_is_active(true);

    assert(stu.get_balance() == 200.5f);
    assert(stu.get_is_active() == true);

    std::cout << "[OK] Student setters test passed\n";
}

int main() {
    test_student_creation();
    test_student_setters();

    std::cout << "All tests passed!\n";
    return 0;
}