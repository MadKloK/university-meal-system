#pragma once

#include <string>
#include <vector>
#include "models/student.hpp"
#include "models/admin.hpp"
#include "models/transaction.hpp"
#include "data/config_path.hpp"
#include "json.hpp"

using json = nlohmann::json;

class UserFileManager {
public:
    // Get users and transactions
    Student* get_student(const std::string& student_id, const std::string& password);
    Admin* get_admin(const std::string& password, const std::string& admin_id);
    std::vector<Transaction> get_recent_transactions(const std::string& student_id);

    // Add users or transactions
    void add_admin(const Admin& admin);
    void add_transaction(const std::string& student_id, const Transaction& trans);

    // Convert between objects and JSON
    json transaction_to_json(const Transaction& trans) const;
    Transaction json_to_transaction(const json& j) const;
    json admin_to_json(const Admin& admin) const;

    // Load/save all transactions
    json load_all_transactions() const;
    void save_all_transactions(const json& data);
};
