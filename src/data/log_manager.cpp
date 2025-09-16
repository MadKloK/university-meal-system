#include <json.hpp>
#include <fstream>
#include <filesystem>
#include "data/log_manager.hpp"

using json = nlohmann::json;

LogManager& LogManager::instance() {
    static LogManager mgr;
    return mgr;
}

void LogManager::set_logs_path(const std::string& path) {
    base_path_ = path;
}

void LogManager::write_jsonline(const std::string& filename, const LogEntry& e) {
    std::filesystem::create_directories(base_path_);
    json j = {
        {"timestamp", static_cast<long long>(e.timestamp)},
        {"level", e.level},
        {"message", e.message},
        {"user_id", e.user_id}
    };
    std::ofstream ofs(base_path_ + "/" + filename, std::ios::app);
    if (!ofs) return; // silent fail for now; optionally handle
    ofs << j.dump() << '\n';
}

void LogManager::logSystem(const LogEntry& e)  { write_jsonline("system.json", e); }
void LogManager::logAdmin(const LogEntry& e)   { write_jsonline("admin.json", e); }
void LogManager::logStudent(const LogEntry& e) { write_jsonline("student.json", e); }
