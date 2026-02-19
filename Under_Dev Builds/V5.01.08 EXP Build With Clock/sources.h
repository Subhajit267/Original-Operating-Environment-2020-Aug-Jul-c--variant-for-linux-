// This is place of function prototype(some functions)
#include <limits>
#include <sys/select.h>
#include <termios.h>
#include <vector>
#include <cctype>
#include <sstream>

void quad_eqn_solve();//Quadratic Eqn solver
int printrndone();
void timerS();//Shutdown timer
void logo();
void color_change();
string Difficult;
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//Arrays(board layout of TicTacToe)
void show_board();//board show korar function
void get_x_player_choice();// getting player's choice whose letter is X
void get_o_player_choice();// getting player's choice whose letter is O
void get_computer_choice_e();
void get_computer_choice_h();
int count_board(char symbol);
char check_winner();// checking the winner
void computer_vs_player();// declaring how computer can play with the player
void player_vs_player();
void selector_t();
void prompt();
void layout();
void install();
void password_change();
int source();
int scr();
void USER_ACCOUNTS();
void PERSONALIZATION();
void RESET_AND_RESTORE();
void timerS();
void IP();
void add_user();
void timerO();
void timerB();
void login();
int loading();
int start();
int about();
int cheatcode();
int evaluator();
void reg_edit();
void bootscreen();
void userid_change();
void login();
void tc();
void password_change();
void activation();

int ap,reg,v,ins,bs,mode;
string choice;
double A1,A2,Bi1,Bi2,C1,C2,x,y,m,n;
char C,A_1,cho;
int state;
string a,filename,name1,password1,password;

// Command history (used by shell input)
extern vector<string> cmdHistory;
extern int historyPos;
void disableRawMode();
void waitForAnyKey();
void enableRawMode();
void updateDateTimeLine();

// Terminal raw mode functions
termios orig_termios;


void gotoxy(int x,int y)// declaring the cursor position
{
    printf("%c[%d;%df",0x1B,y,x);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
void waitForAnyKey() {
    fd_set fds;
    struct timeval tv;
    enableRawMode();
    while (true) {
        updateDateTimeLine();
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;
        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) == 1) {
                disableRawMode();
                return;
            }
        }
    }
}
void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void updateDateTimeLine() {
    time_t now = time(0);
    struct tm *t = localtime(&now);
    char dateStr[20], timeStr[20];
    strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", t);
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", t);
    gotoxy(7, 7);
    cout << "Date: " << dateStr;
    gotoxy(87, 7);
    cout << "Time: " << timeStr;
    fflush(stdout);
}

// ----- Input validation functions (clock‑aware) -----

// Read a full line (with backspace, arrow history for strings)
string getStringWithClock(int x, int y, const string &prompt, bool allowEmpty = false) {
    string input;
    fd_set fds;
    struct timeval tv;
    bool done = false;
    enableRawMode();

    while (!done) {
        updateDateTimeLine();
        gotoxy(x, y);
        cout << "\033[K" << prompt << input;   // clear line then print
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
            } else if (c == 127 || c == '\b') { // Backspace
                if (!input.empty()) input.pop_back();
            } else if (c == 27) { // Escape (arrow keys)
                char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) != 1) continue;
                if (read(STDIN_FILENO, &seq[1], 1) != 1) continue;
                if (seq[0] == '[') {
                    if (seq[1] == 'A') { // Up
                        if (!cmdHistory.empty() && historyPos > 0) {
                            historyPos--;
                            input = cmdHistory[historyPos];
                        }
                    } else if (seq[1] == 'B') { // Down
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
// Read an integer (with validation)
int getIntWithClock(int x, int y, const string &prompt) {
    string input;
    fd_set fds;
    struct timeval tv;
    enableRawMode();

    while (true) {
        updateDateTimeLine();
        gotoxy(x, y);
        cout << prompt << input;
        fflush(stdout);

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;

        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) != 1) continue;

            if (c == '\n' || c == '\r') {
                if (input.empty()) continue;
                char* end;
                long val = strtol(input.c_str(), &end, 10);
                if (end != input.c_str() && *end == '\0') {
                    disableRawMode();
                    return (int)val;
                } else {
                    gotoxy(x, y+1);
                    cout << "Invalid number. Try again.";
                    input.clear();
                    usleep(500000);
                    gotoxy(x, y+1);
                }
            } else if (c == 127 || c == '\b') {
                if (!input.empty()) input.pop_back();
            } else if (isdigit(c) || (c == '-' && input.empty())) {
                input.push_back(c);
            }
        }
    }
}

