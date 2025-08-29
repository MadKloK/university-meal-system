#pragma once

#include <string>
#include <iostream>
extern "C" {
    #include "ow-crypt.h"
}


class User {
private:
    std::string name;
    std::string last_name;
    std::string hashed_password;
    int user_id;

public:
    // Constructor
    User(const std::string& name, const std::string& last_name, const std::string& hashed_password, int user_id)
        : name(name), last_name(last_name), hashed_password(hashed_password), user_id(user_id) {}

    // Getters
    const std::string& get_hashed_password() const;
    const std::string& get_last_name() const;
    const std::string& get_name() const;
    int get_user_id() const;

    // Setters
    void set_hashed_password(const std::string& password);
    void set_last_name(const std::string& last_name);
    void set_name(const std::string& name);
    void set_user_id(int user_id);
    void set_password(const std::string& password);

    //methods
    bool check_password(std::string& password);

    // Virtual methods
    virtual void print() const = 0;
    virtual std::string get_type() const = 0;

    // Virtual destructor
    virtual ~User() = default;
};