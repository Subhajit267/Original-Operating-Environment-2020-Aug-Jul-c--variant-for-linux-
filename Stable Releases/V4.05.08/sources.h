//This is place of function prototype
void quad_eqn_solve();
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
//Complete file embedded with latest layout
//A golbal variable; (reg_values)
int state;
string a,filename,name1,password1,password;
//gotoxy function
void gotoxy(int x,int y)// declaring the cursor position
{
    printf("%c[%d;%df",0x1B,y,x);
}
//Progress_BAR
void progressbar(){ 
	std::srand(time(NULL)); //seed random 
	for(int progress=0;progress!=100;progress+=std::rand()%20){
	    if(state==1)
	    {gotoxy(55,22);}
	    else
	    {gotoxy(55,22);}//increment progress randomly 
		//Delete the line below and change for loop condition to 'progress<=100' and put something meaningful in for loop progress increment in implementation. 
		if(progress>25) progress=25; 
		std::cout<<"\x1B[32m[\033[0m\x1B[34m"; 
		for(int i=0;i<25;i++) 
			if(i<progress) 
				std::cout<<'='; 
			else if(i==progress) 
				std::cout<<'>'; 
			else 
				std::cout<<' '; 
		std::cout<<"\033[0m\x1B[32m]\033[0m "; 
		std::cout.flush(); 
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); //sleep 
		//Delete this line as well in implementation 
		if(progress==25) break; 
	} 
	std::cout<<std::endl; 
	gotoxy(55,22);
	cout<<"                                                        ";
}
//This is place of function prototype

//Source Viewer function
int source()
{     char c;  
    FILE *fp = fopen(__FILE__, "r"); 
    do
    {   c = fgetc(fp); 
        putchar(c); 
    } 
    while (c != EOF); 
    fclose(fp); 
}

//Improvements and Bugs 
void Improvements()
{//layout done
    system("clear");
    gotoxy(1,2);
    layout();
    gotoxy(5,7);
    cout<<bold<<RED<<UNDERLINE<<"New Improvments and Bug Fixes:"<<cc;
    gotoxy(5,9);
    cout<<bold<<blue<<"i.)Change in programming";
    gotoxy(5,10);
    cout<<bold<<yellow<<"ii.)New app Quadratic Eqn solver";
    gotoxy(5,11);
    cout<<bold<<blue<<"iii.)Quad Eqn solver can determine nature of roots";
    gotoxy(5,12);
    cout<<bold<<yellow<<"iv.)Added trial for quiz in registry editor by changing registry values.";
    gotoxy(5,13);
    cout<<bold<<blue<<"v.)Introduction of a brand new UI";
    gotoxy(5,14);
    cout<<bold<<red<<"vi.)Introduction of settings application";
    gotoxy(5,15);
    cout<<bold<<yellow<<"vii.)Parts of Registry Editor are accessible by normal user. Command :  registryeditor.";
    gotoxy(5,16);
    cout<<bold<<blue<<"viii.)Now you can change your User-ID";
    gotoxy(5,17);
     cout<<bold<<yellow<<"iX.)Password can be removed later via the settings application.";
     gotoxy(5,18);
     cout<<bold<<blue<<"x.)Option for system restore by reinstallation to solve several errors.";
        gotoxy(5,19);
     cout<<bold<<yellow<<"xi.)Added support for Kelvin in Temperature Converter.";
      gotoxy(5,20);
     cout<<bold<<blue<<"xii.)One can directly move into the prompt menu form registry editor.";
     gotoxy(5,21);
    cout<<bold<<green<<"Next version comming with more features"<<cc;
    getchar();
}

