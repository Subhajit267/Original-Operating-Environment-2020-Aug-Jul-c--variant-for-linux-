//This time version 3 so kiccchu Improvements chai
//next version  e notun app include hbe but ei versione ager apps e notun fecture pabo ba notun questions ar notun login UI including bootscreen
//tictactoe te ebar difficulty level select kora jbe, eqn solver e type of equations bolte parbe ar notun hidden feature diyechi regisrty editor 
//At last but not the least password bypass
#include<chrono> //for sleeping             //Basically jotogulo predefined function commonly use kori sei sob mention korlam  :)
#include<thread> // --do-- 
#include<cstdlib>//for random increments
#include<ctime>// --do-- 
#include<iostream>
#include <stdlib.h>
#include <string>
#include<fstream>
#include <random>
#include <stdio.h>
#include<unistd.h>
#include <string>
#define bold "\x1B[1m"//ascii escape sequences jate bar bar mention na korte hoi tai age predifine korechi
#define red "\x1B[31m"
#define purple "\x1B[95m"
#define RED "\x1B[31m"
#define yellow "\x1B[93m"
#define blue "\x1B[94m"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
#define green "\x1B[92m"
#define cc "\033[0m"
#define cyan "\x1B[36m"
#define invisible "\x1B[8m"
#include <random>
using namespace std;
int state;
void gotoxy(int x,int y)// declaring the cursor position
{
    printf("%c[%d;%df",0x1B,y,x);
}
void progressbar(){ 
	std::srand(time(NULL)); //seed random 
	for(int progress=0;progress!=100;progress+=std::rand()%20){
	    if(state==1)
	    {gotoxy(53,16);}
	    else
	    {gotoxy(40,16);}//increment progress randomly 
		//Delete the line below and change for loop condition to 'progress<=100' and put something meaningful in for loop progress increment in implementation. 
		if(progress>25) progress=25; 
		std::cout<<"\x1B[33m[\033[0m\x1B[31m"; 
		for(int i=0;i<25;i++) 
			if(i<progress) 
				std::cout<<'='; 
			else if(i==progress) 
				std::cout<<'>'; 
			else 
				std::cout<<' '; 
		std::cout<<"\033[0m\x1B[33m]\033[0m "; 
		std::cout.flush(); 
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //sleep 
		//Delete this line as well in implementation 
		if(progress==25) break; 
	} 
	std::cout<<std::endl; 
}
//This is place of function prototype
void img();
int printrndone();
int timerS();
void logo();
string Difficult;
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//board e jotogulo position acche sob declare korechi
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
int timerS();
void IP();
void add_user();
int timerO();
int timerB();
void login();
int loading();
int start();
int about();
int cheatcode();
int evaluator();
void reg_edit();
void bootscreen();
void login();
void tc();
void password_change();
void activation();
int ap,reg,v,ins,bs,mode;
double A1,A2,B1,B2,C1,C2,x,y,m,n;
char C,A_1,cho;
void solve()//To solve the equations using cross multiplication method
{
    x=((B1*C2) - (B2*C1))/n;
    y=((A2*C1) - (A1*C2))/n;
    cout<<"\nRequired equations after suitable arrangement are:\n";
    if(C=='y'&&A_1=='n')
    {
        C1=C1*1;
        C2=C2*1;
    }
    else if(C=='y'&&A_1=='y')
    {
        C1=C1*-1;
        C2=C2*-1;
    }
    else if(C=='n'&&cho=='y')
    {
        C1=C1*-1;
        C2=C2*-1;
    }
    else if(C=='n'&&cho=='n')
    {
        C1=C1*-1;
        C2=C2*-1;
    }
    else
    {
        cout<<"\nPart of your input is invalid.";
        cout<<"\nThe program will stop.";
    }
    cout<<"("<<A1<<")x + ("<<B1<<")y + ("<<C1<<") = 0 \n";
    cout<<"("<<A2<<")x + ("<<B2<<")y + ("<<C2<<") = 0 \n";
    cout<<"X = \033[31m"<<x<<"\033[0;1m and Y = \033[31m"<<y;
    cout<<"\nThey represent equations with unique solution intersecting at a point on graph.";
    cout<<cc<<cc;
}                 
void get_Side()//to get the side of constant terms
{
     cout<<"Are all the constant terms in same side?(y/n)";
    cin>>C;
    if(C=='y')
    {
         cout<<"Are the constant terms alone in one side?(y/n)";
        cin>>A_1;
           if(A_1=='y')
          {
             m=-1;
              n=n*m;
             solve();
                            
          }
           else if(A_1=='n')
          {
             m=1;
             n=n*m;
            solve();
          }
    }
    else if(C=='n')
    {
        cout<<"\nIs C1 alone in one side(y/n):";
        cin>>cho;
        if(cho=='y')
        {
            m=-1;
              n=n*m;
              C2=C2*-1;
            
        }
        else if(cho=='n')
        {
            m=-1;
              n=n*m;
              C1=C1*-1;
        }
     solve();
    }
}
void get_Eqn()//to get the equation
{
   system("clear");
   gotoxy(1,1);
    cout<<yellow<<bold<<UNDERLINE<<"\n/*IT MUST BE NOTED THAT ALL THE X,Y and constant terms must be numbers*/\033[0m"<<cc<<endl;
    cout<<blue<<bold<<"\nYour equations may be in the form of:";
    cout<<"\na1x + b1y + c1 = 0";
    cout<<"\na2x + b2y + c2 = 0";
    cout<<"\n\na1x + b1y = c1 ";
    cout<<"\na2x + b2y = c2 ";
    cout<<"\n\na1x + b1y = c1 ";
    cout<<"\na2x + b2y + c2 = 0";
    cout<<"\n\na1x + b1y + c1 = 0";
    cout<<"\na2x + b2y = c2 "<<cc<<cc<<endl;
    cout<<green<<bold"\nEnter the value of a1/coefficient of x in first equation:"<<cc<<cc;
    cin>>A1;
    cout<<green<<bold<<"Enter the value of b1/coefficient of y in first equation:"<<cc<<cc;
    cin>>B1;
    cout<<green<<bold<<"Enter the value of c1/constant in first equation:"<<cc<<cc;
    cin>>C1;
    cout<<green<<bold<<"Enter the value of a2/coefficient of x in second equation:"<<cc<<cc;
    cin>>A2;
    cout<<green<<bold<<"Enter the value of b2/coefficient of y in second equation:"<<cc<<cc;
    cin>>B2;
    cout<<green<<bold<<"Enter the value of c2/constant term in second equation:"<<cc<<cc;
    cin>>C2;
    n=((A1*B2) -(A2*B1));
    if(A1*B2 != A2*B1)//Checking if the given equations have unique solution or not
    {
       get_Side();
    }
    else if(A1/A2 == B1/B2&& A1/A2==C1/C2)//If equations have infinite solutions
    {
        cout<<"\nSolution can be given only to equations with unique solution.";
        cout<<"\nYour entered equations have infinitely many solutions and represent coincident lines on graph.";
        getchar();
    }
    else if(A1/A2 == B1/B2&& A1/A2!=C1/C2)//if equations have no solutions
    {
        cout<<"\nSolution can be given only to equations with unique solution.";
        cout<<"\nYour entered equations have no solutions and represent parallel lines on graph.";
        getchar();
    }
}
int source()
{     char c;  
    FILE *fp = fopen(__FILE__, "r"); 
    do
    { 
        c = fgetc(fp); 
        putchar(c); 
    } 
    while (c != EOF); 
    fclose(fp); 
}
void Improvements()
{
    system("clear");
    cout<<"\n"<<bold<<RED<<UNDERLINE<<"New Improvments and Bug Fixes:"<<cc;
    cout<<bold<<blue<<"\ni.)Change in programming";
    cout<<bold<<yellow<<"\nii.)New easter eggs";
    cout<<bold<<blue<<"\niii.)Eqn solver can determine several types of equations";
    cout<<bold<<yellow<<"\niv.)Introduction of Difficulty level in TicTacToe";
    cout<<bold<<blue<<"\nv.)Installing programs take less time";
    cout<<bold<<yellow<<"\nvi.)A new but usefull hidden Program Registry Editor.";
    cout<<bold<<blue<<"\nvii.)Cheat code for tictactoe. Idea given by Ritabrata Saha";
     cout<<bold<<yellow<<"\nviii.)New questions for quiz.";
     cout<<bold<<blue<<"\nix.)New bootscreen and login screen with new feature";
    cout<<bold<<green<<"\nTry to find many hidden features.";
    cout<<bold<<green<<"\nNext version comming with more features"<<cc;
    getchar();
}
 int printerror() // To avoid any error in marks counting this section is used
{ 
    system("clear");  
     printf("\x1B[31m\t\t\t\tAn Unexpected error occured due to invalid input\033[0m\t\t");
     printf("\x1B[34m\nPlease restart the program\033[0m\t\t");
    getchar();
   prompt();
}
void installer()//installer for all programs
{reg=1;//The registry values which registers the apps as installed or not
      system("clear");
      gotoxy(1,1);
      if(v==1 && bs==1)//at differnt states which title will be shown tar jonno
      {
        system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tTIC TAC TOE"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:4.0";
      }
      else if(v==2 && bs==2)
      {
          system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tQUIZ__APP"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:10.8";
      }
      else if(v==3 && bs==3)
      {
           system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tTEMP_CONV"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
      }
      else if(v==4 && bs==4)
      {
          system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tCALCULATOR"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
      }
      else if(v==6 && bs==6)
      {
          system("clear");
          gotoxy(46,1);
        cout <<UNDERLINE<< "Pair_of_eqn_solve"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:4.01";
      }
cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
cout <<"\n\n\n\t\t\t\t\t        Please_Wait.";//Ei gulo common strings
cout<<"\n\t\t\t\t\t     While setup is";
cout<<"\n\t\t\t\t\t        Installing...";
 sleep(1);
      if(v==1 && bs==1)
      {
       activation();
      }
      else if(v==2 && bs==2)
      {
         activation();
      }
      else if(v==3 && bs==3)
      {
           fstream f;
         f.open("TC.txt",ios::out);
         f<<reg;
         f.close();
      }
       else if(v==4 && bs==4)
      {
         fstream f;
         f.open("Calc.txt",ios::out);
         f<<reg;
         f.close();
      }
      
       else if(v==6 && bs==6)
      {
         fstream f;
         f.open("solve.txt",ios::out);
         f<<reg;
         f.close();
      }
    sleep(2);
}
void activation()//Common activation method for tictactoe and Quiz
{system("clear");
reg=1;
cout<<"\nEnter product key(10 charcters):";
    char key[10];
    cin>>key;
if(v==1)
{
 if(key[6]+key[0]==key[9]+key[5])
       {
       
       cout<<"verified";
       getchar();
       fstream k,t;
       k.open("file3.txt",ios::out);
       k<<key;
       k.close();
       t.open("TicTacToe.txt",ios::out); 
       t<<reg;
       t.close();
       prompt();
   }
   else
   {
      cout<<"Invalid key";
      getchar();
      prompt();
   }
}
else if(v==2)
{
     if(key[7]+key[8]==key[2]+key[9])
   {
       cout<<"verified";
       getchar();
       fstream k,t;
       k.open("file6.txt",ios::out);
       k<<key;
       k.close();
       t.open("Quiz.txt",ios::out); 
       t<<reg;
       t.close();
       prompt();
   }
   else
   {
      cout<<"Invalid key";
      getchar();
      prompt();
   }
}
}
void bootscreen()
  { gotoxy(1,1);
  cout<<yellow<<bold;
      if(bs==1)
      {
        system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tTIC TAC TOE"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:4.0";
        state=0;
      }
      else if(bs==0)
      { 
          layout();
            logo();
          state=1;
      }
      else if(bs==2)
      {
          system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tQUIZ__APP"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:10.8";
            state=0;
      }
      else if(bs==3)
      {
           system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tTEMP_CONV"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
            state=0;
      }
      else if(bs==4)
      {
          system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tCALCULATOR"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
        state=0;
      }
      else if(bs==6)
      { system("clear");
          gotoxy(46,1);
        cout <<UNDERLINE<< "Pair_of_eqn_solve"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:4.01";
        state=0;
      }
      cout<<cc<<cc;
    progressbar();
    gotoxy(53,16);
cout<<"                                                         ";
}
void layout(){
system("clear");
     cout<<" ================================================================================================================================"<<endl;
    cout<<"|"<<"\t\t\t\t\t\t\t"<<blue<<bold<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE<<"                                                    |"<<endl;
    cout<<"| "<<"\t\t\t\t\t                  "<<yellow<<bold<<UNDERLINE<<"  Version:3.00  "<<CLOSEUNDERLINE<<cc<<cc<<cc<<"                                                       |"<<endl;
    cout<<"|                                                        (Evaluation_Build)                                                      |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
    cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
      cout<<"|                                                                                                                                |"<<endl;
       cout<<"|                                                                                                                                |"<<endl;
        cout<<"|                                                                                                                                |"<<endl;
         cout<<"|                                                                                                                                |"<<endl;
          cout<<"|                                                                                                                                |"<<endl;
           cout<<"|                                                                                                                                |"<<endl;
            cout<<"|                                                                                                                                |"<<endl;
    cout<<" ================================================================================================================================"<<endl;
    gotoxy(1,1);
}
void login()
{     fstream file;
logo();
     string a,filename,name1,password1,password;
            filename = "file.txt";      // opening file
            file.open(filename.c_str());
            if (file.good()) 
            {gotoxy(2,5);
                cout<<"To begin press enter or type password(if you have created a User-ID).";
                  
                  gotoxy(40,7);
                        cout<<"User-ID:";
                         fstream file1,file;
                        file1.open("file.txt");
                        file1>>name1;
                        cout<<" "<<name1;
                        filename = "file2.txt";
                   file.open(filename.c_str());
                    if (file.good()) 
                    {gotoxy(40,8);
                     cout<<"Password:";
                   cout<<invisible;
                   cin>>password;
                   cout<<cc;
                        fstream file2;
                        file2.open("file2.txt");
                        file2>>password1;
                        if(password1==password)
                        {
                            cout<<bold<<red<<"\n\t\t\t\tWelcome"<<" "<<name1;
                            sleep(0.5);
                            prompt();
                        }
                        else if(password=="reg_edit")
                        {
                            reg_edit();
                        }
                        else
                        {
                                timerS();
                        }
                    }
                    else 
                    {
                       getchar();
                       cout<<bold<<red<<"\n\t\t\t\tWelcome"<<" "<<name1;
                       prompt();
                    }
            }
            else 
            {gotoxy(2,6);
               cout<<" /* To just test the program (*with limited features) type GUEST in the place of USER NAME */ ";
              gotoxy(40,7);
                cout<<"Enter user name:";
                 cout<<" \x1B[36m ";
                 cin>>a;
                   if(a=="GUEST"||a=="Guest")
                   {
                        ins = 9;
                        prompt();
                   }
                   else if(a=="guess_it")
                   {
                       source();
                   }
                   else if(a=="reg_edit")
                   {
                       reg_edit();
                   }
                 else  {
                           timerS();
                       }
            }
}
void selector_t()
{
     sleep(1.5);
       system("clear");
       gotoxy(1,1);
      cout << "\t\t\t\t\t"<<bold<<UNDERLINE<<RED<<"Select Game Mode(1/2)."<< CLOSEUNDERLINE<<cc<<CLOSEUNDERLINE<<endl;
    cout << "  \t\t\t\t\t\x1B[94m1. Computer VS Player." << endl;
    cout << "  \t\t\t\t\t2. Player VS Player." << CLOSEUNDERLINE<<endl;
    cout<<"\x1B[93mENTER YOUR CHOICE: "<<CLOSEUNDERLINE<<"\x1B[96m";
     cin >> mode;
    cout<<cc;
    switch(mode)
        {
        case 1 :
            cout<<RED<<bold<<"\nEnter Game type:"<<cc;
            cout<<yellow<<"\n\ta.)Simple.";
            cout<<"\n\tb.)Difficult."<<cc;
            cout<<"\nEnter Your Choice:";
            cin>>Difficult;
            if(Difficult=="a")
            {
               Difficult="1";
               computer_vs_player();
            }
            else if(Difficult=="b")
            {
               Difficult="2";
               computer_vs_player();
            }
            break;
        case 2:
            player_vs_player();
            break;
        default :
            cout << "Please Select Valid Game Mode."<< endl;
            sleep(1);
            prompt();
        }
}
void computer_vs_player() {
    string player_name;
    system("clear");
    gotoxy(1,1);
    cout<<red<<bold<<"Please fill in the following details:"<<CLOSEUNDERLINE<<endl;
    cout <<yellow<< "Enter Your Name: "<<CLOSEUNDERLINE;
    cin >> player_name;
    while(true) {
        system("clear");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << player_name << "‘s Turn." << endl;
            get_x_player_choice();
        }
        else{
            
            if(Difficult=="1")
            {
            get_computer_choice_e();
            }
            else if(Difficult=="2")
            {
                get_computer_choice_h();
            }
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("clear");
            show_board();
            cout << player_name <<" Won The Game."<< endl;
            getchar();
            break;
        }
        else if(winner == 'O') {
            system("clear");
            show_board();
            cout << "Computer Won The Game." << endl;
            getchar();
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw." << endl;
            getchar();
            break;
        }
    }
    getchar();
   cout<<"\nThe program is shutting down to prevent any file corruption.";
    exit(0);
}
void get_computer_choice_e() {
     srand(time(0));
    int choice;
    do{
        choice = rand()%10;
    }while(board[choice] != ' ');
    board[choice] = 'O';
}
void get_computer_choice_h() {
    while(true)
    {
        if(board[0] == board[1] && board[2] == ' ' && board[0]=='O')//Checking horizontally
        {
            board[2]='O';
            break;
        }
         else if(board[3] == board[4] && board[5] == ' '&& board[3]=='O')
        {
            board[5]='O';
            break;
        }                                          
         else if(board[6] == board[7] && board[8] == ' '&& board[6]=='O')
        {
            board[8]='O';
            break;
        }
         else if(board[0] == board[2] && board[1] == ' '&& board[0]=='O')
        {
            board[1]='O';
            break;
        }// if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
         else if(board[3] == board[5] && board[4] == ' '&& board[3]=='O')
        {
            board[4]='O';
            break;
        }                                            //     return board[0];
         else if(board[6] == board[8] && board[7] == ' '&& board[6]=='O')
        {
            board[7]='O';
            break;
        }  
         else if(board[7] == board[8] && board[6] == ' '&& board[7]=='O')
        {
            board[6]='O';
            break;
        }// if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
         else if(board[5] == board[4] && board[3] == ' '&& board[5]=='O')
        {
            board[3]='O';
            break;
        }  
        else if(board[1] == board[2] && board[0] == ' '&& board[1]=='O')
        {
            board[0]='O';
            break;
        }
         else if(board[0] == board[3] && board[6] == ' '&& board[0]=='O')
        {
            board[6]='O';
            break;
        }
         else if(board[1] == board[4] && board[7] == ' '&& board[1]=='O')
        {
            board[7]='O';
            break;
        }                                           //         // checking winner in horizontal/row
         else if(board[2] == board[5] && board[8] == ' '&& board[5]=='O')
        {
            board[8]='O';
            break;
        }
         else if(board[0] == board[6] && board[3] == ' '&& board[0]=='O')
        {
            board[3]='O';
            break;
        }// if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
         else if(board[1] == board[7] && board[4] == ' '&& board[1]=='O')
        {
            board[4]='O';
            break;
        }                                            //     return board[0];
         else if(board[2] == board[8] && board[5] == ' '&& board[2]=='O')
        {
            board[5]='O';
            break;
        }  
         else if(board[3] == board[6] && board[0] == ' '&& board[3]=='O')
        {
            board[0]='O';
            break;
        }// if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
         else if(board[4] == board[7] && board[1] == ' '&& board[4]=='O')
        {
            board[1]='O';
            break;
        }  
         else if(board[8] == board[5] && board[2] == ' '&& board[5]=='O')
        {
            board[2]='O';
            break;
        }
        else if(board[8] == board[0] && board[4] == ' '&& board[0]=='O')
        {
            board[4]='O';
            break;
        } 
        else if(board[8] == board[4] && board[0] == ' '&& board[4]=='O')
        {
            board[0]='O';
            break;
        }// if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        else if(board[4] == board[0] && board[8] == ' '&& board[0]=='O')
        {
            board[8]='O';
            break;
        }
        else if(board[2] == board[6] && board[4] == ' '&& board[2]=='O')
        {
            board[4]='O';
            break;
        } 
        else if(board[2] == board[4] && board[6] == ' '&& board[4]=='O')
        {
            board[6]='O';
            break;
        }// if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        else if(board[4] == board[6] && board[2] == ' '&& board[4]=='O')
        {
            board[2]='O';
            break;
        } 
       else if(board[0] == board[1] && board[2] == ' ' && board[0]=='X')//Checking horizontally
        {
            board[2]='O';
            break;
        }
         else if(board[3] == board[4] && board[5] == ' '&& board[3]=='X')
        {
            board[5]='O';
            break;
        }                                          
         else if(board[6] == board[7] && board[8] == ' '&& board[6]=='X')
        {
            board[8]='O';
            break;
        }
         else if(board[0] == board[2] && board[1] == ' '&& board[0]=='X')
        {
            board[1]='O';
            break;
        }// if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
         else if(board[3] == board[5] && board[4] == ' '&& board[3]=='X')
        {
            board[4]='O';
            break;
        }                                            //     return board[0];
         else if(board[6] == board[8] && board[7] == ' '&& board[6]=='X')
        {
            board[7]='O';
            break;
        }  
         else if(board[7] == board[8] && board[6] == ' '&& board[7]=='X')
        {
            board[6]='O';
            break;
        }// if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
         else if(board[5] == board[4] && board[3] == ' '&& board[5]=='X')
        {
            board[3]='O';
            break;
        }  
        //     return board[3];
         else if(board[1] == board[2] && board[0] == ' '&& board[1]=='X')
        {
            board[0]='O';
            break;
        }
         else if(board[0] == board[3] && board[6] == ' '&& board[0]=='X')
        {
            board[6]='O';
            break;
        }
         else if(board[1] == board[4] && board[7] == ' '&& board[1]=='X')
        {
            board[7]='O';
            break;
        }                                           //         // checking winner in horizontal/row
         else if(board[2] == board[5] && board[8] == ' '&& board[5]=='X')
        {
            board[8]='O';
            break;
        }
         else if(board[0] == board[6] && board[3] == ' '&& board[0]=='X')
        {
            board[3]='O';
            break;
        }// if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
         else if(board[1] == board[7] && board[4] == ' '&& board[1]=='X')
        {
            board[4]='O';
            break;
        }                                            //     return board[0];
         else if(board[2] == board[8] && board[5] == ' '&& board[2]=='X')
        {
            board[5]='O';
            break;
        }  
         else if(board[3] == board[6] && board[0] == ' '&& board[3]=='X')
        {
            board[0]='O';
            break;
        }// if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
         else if(board[4] == board[7] && board[1] == ' '&& board[4]=='X')
        {
            board[1]='O';
            break;
        }  
        //     return board[3];
         else if(board[8] == board[5] && board[2] == ' '&& board[5]=='X')
        {
            board[2]='O';
            break;
        }
        else if(board[8] == board[0] && board[4] == ' '&& board[0]=='X')
        {
            board[4]='O';
            break;
        } 
        else if(board[8] == board[4] && board[0] == ' '&& board[4]=='X')
        {
            board[0]='O';
            break;
        }// if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        else if(board[4] == board[0] && board[8] == ' '&& board[0]=='X')
        {
            board[8]='O';
            break;
        }
        //     return board[6];
          else if(board[2] == board[6] && board[4] == ' '&& board[2]=='X')
        {
            board[4]='O';
            break;
        } 
        else if(board[2] == board[4] && board[6] == ' '&& board[4]=='X')
        {
            board[6]='O';
            break;
        }// if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        else if(board[4] == board[6] && board[2] == ' '&& board[4]=='X')
        {
            board[2]='O';
            break;
        }
        else if(board[4]=='X')
        {
            if(' '==board[0])
            {
                    board[0]='O';
                    break;
            }
            else if(' '==board[1])
            {
                    board[1]='O';
                    break;
            }
            else if(' '==board[2])
            {
                    board[2]='O';
                    break;
            }
           else if(' '==board[3])
            {
                    board[3]='O';
                    break;
            }
             if(' '==board[4])
            {
                    board[4]='O';
                    break;
            }
            else if(' '==board[5])
            {
                    board[5]='O';
                    break;
            }
            else if(' '==board[6])
            {
                    board[6]='O';
                    break;
            }
           else if(' '==board[7])
            {
                    board[7]='O';
                    break;
            }
            else if(' '==board[8])
            {
                    board[8]='O';
                    break;
            }
        }
          else if('X'==board[0]||'X'==board[2]||'X'==board[6]||'X'==board[8])
        {
            if(' '==board[0])
            {
                    board[0]='O';
                    break;
            }
            else if(' '==board[2])
            {
                    board[2]='O';
                    break;
            }
            else if(' '==board[6])
            {
                    board[6]='O';
                    break;
            }
           else if(' '==board[8])
            {
                    board[8]='O';
                    break;
            }
        }
         else if('X'==board[1]||'X'==board[3]||'X'==board[7]||'X'==board[5])
        {
            if(' '==board[1])
            {
                    board[1]='O';
                    break;
            }
            else if(' '==board[3])
            {
                    board[3]='O';
                    break;
            }
            else if(' '==board[7])
            {
                    board[7]='O';
                    break;
            }
           else if(' '==board[5])
            {
                    board[5]='O';
                    break;
            }
        }
    }
}
void get_x_player_choice() {
    while(true) {
        cout << "Select Your Position (1 – 9): " ;
        long choice_a;
        cin >> choice_a;
        choice_a -- ;
        if(char(choice_a)=='w')//cheat
        {
            board[1]=board[4]=board[7]=board[2]=board[3]='X';
            board[0]=board[6]=board[8]=board[5]='O';
            system("clear");
            show_board();
            cout<<"\nYou win the game, Computer/player 2 lost the game";
            getchar();
            exit(0);
            break;
        }
        else if(choice_a < 0 || choice_a > 8) {
            cout << "Please Select Your Choice From (1 – 9)." << endl;
        }
        else if(board[choice_a] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice_a] = 'X';
            break;
        }
    }
}
void get_o_player_choice() {
    while(true) {
         cout << "Select Your Position (1 – 9): " ;
        int choice_b;
        cin >> choice_b;
        choice_b -- ;
         if(char(choice_b)=='w')//cheat
        {
            board[1]=board[4]=board[7]=board[2]=board[3]='O';
            board[0]=board[6]=board[8]=board[5]='X';
            system("clear");
            show_board();
            cout<<"\nYou win the game, player 1 lost the game";
            getchar();
            exit(0);
            break;
        }
       else if(choice_b < 0 || choice_b > 8) {
            cout << "Please Select Your Choice From (1 – 9)." << endl;
        }
        else if(board[choice_b] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice_b] = 'O';
            break;
        }
    }
}

