# Banking Management System (C++)

A modular, console-based Banking Management System developed using **C++**, demonstrating core software engineering concepts such as **Object-Oriented Programming, file handling, and persistent data storage**.

This project simulates basic banking operations and is designed to strengthen backend development fundamentals.

---

## 🚀 Features

- Create new bank accounts
- Secure login using Account Number and PIN
- Deposit and withdraw money
- Check account balance
- Transaction logging
- Persistent storage using text files
- Menu-driven console interface

---

## 🛠 Tech Stack & Concepts Used

- **C++**
- Object-Oriented Programming (OOP)
- File Handling (`fstream`)
- Standard Template Library (STL)
  - `vector`
  - `stringstream`
- Modular code structure (`.h` / `.cpp` separation)

---

## ▶ How to Run the Project

### Prerequisites
- C++ compiler (GCC / MinGW)
- Windows PowerShell or Command Prompt

### Compile
```bash
- g++ src/main.cpp src/Bank.cpp src/Account.cpp src/Transaction.cpp -I include -o bank
- .\bank.exe
