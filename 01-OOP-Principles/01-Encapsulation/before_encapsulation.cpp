// ============================================================
// BEFORE Encapsulation
// ============================================================
// Problem:  All data is global and publicly accessible.
//           Any part of the program can change student data
//           without validation — leading to bugs and chaos.
//
// Observe:
//   - Global variables with no protection
//   - Nothing prevents invalid data (e.g. negative grades)
//   - Functions operate on globals — tightly coupled
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// --- Global variables: anyone can read or modify these ---
string studentName = "Alex";
int grade1 = 78;
int grade2 = 85;
int grade3 = 92;

void printStudent() {
    cout << "Student: " << studentName << "\n";
}

double calculateAverage() {
    return (grade1 + grade2 + grade3) / 3.0;
}

string getLetterGrade(double avg) {
    if      (avg >= 90) return "A";
    else if (avg >= 80) return "B";
    else if (avg >= 70) return "C";
    else                return "F";
}

void printReport() {
    double avg = calculateAverage();
    cout << "Student: " << studentName << "\n";
    cout << "Average: " << avg << "\n";
    cout << "Letter Grade: " << getLetterGrade(avg) << "\n";
}

int main() {
    cout << "=== Before Encapsulation ===\n\n";

    printReport();

    // Problem: Anyone can corrupt the data directly!
    cout << "\n--- Corrupting data directly ---\n";
    grade1 = -500;                     // No validation!
    studentName = "";                  // Empty name — no guard!

    printReport();  // Prints garbage — no way to prevent this

    return 0;
}
