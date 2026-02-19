//VER:5.01.08 Release build
//Last C++ complete variant for linux
//Last Updated: 19/02/2026
//Author: Subhajit Halder
#include<chrono> //Basically jotogulo predefined function commonly use kori sei sob mention korlam  :)
#include<thread>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<fstream>
#include<random>
#include<stdio.h>
#include<unistd.h>
#include<string>
#include<random>
#include<limits>   // added for numeric_limits
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
void settings();
using namespace std;
#include "sources.h"
#include "Sources2.h"
#include "programs.h"
/*  
    And an ernest request to everyperson who will view this source code
    PLEASE dont change my name from the secret about menu
    You may change it from the start screen but not from anywhere else
*/
void prompt()//Main controller
{	
    system("clear");
	gotoxy(1,1);
	layout();
	logo();
	gotoxy(32,10);
	cout<<red<<bold<<UNDERLINE<<"Operating Environment ver: 5.01.08 "<<cc;
	string command;
	while(true)
	{
		if(ins==9)//if guest user
		{	cout<<"\a"<<flush;
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
				{	gotoxy(32,14);
					cout<<"Already  installed.";
					cout<<"\a\a\a"<<flush;
					gotoxy(32,16);
					cout<<"Type login and re login with your user ID password(if exists).";
					getchar();
					getchar();
					prompt();
				}
				else {
					IP();
					prompt();
				}
			}
			else if(command=="exit")
			{	cout<<red<<bold" Status: You are about to exit.";
				cout<<"\a\a"<<flush;
				exit(0);
			}
			else if(command=="reg_edit")
			{	cout<<"\a"<<flush;
				reg_status=0;
				reg_edit();
			}
			else if(command=="login")
			{	fstream file;
				string word, t, q, filename;
				filename = "file.txt";
				file.open(filename.c_str());
				if (file.good())
				{	ins=0;
				}
				else {
					ins=9;
				}

				gotoxy(1,1);
				system("clear");
				layout();
				logo();
				login();
			}
			else
			{	fstream file;
				string word, t, q, filename;
				filename = "file.txt";
				file.open(filename.c_str());
				if (file.good())
				{	gotoxy(32,15);
					cout<<red<<bold"I see you trying to access user features without a valid installation/ user id creation. But access denied."<<cc;
					cout<<"\a\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
				else {
					gotoxy(32,20);
					cout<<red<<bold" Status: No Command";
					getchar();
					getchar();
					prompt();
				}
			}
		}
		else//If a proper user
		{	gotoxy(32,11);
			cout<<green<<bold<<"Type help to get list of commands"<<cc;
			gotoxy(88,10);
			reg_status=0;
			cout<<bold<<purple<<"Welcome"<<" "<<cyan<<bold<<name1;
			gotoxy(32,13);
			cout<<blue<<bold<<"Command->"<<cc;
			cin>>command;
			if (command=="Help"||command=="HELP"||command=="help")//Help command to make the command interface easy
			{	gotoxy(35,14);
				cout<<yellow<<bold<<"Type:"<<cc;
				gotoxy(35,15);
				cout<<blue<<bold<<"\tTicTacToe";//TicTacToe
				gotoxy(35,16);
				cout<<red<<bold<<"\tCalculator";//Calculator
				gotoxy(35,17);
				cout<<blue<<bold<<"\tQuiz";//Quiz
				gotoxy(35,18);
				cout<<red<<bold<<"\tTemp_Conv";//Temperature_Converter
				gotoxy(35,19);
				cout<<blue<<bold<<"\teqn_solve";//Pair of linear equations in two variables
				gotoxy(35,20);
				cout<<red<<bold<<"\tquad_eqn_solve, to open the applications(if installed).";//Quadratic Equation SOlver
				gotoxy(35,21);
				cout<<yellow<<bold<<"Type:"<<cc;//New Section
				gotoxy(35,22);
				cout<<red<<bold<<"\texit: To exit .";//Exit COmmand
				gotoxy(35,23);
				cout<<blue<<bold<<"\tver: To see version number";//Version Number Command
				gotoxy(35,24);
				cout<<red<<bold<<"\tinst_all: To install al applications except TicTacToe and Quiz at once.";//Installer for programs
				gotoxy(35,25);
				cout<<blue<<bold<<"\tsettings: To change your existing settings.";//Settings Application
				gotoxy(35,26);
				cout<<red<<bold<<"\tType 'registryeditor' to enter the mode"; //Registry KEy modifier/ manipulator.
				gotoxy(35,27);
				cout<<blue<<bold<<"\tTo re-login type login.";//Login
				gotoxy(35,28);
				cout<<red<<bold<<"\tTo install an app from above  list type inst_'with app name'";//Install command for individual Application
				gotoxy(35,29);
				cout<<blue<<bold<<"\tTo uninstall an app from above  list type unst_'with app name'";//Un-install command for individual Application
				getchar();
				getchar();
				prompt();//Since Cls command has been removed hence after completion of a command the program returns too the origin
			}
			else if (command=="TicTacToe"||command=="tictactoe"||command=="TICTACTOE")//If TicTacToe is installed
			{	bs=1;//Registry key for the bootscreen to chnage it  for tictactoe
				fstream f;//opening file containing installation info
				f.open("TicTacToe.txt",ios::in);
				f>>reg;
				if (reg==1) //If installed
				{
					bootscreen();
					selector_t();
				}
				else //If not installed
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if (command=="Quiz"||command=="QUIZ"||command=="quiz")//If quiz is installed
			{	fstream f;
				f.open("Quiz.txt",ios::in);
				f>>reg;
				bs=2;//Changing bootscreen
				if (reg==1) //Checking installation state
				{	bootscreen();
					start();
				}
				else
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="ar(t_c)")
			{	fstream f;
				f.open("ATC.txt",ios::in);
				f>>reg;
				bs=8;//Changing bootscreen
				if (reg==1) //Checking installation state
				{	bootscreen();
					atc();
				}
				else
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="inst_ar(t_c)")//Installer command for Area of Triangle
			{
				v=8;//Activation required hence v=1
				bs=8;
				fstream f;
				f.open("ATC.txt",ios::in);
				f>>reg;
				if (reg==1) //Error handling if already installed
				{	gotoxy(32,15);
					cout<<yellow<<bold"  Status: Already installed"<<cc;
					cout<<"\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
				else //running the installer
				{
					bootscreen();
					installer();
				}
			}
			else if (command=="TEMP_CONV"||command=="temp_conv"||command=="Temp_Conv")//If temperature converter is installed
			{	bs=3;//Changing bootscreen
				fstream f;//Checking installation state
				f.open("TC.txt",ios::in);
				f>>reg;
				if (reg==1)
				{	bootscreen();
					tc();
				}
				else
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="VER"||command=="ver")//Version command
			{	gotoxy(32,15);
				cout<<red<<bold<<"   VER: 4.23.09(DEV)";
				getchar();
				getchar();
				prompt();
			}
			else if(command=="whoami"||command=="list_ID")//username identifier
			{	gotoxy(32,15);
				cout<<red<<bold<<name1;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="exit"||command=="EXIT"||command=="Exit")//exit command
			{
				cout<<"\a\a\a\a"<<flush;
				gotoxy(30,10);
				system("clear");
				cout<<RED<<bold" Program is shuttng Down. Thank You for using. Have a good time. Bye!!!"<<cc;
				sleep(1);
				exit(0);
				prompt();
			}
			else if(command=="inst_TicTacToe")//Installer command for TicTacToe
			{
				v=1;//Activation required hence v=1
				bs=1;
				fstream f;
				f.open("TicTacToe.txt",ios::in);
				f>>reg;
				if (reg==1) //Error handling if already installed
				{	gotoxy(32,15);
					cout<<yellow<<bold"  Status: Already installed"<<cc;
					cout<<"\a"<<flush;
					getchar();
					getchar();
					prompt();
				}

				else //running the installer
				{
					bootscreen();
					installer();
				}
			}
			else if(command=="inst_Temp_Conv"||command=="inst_temp_conv")//Installer for Temperature_Converter
			{
				v=3;//Activation not required
				bs=3;//CHnaging bootscreen
				fstream f;
				f.open("TC.txt",ios::in);
				f>>reg;
				if (reg==1) //If already installed
				{	gotoxy(32,15);
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
			else if(command=="inst_Calculator")//Installer for calculator
			{
				bs=4; //Changing bootscreen
				v=4; //activation required
				fstream f;
				f.open("Calc.txt",ios::in);
				f>>reg;
				if (reg==1) //If already installed
				{	gotoxy(32,15);
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

			else if(command=="inst_Quiz")//Installer for quiz
			{
				v=2;//Activation required
				bs=2;
				fstream f;
				f.open("Quiz.txt",ios::in);
				f>>reg;
				if (reg==1)
				{	gotoxy(32,15);
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
			else if(command=="Calculator"||command=="calculator")//COmmand for calculator
			{
				bs=4;//At first changing registry value to bring appropriate bootscreen
				fstream f;
				f.open("Calc.txt",ios::in);//Openong the file for checking installation state
				f>>reg;
				if (reg==1) //If installed
				{
					bootscreen();//opening the calculator
					calc();
				}
				else
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;//if not  installed
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="eqn_solve")//command for eqnuation solver
			{
				bs=6;//Settings bootscreen
				fstream f;
				f.open("solve.txt",ios::in);
				f>>reg;
				if (reg==1) //if installed
				{
					bootscreen();
					get_Eqn();
				}
				else //if not installed
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="quad_eqn_solve")//command for quadratic equation solver
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
				{	gotoxy(32,15);
					cout<<red<<bold"  Status: Non installed yet"<<cc;
					cout<<"\a\a"<<flush;
					getchar();
					getchar();
					prompt();
				}
			}
			else if(command=="inst_eqn_solve")//command for installing equation solver
			{
				v=6;
				bs=6;
				fstream f;
				f.open("solve.txt",ios::in);
				f>>reg;
				if (reg==1)
				{	gotoxy(32,15);
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
					get_Eqn();
				}
			}
			else if(command=="inst_quad_eqn_solve")//command for installaing quadratic equation solver
			{
				v=7;
				bs=7;
				fstream f;
				f.open("quad_solve.txt",ios::in);
				f>>reg;
				if (reg==1)
				{	gotoxy(32,15);
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
					quad_eqn_solve();
				}
			}
			//List of un istalling commands
			else if(command=="unst_eqn_solve")
			{	fstream f;
				reg =0;
				f.open("solve.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_TicTacToe")
			{	fstream f;
				reg =0;
				f.open("TicTacToe.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_Temp_Conv")
			{	fstream f;
				reg =0;
				f.open("TC.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_Calculator")
			{	fstream f;
				reg =0;
				f.open("Calc.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_quad_eqn_solve")
			{	fstream f;
				reg =0;
				f.open("quad_solve.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_Quiz")
			{	fstream f;
				reg =0;
				f.open("Quiz.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			else if(command=="unst_ar(t_c)")
			{	fstream f;
				reg =0;
				f.open("ATC.txt",ios::out);
				f<<reg;
				f.close();
				gotoxy(32,15);
				cout<<blue<<bold<<" Unistallation finished."<<cc;
				cout<<"\a\a\a\a\a\a"<<flush;
				getchar();
				getchar();
				prompt();
			}
			//Something interesting
			else if(command=="registryeditor")//An inbuilt tool for manipulating reg_keys
			{	cout<<"\a\a\a\a\a\a\a"<<flush;
				reg_status=0;//here it starts without admin previleges or manipulating
				reg_edit();
			}
			else if(command=="display_source")//Source code displayer
			{	cout<<"\a"<<flush;
				source();
				getchar();
				system("clear");
			}
			else if(command=="inst_all")//Installer for applications other than TicTacToe and Quiz
			{
				reg=1;
				fstream tc,c,eqn,qe,at;
				tc.open("TC.txt",ios::out);
				tc<<reg;
				tc.close();
				c.open("Calc.txt",ios::out);
				c<<reg;
				c.close();
				eqn.open("solve.txt",ios::out);
				eqn<<reg;
				eqn.close();
				qe.open("quad_solve.txt",ios::out);
				qe<<reg;
				qe.close();
				at.open("ATC.txt",ios::out);
				at<<reg;
				at.close();
				gotoxy(32,15);
				cout<<green<<bold<<"Successfully completed the command";
				getchar();
				getchar();
				prompt();
			}
			else if(command=="settings"||command=="Settings"||command=="SETTINGS")//Settings Application for controlling the system
			{
				settings();
			}
			else if(command=="login"||command=="Login")//Displaying the login screen
			{
				system("clear");
				layout();
				login();
			}
			else
			{	gotoxy(32,15) ;
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
{	bs=0;//initial bootscreen for OE
	bootscreen();
	fstream file;
	string word, t, q, filename;
	filename = "file.txt";      // opening file
	file.open(filename.c_str());
	if (file.good())
	{	system("clear");
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
void IP()//Installer procedure
{
	gotoxy(1,1);
	layout();
	logo();
	gotoxy(10,8);
	string c;
	reg_status=1;//Added support for adming reg_edit
	cout<<BLUE<<bold<<"Do you want to directly install this application or you want to use it once before installation?(Enter choice below)."<<cc<<cc;//Same strings that are displayed there
	gotoxy(32,10);
	cout<<purple<<bold<<UNDERLINE"Help Me Decide:"<<cc;
	gotoxy(32,12);
	cout<<yellow<<bold<<"If you wish to install the program directly on the browser without testing for once press y.";
	gotoxy(32,13);
	cout<<"If you want to test the progarm before installing i.e. if you want to have a look at the user ";
	gotoxy(32,14);
	cout<<"interface press n and it will load you into the guest user login screen. Just Press enter there  ";
	gotoxy(32,15);
	cout<<"to login. As it is trial so only three commands login, install and exit would be there.";
	gotoxy(32,18);
	cout<<cyan<<bold<<"Enter your choice(y/n):";
	cout<<invisible;//making console output and input invisible for a while
	cin>>c;//taking input
	cout<<cc;//making everythinh again normal afetr taking the input
	if(c=="n"||c=="N")//if trial required
	{
		system("clear");
		gotoxy(1,1);
		layout();
		logo();
		gotoxy(5,7);
		cout<<"After completeion of your trial type 'install' to restart the setup to continue.";
		login();
	}
	else if(c=="registryeditor_admin")//if reg_edit is required
	{
		reg_edit();	//Skipping setup
	}
	else if(c=="prompt")//Totally skipping setup
	{	reg_status=1;
		ins=0;
		prompt();
	}
	else if(c=="y"||c=="Y")//if direct installation required
	{	system("clear");
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
		install();//Creating default files
		Improvements();//Showing improvements
		getchar();//waiting to get a charcter thus pausing the screen
		gotoxy(1,2);
		layout();
		login();//Restarting after installation over
	}
}
void reg_edit()//Registry Key modifier/manipulator
{	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<bold<<UNDERLINE<<red<<"Welcome to Registry Editor version:3.5.0(For Power Users)."<<cc;
	gotoxy(5,8);
	cout<<green<<bold<<"Available commands:"<<cc;	//Displaying version numbers and available commanda
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
	while(true)//Starting an infinite loop to take use input n number of times
	{
		string command;
		gotoxy(5,17);
		cout<<"Command->";
		cin>>command;
		fstream t,q,tc,c,eqn,d;
		reg=1;
		if(command=="install")
		{	if(reg_status==1)
			{
				install();
				gotoxy(5,18);
				cout<<cyan<<bold<<"Succesfully completed the command";
				getchar();
				getchar();
				reg_edit();
			}
			else
			{
				gotoxy(5,18);
				cout<<cyan<<bold<<"Succesfully completed the command";
				getchar();
				getchar();
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
		else if(command=="add_key")//CHanging permanent keys
		{
			if(reg_status==1)//If admin reg_edit
			{
				gotoxy(5,18);
				cout<<"\tCommand->";
				cin>>command;
				reg=1;
				if(command=="both")//if both keys are required to be changed
				{
					t.open("TicTacToe.txt",ios::out);
					t<<reg;
					t.close();
					q.open("Quiz.txt",ios::out);
					q<<reg;
					q.close();
				}
				else if(command=="quiz")//if key for quiz only is changed
				{
					q.open("Quiz.txt",ios::out);
					q<<reg;
					q.close();
				}
				else if(command=="tictactoe")//if key only for tictactie is changed
				{
					t.open("TicTacToe.txt",ios::out);
					t<<reg;
					t.close();
				}
				gotoxy(5,18);
				cout<<cyan<<bold"Succesfully completed the command"<<cc;
				getchar();
				getchar();
				reg_edit();

			}
			else//no command available for regular reg_edit_status
			{	gotoxy(5,20);
				cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
				getchar();
				getchar();
				reg_edit();

			}
		}
		else if(command=="exit")//exit command bringing back to login menu (available for all)
		{
			layout();
			logo();
			login();
		}
		else if(command=="temp")//Temporary key modifier
		{	gotoxy(5,18);
			cout<<"Command->";
			cin>>command;
			if(command=="TTT"||command=="ttt")//if TicTacToe is played
			{
				if(reg_status==1)//Only available for admin reg_edit
				{
					computer_vs_player();        //Only computer_vs_player mode available
				}
				else
				{	gotoxy(5,20);
					cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
					getchar();
					getchar();
					reg_edit();
				}
			}
			else if(command=="quiz")//if quiz is played
			{	if(reg_status==1)
				{
					start();
				}
				else
				{	trial=4;//Valid upto round two
					start();
				}
			}
			else
			{	gotoxy(10,20);
				cout<<red<<bold"temp command is available for only one program(s)";
				getchar();
				getchar();
				reg_edit();
			}
		}
		else if(command=="user")//Can be used for password reset
		{	if(reg_status==1)//ONLY AVAILABLE FOR ADMIN_REG_EDIT
			{
				fstream file;
				string word, t, q, filename;
				filename = "file.txt";      // opening file
				file.open(filename.c_str());
				if (file.good()) //IF USER EXISTS
				{	gotoxy(5,19);
					cout<<RED<<bold"Warning! This command will reset all your user-id password"<<"\a\a\a\a\a\a\a\a\a\a"<<flush;//HENCE WARNING IS DISPLAYED
					gotoxy(5,20);
					cout<<"Do you want to continue:"<<cc;
					char a;
					cin_validattion(a,5,20); // char validation with buffer clear
					if(a=='y')
					{
						add_user();//RECREATING USER
						getchar();
						gotoxy(5,25);
						cout<<cyan<<bold"Succesfully completed the command";
						getchar();
						getchar();
						reg_edit();
					}
					else
					{	gotoxy(5,19);
						cout<<RED<<bold<<"Execution Cancelled!!";
						getchar();
						getchar();
						reg_edit();
					}
				}
				else //IF CLEAN INSTALLATION
				{	add_user();
				}
			}
			else
			{	gotoxy(5,19);
				cout<<RED<<bold<<"Execution Cancelled!!";
				getchar();
				getchar();
				reg_edit();
			}

		}
		else if(command=="reset")//RESET ALL APPLICATIONS AT ONCE
		{	gotoxy(5,19);//WARNING DISPLAYED
			cout<<RED<<bold"Warning! This command will reset all your applications."<<"\a\a\a\a\a\a\a\a\a\a"<<flush;
			gotoxy(5,20);
			cout<<"Do you want to continue:"<<cc;
			char a;
			cin_validattion(a,5,20); // char validation with buffer clear
			if(a=='y')
			{	reg=0;//REGISTRY KEY 0 FOR UN_INSTALLATION
				install();
				gotoxy(5,25);
				cout<<cyan<<bold<<"Succesfully completed the command";
				getchar();
				getchar();
				reg_edit();
			}
			else
			{	gotoxy(5,19);
				cout<<RED<<bold<<"Execution Cancelled!!";
				getchar();
				getchar();
				reg_edit();
			}
		}
		else if(command=="prompt"||command=="Prompt")//DIRECTLY JUMP INTO PROMPT MENU
		{
			system("clear");
			gotoxy(1,1);
			layout();
			logo();
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
		else if(command=="help")//Help Documentation
		{	gotoxy(5,20);
			cout<<blue<<bold<<" Welcome to HELP Documentation Ver: 1.0. :"<<cc;
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
			getchar();
			getchar();
			reg_edit();
		}
		else if(command=="clear"||command=="cls")//Backward compatibility, was used in earlier version like ver 3 but of no use now
		{
			system("clear");
			reg_edit();
		}
		else if(command=="start_admin_reg_edit")
		{
			reg_status=1;
			reg_edit();
		}
		else
		{	gotoxy(5,20);
			cout<<red<<bold<<"Status: No available command"<<"\a\a\a\a\a\a\a\a\a\a\a\a"<<cc;
			getchar();
			getchar();
			reg_edit();
		}

	}
}