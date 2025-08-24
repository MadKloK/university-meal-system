#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>

#include "meal.hpp"
#include "dining_hall.hpp"

class Storage {
private:
    // Attributes
    int meal_id_counter = 1;
    int dining_hall_id_counter = 1;
    std::vector<Meal> all_meals;
    std::vector<DiningHall> all_dining_halls;

    // Private constructor for Singleton pattern
    Storage() = default;

    // Deleted copy constructor and assignment operator
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;

public:
    // Static method to get the singleton instance
    static Storage& instance() {
        static Storage storage_instance;
        return storage_instance;
    }

    // Getters
    int get_meal_id_counter() const { return meal_id_counter; }
    int get_dining_hall_id_counter() const { return dining_hall_id_counter; }
    const std::vector<Meal>& get_all_meals() const { return all_meals; }
    const std::vector<DiningHall>& get_all_dining_halls() const { return all_dining_halls; }

    // Methods
    void add_meal(const Meal& meal) { all_meals.push_back(meal); }
    void add_dining_hall(const DiningHall& dining_hall) { all_dining_halls.push_back(dining_hall); }
};

#endif // STORAGE_HPP