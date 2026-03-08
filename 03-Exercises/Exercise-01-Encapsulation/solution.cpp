// ============================================================
// Exercise 1: Solution — BankAccount Encapsulation
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(const string& ownerName, double initialBalance)
        : ownerName(ownerName), balance(initialBalance)
    {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
    }

    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
    }
};

#endif // EXERCISE_CPP
