# 03 — Exercises

Practice implementing OOP and SOLID principles. Each exercise has:

- **`exercise.cpp`** — A skeleton or broken code for you to fix
- **`tests.cpp`** — Assert-based tests that verify your implementation

## How to Work

1. Read the instructions in `exercise.cpp`
2. Implement your solution in `exercise.cpp`
3. Compile and run the tests:

```bash
g++ -std=c++17 -o test tests.cpp && ./test
```

4. Tests print **PASS** for each successful check, or crash with an assertion error showing what went wrong.

## Exercises

| # | Exercise | Concepts | What to Do |
|---|----------|----------|------------|
| 1 | [Encapsulation](Exercise-01-Encapsulation/) | Private data, validation | Implement a `BankAccount` class |
| 2 | [Inheritance & Polymorphism](Exercise-02-Inheritance-Polymorphism/) | Virtual functions, base classes | Build a `Shape` hierarchy |
| 3 | [SRP Refactor](Exercise-03-SRP-Refactor/) | Single Responsibility | Split a monolithic `Library` class |
| 4 | [OCP Extension](Exercise-04-OCP-Extension/) | Open/Closed Principle | Build a polymorphic discount system |
| 5 | [Full SOLID](Exercise-05-Full-SOLID/) | DIP, ISP, SRP, OCP | Fix a notification system |

## Difficulty

- **Exercises 1-2**: Fill in the skeleton (guided)
- **Exercises 3-5**: Refactor/redesign (more open-ended)

> Solutions will be released by your instructor.
