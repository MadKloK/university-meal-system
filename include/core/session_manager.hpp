#pragma once

#include <string>
#include "models/admin.hpp"
#include "models/student.hpp"
#include "models/shopping_cart.hpp"


enum class SessionStatus {
    AUTHENTICATED,
    ANONYMOUS
};

class SessionBase {
protected:
    time_t created_at{};
    time_t lasttime_login{};
    SessionStatus status{SessionStatus::ANONYMOUS};

    virtual void load_session() = 0;
    virtual void save_session() = 0;

public:
    virtual void login(std::string username, std::string passw) = 0;
    virtual void logout() = 0;

    // getters
    time_t get_created_at() const { return created_at; }
    time_t get_lasttime_login() const { return lasttime_login; }
    SessionStatus get_status() const { return status; }

    // setters
    void set_created_at(time_t created_at_) { created_at = created_at_; }
    void set_lasttime_login(time_t lasttime_login_) { lasttime_login = lasttime_login_; }
    void set_status(SessionStatus status_) { status = status_; }
};


namespace AdminSession {

class SessionManager : public SessionBase {
private:
    // Singleton core
    SessionManager() = default;
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;

    // Members
    Admin* current_admin = nullptr;
    int admin_id = -1;

    void load_session() override;
    void save_session() override;

public:
    static bool sign_up();
    static bool is_there_any_admin();
    void login(std::string username, std::string passw) override;
    void logout() override;
    
    // getters
    int get_admin_id() const { return admin_id; }
    Admin* get_current_admin_ptr() const { return current_admin; }
    
    // setters
    void set_admin_id(int id) { this->admin_id = id; };
    void set_current_admin(Admin* curr) { this->current_admin = curr; }
    
    // Singleton accessor
    static SessionManager& instance();
};

} // namespace AdminSession


namespace StudentSession {

class SessionManager : public SessionBase {
private:
    // Singleton core
    SessionManager() = default;
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;

    // Members
    Student* current_student = nullptr;
    ShoppingCart* shopping_cart = nullptr;
    int student_id = -1;

    void load_session() override;
    void save_session() override;

public:
    void login(std::string username, std::string passw) override;
    void logout() override;
    
    // getters
    int get_student_id() const { return this->student_id; }
    Student* get_current_student_ptr() const { return this->current_student; }
    ShoppingCart* get_shopping_cart_ptr() const { return this->shopping_cart; }

    // setters
    void set_shopping_cart(ShoppingCart* sc) { this->shopping_cart = sc; }
    void set_current_student(Student* s) { this->current_student = s; }
    void set_student_id(int id) { this->student_id = id; }

    // Singleton accessor
    static SessionManager& instance();
};

} // namespace StudentSession
