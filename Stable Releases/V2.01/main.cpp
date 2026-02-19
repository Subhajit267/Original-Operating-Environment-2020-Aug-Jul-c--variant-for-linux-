#include<chrono> //for sleeping             //Basically jotogulo predefined function commonly use kori sei sob mention korlam  :)
#include<thread> // --do-- 
#include<cstdlib>//for random increments
#include<ctime>// --do-- 
#include<iostream>
#include <stdlib.h>
#include <string>
void password_change();
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
using namespace std;
     int source();
     int scr();
     int ins,bs;
   void IP();
    int v;
void bootscreen();
void login();
void password_change();
#define cc "\033[0m"
void gotoxy(int x,int y)// declaring the cursor position
{
    printf("%c[%d;%df",0x1B,y,x);
}
void activation();
int ap;
double A1,A2,B1,B2,C1,C2,x,y,m,n;
 char C,A_1;

void solve()//To solve the equations
{
    x=((B1*C2) - (B2*C1))/n;
    y=((A2*C1) - (A1*C2))/n;
    cout<<"X = \033[31m"<<-1*x<<"\033[0;1m and Y = \033[31m"<<-1*y;
}
void get_Side()//to get the side of constant terms
{
     cout<<"Are all the constant terms in same side:";
    cin>>C;
     
    if(C=='y')
    {
         cout<<"Are the constant terms alone in one side?";
        cin>>A_1;
           if(A_1=='y')
          {
             m=1;
              n=n*m;
             solve();
                            
          }
           else if(A_1='n')
          {
             m=-1;
             n=n*m;
            solve();
          }
    }
    else if(C=='n')
    {
     C2=(C2*-1);
     solve();
    }
}

