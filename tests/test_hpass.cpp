#include "catch.hpp"

#define _OW_SOURCE
extern "C" {
    #include "ow-crypt.h"
}

TEST_CASE("bcrypt hashing test") {
    char salt[64];
    REQUIRE(crypt_gensalt_rn("$2a$", 12, nullptr, 0, salt, sizeof(salt)) != nullptr);

    char hash[64];
    REQUIRE(crypt_rn("secret123", salt, hash, sizeof(hash)) != nullptr);

    char verify[64];
    crypt_rn("secret123", hash, verify, sizeof(verify));

    // Compare as std::string
    REQUIRE(std::string(hash) == std::string(verify));
}
