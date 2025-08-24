#include "session_manager.hpp"

using namespace AdminSession;

// methods
void SessionManager::load_session(){
    //empty for now
}

void SessionManager::save_session(){
    //empty for now
}

void SessionManager::login(std::string username, std::string passw){
    //empty for now
}

void SessionManager::logout(){
    //empty for now
}

SessionManager& SessionManager::instance(){
    static SessionManager session_manager;
    return session_manager;
}