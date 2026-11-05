# C Practices

A structured collection of C programming exercises that build from the language fundamentals to a complete, interactive console application. Each program is self-contained and focuses on a specific concept, making the repository easy to study, run, and extend.

![Language](https://img.shields.io/badge/language-C-blue)
![Programs](https://img.shields.io/badge/programs-52-brightgreen)
![Level](https://img.shields.io/badge/level-beginner%20to%20intermediate-orange)

## Table of Contents

- [Overview](#overview)
- [Topics Covered](#topics-covered)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
- [Program Index](#program-index)
- [Capstone Project](#capstone-project)
- [Reference Material](#reference-material)
- [Notes and Conventions](#notes-and-conventions)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

## Overview

This repository documents a hands-on path through C programming. The numbered exercises (`p1.c` through `p49.c`) follow a course sequence, starting with variables, input/output, and operators before moving on to conditionals, loops, functions, and a final price-calculator application.

The goal is not just to collect working code, but to show how individual language features combine into larger programs. Every file is standalone and contains its own `main()` function.

## Topics Covered

- Program structure and the `main()` entry point
- Variables, data types, and format specifiers
- Console input and output with `printf` and `scanf`
- Arithmetic, relational, logical, and assignment operators
- Operator precedence and type casting
- Conditional statements: `if`, `else if`, `else`, `switch`, and the ternary operator
- Loops: `for`, `while`, and `do-while`
- Loop control with `break` and `continue`
- Function declarations, definitions, parameters, arguments, and return values
- Defensive input validation and modular program design
- Structures, arrays of structures, and formatted receipt output

## Repository Structure

```text
.
├── Hello.c              # First program: Hello, World!
├── hey.c                # Console output practice
├── sum.c                # Multiplication practice with user input
├── p1.c … p49.c         # Numbered exercise set (see Program Index)
├── C Notes/             # Chapter-wise reference material (ZIP archives)
└── README.md
```

## Getting Started

### Requirements

- A C compiler such as GCC, Clang, or MSVC
- A C11-compatible compiler is recommended
- No third-party libraries are required

On Windows, GCC is available through [MinGW-w64](https://www.mingw-w64.org/) or [MSYS2](https://www.msys2.org/). On Linux and macOS, GCC or Clang is typically available by default.

### Compile and Run

Each program is independent. Compile only the file you want to run.

**Linux / macOS**

```bash
gcc p1.c -o p1
./p1
```

**Windows (PowerShell)**

```powershell
gcc p1.c -o p1
.\p1.exe
```

Replace `p1.c` with any other exercise, for example:

```bash
gcc p49.c -o p49
./p49
```

## Program Index

### Fundamentals

| File | Description |
| --- | --- |
| `Hello.c` | Prints `Hello World` to the console. |
| `hey.c` | Demonstrates multiple `printf` calls on separate lines. |
| `p1.c` | Declares variables of different types and prints them with format specifiers. |
| `p2.c` | Reads an integer with `scanf` and echoes it back. |
| `p3.c` | Calculates the area of a square from a user-supplied side length. |
| `p4.c` | Calculates the area of a circle from a user-supplied radius. |
| `p5.c` | Evaluates an arithmetic expression using floating-point variables. |
| `p6.c` | Compares floating-point division with integer modulus. |
| `p7.c` | Demonstrates explicit type casting from `double` to `int`. |
| `p8.c` | Explores operator precedence in arithmetic expressions. |
| `sum.c` | Reads two integers and prints their product. |

### Operators and Expressions

| File | Description |
| --- | --- |
| `p9.c` | Demonstrates relational operators such as `==`, `>`, `<`, and `!=`. |
| `p10.c` | Demonstrates logical AND, OR, and NOT operators. |
| `p11.c` | Demonstrates compound assignment operators (`+=`, `*=`, `/=`, `-=`, `%=`). |
| `p12.c` | Checks whether a number is even and performs integer division. |
| `p13.c` | Checks for even or odd values using a boolean expression. |
| `p14.c` | Combines boolean flags with the logical OR operator. |
| `p15.c` | Validates whether a number lies between 9 and 1000. |
| `p16.c` | Validates whether a number lies between 9 and 100. |
| `p26.c` | Distinguishes pre-increment from post-increment. |
| `p27.c` | Distinguishes pre-decrement from post-decrement. |

### Conditionals

| File | Description |
| --- | --- |
| `p17.c` | Checks adult eligibility based on age. |
| `p18.c` | Assigns a grade from a percentage using an `if` / `else if` chain. |
| `p19.c` | Rewrites an age check with the ternary operator. |
| `p20.c` | Maps a number from 1 to 7 to a day of the week using `switch`. |
| `p21.c` | Uses nested conditions to classify a number as positive/negative and even/odd. |
| `p22.c` | Determines pass or fail from a marks value and rejects invalid input. |
| `p23.c` | Classifies a character as uppercase, lowercase, or a non-English letter. |

### Loops

| File | Description |
| --- | --- |
| `p24.c` | Repeats a greeting 100 times with a `for` loop. |
| `p25.c` | Prints the numbers from 1 to 100. |
| `p28.c` | Iterates over the alphabet and a range of floating-point values. |
| `p29.c` | Prints 1 through 5 with a `while` loop. |
| `p30.c` | Prints every number from 0 to a user-supplied limit. |
| `p31.c` | Prints 1 through 5 with a `do-while` loop. |
| `p32.c` | Computes the sum from 1 to `n` and prints a countdown. |
| `p33.c` | Combines a running sum and a reverse countdown in a single loop. |
| `p34.c` | Prints the first ten multiples of 2. |
| `p35.c` | Demonstrates early loop termination with `break`. |
| `p36.c` | Repeatedly reads numbers until an odd value is entered. |
| `p37.c` | Repeatedly reads numbers until a multiple of 7 is entered. |
| `p38.c` | Demonstrates skipping an iteration with `continue`. |
| `p39.c` | Prints the odd numbers from 5 to 50. |
| `p40.c` | Calculates the factorial of a user-supplied number. |
| `p41.c` | Prints the multiplication table of a number in descending order. |
| `p42.c` | Sums all integers between two bounds and validates the range. |

### Functions and Modular Design

| File | Description |
| --- | --- |
| `p43.c` | Declares, defines, and calls a function that prints a greeting. |
| `p44.c` | Organizes two related greetings into separate functions. |
| `p45.c` | Selects a language-specific greeting based on user input. |
| `p46.c` | Passes arguments to a function and returns the sum. |
| `p47.c` | Prints a multiplication table through a function with a parameter. |
| `p48.c` | Calculates a final price with 18% tax using pass-by-value. |
| `p49.c` | Capstone: an interactive shopping cart and price calculator. |

## Capstone Project

### Advanced Price Calculator (`p49.c`)

The final program brings together structures, arrays, functions, loops, conditionals, and input validation in a single console application.

Features:

- Adds up to 10 items to a shopping cart
- Captures item name, unit price, quantity, and discount percentage
- Supports a configurable tax rate with an 18% default
- Calculates base price, discount amount, taxable amount, tax, and final price per item
- Displays a cart summary and a formatted final receipt
- Validates numeric input and rejects invalid values without crashing

Run it with:

```bash
gcc p49.c -o p49
./p49
```

## Reference Material

The `C Notes/` directory contains chapter-wise ZIP archives used as supplementary study material. These files are reference notes only and are not required to compile or run any program.

## Notes and Conventions

- Files named `pN.c` follow the original course sequence; the numbering reflects learning order rather than difficulty.
- Every source file is self-contained and can be compiled independently.
- Early exercises use simplified input handling to keep the focus on the concept being demonstrated. `p49.c` shows a more defensive approach suitable for interactive programs.
- `a.exe` is a local build artifact produced by a previous compilation. It is not part of the source code and can be safely removed.

## Contributing

This repository is primarily a personal learning record, but suggestions and corrections are welcome. If you find an issue or have an improvement:

1. Open an issue describing the problem or suggestion.
2. Fork the repository, create a focused branch, and make your change.
3. Submit a pull request with a clear explanation of the update.

Please keep contributions consistent with the existing structure and naming conventions.

## License

No open-source license is currently included with this repository. The code is provided for educational and personal reference use. All rights remain with the author.

## Author

**Bidyut Paul**

- GitHub: [@imbidyutpaul](https://github.com/imbidyutpaul)
- Repository: [C-Practices](https://github.com/imbidyutpaul/C-Practices)
