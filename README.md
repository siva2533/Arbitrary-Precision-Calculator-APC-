# 📟 Arbitrary Precision Calculator (C Programming)

A command-line Arbitrary Precision Calculator built using C. This project performs arithmetic operations on integers of unlimited length by overcoming standard data type limitations. It uses doubly linked lists for digit-level computation and follows a modular, multi-file architecture.

---

## 🚀 Features
### ✔ Input Validation
- Accepts operands and operators via command-line
- Supports negative numbers
- Rejects invalid inputs and operators
- Detects division and modulus by zero

### ✔ Addition & Subtraction
- Handles all sign combinations
- Correct carry and borrow propagation
- Supports very large integers
- Removes leading zeros automatically

### ✔ Multiplication
- Digit-by-digit multiplication
- Handles large numbers with multiple carry chains
- Correct sign handling

### ✔ Division (with Decimal Precision)
- Integer and fractional division
- Configurable decimal precision
- Handles large divisors safely
- Prevents infinite loops

### ✔ Modulus Operation

- Computes remainder for large numbers

- Consistent sign handling

### ✔ Exponentiation

- Supports large powers

- Handles negative bases correctly

- Limits exponent size for safety

---
# 📂 Project Structure
├── main.c        - *Program flow and operator handling*

├── val.c         - *Input validation and number conversion*

├── operations.c  - *Utility functions (compare, free, helpers)*

├── add.c         - *Addition logic*

├── sub.c         - *Subtraction logic*

├── mul.c         - *Multiplication logic*

├── div.c         - *Division with decimal precision*

├── mod.c         - *Modulus operation*

├── pow.c         - *Power operation*

├── apc.h          - *Structs, macros, and function prototypes*

├── Makefile      - *Build automation*
---
# 🛠 Technologies Used

* C Language

* Doubly Linked Lists
* Dynamic Memory Management
* Modular Programming
* Makefile-based build system

---
# ▶️ How to Compile & Run
```
make
Run:
./apc <operand1> <operator> <operand2>

Examples:
./apc 999999999 + 1
./apc -16 / 4
./apc 2 ^ 10
./apc 1 / 3
```
---

# 📸 Sample Output
```
999999999 + 1 is 1000000000
1 / 3 is 0.33333
-5 + 5 is 0
```
---

# 📌 Future Enhancements

- Support for floating-point input
- Configurable decimal precision at runtime
- Performance optimizations for division
- Unit testing framework
- Interactive menu-based interface  
