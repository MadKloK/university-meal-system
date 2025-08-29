#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "user.hpp"
#include <string>

class Admin : public User {
public:
    // Constructor
    Admin(const std::string& name, const std::string& last_name, const std::string& hashed_password, int user_id)
        : User(name, last_name, hashed_password, user_id) {}

    // Override pure virtual functions from User
    void print() const override {
        std::cout << "Admin Name: " << get_name() << ", Last Name: " << get_last_name()
                  << ", User ID: " << get_user_id() << ", Type: " << get_type() << std::endl;
    }

    std::string get_type() const override {
        return "Admin";
    }
};

#endif // ADMIN_HPP