// ============================================================
// Exercise 1: Tests — BankAccount Encapsulation
// ============================================================
// Compile:  g++ -std=c++17 -o test tests.cpp && ./test
//
// Each test prints PASS on success or crashes with an assert
// failure showing exactly what went wrong.
// ============================================================

#include "exercise.cpp"  // Change to "solution.cpp" to verify solution
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    // Test 1: Constructor and getters
    {
        BankAccount acc("Alice", 100.0);
        assert(acc.getOwnerName() == "Alice");
        assert(acc.getBalance() == 100.0);
        cout << "PASS: Constructor and getters work correctly\n";
    }

    // Test 2: Deposit adds to balance
    {
        BankAccount acc("Bob", 50.0);
        acc.deposit(25.0);
        assert(acc.getBalance() == 75.0);
        acc.deposit(0.50);
        assert(acc.getBalance() == 75.50);
        cout << "PASS: Deposit adds to balance correctly\n";
    }

    // Test 3: Withdraw subtracts from balance
    {
        BankAccount acc("Carol", 100.0);
        acc.withdraw(30.0);
        assert(acc.getBalance() == 70.0);
        acc.withdraw(70.0);
        assert(acc.getBalance() == 0.0);
        cout << "PASS: Withdraw subtracts from balance correctly\n";
    }

    // Test 4: Reject negative initial balance
    {
        bool threw = false;
        try {
            BankAccount acc("Dave", -50.0);
        } catch (const invalid_argument&) {
            threw = true;
        }
        assert(threw && "Constructor should throw for negative initial balance");
        cout << "PASS: Negative initial balance rejected\n";
    }

    // Test 5: Reject non-positive deposit
    {
        BankAccount acc("Eve", 100.0);
        bool threw = false;
        try {
            acc.deposit(0);
        } catch (const invalid_argument&) {
            threw = true;
        }
        assert(threw && "Deposit of 0 should throw");

        threw = false;
        try {
            acc.deposit(-10);
        } catch (const invalid_argument&) {
            threw = true;
        }
        assert(threw && "Deposit of negative amount should throw");
        assert(acc.getBalance() == 100.0);  // Balance unchanged
        cout << "PASS: Non-positive deposits rejected\n";
    }

    // Test 6: Reject non-positive withdrawal
    {
        BankAccount acc("Frank", 100.0);
        bool threw = false;
        try {
            acc.withdraw(0);
        } catch (const invalid_argument&) {
            threw = true;
        }
        assert(threw && "Withdraw of 0 should throw");
        cout << "PASS: Non-positive withdrawal rejected\n";
    }

    // Test 7: Reject overdraft (insufficient funds)
    {
        BankAccount acc("Grace", 50.0);
        bool threw = false;
        try {
            acc.withdraw(100.0);
        } catch (const runtime_error&) {
            threw = true;
        }
        assert(threw && "Overdraft should throw runtime_error");
        assert(acc.getBalance() == 50.0);  // Balance unchanged
        cout << "PASS: Overdraft rejected with runtime_error\n";
    }

    cout << "\n=== ALL TESTS PASSED ===\n";
    return 0;
}
