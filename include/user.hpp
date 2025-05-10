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
    const std::string& getHashedPassword() const { return hashed_password; }
    const std::string& getLastName() const { return last_name; }
    const std::string& getName() const { return name; }
    int getUserId() const { return user_id; }

    // Setters
    void setHashedPassword(const std::string& hashedPassword) { hashed_password = hashedPassword; }
    void setLastName(const std::string& lastName) { last_name = lastName; }
    void setName(const std::string& Name) { name = Name; }
    void setUserId(int userId) { user_id = userId; }

    // Virtual methods
    virtual void print() const = 0;
    virtual std::string getType() const = 0;

    // Virtual destructor
    virtual ~User() = default;
};