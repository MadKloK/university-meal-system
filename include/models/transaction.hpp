#pragma once

#include <string>

enum class TransactionType {
    TRANSFER,
    PAYMENT
};

enum class TransactionStatus {
    PENDING,
    COMPLETED,
    FAILED
};

class Transaction {
private:
    static int transaction_next_id;
    int transaction_id;
    std::string tracking_code;
    float amount;
    TransactionType type;
    TransactionStatus status;
    time_t created_at;

public:
    Transaction(std::string tracking_code, float amount, TransactionType type, TransactionStatus status, time_t time);
    int get_transaction_id() const;
    time_t get_created_at() const;
    std::string get_tracking_code() const;
    float get_amount() const;
    TransactionStatus get_status() const;
    TransactionType get_type() const;
    
    void set_tracking_code(const std::string& code);
    void set_transaction_id(int id);
    void set_amount(float amt);
    void set_type(TransactionType t);
    void set_status(TransactionStatus s);
    void set_created_at(time_t t);

    void print() const;
};