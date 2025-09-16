#pragma once
#include <string>
#include <ctime>
#include "log_manager.hpp"
#include "log_level.hpp"

class Logger {
public:
    enum class Type { SYSTEM, ADMIN, STUDENT };

    explicit Logger(Type type) : type_(type) {}
    
    static Logger& system() {
        static Logger logger(Logger::Type::SYSTEM);
        return logger;
    }

    void log(LogLevel level, const std::string& message, const std::string& user_id = "") {
        LogEntry entry{ std::time(nullptr), to_string(level), message, user_id };

        switch(type_) {
            case Type::SYSTEM:
                LogManager::instance().logSystem(entry);
                break;
            case Type::ADMIN:
                LogManager::instance().logAdmin(entry);
                break;
            case Type::STUDENT:
                LogManager::instance().logStudent(entry);
                break;
        }
    }

private:
    Type type_;
};