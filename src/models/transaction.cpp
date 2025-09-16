#include "models/transaction.hpp"
#include <iostream>

// Static initialization
int Transaction::transaction_next_id = 1001;

//Constructor
Transaction::Transaction(std::string tracking_code, float amount, TransactionType type, TransactionStatus status, time_t time){
    set_transaction_id(transaction_next_id ++);
    set_tracking_code(tracking_code);
    set_amount(amount);
    set_type(type);
    set_status(status);
    created_at = time;
}

//Setters
void Transaction::set_tracking_code(const std::string& code){
    tracking_code = code;
}

void Transaction::set_transaction_id(int id){
    transaction_id = id;
}

void Transaction::set_amount(float amt){
    if(amount <= 0){
        throw std::invalid_argument("Invalid amount!");
    }
    amount = amt;
}

void Transaction::set_type(TransactionType t){
    type = t;
}

void Transaction::set_status(TransactionStatus s){
    status = s;
}

void Transaction::set_created_at(time_t t){
    created_at = t;
}

//Getters
int Transaction::get_transaction_id() const{
    return transaction_id;
}

time_t Transaction::get_created_at() const{
    return created_at;
}

std::string Transaction::get_tracking_code() const{
    return tracking_code;
}

float Transaction::get_amount() const{
    return amount;
}

TransactionStatus Transaction::get_status() const{
    return status;
}

TransactionType Transaction::get_type() const{
    return type;
}

//Methods
void Transaction::print() const {
    const char* type_str = "";
    switch (type) {
        case TransactionType::TRANSFER: type_str = "TRANSFER"; break;
        case TransactionType::PAYMENT: type_str = "PAYMENT"; break;
    }
    
    const char* status_str = "";
    switch (status) {
        case TransactionStatus::PENDING: status_str = "PENDING"; break;
        case TransactionStatus::COMPLETED: status_str = "COMPLETED"; break;
        case TransactionStatus::FAILED: status_str = "FAILED"; break;
    }
    
    std::cout << "Transaction ID: " << transaction_id << "\n"
              << "Tracking Code: " << tracking_code << "\n"
              << "Amount: " << amount << "\n"
              << "Type: " << type_str << "\n"
              << "Status: " << status_str << "\n"
              << "Created At: " << created_at << std::endl;
}

