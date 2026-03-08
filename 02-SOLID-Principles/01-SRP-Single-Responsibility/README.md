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

## Run It

```bash
g++ -std=c++17 -o before before_srp.cpp && ./before
g++ -std=c++17 -o after  after_srp.cpp  && ./after
```
