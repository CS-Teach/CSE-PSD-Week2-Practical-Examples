# LSP — Liskov Substitution Principle

> *Objects of a superclass should be replaceable with objects of a subclass without breaking the program.*

## What to Observe

### `before_lsp.cpp` — The Violation
`Square` inherits from `Rectangle` and overrides `setWidth()`/`setHeight()` to keep both dimensions equal. This breaks code that expects Rectangle behaviour — setting the width shouldn't change the height, but for a Square it does.

### `after_lsp.cpp` — The Solution
`Rectangle` and `Square` are **siblings**, not parent-child. Both implement a common `Shape` interface. Any `Shape*` can be safely used without unexpected side effects.

## Key Takeaway

> If substituting a subclass breaks expectations, the inheritance relationship is wrong. Prefer composition or sibling hierarchies.

## Run It

```bash
g++ -std=c++17 -o before before_lsp.cpp && ./before
g++ -std=c++17 -o after  after_lsp.cpp  && ./after
```
