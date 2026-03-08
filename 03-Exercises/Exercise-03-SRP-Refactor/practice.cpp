// ============================================================
// Exercise 3: SRP Refactoring — Library System
// ============================================================
// Problem:  The Library class below violates SRP — it handles
//           book storage, search, membership, and reporting
//           all in one class.
//
// Your task: Refactor into separate classes so that each class
//            has a single responsibility:
//
//   1. Book — stores title and author
//      - Constructor: Book(string title, string author)
//      - string getTitle() const
//      - string getAuthor() const
//
//   2. BookCatalogue — manages the collection of books
//      - void addBook(const Book& book)
//      - int getBookCount() const
//      - Book* findByTitle(const string& title)
//        (returns pointer to found book, or nullptr if not found)
//
//   3. MemberRegistry — manages library members
//      - void addMember(const string& name)
//      - int getMemberCount() const
//      - bool isMember(const string& name) const
//
//   4. LibraryReporter — generates reports
//      - static string generateReport(const BookCatalogue&, const MemberRegistry&)
//        (returns a string like: "Books: 3, Members: 2")
//
// Compile & test:
//   g++ -std=c++17 -o test tests.cpp && ./test
//
// The tests verify your refactored classes work correctly.
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// --- ORIGINAL MONOLITHIC CLASS (for reference — DELETE or refactor) ---
// This is what you need to break apart:

class Library {
public:
    struct BookEntry {
        string title;
        string author;
    };

    vector<BookEntry> books;
    vector<string> members;

    void addBook(const string& title, const string& author) {
        books.push_back({title, author});
    }

    void addMember(const string& name) {
        members.push_back(name);
    }

    bool isMember(const string& name) {
        for (const auto& m : members)
            if (m == name) return true;
        return false;
    }

    BookEntry* findByTitle(const string& title) {
        for (auto& b : books)
            if (b.title == title) return &b;
        return nullptr;
    }

    string generateReport() {
        return "Books: " + to_string(books.size())
             + ", Members: " + to_string(members.size());
    }
};

// --- YOUR REFACTORED CLASSES BELOW ---
// TODO: Implement Book class
// TODO: Implement BookCatalogue class
// TODO: Implement MemberRegistry class
// TODO: Implement LibraryReporter class

#endif // EXERCISE_CPP
