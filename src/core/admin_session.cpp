#include "core/session_manager.hpp"

using namespace AdminSession;

//methods
void SessionManager::load_session(){
    SessionFileManager file_manager;
    file_manager.load_student_session(SessionManager::instance().get_current_admin_ptr()->get_admin_id());
}

void SessionManager::save_session(){
    //No need for now
}

void SessionManager::login(std::string username, std::string passw){
    UserFileManager file_manager;
    SessionManager::set_current_admin(file_manager.get_admin(username, passw));
}

void SessionManager::logout(){
    SessionManager::instance().set_current_admin(nullptr);
    SessionManager::instance().set_status(SessionStatus::ANONYMOUS);
}

SessionManager& SessionManager::instance(){
    static SessionManager session_manager;
    return session_manager;
}