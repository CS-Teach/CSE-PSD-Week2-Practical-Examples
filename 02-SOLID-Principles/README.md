# 02 — SOLID Principles

The five SOLID design principles, each demonstrated with a **before/after** pair using university-themed examples.

## The Principles

| Letter | Principle | Meaning |
|--------|-----------|---------|
| **S** | [Single Responsibility](01-SRP-Single-Responsibility/) | A class should have only one reason to change |
| **O** | [Open/Closed](02-OCP-Open-Closed/) | Open for extension, closed for modification |
| **L** | [Liskov Substitution](03-LSP-Liskov-Substitution/) | Subtypes must be substitutable for their base types |
| **I** | [Interface Segregation](04-ISP-Interface-Segregation/) | Don't force classes to implement interfaces they don't use |
| **D** | [Dependency Inversion](05-DIP-Dependency-Inversion/) | Depend on abstractions, not concrete implementations |

## How to Run

Each file compiles and runs independently:

```bash
g++ -std=c++17 -o before before_srp.cpp && ./before
g++ -std=c++17 -o after  after_srp.cpp  && ./after
```

Read the **before** to see the violation, then the **after** to see the fix.
