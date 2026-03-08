// ============================================================
// Exercise 5: Tests — Full SOLID Notification System
// ============================================================
// Compile:  g++ -std=c++17 -o test tests.cpp && ./test
//
// These tests capture cout output to verify formatting and
// channel behaviour. If your implementation matches the spec,
// all tests will pass.
// ============================================================

#include "exercise.cpp"  // Change to "solution.cpp" to verify solution
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

// Helper: capture cout output during a function call
string captureOutput(function<void()> fn) {
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    fn();
    cout.rdbuf(old);
    return buffer.str();
}

int main() {
    // Test 1: MessageFormatter formats correctly
    {
        string result = MessageFormatter::format("Alice", "your grade is ready");
        assert(result == "Dear Alice, your grade is ready");
        cout << "PASS: MessageFormatter formats correctly\n";
    }

    // Test 2: EmailChannel name
    {
        EmailChannel email;
        assert(email.getChannelName() == "Email");
        cout << "PASS: EmailChannel has correct name\n";
    }

    // Test 3: SMSChannel name
    {
        SMSChannel sms;
        assert(sms.getChannelName() == "SMS");
        cout << "PASS: SMSChannel has correct name\n";
    }

    // Test 4: EmailChannel output format
    {
        EmailChannel email;
        string output = captureOutput([&]() {
            email.send("alice@uni.edu", "Hello world");
        });
        assert(output == "[EMAIL] To: alice@uni.edu | Hello world\n");
        cout << "PASS: EmailChannel sends with correct format\n";
    }

    // Test 5: SMSChannel output format
    {
        SMSChannel sms;
        string output = captureOutput([&]() {
            sms.send("+61400111222", "Hello world");
        });
        assert(output == "[SMS] To: +61400111222 | Hello world\n");
        cout << "PASS: SMSChannel sends with correct format\n";
    }

    // Test 6: NotificationService with EmailChannel (DIP)
    {
        EmailChannel email;
        NotificationService service(email);
        string output = captureOutput([&]() {
            service.notify("alice@uni.edu", "Alice", "your grade is ready");
        });
        assert(output == "[EMAIL] To: alice@uni.edu | Dear Alice, your grade is ready\n");
        cout << "PASS: NotificationService works with EmailChannel\n";
    }

    // Test 7: NotificationService with SMSChannel (DIP swap)
    {
        SMSChannel sms;
        NotificationService service(sms);
        string output = captureOutput([&]() {
            service.notify("+61400111222", "Bob", "lab 3 is due tomorrow");
        });
        assert(output == "[SMS] To: +61400111222 | Dear Bob, lab 3 is due tomorrow\n");
        cout << "PASS: NotificationService works with SMSChannel\n";
    }

    // Test 8: Polymorphism — IMessageChannel pointer
    {
        EmailChannel email;
        SMSChannel sms;

        IMessageChannel* channels[] = {&email, &sms};
        assert(channels[0]->getChannelName() == "Email");
        assert(channels[1]->getChannelName() == "SMS");
        cout << "PASS: Polymorphism works through IMessageChannel pointers\n";
    }

    cout << "\n=== ALL TESTS PASSED ===\n";
    return 0;
}
