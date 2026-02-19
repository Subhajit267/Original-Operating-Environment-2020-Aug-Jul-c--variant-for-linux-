
# 🛠️ Operating Environment v4.23.09 – Under‑development Build

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Status](https://img.shields.io/badge/Status-Experimental-red)
![Build](https://img.shields.io/badge/Build-4.23.09--DEV-orange)

**A major development snapshot introducing a new geometry application, a vastly improved color customization panel, and a completely reorganized settings menu.**

*This build represents a significant leap forward in both functionality and user experience, paving the way for the next stable release.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 What's New in v4.23.09 (DEV)](#-whats-new-in-v42309-dev)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
  - [New Application: Area of Triangle (Coordinates)](#new-application-area-of-triangle-coordinates)
  - [Enhanced Color Changer](#enhanced-color-changer)
  - [Modular Settings Menu](#modular-settings-menu)
  - [Other Improvements](#other-improvements)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**v4.23.09** is the most advanced under‑development build in the 4.x series. It introduces a brand new application for calculating the area of a triangle given its vertices, a complete overhaul of the color customization feature with 16 color options, and a fully modular settings menu divided into logical sub‑panels. The codebase has been further refined, with better organization and many small usability improvements.

All existing features from previous versions (quadratic solver, Kelvin support, registry editor, TicTacToe, Quiz, etc.) remain intact and have been integrated into the new settings structure.

## 🚀 What's New in v4.23.09 (DEV)

### 🆕 New Application: Area of Triangle (Coordinates)
- Command: `ar(t_c)` – calculates the area of a triangle using the shoelace formula.
- Takes three coordinate pairs (x,y) as input and outputs the absolute area.
- Installer: `inst_ar(t_c)` – creates `ATC.txt` registry file.
- Uninstaller: `unst_ar(t_c)` – removes the registry entry.
- Bootscreen mode `bs=8` and installer variable `v=8`.

### 🎨 Enhanced Color Changer
- The color customization wizard (`color_change()`) now offers **16 different background colors** for the main layout border.
- A stylish table displays each color name alongside a live sample using the predefined macros `B1`…`B15`.
- User can choose by entering a number (1‑16) or press `e` to exit.
- The selection is saved by rewriting the `looks.h` header file with the corresponding ANSI escape code.
- After saving, the program automatically restarts to apply the new color (by exiting with a message).

### ⚙️ Modular Settings Menu
- The monolithic `settings()` function has been split into three dedicated sub‑panels:
  - **USER ACCOUNTS** – change password, change user ID.
  - **RESET AND RESTORE** – reset all applications, reinstall the system.
  - **Personalization** – change border color (calls the enhanced color changer).
  - **HELP** – displays documentation.
  - **EXIT** – returns to the main shell.
- Each sub‑panel is implemented in its own function (`USER_ACCOUNTS()`, `RESET_AND_RESTORE()`, `PERSONALIZATION()`) for better code organization.

### 🖥️ Shell Enhancements
- New command: `whoami` (or `list_ID`) – displays the current logged‑in username.
- The `ver` command now shows `4.23.09(DEV)`.
- Guest mode messages have been slightly reworded for clarity.
- The progress bar now uses `'-'` and `'_'` characters instead of `'='` and `'>'`, giving a different visual style.

### 🧩 Registry Editor
- The registry editor (`reg_edit`) remains largely unchanged but now includes the ability to start in admin mode via `start_admin_reg_edit` (hidden command).
- The `temp` command now allows running TicTacToe or Quiz in trial mode for non‑admin users.

### 🐛 Bug Fixes & Improvements
- The color changer no longer has the recursive call bug – it properly exits the program after saving.
- The `unst_ar(t_c)` command correctly writes to `ATC.txt` instead of misusing `TicTacToe.txt` (unlike some older uninstall commands that still have bugs).
- The `layout()` function now consistently uses the `border` macro, making color changes effective immediately after restart.
- Many small code cleanups and formatting improvements throughout.

## 🖥️ Code Structure

The codebase is split across the same files as before, with new functions added:

- **`main.cpp`** – entry point, `prompt()`, `IP()`, `reg_edit()`. Version string updated.
- **`programs.h`** – contains all application logic, including the new `atc()` function for area of triangle.
- **`sources.h`** – prototypes, utility functions (`gotoxy`, `progressbar`, `login`, `layout`), and the new modular settings functions: `USER_ACCOUNTS()`, `RESET_AND_RESTORE()`, `PERSONALIZATION()`. Also contains the enhanced `color_change()`.
- **`Sources2.h`** – `installer()`, `activation()`, `bootscreen()`, `printerror()`, `logo()`, `password_change()`, `timerS()`, `userid_change()`, `settings()` (now simplified).

The code is better organized, with clear separation of concerns. Global variables are still used extensively but are now declared in `sources.h`.

## 📦 Building & Running

### Prerequisites
- Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v4.23.09 main.cpp
```

### Execution
```bash
./oe_v4.23.09
```

If no user file exists, the installer (`IP()`) will guide you through user creation.

### Changing the Border Color
1. From the main shell, type `settings`.
2. Select **3) Personalization**.
3. Choose **1) Change your border color**.
4. Pick a color number from the displayed table (1–16) or press `e` to exit.
5. The program will save the new color and then exit. Restart the program to see the change.

## 🔧 Technical Details

### New Application: Area of Triangle (Coordinates)
- Implemented in `atc()`.
- Uses the formula:  
  `area = 0.5 * | x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) |`
- Prompts for three coordinate pairs and displays the absolute area.
- No error checking for collinear points (area will be zero).

### Enhanced Color Changer
- The function `color_change()` now displays a 16‑option menu with color samples.
- Each sample is shown using pre‑defined macros (`B1`…`B15`) that expand to ANSI background color codes.
- The user’s choice is mapped to an ANSI code and written to `looks.h`.
- After writing, the program prints a shutdown message and exits, forcing a restart to apply the change. This is a simple but effective way to make the new border color take effect.

### Modular Settings Menu
- The old monolithic `settings()` has been replaced by a top‑level menu that calls separate functions.
- `USER_ACCOUNTS()` handles password and user ID changes.
- `RESET_AND_RESTORE()` provides options to reset apps or reinstall the system.
- `PERSONALIZATION()` currently only offers color change, but could be extended.
- Each function uses `gotoxy` for consistent screen positioning.

### Other Improvements
- The `progressbar()` function now uses `'-'` for filled portion and `'_'` for the current position, giving a different aesthetic.
- The `whoami` command simply outputs the current username stored in `name1`.
- Guest mode now correctly allows `login` to switch to a real user.

## 🐞 Known Issues

- **Uninstall commands** for older apps (`unst_Temp_Conv`, `unst_Calculator`, etc.) still mistakenly write to `TicTacToe.txt` instead of their own registry files. This bug persists from earlier versions.
- **Timer functions** (`timerO`, `timerB`) work, but the beeping at 5 seconds may be excessive.
- **Missing input validation** in many places – entering non‑numeric values where numbers are expected can cause infinite loops or crashes.
- **Progress bar** still hardcoded to stop at 25% (a debugging leftover) – it does not actually reach 100%.
- **The `inst_all` command** does not install the new Area of Triangle app (it was not added to the list).
- **The `unst_ar(t_c)` command** correctly uses `ATC.txt`, but other uninstall commands remain broken.
- **Color changer** requires a full program restart to take effect; there is no way to apply the change without exiting.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
v4.23.09 represents a culmination of many ideas and experiments. The new geometry app adds a practical tool, while the revamped settings menu makes the environment more user‑friendly. The color changer, now with 16 options, gives users true personalization. This build is a strong candidate for becoming the next stable release after some bug fixes, especially to the uninstall commands.

---

<div align="center">

*A giant leap toward a polished, feature‑rich operating environment – with colors to match your mood.*

</div>
