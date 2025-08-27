#include "panel.hpp"
#include "session_manager.hpp"
#include "Storage.hpp"
#include <iostream>

using namespace StudentSession;

// Show menu
void Panel::show_menu() {
    std::cout << "1. Show Student Info\n"
              << "2. Check Balance\n"
              << "3. View Reservations\n"
              << "4. View ShoppingCart"
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
            view_shopping_cart();
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

//actions
void Panel::show_student_info(){
    std::cout << *SessionManager::instance().get_current_student_ptr();
}

void Panel::check_balance(){
    float balance = SessionManager::instance().get_current_student_ptr()-> get_balance();
    std::cout << "your balance is: " << balance << " $" << std::endl;
}

void Panel::view_reservations(){
    std::vector<Reservation> reservations = SessionManager::instance().get_current_student_ptr()-> get_reservations();
    for(Reservation reservation : reservations){
        reservation.print();
    }
}

void Panel::view_shopping_cart(){
    SessionManager::instance().get_shopping_cart_ptr()-> view_shopping_cart_items();
}

void Panel::add_to_shopping_cart(){
    std::vector<Meal> all_meals = Storage::instance().get_all_meals();                //should show only active meals(fix it)
    std::vector<DiningHall> all_dining_halls = Storage::instance().get_all_dining_halls();
    int meal_index = 0;
    int dining_hall_index = 0;

    std::cout << "Select your meal: " << std::endl;
    for(Meal meal : all_meals){
        std::cout << meal_index + 1 <<". ";
        meal.print();
        meal_index++;
    }
    std::cin >>"your choice: " >> meal_index;
    
    std::cout << "Select your dining hall: " << std::endl;
    for(DiningHall dining_hall : all_dining_halls){
        std::cout << dining_hall_index + 1 <<". ";
        dining_hall.print();
        dining_hall_index++;
    }
    std::cin >>"your choice: " >> dining_hall_index;

    Reservation new_reservation(SessionManager::instance().get_current_student_ptr(), &all_dining_halls.at(dining_hall_index), &all_meals.at(meal_index));
    SessionManager::instance().get_shopping_cart_ptr()-> add_reservation(new_reservation);
}

void Panel::remove_shopping_cart_item(){
    int reservation_index;
    std::vector<Reservation> shopping_cart_items = SessionManager::instance().get_shopping_cart_ptr()-> get_reservations();

    std::cout <<"which one you want to remove?" << std::endl;
    SessionManager::instance().get_shopping_cart_ptr()-> view_shopping_cart_items();
    std::cin >> "your choice: " >> reservation_index;

    int ID = shopping_cart_items.at(reservation_index).get_reservation_id();
    SessionManager::instance().get_shopping_cart_ptr()-> remove_reservation(ID);
}

void Panel::increase_balance(){
    // Create a banking portal please.
}

// not for this phase:
// void addToShoppingCart() 
// void confirmShoppingCart()
// void viewRecentTransactions()
// void cancelReservation(int)

// Exit method
void Panel::exit() {
    std::cout << "Exiting the panel. Goodbye!\n";
}