#include "Bank.h"
#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Generate Account Number

string Bank::generateAccountNumber() {
    int counter = 1000;

    // if the account_counter file is present, open this and write the data
    ifstream inFile("data/account_counter.txt");

    if (inFile.is_open()) {
        inFile >> counter;
        inFile.close();
    }

    counter++;

    ofstream outFile("data/account_counter.txt");
    outFile << counter;
    outFile.close();

    return "ACC" + to_string(counter);
}


// Create Account

void Bank::createAccount() {
    string name;
    int pin;
    double deposit;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter 4-digit PIN: ";
    cin >> pin;
    // check if the pin number is valid or not
    if (pin < 1000 || pin > 9999) {
        cout << "Invalid PIN!\n";
        return;
    }

    cout << "Enter Initial Deposit: ";
    cin >> deposit;

    // deposit should not be 0
    if (deposit < 0) {
        cout << "Deposit cannot be negative!\n";
        return;
    }

    string accNo = generateAccountNumber();

    ofstream file("data/accounts.txt", ios::app);
    file << accNo << "|" << name << "|" << pin << "|" << deposit << endl;
    file.close();

    cout << "\nAccount Created Successfully!\n";
    cout << "Your Account Number: " << accNo << endl;
}


// Login into your account

void Bank::login() {
    string accNo;
    int pin;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    cout << "Enter PIN: ";
    cin >> pin;

    ifstream file("data/accounts.txt");
    vector<string> allAccounts;
    string line;
    bool found = false;

    while (getline(file, line)) {
        allAccounts.push_back(line);
    }
    file.close();

    for (int i = 0; i < allAccounts.size(); i++) {
        stringstream ss(allAccounts[i]);
        string fileAccNo, name, filePinStr, balanceStr;

        getline(ss, fileAccNo, '|');
        getline(ss, name, '|');
        getline(ss, filePinStr, '|');
        getline(ss, balanceStr, '|');

        if (fileAccNo == accNo && stoi(filePinStr) == pin) {
            double balance = stod(balanceStr);
            found = true;

            int choice;
            do {
                cout << "\nWelcome, " << name << endl;
                cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Logout\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1) {
                    double amt;
                    cout << "Enter amount: ";
                    cin >> amt;

                    balance += amt;

                    Transaction t(accNo, "Deposit", amt);
                    t.save();

                    cout << "Deposit successful!\n";
                }
                else if (choice == 2) {
                    double amt;
                    cout << "Enter amount: ";
                    cin >> amt;

                    if (amt > balance) {
                        cout << "Insufficient balance!\n";
                    } else {
                        balance -= amt;

                        Transaction t(accNo, "Withdraw", amt);
                        t.save();

                        cout << "Withdrawal successful!\n";
                    }
                }
                else if (choice == 3) {
                    cout << "Current Balance: " << balance << endl;
                }

            } while (choice != 4);

            // Update balance in file
            allAccounts[i] = accNo + "|" + name + "|" + filePinStr + "|" + to_string(balance);

            ofstream outFile("data/accounts.txt");
            for (const string& acc : allAccounts) {
                outFile << acc << endl;
            }
            outFile.close();

            break;
        }
    }

    if (!found) {
        cout << "Invalid credentials!\n";
    }
}