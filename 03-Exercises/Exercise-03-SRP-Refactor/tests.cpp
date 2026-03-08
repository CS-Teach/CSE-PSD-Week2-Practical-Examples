// ============================================================
// Exercise 3: Tests — Library SRP Refactoring
// ============================================================
// Compile:  g++ -std=c++17 -o test tests.cpp && ./test
//
// These tests verify your refactored classes. The monolithic
// Library class won't pass these — you need Book, BookCatalogue,
// MemberRegistry, and LibraryReporter.
// ============================================================

#include "practice.cpp"  // Students edit practice.cpp — exercise.cpp is the clean reference
#include <cassert>
#include <iostream>
using namespace std;

int main() {
    // Test 1: Book stores title and author
    {
        Book b("The Pragmatic Programmer", "Hunt & Thomas");
        assert(b.getTitle() == "The Pragmatic Programmer");
        assert(b.getAuthor() == "Hunt & Thomas");
        cout << "PASS: Book stores title and author\n";
    }

    // Test 2: BookCatalogue manages books
    {
        BookCatalogue catalogue;
        assert(catalogue.getBookCount() == 0);

        catalogue.addBook(Book("Clean Code", "Robert Martin"));
        catalogue.addBook(Book("Design Patterns", "GoF"));
        assert(catalogue.getBookCount() == 2);
        cout << "PASS: BookCatalogue manages book collection\n";
    }

    // Test 3: BookCatalogue findByTitle
    {
        BookCatalogue catalogue;
        catalogue.addBook(Book("Clean Code", "Robert Martin"));
        catalogue.addBook(Book("Refactoring", "Martin Fowler"));

        Book* found = catalogue.findByTitle("Clean Code");
        assert(found != nullptr);
        assert(found->getAuthor() == "Robert Martin");

        Book* notFound = catalogue.findByTitle("Nonexistent");
        assert(notFound == nullptr);
        cout << "PASS: BookCatalogue finds books by title\n";
    }

    // Test 4: MemberRegistry manages members
    {
        MemberRegistry registry;
        assert(registry.getMemberCount() == 0);

        registry.addMember("Alice");
        registry.addMember("Bob");
        assert(registry.getMemberCount() == 2);

        assert(registry.isMember("Alice") == true);
        assert(registry.isMember("Charlie") == false);
        cout << "PASS: MemberRegistry manages members\n";
    }

    // Test 5: LibraryReporter generates report
    {
        BookCatalogue catalogue;
        catalogue.addBook(Book("Book A", "Author A"));
        catalogue.addBook(Book("Book B", "Author B"));
        catalogue.addBook(Book("Book C", "Author C"));

        MemberRegistry registry;
        registry.addMember("Alice");
        registry.addMember("Bob");

        string report = LibraryReporter::generateReport(catalogue, registry);
        assert(report == "Books: 3, Members: 2");
        cout << "PASS: LibraryReporter generates correct report\n";
    }

    // Test 6: Empty report
    {
        BookCatalogue catalogue;
        MemberRegistry registry;
        string report = LibraryReporter::generateReport(catalogue, registry);
        assert(report == "Books: 0, Members: 0");
        cout << "PASS: Empty report works correctly\n";
    }

    cout << "\n=== ALL TESTS PASSED ===\n";
    return 0;
}
