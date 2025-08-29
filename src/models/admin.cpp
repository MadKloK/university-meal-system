#include "models/admin.hpp"

int Admin::next_id = 1001; 

//constructor
Admin::Admin(const std::string& name, const std::string& last_name, const std::string& hashed_password, std::string admin_id)
        : User(name, last_name, hashed_password, next_id++){
            set_admin_id(admin_id);
            next_id ++;
        }

//methods
void Admin::print() const{
    std::cout << "Admin Name: " << get_name() << ", Last Name: " << get_last_name()
                << ", User ID: " << get_user_id() << ", Type: " << get_type() << std::endl;
}

//getters
std::string Admin::get_type() const{
    return "Admin";
}
std::string Admin::get_admin_id() const{
    return admin_id;
}

//setters
void Admin::set_admin_id(std::string admin_id){
    this->admin_id = admin_id;
}