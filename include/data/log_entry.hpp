#pragma once
#include <string>
#include <ctime>

struct LogEntry {
    std::time_t timestamp{};
    std::string level;     // "INFO","WARN","ERROR","DEBUG"
    std::string message;
    std::string user_id;   // optional ("" when not applicable)
};
