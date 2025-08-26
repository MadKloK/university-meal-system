#define CATCH_CONFIG_MAIN

#include "student.hpp"
#include "dining_hall.hpp"
#include "meal.hpp"
#include "catch.hpp"

TEST_CASE("Student constructor and getters work correctly", "[Student]") {
    Student s("John", "Doe", "1234567890", "john.doe@email.com", "hashedpw");
    REQUIRE(s.get_name() == "John");
    REQUIRE(s.get_last_name() == "Doe");
    REQUIRE(s.get_student_id() == "1234567890");
    REQUIRE(s.get_email() == "john.doe@email.com");
    REQUIRE(s.get_balance() == 0.0f);
    REQUIRE(s.get_is_active() == false);
    REQUIRE(s.get_reservations().empty());
}

TEST_CASE("Student constructor throws on invalid student_id or email", "[Student]") {
    REQUIRE_THROWS_AS(Student("Jane", "Smith", "123", "jane.smith@email.com", "pw"), std::invalid_argument);
    REQUIRE_THROWS_AS(Student("Jane", "Smith", "1234567890", "short@em", "pw"), std::invalid_argument);
}

TEST_CASE("Student setters work and validate input", "[Student]") {
    Student s("Alice", "Brown", "1234567890", "alice@email.com", "pw");
    s.set_student_id("0987654321");
    REQUIRE(s.get_student_id() == "0987654321");

    s.set_email("alice.brown@email.com");
    REQUIRE(s.get_email() == "alice.brown@email.com");

    s.set_balance(100.5f);
    REQUIRE(s.get_balance() == 100.5f);

    s.set_is_active(false);
    REQUIRE_FALSE(s.get_is_active());

    REQUIRE_THROWS_AS(s.set_student_id(""), std::invalid_argument);
    REQUIRE_THROWS_AS(s.set_email("short@em"), std::invalid_argument);
    REQUIRE_THROWS_AS(s.set_balance(-1.0f), std::invalid_argument);
}

TEST_CASE("Student can reserve and cancel meals", "[Student]") {
    Student s("Bob", "White", "1234567890", "bob@email.com", "pw");
    DiningHall* dh = new DiningHall("aboozar", "modares", 100);
    Meal* meal1 = new Meal("kabab", 2500, MealType::BREAKFAST, ReserveDay::MONDAY, true);
    Meal* meal2 = new Meal("bb", 1800, MealType::DINNER, ReserveDay::FRIDAY, true);
    Reservation r1(&s, dh, meal1);
    Reservation r2(&s, dh, meal2);

    s.reserve_meal(r1);
    REQUIRE(s.get_reservations().size() == 1);

    // Cannot reserve the same meal type again
    Reservation r1_dup(&s, dh, meal1);
    REQUIRE_THROWS_AS(s.reserve_meal(r1_dup), std::invalid_argument);

    s.reserve_meal(r2);
    REQUIRE(s.get_reservations().size() == 2);

    // Cancel reservation
    REQUIRE(s.cancel_reservation(10005));
    REQUIRE(s.get_reservations().size() == 1);

    // Cancel non-existing reservation
    REQUIRE_FALSE(s.cancel_reservation(999));

    delete meal1;
    delete meal2;
}

TEST_CASE("Student print and operator<< output", "[Student]") {
    Student s("Eve", "Black", "1234567890", "eve@email.com", "pw");
    std::ostringstream oss;
    oss << s;
    std::string output = oss.str();
    REQUIRE(output.find("Eve Black") != std::string::npos);
    REQUIRE(output.find("1234567890") != std::string::npos);
    REQUIRE(output.find("eve@email.com") != std::string::npos);
}
