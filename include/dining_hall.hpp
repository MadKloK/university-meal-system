#ifndef DINING_HALL_H
#define DINING_HALL_H

#include <string>

class DiningHall {
private:
    static int next_hall_id;
    int hall_id;
    std::string name;
    std::string address;
    int capacity;

public:
    // Constructor
    explicit DiningHall(std::string name, std::string address, int capacity);

    // Setters
    void set_name(const std::string& name);
    void set_address(const std::string& email);
    void set_capacity(int capacity);

    // Getters
    std::string get_name() const;
    std::string get_address() const;
    int get_capacity() const;
    int get_hall_id() const;

    // Methods
    void print();
};

#endif