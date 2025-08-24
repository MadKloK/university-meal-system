#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dining_hall.hpp"

TEST_CASE("Testing dininghall class", "[dining_hall]"){
    DiningHall dining_hall("aboozar", "modares", 100);
    
    SECTION("Constructor and getters"){
        REQUIRE(dining_hall.get_address() == "modares");
        REQUIRE(dining_hall.get_capacity() == 100);
        REQUIRE(dining_hall.get_name() == "aboozar");
    }

    SECTION("Setters"){
        dining_hall.set_address("enghelab");
        dining_hall.set_capacity(200);
        dining_hall.set_name("shariati");

        REQUIRE(dining_hall.get_address() == "enghelab");
        REQUIRE(dining_hall.get_capacity() == 200);
        REQUIRE(dining_hall.get_name() == "shariati");
    }
}


