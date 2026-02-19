//This is place of function prototype(some functions)
void quad_eqn_solve();//Quadratic Eqn solver
int printrndone();
int timerS();//Shutdown timer
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
				std::cout<<'-'; 
			else if(i==progress) 
				std::cout<<'_'; 
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
int source()//Source Viewer function
{     char c;  
    FILE *fp = fopen(__FILE__, "r"); 
    do
    {   c = fgetc(fp); 
        putchar(c); 
    } 
    while (c != EOF); 
    fclose(fp); 
    return 0;
}
void Improvements()//Improvements and Bugs 
{   system("clear");    gotoxy(1,2);    layout();
    gotoxy(5,7);     cout<<bold<<RED<<UNDERLINE<<"New Improvments and Bug Fixes:"<<cc;
    gotoxy(5,9);     cout<<bold<<blue<<"i.)Change in programming";
    gotoxy(5,10);    cout<<bold<<yellow<<"ii.)New app Quadratic Eqn solver";
    gotoxy(5,11);    cout<<bold<<blue<<"iii.)Quad Eqn solver can determine nature of roots";
    gotoxy(5,12);    cout<<bold<<yellow<<"iv.)Added trial for quiz in registry editor by changing registry values.";
    gotoxy(5,13);    cout<<bold<<blue<<"v.)Introduction of a brand new UI";
    gotoxy(5,14);    cout<<bold<<red<<"vi.)Introduction of settings application";
    gotoxy(5,15);    cout<<bold<<yellow<<"vii.)Parts of Registry Editor are accessible by normal user. Command :  registryeditor.";
    gotoxy(5,16);    cout<<bold<<blue<<"viii.)Now you can change your User-ID";
    gotoxy(5,17);    cout<<bold<<yellow<<"iX.)Password can be removed later via the settings application.";
    gotoxy(5,18);    cout<<bold<<blue<<"x.)Option for system restore by reinstallation to solve several errors.";
    gotoxy(5,19);    cout<<bold<<yellow<<"xi.)Added support for Kelvin in Temperature Converter.";
    gotoxy(5,20);    cout<<bold<<blue<<"xii.)One can directly move into the prompt menu form registry editor.";
    gotoxy(5,21);    cout<<bold<<green<<"Next version comming with more features"<<cc;
    getchar();
}
void login() //Latest Login function
{           fstream file;//layout done
			logo();
            filename  = "file.txt";      // opening file
            file.open(filename.c_str());
            if (file.good()) //If User Exists
            {gotoxy(4,9);reg_status=1;
                cout<<"  To begin press enter or type password(if you have created a User-ID).";                  
                  gotoxy(40,12);        cout<<"User-ID:";
                         fstream file1,file;   file1.open("file.txt");
                        file1>>name1;            cout<<" "<<name1;                  
                   fstream file2;
                        file2.open("file2.txt");
                        file2>>password1;
                        if(password1=="0")//if password is removed
                        { getchar();
                    prompt();
                        }
                        else{       gotoxy(40,13);  cout<<"Password:";  cout<<invisible;
                           cin>>password;             cout<<cc;                               
                                if(password1==password)                          
                                    prompt();
                                else if(password=="registryeditor")
                                   reg_edit();
                                   else if(password=="guess_it")
                                   source();
                                else
                                    timerS();
                            }
			}
            else //For Guest User
            {gotoxy(5,9);  reg_status=1;
               cout<<" /* To just test the program (*with limited features) press enter */ ";
              gotoxy(40,13);   cout<<"USER-ID: GUEST";   cout<<" \x1B[36m ";
              getchar();
              getchar();
              system("clear");
                    ins = 9;
                        reg_status=0;
                        prompt();
            }
}
void layout()//main looks the floating form design
{ gotoxy(1,1);system("clear");cout<<cc;gotoxy(1,2);
    cout<<"  "<<border"                                                                                                                                  "<<cc<<endl;
     cout<<"  "<<border" "<<cc"                                                                                                                                "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t\t\t  "<<RED<<bold<<UNDERLINE<< "Operating Environment"<<CLOSEUNDERLINE<<"                                                    "<<border" "<<cc<<endl;
    cout<<"  "<<border" "<<cc"  \t\t\t\t\t                    "<<blue<<bold<<UNDERLINE<<"  Version:4.12  "<<CLOSEUNDERLINE<<cc<<cc<<cc<<"                                                       "<<border" "<<cc<<endl;
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
void add_user()//User Creation menu
{system("clear");     fstream f1,f2,f3;   string id,c,pass;
   system("clear");layout();     
     gotoxy(5,10);     cout<<UNDERLINE<<RED<<bold<<"Welcome to USER-ID Password Creation Wizard Ver: 1.7.9"<<cc;
     gotoxy(5,11);     cout<<"FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER";
     gotoxy(5,12);     cout<<yellow<<"PLease create a user id password for safety reasons:"<<cc;
   gotoxy(5,13);       cout<<"User-Id:";
       cin>>id;       gotoxy(5,14);          cout<<"Do you want to create a password(y/n):";
          cin>>c;
          if (c=="y")//If password is to be created
          { 
          f1.open("file.txt",ios::out);
          gotoxy(5,15);
           cout<<"Enter password:";
           cin>>pass;
							if(pass=="0")//If entered password is 0
							{  gotoxy(5,16);
                               cout<<RED<<bold<<"The password cannot be 0"<<cc<<cc;
                               cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
                               gotoxy(5,17);
                               cout<<blue<<bold<<"Press Enter to continue by recreating user.";
                               getchar();getchar();add_user();}
           
							   else//Password is registered in new file
							   {f1<<id;  f2.open("file2.txt",ios::out);
							   f2<<pass;
							   f1.close();
							   f2.close();}          
		  }
          else
          {pass="0";//Storing password as zero in a file
            f1.open("file.txt",ios::out);
             f1<<id;
           f1.close();
           f2.open("file2.txt",ios::out);
           f2<<pass;
           f1.close();
           f2.close();
          }
   gotoxy(5,16);   cout<<RED<<bold<<"You are Successfull in creating a user."<<cc;    getchar();    getchar();
}
void install()//Installer for setting Reg_Values
{
    fstream t,q,tc,c,eqn,qd,at;
    t.open("TicTacToe.txt",ios::out);          t<<reg;          t.close();
          q.open("Quiz.txt",ios::out);          q<<reg;          q.close();
          tc.open("TC.txt",ios::out);          tc<<reg;          tc.close();
          c.open("Calc.txt",ios::out);          c<<reg;          c.close();
          eqn.open("solve.txt",ios::out);         eqn<<reg;          eqn.close();
          qd.open("quad_solve.txt",ios::out);          qd<<reg;          qd.close();
          at.open("quad_solve.txt",ios::out);          at<<reg;          at.close();
}
void color_change()
{
    system("clear");gotoxy(1,1);    layout();    gotoxy(5,8);
    cout<<UNDERLINE<<RED<<bold"Welcome to background border color changer wizard."<<cc;  gotoxy(5,9);
    cout<<yellow<<bold"Available options:"<<cc;  gotoxy(5,10);
    cout<<" -------------------------------------------"; gotoxy(5,11);  
    cout<<"|    "<<green<<bold"COLOR_NAME"<<cc"       |        "<<green<<bold"SAMPLE"<<cc"       |"  ;     gotoxy(5,12);                             
    cout<<"|"<<bold<<blue<<" 1.) Red            "<<cc<<" |          "<<B1<<"  "<<cc<<"         |";  gotoxy(5,13);
    cout<<"|"<<bold<<blue<<" 2.) Green          "<<cc<<" |          "<<B2<<"  "<<cc<<"         |";  gotoxy(5,14);
    cout<<"|"<<bold<<blue<<" 3.) Yellow         "<<cc<<" |          "<<B3<<"  "<<cc<<"         |";  gotoxy(5,15);
    cout<<"|"<<bold<<blue<<" 4.) Blue           "<<cc<<" |          "<<B4<<"  "<<cc<<"         |";  gotoxy(5,16);
    cout<<"|"<<bold<<blue<<" 5.) Purple         "<<cc<<" |          "<<B5<<"  "<<cc<<cc<<"         |";  gotoxy(5,17);
    cout<<"|"<<bold<<blue<<" 6.) Cyan           "<<cc<<" |          "<<B6<<"  "<<cc<<cc<<"         |";  gotoxy(5,18);
    cout<<"|"<<bold<<blue<<" 7.) Light grey     "<<cc<<" |          "<<B7<<"  "<<cc<<cc<<"         |";  gotoxy(5,19);
    cout<<"|"<<bold<<blue<<" 8.) Grey           "<<cc<<" |          "<<B8<<"  "<<cc<<cc<<"         |";  gotoxy(5,20);
    cout<<"|"<<bold<<blue<<" 9.) Light Red      "<<cc<<" |          "<<B9<<"  "<<cc<<"         |";  gotoxy(5,21);
    cout<<"|"<<bold<<blue<<" 10.) Light Green   "<<cc<<" |          "<<B10<<"  "<<cc<<"         |";  gotoxy(5,22);
    cout<<"|"<<bold<<blue<<" 11.) Light Yellow  "<<cc<<" |          "<<B11<<"  "<<cc<<"         |";  gotoxy(5,23);
    cout<<"|"<<bold<<blue<<" 12.) Light Blue    "<<cc<<" |          "<<B12<<"  "<<cc<<cc<<"         |";  gotoxy(5,24);
    cout<<"|"<<bold<<blue<<" 13.) Light Purple  "<<cc<<" |          "<<B13<<"  "<<cc<<cc<<"         |";  gotoxy(5,25);
    cout<<"|"<<bold<<blue<<" 14.) Light Cyan    "<<cc<<" |          "<<B14<<"  "<<cc<<cc<<"         |";  gotoxy(5,26);
    cout<<"|"<<bold<<blue<<" 15.) White         "<<cc<<" |          "<<B15<<"  "<<cc<<"         |";gotoxy(5,27);
    cout<<"|"<<bold<<blue<<" 16.) Blank         "<<cc<<" |           "<<cc<<"          |";  gotoxy(5,28);  
     cout<<" -------------------------------------------"; 
    gotoxy(5,29);    cout<<purple<<bold"Enter choice (To exit press e): ";
    string colorr; 
    cin>>colorr;
	if(colorr=="1"||colorr=="2"||colorr=="3"||colorr=="4"||colorr=="5"||colorr=="6"||colorr=="7"||colorr=="8"||colorr=="9"||colorr=="10"||colorr=="11"||colorr=="12"||colorr=="13"||colorr=="14"||colorr=="15")
	{			fstream color;
	            color.open("looks.h",ios::out); 
				if(colorr=="1")//Red
				  {color<<"#define border \"\\x1B[41m\"";  }
				else if(colorr=="2")//Green
				  {color<<"#define border \"\\x1B[42m\""; }
				else if(colorr=="3")//Yellow
				  { color<<"#define border \"\\x1B[43m\"";  }
				else if(colorr=="4")//Blue
				  { color<<"#define border \"\\x1B[44m\""; }    
				else if(colorr=="5")//Purple
				  { color<<"#define border \"\\x1B[45m\"";  }   
				else if(colorr=="6")//Aqua
				  { color<<"#define border \"\\x1B[46m\"";  }   
			    else if(colorr=="7")//Light Grey
				  { color<<"#define border \"\\x1B[47m\"";   }  
				else if(colorr=="8")//Grey
				  { color<<"#define border \"\\x1B[100m\"";	}
				else if(colorr=="9")//Light Red
				  { color<<"#define border \"\\x1B[101m\"";	}	
				else if(colorr=="10") //Light Green
				  { color<<"#define border \"\\x1B[102m\""; }      
				else if(colorr=="11")//Light Yellow
				  { color<<"#define border \"\\x1B[103m\"";  }  
				else if(colorr=="12")//Light Blue
				  { color<<"#define border \"\\x1B[104m\"";      }
				else if(colorr=="13")//Light Purple
				  { color<<"#define border \"\\x1B[105m\"";    }    
				else if(colorr=="14")//Cyan
				  { color<<"#define border \"\\x1B[106m\"";      }  
			    else if(colorr=="15")//WHite
				  { color<<"#define border \"\\x1B[107m\"";  }    
				else if(colorr=="16")//Blank
				  { color<<"#define border \"\\x1B[99m\"";  }  
			   
				color.close(); 
				    cout<<"\a\a\a\a"<<flush;			gotoxy(30,10);                system("clear");
							cout<<RED<<bold" Program is shuttng Down to save the changes. Restart to to see the effect!!!"<<cc;
							sleep(1);                exit(0);
	}
    else if(colorr=="e")
        settings();
    else
	{gotoxy(5,30);
        cout<<"No command.";
        getchar();getchar();
        color_change();
    }    
}
void USER_ACCOUNTS()
{
    system("clear");gotoxy(1,1);    layout();gotoxy(5,8);    cout<<UNDERLINE<<red<<bold"Welcome to User Account Control Panel:"<<cc;
	gotoxy(5,9);    cout<<yellow<<bold"Pick a task: ";
	gotoxy(5,10);    cout<<green<<bold"1.) Add /Remove /Create Password for your accounts";
	gotoxy(5,11);    cout<<"2.) Change Your User_ID.";
	gotoxy(5,12);    cout<<"3.) EXIT.";
	gotoxy(5,13);    cout<<bold<<blue"Enter choice(1-3): "<<cc;
    cin>>choice;
    if(choice=="1")
        password_change();
    else if(choice=="2")
            userid_change();
    else if(choice=="3")
        settings();
    else{
        gotoxy(5,25);cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
        getchar();getchar();USER_ACCOUNTS();} 
	getchar();getchar();USER_ACCOUNTS();
}
void RESET_AND_RESTORE()
{
    system("clear");gotoxy(1,1);    layout();gotoxy(5,8);    cout<<UNDERLINE<<red<<bold"Welcome to Reset and Restore Panel:"<<cc;
	gotoxy(5,9);    cout<<yellow<<bold"Pick a task: ";
	gotoxy(5,10);    cout<<blue<<bold"1.) Reset your applications";
	gotoxy(5,11);    cout<<"2.) Restore your system by re-installing it.";
	gotoxy(5,12);    cout<<"3.) EXIT.";
	gotoxy(5,13);    cout<<red<<bold"Warning!! Any of the above task(command) will reset all your applications thus delete /alter data. ";
	gotoxy(5,14);    cout<<green<<bold"Do you want to continue(y/n)?";
    cin>>a;
	if(a=="y"||a=="Y")
	{	gotoxy(5,15);
		cout<<green<<bold"Enter choice(1-3): "<<cc;
		cin>>choice;
		if(choice=="1")
		{        reg=0;
			install();
		}
		else if(choice=="2")
				IP();
		else if(choice=="3")
				settings();    
		else{
			gotoxy(5,25);cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
			getchar();getchar();RESET_AND_RESTORE();
		} getchar();getchar();RESET_AND_RESTORE();
    }
    else 
		settings();
}
void PERSONALIZATION()
{       system("clear");gotoxy(1,1);    layout();
		gotoxy(5,8);    cout<<red<<UNDERLINE<<bold"Welcome to Personalization Panel:"<<cc;
		gotoxy(5,9);    cout<<yellow<<bold"Pick a task: ";
		gotoxy(5,10);    cout<<green<<bold"1.) Change your border color.";
		gotoxy(5,11);    cout<<"2.) EXIT.";
		gotoxy(5,12);    cout<<blue<<bold"Enter choice(1-2): "<<cc;
		cin>>choice;
		if(choice=="1")
			color_change();		
		else if(choice=="2")
					settings();		
		else{
			gotoxy(5,25);cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
			getchar();getchar();PERSONALIZATION();
		    } 
	getchar();getchar();PERSONALIZATION();
}