// ============================================================
// AFTER Dependency Inversion Principle (DIP)
// ============================================================
// Solution: GradeReporter depends on an ABSTRACTION (INotifier),
//           not a concrete class. The specific notification
//           mechanism is injected from outside.
//
// Key ideas:
//   - INotifier interface: the abstraction both sides depend on
//   - GradeReporter uses INotifier — doesn't know or care how
//   - EmailNotifier, SMSNotifier, etc. implement INotifier
//   - Dependency is INJECTED (constructor injection)
//   - Easy to swap, extend, and test
// ============================================================

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// --- Abstraction: both high and low levels depend on this ---
class INotifier {
public:
    virtual ~INotifier() = default;
    virtual void send(const string& recipient,
                      const string& subject,
                      const string& message) = 0;
};

// --- Low-level module 1: Email ---
class EmailNotifier : public INotifier {
public:
    void send(const string& recipient, const string& subject,
              const string& message) override {
        cout << "[EMAIL] To: " << recipient << "\n"
             << "  Subject: " << subject << "\n"
             << "  Body: " << message << "\n";
    }
};

// --- Low-level module 2: SMS (new — no changes to GradeReporter!) ---
class SMSNotifier : public INotifier {
public:
    void send(const string& recipient, const string& subject,
              const string& message) override {
        cout << "[SMS] To: " << recipient << "\n"
             << "  Message: " << subject << " - " << message << "\n";
    }
};

// --- Low-level module 3: Console logger (great for testing) ---
class ConsoleNotifier : public INotifier {
public:
    void send(const string& recipient, const string& subject,
              const string& message) override {
        cout << "[LOG] " << recipient << " | " << subject << " | " << message << "\n";
    }
};

// --- High-level module: depends on INotifier, not any concrete class ---
class GradeReporter {
    INotifier& notifier;   // Depends on abstraction!

public:
    // Dependency is INJECTED via constructor
    GradeReporter(INotifier& notifier) : notifier(notifier) {}

    void reportGrade(const string& recipient, const string& studentName,
                     const string& subject, double grade) {
        string message = studentName + " received " + to_string(grade)
                       + " in " + subject;
        notifier.send(recipient, "Grade Report: " + subject, message);
    }
};

int main() {
    cout << "=== After DIP ===\n\n";

    // Swap the notifier without changing GradeReporter!
    cout << "--- Using Email ---\n";
    EmailNotifier email;
    GradeReporter emailReporter(email);
    emailReporter.reportGrade("alex@uni.edu", "Alex", "CSE1PSD", 85.0);

    cout << "\n--- Using SMS ---\n";
    SMSNotifier sms;
    GradeReporter smsReporter(sms);
    smsReporter.reportGrade("+61400123456", "Jordan", "CSE1OOF", 72.0);

    cout << "\n--- Using Console (testing) ---\n";
    ConsoleNotifier console;
    GradeReporter testReporter(console);
    testReporter.reportGrade("test-student", "Test", "CSE1TST", 99.0);

    // Adding Slack notifications? Just create SlackNotifier.
    // GradeReporter never changes!

    return 0;
}
