#ifndef PANEL_HPP
#define PANEL_HPP

#include "student.hpp"
#include "reservation.hpp"
#include <vector>
#include <string>

class Panel {
private:

public:
    // Constructor
    explicit Panel() {}

    // Methods
    void action(int choice);
    void show_menu();
    void show_student_info();
    void check_balance();
    void view_shopping_cart();
    void view_reservations();
    void add_to_shopping_cart();
    void confirm_shopping_cart();
    void remove_shopping_cart_item();
    void increase_balance();
    void view_recent_transactions();
    void cancel_reservation_intractive();
    void cancel_reservation(int reservation_id);
    void exit();
};

#endif // PANEL_HPP