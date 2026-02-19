# 🔧 Operating Environment v2.01 – Second Release

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Console](https://img.shields.io/badge/UI-Console%20ANSI-brightgreen)
![Status](https://img.shields.io/badge/Status-Archival-orange)

**The second public release of Operating Environment – now with an equation solver, persistent user login, and faster installation!**

*Building upon the foundation of v1.0, this release introduces a new application, better performance, and the beginnings of a proper installer system.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 What's New in v2.01](#-whats-new-in-v201)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**Operating Environment v2.01** is the second milestone in the project's evolution. Released after v1.0, it focuses on:

- **Adding a new application**: Pair of Linear Equations Solver.
- **Performance improvements**: Less resource‑hungry, faster program loading.
- **User experience**: Now only need to log in once per session.
- **Installer enhancements**: Installing applications takes less time.
- **Bootscreen**: A dedicated loading screen for the main environment.

This version still uses a single C++ file (though with more functions) and continues to rely on Linux system calls and ANSI escape sequences. It introduces persistent user data via simple text files, marking the beginning of a "registry" system.

## 🚀 What's New in v2.01

### ✨ New Application: Linear Equation Solver
- Solves two linear equations in two variables using the cross‑multiplication method.
- Handles different equation forms (e.g., `a1x + b1y + c1 = 0`, `a1x + b1y = c1`).
- Detects whether the equations have a unique solution, infinite solutions, or no solution (though this version only handles unique solutions – a bug?).

### 🔧 System Improvements
- **Single Login**: User credentials are saved in `file.txt` and `file2.txt`; you only need to log in once per session.
- **Faster Installation**: Apps are now "installed" by creating marker files (e.g., `file3.txt` for TicTacToe) – installation is nearly instantaneous.
- **Bootscreen**: A custom loading screen for the main environment (with a progress bar) before showing the login prompt.
- **Less Resource Hungry**: Code optimisations reduce CPU usage during idle loops.

### 🖥️ Shell Enhancements
- New command: `eqn_solve` – launches the linear equation solver.
- `inst_eqn_solve` – installs the equation solver (creates `solve.txt`).
- The guest mode (`ins==9`) now only allows `install` and `exit` commands, preventing guest users from accessing full features.

### 🔐 User Management
- User ID and password are stored in `file.txt` and `file2.txt`.
- Password change feature (via `change` as username) works, though it may have issues (see Known Issues).
- Guest mode introduced.

## 🖥️ Code Structure

The entire release is contained in **a single C++ file** (originally named `main.cpp`), but it has grown to approximately 2000+ lines. Key sections:

- **Global variables**: `ins`, `bs`, `v`, `board[]`, quiz scores, etc.
- **Equation solver**: `get_Eqn()`, `get_Side()`, `solve()`.
- **Installer function**: `installer()` – writes marker files based on `v` and `bs`.
- **Bootscreen**: `bootscreen()` – displays a different title depending on `bs`.
- **Login**: `login()` – handles user authentication and guest mode.
- **TicTacToe**: `computer_vs_player()`, `player_vs_player()` (same as v1.0 but with minor tweaks).
- **Quiz**: `printrndone()`, `printrndtwo()`, etc. (unchanged from v1.0).
- **Calculator & Temperature Converter**: unchanged.
- **Progress bar**: `pBar` class and `progressbar()` function.

Notable additions:
- `IP()` – installer procedure for the main environment (called when no user file exists).
- `Improvements()` – displays a changelog after installation.
- `password_change()` – allows user to change password (though it may not work correctly due to file handling).

## 📦 Building & Running

### Prerequisites
- Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v2.01 main.cpp
```

### Execution
```bash
./oe_v2.01
```

If no user file exists, the installer (`IP()`) will run and guide you through creating a user ID and password. After that, you'll see the login screen.

## 🔧 Technical Details

### File‑Based "Registry"
- User ID stored in `file.txt`.
- Password stored in `file2.txt` (plain text – not secure, but it's a hobby project).
- App installation status stored in:
  - `file3.txt` – TicTacToe
  - `file6.txt` – Quiz
  - `TC.txt` – Temperature Converter
  - `Calc.txt` – Calculator
  - `solve.txt` – Equation Solver

### Bootscreen Modes (`bs`)
- `bs=0` – Main OE bootscreen.
- `bs=1` – TicTacToe.
- `bs=2` – Quiz.
- `bs=3` – Temp Converter.
- `bs=4` – Calculator.
- `bs=6` – Equation Solver.

### Installer Variable `v`
- Used by `installer()` to determine which app is being installed and whether activation is needed (for TicTacToe and Quiz, activation keys are checked).

### Equation Solver Logic
- The solver calculates the determinant `n = A1*B2 - A2*B1`.
- If `n != 0`, it proceeds to `get_Side()` to adjust constant terms based on user input.
- The solution is then computed as `x = (B1*C2 - B2*C1)/n` and `y = (A2*C1 - A1*C2)/n`.
- The code attempts to handle cases where constants are on different sides, but there are bugs (see Known Issues).

### Timer Functions
- `timerO()`, `timerB()` – intended to count down during quiz questions, but in this version they are set to 0 seconds (a bug) – they don't actually limit time.

## 🐞 Known Issues

- **Equation solver**: The constant‑side handling is incomplete; it may produce wrong signs for `x` and `y`. The code prints `-1*x` and `-1*y` without clear reason.
- **Timer functions**: `timerO()` and `timerB()` have the countdown variable `a` set to 0, so they don't wait at all. (A leftover from debugging?)
- **Password change**: The `password_change()` function opens `file2.txt` but does not handle cases where the file doesn't exist; it may crash.
- **Guest mode**: After typing `install` in guest mode, the installer runs but then the program may not transition correctly to full user mode.
- **Progress bars**: Still hardcoded to stop at 25% in many places (same as v1.0).
- **Mixed use of `printf` and `cout`** can cause formatting issues.
- **No input validation** in many places – entering non‑numeric values where numbers are expected may cause infinite loops.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
v2.01 was developed shortly after v1.0, incorporating feedback and adding new features. The equation solver was a direct result of a school math project. This version also marks the first attempt at a persistent user system and a rudimentary installer – ideas that would be greatly expanded in later releases.

---

<div align="center">

*From a simple quiz app to a growing environment – each release adds a new layer of complexity.*

</div>
