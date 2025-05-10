#include "student.hpp"
#include <iostream>

// Static initialization
int Student::next_id = 1001;

// Constructor
Student::Student(const std::string& name, const std::string& last_name, const std::string& student_id, const std::string& email, const std::string& hashed_password)
    : User(name, last_name, next_id++, hashed_password), student_id(student_id), email(email) {
    if (student_id.length() < 10) {
        throw std::invalid_argument("Invalid Student ID");
    }

    if (email.length() < 10) {
        throw std::invalid_argument("Invalid email");
    }
}

Student::~Student() {
    this->reservations.clear();
}

// Getters
std::string Student::get_student_id() const {
    return this->student_id;
}

std::string Student::get_email() const {
    return this->email;
}

float Student::get_balance() const {
    return this->balance;
}

bool Student::get_is_active() const {
    return this->is_active;
}

std::vector<Reservation> Student::get_reservations() const {
    return this->reservations;
}

// Setters
void Student::set_student_id(const std::string& student_id) {
    if (student_id.empty()) {
        throw std::invalid_argument("Student ID cannot be empty");
    }
    this->student_id = student_id;
}

void Student::set_email(const std::string& email) {
    if (email.length() < 10) {
        throw std::invalid_argument("Invalid email");
    }
    this->email = email;
}

void Student::set_balance(float balance) {
    if (balance < 0) {
        throw std::invalid_argument("Balance cannot be negative");
    }
    this->balance = balance;
}

void Student::set_is_active(bool is_active) {
    this->is_active = is_active;
}

// Methods
void Student::print() const {
    std::cout << "Student: " << getName() << " " << getLastName() << " - user " << getUserId() << "\n"
              << "ID: " << this->student_id << ", Email: " << this->email << std::endl;
}

void Student::reserve_meal(const Reservation& reservation) {
    for (const auto& res : this->reservations) {
        if (res.get_meal()->get_meal_type() == reservation.get_meal()->get_meal_type()) {
            throw std::invalid_argument("This meal is already reserved");
        }
    }
    this->reservations.push_back(reservation);
}

bool Student::cancel_reservation(int reservation_id) {
    for (auto it = this->reservations.begin(); it != this->reservations.end(); ) {
        if (it->get_reservation_id() == reservation_id) {
            it = this->reservations.erase(it);
            return true;
        } else {
            ++it;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Student& st) {
    os << "Student: " << st.getName() << " " << st.getLastName() << " - user " << st.getUserId() << "\n"
       << "ID: " << st.get_student_id() << ", Email: " << st.get_email() << std::endl;
    return os;
}
