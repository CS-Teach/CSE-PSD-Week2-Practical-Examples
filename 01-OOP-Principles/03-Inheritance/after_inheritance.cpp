// ============================================================
// AFTER Inheritance
// ============================================================
// Solution: Common fields and behaviour live in a base class
//           (Transport). Each subclass (Bus, Train, Ferry)
//           inherits the shared code and only defines what's
//           unique to it.
//
// Key ideas:
//   - Base class holds shared data (name, zones, tappedOn)
//   - tapOn() is identical for all — defined once in base
//   - calculateFare() differs per type — virtual, overridden
//   - Adding a new transport = one small new subclass
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// --- Base class: shared fields and behaviour ---
class Transport {
protected:
    string name;
    int zones;
    bool tappedOn = false;

public:
    Transport(const string& name, int zones)
        : name(name), zones(zones) {}

    virtual ~Transport() = default;

    // Shared behaviour — defined once, inherited by all
    void tapOn() {
        tappedOn = true;
        cout << "[" << name << "] Tapped on for " << zones << " zone(s)\n";
    }

    // Each subclass provides its own fare calculation
    virtual double calculateFare() const = 0;

    void tapOff() {
        tappedOn = false;
        cout << "[" << name << "] Tapped off. Fare: $" << calculateFare() << "\n";
    }
};

// --- Subclasses: only define what's different ---

class Bus : public Transport {
public:
    Bus(int zones) : Transport("Bus", zones) {}

    double calculateFare() const override {
        return 2.50 + zones * 1.20;
    }
};

class Train : public Transport {
    bool isPeak;
public:
    Train(int zones, bool isPeak)
        : Transport("Train", zones), isPeak(isPeak) {}

    double calculateFare() const override {
        double fare = 3.00 + zones * 1.80;
        if (isPeak) fare *= 1.25;
        return fare;
    }
};

class Ferry : public Transport {
public:
    Ferry(int zones) : Transport("Ferry", zones) {}

    double calculateFare() const override {
        return 5.00 + zones * 2.50;
    }
};

int main() {
    cout << "=== After Inheritance ===\n\n";

    // All types share the same base interface
    vector<unique_ptr<Transport>> trips;
    trips.push_back(make_unique<Bus>(2));
    trips.push_back(make_unique<Train>(3, true));
    trips.push_back(make_unique<Ferry>(1));

    for (auto& trip : trips) {
        trip->tapOn();
        trip->tapOff();
        cout << "\n";
    }

    // Adding Tram? Just:
    //   class Tram : public Transport { ... };
    // No duplication needed!

    return 0;
}
