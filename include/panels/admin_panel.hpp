 #include <filesystem>

 namespace fs = std::filesystem;
 class AdminPanel {
public:   
    void choose_csv_file(fs::path);
    void choose_csv_file_intractive();
    void display_all_meals();
    void display_all_dininig_halls();
    void add_new_meal_intractive();
    void add_new_hall_intractive();
    void remove_meal(int ID);
    void remove_meal_interactive();
    void meal_acitvation(int ID, bool is_active);
    void meal_activaion_interactive();
    void remove_hall(int ID);
    void remove_hall_interactive();
    //add_new_admin idea(should change admin class)
    void show_menu();
    void action(int action);
    void exit();
};