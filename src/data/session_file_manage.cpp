#include "session_file_manager.hpp"

void load_student_session(const std::string &student_id){
    std::string file_name = student_id + ".json";
    fs::path file_path = ConfigPath::instance().d_student_sessions / file_name;
    bool found = fs::exists(file_path);
    
    if(found){
        json j;
        
        std::ifstream file(file_path);
        if(!file.is_open()){
            throw std::runtime_error("Can't open the file");
        }

        file >> j;
        file.close();

        StudentSession::SessionManager::instance().get_current_student_ptr()->set_balance(j["balance"].get<float>());

        for(const auto& item : j["reservations"]){
            int meal_id = item["meal_id"].get<int>();
            int dining_hall_id = item["dining_hall_id"].get<int>();

            Meal *meal = &(*Storage::instance().find_meal(meal_id));
            DiningHall *dining_hall = &(*Storage::instance().find_dining_hall(dining_hall_id));
            Student *student = StudentSession::SessionManager::instance().get_current_student_ptr();

            Reservation r(student, dining_hall, meal);

            StudentSession::SessionManager::instance().get_current_student_ptr()->reserve_meal(r);
        }

        for(const auto& item : j["shopping_cart"]){
            int meal_id = item["meal_id"].get<int>();
            int dining_hall_id = item["dining_hall_id"].get<int>();

            Meal *meal = &(*Storage::instance().find_meal(meal_id));
            DiningHall *dining_hall = &(*Storage::instance().find_dining_hall(dining_hall_id));
            Student *student = StudentSession::SessionManager::instance().get_current_student_ptr();

            Reservation r(student, dining_hall, meal);

            StudentSession::SessionManager::instance().get_shopping_cart_ptr()->add_reservation(r);
        }
    }

    else{
        json j;

        j["balance"] = "0";
        j["reservations"] = json::array();
        j["shopping_cart"] = json::array();

        std::ofstream out(file_path);
        if(!out.is_open()){
            throw std::runtime_error("Can't open the file");
        }

        out << j.dump(4);
        out.close();
    }
}

void save_student_session(){
    json j;

    std::string file_name = StudentSession::SessionManager::instance().get_current_student_ptr()->get_student_id() + ".json";
    fs::path file_path = ConfigPath::instance().d_student_sessions / file_name;
    
    std::ifstream file(file_path);
    if(!file.is_open()){
        throw std::runtime_error("Can't open the file");
    }

    file >> j;
    file.close();

    j["balance"] = StudentSession::SessionManager::instance().get_current_student_ptr()->get_balance();
    j["reservations"].clear();
    j["shopping_cart"].clear();

    for(const auto& reservation : StudentSession::SessionManager::instance().get_current_student_ptr()->get_reservations()){
        int meal_id = reservation.get_meal()->get_meal_id();
        int dining_hall_id = reservation.get_dining_hall()->get_hall_id();
        std::string student_id = StudentSession::SessionManager::instance().get_current_student_ptr()->get_student_id();

        json r;
        
        r["meal_id"] = meal_id;
        r["dining_hall_id"] = dining_hall_id;
        r["student_id"] = student_id;

        j["reservations"].push_back(r);
    }

    for(const auto& reservation : StudentSession::SessionManager::instance().get_shopping_cart_ptr()->get_reservations()){
        int meal_id = reservation.get_meal()->get_meal_id();
        int dining_hall_id = reservation.get_dining_hall()->get_hall_id();
        std::string student_id = StudentSession::SessionManager::instance().get_current_student_ptr()->get_student_id();

        json r;
        
        r["meal_id"] = meal_id;
        r["dining_hall_id"] = dining_hall_id;
        r["student_id"] = student_id;

        j["shopping_cart"].push_back(r);
    }

    std::ofstream out(file_path);
    if(!out.is_open()){
        throw std::runtime_error("Can't open the file");
    }

    out << j.dump(4);
}

// void load_admin_session(const std::string &admin_id){

// }

// void save_admin_sesssion(){

// }