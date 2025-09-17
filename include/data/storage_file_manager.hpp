#pragma once

#include "data/storage.hpp"
#include "data/config_path.hpp"
#include "json.hpp"
#include <filesystem>

using json = nlohmann::json;
namespace fs = std::filesystem;

class StorageFileManager {
public:
    void load_dining_halls();
    void load_meals();

    void save_dining_halls();
    void save_meals();
};