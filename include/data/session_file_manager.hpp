#pragma once

#include "json.hpp"
#include "config_path.hpp"
#include "session_manager.hpp"
#include "storage.hpp"
#include <filesystem>
#include <fstream>

using json = nlohmann::json;
namespace fs = std::filesystem;

class SessionFileManager {
public:
    void load_student_session(const std::string &student_id);
    void save_student_session();

    // No need to these for now
    // void load_admin_session(const std::string &admin_id);
    // void save_admin_sesssion();
};
