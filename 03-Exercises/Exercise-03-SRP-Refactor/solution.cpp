// ============================================================
// Exercise 3: Solution — Library SRP Refactoring
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <vector>
using namespace std;

// Responsibility 1: Data storage for a single book
class Book {
    string title;
    string author;
public:
    Book(const string& title, const string& author)
        : title(title), author(author) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

// Responsibility 2: Managing the book collection
class BookCatalogue {
    vector<Book> books;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    int getBookCount() const {
        return books.size();
    }

    Book* findByTitle(const string& title) {
        for (auto& b : books) {
            if (b.getTitle() == title) return &b;
        }
        return nullptr;
    }
};

// Responsibility 3: Managing membership
class MemberRegistry {
    vector<string> members;
public:
    void addMember(const string& name) {
        members.push_back(name);
    }

    int getMemberCount() const {
        return members.size();
    }

    bool isMember(const string& name) const {
        for (const auto& m : members) {
            if (m == name) return true;
        }
        return false;
    }
};

// Responsibility 4: Report generation
class LibraryReporter {
public:
    static string generateReport(const BookCatalogue& catalogue,
                                 const MemberRegistry& registry) {
        return "Books: " + to_string(catalogue.getBookCount())
             + ", Members: " + to_string(registry.getMemberCount());
    }
};

#endif // EXERCISE_CPP
