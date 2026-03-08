// ============================================================
// AFTER Polymorphism
// ============================================================
// Solution: Each transport type IS its own class with virtual
//           functions. The runtime picks the right method
//           automatically — no if/else chains needed.
//
// Key ideas:
//   - Virtual functions enable runtime dispatch
//   - Each subclass defines its OWN behaviour
//   - Calling code uses base class pointers — type-agnostic
//   - Adding a new transport = add a class, no existing code changes
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// --- Base class with virtual functions ---
class Transport {
protected:
    int zones;
public:
    Transport(int zones) : zones(zones) {}
    virtual ~Transport() = default;

    // Each subclass overrides these — runtime dispatch!
    virtual double calculateFare() const = 0;
    virtual string getDescription() const = 0;
    virtual int maxCapacity() const = 0;

    // Common display logic — works for ANY transport
    void printSummary() const {
        cout << getDescription()
             << " | Fare: $" << calculateFare()
             << " | Capacity: " << maxCapacity()
             << "\n";
    }
};

class Bus : public Transport {
public:
    Bus(int zones) : Transport(zones) {}

    double calculateFare() const override {
        return 2.50 + zones * 1.20;
    }
    string getDescription() const override {
        return "City Bus";
    }
    int maxCapacity() const override {
        return 60;
    }
};

class Train : public Transport {
    bool isPeak;
public:
    Train(int zones, bool isPeak)
        : Transport(zones), isPeak(isPeak) {}

    double calculateFare() const override {
        double fare = 3.00 + zones * 1.80;
        if (isPeak) fare *= 1.25;
        return fare;
    }
    string getDescription() const override {
        return isPeak ? "Peak Train" : "Off-Peak Train";
    }
    int maxCapacity() const override {
        return 800;
    }
};

class Ferry : public Transport {
public:
    Ferry(int zones) : Transport(zones) {}

    double calculateFare() const override {
        return 5.00 + zones * 2.50;
    }
    string getDescription() const override {
        return "Harbour Ferry";
    }
    int maxCapacity() const override {
        return 400;
    }
};

int main() {
    cout << "=== After Polymorphism ===\n\n";

    // All stored as Transport* — polymorphism in action!
    vector<unique_ptr<Transport>> trips;
    trips.push_back(make_unique<Bus>(2));
    trips.push_back(make_unique<Train>(3, true));
    trips.push_back(make_unique<Ferry>(1));

    // Same loop, same code — runtime picks the right method
    for (const auto& trip : trips) {
        trip->printSummary();
    }

    // Adding Tram? Just define a Tram class.
    // This loop and printSummary() work unchanged!

    return 0;
}
