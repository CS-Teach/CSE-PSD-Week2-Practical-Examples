# DIP — Dependency Inversion Principle

> *High-level modules should not depend on low-level modules. Both should depend on abstractions.*

## What to Observe

### `before_dip.cpp` — The Violation
`GradeReporter` directly creates an `EmailSender` — it's **hardcoded** to email. Want to switch to SMS? You must edit `GradeReporter`. Want to test without sending emails? You can't.

### `after_dip.cpp` — The Solution
`GradeReporter` depends on an `INotifier` **abstraction** (interface). The concrete notifier (Email, SMS, Console) is **injected** via the constructor. Swapping notification methods requires zero changes to `GradeReporter`.

## Key Takeaway

> Depend on interfaces, not implementations. Inject dependencies from outside rather than creating them inside.

## Try It Yourself

`practice.cpp` is your working copy of the "before" code. Edit it freely — inject the dependency through an abstraction. If you need a fresh start, copy `before_dip.cpp` back over it.

```bash
g++ -std=c++17 -o practice practice.cpp && ./practice
```

## Run the Examples

```bash
g++ -std=c++17 -o before before_dip.cpp && ./before
g++ -std=c++17 -o after  after_dip.cpp  && ./after
```
