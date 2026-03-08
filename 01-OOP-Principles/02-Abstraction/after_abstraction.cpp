// ============================================================
// AFTER Abstraction
// ============================================================
// Solution: Define an abstract base class (Transport) that
//           hides internal details behind a common interface.
//           Callers only interact with the abstraction — they
//           don't need to know how each transport works inside.
//
// Key ideas:
//   - Abstract class with pure virtual function (= 0)
//   - Each transport implements calculateFare() its own way
//   - Callers use Transport* — no type-specific code needed
//   - Adding a new transport = just add a new subclass
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// --- Abstract base class: defines the interface ---
class Transport {
public:
    virtual ~Transport() = default;

    // Pure virtual: every subclass MUST implement this
    virtual double calculateFare() const = 0;

    // Common interface for display
    virtual string getName() const = 0;

    // Concrete method using the abstraction
    void printFare() const {
        cout << getName() << ": $" << calculateFare() << "\n";
    }
};

// --- Each transport hides its own fare logic ---

class Bus : public Transport {
    int zones;
public:
    Bus(int zones) : zones(zones) {}
    string getName() const override { return "Bus (" + to_string(zones) + " zones)"; }
    double calculateFare() const override {
        return 2.50 + zones * 1.20;  // Internal detail — caller doesn't know this
    }
};

class Train : public Transport {
    int zones;
    bool isPeakHour;
public:
    Train(int zones, bool isPeakHour)
        : zones(zones), isPeakHour(isPeakHour) {}
    string getName() const override { return "Train (" + to_string(zones) + " zones)"; }
    double calculateFare() const override {
        double fare = 3.00 + zones * 1.80;
        if (isPeakHour) fare *= 1.25;  // Peak logic hidden inside
        return fare;
    }
};

class Ferry : public Transport {
    int zones;
public:
    Ferry(int zones) : zones(zones) {}
    string getName() const override { return "Ferry (" + to_string(zones) + " zones)"; }
    double calculateFare() const override {
        return 5.00 + zones * 2.50;
    }
};

int main() {
    cout << "=== After Abstraction ===\n\n";

    // Create different transports — all treated uniformly
    vector<unique_ptr<Transport>> transports;
    transports.push_back(make_unique<Bus>(2));
    transports.push_back(make_unique<Train>(3, true));
    transports.push_back(make_unique<Ferry>(1));

    // The caller doesn't need to know how fares are calculated!
    // It just calls printFare() on the abstract interface.
    for (const auto& t : transports) {
        t->printFare();
    }

    // Adding a new transport (e.g. Tram) means:
    //   1. Create a new Tram class inheriting Transport
    //   2. Implement calculateFare() and getName()
    //   3. Done! No changes to existing code.

    return 0;
}
