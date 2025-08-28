#include "catch.hpp"
#include "models/meal.hpp"

TEST_CASE("Meal constructor initializes fields correctly", "[Meal]") {
    Meal m("Pasta", 25.5, MealType::BREAKFAST, ReserveDay::FRIDAY, true);
    REQUIRE(m.get_name() == "Pasta");
    REQUIRE(m.get_price() == Approx(25.5));
    REQUIRE(m.get_meal_type() == MealType::BREAKFAST);
    REQUIRE(m.get_meal_id() >= 101);
    REQUIRE(m.get_side_items().empty());
}

TEST_CASE("Meal constructor throws on invalid price", "[Meal]") {
    REQUIRE_THROWS_AS(Meal("Rice", -5, MealType::DINNER, ReserveDay::FRIDAY, true), std::invalid_argument);
}

TEST_CASE("Meal constructor throws on short name", "[Meal]") {
    REQUIRE_THROWS_AS(Meal("A", 10, MealType::LUNCH, ReserveDay::WEDNESDAY, true), std::invalid_argument);
}

TEST_CASE("Setters validate input", "[Meal]") {
    Meal m("Soup", 10, MealType::LUNCH, ReserveDay::THURSDAY, true);
    REQUIRE_THROWS_AS(m.set_name("B"), std::invalid_argument);
    REQUIRE_THROWS_AS(m.set_price(-1), std::invalid_argument);
    m.set_name("Salad");
    REQUIRE(m.get_name() == "Salad");
    m.set_price(15.5);
    REQUIRE(m.get_price() == Approx(15.5));
}

TEST_CASE("Add and remove side items", "[Meal]") {
    Meal m("Steak", 30, MealType::DINNER, ReserveDay::FRIDAY, true);
    MealSideItem side1 = MealSideItem::ITEM1;
    MealSideItem side2 = MealSideItem::ITEM2;

    m.add_side_item(side1);
    REQUIRE(m.get_side_items().size() == 1);
    REQUIRE(m.get_side_items()[0] == side1);

    m.add_side_item(side2);
    REQUIRE(m.get_side_items().size() == 2);

    REQUIRE_THROWS_AS(m.add_side_item(side1), std::invalid_argument);

    m.remove_side_item(side1);
    REQUIRE(m.get_side_items().size() == 1);
    REQUIRE(m.get_side_items()[0] == side2);

    REQUIRE_THROWS_AS(m.remove_side_item(side1), std::invalid_argument);
}

TEST_CASE("Meal print does not throw", "[Meal]") {
    Meal m("Fish", 20, MealType::LUNCH, ReserveDay::THURSDAY, true);
    REQUIRE_NOTHROW(m.print());
}

