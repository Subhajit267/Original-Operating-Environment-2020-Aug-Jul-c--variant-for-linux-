# 🧪 Operating Environment – Experimental Live Clock Build

<div align="center">

![C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux&logoColor=white)
![Status](https://img.shields.io/badge/Status-Experimental%20%7C%20Unstable-red)
![Based on](https://img.shields.io/badge/Base-v5.01.08-orange)

**An experimental fork of the final stable release (v5.01.08) featuring a real‑time updating clock and non‑blocking input with command history.**

*This build is a proof‑of‑concept and is **not stable** – use at your own risk!*

</div>

---

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [✨ New Features (Experimental)](#-new-features-experimental)
- [🖥️ How It Works](#️-how-it-works)
- [📦 Building & Running](#-building--running)
- [🐞 Known Issues & Limitations](#-known-issues--limitations)
- [📜 Comparison with Stable v5.01.08](#-comparison-with-stable-v50108)
- [👨‍💻 Developer](#-developer)

---

## 🌟 Overview

This experimental branch builds upon the final stable Linux C++ release (**v5.01.08**) and introduces a **live updating clock** displayed in the top border, along with **non‑blocking input** that allows the clock to keep ticking even while waiting for user commands. It also adds **command history** and arrow‑key navigation in the shell.

The goal was to make the environment feel more dynamic and responsive, similar to a modern terminal. However, integrating raw‑mode input with the existing application code (which relies heavily on `cin`) proved challenging, resulting in a number of instabilities.

**This code is provided as a reference and a starting point for future development (e.g., the `oe-reboot` project). It is not intended for daily use.**

---

## ✨ New Features (Experimental)

- **Live Clock** – Date and time displayed at (7,7) and (87,7) update every second, even while waiting for input.
- **Non‑blocking Input** – The shell uses `select()` with a 100 ms timeout, so the clock can be refreshed during idle moments.
- **Command History** – Press **Up** and **Down** arrow keys to recall previously entered commands.
- **Line Editing** – Backspace works immediately; characters are inserted as you type (no need to press Enter until you're done).
- **`waitForAnyKey()`** – Replaces all `getchar()` calls with a non‑blocking version that updates the clock while waiting.
- **Raw Mode** – The terminal is switched to raw mode during input, giving finer control over keypresses.

All other features from v5.01.08 (applications, registry editor, settings, etc.) are present, but many are **broken** due to raw mode conflicts.

---

## 🖥️ How It Works

- The terminal is put into **raw mode** (via `termios`) before any input is read.
- In the shell, `getStringWithTimeout()` loops every 100 ms, calling `updateDateTimeLine()` to refresh the clock, and checks for input using `select()`.
- When a key is pressed, it is processed (backspace, arrow keys for history, printable characters).
- The same pattern is applied to all input functions: `getIntWithClock`, `getDoubleWithClock`, `getCharWithClock`, `getTwoDoublesWithClock`, and `waitForAnyKey`.
- The clock is drawn at two fixed positions: (7,7) for the date and (87,7) for the time, using ANSI escape sequences.

---

## 📦 Building & Running

### Prerequisites
- Linux environment (or any terminal with ANSI escape support)
- `g++` compiler (C++11 or later)

### Compilation
```bash
g++ -o oe_experimental main.cpp -std=c++11
```

### Execution
```bash
./oe_experimental
```

The installer will run as usual. After installation, you'll be at the login screen. Log in (or use guest) and observe the clock ticking at the top. Try typing commands – you'll see that backspace and arrow keys work, and the clock continues to update.

---

## 🐞 Known Issues & Limitations

- **Raw mode conflicts with `cin`** – Many applications (TicTacToe, quiz, etc.) use `cin` internally, which does not play well with raw mode. Expect crashes, garbled input, or unexpected behaviour.
- **Cursor positioning may be off** – After some operations, the cursor may not return to the correct place.
- **`getValidOperator` still blocks** – The operator input in the calculator is still using standard `cin`, so the clock freezes while waiting for an operator.
- **Some `getchar()` calls remain in the code** (e.g., in `login()` for guest mode) – these were not all replaced.
- **The clock may overwrite parts of the UI** if the terminal is resized or if an application prints to those lines.
- **Not all edge cases are handled** – Entering extremely long input or rapidly pressing keys may cause buffer issues.
- **The code is messy** – This is a prototype; many functions have been modified in a hurry.

**In short: This build is for experimentation only. Do not rely on it for actual work.**

---

## 📜 Comparison with Stable v5.01.08

| Feature | Stable v5.01.08 | Experimental Build |
|---------|------------------|---------------------|
| Live clock | ❌ No | ✅ Yes (updates every second) |
| Non‑blocking input | ❌ No | ✅ Yes (in shell) |
| Command history | ❌ No | ✅ Yes (Up/Down arrows) |
| Stability | ✅ High | ❌ Low – many apps broken |
| Code complexity | Moderate | High (raw mode everywhere) |
| Recommended use | ✅ Daily use | ❌ Research only |

---

## 👨‍💻 Developer

<div align="center">

### **Subhajit Halder** 💻

📧 **Email**: [subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)

</div>

This experimental branch is a snapshot of work towards a more interactive shell. The lessons learned here will inform the design of the upcoming `oe-reboot` project, where a clean‑slate approach will allow proper integration of non‑blocking input from the ground up.

If you're curious and want to explore the code, feel free – but be prepared for a bumpy ride!

---

<div align="center">

**Return to the [Stable Releases](../../Stable%20Releases/) for a fully functional environment.**  
*This experimental build is preserved for historical and educational purposes.*

</div>
