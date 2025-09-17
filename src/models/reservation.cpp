#include <iostream>

#include "models/reservation.hpp"
#include "models/student.hpp"
#include "models/dining_hall.hpp"
#include "models/meal.hpp"

// Initialize static member
int Reservation::next_reserve_id = 10001;

// Constructor
Reservation::Reservation(const Student* student, DiningHall* dining_hall, Meal* meal)
    : student(student), dining_hall(dining_hall), meal(meal) {
    this->reservation_id = next_reserve_id++;
    this->created_at = time(0);
    this->status = ReservationStatus::CONFIRMED;
}

// Setters
void Reservation::set_reservation_id(int reservation_id) {
    this->reservation_id = reservation_id;
}

void Reservation::set_student(const Student* student) {
    this->student = student;
}

void Reservation::set_dining_hall(DiningHall* dining_hall) {
    this->dining_hall = dining_hall;
}

void Reservation::set_meal(Meal* meal) {
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

const Student* Reservation::get_student() const {
    return this->student;
}

DiningHall* Reservation::get_dining_hall() const {
    return this->dining_hall;
}

Meal* Reservation::get_meal() const {
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
    std::cout << "Meal: " << this->meal->get_name() << " - " << static_cast<int>(this->meal->get_meal_type()) << std::endl
              << "Dining Hall: " << this->dining_hall->get_name() << std::endl
              << "Created at: " << this->created_at << std::endl
              << "Status: " << static_cast<int>(this->status) << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
    os << "Meal: " << reservation.meal->get_name() << " - " << static_cast<int>(reservation.meal->get_meal_type()) << std::endl
       << "Dining Hall: " << reservation.dining_hall->get_name() << std::endl
       << "Created at: " << reservation.created_at << std::endl
       << "Status: " << static_cast<int>(reservation.status) << std::endl;
    return os;
}

 bool Reservation::operator==(const Reservation& other) const {
        return  get_reservation_id() == other.get_reservation_id();
    }