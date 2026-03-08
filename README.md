# Week 2 Practical — OOP Principles & SOLID

Hands-on C++ examples demonstrating Object-Oriented Programming principles and SOLID design principles, plus exercises to test your understanding.

## How to Use This Repo

Every `.cpp` file is **self-contained** — it compiles and runs on its own:

```bash
g++ -std=c++17 -o program filename.cpp && ./program
```

**Examples** come in **before/after pairs**: the "before" shows the problem, the "after" shows the OOP/SOLID solution. Read both and compare! Each example also has a **`practice.cpp`** — your working copy. Edit `practice.cpp` freely; if you mess up, just copy the `before_*.cpp` back over it.

**Exercises** have test files — compile and run the tests to check your work:

```bash
g++ -std=c++17 -o test tests.cpp && ./test
```

---

## Contents

### [01 — OOP Principles](01-OOP-Principles/)

Core object-oriented concepts with before/after demonstrations:

| # | Principle | Before (Problem) | After (Solution) |
|---|-----------|-------------------|------------------|
| 1 | [Encapsulation](01-OOP-Principles/01-Encapsulation/) | Global vars, no protection | Private members, validation |
| 2 | [Abstraction](01-OOP-Principles/02-Abstraction/) | Procedural fare functions | Abstract Transport interface |
| 3 | [Inheritance](01-OOP-Principles/03-Inheritance/) | Duplicated structs | Shared base class |
| 4 | [Polymorphism](01-OOP-Principles/04-Polymorphism/) | if/else type dispatch | Virtual functions |

### [02 — SOLID Principles](02-SOLID-Principles/)

The five SOLID design principles applied to university-themed examples:

| # | Principle | Before (Problem) | After (Solution) |
|---|-----------|-------------------|------------------|
| 1 | [SRP — Single Responsibility](02-SOLID-Principles/01-SRP-Single-Responsibility/) | Student class does everything | Separated concerns |
| 2 | [OCP — Open/Closed](02-SOLID-Principles/02-OCP-Open-Closed/) | if/else assessment types | Polymorphic strategies |
| 3 | [LSP — Liskov Substitution](02-SOLID-Principles/03-LSP-Liskov-Substitution/) | Rectangle/Square violation | Proper shape hierarchy |
| 4 | [ISP — Interface Segregation](02-SOLID-Principles/04-ISP-Interface-Segregation/) | Fat IUniversitySystem | Role-based interfaces |
| 5 | [DIP — Dependency Inversion](02-SOLID-Principles/05-DIP-Dependency-Inversion/) | Hardcoded EmailSender | Injected INotifier |

### [03 — Exercises](03-Exercises/)

Practice what you've learned — implement the TODO skeletons and run the tests:

| # | Exercise | Concepts | Approach |
|---|----------|----------|----------|
| 1 | [Encapsulation](03-Exercises/Exercise-01-Encapsulation/) | Encapsulation, validation | Fill in the skeleton |
| 2 | [Inheritance & Polymorphism](03-Exercises/Exercise-02-Inheritance-Polymorphism/) | Inheritance, virtual functions | Fill in the skeleton |
| 3 | [SRP Refactor](03-Exercises/Exercise-03-SRP-Refactor/) | Single Responsibility | Refactor monolithic class |
| 4 | [OCP Extension](03-Exercises/Exercise-04-OCP-Extension/) | Open/Closed Principle | Add via polymorphism |
| 5 | [Full SOLID](03-Exercises/Exercise-05-Full-SOLID/) | DIP, ISP, SRP, OCP | Fix multiple violations |

> Solutions will be released by your instructor.

---

## Requirements

- C++17 compatible compiler (`g++`, `clang++`)
- No external libraries needed — everything uses the C++ standard library