void player_vs_player() {
    string x_player_name , o_player_name;
     string player_name;
    gotoxy(1,1);
    system("clear");
    cout<<red<<bold<<"Please fill in the following details:"<<cc<<endl;
    cout <<yellow<<"Enter X Player Name: " <<CLOSEUNDERLINE;
    cin >> x_player_name;
    cout << yellow<<"Enter O Player Name: "<<CLOSEUNDERLINE ;
    cin >> o_player_name;
    while(true) {
        system("clear");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << x_player_name << "‘s Turn."<< endl;
            get_x_player_choice();
        }
        else{
            cout << o_player_name << "‘s Turn." << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("clear");
            show_board();
            cout << x_player_name << " Won The Game." << endl;
            getchar();
            break;
        }
        else if(winner == 'O') {
            system("clear");
            show_board();
            cout << o_player_name << " Won The Game." << endl;
            getchar();
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw." << endl;
            getchar();
            break;
        }
    }
    getchar();
    cout<<"\nThe program is shutting down to prevent any file corruption.";
    exit(0);
}
int count_board(char symbol) {
    int total = 0;
    for(int i=0; i<9; i++) {
        if(board[i] == symbol)
            total += 1;
    }
    return total;
}
char check_winner() {
    // checking winner in horizontal/row
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    // checking winner in vertical/column
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    // checking winner in diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}
void show_board()
{
    cout<<green<<"   "<<"    |   "<<"    |   "<<cc<<endl;//printing the board
    cout<<green<<"   "<<cc<<red<<board[0]<<cc<<green<<"   |   "<<cc<<red<<board[1]<<cc<<green<<"   |   "<<cc<<red<<board[2]<<cc<<endl;
     cout<<green<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"-----------------------"<<endl;
     cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<cc<<"   "<<red<<board[3]<<cc<<green<<"   |   "<<cc<<red<<board[4]<<cc<<green<<"   |   "<<cc<<red<<board[5]<<cc<<endl;
     cout<<green<<"   "<<"    |   "<<"    |   "<<endl;
       cout<<"-----------------------"<<endl;
     cout<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"   "<<cc<<red<<board[6]<<cc<<green<<"   |   "<<cc<<red<<board[7]<<cc<<green<<"   |   "<<cc<<red<<board[8]<<cc<<endl;
     cout<<green<<"   "<<"    |   "<<"    |   "<<cc<<endl;
}
void calc()  //A basic decent calculator
{system("clear");
gotoxy(1,1);
  cout<<"!!!!!!!!!!!!!!This is a calculator!!!!!!!!!!!!!"<<endl;
   gotoxy(1,4);
  float a,b,c,d,e,f,g;
  char A,B,C,D;
  
cout<<"Enter first number:";
cin>>a;
cout<<"Enter first opertor:";
cin>>A;
cout<<"Enter second number:";
cin>>b;
cout<<"Enter second operator:";
cin>>B;
cout<<"Enter third number:";
cin>>c;
cout<<"Enter third operator:";
cin>>C;
cout<<"Enter fourth number:";
cin>>d;
cout<<"Expression you entered is:"<<a<<A<<b<<B<<c<<C<<d<<endl;
           switch (A)
                    {case '+':
            e=a+b;
     break;
     case '-':
           e=a-b;
     break;
     case '/':
            e=a/b;
     break;
     case '*':
           e=a*b;
     break;
     default:
         cout<<"Invalid input";
   }
   switch (B)
   {case '+':
            f=e+c;
     break;
     case '-':
           f=e-c;
     break;
     case '/':
            f=e/c;
     break;
     case '*':
           f=e*c;
     break;
     default:
         cout<<"Invalid input";
          }
   switch (C)
          {case '+':
           g=f+d;
            cout<<"Result is :"<<g<<endl;
     break;
     case '-':
           g=f-d;
           cout<<"Result is :"<<g<<endl;
     break;
     case '/':
            g=f/d;
            cout<<"Result is :"<<g<<endl;
     break;
     case '*':
           g=f*d;
           cout<<"Result is :"<<g<<endl;
     break;
     default:
         cout<<                                                                                                             "Invalid input";
            }
   cout<<"\t\t\t<<PRESS ANY KEY TO EXIT>>"<<endl;
  getchar();
prompt();
}
void tc()//a basic decent temperature converter
{
    system("clear");
    gotoxy(1,1);
    cout<<"!!!!!!!!!!!!!!!!!!!!!This is a temperature converter program.(°C/°F)!!!!!!!!!!!!!!!!!!!!!";
    char choice;//Future e kelvin er jonno support add hbe 
    int temp,temp_c;
    cout<<"\nEnter your desired unit of temperature:(°C/°F):";
    cin>>choice;
    
    cout<<"Enter temperature ("<<choice<<"): ";
    cin>>temp;
    
    if(choice=='C' || choice=='c')
    {
        temp_c=(temp * 1.8) + 32;
        cout<<"Temperature in °F is:"<<temp_c;
   sleep(3);
prompt();
    }
    else if(choice=='F' || choice=='f')
    {
        temp_c=(temp - 32) * 5/9 ;
        cout<<"Temperature in °C is:"<<temp_c;
   sleep(3);
    prompt();
    }
    else{
        cout<<"INVALID INPUT";
        sleep(3);
       prompt();
    }
}
/*  And an ernest request to everyperson who will view this source code
    PLEASE dont change my name from the secret about menu
    You may change it from the start screen but not from anywhere else
*/
int A,B,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5,bo1,bo2,bo3,bo4,bo5,bo6,bo7,bo8,r;//As more questions would be added name them as a5 for groupA and b5 for goupB
char p1,o1,p2,o2,p3,o3,o4,p4,o5,p5,o6,p6,o7,p7,o8,p8;
int printerror1() // To avoid any error in marks counting this section is used
{ 
    system("clear");  
     printf("\n\x1B[31m\t\t\t\tThis cheat code is for entertainment only\033[0m\t\t");
     printf("\x1B[34m\nPlease restart the program\033[0m\t\t");
    getchar();
}
int printawon()
{
     A = 45;
              B = 0;
              system("clear");                     //To count marks this section is used
              cout<<"Correct Answers:";
              cout<<"\n1.) C";
              cout<<"\n2.) A";
              cout<<"\n3.) C";                   // At first declaring all the correct options of all uestion
               cout<<"\n4.) D";
             cout<<"\n5.) B";
              cout<<"\n6.) A";
                cout<<"\nA won";
                cout<<"\n A="<<A<<"\tB="<<B;
                 getchar();
                  printerror1();
}
int printbwon()
{
    B = 45;
              A = 0;
              system("clear");                     //To count marks this section is used
              cout<<"Correct Answers:";
              cout<<"\n1.) C";
              cout<<"\n2.) A";
              cout<<"\n3.) C";                   // At first declaring all the correct options of all uestion
               cout<<"\n4.) D";
             cout<<"\n5.) B";
              cout<<"\n6.) A";
                cout<<"\nB won";
                cout<<"\n A="<<A<<"\tB="<<B;
                 getchar();
                  printerror1();
}
int
scrbrd ()
{
  gotoxy (50, 1);
  system ("clear");
  cout << "Score(Rnd-" << r << ")";
  gotoxy (43, 4);
  cout << "|______Score Board______|";
  gotoxy (43, 5);
  cout << "|_____A_____|_____B_____|";
  gotoxy(43,6);
  cout<<"| ";
 switch(a1)
 {
     case 10:
        cout<<a1;
        break;
     case -5:
        cout<<a1;
        break;
     default:
     cout<<"+"<<a1;
     break;
     
 }
 cout<<"  | +"<<bo2<<"  | ";
  switch(b1)
 {
     case 10:
        cout<<b1;
        break;
     case -5:
        cout<<b1;
        break;
     default:
     cout<<"+"<<b1;
     break;
     
 }
  cout<<"  | +"<<bo1<<"  | ";
   cout<<"\n                                          | ";
   switch(a2)
 {
     case 10:
        cout<<a2;
        break;
     case -5:
        cout<<a2;
        break;
     default:
     cout<<"+"<<a2;
     break;
     
 }
 cout<<"  | +"<<bo4<<"  | ";
  switch(b2)
 {
     case 10:
        cout<<b2;
        break;
     case -5:
        cout<<b2;
        break;
     default:
     cout<<"+"<<b2;
     break;
     
 }
  cout<<"  | +"<<bo3<<"  |";
    cout<<"\n                                          | ";
 switch(a3)
 {
     case 10:
        cout<<a3;
        break;
     case -5:
        cout<<a3;
        break;
     default:
     cout<<"+"<<a3;
     break;
     
 }
 cout<<"  | +"<<bo6<<"  | ";
  switch(b3)
 {
     case 10:
        cout<<b3;
        break;
     case -5:
        cout<<b3;
        break;
     default:
     cout<<"+"<<b3;
     break;
     
 }
  cout<<"  | +"<<bo5<<"  |";
    cout<<"\n                                          | ";
 switch(a4)
 {
     case 10:
        cout<<a4;
        break;
     case -5:
        cout<<a4;
        break;
     default:
     cout<<"+"<<a4;
     break;
     
 }
 cout<<"  | +"<<bo8<<"  | ";
  switch(b4)
 {
     case 10:
        cout<<b4;
        break;
     case -5:
        cout<<b4;
        break;
     default:
     cout<<"+"<<b4;
     break;
     
 }
  cout<<"  | +"<<bo7<<"  |";
getchar();
getchar();
if(r==4)
{
    scr();
}
  return 0;
}
int scr()
{
    A = a1+a2+a3+a4+bo8+bo6+bo2+bo4;
    B = b1+b2+b3+b4+bo7+bo5+bo1+bo3;  //Then counting total marks for both groups
    if(A>B)  //If groupA wins
    {
        gotoxy(51,11);
        
        cout<<"!!!A won!!!";
        gotoxy(49,13);
        cout<<" A="<<A<<"\tB="<<B;
    }
    else if(B>A)  //If group B wins
    {
         gotoxy(51,11);
        cout<<"!!!B won!!!";
         gotoxy(49,13);
        cout<<" A="<<A<<"\tB="<<B;
    }
    else //If there is a tie
    {
         gotoxy(53,11);
        cout<<"Tie.";
         gotoxy(49,13);
        cout<<" A="<<A<<"\tB="<<B;
    }
    getchar();
}
int printrndfour()  // Last round till now 
{
  a4=0;
  b4=0;         // first declaraing all values or marks of fourth round zero
  bo7=0;        // This is done so that on error after showing error screen all marks counted previously becomes zero to avoid confusion
  bo8=0;
  r=4;
  system("clear");
  cout<<"\nGroup: A";
 cout<<"\n7.) Who discovered neutron ?";// Question seven 
  cout<<"\n a.) James Chadwick.";
  cout<<"\n b.) Einstein."; //Put your correct option here. 
  cout<<"\n c.) Newton.";
  cout<<"\n d.) Haris.";
  char g;
  // Don't change here anything
 timerO();// Taking input answer
  cin>>g;
   switch(g)
    {
        case 'a':  // If correct answer is given by group A 
            a4=10;// Full marks
        break;
         case 'z':
            printawon();    
        case'u':// if group A wants to unattempt the answer
            a3=0;// Marks = 0 as per marking scheme
            cout<<"Do you want bonus round(y/n):"; // Asks group B for bonus
            cin>>p7;
            switch(p7)
            {                                           //Especially here please don't change it else marks would not be counted
                case 'y':
                timerB(); // Taking bonus answer
                 cin>>o7;
                 if(o7=='a')  // If answer is correct
                 {
                     bo7=5; // Full marks
                 }
                 else   // If wrong 
                 {
                     bo7=0; // 0 marks
                 }
                  break;
                case 'n':// if bonus round is to be avoided
                 break; 
                 default: // IF input is wrong i.e. not in y/n
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror(); // Error screen not compier one 
                  break;
                }
        break;
        default:// if wrong answer is given by group A 
            a4=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p7;
            switch(p7)
            {
                case 'y':
                 timerB(); // Again asks for bonus
                 cin>>o7;
                 if(o7=='a')
                 {
                     bo7=5;
                 }
                 else  //Everything is same like previous bonus part
                 {
                      
                     bo7=0;// I am using here a bit shortcut
                     int c1 = std::cin. get();
                 }
                 break;
                case 'n':
                    break; 
                 default:
                 cout<<"Invalid Input";
                 int c998 = std::cin.get();
                  printerror();
                  break;
            }
    }

 int c3 = std::cin. get();
 system("clear");
 cout<<"Group: B"<<endl;
  cout<<"8.) Who discovered electron?"; // Question six
  cout<<"\n a.) Purkinje.";
  cout<<"\n b.) J.J. Thompson.";
  cout<<"\n c.) Brown.";
  cout<<"\n d.) Rutherford.";
  char h;
timerO();
  cin>>h;
   switch(h)
    {
        case 'b':
            b4=10;
        break;
         case 'z':
               printbwon();    
        case'u':
            b4=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p8;
            switch(p8)
            {
                case 'y':
                timerB();
                 cin>>o8;
                 if(o8=='b')
                 {
                     bo8=5;
                 }
                 else
                 {
                     bo8=0;
                 }
                
                break;
                case 'n':
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c997 = std::cin.get();
                  printerror();
                  break;
            }
        break;
        default:
            b4=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p8;
            switch(p8)
            {
                case 'y':
                 timerB();
                 cin>>o8;
                 if(o8=='b')
                 {
                     bo6=5;
                 }
                 else
                 {
                      
                     bo6=0;
                     int c16 = std::cin. get();
                 }
                 break;
               case 'n':
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c997 = std::cin.get();
                  printerror();
                  break;
            }
    }

scrbrd();
 return 0;
}
int printrndthree()  // third round now 
{
  a3=0;
  b3=0;         // first declaraing all values or marks of thid round zero
  bo5=0;        // This is done so that on error after showing error screen all marks counted previously becomes zero to avoid confusion
  bo6=0;
  r=3;
  system("clear");
  // AT first telling correct answer of previous question
  cout<<"\nGroup: A";
  cout<<"\n5.) Who discovered e=mc^2 ?";// Question five 
  cout<<"\n a.) Einstein.";
  cout<<"\n b.) James."; //Put your correct option here. 
  cout<<"\n c.) Goebbels.";
  cout<<"\n d.) Haris.";
  char e;
  // Don't change here anything
  timerO();  // Taking input answer
  cin>>e;
   switch(e)
    {
        case 'a':  // If correct answer is given by group A 
            a3=10;// Full marks
        break;
        case'u':// if group A wants to unattempt the answer
            a3=0;// Marks = 0 as per marking scheme
            cout<<"Do you want bonus round(y/n):"; // Asks group B for bonus
            cin>>p5;
            switch(p5)
            {                                           //Especially here please don't change it else marks would not be counted
                case 'y':
                timerB();; // Taking bonus answer
                 cin>>o5;
                 if(o5=='a')  // If answer is correct
                 {
                     bo5=5; // Full marks
                 }
                 else   // If wrong 
                 {
                     bo5=0; // 0 marks
                 }
                
                break;
                case 'n':// if bonus round is to be avoided
                        // No condition declared to proceed to next part
                 break; 
                 default: // IF input is wrong i.e. not in y/n
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror(); // Error screen not compier one 
                  
                  break;
                    
            }
        break;
        default:// if wrong answer is given by group A 
            a3=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p5;
            switch(p5)
            {
                case 'y':
                timerB(); // Again asks for bonus
                 cin>>o5;
                 if(o5=='a')
                 {
                     bo5=5;
                 }
                 else  //Everything is same like previous bonus part
                 {
                      
                     bo5=0;// I am using here a bit shortcut
                    
                     int c1 = std::cin. get();
                 }
                 break;
                  
               case 'n':
                  
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c998 = std::cin.get();
                  printerror();
                  break;
            }
    }

 
 int c3 = std::cin. get();
 system("clear");
cout<<"Group: B"<<endl;
 cout<<"\n6.) Who coined the term protoplasm?"; // Question six
  cout<<"\n a.) Rutherford.";
  cout<<"\n b.) Purkinje.";
  cout<<"\n c.) Brown.";
  cout<<"\n d.) Bohr.";
  char f;
 timerO();
  cin>>f;
   switch(f)
    {
        case 'b':
            b3=10;
             scrbrd();
        break;
        case'u':
            b3=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p6;
            switch(p6)
            {
                case 'y':
                timerB();
                 cin>>o6;
                 if(o6=='b')//correct answer
                 {
                     bo6=5;
                     scrbrd();
                 }
                 else
                 {
                     bo6=0;
                     scrbrd();
                 }
                
                break;
                case 'n':
                  scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c997 = std::cin.get();
                  printerror();
                  
                  break;
                    
            }
        break;
        default:
            b3=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p6;
            switch(p6)
            {
                case 'y':
                timerB();
                 cin>>o6;
                 if(o6=='b')//correct answer
                 {
                     bo6=5;
                     scrbrd();
                 }
                 else
                 {
                      
                     bo6=0;
                    scrbrd();
                     int c16 = std::cin. get();
                 }
                 break;
                  
               case 'n':
                  scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c997 = std::cin.get();
                  printerror();
                  break;
            }
    }
printrndfour();
 return 0;
}
int printrndtwo()
{ 
    a2=0;
    b2=0;
    bo3=0;
    bo4=0;
    r=2;
  system("clear");

  cout<<"\nGroup: A";
 cout<<"\n3.) Conio.h refera to :"; // Question three
  cout<<"\n a.) console in out.";
  cout<<"\n b.) header file.";
  cout<<"\n c.) both a and b.";
  cout<<"\n d.) None.";
  char c;
  
timerO();
  cin>>c;
 switch(c)
    {
        case 'c':
            a2=10;
             
   

        break;
        case'u':
            a2=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p3;
            switch(p3)
            {
                case 'y':
                timerB();
                 cin>>o3;
                 if(o3=='c')
                 {
                     bo3=5;
                 }
                 else
                 {
                     bo3=0;
                 }
                
                break;
                case 'n':
                  
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                  
                  break;
                    
            }
        break;
        default:
            a2=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p3;
            switch(p3)
            {
                case 'y':
                 timerB();
                 cin>>o3;
                 if(o3=='c')
                 {
                     bo3=5;
                 }
                 else
                 {
                      
                     bo3=0;
                    
                     int c1 = std::cin. get();
                 }
                 break;
                  
               case 'n':
                  
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                  break;
            }
    }
 int c3 = std::cin. get();
 system("clear");
 system("clear");
    cout<<"\n4.) Which king ruled France during 1774?"; // Question four
  cout<<"\n a.) Louis XX.";
  cout<<"\n b.) Louis XVI.";
  cout<<"\n c.) Louis XV.";
  cout<<"\n d.) Louis XIV.";
  char d;
  timerO();
  cin>>d;
switch(d)
    {
        case 'b'://Correct answer
            b2=10;
    scrbrd();
        break;
        case'u':
            b2=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p4;
            switch(p4)
            {
                case 'y':
                 timerB();
                 cin>>o4;
                 if(o4=='b')//bonus correct answer
                 {
                     bo4=5;
                      scrbrd();
                 }
                 else
                 {
                     bo4=0;
                     scrbrd();
                 }
                 printrndthree();
                break;
               case 'n':
                scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c911 = std::cin.get();
                  printerror();
                  break;
                    
            }
        break;
        default:
            b2=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p4;
            switch(p4)
            {
                case 'y':
                timerB();
                 cin>>o4;
                 if(o4=='b')
                 {
                     bo4=5;
                     scrbrd();
                 }
                 else
                 {
                     
                     bo4=0;
                      scrbrd();
                     
                      int c2 = std::cin. get();
                     
                 }
                     scrbrd();
                 break;
                  
                case 'n':
                  scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                  printrndtwo();
                  break;
            }
    }
   printrndthree();
    return 0;
}
int printrndone()
{ 
  system("clear");
  a1=0;
    b1=0;
    bo1=0;
    bo2=0;
    r=1;
  cout<<"Group: A";
 cout<<"\n1.) Who was the first propaganda minister of hitler?";// Question One 
  cout<<"\n a.) James.";
  cout<<"\n b.) Gary.";
  cout<<"\n c.) Goebbels.";
  cout<<"\n d.) Haris.";
  timerO();
  char a,b;
 cin>>a;
   switch(a)
    {
        case 'c':
            a1=10;
        break;
        case 'u':
            a1=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p1;
            switch(p1)
            {
                case 'y':
                timerB();
                 cin>>o1;
                 if(o1=='c')
                 {
                     bo1=5;
                 }
                 else
                 {
                     bo1=0;
                 }
                break;
                case 'n':
                  
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                  break;
            }
        break;
        default:
            a1=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p1;
            switch(p1)
            {
                case 'y':
                 timerB();
                 cin>>o1;
                 if(o1=='c')
                 {
                     bo1=5;
                 }
                 else
                 {
                      
                     bo1=0;
                    
                     int c1 = std::cin. get();
                 }
                 break;
                  
               case 'n':
                  
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                 
                  break;
            }
    }
    system("clear");

  cout<<"\nGroup: B";
  cout<<"\n2.) When French Revolution Started?"; // Question two
 cout<<"\n a.) 1764";
  cout<<"\n b.) 1665.";
  cout<<"\n c.) 1122.";
  cout<<"\n d.) 1789.";
 
  
  timerO();
   cin>>b;
    switch(b)
    {
        case 'd'://correct answer
            b1=10;
             
   
    scrbrd();
        break;
        case 'u':
            b1=0;
            cout<<"Do you want bonus round(y/n):";
            cin>>p2;
            switch(p2)
            {
                case 'y':
                 timerB();
                 cin>>o2;
                 if(o2=='d')//bonus correct answer
                 {
                     bo2=5;
                 }
                 else
                 {
                     bo2=0;
                 }
                 scrbrd();
                break;
               case 'n':
                  scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                  break;
                    
            }
        break;
        default:
            b1=-5;
            cout<<"Do you want bonus round(y/n):";
            cin>>p2;
            switch(p2)
            {
                case 'y':
                timerB();
                 cin>>o2;
                 if(o2=='d')//bonus correct answer
                 {
                     bo2=5;
                 }
                 else
                 {
                     
                     bo2=0;
                     
                      int c2 = std::cin. get();
                     
                 }
                  scrbrd();
                 break;
                  
                case 'n':
                  scrbrd();
                 break; 
                 default:
                 cout<<"Invalid Input";
                 int c99 = std::cin.get();
                  printerror();
                 
                  break;
            }
    }
    printrndtwo();
    return 0;
}
int about()
{
     system("clear"); 
     printf("\n");
     cout<<UNDERLINE"\x1B[34m\nAbout:\033[0m"<<CLOSEUNDERLINE;
     cout<<" This is quiz app version 10.8 developed by Subhajit Halder";
     printf("\n       This is console based application. \t\t");
      cout<<"\x1B[32m\n\n\n\n\n\t\tTo raise a suggestion for the new version please write to subhajithalder267@outlook.com\033[0m";
     getchar();
     getchar();
         printrndone();
}
int evaluator()
{
     system("clear");
      cout<<"Evaluated By: Ritabrata Saha";
       int chhh=std::cin.get();
      int c444=std::cin.get();
      prompt();
}
int cheatcode()
{
    
      system("clear");
      cout<<"\n\x1B[31mEvery Game has certain cheat codes or cheat sheets\033[0m";
      cout<<"\nQuiz ver:10.8 is also having it as it is a quiz game.";
      cout<<"\nList of All correct answers.";
    cout<<"\nCorrect Answers:";
    cout<<"\n1.) C";
    cout<<"\n2.) D";
    cout<<"\n3.) C";                   
    cout<<"\n4.) B";
    cout<<"\n5.) A";
    cout<<"\n6.) B";
     cout<<"\n7.) A";
    cout<<"\n8.) B";
       int chhh=std::cin.get();
      int c444=std::cin.get();
      printrndone();
}
int start()
{gotoxy(1,1);
    system("clear");
   cout <<" "<<UNDERLINE<< "\t\t\t\t\t\t Quiz "<<CLOSEUNDERLINE;
  cout <<"\n\t\t\t\t\t     " <<UNDERLINE<<"Version:10.01"<<CLOSEUNDERLINE;
  cout << "\n\t\t\t\t\t    "<<UNDERLINE<<"(Round: 1 - 4 )"<<CLOSEUNDERLINE;
  cout << "\nGeneral Instructions:";
  cout << "\t\t\t\t\t\t\tMarking Scheme:";
  cout << "\na.) This quiz has 4 rounds";
  cout << "\t\t\t\t\t\ti.) Each C.A. 10m";
  cout << "\nb.) Each group can answer 4 questions";
  cout << "\t\t\t\t\tii.) Each W.A. -5m";
  cout << "\nc.) Two groups can attempt the quiz";
  cout << "\t\t\t\t\tiii.) Each U.A. 0m";
  cout << "\nd.) To Unattempt a question type letter 'u' other than the option.";
  cout << "\tiv.) Each B.A. 5m";
  cout<<"\ne.)Each question must be answered in 20 seconds(for originals)";
  cout<<"\nf.)Each bonus question must be answered in 05 seconds";
  cout<< "\n\n\t\t\t\tUsed Short Abbreviations:";
  cout<< "\t\tNew Improvements and bug fixes:";
  cout<<"\n\t\t\t\t1.) C.A. = Correct answer";
  cout<<"\t\t1.) SOURCE CODE VIEW";
  cout<<"\n\t\t\t\t2.) W.A. = Wrong answer";
    cout<<"\n\t\t\t\t3.) U.A. = Unattempted answer";
     cout<<"\n\t\t\t\t4.) B.A. = Bonus answer";
 cout<<"\n\t\t\t\t4.) B.A. = Bonus answer";
     cout<<"\n\n\tQUIZ MASTER: Subhajit Halder";
     cout<<"\t\t\t\tDeveloper: Subhajit Halder";
 cout<<"\x1B[31m \n\n\n\t\t\t\t        <<Press ENTER to Continue>>\033[0m";
 getchar();
  int ch = std::cin. get();
  if(ch==105) // ASCII value of a letter .Guess it
  {
      about();
  }
  else if(ch==101)//ASCII value of a letter. Guess it
  {
     
      evaluator();
  }
   else if(ch==99)//ASCII value of a letter. Guess it
  {
      cheatcode();
  }
  else
  {
      printrndone();
  }
   return 0;
}
int timerO () 
{
 // Local variable declaration:
   int a = 0;
  
   // while loop execution
   while( a >=0 ) 
   {
       gotoxy(70,2);
      cout << "TIME LEFT: " << a <<"sec(s)"<<endl;
      sleep(1);
      a--;
      if(a==-1)
      {
        
      gotoxy(1,11);
      cout<<"TIME OUT";
      
          
          gotoxy(1,12);
          cout<<"Enter your answer:";
      }
   }
}
int timerB () {
 // Local variable declaration:
   int a = 0;
  
   // while loop execution
   while( a >=0 ) {
       gotoxy(70,2);
      cout << "TIME LEFT: " << a <<"sec(s)"<<endl;
      sleep(1);
      a--;
      if(a==-1)
      {
       gotoxy(1,16);
       cout<<"TIME OUT";
          gotoxy(1,17);
          cout<<"Enter your answer:";
      }
   }
 
   return 0;
}
int timerS () 
{
 int a = 10;
 cout<<bold<<RED;
 gotoxy(40,10);
  cout<<"ACCESS DENIED";
  gotoxy(40,11);
  cout<<"Invalid Password.";
                        // while loop execution
     while( a >=0 ) 
     {
        gotoxy(70,7);
        cout << "TIME UNTIL SHUTDOWN: " << a <<"sec(s)"<<endl;
         sleep(1);
        a--;
        if(a==-1)
        {
         exit(0);
        }
    }
return 0;
}
void password_change()
{ system("clear");
cout<<red<<bold<<UNDERLINE<<"\nWelcome to password changing wizard Ver 1.0."<<cc<<cc;
    cout<<yellow<<"\nEnter Following details :"<<cc;
    string name1,name,password,passnew,password1;
    cout<<"\nUser-ID:";
    cin>>name;
    fstream file1;
       file1.open("file.txt");
       file1>>name1;
       if(name1==name)
       {        fstream file;
                string word, t, q, filename;
                filename = "file2.txt";        // opening file
                file.open(filename.c_str());
                if (file.good()) //if Password exists
                {
                   cout<<"\nEnter your last Password:";
                   cout<<invisible;
                   cin>>password;
                   cout<<cc;
                    fstream file2;
                    file2.open("file2.txt");
                    file2>>password1;
                        if(password1==password)
                        {
                           
                            cout<<"Enter new password:";
                            cin>>passnew;
                            getchar();
                            fstream f1;
                            f1.open("file2.txt",ios::out);
                             f1<<passnew;
                             f1.close();
                             cout<<"\nYour password has been changed";
                             getchar();
                            prompt();
                            
                        }
                        else //intruder
                        {
                            timerS();
                        }
                }
                else//if password doesn't exists
                {
                fstream f2;
                string pass;
                f2.open("file2.txt",ios::out);
                cout<<"Enter password:";
                cin>>pass;
                f2<<pass;
                f2.close();
                 cout<<"\nYour password has been changed";
                getchar();
                }
        }
       else//intruder
       {
           timerS();
       }
}
void prompt()//Main controller
{
    system("clear");
    cout<<red<<bold<<UNDERLINE;
    cout<<"\nOperating Environment ver:3.00";
    cout<<cc;
    cout<<blue<<bold;
    cout<<"\nType help to get list of commands";
    cout<<cc;
    while(true)
    {
        if(ins==9)//if guest user 
        {
            cout<<"\nOnly available commands are install and exit";
            cout<<"\nCommand->";
            string command;
            cin>>command;
            if(command=="install")
            {
                fstream file;
                string word, t, q, filename;
                    bs=1;
                filename = "file.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
                {
                  cout<<"Already  installed.";
                  cout<<"\nType exit and re login with your user ID password";
                }
                else{
                    IP();
                }
            }
            else if(command=="exit")
            {
                exit(0);
            }
            else if(command=="reg_edit")
            {
                cout<<"\nNo such command";
                cout<<"\nCommand->";
                cin>>command;
                if(command=="reg_edit")
                {
                    cout<<"\nNo such command";
                        cout<<"\nCommand->";
                        cin>>command;
                        if(command=="reg_edit")
                        {
                           reg_edit();
                        }
                        else
                        {
                            cout<<"\nNo such command";
                        }
                }
            }
            else
            {
                
              fstream file;
                string word, t, q, filename;
                    bs=1;
                filename = "file.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
                {
                  cout<<"\nI see you trying to access user features without a password. But access denied.";
                }
            }
        }
        else//If a proper user
        {                cout<<"\nCommand->";
           string command;
            cin>>command;
            if(command=="Help"||command=="HELP"||command=="help")//Help command to make the command interface easy
            {
                cout<<"\nType:";
                cout<<"\n\tTicTacToe";
                cout<<"\n\tCalculator";
                cout<<"\n\tQuiz";
                cout<<"\n\tTemp_Conv";
                cout<<"\n\teqn_solve";
                cout<<" to open the above applications(if installed).";
                cout<<"\nType:";
                cout<<"\n\texit";
                cout<<"\n\tclear";
                cout<<"\n\tinst_all";
                cout<<"\n\tchange: To change your existing password.";
                cout<<"\n\tTo exit or clear the screen.";
                cout<<"\n\tTo install al applications except TicTacToe and Quiz at once.";
                cout<<"\n\tTo install an app from above  list type inst_'with app name'";
                cout<<"\n\tTo uninstall an app from above  list type unst_'with app name'";
            }
            else if (command=="TicTacToe"||command=="tictactoe"||command=="TICTACTOE")
            {
                bs=1;
                fstream f;
                f.open("TicTacToe.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
              bootscreen();
              selector_t();
                }
                else 
                {
                  cout<<"\nNot installed yet";
                }
            }
             
             else if (command=="Quiz"||command=="QUIZ"||command=="quiz")
            {fstream f;
                f.open("Quiz.txt",ios::in);
                f>>reg;
                    bs=2;
               if (reg==1) 
                {
                   bootscreen();
                   start();
                }
                else 
                {
                  cout<<"\nNot installed yet";
                }
                
            }
             else if (command=="TEMP_CONV"||command=="temp_conv"||command=="Temp_Conv")
            {
                    bs=3;
               fstream f;
                f.open("TC.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
               bootscreen();
              tc();
                }
                else 
                {
                  cout<<"\nNot installed yet";
                }
            }
            
            else if(command=="cls"||command=="clear")
            {
                system("clear");
            }
            else if(command=="exit"||command=="EXIT"||command=="Exit")
            {
                system("clear");
                cout<<"Program is shuttng Down";
                sleep(1);
                exit(0);
            }
            else if(command=="inst_TicTacToe")
            {
                v=1;
                bs=1;
               fstream f;
                f.open("TicTacToe.txt",ios::in);
                f>>reg;
                if (reg==1) 
                {
                cout<<"\nAlready installed";
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
                {
                cout<<"\nAlready installed";
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
                {
                cout<<"\nAlready installed";
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
                {
                cout<<"\nAlready installed";
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
                {
              
                   cout<<"\nNot installed yet";
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
                {
                  cout<<"\nNot installed yet";
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
                {
                cout<<"\nAlready installed";
                }
                else 
                {
                 bootscreen();
                    installer();
                    get_Eqn();
                }
            }
            else if(command=="unst_eqn_solve")
            {
                fstream f;
                reg =0;
                f.open("solve.txt",ios::out);
                f<<reg;
                f.close();
                cout<<"\nUnistallation finished.";
            }
            else if(command=="unst_TicTacToe")
            {
                fstream f;
                reg =0;
                f.open("TicTacToe.txt",ios::out);
                f<<reg;
                f.close();
                cout<<"\nUnistallation finished.";
            }
            else if(command=="unst_Temp_Conv")
            {
                fstream f;
                reg =0;
                f.open("TC.txt",ios::out);
                f<<reg;
                f.close();
                cout<<"\nUnistallation finished.";
            }
            else if(command=="unst_Calculator")
            {
                fstream f;
                reg =0;
                f.open("Calc.txt",ios::out);
                f<<reg;
                f.close();
                cout<<"\nUnistallation finished.";
            }
            else if(command=="unst_Quiz")
            {
                fstream f;
                reg =0;
                f.open("Quiz.txt",ios::out);
                f<<reg;
                f.close();
                cout<<"\nUnistallation finished.";
            }
            else if(command=="reg_edit")
            {
                cout<<"\nNo such command";
                cout<<"\nCommand->";
                cin>>command;
                if(command=="reg_edit")
                {
                    cout<<"\nNo such command";
                        cout<<"\nCommand->";
                        cin>>command;
                        if(command=="reg_edit")
                        {
                           reg_edit();
                        }
                        else
                        {
                            cout<<"\nNo such command";
                        }
                }
                else
                {
                    cout<<"\nNo such command";
                }
            }
            else if(command=="change")
            {
                password_change();
            }
            else if(command=="guess_it")
            {
                cout<<"\nNo such command";
                cout<<"\nCommand->";
                cin>>command;
                if(command=="guess_it")
                {
                    cout<<"\nNo such command";
                        cout<<"\nCommand->";
                        cin>>command;
                        if(command=="guess_it")
                        {
                           source();
                        }
                        else
                        {
                            cout<<"\nNo such command";
                        }
                }
                else
                {
                    cout<<"\nNo such command";
                }
            }
            else if(command=="inst_all")
            {
                reg=1;
                 fstream tc,c,eqn;
                  tc.open("TC.txt",ios::out);
                  tc<<reg;
                  tc.close();
                  c.open("Calc.txt",ios::out);
                  c<<reg;
                  c.close();
                  eqn.open("solve.txt",ios::out);
                  eqn<<reg;
                  eqn.close();
            }
             else
            {
                cout<<"\nNo such commands";
            }
        }
    }
}
int main()
{
    bs=0;
    bootscreen();
     fstream file;
            string word, t, q, filename;
            filename = "file.txt";      // opening file
            file.open(filename.c_str());
            if (file.good()) 
            {
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
gotoxy(2,5);
 string c;
    cout<<"Do you want to directly install this application or you want to use it once before installation?(Enter choice below).";
     gotoxy(18,7);
    cout<<RED<<bold<<UNDERLINE"Help Me Decide:"<<cc;
    gotoxy(18,9);
    cout<<blue<<bold<<"If you wish to install the program directly on the browser without testing for once press y.";
     gotoxy(18,10);
    cout<<"If you want to test the progarm before installing i.e. if you want to have a look at the user interface";
     gotoxy(18,11);
    cout<<"press n and it will load you into the guest user login screen. Enter GUEST or Guest there to login. As it";
     gotoxy(18,12);
    cout<<"is trial so only two commands that is install and exit would be there.";
     gotoxy(18,15);
    cout<<yellow<<bold<<"Enter your choice(y/n):";
  cout<<invisible;
  cin>>c;
  cout<<cc;
  if(c=="y")
    {system("clear");
    layout();
    logo();
        gotoxy(18,6);
  cout<<UNDERLINE<<red<<bold<<"While the game is loading let us know its working:"<<CLOSEUNDERLINE;
  gotoxy(18,8);
   cout<<yellow<<"At first type help command at the prompt.";
   gotoxy(18,9);
   cout<<"You will be getting a list of available commands use it  "<<CLOSEUNDERLINE;
   gotoxy(78,8);
   cout<<purple<<"Desingned for ease"<<cc;
   gotoxy(18,10);
   cout<<yellow<<"to install your desired program"<<cc;
   gotoxy(78,9);
   cout<<purple<<"For ease in using "<<cc;
   gotoxy(18,11);
   cout<<yellow<<"Enjoy using it!!!"<<cc;
   gotoxy(78,12);
    cout<<purple<<"softwares"<<cc;
    gotoxy(78,14);
    cout<<green<<"DEVELOPER:"<<RED<<" Subhajit Halder";
  gotoxy(2,6);
 progressbar();
 sleep(6);
add_user();
   cout<<"Installed";
      reg=0;
          install();
          Improvements();
          img();
    }
    else if(c=="n")
      {  
          system("clear");
          gotoxy(1,1);
          layout();
          logo();
         gotoxy(2,5);
      cout<<"After completeion of your trial the program will stop. You have to restart the setup to continue.";
     login();
      }
     else if(c=="reg_edit")
     {
         reg_edit();
     }
}
void reg_edit()
{
    system("clear");
    cout<<bold<<UNDERLINE<<red<<"Welcome to Registry Editor version:3.0(For Power Users)."<<cc;
    cout<<green<<bold<<"\nAvailable commands:"<<cc;
    cout<<yellow<<bold<<"\n\ta.)install";
    cout<<"\n\tb.)add_key (Only for Quiz and TicTacToe)";
    cout<<"\n\tc.)exit";
    cout<<"\n\td.)temp";
    cout<<"\n\te.)user";
    cout<<"\n\tf.)reset";
    cout<<"\n\tg.)clear";
    cout<<"\n\th.)help (It is adviced to use help command first to gets uses of available commands."<<cc;;
    while(true)
    {
            string command;
            reg=1;
            cout<<"\nCommand->";
            cin>>command;
            fstream t,q,tc,c,eqn;
            if(command=="install")
            {
                  install();
                  cout<<"\nSuccesfully completed the command";
            }
            else if(command=="add_key")
            {
                cout<<"\nCommand->";
                cin>>command;
                        if(command=="both")
                        {
                          t.open("TicTacToe.txt",ios::out);
                          t<<reg;
                          t.close();
                          q.open("Quiz.txt",ios::out);
                          q<<reg;
                          q.close();
                          cout<<"\nSuccesfully completed the command";
                        }
                        else if(command=="quiz")
                        {
                            q.open("Quiz.txt",ios::out);
                          q<<reg;
                          q.close();
                          cout<<"\nSuccesfully completed the command";
                        }
                        else if(command=="tictactoe");
                        {
                             t.open("TicTacToe.txt",ios::out);
                          t<<reg;
                          t.close();
                          cout<<"\nSuccesfully completed the command";
                        }
                        
            }
            else if(command=="exit")
            {
                layout();
                logo();
                login();
            }
            else if(command=="temp")
            {
                    cout<<"\nCommand->";
                    cin>>command;
                    if(command=="TTT"||command=="ttt")
                    {
                        computer_vs_player();
                    }
                    else if(command=="quiz")
                    {
                        start();
                    }
                    else
                    {
                        cout<<"\ntemp command is available for only two programs";
                    }
            }
            else if(command=="user")
            {
                fstream file;
                string word, t, q, filename;
                filename = "file.txt";      // opening file
                file.open(filename.c_str());
                        if (file.good()) 
                        {
                           cout<<"\nWarning! This command will reset all your user-id password";
                           cout<<"\nDo you want to continue:";
                           char a;
                           cin>>a;
                                   if(a=='y')
                                   {
                                       add_user();
                                       getchar();
                                       cout<<"\nSuccesfully completed the command";
                                   }
                        }
                        else 
                        {
                           add_user();
                           getchar();
                           cout<<"\nSuccesfully completed the command";
                        }
            }
            else if(command=="reset")
            {
                 cout<<"\nWarning! This command will reset all applications";
                 cout<<"\nDo you want to continue:";
                           char a;
                           cin>>a;
                                   if(a=='y')
                                   {reg=0;
                                        install();
                                        cout<<"\nSuccesfully completed the command";
                                   }
            }
            else if(command=="clear"||command=="cls")
            {
                system("clear");
            }
            else if(command=="help")
            {
                cout<<blue<<bold<<"\n Welcome to HELP Documenntation Ver: 1.0. :"<<cc;
                cout<<"\n\ta.)install: To install all the programs at once.";
                cout<<"\n\tb.)add_key (Only for Quiz and TicTacToe): To install only TicTacToe and Quiz.";
                cout<<"\n\tc.)exit: Exit the Registry Editor and open the login screen.";
                cout<<"\n\td.)temp: To access a program temporaily(For TicTacToe and QUIZ).";
                cout<<"\n\te.)user: To add a new user or to do password bypass.";
                cout<<"\n\tf.)reset: To uninstall all applications.";
                cout<<"\n\tg.)clear: To clear the output screen.";
            }
            else
            {
                cout<<"\nNo available command";
            }
    }
}
void add_user()
{
     fstream f1,f2,f3;
   string id,pass,c;
   system("clear");
     layout();
     gotoxy(2,5);
     cout<<UNDERLINE<<RED<<bold<<"Welcome to USER-ID Password Creation Wizard Ver 1.0."<<cc;
     gotoxy(2,6);
     cout<<"FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER";
     gotoxy(2,7);
   cout<<yellow<<"PLease create a user id password for safety reasons:"<<cc;
   gotoxy(2,8);
         cout<<"User-Id:";
       cin>>id;
       gotoxy(2,9);
          cout<<"Do you want to create a password(y/n):";
          cin>>c;
          if (c=="y")
          {   f2.open("file2.txt",ios::out);
          f1.open("file.txt",ios::out);
          gotoxy(2,13);
           cout<<"Enter password:";
           cin>>pass;
           f1<<id;
           f2<<pass;
           f1.close();
           f2.close();
           gotoxy(2,15);
           cout<<"You are Successfull in creating a user.";
           getchar();
            system("clear");
            getchar();
          }
          else
          {
            getchar();
            system("clear");
            gotoxy(2,15);
           cout<<"You are Successfull in creating a user.";
            f1.open("file.txt",ios::out);
             f1<<id;
           f1.close();
            getchar();
          }
}
void install()
{
    fstream t,q,tc,c,eqn;
    t.open("TicTacToe.txt",ios::out);
          t<<reg;
          t.close();
          q.open("Quiz.txt",ios::out);
          q<<reg;
          q.close();
          tc.open("TC.txt",ios::out);
          tc<<reg;
          tc.close();
          c.open("Calc.txt",ios::out);
          c<<reg;
          c.close();
          eqn.open("solve.txt",ios::out);
          eqn<<reg;
          eqn.close();
}
void img()
{
                            cout<<"\n ---------------------------------------------------------";
      cout<<"\n|"<<bold<<UNDERLINE<<red" Welcome to Registry Editor version:3.0(For Power Users)."<<cc<<"|";
                            cout<<"\n| Available commands:                                     |"<<cc;
                            cout<<"\n| a.)Install                                              |";
                            cout<<"\n| b.)add_key (Only for Quiz and TicTacToe)                |";
                            cout<<"\n| c.)exit                                                 |";
                            cout<<"\n| d.)temp                                                 |";
                            cout<<"\n| e.)user                                                 |";
                            cout<<"\n| f.)reset                                                |";
                            cout<<"\n ---------------------------------------------------------";
    cout<<"\nOne of the HIDDEN FEATURES. Invest your time in finding many of them.(some of them are in individual apps)";;
}
void logo()
{   gotoxy(2,8);
    cout<<RED<<bold<<" ---------- "<<cc<<cc;
    gotoxy(2,9);
    cout<<RED<<bold<<"|  ==   == |"<<cc<<cc;
    gotoxy(2,10);
    cout<<RED<<bold<<"| |  | |   |"<<cc<<cc;
    gotoxy(2,11);
    cout<<RED<<bold<<"| |  |  == |"<<cc<<cc;
    gotoxy(2,12);
    cout<<RED<<bold<<"| |  | |   |"<<cc<<cc;
    gotoxy(2,13);
    cout<<RED<<bold<<"|  ==   == |"<<cc<<cc;
    gotoxy(2,14);
    cout<<RED<<bold<<" ---------- "<<cc<<cc;
}