//Latest Login function
void login()
{     fstream file;//layout done
logo();
                 filename  = "file.txt";      // opening file
            file.open(filename.c_str());
            if (file.good()) 
            {gotoxy(4,9);reg_status=1;
                cout<<"  To begin press enter or type password(if you have created a User-ID).";
                  
                  gotoxy(40,12);
                        cout<<"User-ID:";
                         fstream file1,file;
                        file1.open("file.txt");
                        file1>>name1;
                        cout<<" "<<name1;
                        filename = "file2.txt";
                   file.open(filename.c_str());
                    if (file.good()) 
                    { fstream file2;
                        file2.open("file2.txt");
                        file2>>password1;
                        if(password1=="0")
                        { getchar();
                    prompt();
                        }
                        else{       gotoxy(40,13);
                             cout<<"Password:";
                           cout<<invisible;
                           cin>>password;
                           cout<<cc;
                               
                                if(password1==password)
                                {
                                    prompt();
                                }
                                else if(password=="registryeditor")
                                {
                                    reg_edit();
                                }
                                else
                                {
                                        timerS();
                                }
                        }
                    }
                    
                    else 
                    {  getchar();
                    prompt();
                       
                       
                    }
            }
            else 
            {gotoxy(5,9);
            reg_status=1;
               cout<<" /* To just test the program (*with limited features) type GUEST in the place of USER NAME */ ";
              gotoxy(40,13);
                cout<<"USER-ID:";
                 cout<<" \x1B[36m ";
                 cin>>a;
                   if(a=="GUEST"||a =="Guest")
                   {
                        ins = 9;
                        reg_status=0;
                        prompt();
                   }
                   else if(a=="guess_it")
                   {
                       source();
                   }
                   else if(a=="registryeditor")
                   {
                       reg_edit();
                   }
                 else  {
                           timerS();
                       }
            }
}

//The newest layout
void layout(){
    gotoxy(1,1);
system("clear");
cout<<cc;
gotoxy(1,2);
    cout<<"  "<<border"                                                                                                                                  "<<cc<<endl;
     cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t\t\t  "<<RED<<bold<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE<<"                                                    "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t                    "<<blue<<bold<<UNDERLINE<<"  Version:4.05  "<<CLOSEUNDERLINE<<cc<<cc<<cc<<"                                                       "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                        "<<yellow<<bold"(EVALUATION_BUILD)"<<cc<< "                                                      "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border"                                                                                                                                  "<<cc<<endl;
    gotoxy(1,1);
}

//User Creation menu
void add_user()
{system("clear");
     fstream f1,f2,f3;
   string id,c,pass;
   system("clear");layout();     
     gotoxy(5,10);
     cout<<UNDERLINE<<RED<<bold<<"Welcome to USER-ID Password Creation Wizard Ver: 1.7.9"<<cc;
     gotoxy(5,11);
     cout<<"FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER";
     gotoxy(5,12);
   cout<<yellow<<"PLease create a user id password for safety reasons:"<<cc;
   gotoxy(5,13);
         cout<<"User-Id:";
       cin>>id;
       gotoxy(5,14);
          cout<<"Do you want to create a password(y/n):";
          cin>>c;
          if (c=="y")
          { 
          f1.open("file.txt",ios::out);
          gotoxy(5,15);
           cout<<"Enter password:";
           cin>>pass;
           if(pass=="0")
           {gotoxy(5,16);
                               cout<<RED<<bold<<"The password cannot be 0"<<cc<<cc;
                               cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
                               gotoxy(5,17);
                               cout<<blue<<bold<<"Press Enter to continue by recreating user.";
                               getchar();getchar();add_user();}
           
           else{f1<<id;  f2.open("file2.txt",ios::out);
           f2<<pass;
           f1.close();
           f2.close();}
           
          }
          else
          {pass="0";
            f1.open("file.txt",ios::out);
             f1<<id;
           f1.close();
           f2.open("file2.txt",ios::out);
           f2<<pass;
           f1.close();
           f2.close();
          }
   gotoxy(5,16);
   cout<<RED<<bold<<"You are Successfull in creating a user."<<cc;
    getchar();
    getchar();
}
//Installer for setting Reg_Values
void install()
{
    fstream t,q,tc,c,eqn,qd;
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
          qd.open("quad_solve.txt",ios::out);
          qd<<reg;
          qd.close();
}