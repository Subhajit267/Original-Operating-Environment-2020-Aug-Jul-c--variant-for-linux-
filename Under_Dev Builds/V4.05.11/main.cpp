//VER:4.0 dev build
#include<chrono> //for sleeping             //Basically jotogulo predefined function commonly use kori sei sob mention korlam  :)
#include<thread> // --do-- 
#include<cstdlib>//for random increments
#include<ctime>// --do-- 
#include<iostream>
#include <stdlib.h>
#include<iomanip>
#include <string>
#include<fstream>
#include <random>
#include <stdio.h>
#include<unistd.h>
#include <string>
#define bold "\x1B[1m"//ascii escape sequences jate bar bar mention na korte hoi tai age predifine korechi
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
#include <random>
#include"looks.h"
#define border2 "\x1B[41m"
#define border3 "\x1B[104m"
void settings();
using namespace std;
#include "sources.h"
#include "Sources2.h"
#include "programs.h"
/*  And an ernest request to everyperson who will view this source code
    PLEASE dont change my name from the secret about menu
    You may change it from the start screen but not from anywhere else
*/
//New layout Established for this file

void prompt()//Main controller
{    system("clear");
    gotoxy(1,1);
    layout();
    logo();
    cout<<red<<bold<<UNDERLINE;
    gotoxy(32,10);
    cout<<"Operating Environment ver: 4.05.11";
    cout<<cc;
    cout<<green<<bold;
    gotoxy(32,11);
    cout<<"Type help to get list of commands";
    cout<<cc;
    string command;
    while(true)
    {
        if(ins==9)//if guest user 
        {cout<<"\a"<<flush;
            gotoxy(32,12);
            cout<<"Only available commands are install, login(use it to re login) and exit";
            gotoxy(32,13);
            cout<<"Command->";
            cin>>command;
            if(command=="install")
            {
                fstream file;
                string word, t, q, filename;
                    bs=1;
                filename = "file.txt";                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
                {  gotoxy(32,14);cout<<"Already  installed.";
                cout<<"\a\a\a"<<flush;
                  gotoxy(32,16);
                  cout<<"Type login and re login with your user ID password(if exists).";
                   getchar();
                   getchar();
                    prompt();
                }
                else{
                    IP();
                    prompt();
                }
            }
            else if(command=="exit")
            {      cout<<red<<bold" Status: You are about to exit.";
            cout<<"\a\a"<<flush;
                exit(0);
            }
            else if(command=="reg_edit")
            {cout<<"\a"<<flush;reg_status=0;
                reg_edit();
            }
            else if(command=="login")
            {                 fstream file;
                string word, t, q, filename;
                filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) 
                { ins=0;
                }
                else{
                    ins=9;
                }
                
                gotoxy(1,1);
                system("clear");
                layout();
                logo();
                login();
            }
            else
            {   fstream file;
                string word, t, q, filename;
                filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) 
                { gotoxy(32,15);
                    cout<<red<<bold"I see you trying to access user features without a password. But access denied."<<cc;
                cout<<"\a\a\a"<<flush;
                  getchar();
                   getchar();
                    prompt();
                }
                else{
                    gotoxy(32,20);
                    cout<<red<<bold" Status: No Command";
                    getchar();
                    getchar();
                    prompt();
                }
            }
        }
        else//If a proper user
        {  gotoxy(88,10);
        reg_status=0;
                       cout<<bold<<purple<<"Welcome"<<" "<<cyan<<bold<<name1;
            gotoxy(32,13);
            cout<<blue<<bold<<"Command->"<<cc;
             cin>>command;
            if (command=="Help"||command=="HELP"||command=="help")//Help command to make the command interface easy
            {   gotoxy(35,14);
                cout<<yellow<<bold<<"Type:"<<cc;
                 gotoxy(35,15);cout<<blue<<bold;
                cout<<"\tTicTacToe";//not found
                 gotoxy(35,16);cout<<red<<bold;
                cout<<"\tCalculator";//thinking 
                 gotoxy(35,17);cout<<blue<<bold;
                cout<<"\tQuiz";//new question set on the go
                 gotoxy(35,18);cout<<red<<bold;
                cout<<"\tTemp_Conv";//added support for kelvin
                 gotoxy(35,19);cout<<blue<<bold;
                cout<<"\teqn_solve";//not found
                 gotoxy(35,20);cout<<red<<bold;
                cout<<"\tquad_eqn_solve, to open the applications(if installed).";//new program
                 gotoxy(35,21);cout<<blue<<bold;
                cout<<yellow<<bold<<"Type:"<<cc;
                 gotoxy(35,22);cout<<red<<bold;
                cout<<"\texit: To exit .";
                 gotoxy(35,23);cout<<blue<<bold;
                cout<<"\tver: To see version number";
                 gotoxy(35,24);cout<<red<<bold;
                cout<<"\tinst_all: To install al applications except TicTacToe and Quiz at once.";
                 gotoxy(35,25);cout<<blue<<bold;
                cout<<"\tsettings: To change your existing settings.";
                 gotoxy(35,26);cout<<red<<bold;
                cout<<"\tType 'registryeditor' to enter the mode";
                 gotoxy(35,27);cout<<blue<<bold;
                cout<<"\tTo re-login type login.";
                 gotoxy(35,28);cout<<red<<bold;
                cout<<"\tTo install an app from above  list type inst_'with app name'";
                 gotoxy(35,29);cout<<blue<<bold;
                cout<<"\tTo uninstall an app from above  list type unst_'with app name'";
                getchar();
                    getchar();
                    prompt();
            }
            else if (command=="TicTacToe"||command=="tictactoe"||command=="TICTACTOE")
            {   bs=1;
                fstream f;
                f.open("TicTacToe.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
                  bootscreen();
                  selector_t();
                }
                else 
                {gotoxy(32,15);
                    cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
            else if (command=="Quiz"||command=="QUIZ"||command=="quiz")
            {fstream f;
                f.open("Quiz.txt",ios::in);
                f>>reg;
                    bs=2;
               if (reg==1) 
                {bootscreen();
                 start();
                 }
                else 
                { gotoxy(32,15);
                    cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
             else if (command=="TEMP_CONV"||command=="temp_conv"||command=="Temp_Conv")
            {  bs=3;
               fstream f;
                f.open("TC.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {bootscreen();
                 tc();
                }
                else 
                { gotoxy(32,15);
                    cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
            else if(command=="VER"||command=="ver")
            {gotoxy(32,15);
               cout<<red<<bold<<"   VER: 4.05.11(DEV)";
                getchar();
                getchar();
                prompt();
            }
            else if(command=="exit"||command=="EXIT"||command=="Exit")
            {
                cout<<"\a\a\a\a"<<flush;
                gotoxy(30,10);
                system("clear");
                cout<<RED<<bold" Program is shuttng Down. Thank You for using. Have a good time. Bye!!!"<<cc;
                sleep(1);
                exit(0);
                prompt();
            }
            else if(command=="inst_TicTacToe")
            {
                v=1;
                bs=1;
               fstream f;
                f.open("TicTacToe.txt",ios::in);
                f>>reg;
                if (reg==1) 
                { gotoxy(32,15);
                    cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                
                else 
                {
                 bootscreen();
                    installer();
                }
            }
            else if(command=="inst_Temp_Conv"||command=="inst_temp_conv")
            {
                v=3;
                bs=3;
               fstream f;
                f.open("TC.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {gotoxy(32,15);
                    cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                else 
                {
                 bootscreen();
                    installer();
                    tc();
                }
            }
            else if(command=="inst_Calculator")
            {
                bs=4;          
                v=4;     // opening file
                fstream f;
                f.open("Calc.txt",ios::in);
                f>>reg;
                if (reg==1) 
                { gotoxy(32,15);
                    cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                else 
                {
                 bootscreen();
                    installer();
                    calc();
                }
            }
              
            else if(command=="inst_Quiz")
            {
                v=2;
                bs=2;
             fstream f;
                f.open("Quiz.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {gotoxy(32,15);
                    cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                else 
                {
                 bootscreen();
                    installer();
                }
            }
             else if(command=="Calculator"||command=="calculator")
            {
                bs=4;
                fstream f;
                f.open("Calc.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
                   bootscreen();
                   calc();
                }
                else 
                {    gotoxy(32,15);  cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
            else if(command=="eqn_solve")
            {
                bs=6;
                fstream f;
                f.open("solve.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
                   bootscreen();
                   get_Eqn();
                }
                else 
                {gotoxy(32,15);cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
             else if(command=="quad_eqn_solve")
            {
                bs=7;
                fstream f;
                f.open("quad_solve.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
                   bootscreen();
                   quad_eqn_solve();
                }
                else 
                {gotoxy(32,15);cout<<red<<bold"  Status: Non installed yet"<<cc;
                cout<<"\a\a"<<flush;
                   getchar();
                    getchar();
                    prompt();
                }
            }
            else if(command=="inst_eqn_solve")
            {
                v=6;
                bs=6;
               fstream f;
                f.open("solve.txt",ios::in);
                f>>reg;
                if (reg==1) 
                { gotoxy(32,15); cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                else 
                {
                 bootscreen();
                    installer();
                    get_Eqn();
                }
            }
             else if(command=="inst_quad_eqn_solve")
            {
                v=7;
                bs=7;
               fstream f;
                f.open("quad_solve.txt",ios::in);
                f>>reg;
                if (reg==1) 
                { gotoxy(32,15); cout<<yellow<<bold"  Status: Already installed"<<cc;
                cout<<"\a"<<flush;
                getchar();
                getchar();
                prompt();
                }
                else 
                {
                 bootscreen();
                    installer();
                    quad_eqn_solve();
                }
            }
            else if(command=="unst_eqn_solve")
            { fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="unst_TicTacToe")
            {   fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="unst_Temp_Conv")
            { fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="unst_Calculator")
            { fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="unst_quad_eqn_solve")
            { fstream f;
                reg =0;
                f.open("quad_solve.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="unst_Quiz")
            { fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();gotoxy(32,15);
                cout<<blue<<bold<<" Unistallation finished."<<cc;
                cout<<"\a\a\a\a\a\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
            else if(command=="registryeditor")
            {cout<<"\a\a\a\a\a\a\a"<<flush;reg_status=0;
                reg_edit();
            }
            else if(command=="display_source")
            {cout<<"\a"<<flush;
              source();
              getchar();
              system("clear");
            }
            else if(command=="inst_all")
            {
                reg=1;
                 fstream tc,d,c,eqn;
                  tc.open("TC.txt",ios::out);
                  tc<<reg;
                  tc.close();
                  c.open("Calc.txt",ios::out);
                  c<<reg;
                  c.close();
                    d.open("Calc.txt",ios::out);
                  d<<reg;
                  d.close();
                  eqn.open("solve.txt",ios::out);
                  eqn<<reg;
                  eqn.close();gotoxy(32,15);
                  cout<<green<<bold<<"Successfully completed the command";
                  getchar();
                getchar();
                prompt();
            }
            else if(command=="settings"||command=="Settings"||command=="SETTINGS")
            {
                settings();
            }
            else if(command=="login"||command=="Login")
            {
                system("clear");layout();login();
            }
             else
            {   gotoxy(32,15) ;
                cout<<red<<bold<<"  No such command"<<cc;
                 cout<<"\a"<<flush;
                 getchar();
                getchar();
                prompt();
            }
        }
    }
}
int main()
{  bs=0;
   bootscreen();
//  start();
     fstream file;
            string word, t, q, filename;
            filename = "file.txt";      // opening file
            file.open(filename.c_str());
            if (file.good()) 
            {system("clear");
            layout();
                logo();
                login();
                prompt();
            }
            else 
            {
                IP();
            }
    return 0;
}
void IP()
{
gotoxy(1,1);
layout();
logo();
gotoxy(10,8);
 string c;
 reg_status=1;
    cout<<BLUE<<bold<<"Do you want to directly install this application or you want to use it once before installation?(Enter choice below)."<<cc<<cc;
     gotoxy(32,10);
    cout<<purple<<bold<<UNDERLINE"Help Me Decide:"<<cc;
    gotoxy(32,12);
    cout<<yellow<<bold<<"If you wish to install the program directly on the browser without testing for once press y.";
     gotoxy(32,13);
    cout<<"If you want to test the progarm before installing i.e. if you want to have a look at the user ";
     gotoxy(32,14);
    cout<<"interface press n and it will load you into the guest user login screen. Enter GUEST or Guest  ";
     gotoxy(32,15);
    cout<<"there to login. As it is trial so only two commands that is install and exit would be there.";
     gotoxy(32,18);
    cout<<cyan<<bold<<"Enter your choice(y/n):";
  cout<<invisible;
  cin>>c;
  cout<<cc;
    if(c=="n"||c=="N")
      {  
          system("clear");
          gotoxy(1,1);
          layout();
          logo();
         gotoxy(5,7);
      cout<<"After completeion of your trial the program will stop. You have to restart the setup to continue.";
     login();
      }
     else if(c=="registryeditor")
     {
         reg_edit();
     }
     else if(c=="prompt")
     {   reg_status=1;ins=0;
        prompt();
     }
      else if(c=="y"||c=="Y")
    {system("clear");
    layout();
    logo();
        gotoxy(32,8);
  cout<<UNDERLINE<<red<<bold<<"While the game is loading let us know its working:"<<CLOSEUNDERLINE;
  gotoxy(32,10);
   cout<<yellow<<"At first type help command at the prompt.";
   gotoxy(32,11);
   cout<<"You will be getting a list of available commands use it  "<<CLOSEUNDERLINE;
   gotoxy(88,10);
   cout<<purple<<"  Desingned for ease"<<cc;
   gotoxy(32,12);
   cout<<yellow<<"to install your desired program"<<cc;
   gotoxy(88,11);
   cout<<purple<<"  For ease in using "<<cc;
   gotoxy(32,13);
   cout<<yellow<<"Enjoy using it!!!"<<cc;
   gotoxy(88,12);
   cout<<purple<<"  softwares"<<cc;
    gotoxy(88,17);
    cout<<green<<"DEVELOPER:"<<RED<<" Subhajit Halder";
  gotoxy(2,6);
 progressbar();
 sleep(6);
add_user();
      reg=0;
          install();
          Improvements();
          getchar();
          gotoxy(1,2);
          layout();
          login();
    }
}
void reg_edit()
{gotoxy(1,1);
    layout();
    gotoxy(5,7);
    cout<<bold<<UNDERLINE<<red<<"Welcome to Registry Editor version:3.5.0(For Power Users)."<<cc;
    gotoxy(5,8);
    cout<<green<<bold<<"Available commands:"<<cc;
    gotoxy(5,9);
    cout<<yellow<<bold<<"\ta.)install";
    gotoxy(5,10);
    cout<<"\tb.)temp";
    gotoxy(5,11);
    cout<<"\tc.)exit";
    gotoxy(5,12);
    cout<<"\td.)reset";
    gotoxy(5,13);
    cout<<"\te.)prompt";
    gotoxy(5,14);
    cout<<"\tf.)add_key (Only for Quiz and TicTacToe)";
    gotoxy(5,15);
    cout<<"\tg.)user";
    gotoxy(5,16);
    cout<<"\th.)help (It is adviced to use help command first to gets uses of available commands."<<cc;;
    while(true)
    {string command;
      gotoxy(5,17);
      cout<<"Command->";
      cin>>command;
      fstream t,q,tc,c,eqn,d;
      reg=1;
            if(command=="install")
            {    if(reg_status==1)
                {install();
                  gotoxy(5,18);
                  cout<<cyan<<bold<<"Succesfully completed the command";
                  getchar(); getchar();
                  reg_edit();
                }
                  else 
                  {  gotoxy(5,18);
                  cout<<cyan<<bold<<"Succesfully completed the command";
                  getchar(); getchar();
                  tc.open("TC.txt",ios::out);
                  tc<<reg;
                  tc.close();
                  c.open("Calc.txt",ios::out);
                  c<<reg;
                  c.close();
                    d.open("Calc.txt",ios::out);
                  d<<reg;
                  d.close();
                  eqn.open("solve.txt",ios::out);
                  eqn<<reg;
                  eqn.close();
                  reg_edit();
                      
                  }
            }
            else if(command=="add_key")
            {if(reg_status==1)
             {
                gotoxy(5,18);
                cout<<"\tCommand->";
                cin>>command;
                reg=1;
                        if(command=="both")
                        {
                          t.open("TicTacToe.txt",ios::out);
                          t<<reg;
                          t.close();
                          q.open("Quiz.txt",ios::out);
                          q<<reg;
                          q.close();
                        }
                        else if(command=="quiz")
                        {
                            q.open("Quiz.txt",ios::out);
                          q<<reg;
                          q.close();
                        }
                        else if(command=="tictactoe");
                        {
                             t.open("TicTacToe.txt",ios::out);
                          t<<reg;
                          t.close();
                        }
                        gotoxy(5,18);
                  cout<<cyan<<bold"Succesfully completed the command"<<cc;
                  getchar(); getchar();
                  reg_edit();
                
             }
                  else
                  {gotoxy(5,20);
                cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
                getchar(); getchar();
                reg_edit();
                      
                  }
                  
                        
            }
            else if(command=="exit")
            {
                layout();
                logo();
                login();
            }
            else if(command=="temp")
            {gotoxy(5,18);
                    cout<<"Command->";
                    cin>>command;
                    if(command=="TTT"||command=="ttt")
                    {
                        if(reg_status==1)
                        {
                        computer_vs_player();
                            
                        }
                          else 
                          {gotoxy(5,20);
                cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
                getchar(); getchar();
                reg_edit();
                              
                          }
                    }
                    else if(command=="quiz")
                    {if(reg_status==1)
                       { start();}
                          else 
                         { trial=4;
                          start();}
                    }
                    else
                    {gotoxy(10,20);
                        cout<<red<<bold"temp command is available for only one program(s)";
                         getchar(); getchar();
                         reg_edit();
                    }
            }
            else if(command=="user")
            {if(reg_status==1)
                    {
                fstream file;
                string word, t, q, filename;
                filename = "file.txt";      // opening file
                file.open(filename.c_str());
                        if (file.good()) 
                        {gotoxy(5,19);
                           cout<<RED<<bold"Warning! This command will reset all your user-id password"<<"\a\a\a\a\a\a\a\a\a\a"<<flush;
                           gotoxy(5,20);
                           cout<<"Do you want to continue:"<<cc;
                           char a;
                           cin>>a;
                                   if(a=='y')
                                   {
                                       add_user();
                                       getchar();
                                       gotoxy(5,25);
                                          cout<<cyan<<bold"Succesfully completed the command";
                                          getchar(); getchar();
                                          reg_edit();
                                   }
                                   else 
                                    {gotoxy(5,19);
                                       cout<<RED<<bold<<"Execution Cancelled!!";
                                       getchar(); getchar();
                                       reg_edit();
                                    }
                        }
                        else 
                        {add_user();
                        }
                    }
                    else 
                                    {gotoxy(5,19);
                                       cout<<RED<<bold<<"Execution Cancelled!!";
                                       getchar(); getchar();
                                       reg_edit();
                                    }
          
            }
            else if(command=="reset")
            {gotoxy(5,19);
                           cout<<RED<<bold"Warning! This command will reset all your applications."<<"\a\a\a\a\a\a\a\a\a\a"<<flush;
                           gotoxy(5,20);
                           cout<<"Do you want to continue:"<<cc;
                           char a;
                           cin>>a;
                                   if(a=='y')
                                   {reg=0;
                                        install();
                                         gotoxy(5,25);
                                          cout<<cyan<<bold<<"Succesfully completed the command";
                                          getchar(); getchar();
                                          reg_edit();
                                   }
                                   else 
                                    {gotoxy(5,19);
                                       cout<<RED<<bold<<"Execution Cancelled!!";
                                       getchar(); getchar();
                                       reg_edit();
                                    }
            }
            else if(command=="prompt"||command=="Prompt")
            {
                system("clear");gotoxy(1,1);layout();logo();
                fstream file;
                string filename;
                filename = "file.txt";
                file.open(filename.c_str());
                if (file.good()) 
                    ins=0;
                else
                    ins=9;
                
                prompt();
            }
            else if(command=="help")
            {gotoxy(5,20);
                cout<<blue<<bold<<" Welcome to HELP Documenntation Ver: 1.0. :"<<cc;
                gotoxy(5,21);
                cout<<"\ta.)install: To install all the programs at once.";
                gotoxy(5,22);
                cout<<"\tb.)add_key (Only for Quiz and TicTacToe): To install only TicTacToe and Quiz[with admin previleges only].";
                gotoxy(5,23);
                cout<<"\tc.)exit: Exit the Registry Editor and open the login screen.";
                gotoxy(5,24);
                cout<<"\td.)temp: To access a program temporaily(For TicTacToe and QUIZ).";
                gotoxy(5,25);
                cout<<"\te.)user: To add a new user or to do password bypass.";
                gotoxy(5,26);
                cout<<"\tf.)reset: To uninstall all applications.";
                gotoxy(5,27);
                cout<<"\tg.)clear: To clear the output screen.";
                getchar(); getchar();
                reg_edit();
            }
            
             else if(command=="reset")
            {    if(reg_status==1){gotoxy(5,19);
                               cout<<RED<<bold"Warning! This command will reset all your applications."<<"\a\a\a\a\a\a\a\a\a\a"<<flush;
                               gotoxy(5,20);
                               cout<<"Do you want to continue:"<<cc;
                               char a;
                               cin>>a;
                                       if(a=='y')
                                       {reg=0;
                                            install();
                                             gotoxy(5,25);
                                              cout<<cyan<<bold<<"Succesfully completed the command";
                                              getchar(); getchar();
                                              reg_edit();
                                       }
                                       else 
                                        {gotoxy(5,19);
                                           cout<<RED<<bold<<"Execution Cancelled!!";
                                           getchar(); getchar();
                                           reg_edit();
                                        }
                                   }
                else {gotoxy(5,20);
                    cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
                    getchar(); getchar();
                    reg_edit();}
            }
            else if(command=="clear"||command=="cls")
            {
                system("clear");
                reg_edit();
            }
            else if(command=="help")
            {gotoxy(5,20);
                cout<<blue<<bold<<" Welcome to HELP Documenntation Ver: 1.0. :"<<cc;
                gotoxy(5,21);
                cout<<"\ta.)install: To install all the programs at once.";
                gotoxy(5,22);
                cout<<"\tb.)add_key (Only for Quiz and TicTacToe): To install only TicTacToe and Quiz[with admin previleges only].";
                gotoxy(5,23);
                cout<<"\tc.)exit: Exit the Registry Editor and open the login screen.";
                gotoxy(5,24);
                cout<<"\td.)temp: To access a program temporaily(For TicTacToe and QUIZ).";
                gotoxy(5,25);
                cout<<"\te.)user: To add a new user or to do password bypass.";
                gotoxy(5,26);
                cout<<"\tf.)reset: To uninstall all applications.";
                gotoxy(5,27);
                cout<<"\tg.)prompt: directly jump into the prompt screen rather than logging in.";
                getchar(); getchar();
                reg_edit();
            }
            else
            {gotoxy(5,20);
                cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
                getchar(); getchar();
                reg_edit();
            }
        
    }
}