// Read a double (with validation)
double getDoubleWithClock(int x, int y, const string &prompt) {
    string input;
    fd_set fds;
    struct timeval tv;
    enableRawMode();

    while (true) {
        updateDateTimeLine();
        gotoxy(x, y);
        cout << prompt << input;
        fflush(stdout);

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;

        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) != 1) continue;

            if (c == '\n' || c == '\r') {
                if (input.empty()) continue;
                char* end;
                double val = strtod(input.c_str(), &end);
                if (end != input.c_str() && *end == '\0') {
                    disableRawMode();
                    return val;
                } else {
                    gotoxy(x, y+1);
                    cout << "Invalid number. Try again.";
                    input.clear();
                    usleep(500000);
                    gotoxy(x, y+1);
                    cout << "";
                }
            } else if (c == 127 || c == '\b') {
                if (!input.empty()) input.pop_back();
            } else if (isdigit(c) || c == '.' || (c == '-' && input.empty())) {
                input.push_back(c);
            }
        }
    }
}

// Read a single character (no echo, no Enter needed)
char getCharWithClock(int x, int y, const string &prompt) {
    fd_set fds;
    struct timeval tv;
    enableRawMode();

    // Print prompt once
    gotoxy(x, y);
    cout << "" << prompt;
    fflush(stdout);

    while (true) {
        updateDateTimeLine();

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;

        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) != 1) continue;
            disableRawMode();
            return c;
        }
    }
}

// Read two doubles (for coordinates) with validation
void getTwoDoublesWithClock(double &x1, double &y1, int x, int y, const string &prompt) {
    string input;
    fd_set fds;
    struct timeval tv;
    enableRawMode();

    while (true) {
        updateDateTimeLine();
        gotoxy(x, y);
        cout << "" << prompt << input;
        fflush(stdout);

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;

        if (select(1, &fds, NULL, NULL, &tv) > 0) {
            char c;
            if (read(STDIN_FILENO, &c, 1) != 1) continue;

            if (c == '\n' || c == '\r') {
                if (input.empty()) continue;
                istringstream iss(input);
                if (iss >> x1 >> y1) {
                    disableRawMode();
                    return;
                } else {
                    gotoxy(x, y+1);
                    cout << "Invalid. Enter two numbers.";
                    input.clear();
                    usleep(500000);
                    gotoxy(x, y+1);
                    cout << "";
                }
            } else if (c == 127 || c == '\b') {
                if (!input.empty()) input.pop_back();
            } else if (isprint(c)) {
                input.push_back(c);
            }
        }
    }
}

// Operator validation (only + - * /) – this one is still blocking but can be made non‑blocking later
void getValidOperator(char &op, int x, int y, const string &prompt) {
    const string allowed = "+-*/";
    gotoxy(x, y);
    cout << prompt;
    while (true) {
        cin >> op;   // blocking – we could replace with getCharWithClock if needed
        if (allowed.find(op) != string::npos) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(x, y);
        cout << "Invalid operator. " << prompt;
    }
}

// (The old cin_validattion functions can be removed or commented out)

