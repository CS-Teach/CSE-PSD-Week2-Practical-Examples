// ============================================================
// PRACTICE FILE — Edit this file freely!
// ============================================================
// This is your working copy of before_srp.cpp.
// Experiment, refactor, and improve this code.
// If you need a fresh start, copy the contents of before_srp.cpp back.
// Compare your work with after_srp.cpp when done.
// ============================================================

// ============================================================
// BEFORE Single Responsibility Principle (SRP)
// ============================================================
// Problem:  The Student class has MULTIPLE responsibilities:
//           - Storing student data
//           - Calculating grades
//           - Formatting/printing reports
//           - Saving to files
//
//           If ANY of these change (new grading scheme, new
//           report format, different file format), we must
//           edit this one class — risky and messy.
// ============================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int grade1, grade2, grade3;
    string assessmentType;   // "exam", "assignment", or "practical"

    Student(string n, int g1, int g2, int g3, string type)
        : name(n), grade1(g1), grade2(g2), grade3(g3), assessmentType(type) {}

    // Responsibility 1: Grade calculation
    double calculateAverage() {
        return (grade1 + grade2 + grade3) / 3.0;
    }

    // Responsibility 2: Weighted score logic
    double calculateWeightedScore() {
        double avg = calculateAverage();
        if (assessmentType == "exam") {
            return avg * 1.0;
        } else if (assessmentType == "assignment") {
            return avg * 0.8;
        } else if (assessmentType == "practical") {
            return avg * 0.9;
        }
        return avg;
    }

    // Responsibility 3: Letter grade determination
    string getLetterGrade() {
        double score = calculateWeightedScore();
        if      (score >= 90) return "A";
        else if (score >= 80) return "B";
        else if (score >= 70) return "C";
        else                  return "F";
    }

    // Responsibility 4: Console output formatting
    void printReport() {
        cout << "====== Student Report ======\n";
        cout << "Name:         " << name << "\n";
        cout << "Assessment:   " << assessmentType << "\n";
        cout << "Average:      " << calculateAverage() << "\n";
        cout << "Weighted:     " << calculateWeightedScore() << "\n";
        cout << "Letter Grade: " << getLetterGrade() << "\n";
        cout << "============================\n";
    }

    // Responsibility 5: File I/O
    void saveToFile(const string& filename) {
        ofstream file(filename);
        file << name << "," << assessmentType << ","
             << calculateWeightedScore() << "," << getLetterGrade() << "\n";
        file.close();
    }
};

int main() {
    cout << "=== Before SRP ===\n\n";

    Student s1("Alex",   78, 85, 92, "exam");
    Student s2("Jordan", 70, 75, 80, "assignment");

    s1.printReport();
    cout << "\n";
    s2.printReport();

    // s1.saveToFile("alex.txt");  // Also does file I/O!

    // Problem: Want to change the report format?
    //          You're editing the same class that holds data
    //          and calculates grades. Risk of breaking everything.

    return 0;
}
