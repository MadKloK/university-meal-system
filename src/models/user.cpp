#include "models/user.hpp"
#define _OW_SOURCE

extern "C" {
    #include "ow-crypt.h"
}

// Helper for hashing
std::string User::hash_password(const std::string& password) {
    char hash[256];
    crypt_rn(password.c_str(), nullptr, hash, sizeof(hash));
    return std::string(hash);
}


// Constructor
User::User(const std::string& name,
           const std::string& last_name,
           const std::string& password,
           int user_id)
    : name(name), last_name(last_name), user_id(user_id) 
{
    set_password(password);
}

// Setters
void User::set_password(const std::string& password) {
    hashed_password = hash_password(password);
}

// Methods
bool User::check_password(const std::string& password) const {
    char hash[256];
    crypt_rn(password.c_str(), hashed_password.c_str(), hash, sizeof(hash));
    return std::string(hash) == hashed_password;
}
