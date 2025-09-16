#include "data/config_path.hpp"

// ConfigPath& ConfigPath::instance(){
//     static ConfigPath instance;
//     return instance;   
// }

// //load
// void ConfigPath::load(const fs::path& config_file_path){
//     std::ifstream file(config_file_path);
//     if (!file) throw std::runtime_error("Could not open config file: " + config_file_path.string());

//     json j;
//     file >> j;
    
//     fs::path base = config_file_path.parent_path(); 
    
//     d_config               = base / j.value("d_config", ".");
//     d_users                = base / j.value("d_users", "../data/users");
//     d_sessions             = base / j.value("d_session", "../data/session");
//     d_storage              = base / j.value("d_storage", "../data/storage");
//     d_logs                 = base / j.value("d_logs", "../data/logs");
//     j_admin_config         = base / j.value("j_admin_config", "admin_config.json");
//     c_student              = base / j.value("c_student", "../data/users/students.csv");
//     j_student_transactions = base / j.value("j_student_transactions", "../data/users/student_transactions.json");
//     j_admin                = base / j.value("j_admins", "../data/users/admins.json");
//     j_admin_session        = base / j.value("j_admin_sessions", "../data/sessions/admin_sessions.json");
//     j_student_session      = base / j.value("j_student_sessions", "../data/sessions/student_sessions.json");
//     j_all_meals            = base / j.value("j_all_meals", "../data/storage/all_meals.json");
//     j_all_dining_hall      = base / j.value("j_all_dining_halls", "../data/storage/all_dining_halls.json");
//     l_student              = base / j.value("l_student_logs", "../data/logs/student.log");
//     l_admin                = base / j.value("l_admin_logs", "../data/logs/admin.log");
//     l_system               = base / j.value("l_system_logs", "../data/logs/system.log");
// }