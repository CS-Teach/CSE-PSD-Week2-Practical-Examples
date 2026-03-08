// ============================================================
// BEFORE Polymorphism
// ============================================================
// Problem:  A string "type" field is used to decide behaviour
//           at runtime via if/else chains. Every function that
//           acts differently per type must repeat this chain.
//
// Observe:
//   - The "type" string acts as a manual type tag
//   - Every function has an if/else checking the type
//   - Adding a new type means updating EVERY if/else chain
//   - Easy to forget one, causing silent bugs
// ============================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct OpalTrip {
    string type;   // "bus", "train", or "ferry"
    int zones;
    bool isPeak;

    OpalTrip(const string& type, int zones, bool isPeak = false)
        : type(type), zones(zones), isPeak(isPeak) {}
};

// --- Every function must check the type string ---

double calculateFare(const OpalTrip& trip) {
    if (trip.type == "bus") {
        return 2.50 + trip.zones * 1.20;
    } else if (trip.type == "train") {
        double fare = 3.00 + trip.zones * 1.80;
        if (trip.isPeak) fare *= 1.25;
        return fare;
    } else if (trip.type == "ferry") {
        return 5.00 + trip.zones * 2.50;
    }
    // Forgot to handle "tram"? Silent bug — returns 0!
    return 0;
}

string getDescription(const OpalTrip& trip) {
    // Another if/else chain — duplicated type checking
    if (trip.type == "bus") {
        return "City Bus";
    } else if (trip.type == "train") {
        return trip.isPeak ? "Peak Train" : "Off-Peak Train";
    } else if (trip.type == "ferry") {
        return "Harbour Ferry";
    }
    return "Unknown";
}

int maxCapacity(const OpalTrip& trip) {
    // Yet another if/else chain!
    if (trip.type == "bus")   return 60;
    if (trip.type == "train") return 800;
    if (trip.type == "ferry") return 400;
    return 0;
}

int main() {
    cout << "=== Before Polymorphism ===\n\n";

    vector<OpalTrip> trips = {
        {"bus",   2, false},
        {"train", 3, true},
        {"ferry", 1, false}
    };

    for (const auto& trip : trips) {
        cout << getDescription(trip)
             << " | Fare: $" << calculateFare(trip)
             << " | Capacity: " << maxCapacity(trip)
             << "\n";
    }

    // Adding "tram" means updating calculateFare(), getDescription(),
    // maxCapacity(), and every other function that checks type.

    return 0;
}
