// ============================================================
// Exercise 5: Solution — Full SOLID Notification System
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <iostream>
using namespace std;

// ISP: Small, focused interface — only what channels need
class IMessageChannel {
public:
    virtual ~IMessageChannel() = default;
    virtual void send(const string& to, const string& message) const = 0;
    virtual string getChannelName() const = 0;
};

// OCP: New channels added by creating new classes
class EmailChannel : public IMessageChannel {
public:
    void send(const string& to, const string& message) const override {
        cout << "[EMAIL] To: " << to << " | " << message << "\n";
    }
    string getChannelName() const override { return "Email"; }
};

class SMSChannel : public IMessageChannel {
public:
    void send(const string& to, const string& message) const override {
        cout << "[SMS] To: " << to << " | " << message << "\n";
    }
    string getChannelName() const override { return "SMS"; }
};

// SRP: Formatting is a separate responsibility
class MessageFormatter {
public:
    static string format(const string& recipient, const string& content) {
        return "Dear " + recipient + ", " + content;
    }
};

// DIP: Depends on IMessageChannel abstraction, not concrete class
class NotificationService {
    const IMessageChannel& channel;
public:
    NotificationService(const IMessageChannel& channel) : channel(channel) {}

    void notify(const string& to, const string& recipient,
                const string& content) const {
        string formatted = MessageFormatter::format(recipient, content);
        channel.send(to, formatted);
    }
};

#endif // EXERCISE_CPP
