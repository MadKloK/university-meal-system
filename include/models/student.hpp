#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

#include "user.hpp"
#include "reservation.hpp"

class User;
class Reservation;
class Meal;

// Student class definition
class Student : public User {
private:
    static int next_id;
    std::string student_id;
    std::string email;
    std::string phone;
    float balance = 0;
    bool is_active = false;
    std::vector<Reservation> reservations;

public:
    // Constructor
    explicit Student(const std::string& name, const std::string& last_name, const std::string& student_id, const std::string& email, const std::string& phone, const std::string& hashed_password);

    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Student& st);

    // Setters
    void set_student_id(const std::string& student_id);
    void set_email(const std::string& email);
    void set_balance(float balance);
    void set_is_active(bool is_active);
    void set_phone(std::string phone);

    // Getters
    std::string get_student_id() const;
    std::string get_email() const;
    float get_balance() const;
    bool get_is_active() const;
    std::string get_phone() const;
    std::vector<Reservation> get_reservations() const;
    std::string get_type() const override;

    // Methods
    void print() const override;
    void reserve_meal(const Reservation& reservation);
    bool cancel_reservation(int reservation_id); // returns true when canceling was successfull
};

#endif // STUDENT_H