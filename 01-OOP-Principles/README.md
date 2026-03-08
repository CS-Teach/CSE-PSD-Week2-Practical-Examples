# 01 — OOP Principles

Four core Object-Oriented Programming principles, each with a **before/after** pair showing the problem and the solution.

## Principles

### [01 — Encapsulation](01-Encapsulation/)
**Before:** Global variables with no protection — anyone can corrupt the data.
**After:** Private members with validated getters/setters — data is safe.

### [02 — Abstraction](02-Abstraction/)
**Before:** Separate functions per transport type — caller must know internal details.
**After:** Abstract `Transport` base class — callers use a common interface.

### [03 — Inheritance](03-Inheritance/)
**Before:** Duplicated structs for Bus, Train, Ferry — same fields copied everywhere.
**After:** Shared `Transport` base class — common code written once.

### [04 — Polymorphism](04-Polymorphism/)
**Before:** String-based type tags with if/else chains in every function.
**After:** Virtual functions — the runtime picks the right method automatically.

## How to Run

Each file compiles and runs independently:

```bash
g++ -std=c++17 -o before before_encapsulation.cpp && ./before
g++ -std=c++17 -o after  after_encapsulation.cpp  && ./after
```

Read the **before** first to understand the problem, then the **after** to see the solution.
