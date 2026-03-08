// ============================================================
// AFTER Open/Closed Principle (OCP)
// ============================================================
// Solution: Use polymorphism so new assessment types can be
//           ADDED without modifying existing code.
//           Open for extension, closed for modification.
//
// Key ideas:
//   - AssessmentStrategy is an abstract base class
//   - Each type (Exam, Assignment, etc.) is a subclass
//   - Adding "Project" = new class, NO edits to existing code
//   - GradeCalculator works with ANY strategy via the base class
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// --- Abstract strategy: open for extension ---
class AssessmentStrategy {
public:
    virtual ~AssessmentStrategy() = default;
    virtual double applyWeight(double average) const = 0;
    virtual string getName() const = 0;
};

// --- Existing types: closed for modification ---
class ExamStrategy : public AssessmentStrategy {
public:
    double applyWeight(double average) const override { return average * 1.0; }
    string getName() const override { return "Exam"; }
};

class AssignmentStrategy : public AssessmentStrategy {
public:
    double applyWeight(double average) const override { return average * 0.8; }
    string getName() const override { return "Assignment"; }
};

class PracticalStrategy : public AssessmentStrategy {
public:
    double applyWeight(double average) const override { return average * 0.9; }
    string getName() const override { return "Practical"; }
};

// --- NEW type: added WITHOUT editing any existing class! ---
class ProjectStrategy : public AssessmentStrategy {
public:
    double applyWeight(double average) const override { return average * 0.7; }
    string getName() const override { return "Project"; }
};

// --- GradeCalculator works with ANY strategy ---
class GradeCalculator {
public:
    static string getLetterGrade(double score) {
        if      (score >= 90) return "A";
        else if (score >= 80) return "B";
        else if (score >= 70) return "C";
        else                  return "F";
    }

    static void printResult(const AssessmentStrategy& strategy, double average) {
        double score = strategy.applyWeight(average);
        cout << strategy.getName() << ": "
             << score << " (" << getLetterGrade(score) << ")\n";
    }
};

int main() {
    cout << "=== After OCP ===\n\n";

    double average = 85.0;

    // All strategies work through the same interface
    vector<unique_ptr<AssessmentStrategy>> strategies;
    strategies.push_back(make_unique<ExamStrategy>());
    strategies.push_back(make_unique<AssignmentStrategy>());
    strategies.push_back(make_unique<PracticalStrategy>());
    strategies.push_back(make_unique<ProjectStrategy>());  // New! No edits needed!

    for (const auto& strategy : strategies) {
        GradeCalculator::printResult(*strategy, average);
    }

    // Adding "Portfolio" weighing 60%?
    // Just create PortfolioStrategy — nothing else changes!

    return 0;
}
