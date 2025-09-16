#include <iostream>
#include "data/user_file_manager.hpp"
#include "data/session_file_manager.hpp"
#include "panels/student_panel.hpp"
#include "panels/admin_panel.hpp"

int main() {
    UserFileManager user_manager;

    std::cout << "=== University Meal System ===\n";
    std::cout << "1) Admin login\n";
    std::cout << "2) Student login\n";
    std::cout << "Choose option: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::string admin_id, password;
        std::cout << "Admin ID: ";
        std::cin >> admin_id;
        std::cout << "Password: ";
        std::cin >> password;

        Admin* admin = user_manager.get_admin(password, admin_id);
        if (!admin) {
            std::cout << "Invalid admin credentials.\n";
            return 1;
        }

        AdminSession::SessionManager& session = AdminSession::SessionManager::instance();
        session.set_current_admin(admin);
        session.set_admin_id(std::stoi(admin_id));
        session.set_status(SessionStatus::AUTHENTICATED);

        AdminPanel admin_panel; // AdminPanel can get current admin from session
        admin_panel.show_menu();

    } else if (choice == 2) {
        std::string student_id, password;
        std::cout << "Student ID: ";
        std::cin >> student_id;
        std::cout << "Password: ";
        std::cin >> password;

        Student* student = user_manager.get_student(student_id, password);
        if (!student) {
            std::cout << "Invalid student credentials.\n";
            return 1;
        }

        StudentSession::SessionManager& session = StudentSession::SessionManager::instance();
        session.set_current_student(student);
        session.set_student_id(std::stoi(student_id));
        session.set_status(SessionStatus::AUTHENTICATED);

        Panel student_panel; // Panel reads current_student and other data from session
        student_panel.show_menu();

    } else {
        std::cout << "Invalid option.\n";
    }

    return 0;
}
