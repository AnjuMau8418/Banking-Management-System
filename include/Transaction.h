#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string accountNumber;
    std::string type;
    double amount;
    std::string timestamp;

public:
    // Constructor
    Transaction(std::string accNo, std::string tType, double amt);

    // Save transaction to file
    void save() const;
};

#endif