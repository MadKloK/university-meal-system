#pragma once

#include <string>
#include <vector>

// Enums
enum class MealType {
    MEAL1,
    MEAL2,
    MEAL3,
    MEAL4
};

enum class MealSideItem {
    ITEM1,
    ITEM2,
    ITEM3,
    ITEM4
};

enum class ReserveDay {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

// Meal Class
class Meal {
private:
    static int next_meal_id;
    int meal_id;
    std::string name;
    float price;
    MealType meal_type;
    ReserveDay reserve_day;
    std::vector<MealSideItem> side_items;
    bool is_active;

public:
    // Constructor
    explicit Meal(std::string name, float price, MealType meal_type, ReserveDay reserve_day, bool is_active = true);

    // Setters
    void set_name(const std::string& name);
    void set_price(float price);
    void set_meal_type(MealType meal_type);
    
    // Getters
    int get_meal_id() const;
    const std::string& get_name() const;
    float get_price() const;
    MealType get_meal_type() const;
    const std::vector<MealSideItem>& get_side_items() const;
    bool get_is_active() const { return is_active; }
    void set_is_active(bool is_active) { this->is_active = is_active; }
    
    // Methods
    void print();
    void add_side_item(MealSideItem side_item);
    void remove_side_item(MealSideItem side_item);
};
