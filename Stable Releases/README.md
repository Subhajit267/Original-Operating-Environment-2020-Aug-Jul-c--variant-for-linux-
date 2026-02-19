---
# 📦 Stable Releases – Operating Environment (Linux)
<div align="center">

![Releases](https://img.shields.io/badge/Releases-4-blue)
![Status](https://img.shields.io/badge/Status-Stable-brightgreen)
![Time Span](https://img.shields.io/badge/Time%20Span-2020--2022-lightgrey)

**This directory contains every officially released version of Operating Environment for Linux**

*From the humble beginnings of v1.0 to the feature‑rich v4.05.08, each release represents a milestone in the project's evolution.*

</div>

## 📋 Table of Contents
- [🌟 Overview](#-overview)
- [📁 Version Structure](#-version-structure)
- [📈 Release Timeline](#-release-timeline)
- [🔍 How to Navigate](#-how-to-navigate)
- [🛠️ Compilation Notes](#️-compilation-notes)

## 🌟 Overview

The **Stable Releases** folder houses all completed, publicly announced versions of Operating Environment. Each version is self‑contained in its own subfolder, with the complete source code and a dedicated README detailing:

- New features and improvements
- Bug fixes and changes
- Known issues (if any)
- Compilation instructions

These releases represent the project as it was presented to users – polished enough for daily use, yet still evolving with each iteration.

## 📁 Version Structure

```
📁 Stable Releases/
├── 📁 v1.0/          # First public release
├── 📁 v2.01/         # Second release – equation solver, bootscreen
├── 📁 v3.0/          # Third release – difficulty levels, registry editor, cheat codes
└── 📁 v4.05.08/      # Fourth release – quadratic solver, settings app, Kelvin support
```

Each folder contains:
- `main.cpp` – Entry point and main shell loop
- Additional `.cpp` files for each application (e.g., `tictactoe.cpp`, `quiz.cpp`, `eqn_solver.cpp`)
- Header files: `sources.h`, `Sources2.h`, `programs.h`, `looks.h` (depending on version)
- A comprehensive `README.md` with version‑specific details

## 📈 Release Timeline

| Version | Date (Approx.) | Key Features |
|---------|----------------|--------------|
| **v1.0** | Mid‑2020 | TicTacToe, Quiz, Calculator, Temperature Converter |
| **v2.01** | Late 2020 | Linear equation solver, bootscreen, single login, faster installer |
| **v3.0** | Early 2021 | Difficulty levels in TicTacToe, registry editor, cheat codes, enhanced equation solver |
| **v4.05.08** | Late 2021 | Quadratic equation solver, settings app, Kelvin support, user account improvements |

## 🔍 How to Navigate

1. Choose a version folder that interests you.
2. Read its `README.md` for an overview and compilation instructions.
3. Browse the source code to see how features were implemented at that time.
4. To run a version, compile it on a Linux system (or compatible terminal) and execute the resulting binary.

## 🛠️ Compilation Notes

All versions were developed and tested on **Linux** using `g++`. They rely on:

- Standard C++ libraries
- Linux system calls (`system`, `usleep`)
- ANSI escape sequences for console control

**Generic compilation command** (specifics may vary per version):

```bash
g++ main.cpp [other .cpp files] -o oe_v[version]
./oe_v[version]
```

Refer to each version's README for exact file lists and any version‑specific requirements.

---

<div align="center">

*Each release is a snapshot of the project's growth – explore them in order to witness the journey.*

</div>

---
