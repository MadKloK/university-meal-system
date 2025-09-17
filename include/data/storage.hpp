#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>

#include "models/meal.hpp"
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
    int get_meal_id_counter() const;
    int get_dining_hall_id_counter() const;
    const std::vector<Meal>& get_all_meals() const;
    const std::vector<DiningHall>& get_all_dining_halls() const;

    // Methods
    void add_meal(const Meal& meal);
    void add_dining_hall(const DiningHall& dining_hall);
    void remove_meal(int ID);
    void remove_dining_hall(int ID);
    void meal_activation(int ID, bool is_active);
    void print_all_meals();
    void print_all_halls();
    std::vector<Meal>::iterator find_meal(int ID);
    std::vector<DiningHall>::iterator find_dining_hall(int ID);

};

#endif // STORAGE_HPP