#include "panels/admin_panel.hpp"
#include <iostream>

// Constructor
AdminPanel::AdminPanel(const std::string& admin_id)
    : admin_id_(admin_id) {
    std::cout << "AdminPanel created for admin: " << admin_id_ << "\n";
}

// Select CSV file directly
void AdminPanel::choose_csv_file(const fs::path& path) {
    csv_file_ = path;
    std::cout << "CSV file chosen: " << csv_file_ << "\n";
}

// Select CSV interactively
void AdminPanel::choose_csv_file_interactive() {
    std::string input;
    std::cout << "Enter path to CSV file: ";
    std::cin >> input;
    csv_file_ = fs::path(input);
    std::cout << "CSV file set to: " << csv_file_ << "\n";
}

// Show all meals
void AdminPanel::display_all_meals() const {
    std::cout << "[TODO] Display all meals\n";
}

// Show all dining halls
void AdminPanel::display_all_dining_halls() const {
    std::cout << "[TODO] Display all dining halls\n";
}

// Add new meal (interactive)
void AdminPanel::add_new_meal_interactive() {
    std::cout << "[TODO] Add new meal interactively\n";
}

// Add new hall (interactive)
void AdminPanel::add_new_hall_interactive() {
    std::cout << "[TODO] Add new hall interactively\n";
}

// Remove meal by ID
void AdminPanel::remove_meal(int ID) {
    std::cout << "[TODO] Remove meal with ID " << ID << "\n";
}

// Remove meal (interactive)
void AdminPanel::remove_meal_interactive() {
    int id;
    std::cout << "Enter meal ID to remove: ";
    std::cin >> id;
    remove_meal(id);
}

// Activate/deactivate meal
void AdminPanel::meal_activation(int ID, bool is_active) {
    std::cout << "[TODO] Set meal " << ID
              << (is_active ? " active\n" : " inactive\n");
}

// Interactive meal activation
void AdminPanel::meal_activation_interactive() {
    int id;
    char choice;
    std::cout << "Enter meal ID: ";
    std::cin >> id;
    std::cout << "Activate (y/n)? ";
    std::cin >> choice;
    meal_activation(id, (choice == 'y' || choice == 'Y'));
}

// Remove hall by ID
void AdminPanel::remove_hall(int ID) {
    std::cout << "[TODO] Remove hall with ID " << ID << "\n";
}

// Remove hall (interactive)
void AdminPanel::remove_hall_interactive() {
    int id;
    std::cout << "Enter hall ID to remove: ";
    std::cin >> id;
    remove_hall(id);
}

// Show admin menu
void AdminPanel::show_menu() const {
    std::cout << "\n--- Admin Panel Menu ---\n";
    std::cout << "1. Choose CSV file\n";
    std::cout << "2. Display all meals\n";
    std::cout << "3. Display all dining halls\n";
    std::cout << "4. Add new meal\n";
    std::cout << "5. Add new hall\n";
    std::cout << "6. Remove meal\n";
    std::cout << "7. Meal activation\n";
    std::cout << "8. Remove hall\n";
    std::cout << "9. Exit\n";
    std::cout << "--------------------------\n";
}

// Execute action
void AdminPanel::action(int action) {
    switch (action) {
        case 1: choose_csv_file_interactive(); break;
        case 2: display_all_meals(); break;
        case 3: display_all_dining_halls(); break;
        case 4: add_new_meal_interactive(); break;
        case 5: add_new_hall_interactive(); break;
        case 6: remove_meal_interactive(); break;
        case 7: meal_activation_interactive(); break;
        case 8: remove_hall_interactive(); break;
        case 9: exit(); break;
        default: std::cout << "Invalid choice.\n"; break;
    }
}

// Exit admin panel
void AdminPanel::exit() {
    std::cout << "Exiting Admin Panel...\n";
}

// Getter
std::string AdminPanel::get_admin_id() const {
    return admin_id_;
}
