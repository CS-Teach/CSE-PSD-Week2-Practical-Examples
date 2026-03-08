// ============================================================
// BEFORE Inheritance
// ============================================================
// Problem:  Each transport type is a separate struct with
//           duplicated fields and logic. Changes to shared
//           behaviour must be copied to every type.
//
// Observe:
//   - name, zones appear in every struct (code duplication)
//   - tapOn/tapOff logic is repeated per type
//   - If we add a field (e.g. maxCapacity), we update everywhere
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// --- Three separate structs with duplicated fields ---

struct BusTrip {
    string name = "Bus";
    int zones;
    bool tappedOn = false;

    BusTrip(int z) : zones(z) {}

    void tapOn() {
        tappedOn = true;
        cout << "[Bus] Tapped on for " << zones << " zone(s)\n";
    }

    void tapOff() {
        tappedOn = false;
        double fare = 2.50 + zones * 1.20;
        cout << "[Bus] Tapped off. Fare: $" << fare << "\n";
    }
};

struct TrainTrip {
    string name = "Train";
    int zones;
    bool isPeak;
    bool tappedOn = false;

    TrainTrip(int z, bool peak) : zones(z), isPeak(peak) {}

    void tapOn() {  // Same logic as Bus — duplicated!
        tappedOn = true;
        cout << "[Train] Tapped on for " << zones << " zone(s)\n";
    }

    void tapOff() {
        tappedOn = false;
        double fare = 3.00 + zones * 1.80;
        if (isPeak) fare *= 1.25;
        cout << "[Train] Tapped off. Fare: $" << fare << "\n";
    }
};

struct FerryTrip {
    string name = "Ferry";
    int zones;
    bool tappedOn = false;

    FerryTrip(int z) : zones(z) {}

    void tapOn() {  // Same again — duplicated!
        tappedOn = true;
        cout << "[Ferry] Tapped on for " << zones << " zone(s)\n";
    }

    void tapOff() {
        tappedOn = false;
        double fare = 5.00 + zones * 2.50;
        cout << "[Ferry] Tapped off. Fare: $" << fare << "\n";
    }
};

int main() {
    cout << "=== Before Inheritance ===\n\n";

    BusTrip bus(2);
    bus.tapOn();
    bus.tapOff();

    cout << "\n";

    TrainTrip train(3, true);
    train.tapOn();
    train.tapOff();

    cout << "\n";

    FerryTrip ferry(1);
    ferry.tapOn();
    ferry.tapOff();

    // If we want to add a "Tram" transport, we copy-paste
    // another struct — more duplication!

    return 0;
}
