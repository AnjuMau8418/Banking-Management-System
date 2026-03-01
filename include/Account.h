#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string name;
    std::string accountNumber;
    int pin;
    double balance;

public:
    // Constructor
    Account(std::string n, std::string accNo, int p, double bal);

    // Getters
    std::string getAccountNumber() const;
    std::string getName() const;
    int getPin() const;
    double getBalance() const;

    // Operations
    void deposit(double amount);
    bool withdraw(double amount);

    // Setter
    void setBalance(double newBalance);
};

#endif