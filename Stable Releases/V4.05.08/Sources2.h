//New layout done for the file
//installer for all programs
void installer()
{ cout<<green<<bold;
    reg=1;//The registry values which registers the apps as installed or not
      gotoxy(1,1); layout();
      if(v==1 && bs==1)//at differnt states which title will be shown tar jonno
      { gotoxy(20,8);
        cout <<UNDERLINE<< "\t\t\t\t\t\tTIC TAC TOE"<<CLOSEUNDERLINE;//String values depending on reg_calls
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:4.0";
      }
      else if(v==2 && bs==2)
      {gotoxy(20,8);
          cout <<UNDERLINE<< "\t\t\t\t\t\tQUIZ__APP"<<CLOSEUNDERLINE;
          gotoxy(20,9);
            cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:10.8";
      }
      else if(v==3 && bs==3)
      {gotoxy(20,8);
            cout <<UNDERLINE<< "\t\t\t\t\t\tTEMP_CONV"<<CLOSEUNDERLINE;
            gotoxy(20,9);
            cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:4.05";
      }
      else if(v==4 && bs==4)
      {gotoxy(20,8);
        cout <<UNDERLINE<< "\t\t\t\t\t\tCALCULATOR"<<CLOSEUNDERLINE;
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:3.05";
      }
      else if(v==6 && bs==6)
      { gotoxy(46,8);
        cout <<UNDERLINE<< "Pair_of_eqn_solve"<<CLOSEUNDERLINE;
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:4.05";
      }
      else if(v==7 && bs==7)
      { gotoxy(60,8);
        cout <<UNDERLINE<< "Quadratic_eqn_solve"<<CLOSEUNDERLINE;
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:1.05";
      }
gotoxy(20,10);
cout <<"\t\t\t\t\t        Please_Wait.";//Ei gulo common strings
gotoxy(20,11);
cout<<"\t\t\t\t\t     While setup is";
gotoxy(20,12);
cout<<"\t\t\t\t\t        Installing..."<<cc;
 sleep(1);
      if(v==1 && bs==1)
      {
       activation(); //activation for tictactoe
      }
      else if(v==2 && bs==2)
      {
         activation();  //activation for quiz
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
      
      else if(v==7 && bs==7)
      {
         fstream f;
         f.open("quad_solve.txt",ios::out);
         f<<reg;
         f.close();
      }
    sleep(2);
}
void activation()//Common activation method for tictactoe and Quiz
{gotoxy(1,1);
layout();
    gotoxy(5,8);
reg=1;
cout<<"Enter product key(10 charcters):";
    char key[10];
    cin>>key;
if(v==1)
{
 if(key[6]+key[0]==key[9]+key[5])
       {gotoxy(5,10);
       cout<<"Verified";
       getchar();getchar();
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
   {gotoxy(5,10);
      cout<<"Invalid key";
      getchar();getchar();
      prompt();
   }
}
else if(v==2)
{
     if(key[7]+key[8]==key[2]+key[9])
   {gotoxy(5,10);
       cout<<"Verified";
       getchar();getchar();
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
   {gotoxy(5,10);
      cout<<"Invalid key";
      getchar();getchar();
      prompt();
   }
}
}

//Bootscreens
void bootscreen()
  {  system("clear");
  gotoxy(1,1);
 
  layout();
  cout<<green<<bold;
      if(bs==1)
      {gotoxy(20,8);
        cout <<"\t\t\t\t\t      "<<UNDERLINE<< "TIC TAC TOE"<<CLOSEUNDERLINE;//String values depending on reg_calls
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t  "<<"    Version:4.0";
        state=0;
      }
      else if(bs==0)
      { 
          layout();
            logo();
          state=1;
      }
      else if(bs==2)
      {gotoxy(20,8);
          cout <<"    "<<"\t\t\t\t\t   "<<"   "<<UNDERLINE<< "QUIZ__APP"<<CLOSEUNDERLINE;
          gotoxy(20,9);
            cout <<yellow<<bold<<"\t\t\t\t\t   "<<"  Version:10.8";
            state=0;
      }
      else if(bs==3)
      {gotoxy(20,8);
            cout <<UNDERLINE<< "\t\t\t\t\t\tTEMP_CONV"<<CLOSEUNDERLINE;
            gotoxy(20,9);
            cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:4.05";
            state=0;
      }
      else if(bs==4)
      {gotoxy(20,8);
        cout <<UNDERLINE<< "\t\t\t\t\t\tCALCULATOR"<<CLOSEUNDERLINE;
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:3.05";
        state=0;
      }
      else if(bs==6)
      {gotoxy(60,8);
        cout <<UNDERLINE<< "Pair_of_eqn_solve"<<CLOSEUNDERLINE;
        gotoxy(17,9);
        cout <<yellow<<bold<<"\t\t\t\t\t  "<<"   Version:4.05";
        state=0;
      }
       else if(bs==7)
      { gotoxy(60,8);
        cout <<UNDERLINE<< "Quadratic_eqn_solve"<<CLOSEUNDERLINE;
        gotoxy(20,9);
        cout <<yellow<<bold<<"\t\t\t\t\t      "<<"  Version:1.05";
      }
      cout<<cc<<cc;
      gotoxy(17,18);
cout <<cyan<<bold<<"\t\t\t\t\t     Please_Wait.";
gotoxy(17,19);
cout<<yellow<<bold"\t\t\t\t\t     LOADING......"<<cc;
    progressbar();
    gotoxy(53,16);
cout<<"                                                         ";
}

 int printerror() // To avoid any error in marks counting this section is used
{gotoxy(1,1);
layout();
    cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
    gotoxy(5,10);
     printf("\x1B[31m\t\t\t\tAn Unexpected error occured due to invalid input\033[0m\t\t");
      gotoxy(5,11);
     printf("\x1B[34m\nThe program is restarting. Press Enter\033[0m\t\t");
    getchar();
    getchar();
   prompt();
}

void logo()
{   gotoxy(5,10);
    cout<<green<<bold<<" ----------------------"<<cc<<cc;
    gotoxy(5,11);
    cout<<green<<bold<<"|    "<<yellow" ======     ====  "<<green"|"<<cc<<cc;
    gotoxy(5,12);
    cout<<green<<bold<<"|   "<<yellow"/      /   /       "<<green"|"<<cc<<cc;
    gotoxy(5,13);
    cout<<green<<bold<<"|  "<<yellow"/      /    ====    "<<green<<"|"<<cc<<cc;
    gotoxy(5,14);
    cout<<green<<bold<<"| "<<red"/      /   /         "<<green"|"<<cc<<cc;
    gotoxy(5,15);
    cout<<green<<bold<<"|"<<red" ======     =====     "<<green"|"<<cc<<cc;
    gotoxy(5,16);
    cout<<green<<bold<<" ----------------------"<<cc<<cc;
}

//password_change wizard
void password_change()
{ gotoxy(1,1);layout();
gotoxy(5,7);
cout<<red<<bold<<UNDERLINE<<"Welcome to password changing wizard Ver 1.7.9"<<cc<<cc;
gotoxy(5,8);
    cout<<yellow<<"Enter Following details :"<<cc;
    string name1,name,password,password1;
    string passnew;
    gotoxy(5,9);
    cout<<"User-ID:";
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
                {gotoxy(5,10);char pc;
                    cout<<"Do you wish to keep a Password? ";cin>>pc;
                    if(pc=='y'){gotoxy(5,11);
                   cout<<"Enter your last Password(if no Password was applied type 0):";
                   cout<<invisible;
                   cin>>password;
                   cout<<cc;
                    fstream file2;
                    file2.open("file2.txt");
                    file2>>password1;
                        if(password1==password)
                        {gotoxy(5,12);
                            cout<<"Enter new password:";
                            cin>>passnew;
                            getchar();
                            if(passnew=="0")
                            {gotoxy(5,16);
                               cout<<RED<<bold<<"The password cannot be 0"<<cc<<cc;
                               cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
                               gotoxy(5,17);
                               cout<<blue<<bold<<"Press Enter to restart password_change wizard.";
                               getchar();getchar();
                               password_change();
                            
                            }
                             else 
                           {
                               fstream f1;
                            f1.open("file2.txt",ios::out);
                             f1<<passnew;
                             f1.close();
                             gotoxy(5,13);
                             cout<<"Your password has been changed";
                             getchar();  system("clear");
                           }
                            
                        }
                        else //intruder
                        {
                            timerS();
                        }
                    }
                    else
                    { gotoxy(5,13);
                        cout<<"Your password has been removed";  getchar();  getchar();
                        fstream file;
                        file.open("file2.txt",ios::out);
                        file<<"0";
                        file.close();
                    }
                }
                else//if password doesn't exists
                {
                fstream f2;
                string pass;
                f2.open("file2.txt",ios::out);gotoxy(5,10);
                cout<<"Enter password:";
                cin>>pass;
                f2<<pass;
                f2.close();gotoxy(5,12);
                 cout<<"Your password has been changed";
                getchar();
                }
           settings();
        }
       else//intruder
       {
           timerS();
       }
}

//Shutdown timer
int timerS () 
{
 int a = 10;
 cout<<bold<<RED;
 gotoxy(40,20);
  cout<<"ACCESS DENIED";
  gotoxy(40,21);
  cout<<"Invalid Password.";
                        // while loop execution
     while( a >=0 ) 
     {cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
        gotoxy(70,12);
        cout << "TIME UNTIL SHUTDOWN: " << setw(2) << a <<"sec(s)"<<endl;
         sleep(1);
        a--;
        if(a==-1)
        {
         exit(0);
        }
    }
return 0;
}
void userid_change()
{system("clear");layout();
      fstream f1;
   string id,c,pass,nnn;
   gotoxy(1,1);
     gotoxy(5,10);
     cout<<UNDERLINE<<RED<<bold<<"Welcome to USER-ID Changing Wizard Ver 1.0."<<cc;
     gotoxy(5,11);
     cout<<yellow<<bold<<"FOLLOW THE ONSCREEN INSTRUCTIONS TO CHANGE THE USER-ID"<<cc;   gotoxy(5,12);
     cout<<"Enter New USER-ID: ";
     cin>>nnn;
     f1.open("file.txt",ios::out);
     f1<<nnn;
     f1.close();gotoxy(5,17);
     cout<<blue<<bold<<"Your USER-ID has been changed. Re login to see the effect, press enter."<<cc<<cc;
     getchar();getchar();system("clear");gotoxy(1,1);layout();login();
}
void settings()
{
    system("clear");
    layout();gotoxy(5,7);
    cout<<red<<bold<<UNDERLINE"Welcome to the Setup Utility"<<CLOSEUNDERLINE;gotoxy(5,8);
    cout<<yellow"Available Options: ";gotoxy(5,9);
    cout<<green"1.) Change /Add /Remove Password.";gotoxy(5,10);
    cout<<"2.) Change USER-ID";gotoxy(5,11);
    cout<<"3.) Reset";gotoxy(5,12);
    cout<<"4.) Re-install the system by performing reset";gotoxy(5,13);
     cout<<"5.) help";gotoxy(5,14);
    cout<<"6.) EXIT."<<cc;
    gotoxy(5,15);cout<<blue<<bold"Enter choice(1-6): "<<cc<<cc;string choice;cin>>choice;
    if(choice=="1")
    {
        password_change();
    }
    else if(choice=="2")
    {
        userid_change();
    }
    else if(choice=="3")
    {reg=0;
    install();
    }
    else if(choice=="4")
    {
        gotoxy(1,1);system("clear");IP();
    }
     else if(choice=="6")
    {
        gotoxy(1,1);system("clear");layout();prompt();
    }
      else if(choice=="5")
    {
        gotoxy(5,16);
        cout<<green<<bold"Welcome to Help Documentaion Ver: 1.0 ";
        gotoxy(5,17);cout<<cc<<cc<<"1.) Press 1 to change/delete/apply new password for your account.";
        gotoxy(5,18);cout<<"2.) Press 2 to change USER-ID for your account.";
        gotoxy(5,19);cout<<"3.) Press 3 to reset or uninstall all your applications for your account.";
        gotoxy(5,20);cout<<"4.) Press 4 to Re-install or recover your system by installation.";
        gotoxy(5,21);cout<<"5.) Press 6 to exit settings."; getchar();getchar();
    }
    else if(choice=="user_add"){add_user();}
    else{
        gotoxy(5,22);cout<<red<<bold<<"No suitable record found"<<"\a\a\a\a\a\a\a\a\a\a\a"<<flush;
        getchar();getchar();settings();
    }gotoxy(5,22);
    cout<<blue<<bold"Successfully completed the command"<<cc;
    getchar();
    settings();
    
} 