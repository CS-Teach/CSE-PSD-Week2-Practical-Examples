// ============================================================
// Exercise 4: Solution — OCP Discount System
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <algorithm>
using namespace std;

class DiscountStrategy {
public:
    virtual ~DiscountStrategy() = default;
    virtual double applyDiscount(double price) const = 0;
    virtual string getName() const = 0;
};

class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double price) const override {
        return price;
    }
    string getName() const override { return "NoDiscount"; }
};

class PercentDiscount : public DiscountStrategy {
    double percentage;
public:
    PercentDiscount(double percentage) : percentage(percentage) {}

    double applyDiscount(double price) const override {
        return price * (1 - percentage / 100.0);
    }
    string getName() const override { return "PercentDiscount"; }
};

class FixedDiscount : public DiscountStrategy {
    double amount;
public:
    FixedDiscount(double amount) : amount(amount) {}

    double applyDiscount(double price) const override {
        return max(0.0, price - amount);
    }
    string getName() const override { return "FixedDiscount"; }
};

class BuyOneGetOneFree : public DiscountStrategy {
public:
    double applyDiscount(double price) const override {
        return price / 2.0;
    }
    string getName() const override { return "BuyOneGetOneFree"; }
};

class PriceCalculator {
    const DiscountStrategy& strategy;
public:
    PriceCalculator(const DiscountStrategy& strategy) : strategy(strategy) {}

    double calculateFinal(double price) const {
        return strategy.applyDiscount(price);
    }
};

#endif // EXERCISE_CPP
