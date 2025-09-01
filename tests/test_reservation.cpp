#include "catch.hpp"
#include "models/reservation.hpp"
#include "models/student.hpp"
#include "models/dining_hall.hpp"
#include "models/meal.hpp"
#include <sstream>

TEST_CASE("Reservation constructor and getters work correctly") {
    Student s("Ali", "Mohammadi", "1234567890", "Ali@gmail.com", "12345678900", "jj55");
    DiningHall dh("tohid", "tohid", 100);
    Meal m("Kabab", 15.5, MealType::BREAKFAST, ReserveDay::FRIDAY, true);

    Reservation r(&s, &dh, &m);

    REQUIRE(r.get_student() == &s);
    REQUIRE(r.get_dining_hall() == &dh);
    REQUIRE(r.get_meal() == &m);
    REQUIRE(r.get_status() == ReservationStatus::CONFIRMED);
    REQUIRE(r.get_reservation_id() >= 10001);
}

TEST_CASE("Reservation setters work correctly") {
    Student s1("Mohammad", "Alizade", "65432112345", "Mohammad@gmail.com", "10234567891", "hh88");
    Student s2("Ali", "Mohammadi", "1234567890", "Ali@gmail.com", "01234567890", "jj55");
    DiningHall dh1("tohid", "tohid", 100);
    DiningHall dh2("shokat", "shokat", 150);
    Meal m1("Kabab", 15.5, MealType::BREAKFAST, ReserveDay::FRIDAY, true);
    Meal m2("Kotlet", 10.2, MealType::LUNCH, ReserveDay::FRIDAY, true);

    Reservation r(&s1, &dh1, &m1);

    r.set_student(&s2);
    r.set_dining_hall(&dh2);
    r.set_meal(&m2);
    r.set_status(ReservationStatus::CANCELED);
    r.set_reservation_id(20000);
    r.set_created_at(123456);

    REQUIRE(r.get_student() == &s2);
    REQUIRE(r.get_dining_hall() == &dh2);
    REQUIRE(r.get_meal() == &m2);
    REQUIRE(r.get_status() == ReservationStatus::CANCELED);
    REQUIRE(r.get_reservation_id() == 20000);
    REQUIRE(r.get_created_at() == 123456);
}

TEST_CASE("Reservation cancel method works") {
    Student s("Mohammad", "Alizade", "65432112345", "Mohammad@gmail.com", "01234567890", "hh88");
    DiningHall dh("tohid", "tohid", 100);
    Meal m("Kabab", 15.5, MealType::BREAKFAST, ReserveDay::FRIDAY, true);

    Reservation r(&s, &dh, &m);

    REQUIRE(r.get_status() == ReservationStatus::CONFIRMED);
    REQUIRE(r.cancel() == true);
    REQUIRE(r.get_status() == ReservationStatus::CANCELED);
    // Cancel again should return false
    REQUIRE(r.cancel() == false);
}

TEST_CASE("Reservation print and operator<< output") {
    Student s("Mohammad", "Alizade", "65432112345", "Mohammad@gmail.com", "01234567890", "hh88");
    DiningHall dh("tohid", "tohid", 100);
    Meal m("Kabab", 15.5, MealType::BREAKFAST, ReserveDay::FRIDAY, true);

    Reservation r(&s, &dh, &m);

    std::ostringstream oss;
    oss << r;
    std::string output = oss.str();

    REQUIRE(output.find("Meal: Kabab") != std::string::npos);
    REQUIRE(output.find("Dining Hall: tohid") != std::string::npos);
    REQUIRE(output.find("Status:") != std::string::npos);
}
