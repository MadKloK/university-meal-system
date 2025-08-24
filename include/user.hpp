#pragma once

#include <string>
#include <iostream>


class User {
private:
    std::string hashed_password;
    std::string last_name;
    std::string name;
    int user_id;

public:
    // Constructor
    User(const std::string& name, const std::string& last_name, int user_id, const std::string& hashed_password)
        : name(name), last_name(last_name), user_id(user_id), hashed_password(hashed_password) {}

    // Getters
    const std::string& get_hashed_password() const { return hashed_password; }
    const std::string& get_last_name() const { return last_name; }
    const std::string& get_name() const { return name; }
    int get_user_id() const { return user_id; }

    // Setters
    void set_hashed_password(const std::string& hashed_password) { this->hashed_password = hashed_password; }
    void set_last_name(const std::string& last_name) { this->last_name = last_name; }
    void set_name(const std::string& name) { this->name = name; }
    void set_user_id(int user_id) { this->user_id = user_id; }

    // Virtual methods
    virtual void print() const = 0;
    virtual std::string get_type() const = 0;

    // Virtual destructor
    virtual ~User() = default;
};