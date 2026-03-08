# Polymorphism

**Polymorphism** means "many forms" — the same function call behaves differently depending on the actual type of the object, decided at runtime.

## What to Observe

### `before_polymorphism.cpp` — The Problem
- A `type` string field acts as a **manual type tag**
- Every function has an **if/else chain** checking the type
- Adding a new type means updating **every** if/else chain — easy to miss one

### `after_polymorphism.cpp` — The Solution
- Each transport type **is its own class** with **virtual functions**
- Calling `trip->calculateFare()` automatically runs the **correct version**
- Adding a new type = adding a class — **no existing code changes**

## Key Takeaway

> Let the type system do the dispatch. Virtual functions replace if/else chains with clean, extensible code.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — refactor it to use polymorphism. If you need a fresh start, copy `before_polymorphism.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_polymorphism.cpp && ./before
g++ -std=c++17 -o after  after_polymorphism.cpp  && ./after
```
