// ============================================================
// Exercise 4: OCP Extension — Discount System
// ============================================================
// The existing discount system works but violates OCP.
// Currently it uses an if/else chain for discount types.
//
// Your task: Refactor using polymorphism so new discount types
//            can be ADDED without modifying existing code.
//
// Step 1: Create an abstract DiscountStrategy base class
//   - Pure virtual: double applyDiscount(double price) const
//   - Pure virtual: string getName() const
//
// Step 2: Implement these concrete strategies:
//   - NoDiscount:       returns price unchanged
//   - PercentDiscount:  constructor takes percentage (e.g. 10.0 for 10%)
//                       returns price * (1 - percentage/100)
//   - FixedDiscount:    constructor takes fixed amount (e.g. 5.0)
//                       returns price - amount (minimum 0.0)
//   - BuyOneGetOneFree: returns price / 2.0
//
// Step 3: Implement PriceCalculator class:
//   - Constructor takes a DiscountStrategy reference
//   - double calculateFinal(double price) const
//     (delegates to the strategy's applyDiscount)
//
// Compile & test:
//   g++ -std=c++17 -o test tests.cpp && ./test
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <algorithm>
using namespace std;

// --- ORIGINAL VIOLATING CODE (for reference) ---
// class OldPriceCalculator {
// public:
//     double calculateFinal(double price, const string& discountType, double param) {
//         if (discountType == "none")       return price;
//         if (discountType == "percent")    return price * (1 - param / 100);
//         if (discountType == "fixed")      return max(0.0, price - param);
//         if (discountType == "bogof")      return price / 2.0;
//         return price;  // Adding new type? Edit here — OCP violation!
//     }
// };

// TODO: Implement DiscountStrategy abstract base class

// TODO: Implement NoDiscount

// TODO: Implement PercentDiscount

// TODO: Implement FixedDiscount

// TODO: Implement BuyOneGetOneFree

// TODO: Implement PriceCalculator

#endif // EXERCISE_CPP
