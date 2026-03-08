# Inheritance

**Inheritance** allows a new class to reuse fields and methods from an existing class, avoiding code duplication.

## What to Observe

### `before_inheritance.cpp` — The Problem
- `BusTrip`, `TrainTrip`, `FerryTrip` are separate structs
- `name`, `zones`, `tappedOn`, and `tapOn()` are **duplicated** in each
- Adding a field (e.g. `maxCapacity`) means editing every struct

### `after_inheritance.cpp` — The Solution
- Shared fields and `tapOn()` live in the **base class** `Transport`
- Each subclass only defines what's **unique** to it (e.g. fare calculation)
- Adding a new transport type means writing one small subclass

## Key Takeaway

> Put shared code in a base class. Subclasses inherit the common parts and only add what's different.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — refactor it to use inheritance. If you need a fresh start, copy `before_inheritance.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_inheritance.cpp && ./before
g++ -std=c++17 -o after  after_inheritance.cpp  && ./after
```
