# 🔧 Operating Environment v1.0 – First Release

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Console](https://img.shields.io/badge/UI-Console%20ANSI-brightgreen)
![Status](https://img.shields.io/badge/Status-Archival-orange)

**The very first public release of Operating Environment – a console‑based “mini OS” built from scratch during online classes (circa 2020).**

*Four built‑in applications, a simple command shell, and the beginning of a hobby project that would grow over several years.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 Features](#-features)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**Operating Environment v1.0** is the first milestone of a project that started as a simple quiz app for online classes and quickly expanded into a full‑fledged console environment. This release includes:

- A **command shell** with a few built‑in commands.
- Four **applications**: Tic‑Tac‑Toe, Quiz, Calculator, and Temperature Converter.
- Basic **user interaction** – no persistent user accounts yet (that came later).
- A single‑file C++ codebase (approximately 1500 lines) with everything mixed together – a true reflection of early hobby programming.

The code is written in C++ and uses Linux system calls (`system("clear")`, `usleep`) and ANSI escape sequences for colours and cursor positioning. No external libraries are used.

## 🚀 Features

### 🎮 Built‑in Applications

| Application | Description |
|-------------|-------------|
| **Tic‑Tac‑Toe** | Two‑player mode on a 3×3 grid. Simple win detection. |
| **Quiz** | A 8‑question quiz with multiple choice, score tracking, and bonus rounds. |
| **Calculator** | Performs arithmetic with three operators (e.g., `5+3*2`). |
| **Temperature Converter** | Converts between Celsius and Fahrenheit. |

### 🖥️ Shell Commands

- `help` – Displays available commands.
- `TicTacToe` / `tictactoe` – Launches the game (checks for installation? Actually v1.0 doesn't have a real installation system – all apps are always available).
- `Quiz` / `quiz` – Launches the quiz.
- `Temp_Conv` / `temp_conv` – Launches temperature converter.
- `Calculator` / `calculator` – Launches calculator.
- `inst_<app>` – Placeholder for installation commands (not fully implemented in v1.0).
- `exit` – Exits the environment.

### 🔐 Hidden / Easter Egg Features

- **`admin`** as a username in the Quiz login gives access to the source code display (`source()`).
- **`CHANGE`** as a username triggers a password change (though passwords aren't persistent in this version).
- **Cheat codes**: In TicTacToe, typing `w` during move selection instantly wins the game (a developer shortcut).

## 🖥️ Code Structure

The entire release is contained in **a single C++ file** (originally named `main.cpp`). It follows a linear, monolithic style:

- Global variables for game state (`board[]`, quiz scores, etc.).
- Function definitions for each feature (often hundreds of lines long).
- A main `prompt()` loop that reads commands and dispatches via `if-else`.
- No separation of headers and implementation – everything is in one place.

Key functions:
- `prompt()` – Main shell loop.
- `computer_vs_player()`, `player_vs_player()` – TicTacToe logic.
- `printrndone()`, `printrndtwo()`, etc. – Quiz rounds.
- `calc()` – Calculator.
- `tc()` – Temperature converter.
- `gotoxy()` – Manual cursor positioning using ANSI escapes.

## 📦 Building & Running

### Prerequisites
- A Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v1.0 main.cpp
```

### Execution
```bash
./oe_v1.0
```

The program will start with a blank screen and a command prompt. Type `help` to see available commands.

## 🔧 Technical Details

- **Language**: C++ (with some C‑style I/O using `printf` and `cout` mixed).
- **Console Control**: ANSI escape sequences for colours, cursor movement (`\033[<row>;<col>H`), and clearing.
- **Timing**: `sleep()` and `usleep()` for delays.
- **Randomness**: `std::rand()` seeded with `time(NULL)` for progress bars and computer moves.
- **Quiz Scoring**: Uses global variables to accumulate scores across rounds; bonus questions add extra points.

### Interesting Code Snippets

#### Custom `gotoxy`
```cpp
void gotoxy(int x,int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}
```

#### TicTacToe Win Cheat
```cpp
if ((char)choice_a == 'w') {
    board[1] = board[4] = board[7] = board[2] = board[3] = 'X';
    board[0] = board[6] = board[8] = board[5] = 'O';
    // ... immediately show win
}
```

#### Quiz Bonus Round Handling
The quiz code includes complex nested `switch` statements to handle correct, wrong, and unattempted answers, plus optional bonus questions.

## 🐞 Known Issues

- The installation commands (`inst_*`) are stubs – they run installers even if the app is already “installed” (no persistent registry in this version).
- The password change feature (`CHANGE`) does not persist between runs because user data is not saved to disk.
- Progress bars are hardcoded to stop at 25% (a debugging leftover).
- The code contains many unused variables and commented‑out sections.
- Mixing of `printf` and `cout` can cause occasional formatting glitches.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
This version was written during the COVID‑19 lockdown when online classes left plenty of time for experimentation. Starting as a quiz app requested by a teacher, it quickly grew into a larger environment. The code reflects a beginner's enthusiasm – it's messy, but it works, and it laid the foundation for all future releases.

---

<div align="center">

*Every journey begins with a single step – this is the first step of the Operating Environment saga.*

</div>
