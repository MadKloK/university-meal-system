#include "core/session_manager.hpp"
#include "data/system_log.hpp"

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
    LogSystem log("Student: " + SessionManager::instance().get_current_student_ptr()->get_student_id() + "Login", LogLevel::INFO);
    log.write_to_file();
    
    UserFileManager file_manager;
    SessionManager::set_current_student(file_manager.get_student(username, passw));
}

void SessionManager::logout(){
    LogSystem log("Student: " + SessionManager::instance().get_current_student_ptr()->get_student_id() + "Logout", LogLevel::INFO);
    log.write_to_file();

    SessionManager::instance().set_current_student(nullptr);
    SessionManager::instance().set_shopping_cart(nullptr);
}

SessionManager& SessionManager::instance(){
    static SessionManager session_manager;
    return session_manager;
}