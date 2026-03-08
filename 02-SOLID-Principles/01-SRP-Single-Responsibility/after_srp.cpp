// ============================================================
// AFTER Single Responsibility Principle (SRP)
// ============================================================
// Solution: Each class has ONE reason to change.
//   - Student:         stores data only
//   - GradeCalculator: handles grade logic only
//   - ReportPrinter:   handles display formatting only
//
// If grading rules change → edit GradeCalculator (Student untouched)
// If report format changes → edit ReportPrinter (Student untouched)
// ============================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --- Responsibility 1: Data storage only ---
class Student {
    string name;
    vector<int> grades;
    string assessmentType;

public:
    Student(const string& name, const vector<int>& grades, const string& type)
        : name(name), grades(grades), assessmentType(type) {}

    string getName() const { return name; }
    string getAssessmentType() const { return assessmentType; }
    const vector<int>& getGrades() const { return grades; }
};

// --- Responsibility 2: Grade calculation only ---
class GradeCalculator {
public:
    static double calculateAverage(const Student& s) {
        const auto& grades = s.getGrades();
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }

    static double calculateWeightedScore(const Student& s) {
        double avg = calculateAverage(s);
        string type = s.getAssessmentType();

        if      (type == "exam")        return avg * 1.0;
        else if (type == "assignment")  return avg * 0.8;
        else if (type == "practical")   return avg * 0.9;
        return avg;
    }

    static string getLetterGrade(const Student& s) {
        double score = calculateWeightedScore(s);
        if      (score >= 90) return "A";
        else if (score >= 80) return "B";
        else if (score >= 70) return "C";
        else                  return "F";
    }
};

// --- Responsibility 3: Report formatting only ---
class ReportPrinter {
public:
    static void printReport(const Student& s) {
        cout << "====== Student Report ======\n";
        cout << "Name:         " << s.getName() << "\n";
        cout << "Assessment:   " << s.getAssessmentType() << "\n";
        cout << "Average:      " << GradeCalculator::calculateAverage(s) << "\n";
        cout << "Weighted:     " << GradeCalculator::calculateWeightedScore(s) << "\n";
        cout << "Letter Grade: " << GradeCalculator::getLetterGrade(s) << "\n";
        cout << "============================\n";
    }
};

int main() {
    cout << "=== After SRP ===\n\n";

    Student s1("Alex",   {78, 85, 92}, "exam");
    Student s2("Jordan", {70, 75, 80}, "assignment");

    // Each class does ONE thing — clear separation
    ReportPrinter::printReport(s1);
    cout << "\n";
    ReportPrinter::printReport(s2);

    // Want a different report format? Change ReportPrinter only.
    // Want different grading rules? Change GradeCalculator only.
    // Student class stays untouched in both cases!

    return 0;
}
