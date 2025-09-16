#include <filesystem>
#include <fstream>
#include "json.hpp"
#include "student.hpp"
#include "admin.hpp"
#include "config_path.hpp"
#include "transaction.hpp"


namespace fs = std::filesystem;
using json = nlohmann::json;

class UserFileManager{
private:
    
public:
    //methods
    Student* get_student(std::string student_id, std::string password);
    Admin* get_admin(std::string password, std::string admin_id);
    std::vector<Transaction> get_recent_transactions();
    
    void add_admin(const Admin& admin);
    void add_transaction(const Transaction& trans);

    json transaction_to_json(const Transaction& trans) const;
    Transaction json_to_transaction(const json& j) const
    json admin_to_json(const Admin& admin);
};