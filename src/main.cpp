#include "student.hpp"

#include <iostream>
#include <cassert>

using namespace std;

void test_student_creation() {
    Student s("1241234222", "s1222223", "John Allenasdf");
    assert(s.get_balance() == 100.0f);
    assert(s.get_name() == "John");
}

int main() {
    Student st("1241234222", "s1222223", "John Allenasdf");
    cout << st << std::endl;
    st.print();
}