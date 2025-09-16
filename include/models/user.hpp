#pragma once

#include <string>
#include <iostream>

class User {
private:
    std::string name;
    std::string last_name;
    std::string hashed_password;
    int user_id;

    // helper for hashing
    static std::string hash_password(const std::string& password);

public:
    // Constructor
    User(const std::string& name,
         const std::string& last_name,
         const std::string& password,  // plain password - will be hashed
         int user_id);

    // Getters
    const std::string& get_hashed_password() const { return hashed_password; }
    const std::string& get_last_name() const { return last_name; }
    const std::string& get_name() const { return name; }
    int get_user_id() const { return user_id; }

    // Setters
    void set_last_name(const std::string& ln) { last_name = ln; }
    void set_name(const std::string& n) { name = n; }
    void set_user_id(int id) { user_id = id; }
    void set_password(const std::string& password);

    // Methods
    bool check_password(const std::string& password) const;

    // Virtual methods
    virtual void print() const = 0;
    virtual std::string get_type() const = 0;

    // Virtual destructor
    virtual ~User() = default;
};
