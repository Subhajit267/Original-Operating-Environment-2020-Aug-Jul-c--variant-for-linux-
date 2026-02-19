# 🔧 Operating Environment v3.0 – Third Release

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Console](https://img.shields.io/badge/UI-Console%20ANSI-brightgreen)
![Status](https://img.shields.io/badge/Status-Archival-orange)

**The third major release of Operating Environment – now with difficulty levels, a hidden registry editor, cheat codes, and a completely revamped quiz!**

*This version focuses on adding depth to existing applications, introducing power‑user tools, and hiding plenty of Easter eggs for curious explorers.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 What's New in v3.0](#-whats-new-in-v30)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
  - [Registry System](#registry-system)
  - [Bootscreens and State Variables](#bootscreens-and-state-variables)
  - [Equation Solver Enhancements](#equation-solver-enhancements)
  - [TicTacToe Difficulty](#tictactoe-difficulty)
  - [Quiz Updates](#quiz-updates)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**Operating Environment v3.0** is a feature‑packed release that builds on the foundation of v2.01. It introduces several highly requested features and hidden surprises:

- **Difficulty levels** in TicTacToe (Easy / Hard).
- A **Registry Editor** – a hidden tool for power users to manage app installation, user accounts, and system settings.
- **Cheat codes** in TicTacToe and Quiz.
- **Equation solver** now detects whether equations have unique, infinite, or no solutions.
- **New quiz questions** and improved bonus round handling.
- A new **bootscreen and login screen** with a fancy ASCII logo.
- **Uninstall commands** for all applications.
- **Faster installation** and many bug fixes.

The codebase has grown to approximately 2500 lines and is still a single C++ file, but with more modular functions and clearer separation of concerns. The “registry” (simple text files) is now used consistently to track installation status, and global variables like `bs`, `v`, `reg` control the behaviour of bootscreens and installers.

## 🚀 What's New in v3.0

### 🎮 TicTacToe
- **Difficulty selection**: Easy (random moves) or Hard (uses win/block logic, with a massive `if-else` tree).
- **Cheat code**: Typing `w` as a move instantly wins the game (a developer leftover).

### 🕹️ Registry Editor (`reg_edit`)
- A hidden command (accessed by typing `reg_edit` at the password prompt or during IP) that gives access to:
  - `install` – install all apps.
  - `add_key` – install only TicTacToe and Quiz.
  - `temp` – temporarily run TicTacToe or Quiz without installation.
  - `user` – add a new user or reset password.
  - `reset` – uninstall all apps.
  - `clear`, `help`, `exit`.
- This is the first step toward a true system configuration tool.

### 📝 Quiz
- **New questions** (updated set covering history, science, and general knowledge).
- Bonus round logic improved.
- Cheat sheet accessible via the `cheatcode()` function (triggered by pressing 'c' at the start screen).
- Easter egg: pressing 'i' shows `about()`, 'e' shows `evaluator()`.

### 🧮 Equation Solver
- Now correctly identifies:
  - Unique solution (`A1*B2 != A2*B1`)
  - Infinite solutions (`A1/A2 == B1/B2 == C1/C2`)
  - No solution (`A1/A2 == B1/B2 != C1/C2`)
- Improved constant‑side handling with user prompts.

### 🖥️ Shell Enhancements
- New commands: `unst_<app>` to uninstall any app.
- `inst_all` installs all apps except TicTacToe and Quiz (which require a product key).
- `change` – password change wizard.
- `guess_it` – Easter egg that displays the source code (same as v2.01).
- Bootscreen now uses a `state` variable to adjust progress bar position.

### 🔐 User Management
- Password change wizard (`password_change()`) now properly handles cases where no password file exists.
- Guest mode (`ins==9`) now allows only `install` and `exit`, but with a funny triple‑check for `reg_edit` (see Known Issues).

### 🎨 UI Improvements
- A proper `layout()` function draws a fancy border and title.
- `logo()` draws an ASCII art logo.
- Bootscreen for each app with a consistent progress bar.

## 🖥️ Code Structure

The entire release remains in a **single C++ file** (originally named `main.cpp`), but functions are better organised:

- **Global variables**: `board[]`, quiz scores (`a1..a4`, `b1..b4`, `bo1..bo8`), `reg`, `v`, `bs`, `ins`, `mode`, `Difficult`, etc.
- **TicTacToe functions**: `selector_t()`, `computer_vs_player()`, `player_vs_player()`, `get_computer_choice_e()`, `get_computer_choice_h()`.
- **Quiz functions**: `printrndone()` to `printrndfour()`, `scrbrd()`, `scr()`, `about()`, `evaluator()`, `cheatcode()`.
- **Equation solver**: `get_Eqn()`, `get_Side()`, `solve()` with improved logic.
- **Registry editor**: `reg_edit()` – a full interactive sub‑shell.
- **Installer**: `installer()`, `activation()` for key‑protected apps.
- **Bootscreen and UI**: `bootscreen()`, `layout()`, `logo()`, `progressbar()`.
- **User management**: `login()`, `add_user()`, `password_change()`.
- **Main shell**: `prompt()` – now with many new commands.

## 📦 Building & Running

### Prerequisites
- Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v3.0 main.cpp
```

### Execution
```bash
./oe_v3.0
```

If no user file exists, the installer (`IP()`) will run, guiding you through user creation and showing the new features.

## 🔧 Technical Details

### Registry System
- Installation status stored in text files:
  - `TicTacToe.txt` – for TicTacToe
  - `Quiz.txt` – for Quiz
  - `TC.txt` – Temperature Converter
  - `Calc.txt` – Calculator
  - `solve.txt` – Equation Solver
- Each file contains a single integer (`reg`): `1` = installed, `0` = not installed.
- The `installer()` function writes `1` to the appropriate file (after activation for TicTacToe and Quiz).

### Bootscreens and State Variables
- `bs` (bootscreen) determines which title to show and where to place the progress bar.
- `state` is used in `progressbar()` to adjust the cursor position (1 for main OE, 0 for others).
- `v` (version) is used by `installer()` to know which app is being installed and whether activation is required.

### Equation Solver Enhancements
The solver now includes checks for:
- `A1*B2 != A2*B1` → unique solution.
- `A1/A2 == B1/B2 && A1/A2 == C1/C2` → infinite solutions (coincident lines).
- `A1/A2 == B1/B2 && A1/A2 != C1/C2` → no solution (parallel lines).

### TicTacToe Difficulty
- **Easy mode**: `get_computer_choice_e()` – random move.
- **Hard mode**: `get_computer_choice_h()` – a massive 200+ line `if-else` tree that checks all winning/blocking possibilities and then falls back to center, corners, or sides. It's not minimax, but it works.

### Quiz Updates
- Questions changed (e.g., “Who was the first propaganda minister of Hitler?” → Goebbels; “Conio.h refers to” → both a and b; “Who discovered neutron?” → James Chadwick; “Who discovered electron?” → J.J. Thompson).
- Bonus round still works the same way.
- The start screen now includes a credit to the quiz master (still Subhajit Halder).

## 🐞 Known Issues

- **Registry editor access**: In guest mode, typing `reg_edit` three times in a row finally opens it – this is a weird leftover from debugging.
- **Timer functions**: `timerO()` and `timerB()` still have `a = 0`, so they don't actually count down. The messages appear but no real timeout.
- **Password change**: Works but still stores passwords in plain text.
- **Uninstall commands**: They set the registry file to `0`, but do not remove any other data.
- **Progress bars**: Still hardcoded to stop at 25% (same as before).
- **Cheat code in TicTacToe**: Typing `w` as a move wins instantly, but it also corrupts the board state (the board is set to a predetermined pattern). It's a fun cheat but not intended for normal play.
- **Missing input validation**: Entering non‑numeric values where numbers are expected can cause infinite loops or crashes.
- **Equation solver**: The sign handling in `get_Side()` is still a bit confusing; it works for most cases but may produce wrong signs for some equation forms.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
v3.0 represents a major leap in complexity and user experience. The registry editor was inspired by Windows Registry and became a sandbox for experimenting with system‑level ideas. Cheat codes were added at the suggestion of a friend (Ritabrata Saha) and remain as hidden gems for those who explore. This version also laid the groundwork for the even more advanced v4.x releases.

---

<div align="center">

*With every release, the environment grows – now with secrets waiting to be uncovered.*

</div>
