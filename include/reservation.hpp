#pragma once

#include "student.hpp"
#include "dining_hall.hpp"
#include "meal.hpp"

#include <ctime>

enum class ReservationStatus {
    PENDING,
    CONFIRMED,
    CANCELED,
    FAILED
};

class Reservation {
private:
    static int next_reserve_id;
    int reservation_id;
    Student student;
    DiningHall dining_hall;
    Meal meal;
    ReservationStatus status = ReservationStatus::CONFIRMED; // will be on PENDING when theres any condition like paying stuff
    time_t created_at = time(0);

public:
    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);

    // Constructor
    explicit Reservation(Student student, DiningHall dining_hall, Meal meal)
    : student(student), dining_hall(dining_hall), meal(meal) {}
    
    // Setters
    void set_reservation_id(int reservation_id);
    void set_student(Student student);
    void set_dining_hall(DiningHall dining_hall);
    void set_meal(Meal meal);
    void set_status(ReservationStatus status);
    void set_created_at(time_t created_at);

    // Getters
    int get_reservation_id() const;
    Student get_student() const;
    DiningHall get_dining_hall() const;
    Meal get_meal() const;
    ReservationStatus get_status() const;
    time_t get_created_at() const;

    // Methods
    bool cancel(); // returns true if its not already canceled
    void print();
};
