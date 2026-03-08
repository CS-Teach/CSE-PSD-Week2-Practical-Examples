// ============================================================
// PRACTICE FILE — Edit this file freely!
// ============================================================
// This is your working copy of before_dip.cpp.
// Experiment, refactor, and improve this code.
// If you need a fresh start, copy the contents of before_dip.cpp back.
// Compare your work with after_dip.cpp when done.
// ============================================================

// ============================================================
// BEFORE Dependency Inversion Principle (DIP)
// ============================================================
// Problem:  GradeReporter directly creates and uses EmailSender.
//           High-level policy (reporting) depends on low-level
//           detail (email). Can't switch to SMS or Slack
//           without modifying GradeReporter.
//
// The rule: High-level modules should not depend on low-level
//           modules. Both should depend on abstractions.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// --- Low-level module: specific notification mechanism ---
class EmailSender {
public:
    void sendEmail(const string& to, const string& subject, const string& body) {
        cout << "[EMAIL] To: " << to << "\n"
             << "  Subject: " << subject << "\n"
             << "  Body: " << body << "\n";
    }
};

// --- High-level module: DIRECTLY depends on EmailSender ---
class GradeReporter {
    EmailSender emailSender;   // Hardcoded dependency!

public:
    void reportGrade(const string& studentEmail, const string& studentName,
                     const string& subject, double grade) {
        string body = studentName + " received " + to_string(grade)
                    + " in " + subject;

        // Locked to email — can't use SMS, Slack, etc.
        emailSender.sendEmail(studentEmail, "Grade Report: " + subject, body);
    }
};

int main() {
    cout << "=== Before DIP ===\n\n";

    GradeReporter reporter;
    reporter.reportGrade("alex@uni.edu", "Alex", "CSE1PSD", 85.0);
    reporter.reportGrade("jordan@uni.edu", "Jordan", "CSE1OOF", 72.0);

    // Want to send via SMS instead? Must edit GradeReporter!
    // Want to log to a file? Must edit GradeReporter!
    // Want to test without actually sending? Can't!

    return 0;
}
