#include "student.hpp"
#include <iostream>

// Static initialization
int Student::next_id = 1001;

// Constructor ans Destructor
Student::Student(const std::string &student_id, const std::string &name, const std::string &email)
    : student_id(student_id), name(name), email(email)
{
    user_id = next_id++;

    if (student_id.length() < 10) {
        throw std::invalid_argument("Invalid Student ID");
    }

    if (name.length() < 6) {
        throw std::invalid_argument("Name length must be over 6");
    }

    if (email.length() < 10) {
        throw std::invalid_argument("Invalid email");
    }
}

Student::~Student() {
    this->reservations.clear();
}

// Getters
int Student::get_user_id() const {
    return this->user_id;
}

std::string Student::get_student_id() const {
    return this->student_id;
}

std::string Student::get_name() const {
    return this->name;
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

// Setter
void Student::set_user_id(int user_id) {
    if (user_id < 1000) {
        throw std::invalid_argument("User ID must be over 999");
    }
    this->user_id = user_id;
}

void Student::set_student_id(const std::string &student_id) {
    if (student_id.length() == 0) {
        throw std::invalid_argument("Student ID cannot be empty");
    }
    this->student_id = student_id;
}

void Student::set_name(const std::string &name) {
    if (name.length() < 6) {
        throw std::invalid_argument("Name length must be over 6");
    }
    this->name = name;
}

void Student::set_email(const std::string &email) {
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
    std::cout << "Student: " << this->name << " - user " << this->user_id << "\n"
              << "ID: " << this->student_id << std::endl;
}

void Student::reserve_meal(const Reservation& reservation) {
    for (const auto& res : this->reservations) {
        if (res.get_meal().get_meal_type() == reservation.get_meal().get_meal_type()) {
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
            it++;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Student& st) {
    os << "Student: " << st.get_name() << " - user " << st.get_user_id() << "\n"
    << "ID: " << st.get_student_id() << std::endl;
    return os;
}
