#pragma once

#include <string>
#include "log_entry.hpp"

class LogManager {
public:
    static LogManager& instance();

    // log to three distinct files
    void logSystem(const LogEntry& e);
    void logAdmin(const LogEntry& e);
    void logStudent(const LogEntry& e);

    // optionally configure base path
    void set_logs_path(const std::string& path);

private:
    LogManager() = default;
    ~LogManager() = default;
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

    std::string base_path_ = "data/logs";
    void write_jsonline(const std::string& filename, const LogEntry& e);
};
