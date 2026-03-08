// ============================================================
// BEFORE Abstraction
// ============================================================
// Problem:  Each transport type has its own standalone function.
//           The caller must know which function to call and
//           understand each type's internal details.
//
// Observe:
//   - No common interface — each transport is handled separately
//   - Caller must manage type-specific logic
//   - Adding a new transport means adding another function
//     and updating every call site
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// --- Separate functions for each transport type ---

double calculateBusFare(int zones) {
    // Bus: $2.50 base + $1.20 per zone
    return 2.50 + zones * 1.20;
}

double calculateTrainFare(int zones, bool isPeakHour) {
    // Train: $3.00 base + $1.80 per zone, 25% surcharge at peak
    double fare = 3.00 + zones * 1.80;
    if (isPeakHour) fare *= 1.25;
    return fare;
}

double calculateFerryFare(int zones) {
    // Ferry: $5.00 base + $2.50 per zone
    return 5.00 + zones * 2.50;
}

// Caller must know which function to use and what parameters each needs
void printFare(const string& type, int zones, bool isPeak) {
    double fare = 0;

    // Must handle each type individually
    if (type == "bus") {
        fare = calculateBusFare(zones);
    } else if (type == "train") {
        fare = calculateTrainFare(zones, isPeak);
    } else if (type == "ferry") {
        fare = calculateFerryFare(zones);
    } else {
        cout << "Unknown transport type: " << type << "\n";
        return;
    }

    cout << type << " (" << zones << " zones): $" << fare << "\n";
}

int main() {
    cout << "=== Before Abstraction ===\n\n";

    printFare("bus",   2, false);
    printFare("train", 3, true);
    printFare("ferry", 1, false);

    // What if we want to add "tram"?
    // We'd need: a new calculateTramFare() function
    //            AND update the if/else chain in printFare()
    //            AND update every other place that handles types

    return 0;
}
