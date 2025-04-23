#include "reservation.hpp"
#include <iostream>

// Initialize static member
int Reservation::next_reserve_id = 10001;

// Constructor
Reservation::Reservation(Student student, DiningHall dining_hall, Meal meal)
    : student(student), dining_hall(dining_hall), meal(meal) {
    this->reservation_id = next_reserve_id++;
    this->created_at = time(0);
    this->status = ReservationStatus::PENDING;
}

// Setters
void Reservation::set_reservation_id(int reservation_id) {
    this->reservation_id = reservation_id;
}

void Reservation::set_student(Student student) {
    this->student = student;
}

void Reservation::set_dining_hall(DiningHall dining_hall) {
    this->dining_hall = dining_hall;
}

void Reservation::set_meal(Meal meal) {
    this->meal = meal;
}

void Reservation::set_status(ReservationStatus status) {
    this->status = status;
}

void Reservation::set_created_at(time_t created_at) {
    this->created_at = created_at;
}

// Getters
int Reservation::get_reservation_id() const {
    return this->reservation_id;
}

Student Reservation::get_student() const {
    return this->student;
}

DiningHall Reservation::get_dining_hall() const {
    return this->dining_hall;
}

Meal Reservation::get_meal() const {
    return this->meal;
}

ReservationStatus Reservation::get_status() const {
    return this->status;
}

time_t Reservation::get_created_at() const {
    return this->created_at;
}

// Methods
bool Reservation::cancel() {
    if (this->status == ReservationStatus::CANCELED) {
        return false;
    }
    this->status = ReservationStatus::CANCELED;
    return true;
}

void Reservation::print() {
    //  TODO: will be implemented after meal. logical to have a name on print yk.
}

std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
    // TODO: same here
    return os;
}