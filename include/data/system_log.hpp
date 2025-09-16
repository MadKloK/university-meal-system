#pragma once

#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
#include <iostream>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class SystemLog {
private:
    std::ofstream log_file;
    std::mutex mtx; // for thread safety
    std::string filename;

    // Private constructor for singleton
    SystemLog(const std::string& file = "system.log") : filename(file) {
        log_file.open(filename, std::ios::app);
        if (!log_file.is_open()) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    ~SystemLog() {
        if (log_file.is_open()) {
            log_file.close();
        }
    }

    // Format timestamp
    std::string current_time() {
        std::time_t t = std::time(nullptr);
        char buf[64];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
        return std::string(buf);
    }

    // Convert LogLevel to string
    std::string level_to_string(LogLevel level) {
        switch (level) {
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR:   return "ERROR";
            default: return "UNKNOWN";
        }
    }

public:
    // Delete copy & assignment for singleton
    SystemLog(const SystemLog&) = delete;
    SystemLog& operator=(const SystemLog&) = delete;

    // Singleton accessor
    static SystemLog& instance() {
        static SystemLog instance;
        return instance;
    }

    // Log a message
    void log(const std::string& message, LogLevel level = LogLevel::INFO) {
        std::lock_guard<std::mutex> lock(mtx);
        if (log_file.is_open()) {
            log_file << "[" << current_time() << "] "
                     << "[" << level_to_string(level) << "] "
                     << message << std::endl;
        }
    }
};
