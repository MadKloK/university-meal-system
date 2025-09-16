#include "models/shopping_cart.hpp"
#include <iostream>
#include <algorithm>

//Constructor
ShoppingCart::ShoppingCart(Reservation reservation){
    reservations.push_back(reservation);
}

//methods
void ShoppingCart::add_reservation(Reservation reservation){
    auto it = std::find(reservations.begin(), reservations.end(), reservation);

    if(reservations.end() == it){
        reservations.push_back(reservation);
    }
}

void ShoppingCart::remove_reservation(int ID){
    auto it = std::find_if(reservations.begin(), reservations.end(), [ID](const Reservation& reservation){
        return reservation.get_reservation_id() == ID;
    });

    if(it != reservations.end()){
        reservations.erase(it);
    }
}

void ShoppingCart::view_shopping_cart_items(){
    int reservation_index;
    for(Reservation reservation : reservations){
        std::cout << reservation_index << ". ";
        reservation.print();
        reservation_index++;
    }
}

void ShoppingCart::clear(){
    reservations.clear();
}

std::vector<Reservation> ShoppingCart::get_reservations() const{
    return reservations;
}