//Progress_BAR
void progressbar() {
    std::srand(time(NULL));
    for(int progress=0; progress!=100; progress+=std::rand()%20) {
        if(state==1) gotoxy(55,22);
        else gotoxy(55,22);
        if(progress>25) progress=25;
        std::cout<<"\x1B[32m[\033[0m\x1B[34m";
        for(int i=0; i<25; i++)
            if(i<progress) std::cout<<'-';
            else if(i==progress) std::cout<<'_';
            else std::cout<<' ';
        std::cout<<"\033[0m\x1B[32m]\033[0m ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if(progress==25) break;
    }
    std::cout<<std::endl;
    gotoxy(55,22);
    cout<<"                                                        ";
}

int source()//Source Viewer function
{
    char c;
    FILE *fp = fopen(__FILE__, "r");
    if (fp == NULL) return 1;
    do { c = fgetc(fp); putchar(c); } while (c != EOF);
    fclose(fp);
    return 0;
}

void Improvements()//Improvements and Bugs
{
    system("clear");
    gotoxy(1,2);
    layout();
    gotoxy(5,7);
    cout<<bold<<RED<<UNDERLINE<<"New Improvments and Bug Fixes:"<<cc;
    gotoxy(5,9);  cout<<bold<<blue<<"i.)Change in programming";
    gotoxy(5,10); cout<<bold<<yellow<<"ii.)New app Quadratic Eqn solver";
    gotoxy(5,11); cout<<bold<<blue<<"iii.)Quad Eqn solver can determine nature of roots";
    gotoxy(5,12); cout<<bold<<yellow<<"iv.)Added trial for quiz in registry editor by changing registry values.";
    gotoxy(5,13); cout<<bold<<blue<<"v.)Introduction of a brand new UI";
    gotoxy(5,14); cout<<bold<<red<<"vi.)Introduction of settings application";
    gotoxy(5,15); cout<<bold<<yellow<<"vii.)Parts of Registry Editor are accessible by normal user. Command :  registryeditor.";
    gotoxy(5,16); cout<<bold<<blue<<"viii.)Now you can change your User-ID";
    gotoxy(5,17); cout<<bold<<yellow<<"iX.)Password can be removed later via the settings application.";
    gotoxy(5,18); cout<<bold<<blue<<"x.)Option for system restore by reinstallation to solve several errors.";
    gotoxy(5,19); cout<<bold<<yellow<<"xi.)Added support for Kelvin in Temperature Converter.";
    gotoxy(5,20); cout<<bold<<blue<<"xii.)One can directly move into the prompt menu form registry editor.";
    gotoxy(5,21); cout<<bold<<green<<"Next version comming with more features"<<cc;
    getchar();
}

void login() //Latest Login function
{
    fstream file;
    logo();
    filename  = "file.txt";
    file.open(filename.c_str());
    if (file.good()) //If User Exists
    {
        gotoxy(4,9);
        reg_status=1;
        cout<<"  To begin press enter or type password(if you have created a User-ID).";
        gotoxy(40,12);
        cout<<"User-ID:";
        fstream file1;   file1.open("file.txt");
        file1>>name1;
        cout<<" "<<name1;
        fstream file2;
        file2.open("file2.txt");
        file2>>password1;
        file2.close();
        if(password1=="0")//if password is removed
        {
            getchar(); // replace with non‑blocking? maybe keep – it's just one key
            prompt();
        }
        else {
            gotoxy(40,13);
            cout<<"Password:";
            cout<<invisible;
            string pass = getStringWithClock(40,13, "", false); // use non‑blocking input
            password = pass;
            cout<<cc;
            if(password1==password) prompt();
            else if(password=="registryeditor") reg_edit();
            else if(password=="guess_it") source();
            else timerS();
        }
    }
    else //For Guest User
    {
        gotoxy(5,9);
        reg_status=1;
        cout<<" /* To just test the program (*with limited features) press enter */ ";
        gotoxy(40,13);
        cout<<"USER-ID: GUEST";
        cout<<" \x1B[36m ";
        getchar(); getchar();
        system("clear");
        ins = 9;
        reg_status=0;
        prompt();
    }
}

