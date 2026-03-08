// ============================================================
// Exercise 2: Tests — Shape Hierarchy
// ============================================================
// Compile:  g++ -std=c++17 -o test tests.cpp && ./test
// ============================================================

#include "exercise.cpp"  // Change to "solution.cpp" to verify solution
#include <cassert>
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
using namespace std;

bool approxEqual(double a, double b, double epsilon = 0.01) {
    return fabs(a - b) < epsilon;
}

int main() {
    // Test 1: Circle area and perimeter
    {
        Circle c(5.0);
        assert(approxEqual(c.getArea(), 78.54));  // pi * 25
        assert(approxEqual(c.getPerimeter(), 31.42));  // 2 * pi * 5
        assert(c.getName() == "Circle");
        cout << "PASS: Circle area, perimeter, and name correct\n";
    }

    // Test 2: Rectangle area and perimeter
    {
        Rectangle r(4.0, 6.0);
        assert(approxEqual(r.getArea(), 24.0));
        assert(approxEqual(r.getPerimeter(), 20.0));
        assert(r.getName() == "Rectangle");
        cout << "PASS: Rectangle area, perimeter, and name correct\n";
    }

    // Test 3: Triangle area and perimeter
    {
        Triangle t(3.0, 4.0, 3.0, 4.0, 5.0);  // 3-4-5 right triangle
        assert(approxEqual(t.getArea(), 6.0));  // 0.5 * 3 * 4
        assert(approxEqual(t.getPerimeter(), 12.0));  // 3 + 4 + 5
        assert(t.getName() == "Triangle");
        cout << "PASS: Triangle area, perimeter, and name correct\n";
    }

    // Test 4: Polymorphism — treat all shapes through base pointer
    {
        vector<unique_ptr<Shape>> shapes;
        shapes.push_back(make_unique<Circle>(1.0));
        shapes.push_back(make_unique<Rectangle>(2.0, 3.0));
        shapes.push_back(make_unique<Triangle>(6.0, 4.0, 5.0, 5.0, 6.0));

        // Circle(1): area = pi ≈ 3.14
        assert(approxEqual(shapes[0]->getArea(), 3.14));
        // Rectangle(2,3): area = 6
        assert(approxEqual(shapes[1]->getArea(), 6.0));
        // Triangle(base=6, h=4): area = 12
        assert(approxEqual(shapes[2]->getArea(), 12.0));
        cout << "PASS: Polymorphism works through Shape pointers\n";
    }

    // Test 5: Unit circle
    {
        Circle unit(1.0);
        assert(approxEqual(unit.getArea(), PI));
        assert(approxEqual(unit.getPerimeter(), 2 * PI));
        cout << "PASS: Unit circle matches PI values\n";
    }

    // Test 6: Square as rectangle
    {
        Rectangle square(5.0, 5.0);
        assert(approxEqual(square.getArea(), 25.0));
        assert(approxEqual(square.getPerimeter(), 20.0));
        cout << "PASS: Square works as Rectangle(5,5)\n";
    }

    cout << "\n=== ALL TESTS PASSED ===\n";
    return 0;
}
