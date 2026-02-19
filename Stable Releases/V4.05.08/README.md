# 🔧 Operating Environment v4.05.08 – Fourth Release

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Console](https://img.shields.io/badge/UI-Console%20ANSI-brightgreen)
![Status](https://img.shields.io/badge/Status-Archival-orange)

**The fourth major release of Operating Environment – now with a quadratic equation solver, a full settings panel, Kelvin support, and a refined user experience!**

*This version focuses on expanding functionality, improving system management, and polishing the overall environment.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 What's New in v4.05.08](#-whats-new-in-v40508)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
  - [Registry System](#registry-system)
  - [Bootscreens and State Variables](#bootscreens-and-state-variables)
  - [Quadratic Equation Solver](#quadratic-equation-solver)
  - [Settings Application](#settings-application)
  - [User Account Improvements](#user-account-improvements)
  - [Temperature Converter with Kelvin](#temperature-converter-with-kelvin)
  - [Registry Editor Enhancements](#registry-editor-enhancements)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**Operating Environment v4.05.08** is the most feature‑rich release up to this point. Building on the foundation of v3.0, it introduces:

- **Quadratic Equation Solver** – solves `ax²+bx+c=0` with root type detection.
- **Settings Application** – a centralised panel for user accounts, system reset, and personalisation.
- **User Account Improvements** – change user ID, remove password, and more.
- **Temperature Converter** – now supports Kelvin directly.
- **System Restore** – option to reinstall the environment to fix errors.
- **Registry Editor Enhancements** – now accessible to normal users (limited mode) and includes new commands.
- **Brand New UI** – a polished layout with a border and improved visuals.
- **Many bug fixes and optimisations**.

The codebase has grown significantly, now split across multiple header and source files (`sources.h`, `Sources2.h`, `programs.h`). It remains in C++ but is better organised than previous versions.

## 🚀 What's New in v4.05.08

### 🧮 New Application: Quadratic Equation Solver
- Solves equations of the form `ax² + bx + c = 0`.
- Calculates discriminant and determines real/equal, real/unequal, or imaginary roots.
- Provides explanations for approximation differences.

### ⚙️ Settings Application
- Centralised menu accessible via the `settings` command.
- Sub‑panels:
  - **User Accounts** – change password, change user ID.
  - **Reset and Restore** – uninstall all apps or reinstall the entire environment.
  - **Personalisation** – change border color (by modifying `looks.h` and restarting).
- Help documentation built‑in.

### 🔐 User Account Improvements
- Password change wizard now supports removing password (set to `0`).
- User ID can be changed directly from settings.
- Guest mode still available with limited commands.

### 🌡️ Temperature Converter
- Now supports **Kelvin** (`K`) in addition to Celsius and Fahrenheit.
- Converts between all three units.

### 🛠️ Registry Editor Enhancements
- Normal users can now access a limited version of the registry editor (by typing `registryeditor` at the password prompt or in guest mode).
- Admin mode (full access) is still available via the installer or special commands.
- New commands: `prompt` (jump directly to main shell), `reset` (uninstall all apps), `user` (add new user or reset password), `add_key` (install TicTacToe and Quiz with admin rights).

### 🎨 UI Improvements
- A new `layout()` function draws a stylish border with a title bar.
- `logo()` displays an ASCII art logo.
- Bootscreens now use a consistent progress bar positioning.
- The main shell prompt now shows the version number prominently.

### 🧩 Other Enhancements
- **Installation system**: Apps now have dedicated registry files (`TicTacToe.txt`, `Quiz.txt`, `TC.txt`, `Calc.txt`, `solve.txt`, `quad_solve.txt`).
- **Uninstall commands** for all apps (e.g., `unst_quad_eqn_solve`).
- **Source code viewer** (`display_source`) – dumps the current source file.
- **Version command** (`ver`) shows the current build.
- **Improved error handling** with beeps and clearer messages.

## 🖥️ Code Structure

The code is now split into multiple files, making it easier to navigate (though still not fully modular). Key files:

- **`main.cpp`** – entry point, `prompt()` (main shell loop), `IP()` (installer procedure), `reg_edit()` (registry editor).
- **`sources.h`** – function prototypes, global variables, utility functions (`gotoxy`, `progressbar`, `login`, `layout`, `add_user`, `install`, `Improvements`, etc.).
- **`Sources2.h`** – `installer()`, `activation()`, `bootscreen()`, `printerror()`, `logo()`, `password_change()`, `timerS()`, `userid_change()`, `settings()`.
- **`programs.h`** – equation solvers (`get_Eqn`, `solve`, `quad_eqn_solve`), TicTacToe (`selector_t`, `computer_vs_player`, etc.), calculator (`calc`), temperature converter (`tc`), quiz (`printrndone` to `printrndfour`, `scrbrd`, `scr`, `about`, `evaluator`, `cheatcode`, `start`).

Global variables are still used extensively, but they are now declared in `sources.h` and referenced elsewhere.

## 📦 Building & Running

### Prerequisites
- Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v4.05.08 main.cpp
```

**Note:** The code uses multiple header files; they are included via `#include` directives, so only `main.cpp` needs to be compiled.

### Execution
```bash
./oe_v4.05.08
```

If no user file exists, the installer (`IP()`) will guide you through user creation and show the new features.

## 🔧 Technical Details

### Registry System
- Installation status stored in text files:
  - `TicTacToe.txt` – TicTacToe
  - `Quiz.txt` – Quiz
  - `TC.txt` – Temperature Converter
  - `Calc.txt` – Calculator
  - `solve.txt` – Linear Equation Solver
  - `quad_solve.txt` – Quadratic Equation Solver
- Each file contains a single integer (`reg`): `1` = installed, `0` = not installed.
- The `installer()` function writes `1` to the appropriate file (after activation for TicTacToe and Quiz).

### Bootscreens and State Variables
- `bs` (bootscreen) determines which title to show and where to place the progress bar.
- `state` is used in `progressbar()` to adjust the cursor position (1 for main OE, 0 for others).
- `v` (version) is used by `installer()` to know which app is being installed and whether activation is required.

### Quadratic Equation Solver
- Uses the quadratic formula: `x = (-b ± √(b² - 4ac)) / 2a`.
- Detects:
  - `d == 0` → real and equal roots.
  - `d > 0` → real and unequal roots.
  - `d < 0` → imaginary roots.
- Includes a note about approximation differences for non‑perfect squares.

### Settings Application
- Implemented in `settings()` (in `Sources2.h`).
- Options:
  1. **Change/Add/Remove Password** – calls `password_change()`.
  2. **Change USER‑ID** – calls `userid_change()`.
  3. **Reset** – sets all registry files to `0` (uninstalls all apps).
  4. **Re‑install the system** – calls `IP()` to rerun the initial setup.
  5. **Help** – displays documentation.
  6. **Exit** – returns to the main shell.
- Password removal: if user chooses not to keep a password, the password file is set to `"0"`.

### User Account Improvements
- **Password change** now handles the case where no password existed before.
- **User ID change** directly modifies `file.txt`.
- Guest mode (`ins==9`) still restricts commands, but now allows `login` to switch to a real user.

### Temperature Converter with Kelvin
- Added case `'K'` or `'k'`:
  - Converts Kelvin to Celsius (`temp - 273`), then to Fahrenheit.
- Improved formatting and messages.

### Registry Editor Enhancements
- Now two modes:
  - **Admin mode** (`reg_status==1`) – full access, entered during initial setup or via special commands.
  - **User mode** (`reg_status==0`) – limited commands (e.g., `install` without admin rights still works, but some features are restricted).
- New commands:
  - `prompt` – jump directly to the main shell.
  - `reset` – uninstall all apps (requires admin).
  - `user` – add new user or reset password (admin only).
  - `add_key` – install TicTacToe and Quiz (admin only).
- Help text available via `help`.

## 🐞 Known Issues

- **Timer functions**: `timerO()` and `timerB()` now have proper countdowns (15 and 10 seconds respectively), but the timing may be affected by `sleep(1)` precision.
- **Password file handling**: If the password file contains `"0"`, the login bypass works, but there is no confirmation prompt.
- **Uninstall commands**: Some `unst_*` commands mistakenly write to `TicTacToe.txt` instead of the correct file (e.g., `unst_Temp_Conv` opens `TicTacToe.txt`). This is a copy‑paste error and will cause incorrect uninstallation.
- **Registry editor**: In guest mode, the triple‑input trick to open `reg_edit` still exists (leftover from v3.0).
- **Progress bars**: Still hardcoded to stop at 25% in many places (a debugging leftover).
- **Missing input validation**: Entering non‑numeric values where numbers are expected can still cause infinite loops or crashes.
- **Quadratic solver**: Uses `pow(b,2)` – could be replaced with `b*b` for efficiency.
- **Layout function**: The border characters may not display correctly on all terminals (requires UTF‑8 support).

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
v4.05.08 represents a major leap in both functionality and polish. The addition of a settings panel, quadratic solver, and Kelvin support were direct responses to user feedback. The registry editor became more accessible, and the UI got a complete overhaul. This version laid the groundwork for even more advanced features in subsequent development builds.

---

<div align="center">

*Four releases in, the environment is becoming a truly versatile tool – with secrets still waiting to be uncovered.*

</div>
