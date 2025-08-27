#include "storage.hpp"

// getters
int Storage::get_meal_id_counter() const{
    return meal_id_counter;
}

int Storage::get_dining_hall_id_counter() const{
    return dining_hall_id_counter;
}

const std::vector<Meal>& Storage::get_all_meals() const{
    return all_meals;
}

const std::vector<DiningHall>& Storage::get_all_dining_halls() const{
    return all_dining_halls;
}

// methods
void Storage::add_meal(const Meal& meal){
    all_meals.push_back(meal);
}

void Storage::add_dining_hall(const DiningHall& dining_hall){
    all_dining_halls.push_back(dining_hall);
}

void Storage::remove_meal(int ID){
    auto meal = find_meal(ID);
    all_meals.erase(meal);
}

void Storage::remove_dining_hall(int ID){
    auto dining_hall = find_dining_hall(ID);
    all_dining_halls.erase(dining_hall);
}

void Storage::meal_activation(int ID, bool is_active){
    auto meal = find_meal(ID);
    meal->set_is_active(is_active);
}

std::vector<Meal>::iterator Storage::find_meal(int ID){
    for (auto it = all_meals.begin(); it != all_meals.end(); ++it) {
        if (it->get_meal_id() == ID) {
            return it;
        }
    }
    return all_meals.end(); 
}

std::vector<DiningHall>::iterator Storage::find_dining_hall(int ID){
     for (auto it = all_dining_halls.begin(); it != all_dining_halls.end(); ++it) {
        if (it->get_hall_id() == ID) {
            return it;
        }
    }
    return all_dining_halls.end();
}



