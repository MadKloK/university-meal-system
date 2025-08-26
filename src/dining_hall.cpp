#include "dining_hall.hpp"
#include <iostream>

// Static initialization
int DiningHall::next_hall_id = 1;

// Constructor
DiningHall::DiningHall(std::string name, std::string address, int capacity)
    : name(name), address(address), capacity(capacity) {
    this->hall_id = next_hall_id++;

    if (name.empty()) {
        throw std::invalid_argument("Dining hall name cannot be empty");
    }

    if (address.empty()) {
        throw std::invalid_argument("Dining hall address cannot be empty");
    }

    if (capacity <= 0) {
        throw std::invalid_argument("Dining hall capacity must be greater than 0");
    }
}

// Setters
void DiningHall::set_name(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Dining hall name cannot be empty");
    }
    this->name = name;
}

void DiningHall::set_address(const std::string& address) {
    if (address.empty()) {
        throw std::invalid_argument("Dining hall address cannot be empty");
    }
    this->address = address;
}

void DiningHall::set_capacity(int capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Dining hall capacity must be greater than 0");
    }
    this->capacity = capacity;
}

// Getters
std::string DiningHall::get_name() const {
    return this->name;
}

std::string DiningHall::get_address() const {
    return this->address;
}

int DiningHall::get_capacity() const {
    return this->capacity;
}

int DiningHall::get_hall_id() const {
    return this->hall_id;
}

// Methods
void DiningHall::print() {
    std::cout << "Dining Hall: " << this->name << "\tcapacity: " << this->capacity << std::endl
              << "Address: " << this->address << "\thall ID: " << this->hall_id << std::endl;
}