#include "models/user.hpp"
#define _OW_SOURCE


//getters
const std::string& User::get_hashed_password() const{
    return hashed_password;
}

const std::string& User::get_last_name() const{
    return last_name;
}

const std::string& User::get_name() const{
    return name;
}

int User::get_user_id() const{
    return user_id;
}

//setters
void User::set_hashed_password(const std::string& hashed_password){
    this->hashed_password = hashed_password;
}

void User::set_last_name(const std::string& last_name){
    this->last_name = last_name;
}

void User::set_name(const std::string& name){
    this->name = name;
}

void User::set_user_id(int user_id){
    this-> user_id = user_id;
}

void User::set_password (const std::string& password){
    char hash[256];
    crypt_rn(password.c_str(), nullptr, hash, sizeof(hash));
    set_hashed_password(hash);
}

//methods
bool User::check_password(std::string& password){
    char hash[256];
    crypt_rn(password.c_str(), get_hashed_password().c_str(), hash, sizeof(hash));
    return std::string(hash) == get_hashed_password();
}