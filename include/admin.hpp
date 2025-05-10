#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "user.hpp"
#include <string>

class Admin : public User {
public:
    // Constructor
    Admin(const std::string& name, const std::string& last_name, int user_id, const std::string& hashed_password)
        : User(name, last_name, user_id, hashed_password) {}

    // Override pure virtual functions from User
    void print() const override {
        std::cout << "Admin Name: " << getName() << ", Last Name: " << getLastName()
                  << ", User ID: " << getUserId() << ", Type: " << getType() << std::endl;
    }

    std::string getType() const override {
        return "Admin";
    }
};

#endif // ADMIN_HPP