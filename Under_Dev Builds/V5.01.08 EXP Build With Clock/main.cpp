//VER:5.01.08 Release build
//Last C++ complete variant for linux
//Last Updated: 19/02/2026
//Author: Subhajit Halder
#include<chrono>
#include<thread>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<random>
#include<stdio.h>
#include<unistd.h>
#include<string>
#include<random>
#include<limits>
#include<sys/select.h>
#include<termios.h>
#include<vector>
#include<cctype>
#include<sstream>

#define bold "\x1B[1m"
#define red "\x1B[31m"
#define BLUE "\x1B[34m"
#define purple "\x1B[95m"
#define RED "\x1B[91m"
#define Yellow "\x1B[33m"
#define yellow "\x1B[93m"
#define blue "\x1B[94m"
#define UNDERLINE "\033[4m"
int reg_status,trial;
#define CLOSEUNDERLINE "\033[0m"
#define green "\x1B[92m"
#define cc "\033[0m"
#define cyan "\x1B[36m"
#define invisible "\x1B[8m"
#define B1 "\x1B[41m"
#define B2 "\x1B[42m"
#define B3 "\x1B[43m"
#define B4 "\x1B[44m"
#define B5 "\x1B[45m"
#define B6 "\x1B[46m"
#define B7 "\x1B[47m"
#define B8 "\x1B[100m"
#define B9 "\x1B[101m"
#define B10 "\x1B[102m"
#define B11 "\x1B[103m"
#define B12 "\x1B[104m"
#define B13 "\x1B[105m"
#define B14 "\x1B[106m"
#define B15 "\x1B[107m"
#include"looks.h"

using namespace std;

// Global command history (used by getStringWithTimeout)
vector<string> cmdHistory;
int historyPos = 0;

void settings();
#include "sources.h"
#include "Sources2.h"
#include "programs.h"

/*  
    And an ernest request to everyperson who will view this source code
    PLEASE dont change my name from the secret about menu
    You may change it from the start screen but not from anywhere else
*/

// ================== Non‑blocking input with live clock ==================

string getStringWithTimeout(int x, int y, const string &prompt, bool allowEmpty = false) {
    string input;
    fd_set fds;
    struct timeval tv;
    bool done = false;
    enableRawMode();

    while (!done) {
        updateDateTimeLine();   // refresh date/time at (7,7) and (87,7)

        // Show prompt and current input
        gotoxy(x, y);
        cout<< prompt << input;
        fflush(stdout);

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000; // 0.1 seconds

        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) != 1) continue;

            if (c == '\n' || c == '\r') {
                if (allowEmpty || !input.empty()) {
                    cout << endl;
                    done = true;
                }
            } else if (c == 127 || c == '\b') {
                if (!input.empty()) input.pop_back();
            } else if (c == 27) {
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) != 1) continue;
                if (read(STDIN_FILENO, &seq[1], 1) != 1) continue;
                if (seq[0] == '[') {
                    if (seq[1] == 'A') {
                        if (!cmdHistory.empty() && historyPos > 0) {
                            historyPos--;
                            input = cmdHistory[historyPos];
                        }
                    } else if (seq[1] == 'B') {
                        if (historyPos < (int)cmdHistory.size() - 1) {
                            historyPos++;
                            input = cmdHistory[historyPos];
                        } else {
                            input = "";
                        }
                    }
                }
            } else if (isprint(c)) {
                input.push_back(c);
            }
        }
    }

    if (!input.empty() && !allowEmpty) {
        cmdHistory.push_back(input);
        historyPos = cmdHistory.size();
    }

    disableRawMode();
    return input;
}

// ================== Main Shell ==================

