# Encapsulation

**Encapsulation** means bundling data and the methods that operate on it into a single class, and restricting direct access to the data.

## What to Observe

### `before_encapsulation.cpp` — The Problem
- Student data is stored in **global variables**
- Any code can directly set `grade1 = -500` — no validation
- Functions are disconnected from the data they operate on

### `after_encapsulation.cpp` — The Solution
- Data is **private** inside the `Student` class
- Access is through **getters** (read) and **setters** (write with validation)
- Invalid data is **rejected** at the boundary — the object stays consistent

## Key Takeaway

> Make data private. Control access through public methods that enforce your rules.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — refactor it to use encapsulation. If you need a fresh start, copy `before_encapsulation.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_encapsulation.cpp && ./before
g++ -std=c++17 -o after  after_encapsulation.cpp  && ./after
```
