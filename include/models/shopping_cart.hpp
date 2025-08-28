#pragma once

#include <vector>
#include "transaction.hpp"
#include "reservation.hpp"

class ShoppingCart {
private:
    std::vector<Reservation> reservations;

public:
    //Constructor
    ShoppingCart(Reservation reservation);

    //methods
    Transaction confirm();
    void add_reservation(Reservation reservation);
    void remove_reservation(int ID);
    void view_shopping_cart_items();
    void clear();
    std::vector<Reservation> get_reservations() const;
};