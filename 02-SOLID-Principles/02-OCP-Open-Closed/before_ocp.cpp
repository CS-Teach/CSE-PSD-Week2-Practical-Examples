// ============================================================
// BEFORE Open/Closed Principle (OCP)
// ============================================================
// Problem:  To add a new assessment type, we must EDIT the
//           existing calculateWeightedScore() method.
//           The class is NOT closed for modification.
//
// Observe:
//   - Adding "project" means modifying the if/else chain
//   - Every modification risks breaking existing types
//   - The class must be recompiled and retested entirely
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class GradeCalculator {
public:
    // This method must be EDITED every time we add a type
    static double calculateWeightedScore(double average, const string& type) {
        if (type == "exam") {
            return average * 1.0;
        } else if (type == "assignment") {
            return average * 0.8;
        } else if (type == "practical") {
            return average * 0.9;
        }
        // Want to add "project"?  Must edit HERE.
        // Want to add "portfolio"? Must edit HERE again.
        // Each edit risks breaking existing calculations.
        return average;
    }

    static string getLetterGrade(double score) {
        if      (score >= 90) return "A";
        else if (score >= 80) return "B";
        else if (score >= 70) return "C";
        else                  return "F";
    }
};

int main() {
    cout << "=== Before OCP ===\n\n";

    double examScore = GradeCalculator::calculateWeightedScore(85.0, "exam");
    cout << "Exam:       " << examScore
         << " (" << GradeCalculator::getLetterGrade(examScore) << ")\n";

    double assignScore = GradeCalculator::calculateWeightedScore(85.0, "assignment");
    cout << "Assignment: " << assignScore
         << " (" << GradeCalculator::getLetterGrade(assignScore) << ")\n";

    double practScore = GradeCalculator::calculateWeightedScore(85.0, "practical");
    cout << "Practical:  " << practScore
         << " (" << GradeCalculator::getLetterGrade(practScore) << ")\n";

    // To add "project" weighing 70%, we must modify
    // GradeCalculator::calculateWeightedScore() — violating OCP!

    return 0;
}
