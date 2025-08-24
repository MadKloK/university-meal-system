#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "meal.hpp"

TEST_CASE("Testing meal class", "[meal]"){
    Meal meal("kabab", 2500, MealType::LUNCH, ReserveDay::MONDAY, true);
    std::vector<MealSideItem> si;

    SECTION("Constructor and getters"){
        REQUIRE(meal.get_is_active() == true);
        REQUIRE(meal.get_meal_id() == 101);
        REQUIRE(meal.get_meal_type() == MealType::LUNCH);
        REQUIRE(meal.get_name() == "kabab");
        REQUIRE(meal.get_price() == 2500);
        si = meal.get_side_items();
        REQUIRE(si.empty());
    }

    SECTION("Setters"){
        meal.set_is_active(false);
        meal.set_meal_type(MealType::BREAKFAST);
        meal.set_name("chaii");
        meal.set_price(1500);

        REQUIRE(meal.get_is_active() == false);
        REQUIRE(meal.get_meal_type() == MealType::BREAKFAST);
        REQUIRE(meal.get_name() == "chaii");
        REQUIRE(meal.get_price() == 1500);
    }

    SECTION("Managing the sideitems"){
        si.push_back(MealSideItem::ITEM1);
        meal.add_side_item(MealSideItem::ITEM1); //add sideitem
        REQUIRE(meal.get_side_items() == si);

        si.clear();
        meal.remove_side_item(MealSideItem::ITEM1); //remove sideitem
        REQUIRE(meal.get_side_items() == si);
    }    
    
}