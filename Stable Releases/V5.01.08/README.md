
---

# 🔧 Operating Environment v5.01.08 – Linux C++ Final Release

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B\&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux\&logoColor=white)
![Status](https://img.shields.io/badge/Status-Stable%20%7C%20Final-brightgreen)
![Release Date](https://img.shields.io/badge/Release%20Date-19%20Feb%202026-orange)

**The culmination of the original Linux C++ lineage — a fully featured console-based “operating environment” with multiple applications, user management, registry system, and hidden features.**

</div>

---

## 📌 Overview

**Operating Environment** began as a simple quiz application during online classes and gradually evolved into a full console-based environment.

It mimics several operating system concepts:

* Command shell
* User accounts
* Application registry system
* Settings panel
* Hidden registry editor

All applications are built-in and written in pure **C++ (with some C-style I/O)**.

This release, **v5.01.08**, marks the **final stable version of the original Linux C++ codebase**.

Future development will continue in separate repositories:

* Windows port
* `oe-reboot` (clean-slate architecture rewrite)

---

## ✨ What's New in v5.01.08

Compared to previous versions (v4.23.09 and earlier):

* ✅ Fixed uninstall command mis-targeting registry files
* ✅ Full numeric input validation across apps
* ✅ Progress bar now reaches 100% smoothly
* ✅ Area of Triangle fully integrated (`ATC.txt`)
* ✅ `inst_all` correctly installs all supported apps
* ✅ Registry editor duplicate reset block removed
* ✅ Unified version string (`5.01.08`)
* ✅ Timer functions now return `void`
* ✅ Guest mode simplified
* ✅ Code cleanup and file handling improvements

This version is **stable and fully functional**.

---

## 🖥️ System Features

### 👤 User Management

* Login with password
* Guest mode
* Password change
* User ID change
* Password removal (set to `0`)

### 📁 Registry System

Each app has a registry file:

```
TicTacToe.txt → contains 1 (installed) or 0 (not installed)
```

Installer and registry editor modify these files.

### 🛠️ Registry Editor

Hidden power-user tool:

* Install/uninstall apps
* Temporary app execution
* Reset system
* Admin mode access

### ⚙️ Settings Panel

Three sub-panels:

* **User Accounts**
* **Reset & Restore**
* **Personalization (Border colour, 16 options)**

Color changes modify `looks.h` and restart the system.

### 🖥️ Boot Screens

Each application has a loading screen with a progress bar.

### 👥 Guest Mode

Limited commands:

```
install
login
exit
```

---

## 🎮 Built-in Applications

| Application                   | Command(s)                            | Description                                                     |
| ----------------------------- | ------------------------------------- | --------------------------------------------------------------- |
| **TicTacToe**                 | `TicTacToe`, `tictactoe`, `TICTACTOE` | PvP / Computer (Easy/Hard). Cheat: `w`                          |
| **Quiz**                      | `Quiz`, `QUIZ`, `quiz`                | 2-player quiz, 8 rounds, scoreboard. Cheats: `i`, `e`, `c`, `z` |
| **Calculator**                | `Calculator`, `calculator`            | Simple arithmetic parser                                        |
| **Temperature Converter**     | `Temp_Conv`, `temp_conv`              | C ↔ F ↔ K                                                       |
| **Linear Equation Solver**    | `eqn_solve`                           | Solves two equations (cross multiplication)                     |
| **Quadratic Equation Solver** | `quad_eqn_solve`                      | Solves ax²+bx+c=0                                               |
| **Area of Triangle**          | `ar(t_c)`                             | Area from coordinate pairs                                      |

Each app has:

```
inst_<app>
unst_<app>
```

`inst_all` installs all except TicTacToe and Quiz (require keys).

---

## 🕹️ Hidden Features & Easter Eggs

* `registryeditor` → open registry editor
* `guess_it` → display source
* `start_admin_reg_edit` → admin mode
* `temp TTT` / `temp quiz` → temporary run
* `whoami` → show username
* `display_source` → dump source file
* Quiz cheat: `z` → instant round win

---

## 📁 File Structure

```
OperatingEnvironment/

├── main.cpp
├── sources.h
├── Sources2.h
├── programs.h
├── looks.h
├── file.txt
├── file2.txt
├── *.txt (registry files)
├── file3.txt / file6.txt (activation keys)
```

Registry files contain:

```
1 → Installed
0 → Not installed
```

---

## 🛠️ Building & Running

### Requirements

* Linux terminal
* `g++` (C++11+)

### Compile

```bash
g++ -o oe main.cpp -std=c++11
```

### Run

```bash
./oe
```

---

## 🐞 Known Issues

* Progress bar pause at 25% (cosmetic)
* Some uninstall commands may require verification
* Extremely long input may overflow buffers
* Timer beep may be annoying
* Color change requires restart
* Live clock feature incomplete

---

## 🚧 Experimental: Live Clock

An experimental branch attempted a real-time clock using:

* `select()` non-blocking input
* Raw terminal mode
* 100ms polling

### What Works

* Clock updates when idle
* Basic input works

### Issues

* Conflicts with `cin`
* Cursor glitches
* Complex integration

The feature is preserved in:

```
underdev-live-clock
```

It is not stable and not recommended for regular use.

Future integration planned for `oe-reboot`.

---

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder**

📧 [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

---

## 🕰️ Project Timeline

* v1.0 — First release (2020)
* v2.01 — Linear solver, bootscreen
* v3.0 — Registry editor, difficulty modes
* v4.05.08 — Quadratic solver, settings app
* v5.01.08 — Final stable release

---

<div align="center">

*This version marks the end of the original Linux C++ journey. Future development continues in Windows ports and the `oe-reboot` project.*

</div>

---
