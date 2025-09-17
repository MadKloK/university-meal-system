#include "data/system_log.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>

//Constructor
LogSystem::LogSystem(std::string log_massage, LogLevel level){
    set_log_message(log_massage);
    set_log_level(level);
    created_at = time(0);
}

//setters
void LogSystem::set_log_message(const std::string& message){
    this->log_massage = message;
}

void LogSystem::set_log_level(LogLevel lvl){
    this->level = lvl;
}

//getters
std::string LogSystem::get_log_message() const{
    return log_massage;
}

LogLevel LogSystem::get_log_level() const{
    return level;
}

time_t LogSystem::get_time() const{
    return created_at;
}

//methods
void LogSystem::write_to_file(){
    std::ofstream file(ConfigPath::instance().l_system, std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open system.log for writing");
        }

        std::time_t t = get_time();
        std::tm* tm_ptr = std::localtime(&t);

        file << "[" << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S") << "] "
            << "[" << log_level_to_string(get_log_level()) << "] "
            << get_log_message()
            << std::endl;

        file.close();
}

std::string LogSystem::log_level_to_string(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        default:                return "UNKNOWN";
    }
}