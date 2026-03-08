// ============================================================
// PRACTICE FILE — Edit this file freely!
// ============================================================
// This is your working copy of before_lsp.cpp.
// Experiment, refactor, and improve this code.
// If you need a fresh start, copy the contents of before_lsp.cpp back.
// Compare your work with after_lsp.cpp when done.
// ============================================================

// ============================================================
// BEFORE Liskov Substitution Principle (LSP)
// ============================================================
// Problem:  Square inherits from Rectangle, but overriding
//           setWidth/setHeight breaks the expected behaviour.
//           Code that works correctly with Rectangle fails
//           when given a Square — LSP violation!
//
// The rule: If S is a subtype of T, then objects of type T
//           can be replaced with objects of type S without
//           breaking the program's correctness.
// ============================================================

#include <iostream>
#include <cassert>
using namespace std;

class Rectangle {
protected:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    virtual ~Rectangle() = default;

    virtual void setWidth(int w)  { width = w; }
    virtual void setHeight(int h) { height = h; }

    int getWidth() const  { return width; }
    int getHeight() const { return height; }
    int getArea() const   { return width * height; }
};

// Square IS-A Rectangle... right?
class Square : public Rectangle {
public:
    Square(int side) : Rectangle(side, side) {}

    // Override to keep width == height (that's what a square is!)
    void setWidth(int w) override {
        width = w;
        height = w;   // Forces both to match
    }
    void setHeight(int h) override {
        width = h;    // Forces both to match
        height = h;
    }
};

// This function expects Rectangle behaviour:
// "Setting width should NOT affect height"
void doubleWidth(Rectangle& r) {
    int originalHeight = r.getHeight();
    r.setWidth(r.getWidth() * 2);

    // This should ALWAYS be true for a Rectangle...
    // but it FAILS for a Square! (height changed too!)
    cout << "Expected height: " << originalHeight
         << ", Actual height: " << r.getHeight() << "\n";
}

int main() {
    cout << "=== Before LSP ===\n\n";

    Rectangle rect(5, 10);
    cout << "Rectangle (5x10):\n";
    cout << "  Area: " << rect.getArea() << "\n";
    doubleWidth(rect);
    cout << "  Area after doubling width: " << rect.getArea() << "\n\n";

    // Square substituted where Rectangle expected — breaks!
    Square sq(5);
    cout << "Square (5x5) used as Rectangle:\n";
    cout << "  Area: " << sq.getArea() << "\n";
    doubleWidth(sq);  // Height changes unexpectedly!
    cout << "  Area after doubling width: " << sq.getArea() << "\n";
    cout << "\n  BUG: Square's height changed when only width was set!\n";
    cout << "  This violates the Liskov Substitution Principle.\n";

    return 0;
}
