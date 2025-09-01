#include "data/user_file_manager.hpp"
#include <sstream>

void UserFileManager::add_admin(const Admin& admin){
    json j;

    // Read existing file if it exists
    std::ifstream inFile(ConfigPath::instance().j_admin);
    if (inFile.is_open()) {
        inFile >> j;
        inFile.close();
    } else {
        j = json::array(); // start new array if file doesn't exist
    }

    // Optional: check for duplicate admin_id
    for (const auto& item : j) {
        if (item["admin_id"] == admin.get_admin_id()) {
            throw std::runtime_error("Admin with this ID already exists.");
        }
    }

    // Add the new admin using the free function
    j.push_back(admin_to_json(admin));

    // Write back to file
    std::ofstream outFile(ConfigPath::instance().j_admin);
    if (!outFile.is_open())
        throw std::runtime_error("Failed to open admin JSON file for writing.");

    outFile << j.dump(4); // pretty-print JSON
}

json UserFileManager::admin_to_json(const Admin& admin) {
    return json{
        {"admin_id", admin.get_admin_id()},
        {"name", admin.get_name()},
        {"last_name", admin.get_last_name()},
        {"hash_password", admin.get_hashed_password()}
    };
}

Student* UserFileManager::get_student(std::string student_id, std::string password){
    std::ifstream file(ConfigPath::instance().c_student);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open student CSV file.");
    }

    std::string line;
    std::getline(file, line); // skip header
    
    std::string u_id, s_id, name, last_name, hash_password, email, phone;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, u_id, ',');
        std::getline(ss, s_id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, last_name, ',');
        std::getline(ss, hash_password, ',');
        std::getline(ss, email, ',');
        std::getline(ss, phone, ',');
        if (s_id ==  student_id && hash_password == password) {
            return new Student(name, last_name, student_id, email, phone,hash_password);
        }
    }

    return nullptr;    
}

Admin* UserFileManager::get_admin(std::string password, std::string admin_id){
    std::ifstream file(ConfigPath::instance().j_admin);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open admin JSON file.");
    }

    json j;
    file >> j;

    for (const auto& item : j) {
        std::string hash = item["hash_password"];
        std::string id = item["admin_id"];

        if(hash == password && admin_id == id) {
            return new Admin(
                item["name"],
                item["last_name"],
                hash,
                admin_id
            );
        }
    }

    return nullptr; // admin not found
}