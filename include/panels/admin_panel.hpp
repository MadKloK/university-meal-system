#ifndef ADMIN_PANEL_HPP
#define ADMIN_PANEL_HPP

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class AdminPanel {
public:
    explicit AdminPanel(const std::string& admin_id);

    void choose_csv_file(const fs::path& path);
    void choose_csv_file_interactive();
    void display_all_meals() const;
    void display_all_dining_halls() const;
    void add_new_meal_interactive();
    void add_new_hall_interactive();
    void remove_meal(int ID);
    void remove_meal_interactive();
    void meal_activation(int ID, bool is_active);
    void meal_activation_interactive();
    void remove_hall(int ID);
    void remove_hall_interactive();
    void show_menu() const;
    void action(int action);
    void exit();

    std::string get_admin_id() const;

private:
    std::string admin_id_;
    fs::path csv_file_;
};

#endif // ADMIN_PANEL_HPP
