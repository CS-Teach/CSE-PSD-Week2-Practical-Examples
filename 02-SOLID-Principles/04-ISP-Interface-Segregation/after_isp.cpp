// ============================================================
// AFTER Interface Segregation Principle (ISP)
// ============================================================
// Solution: Split the fat interface into small, role-specific
//           interfaces. Each class only implements the
//           interfaces relevant to its role.
//
// Key ideas:
//   - IStudentActions: enrol, submit, view grades
//   - ILecturerActions: manage course, grade students
//   - IAdminActions: manage enrolments
//   - Each user class implements ONLY what it needs
//   - No dummy implementations, no runtime exceptions
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// --- Small, focused interfaces ---

class IStudentActions {
public:
    virtual ~IStudentActions() = default;
    virtual void enrolInSubject(const string& subject) = 0;
    virtual void submitAssignment(const string& assignment) = 0;
    virtual void viewGrades() = 0;
};

class ILecturerActions {
public:
    virtual ~ILecturerActions() = default;
    virtual void manageCourse(const string& course) = 0;
    virtual void gradeStudent(const string& student, int grade) = 0;
    virtual void viewGrades() = 0;
};

class IAdminActions {
public:
    virtual ~IAdminActions() = default;
    virtual void manageEnrolments() = 0;
    virtual void viewGrades() = 0;
};

// --- Student only implements student operations ---
class StudentUser : public IStudentActions {
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
    // No manageCourse()! No gradeStudent()! Clean!
};

// --- Lecturer only implements lecturer operations ---
class LecturerUser : public ILecturerActions {
    string name;
public:
    LecturerUser(const string& n) : name(n) {}

    void manageCourse(const string& course) override {
        cout << name << " managing " << course << "\n";
    }
    void gradeStudent(const string& student, int grade) override {
        cout << name << " gave " << student << " a grade of " << grade << "\n";
    }
    void viewGrades() override {
        cout << name << " viewing all student grades\n";
    }
    // No enrolInSubject()! No submitAssignment()! Clean!
};

// --- Admin can inherit multiple interfaces if needed ---
class AdminUser : public IAdminActions {
    string name;
public:
    AdminUser(const string& n) : name(n) {}

    void manageEnrolments() override {
        cout << name << " managing enrolments\n";
    }
    void viewGrades() override {
        cout << name << " viewing system-wide grades\n";
    }
};

int main() {
    cout << "=== After ISP ===\n\n";

    StudentUser student("Alex");
    student.enrolInSubject("CSE1PSD");
    student.submitAssignment("Week 2 Practical");
    student.viewGrades();

    cout << "\n";

    LecturerUser lecturer("Dr. Smith");
    lecturer.manageCourse("CSE1PSD");
    lecturer.gradeStudent("Alex", 85);
    lecturer.viewGrades();

    cout << "\n";

    AdminUser admin("Pat");
    admin.manageEnrolments();
    admin.viewGrades();

    // No runtime errors! Each class only has methods it can use.
    // student.manageCourse("X");  // Won't compile — not available!
    // lecturer.enrolInSubject("X"); // Won't compile — not available!

    cout << "\nNo dummy methods. No runtime exceptions.\n";
    cout << "Each role only sees the operations it needs.\n";

    return 0;
}
