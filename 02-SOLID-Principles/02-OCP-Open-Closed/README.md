# OCP — Open/Closed Principle

> *Software entities should be open for extension, but closed for modification.*

## What to Observe

### `before_ocp.cpp` — The Violation
Adding a new assessment type (e.g. "project") requires **editing** the existing `calculateWeightedScore()` method. Every edit risks breaking existing calculations that already work.

### `after_ocp.cpp` — The Solution
Each assessment type is a **separate strategy class**. Adding "Project" means creating `ProjectStrategy` — no existing code is modified. The system is extended without touching what already works.

## Run It

```bash
g++ -std=c++17 -o before before_ocp.cpp && ./before
g++ -std=c++17 -o after  after_ocp.cpp  && ./after
```
