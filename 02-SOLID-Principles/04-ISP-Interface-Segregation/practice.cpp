// ============================================================
// PRACTICE FILE — Edit this file freely!
// ============================================================
// This is your working copy of before_isp.cpp.
// Experiment, refactor, and improve this code.
// If you need a fresh start, copy the contents of before_isp.cpp back.
// Compare your work with after_isp.cpp when done.
// ============================================================

// ============================================================
// BEFORE Interface Segregation Principle (ISP)
// ============================================================
// Problem:  A single "fat" interface forces ALL users to
//           implement methods they don't need.
//           Students shouldn't manage courses.
//           Lecturers shouldn't enrol in subjects.
//
// Observe:
//   - IUniversitySystem has methods for every role
//   - StudentUser must implement manageCourse() — makes no sense
//   - LecturerUser must implement enrolInSubject() — also nonsense
//   - Both throw exceptions for unsupported operations
// ============================================================

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// --- Fat interface: every role must implement everything ---
class IUniversitySystem {
public:
    virtual ~IUniversitySystem() = default;

    // Student operations
    virtual void enrolInSubject(const string& subject) = 0;
    virtual void submitAssignment(const string& assignment) = 0;
    virtual void viewGrades() = 0;

    // Lecturer operations
    virtual void manageCourse(const string& course) = 0;
    virtual void gradeStudent(const string& student, int grade) = 0;

    // Admin operations
    virtual void manageEnrolments() = 0;
};

// Student is FORCED to implement lecturer/admin methods
class StudentUser : public IUniversitySystem {
    string name;
public:
    StudentUser(const string& n) : name(n) {}

    void enrolInSubject(const string& subject) override {
        cout << name << " enrolled in " << subject << "\n";
    }
    void submitAssignment(const string& assignment) override {
        cout << name << " submitted " << assignment << "\n";
    }
    void viewGrades() override {
        cout << name << " viewing grades\n";
    }

    // Forced to implement — but students can't do these!
    void manageCourse(const string&) override {
        throw runtime_error("Students cannot manage courses!");
    }
    void gradeStudent(const string&, int) override {
        throw runtime_error("Students cannot grade!");
    }
    void manageEnrolments() override {
        throw runtime_error("Students cannot manage enrolments!");
    }
};

// Lecturer is FORCED to implement student/admin methods
class LecturerUser : public IUniversitySystem {
    string name;
public:
    LecturerUser(const string& n) : name(n) {}

    // Forced to implement — but lecturers don't enrol!
    void enrolInSubject(const string&) override {
        throw runtime_error("Lecturers don't enrol in subjects!");
    }
    void submitAssignment(const string&) override {
        throw runtime_error("Lecturers don't submit assignments!");
    }
    void viewGrades() override {
        cout << name << " viewing all student grades\n";
    }

    void manageCourse(const string& course) override {
        cout << name << " managing " << course << "\n";
    }
    void gradeStudent(const string& student, int grade) override {
        cout << name << " gave " << student << " a grade of " << grade << "\n";
    }
    void manageEnrolments() override {
        throw runtime_error("Lecturers cannot manage enrolments!");
    }
};

int main() {
    cout << "=== Before ISP ===\n\n";

    StudentUser student("Alex");
    student.enrolInSubject("CSE1PSD");
    student.submitAssignment("Week 2 Practical");
    student.viewGrades();

    cout << "\n";

    LecturerUser lecturer("Dr. Smith");
    lecturer.manageCourse("CSE1PSD");
    lecturer.gradeStudent("Alex", 85);

    // These will throw — forced to implement but can't use
    cout << "\nTrying invalid operations:\n";
    try { student.manageCourse("CSE1PSD"); }
    catch (const exception& e) { cout << "  ERROR: " << e.what() << "\n"; }

    try { lecturer.enrolInSubject("CSE1PSD"); }
    catch (const exception& e) { cout << "  ERROR: " << e.what() << "\n"; }

    return 0;
}
