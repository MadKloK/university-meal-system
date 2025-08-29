#include "catch.hpp"

#define _OW_SOURCE
extern "C" {
    #include "ow-crypt.h"
}

TEST_CASE("bcrypt hashing test") {
    
    char hash[256] = {0};
    REQUIRE(crypt_rn("secret123", nullptr, hash, sizeof(hash)) != nullptr);

    char verify[256] = {0};
    crypt_rn("secret123", hash, verify, sizeof(verify));

    // Compare as std::string
    REQUIRE(std::string(hash) == std::string(verify));
}
