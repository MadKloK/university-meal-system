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
    }

    std::string username, pass;
    
    std::cout << "enter your username: \n";
    std::cin >> username;
    std::cout << "enter your password: \n";
    std::cin >> pass;

    Admin *admin = u_manager.get_admin(username, pass);
    if(admin != nullptr){
        AdminSession
        
        int choice;
        AdminPanel admin_panel;

        while(true){
            admin_panel.show_menu();
            admin_panel.action(choice);
        }
    }
}