#include "Bank.h"
#include <iostream>

using namespace std;

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n===== Banking Management System =====\n";
        cout << "1. Create the Account\n";
        cout << "2. Login into your Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
       
        // start the method according to the choosen option
        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.login();
                break;
            case 3:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}