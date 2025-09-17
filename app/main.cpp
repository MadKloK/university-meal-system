#include "panels/admin_panel.hpp"
#include "panels/student_panel.hpp"
#include "data/system_log.hpp"
#include "data/user_file_manager.hpp"
#include "core/session_manager.hpp"

int main(){
    UserFileManager u_manager;
    if(u_manager.is_there_admin()){
        std::string firstName, lastName, username, password;

        std::cout << "=========================================\n";
        std::cout << "          WELCOME OWNER!\n";
        std::cout << "=========================================\n\n";

        std::cout << "Hello, first admin! Let's get you set up.\n\n";

        std::cout << "Enter your first name: ";
        std::getline(std::cin, firstName);

        std::cout << "Enter your last name: ";
        std::getline(std::cin, lastName);

        std::cout << "Choose a username: ";
        std::getline(std::cin, username);

        std::cout << "Choose a password: ";
        std::getline(std::cin, password);

        Admin first_admin(firstName, lastName, password, username);
        u_manager.add_admin(first_admin);

        std::cout << "\n-----------------------------------------\n";
        std::cout << "Welcome aboard, " << firstName << " " << lastName << "!\n";
        std::cout << "Your username: " << username << "\n";
        std::cout << "Your password: " << password << "\n";
        std::cout << "Enjoy managing the system! 🚀\n";
        std::cout << "-----------------------------------------\n";

        LogSystem log("system started for the first time.", LogLevel::INFO);
        log.write_to_file();
    }

    LogSystem log("system started!", LogLevel::INFO);
    log.write_to_file();

    int i_panel;
    std::cout << "login admin(1) or student(2)? \n";
    std::cin >> i_panel;

    if(i_panel == 1){
        std::string username, pass;
        AdminPanel admin_panel;
        int choice;

        std::cout << "enter your username: \n";
        std::cin >> username;
        std::cout << "enter your password: \n";
        std::cin >> pass;

        AdminSession::SessionManager::instance().login(username, pass);
        while(true){
            admin_panel.show_menu();
            std::cin >> choice;
            admin_panel.action(choice);
        }

        AdminSession::SessionManager::instance().logout();
    }
    else if(i_panel == 2){
        std::string username, pass;
        Panel student_panel;
        int choice;

        std::cout << "enter your username: \n";
        std::cin >> username;
        std::cout << "enter your password: \n";
        std::cin >> pass;

        StudentSession::SessionManager::instance().login(username, pass);
        StudentSession::SessionManager::instance().load_session();

        while(true){
            student_panel.show_menu();
            std::cin >> choice;
            student_panel.action(choice);    
        }
        StudentSession::SessionManager::instance().logout();
        AdminSession::SessionManager::instance().save_session();
    }
}