#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "user.hpp"
#include <string>

class Admin : public User {
    static int next_id;
    std::string admin_id;

public:
    // Constructor
    Admin(const std::string& name, const std::string& last_name, const std::string& hashed_password, std::string admin_id);

    // Override pure virtual functions from User
    void print() const override;

    //getters
    std::string get_type() const override;
    std::string get_admin_id() const;

    //setters
    void set_admin_id(std::string admin_id);
};

#endif // ADMIN_HPP