#include "../include/panel.hpp"
#include <iostream>

// Show menu
void Panel::show_menu() {
    std::cout << "1. Show Student Info\n"
              << "2. Check Balance\n"
              << "3. View Reservations\n"
              << "4. Add Reservation\n"
              << "5. Add to Shopping Cart\n"
              << "6. Confirm Shopping Cart\n"
              << "7. Remove Shopping Cart Item\n"
              << "8. Increase Balance\n"
              << "9. View Recent Transactions\n"
              << "10. Cancel Reservation\n"
              << "11. Exit\n";
}

// Action method
void Panel::action(int choice) {
    switch (choice) {
        case 1:
            show_student_info();
            break;
        case 2:
            check_balance();
            break;
        case 3:
            view_reservations();
            break;
        case 4:
            add_reservation();
            break;
        case 5:
            add_to_shopping_cart();
            break;
        case 6:
            confirm_shopping_cart();
            break;
        case 7:
            remove_shopping_cart_item();
            break;
        case 8:
            increase_balance();
            break;
        case 9:
            view_recent_transactions();
            break;
        case 10:
            int reservation_id;
            std::cout << "Enter Reservation ID to cancel: ";
            std::cin >> reservation_id;
            cancel_reservation(reservation_id);
            break;
        case 11:
            exit();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}

// Exit method
void Panel::exit() {
    std::cout << "Exiting the panel. Goodbye!\n";
}