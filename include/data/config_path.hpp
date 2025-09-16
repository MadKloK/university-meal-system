#pragma once
#include <filesystem>
#include <fstream>
#include "json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

class ConfigPath {
private:
    // Singleton
    ConfigPath() = default;
    ConfigPath(const ConfigPath&) = delete;
    ConfigPath& operator=(const ConfigPath&) = delete;

public:
    // Paths
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

    // Singleton accessor
    static ConfigPath& instance() {
        static ConfigPath instance;
        return instance;
    }

    // Load configuration from JSON file
    void load(const fs::path& config_file_path) {
        std::ifstream file(config_file_path);
        if (!file.is_open()) throw std::runtime_error("Failed to open config file");

        json j;
        file >> j;

        d_config = j["d_config"].get<std::string>();
        d_users = j["d_users"].get<std::string>();
        d_sessions = j["d_sessions"].get<std::string>();
        d_student_sessions = j["d_student_sessions"].get<std::string>();
        d_admin_sessions = j["d_admin_sessions"].get<std::string>();
        d_storage = j["d_storage"].get<std::string>();
        d_logs = j["d_logs"].get<std::string>();
        j_admin_config = j["j_admin_config"].get<std::string>();
        j_config_path = j["j_config_path"].get<std::string>();
        c_student = j["c_student"].get<std::string>();
        j_student_transactions = j["j_student_transactions"].get<std::string>();
        j_admin = j["j_admin"].get<std::string>();
        j_all_meals = j["j_all_meals"].get<std::string>();
        j_all_dining_hall = j["j_all_dining_hall"].get<std::string>();
        l_student = j["l_student"].get<std::string>();
        l_admin = j["l_admin"].get<std::string>();
        l_system = j["l_system"].get<std::string>();
    }
};
