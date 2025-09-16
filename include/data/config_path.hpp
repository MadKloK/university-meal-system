#include <filesystem>
#include <fstream>
#include "json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class ConfigPath{
private:
    //singelton core
    ConfigPath() = default;
    ConfigPath(const ConfigPath&) = delete;
    ConfigPath& operator=(const ConfigPath&) = delete;

public:    
    fs::path d_config;
    fs::path d_users; 
    fs::path d_sessions;
    fs::path d_student_sessions;
    fs::path d_admin_sessions;      
    fs::path d_storage; 
    fs::path d_logs;
    fs::path j_admin_config;
    fs::path j_config_path;
    fs::path c_student;
    fs::path j_student_transactions;
    fs::path j_admin;
    fs::path j_all_meals;
    fs::path j_all_dining_hall;
    fs::path l_student;
    fs::path l_admin;
    fs::path l_system;

    static ConfigPath& instance();

    //load
    void load(const fs::path& config_file_path);
};