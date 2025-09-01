#include <filesystem>
#include <fstream>
#include "json.hpp"
#include "student.hpp"
#include "admin.hpp"
#include "config_path.hpp"


namespace fs = std::filesystem;
using json = nlohmann::json;

class UserFileManager{
private:
    
public:
    //methods
    Student* get_student(std::string student_id, std::string password);
    Admin* get_admin(std::string password, std::string admin_id);
    
    void add_admin(const Admin& admin);
    
    json admin_to_json(const Admin& admin);
};