void get_Eqn()//to get the equation
{
   system("clear");
    cout<<"\033[1;4m/*IT MUST BE NOTED THAT ALL THE X,Y and constant terms must be numbers*/\033[0m"<<endl;
    cout<<"\033[1mEnter the value of a1/coefficient of x in first equation:";
    cin>>A1;
    cout<<"Enter the value of b1/coefficient of y in first equation:";
    cin>>B1;
    cout<<"Enter the value of c1/constant in first equation:";
    cin>>C1;
    cout<<"Enter the value of a2/coefficient of x in second equation:";
    cin>>A2;
    cout<<"Enter the value of b2/coefficient of y in second equation:";
    cin>>B2;
    cout<<"Enter the value of c2/constant term in second equation:";
    cin>>C2;
    n=((A1*B2) -(A2*B1));
    if(A1*B2 != A2*B1)//Checking if the given equations have unique solution or not
    {
       get_Side();
    }
    else{
        cout<<"\nSolution can be given only to equations with unique solution";
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

#define cyan "\x1B[36m"
#include<fstream>
#define invisible "\x1B[8m"
#include <random>
using namespace std;
void prompt();
class pBar {
public:
    void update(double newProgress) {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
    }
    void print() {
        currUpdateVal %= pBarUpdater.length();
        gotoxy(28,12);
        cout<< firstPartOfpBar; //Print out first part of pBar
        for (int a = 0; a < amountOfFiller; a++) { //Print out current progress
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++) { //Print out spaces
            cout << " ";
        }
        cout << lastPartOfpBar //Print out last part of progress bar
            << " (" << (int)(100*(currentProgress/neededProgress)) << "%)" //This just prints out the percent
            << flush;
        currUpdateVal += 1;
    }
    std::string firstPartOfpBar = "[", //Change these at will (that is why I made them public)
        lastPartOfpBar = "]",
        pBarFiller = "|",
        pBarUpdater = "/-\\|";
private:
    int amountOfFiller,
        pBarLength = 50, //I would recommend NOT changing this
        currUpdateVal = 0; //Do not change
    double currentProgress = 0, //Do not change
        neededProgress = 100; //I would recommend NOT changing this
};
void progressbar(){ 
	std::srand(time(NULL)); //seed random 
	for(int progress=0;progress!=100;progress+=std::rand()%20){
	    gotoxy(40,20);//increment progress randomly 
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
void Improvements()
{
    system("clear");
    cout<<bold<<RED<<UNDERLINE<<"New Improvments and Bug Fixes:"<<cc;
    cout<<bold<<blue<<"\ni.)Change in programming";
    cout<<bold<<yellow<<"\nii.)Less Resource hungry";
    cout<<bold<<blue<<"\niii.)Introduction of a new program";
    cout<<bold<<yellow<<"\niv.)Now only need to login once";
    cout<<bold<<blue<<"\nv.)Installing programs take less time";
    cout<<bold<<yellow<<"\nvi.)Introduction of bootscreen for main program.";
    cout<<bold<<green<<"\nNext version comming with more features";
    getchar();
    cout<<cc;
}
 int printerror() // To avoid any error in marks counting this section is used
{ 
    system("clear");  
     printf("\n");
     printf("\x1B[31m\t\t\t\tAn Unexpected error occured due to invalid input\033[0m\t\t");
     printf("\x1B[34m\nPlease restart the program\033[0m\t\t");
    int c77 = std::cin. get();
   exit(0);
}
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//board e jotogulo position acche sob declare korechi
void show_board();//board show korar function
void get_x_player_choice();// getting player's choice whose letter is X
void get_o_player_choice();// getting player's choice whose letter is O
void get_computer_choice();
int count_board(char symbol);
char check_winner();// checking the winner
void computer_vs_player();// declaring how computer can play with the player
void player_vs_player();
void selector_t();
void installer()//installer for all programs
{
      system("clear");
      if(v==1 && bs==1)//at differnt states which title will be shown tar jonno
      {
        system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tTIC TAC TOE"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:3.0";
      }
      else if(v==2 && bs==2)
      {
          system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tQUIZ__APP"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:10.5";
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
        cout <<"\n\t\t\t\t\t      "<<"  Version:1.01";
      }
cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
cout <<"\n\n\n\t\t\t\t\t        Please_Wait.";//Ei gulo common strings
cout<<"\n\t\t\t\t\t     While setup is";
cout<<"\n\t\t\t\t\t        Installing...";
 progressbar();
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
         f.close();
      }
       else if(v==4 && bs==4)
      {
         fstream f;
         f.open("Calc.txt",ios::out);
         f.close();
      }
      
       else if(v==6 && bs==6)
      {
         fstream f;
         f.open("solve.txt",ios::out);
         f.close();
      }
    sleep(2);
}

void activation()//Common activation method for tictactoe and Quiz
{system("clear");
cout<<"\nEnter product key(10 charcters):";
    char key[10];
    cin>>key;
if(v==1)
{
 if(key[5]+key[1]==key[4]+key[2])
       {
       
       cout<<"verified";
       getchar();
       fstream k,t;
       k.open("file3.txt",ios::out);
       k<<key;
       k.close();
       t.open("TicTacToe.txt"); 
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
     if(key[1]+key[2]==key[8]+key[9])
   {
       cout<<"verified";
       getchar();
       fstream k,t;
       k.open("file6.txt",ios::out);
       k<<key;
       k.close();
       t.open("QUIZ.txt"); 
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
  {  if(bs==1)
      {
        system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tTIC TAC TOE"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:3.0";
      }
      else if(bs==0)
      { system("clear");
        cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";
      }
      else if(bs==2)
      {
          system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tQUIZ__APP"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:10.5";
      }
      else if(bs==3)
      {
           system("clear");
            cout <<UNDERLINE<< "\t\t\t\t\t\tTEMP_CONV"<<CLOSEUNDERLINE;
            cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
      }
      else if(bs==4)
      {
          system("clear");
        cout <<UNDERLINE<< "\t\t\t\t\t\tCALCULATOR"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:3.05";
      }
      else if(bs==6)
      { system("clear");
          gotoxy(46,1);
        cout <<UNDERLINE<< "Pair_of_eqn_solve"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:1.01";
      }
      
  cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
    cout <<"\n\n\n\t\t\t\t\t        Please_Wait.";
     cout <<"\n\n\t\t\t\t\t        Loading.....";
     
     cout<<"  ";
    progressbar();
    sleep(0.5);
     
  }
  
void login()
{
   system("clear");
system("clear");
        cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";
        cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
  cout<<"\nTo begin enter your username and password";
  cout<<"\n /* To just test the program with limited features type GUEST in the place of USER NAME */ ";
    cout<<"\n /* To change your password type 'change' in thre place of user ID. */ ";
    //   cout<<"\n /* To add new user type ADD in the palce of user ID*/ ";
   cout<<"\nEnter user name:";
  cout<<" \x1B[36m ";
  string a,filename,name1,password,password1;
   cin>>a;
   cout<<"\033[0m";
    fstream file1,file;
       file1.open("file.txt");
       file1>>name1;
       if(name1==a)
       {
           filename = "file2.txt";
           file.open(filename.c_str());
            if (file.good()) 
            {
             cout<<"\nPassword:";
           cout<<invisible;
           cin>>password;
           cout<<cc;
                fstream file2;
                file2.open("file2.txt");
                file2>>password1;
                if(password1==password)
                {
                    cout<<bold<<red<<"\n\t\t\t\tWelcome"<<" "<<a;
                    sleep(0.5);
                    prompt();
                }
                else
                {
                        int a = 10;
                          cout<<"\nACCESS DENIED";
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
                }
            }
            else 
            {
               cout<<bold<<red<<"\n\t\t\t\tWelcome"<<" "<<a;
               sleep(0.5);
               prompt();
            }
       }
   else if(a=="GUEST"||a=="Guest")
   {
      getchar();
      system("clear");
      cout<<"IF YOU LIKED THE PROGRAM CONTACT THE ADMIN";
      cout<<"\nFOR YOUR USER ID AND PASSWORD TO VIEW FULL FEATURES OF THE PROGRAM";
      cout<<"\nADMIN: Subhajit Halder";
      cout<<"\nEmail Id: subhohalder267@gmail.com";
      cout<<"\nWhatsapp No. : 7047736124";
      getchar();
      ins=9;
      prompt();
   }
   else if(a=="admin")
   {
       source();
   }
   else if(a=="change")
   {
       password_change();
   }
 else
       {
           
                        int a = 10;
                          cout<<"\nACCESS DENIED";
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
       }
  
    system("clear");
}

void selector_t()
{
     int mode;
     sleep(1.5);
       system("clear");
      cout << "\t\t\t\t\t"<<bold<<UNDERLINE<<RED<<"Select Game Mode(1/2)."<< CLOSEUNDERLINE<<cc<<CLOSEUNDERLINE<<endl;
  
    cout << "  \t\t\t\t\t\x1B[94m1. Computer VS Player." << endl;
    cout << "  \t\t\t\t\t2. Player VS Player." << CLOSEUNDERLINE<<endl;
    cout<<"\x1B[93mENTER YOUR CHOICE: "<<CLOSEUNDERLINE<<"\x1B[96m";
     cin >> mode;
    cout<<cc;
    cout<<"\033[0m";
     cout <<green<<"\n\n\n\t\t\t\t\t      Please Wait.";
  cout <<"\n\t\t\t\twhile your desired mode is loading.....";
    progressbar();
    cout<<"\x1B[95m\n\t\t\t\t\t   Successfully Loaded\033[0m";
    getchar();
    getchar();
    switch(mode)
        {
        case 1 :
            computer_vs_player();
            break;
        case 2:
            player_vs_player();
            break;
        default :
            cout << "Please Select Valid Game Mode."<< endl;
            sleep(1);
            exit(0);
            break;
        }
}

void computer_vs_player() {
    string player_name;
    system("clear");
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
            get_computer_choice();
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
   prompt();
}

void get_computer_choice() {
    
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
        //     return board[3];
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
        //     return board[3];
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
        //     return board[6];
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
        int choice_a;
        cin >> choice_a;
        choice_a -- ;
        if(choice_a < 0 || choice_a > 8) {
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
        if(choice_b < 0 || choice_b > 8) {
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
    prompt();
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
{
    
    system("clear");
 
     system("clear");
     system("clear");
     system("clear");
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
  getchar();
prompt();
}
void tc();

void tc()//a basic decent temperature converter
{
    system("clear");
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
int printrndone();
int timerS();
/* 
Atlast source code is displayed
But there is suspense
wait and watch
*/
/*
This will be the second easter egg
the first is a secret about option
which can be seen just after the start screen
and some others are also there including a cheat sheet
*/

/*  In future if someone wants to 
    change the questions please
    do it as directed
*/
int timerO();
int timerB();
void login();
int loading();
int start();
int about();
int cheatcode();
int evaluator();

/*
    one can change options but he/she also has to change 
    the correct options from the conditions
    programmed here else marks won't be counted properly
*/

/*  And an ernest request to everyperson who will view this source code
    PLEASE dont change my name from the secret about menu
    You may change it from the start screen but not from anywhere else
*/

using namespace std;
int A,B,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5,bo1,bo2,bo3,bo4,bo5,bo6,bo7,bo8,r;//As more questions would be added name them as a5 for groupA and b5 for goupB
    //For bonus add bo5,bo6
char p1,o1,p2,o2,p3,o3,o4,p4,o5,p5,o6,p6,o7,p7,o8,p8;

int printans()     // This is the result declaration function
{  system("clear");
    cout<<"Correct Answers:";
    cout<<"\n1.)On which island of France Napoleon was born? : Corsica\n2.)'Mein Kampf' is the autobiography of which political leader? : Adolf Hitler\n3.)Leonardo Da Vinchi was born in which city? : Florence \n4.)Who was the Chineese Emperor when Marco Polo visited China : Kublai Khan\n5.)Who was the President of America during the Civil War? : Abhraham Lincoln\n6.)In which year America got Independence? : 1776\n7.)Which Ottoman Sultan defeat Byzantine Empire and\ncapture Constantinopole city in 1453? : \nMehmed II\n8.)The Organisation 'League of Nations' was formed after the end of __ : \nWorld War I";
    
    getchar();
    evaluator();
    prompt();
    return 0;
}
int printerror1() // To avoid any error in marks counting this section is used
{ 
    system("clear");  
    
     printf("\n");
     printf("\x1B[31m\t\t\t\tThis cheat code is for entertainment only\033[0m\t\t");
     printf("\x1B[34m\nPlease restart the program\033[0m\t\t");

   
    int c77 = std::cin. get();
    
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
                 int c9988 = std::cin.get();
                  int c9989 = std::cin.get();
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
                 int c9977 = std::cin.get();
                  int c9978 = std::cin.get();
                  printerror1();
}
/*
    A request for the viewer of the source code: In this application I have declared certain cheat codes 
    but they are for entertainment purpose only. Don't use them for your own profit

*/

int
scrbrd ()
{
    //Marks a1,b1 10,-5,0 :  bo1:5,0      
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
    int ch22= std::cin.get();
     int ch23 = std::cin.get();
     
    printans();
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
  cout<<"\n7.) Which Ottoman Sultan defeat Byzantine Empire and ";
  cout<<"\nCapture Constantinopole city?";// Question seven 
                                        //To insert new question insert it between the double inverted commas
                                        //Don't delete the \n else all questions and options would appear in one line
  cout<<"\n a.) Mehmed II.";//correct answer
  cout<<"\n b.) Bayezid II.";  
  cout<<"\n c.) Murad II.";
  cout<<"\n d.) Mehmed IV.";
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
 system("clear");
 cout<<"Group: B"<<endl;

 

  cout<<"8.) The organisation 'League of Nations' was founded after";
  cout<<"\nthe end of  ___?"; // Question six
  cout<<"\n a.) Worls War II.";
  cout<<"\n b.) World War I.";//correct answer
  cout<<"\n c.) Crimean war.";
  cout<<"\n d.) Vietnam War.";
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
  cout<<"\n5.) Who was the President of America during the Civil War?";// Question five 
                                        //To insert new question insert it between the double inverted commas
                                        //Don't delete the \n else all questions and options would appear in one line
  cout<<"\n a.) Abhraham Lincoln.";//correct answer
  cout<<"\n b.) Andrew Jackson."; 
  cout<<"\n c.) George Washington.";
  cout<<"\n d.) James Madison.";
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
 system("clear");

 
cout<<"Group: B"<<endl;
  cout<<"\n6.) In which Year America got Independence?"; // Question six
  cout<<"\n a.) 1760.";
  cout<<"\n b.) 1776.";//Correct answer
  cout<<"\n c.) 1777.";
  cout<<"\n d.) 1761.";
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
  cout<<"\n3.) Leonardo De Vinchi was born in the city of _____"; // Question three
  cout<<"\n a.) Rome.";
  cout<<"\n b.) Milan.";
  cout<<"\n c.) Folorence.";
  cout<<"\n d.) Madrid.";
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
   

   cout<<"Group: B";
  cout<<"\n4.) Who was the Chineese Emperor when Marco Polo visted China ?"; // Question four
  cout<<"\n a.) Temur Khan.";
  cout<<"\n b.) Kublai Khan.";//Correct answer
  cout<<"\n c.) Genghis Khan.";
  cout<<"\n d.) Ogedei Khan.";
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
  cout<<"\n1.) On which island of France, Napoleon was born?";// Question One 
  cout<<"\n a.) Saint Helena.";
  cout<<"\n b.) Corsica.";//Answer
  cout<<"\n c.) Elba.";
  cout<<"\n d.) Oleron.";
  timerO();
  char a,b;
  
  
  
 cin>>a;
   switch(a)
    {
        case 'b':
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
                 if(o1=='b')
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
                 if(o1=='b')
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
  cout<<"\n2.) 'Mein Kampf' is the autobiogarphy of which political leader?"; // Question two
  cout<<"\n a.) Joseph Stalin.";
  cout<<"\n b.) Bennito Mussolini.";
  cout<<"\n c.) Winston Churchill.";
  cout<<"\n d.) Adolf Hitler.";
 
  
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
      system("clear");  
    
     printf("\n");
     cout<<UNDERLINE"\x1B[34m\nAbout:\033[0m"<<CLOSEUNDERLINE;
     cout<<" This is quiz app version 10.0 developed by Subhajit Halder";
     printf("\n       This is console based application. \t\t");

      
      cout<<"\x1B[32m\n\n\n\n\n\t\tTo raise a suggestion for the new version please write to subhohalder267@gmail.com\033[0m";
      
      int ch736 = std::cin. get();
         int ch737 = std::cin. get();
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
      cout<<"\nQuiz ver:10.0 is also having it as it is a quiz game.";
      cout<<"\nList of All correct answers.";
   
    cout<<"\nCorrect Answers:";
    cout<<"\n1.) C";
    cout<<"\n2.) A";
    cout<<"\n3.) C";                   
    cout<<"\n4.) D";
    cout<<"\n5.) B";
    cout<<"\n6.) A";
     cout<<"\n7.) C";
    cout<<"\n8.) D";
       int chhh=std::cin.get();
      int c444=std::cin.get();
      printrndone();
     
}


int start()
{
     
    system("clear");
     system("clear");
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
     cout<<"\n\n\tQUIZ MASTER: Tanushree Roy Chowdhury";
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
    return 0;
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
int timerS () {
 // Local variable declaration:
   int a = 10;
  
   // while loop execution
   while( a >=0 ) {
       gotoxy(70,7);
      cout << "TIME UNTIL SHUTDOWN: " << a <<"sec(s)"<<endl;
      sleep(1);
      a--;
      if(a==-1)
      {
        
       
          
 prompt();
          
      }
   }
 
   return 0;
}








void password_change()
{ system("clear");
    cout<<"Enter Following details :";
    string name1,name,password,passnew,password1;
    cout<<"\nUser-ID:";
    cin>>name;
    
    fstream file1;
       file1.open("file.txt");
       file1>>name1;
       if(name1==name)
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
                else
                {
                    
                        int a = 10;
                          cout<<"\nACCESS DENIED";
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
                }
    

       }
       else
       {
           
                        int a = 10;
                          cout<<"\nACCESS DENIED";
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
       }
  
}








void prompt()
{
    system("clear");
    
    system("clear");
    cout<<red<<bold<<UNDERLINE;
    cout<<"\nOperating Environment ver:2.01";
    cout<<cc;
    cout<<blue<<bold;
    cout<<"\nType help to get list of commands";
    cout<<cc;
    while(true)
    {
       
        if(ins==9)
        {
            cout<<"\nOnly available command is install and exit";
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
                  cout<<"\nI see you trying to LogIn without a password. But access denied.";
                }
            }
        }
        else
        {
                cout<<"\nCommand->";
           string command;
            cin>>command;
            if(command=="Help"||command=="HELP"||command=="help")
            {
                cout<<"\n\tType:";
                cout<<"\n\tTicTacToe";
                cout<<"\n\tCalculator";
                cout<<"\n\tQuiz";
                cout<<"\n\tTemp_Conv";
                cout<<"\n\teqn_solve";
                cout<<" to open the above applications(if installed).";
                cout<<"\n\tTo install an app from above  list type inst_'with app name'";
                
                
            }
            else if (command=="TicTacToe"||command=="tictactoe"||command=="TICTACTOE")
            {
                
                    fstream file;
                string word, t, q, filename;
                    bs=1;
                filename = "file3.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
            {
              fstream file;
                string word, t, q, filename;
                    bs=2;
                filename = "file6.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
                
                    fstream file;
                string word, t, q, filename;
          
                filename = "TC.txt";
                    bs=3;
                file.open(filename.c_str());
                if (file.good()) 
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
                    fstream file;
                string word, t, q, filename;
                v=1;
                bs=1;
                filename = "file3.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
                {
                cout<<"\nAlready installed";
                }
                else 
                {
                 bootscreen();
                    installer();
                }
                
            }
            else if(command=="inst_Temp_Conv")
            {
                    fstream file;
                string word, t, q, filename;
                v=3;
                bs=3;
                filename = "TC.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
                  fstream file;
                string word, t, q, filename;
          
                filename = "Calc.txt";
                bs=4;          
                v=4;     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
                  fstream file;
                string word, t, q, filename;
                v=2;
                bs=2;
                filename = "file6.txt";
          
                     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
                  fstream file;
                string word, t, q, filename;
          
                filename = "Calc.txt";
                bs=4;
                file.open(filename.c_str());
                if (file.good()) 
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
                  fstream file;
                string word, t, q, filename;
          
                filename = "solve.txt";
                bs=6;
                file.open(filename.c_str());
                if (file.good()) 
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
                  fstream file;
                string word, t, q, filename;
                v=6;
                bs=6;
                filename = "solve.txt";     // opening file
                file.open(filename.c_str());
                if (file.good()) 
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
system("clear");
 cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";
  char c;
  cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
    cout<<"\nDo you want to directly install this application or you want to use it once before installation?(y/n):";
  cin>>c;
  if(c=='y')
    {
        system("clear");
        cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";
        cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
        cout <<"\n\n\n\t\t\t\t\t        Please_Wait.";
        cout<<"\n\t\t\t\t\t     While setup is";
        cout <<"\n\n\t\t\t\t\t        Loading.....";
   pBar bar;
    //Main loop:
    for (int i = 0; i < 100; i++) 
        { //This can be any loop, but I just made this as an example
            //Update pBar:
            bar.update(1); //How much new progress was added (only needed when new progress was added)
            //Print pBar:
            bar.print(); //This should be called more frequently than it is in this demo (you'll have to see what looks best for your program)
            sleep(1);
        }
        cout << endl;
    cout<<"\n\t\t\t\t\t  Successfully Loaded";
    cout<<" \n\n\n\t\t\t\t      <<Press ENTER to Continue>>";
getchar();
getchar();
system("clear");
   system("clear");
 cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";
        cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
  cout<<UNDERLINE<<red<<bold<<"\n\nWhile the game is loading let us know its working:"<<CLOSEUNDERLINE;
   cout<<yellow<<"\n\nAt first type help command at the prompt.";
   cout<<"\nYou will be getting a list of available commands use it  "<<CLOSEUNDERLINE;
   cout<<purple<<"\t\tDesingned for ease"<<cc;
   cout<<yellow<<"\nto install your desired program"<<cc;
   cout<<purple<<"\t\t\t\t\t\tFor ease in using "<<cc;
   cout<<yellow<<"\nEnjoy using it!!!"<<cc;
    cout<<purple<<"\t\t\t\t\t\t\tsoftwares"<<cc;
    cout <<cyan<<"\n\n\n\t\t\t\t\t      Please Wait.";
  cout <<"\n\t\t\t\t\t      Loading....."<<cc;
  cout<<green<<"\t\tDEVELOPER:"<<RED<<" Subhajit Halder";
 progressbar();
    cout<<"\x1B[34m\n\t\t\t\t\t   Successfully Loaded\033[0m";//blue color
 sleep(5);
   fstream f1,f2,f3;
 
   string id,pass;
   system("clear");
     system("clear");
   cout<<UNDERLINE<<red<<"\nPLease create a user id password for safety reasons:"<<cc;
         cout<<"\nUser-Id:";
       cin>>id;
          cout<<"\nDo you want to create a password(y/n):";
          cin>>c;
          if (c=='y')
          {   f2.open("file2.txt",ios::out);
          f1.open("file.txt",ios::out);
f3.open("PROMPT.txt",ios::out);
           cout<<"Enter password:";
           cin>>pass;
           f1<<id;
           f2<<pass;
           f1.close();
           f2.close();
           getchar();
            system("clear");
            cout<<"Installed";
            getchar();
          }
          else
          {
            getchar();
            system("clear");
            cout<<"Installed";
             f1<<id;
           f1.close();
            getchar();
          }
          
          Improvements();
    }
    else if(c=='n')
      {  cout <<"\t\t\t\t\t   "<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE;
        cout <<"\n\t\t\t\t\t      "<<"  Version:2.01";

        cout << "\n\t\t\t\t\t  "<<"  (Evaluation_Build)";
      cout<<"\nAfter completeion of your trial the program will stop. You have to restart the setup to continue.";
      ins = 9;
        prompt();
      }
}
  
  








