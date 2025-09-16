#ifndef STUDENT_PANEL_HPP
#define STUDENT_PANEL_HPP

#include "models/student.hpp"
#include "models/reservation.hpp"
#include "data/logger.hpp"       // optional if we want logging
#include <vector>
#include <string>

class Panel {
private:
    Student* current_student;                    // Pointer to the current student
    std::vector<Reservation> reservations;      // List of reservations
    std::vector<std::string> shopping_cart;     // Shopping cart items
    float balance = 0.0;                         // Current balance
    std::vector<std::string> recent_transactions; // Recent transactions
    Logger logger_;                               // Logger instance for student actions

public:
    // Main menu and action handler
    void show_menu() const;
    void action(int choice);

    // Student info & balance
    void show_student_info() const;
    void check_balance() const;

    // Shopping cart
    void view_shopping_cart() const;
    void add_to_shopping_cart();
    void confirm_shopping_cart();
    void remove_shopping_cart_item();

    // Reservations
    void view_reservations() const;
    void cancel_reservation_interactive();
    void cancel_reservation(int reservation_id);

    // Balance management
    void increase_balance();

    // Transaction history
    void view_recent_transactions() const;

    // Exit panel
    void exit();
};

#endif // STUDENT_PANEL_HPP
