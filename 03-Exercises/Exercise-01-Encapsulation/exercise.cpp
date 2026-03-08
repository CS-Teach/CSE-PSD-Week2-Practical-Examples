// ============================================================
// Exercise 1: Encapsulation — BankAccount
// ============================================================
// Your task: Implement a BankAccount class with proper
//            encapsulation (private data, public interface).
//
// Requirements:
//   1. Private members: ownerName (string), balance (double)
//   2. Constructor takes owner name and initial balance
//      - Throw invalid_argument if initial balance is negative
//   3. getOwnerName() — returns the owner's name
//   4. getBalance() — returns the current balance
//   5. deposit(double amount)
//      - Add amount to balance
//      - Throw invalid_argument if amount <= 0
//   6. withdraw(double amount)
//      - Subtract amount from balance
//      - Throw invalid_argument if amount <= 0
//      - Throw runtime_error if amount > balance (insufficient funds)
//
// Compile & test:
//   g++ -std=c++17 -o test tests.cpp && ./test
//
// The tests file #includes this file — just implement below.
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
    // TODO: Add private member variables

public:
    // TODO: Implement constructor
    BankAccount(const string& ownerName, double initialBalance) {
        // Your code here
    }

    // TODO: Implement getOwnerName()

    // TODO: Implement getBalance()

    // TODO: Implement deposit()

    // TODO: Implement withdraw()
};

#endif // EXERCISE_CPP
