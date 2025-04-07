# Bank Account Management System (C++ Project)

This C++ program implements a console-based banking system where users can create and manage both regular and premium accounts. 
The system allows deposits, withdrawals, and account summaries, while applying different rules for each account type. 
The project emphasizes object-oriented programming with class hierarchies, encapsulation, and method overriding.

---

## Features

- Create up to 5 total bank accounts
- Two account types:
  - RegularAccount – standard account with no minimum balance requirement
  - PremiumAccount – enforces a minimum balance of 1000 Galactic units
- Deposit and withdraw funds with input validation
- Transaction date/time structure using a custom `Date` class
- Dynamic account creation with polymorphic behavior
- Input-driven menu loop for interaction
- Formatted account summaries


---

## File Overview

- `main.cpp`  
  The main program file. Handles the user menu, input/output, and overall program flow.

- `Account.h / Account.cpp`  
  Abstract base class for both Regular and Premium accounts. Stores account ID, balance, and creation date. Includes virtual methods like `deposit`, `withdraw`, and `print`.

- `RegularAccount.h / RegularAccount.cpp`  
  Inherits from `Account`. Allows deposits and withdrawals with no balance restrictions.

- `PremiumAccount.h / PremiumAccount.cpp`  
  Inherits from `Account`. Requires a minimum balance of 1000. Overrides `withdraw` to prevent dropping below that threshold.

- `Date.h / Date.cpp`  
  Manages date tracking for when each account is created. Provides formatted date output.

---

## Concepts Used

- Inheritance and polymorphism
- Abstract classes and virtual functions
- Method overriding
- Encapsulation and access control
- Static member variables
- Input validation
- Menu-driven user interface

---

## Author

Ali Ghorbani  
University of Texas at Dallas  
CS 1337 Project – Spring 2024 
GitHub: [@alighorbanii](https://github.com/alighorbanii)

