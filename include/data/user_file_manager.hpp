#pragma once


#include <filesystem>
#include <fstream>
#include "json.hpp"
#include "models/student.hpp"
#include "models/admin.hpp"
#include "models/transaction.hpp"
#include "data/config_path.hpp"


namespace fs = std::filesystem;
using json = nlohmann::json;

class UserFileManager{
private:
    
public:
    //methods
    Student* get_student(std::string student_id, std::string password);
    Admin* get_admin(std::string password, std::string admin_id);
    std::vector<Transaction> get_recent_transactions(const std::string& student_id);
    
    
    void add_admin(const Admin& admin);
    void add_transaction(const Transaction& trans);
    void add_transaction(const std::string& student_id, const Transaction& trans);


    json transaction_to_json(const Transaction& trans) const;
    Transaction json_to_transaction(const json& j) const;
    json admin_to_json(const Admin& admin);

    json load_all_transactions() const;
    void save_all_transactions(const json& data);

    bool is_there_admin();
};