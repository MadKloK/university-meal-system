#include "meal.hpp"
#include <iostream>
#include <algorithm>

// Static initialization
int Meal::next_meal_id = 101;

// Constructor
Meal::Meal(std::string name, float price, MealType meal_type, ReserveDay reserve_day, bool is_active = true)
    : name(name), price(price), meal_type(meal_type), reserve_day(reserve_day), is_active(is_active)
{
    this->meal_id = this->next_meal_id++;

    if (price < 0)
        throw std::invalid_argument("Invalid price");

    if (name.length() < 2)
        throw std::invalid_argument("Invalid meal name");
}

// Setters
void Meal::set_name(const std::string& name) {
    if (name.length() < 2)
        throw std::invalid_argument("Invalid meal name");
    this->name = name;
}

void Meal::set_price(float price) {
    if (price < 0)
        throw std::invalid_argument("Invalid price");
    this->price = price;
}

void Meal::set_meal_type(MealType meal_type) {
    this->meal_type = meal_type;
}

// Getters
int Meal::get_meal_id() const {
    return this->meal_id;
}

const std::string& Meal::get_name() const {
    return this->name;
}

float Meal::get_price() const {
    return this->price;
}

MealType Meal::get_meal_type() const {
    return this->meal_type;
}

const std::vector<MealSideItem>& Meal::get_side_items() const {
    return this->side_items;
}

// Methods
void Meal::print() {
    std::cout << "Meal: " << this->name << "\t- id: " << this->meal_id << "\n"
              << "price: $" << this->price << "\t- type: " << static_cast<int>(this->meal_type) << std::endl;
}

void Meal::add_side_item(MealSideItem side_item) {
    auto it = std::find(this->side_items.begin(), this->side_items.end(), side_item);
    if (it != this->side_items.end()) {
        throw std::invalid_argument("Side item already added");
    }
    this->side_items.push_back(side_item);
}

void Meal::remove_side_item(MealSideItem side_item) {
    auto it = std::find(this->side_items.begin(), this->side_items.end(), side_item);
    if (it == this->side_items.end()) {
        throw std::invalid_argument("Side item not found");
    }
    this->side_items.erase(it);
}
