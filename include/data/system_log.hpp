#include "data/config_path.hpp"
#include <string>

enum class LogLevel{
    WARNING,
    ERROR,
    INFO

};

class LogSystem{
    std::string log_massage;
    LogLevel level;
    time_t created_at;

public:   
    //Constructor
    LogSystem(std::string log_massage, LogLevel level);

    //setters
    void set_log_message(const std::string& message);
    void set_log_level(LogLevel lvl);

    //getters
    std::string get_log_message() const;
    LogLevel get_log_level() const;
    time_t get_time() const;

    //methods
    void write_to_file();
    std::string log_level_to_string(LogLevel level);

};