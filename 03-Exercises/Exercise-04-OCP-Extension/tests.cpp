// ============================================================
// Exercise 4: Tests — OCP Discount System
// ============================================================
// Compile:  g++ -std=c++17 -o test tests.cpp && ./test
// ============================================================

#include "practice.cpp"  // Students edit practice.cpp — exercise.cpp is the clean reference
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;

bool approxEqual(double a, double b, double epsilon = 0.01) {
    return fabs(a - b) < epsilon;
}

int main() {
    // Test 1: NoDiscount returns full price
    {
        NoDiscount nd;
        assert(approxEqual(nd.applyDiscount(100.0), 100.0));
        assert(nd.getName() == "NoDiscount");
        cout << "PASS: NoDiscount returns full price\n";
    }

    // Test 2: PercentDiscount applies percentage
    {
        PercentDiscount pd(10.0);  // 10% off
        assert(approxEqual(pd.applyDiscount(100.0), 90.0));
        assert(approxEqual(pd.applyDiscount(50.0), 45.0));
        assert(pd.getName() == "PercentDiscount");
        cout << "PASS: PercentDiscount applies percentage correctly\n";
    }

    // Test 3: PercentDiscount with different percentages
    {
        PercentDiscount half(50.0);
        assert(approxEqual(half.applyDiscount(80.0), 40.0));

        PercentDiscount full(100.0);
        assert(approxEqual(full.applyDiscount(80.0), 0.0));
        cout << "PASS: PercentDiscount works with various percentages\n";
    }

    // Test 4: FixedDiscount subtracts fixed amount
    {
        FixedDiscount fd(15.0);  // $15 off
        assert(approxEqual(fd.applyDiscount(100.0), 85.0));
        assert(approxEqual(fd.applyDiscount(50.0), 35.0));
        assert(fd.getName() == "FixedDiscount");
        cout << "PASS: FixedDiscount subtracts correctly\n";
    }

    // Test 5: FixedDiscount doesn't go below zero
    {
        FixedDiscount fd(50.0);
        assert(approxEqual(fd.applyDiscount(30.0), 0.0));  // 30 - 50 = clamped to 0
        assert(approxEqual(fd.applyDiscount(50.0), 0.0));
        cout << "PASS: FixedDiscount clamps to zero\n";
    }

    // Test 6: BuyOneGetOneFree halves price
    {
        BuyOneGetOneFree bogof;
        assert(approxEqual(bogof.applyDiscount(100.0), 50.0));
        assert(approxEqual(bogof.applyDiscount(37.0), 18.5));
        assert(bogof.getName() == "BuyOneGetOneFree");
        cout << "PASS: BuyOneGetOneFree halves price\n";
    }

    // Test 7: PriceCalculator delegates to strategy
    {
        PercentDiscount pd(20.0);
        PriceCalculator calc(pd);
        assert(approxEqual(calc.calculateFinal(100.0), 80.0));
        assert(approxEqual(calc.calculateFinal(50.0), 40.0));
        cout << "PASS: PriceCalculator delegates to strategy\n";
    }

    // Test 8: PriceCalculator with different strategies
    {
        NoDiscount nd;
        PriceCalculator calc1(nd);
        assert(approxEqual(calc1.calculateFinal(100.0), 100.0));

        FixedDiscount fd(10.0);
        PriceCalculator calc2(fd);
        assert(approxEqual(calc2.calculateFinal(100.0), 90.0));
        cout << "PASS: PriceCalculator works with multiple strategies\n";
    }

    cout << "\n=== ALL TESTS PASSED ===\n";
    return 0;
}
