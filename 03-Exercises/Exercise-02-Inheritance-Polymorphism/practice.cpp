// ============================================================
// Exercise 2: Inheritance & Polymorphism — Shape Hierarchy
// ============================================================
// Your task: Implement a shape hierarchy using inheritance
//            and polymorphism.
//
// Requirements:
//   1. Abstract base class: Shape
//      - Pure virtual: double getArea() const
//      - Pure virtual: double getPerimeter() const
//      - Pure virtual: string getName() const
//      - Virtual destructor
//
//   2. Circle (inherits Shape)
//      - Constructor takes radius (double)
//      - getArea() = pi * r^2
//      - getPerimeter() = 2 * pi * r
//      - getName() = "Circle"
//      - Use M_PI or 3.14159265358979 for pi
//
//   3. Rectangle (inherits Shape)
//      - Constructor takes width and height (double)
//      - getArea() = width * height
//      - getPerimeter() = 2 * (width + height)
//      - getName() = "Rectangle"
//
//   4. Triangle (inherits Shape)
//      - Constructor takes base, height, side1, side2, side3 (double)
//      - getArea() = 0.5 * base * height
//      - getPerimeter() = side1 + side2 + side3
//      - getName() = "Triangle"
//
// Compile & test:
//   g++ -std=c++17 -o test tests.cpp && ./test
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

// TODO: Implement Shape base class

// TODO: Implement Circle

// TODO: Implement Rectangle

// TODO: Implement Triangle

#endif // EXERCISE_CPP
