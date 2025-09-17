#include "core/session_manager.hpp"
#include "data/system_log.hpp"

using namespace AdminSession;

//methods
void SessionManager::load_session(){
    //no need for now
}

void SessionManager::save_session(){
    //No need for now
}

void SessionManager::login(std::string username, std::string passw){
    UserFileManager file_manager;
    LogSystem log("Admin: " + SessionManager::instance().get_current_admin_ptr()->get_admin_id() + "Login", LogLevel::INFO);

    log.write_to_file();
    SessionManager::set_current_admin(file_manager.get_admin(username, passw));
}

void SessionManager::logout(){
    LogSystem log("Admin: " + SessionManager::instance().get_current_admin_ptr()->get_admin_id() + " Logout", LogLevel::INFO);
    log.write_to_file();

    SessionManager::instance().set_current_admin(nullptr);
    SessionManager::instance().set_status(SessionStatus::ANONYMOUS);
}

SessionManager& SessionManager::instance(){
    static SessionManager session_manager;
    return session_manager;
}