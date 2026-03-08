# Abstraction

**Abstraction** means hiding complex implementation details behind a simple interface. Users of the abstraction don't need to know *how* it works — just *what* it does.

## What to Observe

### `before_abstraction.cpp` — The Problem
- Each transport type has its **own standalone function**
- The caller must know **which function** to call and **what parameters** each needs
- Adding a new transport requires a new function AND updating every call site

### `after_abstraction.cpp` — The Solution
- An **abstract base class** `Transport` defines the common interface
- Each transport **implements** `calculateFare()` internally
- Callers use `Transport*` — they don't know or care about the concrete type

## Key Takeaway

> Define what something DOES (interface), not HOW it does it (implementation).

## Run It

```bash
g++ -std=c++17 -o before before_abstraction.cpp && ./before
g++ -std=c++17 -o after  after_abstraction.cpp  && ./after
```
