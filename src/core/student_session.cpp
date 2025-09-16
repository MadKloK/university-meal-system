#include "core/session_manager.hpp"

using namespace StudentSession;

//methods
void SessionManager::load_session(){
    SessionFileManager file_manager;
    file_manager.load_student_session(SessionManager::instance().get_current_student_ptr()->get_student_id());
}

void SessionManager::save_session(){
    SessionFileManager file_manager;
    file_manager.save_student_session();
}

void SessionManager::login(std::string username, std::string passw){
    UserFileManager file_manager;
    SessionManager::set_current_student(file_manager.get_student(username, passw));
}

void SessionManager::logout(){
    SessionManager::instance().set_current_student(nullptr);
    SessionManager::instance().set_shopping_cart(nullptr);
}

SessionManager& SessionManager::instance(){
    static SessionManager session_manager;
    return session_manager;
}