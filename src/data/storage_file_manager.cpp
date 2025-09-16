#include "storage_file_manager.hpp"

void StorageFileManager::load_dining_halls(){
    json j = json::array();

    fs::path file_path = ConfigPath::instance().j_all_dining_hall;
    bool found = fs::exists(file_path);

    if(!found){
        std::ofstream out(file_path.string());
        if(!out.is_open()){
            throw std::runtime_error("Can't open the file");
        }

        out << j.dump(4);
        out.close();
        return;
    }

    std::ifstream file(ConfigPath::instance().j_all_dining_hall.string());
    if(!file.is_open()){
            throw std::runtime_error("Can't open the file");
        }
    
    file >> j;
    file.close();
    
    for(const auto& hall : j){
        DiningHall dining_hall(hall["dining_hall_id"], hall["address"], hall["capacity"].get<int>());
        Storage::instance().add_dining_hall(dining_hall);
    }
}

void StorageFileManager::load_meals(){
    json j = json::array();

    fs::path file_path = ConfigPath::instance().j_all_meals;
    bool found = fs::exists(file_path);

    if(!found){    
        std::ofstream out(file_path.string());
        if(!out.is_open()){
            throw std::runtime_error("Can't open the file");
        }

        out << j.dump(4);
        out.close();
        return;
    }

    std::ifstream file(file_path.string());
    if(!file.is_open()){
            throw std::runtime_error("Can't open the file");
        }
    
    file >> j;
    file.close();
    
    for(const auto& m : j){
        Meal meal(m["name"],
             m["price"].get<float>(), 
             static_cast<MealType>(m["meal_type"].get<int>()), 
             static_cast<ReserveDay>(m["reservation_day"].get<int>()), 
             m["is_active"].get<bool>());
        Storage::instance().add_meal(meal);
    }
}

void StorageFileManager::save_dining_halls(){
    json j = json::array(); // root array for all dining halls

    fs::path file_path = ConfigPath::instance().j_all_dining_hall;

    // Loop through all dining halls in storage
    for (const auto& hall : Storage::instance().get_all_dining_halls()) {
        json h;

        h["dining_hall_id"] = hall.get_hall_id();   // int
        h["address"] = hall.get_address();          // string
        h["capacity"] = hall.get_capacity();        // int

        j.push_back(h);
    }

    // Ensure the folder exists
    fs::path folder = file_path.parent_path();
    if (!fs::exists(folder)) fs::create_directories(folder);

    // Open file with truncation to overwrite
    std::ofstream out(file_path.string(), std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        throw std::runtime_error("Can't open the file for writing");
    }

    out << j.dump(4); // pretty print
    out.close();
}

void StorageFileManager::save_meals(){
    json j = json::array(); // root array for all meals

    fs::path file_path = ConfigPath::instance().j_all_meals;

    // Loop through all meals in storage
    for (const auto& meal : Storage::instance().get_all_meals()) {
        json m;

        m["name"] = meal.get_name();                      // string
        m["price"] = meal.get_price();                    // float
        m["meal_type"] = static_cast<int>(meal.get_meal_type());        // enum -> int
        m["reservation_day"] = static_cast<int>(meal.get_reserve_day()); // enum -> int
        m["is_active"] = meal.get_is_active();                // bool

        j.push_back(m);
    }

    // Open file with truncation to clear old content
    std::ofstream out(file_path.string(), std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        throw std::runtime_error("Can't open the file for writing");
    }

    out << j.dump(4); // pretty print with 4-space indentation
    out.close();
}
