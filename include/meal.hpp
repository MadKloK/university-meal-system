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

// Meal Class
class Meal {
private:
    static int next_meal_id;
    int meal_id;
    std::string name;
    float price;
    MealType meal_type;
    std::vector<MealSideItem> side_items;

public:
    // Constructor
    explicit Meal(std::string name, float price, MealType meal_type);

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
    
    // Methods
    void print();
    void add_side_item(MealSideItem side_item);
    void remove_side_item(MealSideItem side_item);
};