void layout()//main looks the floating form design
{
    gotoxy(1,1);
    system("clear");
    cout<<cc;
    gotoxy(1,2);
    cout<<"  "<<border"                                                                                                                                  "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t\t\t  "<<RED<<bold<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE<<"                                                    "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t                    "<<blue<<bold<<UNDERLINE<<" Version:5.01.08"<<CLOSEUNDERLINE<<cc<<cc<<cc<<"                                                       "<<border" "<<cc<<endl;
    //cout<<"  "<<border" "<<cc"                                                        "<<yellow<<bold"(EVALUATION_BUILD)"<<cc<< "                                                      "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                  "<<yellow<<bold"(Final Release Build C++ Based)"<<cc<< "                                               "<<border" "<<cc<<endl;
    for (int i=0; i<30; i++)
        cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border"                                                                                                                                  "<<cc<<endl;
    gotoxy(1,1);
}

void add_user()//User Creation menu
{
    system("clear");
    fstream f1,f2;
    string id,c,pass;
    system("clear");
    layout();
    gotoxy(5,10);
    cout<<UNDERLINE<<RED<<bold<<"Welcome to USER-ID Password Creation Wizard Ver: 1.7.9"<<cc;
    gotoxy(5,11); cout<<"FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER";
    gotoxy(5,12); cout<<yellow<<"PLease create a user id password for safety reasons:"<<cc;
    gotoxy(5,13); cout<<"User-Id:"; cin>>id; // could be replaced with getStringWithClock, but it's one‑time
    f1.open("file.txt",ios::out);
    f1<<id;
    f1.close();
    gotoxy(5,14); cout<<"Do you want to create a password(y/n):"; cin>>c; // also one‑time
    if (c=="y")//If password is to be created
    {
        gotoxy(5,15); cout<<"Enter password:"; cin>>pass;
        if(pass=="0")
        {
            gotoxy(5,16); cout<<RED<<bold<<"The password cannot be 0"<<cc<<cc;
            cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
            gotoxy(5,17); cout<<blue<<bold<<"Press Enter to continue by recreating user.";
            getchar(); getchar(); add_user();
        }
        else
        {
            f2.open("file2.txt",ios::out);
            f2<<pass;
            f2.close();
        }
    }
    else
    {
        pass="0";
        f2.open("file2.txt",ios::out);
        f2<<pass;
        f2.close();
    }
    gotoxy(5,16); cout<<RED<<bold<<"You are Successfull in creating a user."<<cc;
    getchar(); getchar();
}

void install()//Installer for setting Reg_Values
{
    fstream t,q,tc,c,eqn,qd,at;
    t.open("TicTacToe.txt",ios::out); t<<reg; t.close();
    q.open("Quiz.txt",ios::out); q<<reg; q.close();
    tc.open("TC.txt",ios::out); tc<<reg; tc.close();
    c.open("Calc.txt",ios::out); c<<reg; c.close();
    eqn.open("solve.txt",ios::out); eqn<<reg; eqn.close();
    qd.open("quad_solve.txt",ios::out); qd<<reg; qd.close();
    at.open("ATC.txt",ios::out); at<<reg; at.close();
}

