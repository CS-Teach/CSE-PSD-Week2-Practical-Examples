// ============================================================
// AFTER Liskov Substitution Principle (LSP)
// ============================================================
// Solution: Don't force Square to be a subtype of Rectangle.
//           Instead, use a common Shape interface that both
//           implement correctly without violating expectations.
//
// Key ideas:
//   - Shape defines what ALL shapes can do: getArea()
//   - Rectangle and Square are SEPARATE implementations
//   - No misleading IS-A relationship
//   - Any Shape* can be safely substituted for another
// ============================================================

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// --- Common interface: all shapes can report area ---
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual string describe() const = 0;
};

// --- Rectangle: independent width and height ---
class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    void setWidth(int w)  { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() const  { return width; }
    int getHeight() const { return height; }

    double getArea() const override {
        return width * height;
    }
    string describe() const override {
        return "Rectangle(" + to_string(width) + "x" + to_string(height) + ")";
    }
};

// --- Square: single side length, no width/height confusion ---
class Square : public Shape {
    int side;
public:
    Square(int side) : side(side) {}

    void setSide(int s) { side = s; }
    int getSide() const { return side; }

    double getArea() const override {
        return side * side;
    }
    string describe() const override {
        return "Square(" + to_string(side) + ")";
    }
};

// This function works correctly with ANY Shape
void printArea(const Shape& shape) {
    cout << shape.describe() << " -> Area: " << shape.getArea() << "\n";
}

int main() {
    cout << "=== After LSP ===\n\n";

    // Both are Shapes — substitution works correctly
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(5, 10));
    shapes.push_back(make_unique<Square>(5));
    shapes.push_back(make_unique<Rectangle>(3, 7));
    shapes.push_back(make_unique<Square>(8));

    for (const auto& shape : shapes) {
        printArea(*shape);  // Works correctly for all!
    }

    cout << "\nNo misleading IS-A relationship.\n";
    cout << "Rectangle and Square are siblings, not parent-child.\n";
    cout << "Any Shape can be safely substituted for another.\n";

    return 0;
}
