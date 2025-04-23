#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "reservation.hpp"
#include "meal.hpp"

// Forward declaration
class Reservation;
class Meal;

// Student class definition
class Student {
private:
    static int next_id;
    int user_id;
    std::string student_id;
    std::string name;
    std::string email;
    float balance = 0;
    bool is_active = false;
    std::vector<Reservation> reservations;
 
public:
    // Constructor
    explicit Student(const std::string& student_id, const std::string& name, const std::string& email);

    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Student& st);

    // Getters
    int get_user_id() const;
    std::string get_student_id() const;
    std::string get_name() const;
    std::string get_email() const;
    float get_balance() const;
    bool get_is_active() const;
    std::vector<Reservation> get_reservations() const;

    // Setters
    void set_user_id(int user_id);
    void set_student_id(const std::string& student_id);
    void set_name(const std::string& name);
    void set_email(const std::string& email);
    void set_balance(float balance);
    void set_is_active(bool is_active);

    // Methods
    void print() const;
    void reserve_meal(const Meal& meal);
    bool cancel_reservation(const Reservation& reservation);

    // Destructor
    ~Student();
};

#endif // STUDENT_H