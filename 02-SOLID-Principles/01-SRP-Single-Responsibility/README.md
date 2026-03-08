# SRP — Single Responsibility Principle

> *A class should have only one reason to change.*

## What to Observe

### `before_srp.cpp` — The Violation
The `Student` class handles **five** different responsibilities:
1. Storing student data
2. Calculating averages
3. Applying assessment weights
4. Formatting and printing reports
5. Saving to files

If the grading formula changes, you edit the same class that handles printing. If the report format changes, you risk breaking the grade calculation.

### `after_srp.cpp` — The Solution
Responsibilities are split into focused classes:
- **`Student`** — stores data only
- **`GradeCalculator`** — handles all grade logic
- **`ReportPrinter`** — handles display formatting

Each class has **one reason to change**, and changing one doesn't risk breaking the others.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — split the monolithic class into separate responsibilities. If you need a fresh start, copy `before_srp.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_srp.cpp && ./before
g++ -std=c++17 -o after  after_srp.cpp  && ./after
```
