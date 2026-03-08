# ISP — Interface Segregation Principle

> *No client should be forced to depend on methods it does not use.*

## What to Observe

### `before_isp.cpp` — The Violation
`IUniversitySystem` is a **fat interface** with methods for students, lecturers, AND admins. `StudentUser` is forced to implement `manageCourse()` (which it can't do), and `LecturerUser` is forced to implement `enrolInSubject()` (which makes no sense). Both throw runtime exceptions for unsupported operations.

### `after_isp.cpp` — The Solution
The fat interface is split into **role-specific** interfaces:
- `IStudentActions` — enrol, submit, view grades
- `ILecturerActions` — manage courses, grade students
- `IAdminActions` — manage enrolments

Each class only implements what it actually needs. Invalid operations are caught at **compile time**, not runtime.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — split the fat interface into role-based interfaces. If you need a fresh start, copy `before_isp.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_isp.cpp && ./before
g++ -std=c++17 -o after  after_isp.cpp  && ./after
```
