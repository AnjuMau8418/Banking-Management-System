#ifndef BANK_H
#define BANK_H

#include <string>

class Bank {
private:
    std::string generateAccountNumber();

public:
    void createAccount();
    void login();
};

#endif