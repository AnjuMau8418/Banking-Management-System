#include "Transaction.h"
#include <fstream>
#include <ctime>

using namespace std;

Transaction::Transaction(string accNo, string tType, double amt) {
    accountNumber = accNo;
    type = tType;
    amount = amt;

    time_t now = time(0);
    timestamp = ctime(&now);
}

void Transaction::save() const {
    ofstream file("data/transactions.txt", ios::app);
    file << accountNumber << "|"
         << type << "|"
         << amount << "|"
         << timestamp;
    file.close();
}