void color_change()
{
    system("clear");
    gotoxy(1,1); layout(); gotoxy(5,8);
    cout<<UNDERLINE<<RED<<bold"Welcome to background border color changer wizard."<<cc;
    gotoxy(5,9); cout<<yellow<<bold"Available options:"<<cc;
    gotoxy(5,10); cout<<" -------------------------------------------";
    gotoxy(5,11); cout<<"|    "<<green<<bold"COLOR_NAME"<<cc"       |        "<<green<<bold"SAMPLE"<<cc"       |";
    gotoxy(5,12); cout<<"|"<<bold<<blue<<" 1.) Red            "<<cc<<" |          "<<B1<<"  "<<cc<<"         |";
    // ... (rest of color table unchanged)
    gotoxy(5,29); cout<<purple<<bold"Enter choice (To exit press e): ";
    string colorr; cin>>colorr;
    if(colorr=="1"||colorr=="2"||colorr=="3"||colorr=="4"||colorr=="5"||colorr=="6"||colorr=="7"||colorr=="8"||colorr=="9"||colorr=="10"||colorr=="11"||colorr=="12"||colorr=="13"||colorr=="14"||colorr=="15")
    {
        fstream color;
        color.open("looks.h",ios::out);
        // ... write appropriate macro
        color.close();
        cout<<"\a\a\a\a"<<flush;
        gotoxy(30,10); system("clear");
        cout<<RED<<bold" Program is shuttng Down to save the changes. Restart to to see the effect!!!"<<cc;
        sleep(1); exit(0);
    }
    else if(colorr=="e") settings();
    else { gotoxy(5,30); cout<<"No command."; getchar(); getchar(); color_change(); }
}

void USER_ACCOUNTS()
{
    system("clear"); gotoxy(1,1); layout(); gotoxy(5,8);
    cout<<UNDERLINE<<red<<bold"Welcome to User Account Control Panel:"<<cc;
    gotoxy(5,9); cout<<yellow<<bold"Pick a task: ";
    gotoxy(5,10); cout<<green<<bold"1.) Add /Remove /Create Password for your accounts";
    gotoxy(5,11); cout<<"2.) Change Your User_ID.";
    gotoxy(5,12); cout<<"3.) EXIT.";
    gotoxy(5,13); cout<<bold<<blue"Enter choice(1-3): "<<cc;
    cin>>choice;
    if(choice=="1") password_change();
    else if(choice=="2") userid_change();
    else if(choice=="3") settings();
    else { gotoxy(5,25); cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
           getchar(); getchar(); USER_ACCOUNTS(); }
    getchar(); getchar(); USER_ACCOUNTS();
}

void RESET_AND_RESTORE()
{
    system("clear"); gotoxy(1,1); layout(); gotoxy(5,8);
    cout<<UNDERLINE<<red<<bold"Welcome to Reset and Restore Panel:"<<cc;
    gotoxy(5,9); cout<<yellow<<bold"Pick a task: ";
    gotoxy(5,10); cout<<blue<<bold"1.) Reset your applications";
    gotoxy(5,11); cout<<"2.) Restore your system by re-installing it.";
    gotoxy(5,12); cout<<"3.) EXIT.";
    gotoxy(5,13); cout<<red<<bold"Warning!! Any of the above task(command) will reset all your applications thus delete /alter data. ";
    gotoxy(5,14); cout<<green<<bold"Do you want to continue(y/n)?";
    cin>>a;
    if(a=="y"||a=="Y")
    {
        gotoxy(5,15); cout<<green<<bold"Enter choice(1-3): "<<cc;
        cin>>choice;
        if(choice=="1") { reg=0; install(); }
        else if(choice=="2") IP();
        else if(choice=="3") settings();
        else { gotoxy(5,25); cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
               getchar(); getchar(); RESET_AND_RESTORE(); }
        getchar(); getchar(); RESET_AND_RESTORE();
    }
    else settings();
}

void PERSONALIZATION()
{
    system("clear"); gotoxy(1,1); layout(); gotoxy(5,8);
    cout<<red<<UNDERLINE<<bold"Welcome to Personalization Panel:"<<cc;
    gotoxy(5,9); cout<<yellow<<bold"Pick a task: ";
    gotoxy(5,10); cout<<green<<bold"1.) Change your border color.";
    gotoxy(5,11); cout<<"2.) EXIT.";
    gotoxy(5,12); cout<<blue<<bold"Enter choice(1-2): "<<cc;
    cin>>choice;
    if(choice=="1") color_change();
    else if(choice=="2") settings();
    else { gotoxy(5,25); cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
           getchar(); getchar(); PERSONALIZATION(); }
    getchar(); getchar(); PERSONALIZATION();
}