void prompt() {
    system("clear");
    gotoxy(1,1);
    layout();
    logo();
    updateDateTimeLine();  // show initial clock
    gotoxy(32,10);
    cout << red << bold << UNDERLINE << "Operating Environment ver: 5.01.08 " << cc;
    string command;

    while (true) {
        if (ins == 9) { // guest user
            cout << "\a" << flush;
            gotoxy(32,12);
            cout << "Only available commands are install, login(use it to re login) and exit";
            gotoxy(32,13);
            cout << "Command->";
            command = getStringWithTimeout(43, 13, "", false);
            if (command == "install") {
                fstream file;
                string filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) {
                    gotoxy(32,14);
                    cout << "Already installed.";
                    cout << "\a\a\a" << flush;
                    gotoxy(32,16);
                    cout << "Type login and re login with your user ID password (if exists).";
                    waitForAnyKey();
                    prompt();
                } else {
                    IP();
                    prompt();
                }
            } else if (command == "exit") {
                cout << red << bold << " Status: You are about to exit.";
                cout << "\a\a" << flush;
                exit(0);
            } else if (command == "reg_edit") {
                cout << "\a" << flush;
                reg_status = 0;
                reg_edit();
            } else if (command == "login") {
                fstream file;
                string filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) ins = 0;
                else ins = 9;
                gotoxy(1,1);
                system("clear");
                layout();
                logo();
                login();
            } else {
                fstream file;
                string filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) {
                    gotoxy(32,15);
                    cout << red << bold << "I see you trying to access user features without a valid installation/ user id creation. But access denied." << cc;
                    cout << "\a\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    gotoxy(32,20);
                    cout << red << bold << " Status: No Command" << cc;
                    waitForAnyKey();
                    prompt();
                }
            }
        } else { // proper user
            gotoxy(32,11);
            cout << green << bold << "Type help to get list of commands" << cc;
            gotoxy(88,10);
            reg_status = 0;
            cout << bold << purple << "Welcome" << " " << cyan << bold << name1;
            gotoxy(32,13);
            cout << blue << bold << "Command->" << cc;
            command = getStringWithTimeout(43, 13, "", false);

            if (command == "Help" || command == "HELP" || command == "help") {
                gotoxy(35,14);
                cout << yellow << bold << "Type:" << cc;
                gotoxy(35,15); cout << blue << bold << "\tTicTacToe" << cc;
                gotoxy(35,16); cout << red << bold << "\tCalculator" << cc;
                gotoxy(35,17); cout << blue << bold << "\tQuiz" << cc;
                gotoxy(35,18); cout << red << bold << "\tTemp_Conv" << cc;
                gotoxy(35,19); cout << blue << bold << "\teqn_solve" << cc;
                gotoxy(35,20); cout << red << bold << "\tquad_eqn_solve, to open the applications(if installed)." << cc;
                gotoxy(35,21); cout << yellow << bold << "Type:" << cc;
                gotoxy(35,22); cout << red << bold << "\texit: To exit ." << cc;
                gotoxy(35,23); cout << blue << bold << "\tver: To see version number" << cc;
                gotoxy(35,24); cout << red << bold << "\tinst_all: To install al applications except TicTacToe and Quiz at once." << cc;
                gotoxy(35,25); cout << blue << bold << "\tsettings: To change your existing settings." << cc;
                gotoxy(35,26); cout << red << bold << "\tType 'registryeditor' to enter the mode" << cc;
                gotoxy(35,27); cout << blue << bold << "\tTo re-login type login." << cc;
                gotoxy(35,28); cout << red << bold << "\tTo install an app from above  list type inst_'with app name'" << cc;
                gotoxy(35,29); cout << blue << bold << "\tTo uninstall an app from above  list type unst_'with app name'" << cc;
                waitForAnyKey();
                prompt();
            }
            else if (command == "TicTacToe" || command == "tictactoe" || command == "TICTACTOE") {
                bs = 1;
                fstream f;
                f.open("TicTacToe.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    bootscreen();
                    selector_t();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "Quiz" || command == "QUIZ" || command == "quiz") {
                fstream f;
                f.open("Quiz.txt", ios::in);
                f >> reg;
                bs = 2;
                if (reg == 1) {
                    bootscreen();
                    start();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "ar(t_c)") {
                fstream f;
                f.open("ATC.txt", ios::in);
                f >> reg;
                bs = 8;
                if (reg == 1) {
                    bootscreen();
                    atc();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "inst_ar(t_c)") {
                v = 8;
                bs = 8;
                fstream f;
                f.open("ATC.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                }
            }
            else if (command == "TEMP_CONV" || command == "temp_conv" || command == "Temp_Conv") {
                bs = 3;
                fstream f;
                f.open("TC.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    bootscreen();
                    tc();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "VER" || command == "ver") {
                gotoxy(32,15);
                cout << red << bold << "   VER: 4.23.09(DEV)" << cc;
                waitForAnyKey();
                prompt();
            }
            else if (command == "whoami" || command == "list_ID") {
                gotoxy(32,15);
                cout << red << bold << name1 << cc;
                waitForAnyKey();
                prompt();
            }
            else if (command == "exit" || command == "EXIT" || command == "Exit") {
                cout << "\a\a\a\a" << flush;
                gotoxy(30,10);
                system("clear");
                cout << RED << bold << " Program is shutting Down. Thank You for using. Have a good time. Bye!!!" << cc;
                sleep(1);
                exit(0);
            }
            else if (command == "inst_TicTacToe") {
                v = 1;
                bs = 1;
                fstream f;
                f.open("TicTacToe.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                }
            }
            else if (command == "inst_Temp_Conv" || command == "inst_temp_conv") {
                v = 3;
                bs = 3;
                fstream f;
                f.open("TC.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                    tc();
                }
            }
            else if (command == "inst_Calculator") {
                bs = 4;
                v = 4;
                fstream f;
                f.open("Calc.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                    calc();
                }
            }
            else if (command == "inst_Quiz") {
                v = 2;
                bs = 2;
                fstream f;
                f.open("Quiz.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                }
            }
            else if (command == "Calculator" || command == "calculator") {
                bs = 4;
                fstream f;
                f.open("Calc.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    bootscreen();
                    calc();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "eqn_solve") {
                bs = 6;
                fstream f;
                f.open("solve.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    bootscreen();
                    get_Eqn();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "quad_eqn_solve") {
                bs = 7;
                fstream f;
                f.open("quad_solve.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    bootscreen();
                    quad_eqn_solve();
                } else {
                    gotoxy(32,15);
                    cout << red << bold << "  Status: Non installed yet" << cc;
                    cout << "\a\a" << flush;
                    waitForAnyKey();
                    prompt();
                }
            }
            else if (command == "inst_eqn_solve") {
                v = 6;
                bs = 6;
                fstream f;
                f.open("solve.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                    get_Eqn();
                }
            }
            else if (command == "inst_quad_eqn_solve") {
                v = 7;
                bs = 7;
                fstream f;
                f.open("quad_solve.txt", ios::in);
                f >> reg;
                if (reg == 1) {
                    gotoxy(32,15);
                    cout << yellow << bold << "  Status: Already installed" << cc;
                    cout << "\a" << flush;
                    waitForAnyKey();
                    prompt();
                } else {
                    bootscreen();
                    installer();
                    quad_eqn_solve();
                }
            }
            else if (command == "unst_eqn_solve") {
                fstream f;
                reg = 0;
                f.open("solve.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_TicTacToe") {
                fstream f;
                reg = 0;
                f.open("TicTacToe.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_Temp_Conv") {
                fstream f;
                reg = 0;
                f.open("TC.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_Calculator") {
                fstream f;
                reg = 0;
                f.open("Calc.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_quad_eqn_solve") {
                fstream f;
                reg = 0;
                f.open("quad_solve.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_Quiz") {
                fstream f;
                reg = 0;
                f.open("Quiz.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "unst_ar(t_c)") {
                fstream f;
                reg = 0;
                f.open("ATC.txt", ios::out);
                f << reg;
                f.close();
                gotoxy(32,15);
                cout << blue << bold << " Unistallation finished." << cc;
                cout << "\a\a\a\a\a\a" << flush;
                waitForAnyKey();
                prompt();
            }
            else if (command == "registryeditor") {
                cout << "\a\a\a\a\a\a\a" << flush;
                reg_status = 0;
                reg_edit();
            }
            else if (command == "display_source") {
                cout << "\a" << flush;
                source();
                waitForAnyKey();
                system("clear");
            }
            else if (command == "inst_all") {
                reg = 1;
                fstream tc, c, eqn, qe, at;
                tc.open("TC.txt", ios::out); tc << reg; tc.close();
                c.open("Calc.txt", ios::out); c << reg; c.close();
                eqn.open("solve.txt", ios::out); eqn << reg; eqn.close();
                qe.open("quad_solve.txt", ios::out); qe << reg; qe.close();
                at.open("ATC.txt", ios::out); at << reg; at.close();
                gotoxy(32,15);
                cout << green << bold << "Successfully completed the command" << cc;
                waitForAnyKey();
                prompt();
            }
            else if (command == "settings" || command == "Settings" || command == "SETTINGS") {
                settings();
            }
            else if (command == "login" || command == "Login") {
                system("clear");
                layout();
                login();
            }
            else {
                gotoxy(32,15);
                cout << red << bold << "  No such command" << cc;
                cout << "\a" << flush;
                waitForAnyKey();
                prompt();
            }
        }
    }
}

// ================== Original Installer (IP) ==================

void IP() {
    gotoxy(1,1);
    layout();
    logo();
    gotoxy(10,8);
    string c;
    reg_status = 1;
    cout << BLUE << bold << "Do you want to directly install this application or you want to use it once before installation?(Enter choice below)." << cc << cc;
    gotoxy(32,10);
    cout << purple << bold << UNDERLINE << "Help Me Decide:" << cc;
    gotoxy(32,12);
    cout << yellow << bold << "If you wish to install the program directly on the browser without testing for once press y.";
    gotoxy(32,13);
    cout << "If you want to test the program before installing i.e. if you want to have a look at the user ";
    gotoxy(32,14);
    cout << "interface press n and it will load you into the guest user login screen. Just Press enter there  ";
    gotoxy(32,15);
    cout << "to login. As it is trial so only three commands login, install and exit would be there.";
    gotoxy(32,18);
    cout << cyan << bold << "Enter your choice(y/n):";
    cout << invisible;
    cin >> c;
    cout << cc;

    if (c == "n" || c == "N") {
        system("clear");
        gotoxy(1,1);
        layout();
        logo();
        gotoxy(5,7);
        cout << "After completion of your trial type 'install' to restart the setup to continue.";
        login();
    }
    else if (c == "registryeditor_admin") {
        reg_edit();
    }
    else if (c == "prompt") {
        reg_status = 1;
        ins = 0;
        prompt();
    }
    else if (c == "y" || c == "Y") {
        system("clear");
        layout();
        logo();
        gotoxy(32,8);
        cout << UNDERLINE << red << bold << "While the game is loading let us know its working:" << CLOSEUNDERLINE;
        gotoxy(32,10);
        cout << yellow << "At first type help command at the prompt.";
        gotoxy(32,11);
        cout << "You will be getting a list of available commands use it  " << CLOSEUNDERLINE;
        gotoxy(88,10);
        cout << purple << "  Designed for ease" << cc;
        gotoxy(32,12);
        cout << yellow << "to install your desired program" << cc;
        gotoxy(88,11);
        cout << purple << "  For ease in using " << cc;
        gotoxy(32,13);
        cout << yellow << "Enjoy using it!!!" << cc;
        gotoxy(88,12);
        cout << purple << "  softwares" << cc;
        gotoxy(88,17);
        cout << green << "DEVELOPER:" << RED << " Subhajit Halder" << cc;
        gotoxy(2,6);
        progressbar();
        sleep(6);
        add_user();
        reg = 0;
        install();
        Improvements();
        waitForAnyKey();
        gotoxy(1,2);
        layout();
        login();
    }
}

// ================== Registry Editor ==================

void reg_edit() {
    gotoxy(1,1);
    layout();
    gotoxy(5,7);
    cout << bold << UNDERLINE << red << "Welcome to Registry Editor version:3.5.0(For Power Users)." << cc;
    gotoxy(5,8);
    cout << green << bold << "Available commands:" << cc;
    gotoxy(5,9);   cout << yellow << bold << "\ta.)install";
    gotoxy(5,10);  cout << "\tb.)temp";
    gotoxy(5,11);  cout << "\tc.)exit";
    gotoxy(5,12);  cout << "\td.)reset";
    gotoxy(5,13);  cout << "\te.)prompt";
    gotoxy(5,14);  cout << "\tf.)add_key (Only for Quiz and TicTacToe)";
    gotoxy(5,15);  cout << "\tg.)user";
    gotoxy(5,16);  cout << "\th.)help (It is advised to use help command first to get uses of available commands." << cc;

    while (true) {
        string command;
        gotoxy(5,17);
        cout << "Command->";
        cin >> command;   // blocking – but registry editor is a separate tool, clock not needed here
        fstream t, q, tc, c, eqn, d;
        reg = 1;
        if (command == "install") {
            if (reg_status == 1) {
                install();
                gotoxy(5,18);
                cout << cyan << bold << "Succesfully completed the command" << cc;
                waitForAnyKey();
                reg_edit();
            } else {
                gotoxy(5,18);
                cout << cyan << bold << "Succesfully completed the command" << cc;
                waitForAnyKey();
                tc.open("TC.txt", ios::out); tc << reg; tc.close();
                c.open("Calc.txt", ios::out); c << reg; c.close();
                eqn.open("solve.txt", ios::out); eqn << reg; eqn.close();
                reg_edit();
            }
        }
        else if (command == "add_key") {
            if (reg_status == 1) {
                gotoxy(5,18);
                cout << "\tCommand->";
                cin >> command;
                reg = 1;
                if (command == "both") {
                    t.open("TicTacToe.txt", ios::out); t << reg; t.close();
                    q.open("Quiz.txt", ios::out); q << reg; q.close();
                }
                else if (command == "quiz") {
                    q.open("Quiz.txt", ios::out); q << reg; q.close();
                }
                else if (command == "tictactoe") {
                    t.open("TicTacToe.txt", ios::out); t << reg; t.close();
                }
                gotoxy(5,18);
                cout << cyan << bold << "Succesfully completed the command" << cc;
                waitForAnyKey();
                reg_edit();
            } else {
                gotoxy(5,20);
                cout << red << bold << "Status: No available command" << "\a\a\a\a\a\a\a\a\a\a\a\a" << cc;
                waitForAnyKey();
                reg_edit();
            }
        }
        else if (command == "exit") {
            layout();
            logo();
            login();
        }
        else if (command == "temp") {
            gotoxy(5,18);
            cout << "Command->";
            cin >> command;
            if (command == "TTT" || command == "ttt") {
                if (reg_status == 1) {
                    computer_vs_player();
                } else {
                    gotoxy(5,20);
                    cout << red << bold << "Status: No available command" << "\a\a\a\a\a\a\a\a\a\a\a\a" << cc;
                    waitForAnyKey();
                    reg_edit();
                }
            }
            else if (command == "quiz") {
                if (reg_status == 1) start();
                else { trial = 4; start(); }
            }
            else {
                gotoxy(10,20);
                cout << red << bold << "temp command is available for only one program(s)" << cc;
                waitForAnyKey();
                reg_edit();
            }
        }
        else if (command == "user") {
            if (reg_status == 1) {
                fstream file;
                string filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) {
                    gotoxy(5,19);
                    cout << RED << bold << "Warning! This command will reset all your user-id password" << "\a\a\a\a\a\a\a\a\a\a" << flush;
                    gotoxy(5,20);
                    cout << "Do you want to continue:" << cc;
                    char a;
                    cin >> a;  // blocking, but okay
                    if (a == 'y') {
                        add_user();
                        waitForAnyKey();
                        gotoxy(5,25);
                        cout << cyan << bold << "Succesfully completed the command" << cc;
                        waitForAnyKey();
                        reg_edit();
                    } else {
                        gotoxy(5,19);
                        cout << RED << bold << "Execution Cancelled!!" << cc;
                        waitForAnyKey();
                        reg_edit();
                    }
                } else {
                    add_user();
                }
            } else {
                gotoxy(5,19);
                cout << RED << bold << "Execution Cancelled!!" << cc;
                waitForAnyKey();
                reg_edit();
            }
        }
        else if (command == "reset") {
            gotoxy(5,19);
            cout << RED << bold << "Warning! This command will reset all your applications." << "\a\a\a\a\a\a\a\a\a\a" << flush;
            gotoxy(5,20);
            cout << "Do you want to continue:" << cc;
            char a;
            cin >> a;
            if (a == 'y') {
                reg = 0;
                install();
                gotoxy(5,25);
                cout << cyan << bold << "Succesfully completed the command" << cc;
                waitForAnyKey();
                reg_edit();
            } else {
                gotoxy(5,19);
                cout << RED << bold << "Execution Cancelled!!" << cc;
                waitForAnyKey();
                reg_edit();
            }
        }
        else if (command == "prompt" || command == "Prompt") {
            system("clear");
            gotoxy(1,1);
            layout();
            logo();
            fstream file;
            string filename = "file.txt";
            file.open(filename.c_str());
            if (file.good()) ins = 0;
            else ins = 9;
            prompt();
        }
        else if (command == "help") {
            gotoxy(5,20);
            cout << blue << bold << " Welcome to HELP Documentation Ver: 1.0. :" << cc;
            gotoxy(5,21); cout << "\ta.)install: To install all the programs at once.";
            gotoxy(5,22); cout << "\tb.)add_key (Only for Quiz and TicTacToe): To install only TicTacToe and Quiz[with admin privileges only].";
            gotoxy(5,23); cout << "\tc.)exit: Exit the Registry Editor and open the login screen.";
            gotoxy(5,24); cout << "\td.)temp: To access a program temporarily(For TicTacToe and QUIZ).";
            gotoxy(5,25); cout << "\te.)user: To add a new user or to do password bypass.";
            gotoxy(5,26); cout << "\tf.)reset: To uninstall all applications.";
            gotoxy(5,27); cout << "\tg.)clear: To clear the output screen.";
            waitForAnyKey();
            reg_edit();
        }
        else if (command == "clear" || command == "cls") {
            system("clear");
            reg_edit();
        }
        else if (command == "start_admin_reg_edit") {
            reg_status = 1;
            reg_edit();
        }
        else {
            gotoxy(5,20);
            cout << red << bold << "Status: No available command" << "\a\a\a\a\a\a\a\a\a\a\a\a" << cc;
            waitForAnyKey();
            reg_edit();
        }
    }
}

// ================== main ==================

int main() {
    bs = 0;
    bootscreen();
    fstream file;
    string filename = "file.txt";
    file.open(filename.c_str());
    if (file.good()) {
        system("clear");
        layout();
        logo();
        login();
        prompt();
    } else {
        IP();
    }
    return 0;
}