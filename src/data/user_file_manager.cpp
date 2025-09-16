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

json UserFileManager::admin_to_json(const Admin& admin){
    return json{
        {"admin_id", admin.get_admin_id()},
        {"name", admin.get_name()},
        {"last_name", admin.get_last_name()},
        {"hash_password", admin.get_hashed_password()}
    };
}

json UserFileManager::transaction_to_json(const Transaction& trans) const {
    return {
        {"transaction_id", trans.get_transaction_id()},
        {"tracking_code", trans.get_tracking_code()},
        {"amount", trans.get_amount()},
        {"type", static_cast<int>(trans.get_type())},
        {"status", static_cast<int>(trans.get_status())},
        {"created_at", trans.get_created_at()}
    };
}

Transaction UserFileManager::json_to_transaction(const json& j) const {
    Transaction trans(
        j.at("tracking_code").get<std::string>(),
        j.at("amount").get<float>(),
        static_cast<TransactionType>(j.at("type").get<int>()),
        static_cast<TransactionStatus>(j.at("status").get<int>()),
        j.at("created_at").get<time_t>()
    );
    trans.set_transaction_id(j.at("transaction_id").get<int>());
    return trans;
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

json UserFileManager::load_all_transactions() const {
    std::ifstream file(ConfigPath::instance().j_student_transactions);
    
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file!\n");
    }
    
    json data;
    try {
        file >> data;
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to parse JSON from file!\n");
    }
    
    return data;
}

std::vector<Transaction> UserFileManager::get_recent_transactions(const std::string& student_id) {
    json all_data = load_all_transactions();
    
    if (!all_data.contains(student_id)) {
        return {};
    }
    
    std::vector<Transaction> transactions;
    for (const auto& trans_json : all_data[student_id]) {
        transactions.push_back(json_to_transaction(trans_json));
    }
    
    std::sort(transactions.begin(), transactions.end(),
        [](const Transaction& a, const Transaction& b) {
            return a.get_created_at() > b.get_created_at();
        });
    
    size_t count = std::min(transactions.size(), size_t(5));
    return std::vector<Transaction>(transactions.begin(), transactions.begin() + count);
    }
 
void UserFileManager::add_transaction(const std::string& student_id, const Transaction& trans) {
    json all_data = load_all_transactions();
    
    if (!all_data.contains(student_id)) {
        all_data[student_id] = json::array();
    }

    all_data[student_id].push_back(transaction_to_json(trans));

    save_all_transactions(all_data);
}

void UserFileManager::save_all_transactions(const json& data) {
    std::ofstream file(ConfigPath::instance().j_student_transactions);
    file << data.dump(4);
}