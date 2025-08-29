#include "catch.hpp"
#include "models/dining_hall.hpp"

TEST_CASE("DiningHall constructor sets fields correctly", "[DiningHall]") {
    DiningHall hall("Main Hall", "123 University Ave", 200);
    REQUIRE(hall.get_name() == "Main Hall");
    REQUIRE(hall.get_address() == "123 University Ave");
    REQUIRE(hall.get_capacity() == 200);
}

TEST_CASE("DiningHall constructor throws on invalid arguments", "[DiningHall]") {
    REQUIRE_THROWS_AS(DiningHall("", "Some Address", 100), std::invalid_argument);
    REQUIRE_THROWS_AS(DiningHall("Hall", "", 100), std::invalid_argument);
    REQUIRE_THROWS_AS(DiningHall("Hall", "Some Address", 0), std::invalid_argument);
    REQUIRE_THROWS_AS(DiningHall("Hall", "Some Address", -5), std::invalid_argument);
}

TEST_CASE("DiningHall setters work and validate input", "[DiningHall]") {
    DiningHall hall("A", "B", 10);

    hall.set_name("New Name");
    REQUIRE(hall.get_name() == "New Name");
    REQUIRE_THROWS_AS(hall.set_name(""), std::invalid_argument);

    hall.set_address("New Address");
    REQUIRE(hall.get_address() == "New Address");
    REQUIRE_THROWS_AS(hall.set_address(""), std::invalid_argument);

    hall.set_capacity(50);
    REQUIRE(hall.get_capacity() == 50);
    REQUIRE_THROWS_AS(hall.set_capacity(0), std::invalid_argument);
    REQUIRE_THROWS_AS(hall.set_capacity(-1), std::invalid_argument);
}

TEST_CASE("DiningHall hall_id is unique and auto-incremented", "[DiningHall]") {
    DiningHall hall1("Hall1", "Addr1", 10);
    DiningHall hall2("Hall2", "Addr2", 20);
    REQUIRE(hall2.get_hall_id() == hall1.get_hall_id() + 1);
}
