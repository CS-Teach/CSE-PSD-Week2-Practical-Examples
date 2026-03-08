// ============================================================
// AFTER Encapsulation
// ============================================================
// Solution: Data is private inside a class. Access is only
//           through controlled public methods (getters/setters)
//           that enforce validation rules.
//
// Key ideas:
//   - Private member variables — cannot be accessed directly
//   - Public setter with validation — rejects bad input
//   - Public getter — provides read access safely
//   - Data and behaviour live together in one class
// ============================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    // --- Private: only accessible through public methods ---
    string name;
    vector<int> grades;

public:
    // Constructor validates on creation
    Student(const string& name, const vector<int>& grades)
        : name(name), grades(grades)
    {
        if (name.empty()) {
            throw invalid_argument("Name cannot be empty");
        }
        for (int g : grades) {
            if (g < 0 || g > 100) {
                throw invalid_argument("Grade must be 0-100");
            }
        }
    }

    // --- Getter: safe read access ---
    string getName() const { return name; }

    // --- Setter with validation: controlled write access ---
    void addGrade(int grade) {
        if (grade < 0 || grade > 100) {
            throw invalid_argument("Grade must be between 0 and 100");
        }
        grades.push_back(grade);
    }

    // --- Behaviour that uses private data ---
    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }

    string getLetterGrade() const {
        double avg = calculateAverage();
        if      (avg >= 90) return "A";
        else if (avg >= 80) return "B";
        else if (avg >= 70) return "C";
        else                return "F";
    }

    void printReport() const {
        cout << "Student: " << name << "\n";
        cout << "Average: " << calculateAverage() << "\n";
        cout << "Letter Grade: " << getLetterGrade() << "\n";
    }
};

int main() {
    cout << "=== After Encapsulation ===\n\n";

    Student alex("Alex", {78, 85, 92});
    alex.printReport();

    // Adding a valid grade works fine
    alex.addGrade(88);
    cout << "\nAfter adding grade 88:\n";
    alex.printReport();

    // Trying to add an invalid grade — caught by validation!
    cout << "\nTrying to add grade -500...\n";
    try {
        alex.addGrade(-500);
    } catch (const invalid_argument& e) {
        cout << "Rejected! " << e.what() << "\n";
    }

    // Trying to create a student with empty name — also caught!
    cout << "\nTrying to create student with empty name...\n";
    try {
        Student bad("", {50, 60});
    } catch (const invalid_argument& e) {
        cout << "Rejected! " << e.what() << "\n";
    }

    return 0;
}
