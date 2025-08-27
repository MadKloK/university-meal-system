#include "admin_panel.hpp"
#include "storage.hpp"
#include <iostream>


//Show menu
void AdminPanel::show_menu(){
    std::cout << "===== Admin Panel Menu =====\n"
                << "1. Choose csv File\n"
                << "2. Show All Meals\n"
                << "3. Show All DiningHalls\n"
                << "4. Add New Meal\n"
                << "5. Add New DiningHall\n"
                << "6. Remove a Meal\n"
                << "7. Active Or Deavtive a Meal\n"
                << "8. Remove a DiningHall\n"
                << "9. Exit\n"
                << "Please enter your choice: ";
}

//Reciving the command
void AdminPanel::action(int action)
{
    switch(action) {
        case 1:
            choose_csv_file_intractive();  
            break;
        case 2:
            display_all_meals();
            break;
        case 3:
            display_all_dininig_halls();
            break;
        case 4:
            add_new_meal_intractive();
            break;
        case 5:
            add_new_hall_intractive();
            break;
        case 6:
            remove_meal_interactive();
            break;
        case 7:
            meal_activaion_interactive();
            break;
        case 8:
            remove_hall_interactive();
            break;
        case 9:
            exit();
            break;
        default:
            std::cout << "Invalide Choice. Please try again later";
            break;
    }
}

//Actions
void AdminPanel::choose_csv_file(fs::path) {
    //should copy csv file to /project/data
}

void AdminPanel::choose_csv_file_intractive() {
    std::string path;
    std::cout << "Inter the path of csv file : \n";
    std::cin >> path;
    choose_csv_file(path);
}

void AdminPanel::display_all_meals() {          
    Storage::instance().print_all_meals();
}

void AdminPanel::display_all_dininig_halls() {
    Storage::instance().print_all_halls();
}

void AdminPanel::add_new_meal_intractive() {
    std::string name;
    float price;
    int type;
    int day;

    std::cout << "=== Adding a Meal ===\n";

    std::cout << "Please inter the name : ";
    std::cin >> name >> "\n";

    std::cout << "Inter the price : ";
    std::cin >> price >> "\n";

    std::cout << "Choose the type of the food(\n0 : Breakfast,\n1 : Lunch,\n2 : Dinner) : ";
    std::cin >> type >> "/n";
    
    std::cout << "Enter the day the meal is served(\n0 : Monday,\n1 : Tuesday,\n2 : Wednesday,\n3 : Thursday,\n4 : Friday) : ";
    std::cin >> day >> "\n";

    //can ask for be sure
    Meal new_meal(name, price, static_cast<MealType>(type), static_cast<ReserveDay>(day));
    Storage::instance().add_meal(new_meal);
}

void AdminPanel::add_new_hall_intractive() {
    std::string name;
    std::string address;
    int capacity;

    std::cout << "=== Adding a DiningHall ===\n";

    std::cout << "Please inter the name : ";
    std::cin >> name >> "\n";

    std::cout << "Inter the addres : ";
    std::cin >> address >> "\n";

    std::cout << "Inter the capacity : ";
    std::cin >> capacity >> "\n";

    DiningHall new_hall(name, address, capacity);
    Storage::instance().add_dining_hall(new_hall);
}

void AdminPanel::remove_meal(int ID) {
    Storage::instance().remove_meal(ID);
    //file thing should be done
}

void AdminPanel::remove_meal_interactive() {
    //need to work with files(show meals and getting the ID)
}

void AdminPanel::meal_acitvation(int ID, bool is_active) {
    Storage::instance().meal_activation(ID, is_active);
    //file thing should be done
}

void AdminPanel::meal_activaion_interactive() {
    //need to work with files
}

void AdminPanel::remove_hall(int ID) {
    Storage::instance().remove_dining_hall(ID);
    //need file work
}

void AdminPanel::remove_hall_interactive() {
    //need file work
}
