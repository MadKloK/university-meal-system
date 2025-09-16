#include "panels/student_panel.hpp"
#include <iostream>

// Constructor is inline in header

// Show menu
void Panel::show_menu() const {
    std::cout << "\n--- Student Panel Menu ---\n";
    std::cout << "1. Show student info\n";
    std::cout << "2. Check balance\n";
    std::cout << "3. View shopping cart\n";
    std::cout << "4. Add to shopping cart\n";
    std::cout << "5. Confirm shopping cart\n";
    std::cout << "6. Remove shopping cart item\n";
    std::cout << "7. View reservations\n";
    std::cout << "8. Cancel reservation\n";
    std::cout << "9. Increase balance\n";
    std::cout << "10. View recent transactions\n";
    std::cout << "11. Exit\n";
    std::cout << "--------------------------\n";
}

// Execute chosen action
void Panel::action(int choice) {
    switch (choice) {
        case 1: show_student_info(); break;
        case 2: check_balance(); break;
        case 3: view_shopping_cart(); break;
        case 4: add_to_shopping_cart(); break;
        case 5: confirm_shopping_cart(); break;
        case 6: remove_shopping_cart_item(); break;
        case 7: view_reservations(); break;
        case 8: cancel_reservation_interactive(); break;
        case 9: increase_balance(); break;
        case 10: view_recent_transactions(); break;
        case 11: exit(); break;
        default: std::cout << "Invalid choice.\n"; break;
    }
}

// Display student information
void Panel::show_student_info() const {
    if (!current_student) return;
    std::cout << "[TODO] Display info for student: " << current_student->get_name() << "\n";
}

// Check current balance
void Panel::check_balance() const {
    std::cout << "[TODO] Current balance: " << balance << "\n";
}

// View shopping cart items
void Panel::view_shopping_cart() const {
    std::cout << "[TODO] Shopping cart items:\n";
    for (const auto& item : shopping_cart) {
        std::cout << "- " << item << "\n";
    }
}

// View reservations
void Panel::view_reservations() const {
    std::cout << "[TODO] Reservations:\n";
    for (const auto& res : reservations) {
        std::cout << "- Reservation ID: " << res.get_reservation_id() << "\n";
    }
}

// Add an item to shopping cart
void Panel::add_to_shopping_cart() {
    std::string item;
    std::cout << "Enter item to add to cart: ";
    std::cin >> item;
    shopping_cart.push_back(item);
    std::cout << item << " added to shopping cart.\n";
}

// Confirm shopping cart
void Panel::confirm_shopping_cart() {
    std::cout << "[TODO] Confirming shopping cart...\n";
    shopping_cart.clear();
}

// Remove item from shopping cart
void Panel::remove_shopping_cart_item() {
    std::cout << "[TODO] Remove item from shopping cart\n";
}

// Increase balance
void Panel::increase_balance() {
    float amount;
    std::cout << "Enter amount to add: ";
    std::cin >> amount;
    balance += amount;
    recent_transactions.push_back("Added: " + std::to_string(amount));
    std::cout << "Balance increased. New balance: " << balance << "\n";
}

// View recent transactions
void Panel::view_recent_transactions() const {
    std::cout << "[TODO] Recent transactions:\n";
    for (const auto& t : recent_transactions) {
        std::cout << "- " << t << "\n";
    }
}

// Cancel reservation interactively
void Panel::cancel_reservation_interactive() {
    int id;
    std::cout << "Enter reservation ID to cancel: ";
    std::cin >> id;
    cancel_reservation(id);
}

// Cancel reservation by ID
void Panel::cancel_reservation(int reservation_id) {
    std::cout << "[TODO] Cancel reservation with ID: " << reservation_id << "\n";
}

// Exit panel
void Panel::exit() {
    std::cout << "Exiting Student Panel...\n";
}
