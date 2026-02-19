
# 🛠️ Operating Environment v4.05.11 – Under‑development Build

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Status](https://img.shields.io/badge/Status-Experimental-red)
![Build](https://img.shields.io/badge/Build-4.05.11--DEV-orange)

**A development snapshot following the v4.05.08 stable release – includes early work on a color customization wizard and UI refinements.**

*This build is part of the under‑development series and may contain incomplete features or bugs.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [🚀 What's New in v4.05.11 (DEV)](#-whats-new-in-v40511-dev)
- [🖥️ Code Structure](#️-code-structure)
- [📦 Building & Running](#-building--running)
- [🔧 Technical Details](#-technical-details)
  - [Color Change Wizard (Non‑functional)](#color-change-wizard-non-functional)
  - [Updated Logo](#updated-logo)
  - [Border Customization via `looks.h`](#border-customization-via-looksh)
  - [Registry Editor & Settings](#registry-editor--settings)
- [🐞 Known Issues](#-known-issues)
- [👨‍💻 Developer](#-developer)

## 🌟 Overview

**v4.05.11** is an experimental development build created after the stable v4.05.08 release. It focuses on introducing a **color change wizard** for personalizing the environment’s border, along with minor UI tweaks. However, the color wizard is **currently non‑functional** – it exists as a stub in the code and is not yet hooked up to actually change colors. This build is preserved to document the early stages of that feature and to show the ongoing evolution of the project.

All existing features from v4.05.08 remain present (quadratic solver, settings app, Kelvin support, registry editor, etc.), but with some modifications and the addition of an incomplete customization option.

## 🚀 What's New in v4.05.11 (DEV)

### 🎨 (Attempted) Color Change Wizard
- A new option **7** appears in the Settings menu: *“Change border colors.”*
- Selecting it calls a stub function `color_change()` which simply prints a menu and waits for input – **no actual color change occurs**.
- The function is intended to modify the `border` macro defined in `looks.h`, but this functionality is not implemented.

### 🖼️ Updated Logo
- The ASCII art logo displayed during login and boot has been redesigned with multiple colors (red, blue, yellow, green).
- The new logo adds a more polished look to the environment.

### 🧩 Border Customization via `looks.h`
- The main `layout()` function now reads the border color from `looks.h` (which contains `#define border "\x1B[100m"` – a grey background).
- This separation suggests future plans to allow dynamic border color changes by rewriting `looks.h` (similar to the earlier color‑change mechanism in v4.05.08, but now more modular).

### 🐛 Other Tweaks
- The `Improvements()` function in `sources.h` has been heavily commented out, leaving only one line mentioning the new (non‑functional) color wizard. This indicates that the developer was in the middle of updating the changelog.
- Minor code cleanup and formatting adjustments.

## 🖥️ Code Structure

The codebase remains split across the same files as v4.05.08, with a few additions:

- **`looks.h`** – Now solely defines the `border` macro (was previously used for multiple borders in earlier versions).
- **`sources.h`** – Contains the stub `color_change()` function and an updated `Improvements()` with commented‑out old entries.
- **`Sources2.h`** – The `settings()` function now includes option `7` calling `color_change()`.
- **`main.cpp`** – Version string updated to `4.05.11(DEV)`.

All other application code (TicTacToe, Quiz, calculators, equation solvers, registry editor) remains unchanged from v4.05.08.

## 📦 Building & Running

### Prerequisites
- Linux environment (or any system with a terminal that supports ANSI escape sequences).
- `g++` compiler.

### Compilation
```bash
g++ -o oe_v4.05.11 main.cpp
```

### Execution
```bash
./oe_v4.05.11
```

If no user file exists, the installer (`IP()`) will guide you through user creation.

## 🔧 Technical Details

### Color Change Wizard (Non‑functional)
- The function `color_change()` in `sources.h` currently only prints a static menu and calls `getchar()`.
- It does **not** modify any files or change the actual border color.
- The intended mechanism (rewriting `looks.h`) is not implemented, making this feature a placeholder.

### Updated Logo
- The `logo()` function now uses multiple color macros (`RED`, `blue`, `yellow`, `green`) to draw a stylized “OE” logo.
- Example snippet:
  ```cpp
  cout<<RED<<bold<<" ======================== "<<cc;
  cout<<RED<<bold<<"|"<<blue<<bold<<"   --------    -------"<<RED<<bold<<"  |"<<cc;
  // ... etc.
  ```

### Border Customization via `looks.h`
- The `layout()` function now uses the `border` macro from `looks.h` to draw the top/bottom lines and side borders.
- This decouples the border color from the main code, making it easier to change in the future (e.g., by providing a configuration file).

### Registry Editor & Settings
- The registry editor and settings panels are unchanged, but the settings menu now includes the new (non‑functional) option 7.
- Guest mode (`ins==9`) still works as before.

## 🐞 Known Issues

- **Color change wizard does nothing** – Selecting option 7 in settings only displays a menu; no actual color change occurs.
- **Uninstall commands** still have bugs (e.g., `unst_Temp_Conv` mistakenly writes to `TicTacToe.txt`).
- **Progress bar** positioning: the `state` variable is used but both branches of the `if` set the same coordinates (55,22), so no actual variation.
- **Timer functions** (`timerO`, `timerB`) work, but the beeping at 5 seconds may be excessive.
- **Missing input validation** in many places – entering non‑numeric values where numbers are expected can cause infinite loops or crashes.
- **Incomplete `Improvements()`** – the function now only shows one line, which may confuse users expecting a full changelog.

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

![Profile](https://img.shields.io/badge/Developer-Subhajit_Halder-blue?style=for-the-badge)

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

**Project Background**:  
This development build represents a moment in time where the focus shifted toward user personalization. The color change wizard was envisioned to allow users to customize the environment’s appearance, but it remained unfinished. The updated logo and the separation of border definition into `looks.h` are steps toward that goal. Future builds would likely complete this feature and refine the UI further.

---

<div align="center">

*An experimental step toward a more customizable Operating Environment – even if the colors haven't changed yet.*

</div>
