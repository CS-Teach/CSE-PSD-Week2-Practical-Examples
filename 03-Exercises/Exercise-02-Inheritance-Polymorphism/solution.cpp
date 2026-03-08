// ============================================================
// Exercise 2: Solution — Shape Hierarchy
// ============================================================

#ifndef EXERCISE_CPP
#define EXERCISE_CPP

#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual string getName() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        return PI * radius * radius;
    }
    double getPerimeter() const override {
        return 2 * PI * radius;
    }
    string getName() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    string getName() const override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
    double base, height, side1, side2, side3;
public:
    Triangle(double base, double height, double s1, double s2, double s3)
        : base(base), height(height), side1(s1), side2(s2), side3(s3) {}

    double getArea() const override {
        return 0.5 * base * height;
    }
    double getPerimeter() const override {
        return side1 + side2 + side3;
    }
    string getName() const override {
        return "Triangle";
    }
};

#endif // EXERCISE_CPP
