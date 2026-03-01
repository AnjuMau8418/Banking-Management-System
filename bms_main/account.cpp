#include "Account.h"
#include <fstream>

using namespace std;

Account::Account(string n, string accNo, int p, double bal) {
    name = n;
    accountNumber = accNo;
    pin = p;
    balance = bal;
}

// get the account number
string Account::getAccountNumber() const { return accountNumber; }

// get the customer name
string Account::getName() const { return name; }

// get the pin of the customer
int Account::getPin() const { return pin; }

// get the account balance of the customer
double Account::getBalance() const { return balance; }

// add the deposited amount in the balance amount
void Account::deposit(double amount) {
    balance += amount;
}

// reduce the amount need to draw from the balance and if balance is less then amount return is as invalid
bool Account::withdraw(double amount) {
    if (amount > balance)
        return false;

    balance -= amount;
    return true;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}