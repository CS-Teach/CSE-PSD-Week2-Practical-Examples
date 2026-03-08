// ============================================================
// Exercise 5: Full SOLID — Notification System
// ============================================================
// The code below violates several SOLID principles:
//
//   - DIP: NotificationService directly creates EmailSender
//     (hardcoded dependency on a concrete class)
//   - ISP: IMessenger is a fat interface — not every channel
//     supports subjects or attachments
//   - SRP: NotificationService formats messages AND sends them
//   - OCP: Adding a new channel requires editing the service
//
// Your task: Refactor to follow SOLID principles.
//
// Required classes:
//
//   1. IMessageChannel (abstract base — the DIP abstraction)
//      - Pure virtual: void send(const string& to, const string& message) const
//      - Pure virtual: string getChannelName() const
//
//   2. EmailChannel : public IMessageChannel
//      - send() prints: [EMAIL] To: {to} | {message}
//      - getChannelName() returns "Email"
//
//   3. SMSChannel : public IMessageChannel
//      - send() prints: [SMS] To: {to} | {message}
//      - getChannelName() returns "SMS"
//
//   4. MessageFormatter (SRP — separate formatting from sending)
//      - static string format(const string& recipient, const string& content)
//        Returns: "Dear {recipient}, {content}"
//
//   5. NotificationService (depends on IMessageChannel abstraction)
//      - Constructor takes IMessageChannel reference (DIP!)
//      - void notify(const string& to, const string& recipient,
//                    const string& content) const
//        Uses MessageFormatter to format, then channel to send
//
// Compile & test:
//   g++ -std=c++17 -o test tests.cpp && ./test
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <iostream>
using namespace std;

// --- ORIGINAL VIOLATING CODE (for reference) ---

// Fat interface — not every channel needs all of these
class IMessenger {
public:
    virtual ~IMessenger() = default;
    virtual void sendBasic(const string& to, const string& msg) = 0;
    virtual void sendWithSubject(const string& to, const string& subject,
                                 const string& msg) = 0;
    virtual void sendWithAttachment(const string& to, const string& msg,
                                    const string& filePath) = 0;
};

// Hardcoded email sender
class EmailSender {
public:
    void send(const string& to, const string& subject, const string& body) {
        cout << "[EMAIL] To: " << to << " | Subject: " << subject
             << " | Body: " << body << "\n";
    }
};

// Violates DIP (creates its own dependency) and SRP (formats + sends)
class BadNotificationService {
    EmailSender sender;  // Hardcoded — can't swap!
public:
    void notify(const string& email, const string& name, const string& content) {
        string formatted = "Dear " + name + ", " + content;
        sender.send(email, "Notification", formatted);
    }
};

// --- YOUR REFACTORED CLASSES BELOW ---
// TODO: Implement IMessageChannel (abstract)
// TODO: Implement EmailChannel
// TODO: Implement SMSChannel
// TODO: Implement MessageFormatter
// TODO: Implement NotificationService

#endif // EXERCISE_CPP
