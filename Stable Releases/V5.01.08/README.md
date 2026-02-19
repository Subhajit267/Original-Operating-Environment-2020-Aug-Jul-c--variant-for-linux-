\# 🔧 Operating Environment v5.01.08 – Linux C++ Final Release



<div align="center">



!\[C++](https://img.shields.io/badge/Language-C++-blue?logo=c%2B%2B\&logoColor=white)

!\[Linux](https://img.shields.io/badge/Platform-Linux-yellow?logo=linux\&logoColor=white)

!\[Status](https://img.shields.io/badge/Status-Stable%20%7C%20Final-brightgreen)

!\[Release Date](https://img.shields.io/badge/Release%20Date-19%20Feb%202026-orange)



\*\*The culmination of the original Linux C++ lineage – a fully featured console‑based “operating environment” with multiple applications, user management, registry system, and countless hidden features.\*\*



</div>



---



\## 📋 Table of Contents

\- \[📌 Overview](#-overview)

\- \[✨ What's New in v5.01.08](#-whats-new-in-v50108)

\- \[🖥️ System Features](#️-system-features)

\- \[🎮 Built‑in Applications](#-built‑in-applications)

\- \[🕹️ Hidden Features \& Easter Eggs](#️-hidden-features--easter-eggs)

\- \[📁 File Structure](#-file-structure)

\- \[🛠️ Building \& Running](#️-building--running)

\- \[🐞 Known Issues](#-known-issues)

\- \[🚧 Experimental: Live Clock (Under Development)](#-experimental-live-clock-under-development)

\- \[👨‍💻 Developer](#-developer)



---



\## 📌 Overview



\*\*Operating Environment\*\* is a hobby project that started as a simple quiz app during online classes and grew into a full‑fledged console‑based environment. It mimics some aspects of an operating system: a command shell, user accounts, an application registry, a settings panel, and even a registry editor for power users. All applications are built‑in and written in pure C++ (with some C‑style I/O).



This release, \*\*v5.01.08\*\*, is the final stable version of the original Linux C++ codebase. It incorporates numerous bug fixes, input validation improvements, and a polished user interface. Future development will continue in separate repositories for Windows ports and a clean‑slate reboot project (`oe-reboot`).



---



\## ✨ What's New in v5.01.08



Compared to previous versions (v4.23.09 and earlier), this release includes:



\- \*\*Uninstall command fixes\*\* – all `unst\_\*` commands now target the correct registry files (no more accidentally wiping TicTacToe when trying to uninstall the temperature converter).

\- \*\*Input validation\*\* – all numeric inputs are now thoroughly validated; entering letters where numbers are expected will prompt the user to re‑enter.

\- \*\*Progress bar\*\* – the artificial 25% cap has been removed; the loading bar now runs smoothly to 100% (though it still uses a fixed‑step simulation).

\- \*\*Area of Triangle app\*\* – fully integrated with its own installer/uninstaller and registry file (`ATC.txt`).

\- \*\*`inst\_all` command\*\* – now correctly installs all apps except TicTacToe and Quiz, including the Area of Triangle.

\- \*\*Registry editor\*\* – duplicate `reset` block removed; stray semicolon in `add\_key` fixed.

\- \*\*Version strings\*\* – unified to `5.01.08` throughout the interface.

\- \*\*Timer functions\*\* – changed return type to `void` (no more dummy return values).

\- \*\*Guest mode\*\* – simplified access to registry editor; no more triple‑click.

\- \*\*Code cleanup\*\* – many small improvements, better file closing, and removal of unused variables.



This version is \*\*stable and fully functional\*\* as a self‑contained environment.



---



\## 🖥️ System Features



\- \*\*User Management\*\* – Login with password, guest mode, password change, user ID change. Passwords can be removed (set to `0`).

\- \*\*Registry System\*\* – Text files track application installation status (e.g., `TicTacToe.txt` contains `1` if installed). The installer and registry editor manipulate these files.

\- \*\*Registry Editor\*\* – A hidden power‑user tool accessible via `registryeditor`. Offers commands to install/uninstall, temporarily run apps, manage users, and reset all applications. Admin/normal modes.

\- \*\*Settings Panel\*\* – Three sub‑panels:

&nbsp; - \*\*User Accounts\*\* – change password, change user ID.

&nbsp; - \*\*Reset \& Restore\*\* – reset all apps or reinstall the system.

&nbsp; - \*\*Personalization\*\* – change the border colour (16 options, writes to `looks.h` and restarts).

\- \*\*Bootscreens\*\* – Each app has its own loading screen with a progress bar.

\- \*\*Guest Mode\*\* – Limited commands (`install`, `login`, `exit`) for testing without a user account.



---



\## 🎮 Built‑in Applications



| Application | Command(s) | Description |

|-------------|------------|-------------|

| \*\*TicTacToe\*\* | `TicTacToe`, `tictactoe`, `TICTACTOE` | Player vs. Player or Computer (Easy/Hard). Cheat: type `w` to win instantly. |

| \*\*Quiz\*\* | `Quiz`, `QUIZ`, `quiz` | Two‑player quiz with 8 rounds, bonus questions, and a detailed scoreboard. Easter eggs: `i` (about), `e` (evaluator), `c` (cheat sheet), `z` (instant win). |

| \*\*Calculator\*\* | `Calculator`, `calculator` | Simple arithmetic with three operators (e.g., `5+3\*2-4`). |

| \*\*Temperature Converter\*\* | `Temp\_Conv`, `temp\_conv`, `Temp\_Conv` | Converts between Celsius, Fahrenheit, and Kelvin. |

| \*\*Linear Equation Solver\*\* | `eqn\_solve` | Solves two equations in two variables using cross‑multiplication. Handles different equation forms. |

| \*\*Quadratic Equation Solver\*\* | `quad\_eqn\_solve` | Solves `ax²+bx+c=0` and reports root types (real/equal, real/unequal, imaginary). |

| \*\*Area of Triangle\*\* | `ar(t\_c)` | Calculates area from three coordinate pairs. |



Each app has an installer (`inst\_<app>`) and uninstaller (`unst\_<app>`). The `inst\_all` command installs all apps except TicTacToe and Quiz (which require product keys).



---



\## 🕹️ Hidden Features \& Easter Eggs



\- \*\*Special login passwords\*\* – `registryeditor` opens the registry editor (non‑admin), `guess\_it` displays the source code.

\- \*\*Registry editor admin mode\*\* – within the editor, type `start\_admin\_reg\_edit` to gain full privileges.

\- \*\*`temp` command\*\* – inside the registry editor, `temp TTT` or `temp quiz` lets you play without installing.

\- \*\*Colour changer\*\* – in Personalization, press `e` to exit without changing the colour.

\- \*\*`whoami`\*\* – not listed in help, but works to show the current username.

\- \*\*`display\_source`\*\* – dumps the current source file to the screen.

\- \*\*Quiz cheat\*\* – during a question, type `z` to instantly win that round for your group.



---



\## 📁 File Structure



```

OperatingEnvironment/

├── main.cpp           # Entry point, shell, registry editor

├── sources.h          # Prototypes, utilities, validation functions, layout

├── Sources2.h         # Installer, activation, bootscreens, password change, settings

├── programs.h         # All application code (equation solvers, TicTacToe, quiz, etc.)

├── looks.h            # Border colour macro (can be modified by color\_change)

├── file.txt           # Stores current username

├── file2.txt          # Stores password (or "0" if no password)

├── \*.txt              # Registry files for each app (TicTacToe.txt, Quiz.txt, etc.)

└── file3.txt / file6.txt # Activation key files (for TicTacToe and Quiz)

```



The program creates these files on first run. All registry files are plain text containing a single integer (`1` = installed, `0` = not installed).



---



\## 🛠️ Building \& Running



\### Prerequisites

\- Linux environment (or any terminal with ANSI escape sequence support)

\- `g++` compiler (C++11 or later)



\### Compilation

```bash

g++ -o oe main.cpp -std=c++11

```



\### Execution

```bash

./oe

```

On first run, the installer will guide you through user creation and app installation.



---



\## 🐞 Known Issues



\- \*\*Progress bar\*\* – still a simulation that stops at 25% for a moment; this is a deliberate cosmetic leftover.

\- \*\*Uninstall commands\*\* – some may still have minor glitches (e.g., `unst\_eqn\_solve` writes to `solve.txt` correctly now, but double‑check if you encounter issues).

\- \*\*Input validation\*\* – works well, but if you enter an extremely long string (e.g., thousands of characters) the buffer may overflow; the code limits input length.

\- \*\*Timer functions\*\* – beep at 5 seconds may be considered annoying; they work as intended.

\- \*\*Color changer\*\* – requires a program restart; this is by design.

\- \*\*Live clock\*\* – a prototype was attempted but remains incomplete (see next section).



---



\## 🚧 Experimental: Live Clock (Under Development)



An experimental branch was created to add a \*\*real‑time updating clock\*\* in the top border of the shell. The idea was to have the date and time update every second without blocking user input. A partial implementation was made using non‑blocking input (`select` with a 100 ms timeout) and raw terminal mode. However, due to the complexity of integrating raw mode with all existing input functions (`cin\_validattion`, `getchar`, etc.), the clock feature is \*\*not yet stable\*\* and has been temporarily shelved.



\### What works:

\- The clock displays and updates when the program is idle.

\- Basic line editing and command history work.



\### What's broken:

\- Input in many applications (TicTacToe, quiz, etc.) malfunctions because raw mode conflicts with `cin`.

\- The cursor sometimes disappears or behaves unexpectedly.

\- The code became too messy to maintain alongside the stable release.



\### Future plans:

The live clock feature may be revisited in the `oe-reboot` project, where a clean‑slate approach will allow proper integration of non‑blocking input from the ground up.



\### Where to find it:

If you're curious, the partially working code is preserved in the \*\*`underdev-live-clock`\*\* branch of this repository. It is \*\*not recommended for general use\*\* – it's a snapshot of work in progress.



---



\## 👨‍💻 Developer



<div align="center">



\### \*\*Subhajit Halder\*\* 💻



!\[Profile](https://img.shields.io/badge/Developer-Subhajit\_Halder-blue?style=for-the-badge)



📧 \*\*Email\*\*: \[subhajithalder267@outlook.com](mailto:subhajithalder267@outlook.com)



</div>



\*\*Project Timeline\*\*:  

\- \*\*v1.0\*\* – First release (mid‑2020): TicTacToe, Quiz, Calculator, Temp\_Conv.  

\- \*\*v2.01\*\* – Added linear equation solver, bootscreen, single login.  

\- \*\*v3.0\*\* – Difficulty levels, registry editor, cheat codes.  

\- \*\*v4.05.08\*\* – Quadratic equation solver, settings app, Kelvin support.  

\- \*\*v5.01.08\*\* – Final stable release with all known bugs fixed and input validation.



\*\*Acknowledgements\*\*:  

\- Ritabrata Saha for evaluator and cheat code ideas.  

\- All friends who hyped and tested the project over the years.



---



<div align="center">



\*This version marks the end of the original Linux C++ journey. Future work will continue on Windows ports and the `oe-reboot` project. Thank you for exploring!\*



</div>

