// EQN SOLVER
void solve()//To solve the equations using cross multiplication method
{
	x=((Bi1*C2) - (Bi2*C1))/n;
	y=((A2*C1) - (A1*C2))/n;
	gotoxy(5,28);
	cout<<"Required equations after suitable arrangement are:";
	if(C=='y'&&A_1=='n') {
		C1=C1*1;
		C2=C2*1;
	}
	else if(C=='y'&&A_1=='y') {
		C1=C1*-1;
		C2=C2*-1;
	}
	else if(C=='n'&&cho=='y') {
		C1=C1*-1;
		C2=C2*-1;
	}
	else if(C=='n'&&cho=='n') {
		C1=C1*-1;
		C2=C2*-1;
	}
	else {
		cout<<"\nPart of your input is invalid.\nThe program will stop.\n";
	}
	gotoxy(5,29);
	cout<<"("<<A1<<")x + ("<<Bi1<<")y + ("<<C1<<") = 0 n";
	gotoxy(5,30);
	cout<<"("<<A2<<")x + ("<<Bi2<<")y + ("<<C2<<") = 0 ";
	gotoxy(5,31);
	cout<<"X = \033[31m"<<x<<"\033[0;1m and Y = \033[31m"<<y;
	gotoxy(5,32);
	cout<<"They represent equations with unique solution intersecting at a point on graph."<<cc<<cc;
}

void get_Side()//to get the side of constant terms
{
	gotoxy(5,26);
	C = getCharWithClock(5,26, "Are all the constant terms in same side?(y/n)");
	if(C=='y')
	{
		gotoxy(5,27);
		A_1 = getCharWithClock(5,27, "Are the constant terms alone in one side?(y/n)");
		if(A_1=='y') {
			m=-1;
			n=n*m;
			solve();
		}
		else if(A_1=='n') {
			m=1;
			n=n*m;
			solve();
		}
	}
	else if(C=='n')
	{
		gotoxy(5,27);
		cho = getCharWithClock(5,27, "Is C1 alone in one side(y/n):");
		if(cho=='y') {
			m=-1;
			n=n*m;
			C2=C2*-1;
		}
		else if(cho=='n') {
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
	layout();
	gotoxy(5,6);
	cout<<yellow<<bold<<UNDERLINE<<"/*IT MUST BE NOTED THAT ALL THE X,Y and constant terms must be numbers*/\033[0m"<<cc<<endl;
	gotoxy(5,7);
	cout<<blue<<bold<<"Your equations may be in the form of:";
	gotoxy(5,8);
	cout<<"a1x + b1y + c1 = 0";
	gotoxy(5,9);
	cout<<"a2x + b2y + c2 = 0";
	gotoxy(5,11);
	cout<<"a1x + b1y = c1 ";
	gotoxy(5,12);
	cout<<"a2x + b2y = c2 ";
	gotoxy(5,14);
	cout<<"a1x + b1y = c1 ";
	gotoxy(5,15);
	cout<<"a2x + b2y + c2 = 0";
	gotoxy(5,17);
	cout<<"a1x + b1y + c1 = 0";
	gotoxy(5,18);
	cout<<"a2x + b2y = c2 "<<cc<<cc<<endl;
	gotoxy(5,20);
	A1 = getDoubleWithClock(5,20, string(green) + string(bold) + "Enter the value of a1/coefficient of x in first equation:" + cc + " ");
	gotoxy(5,21);
	Bi1 = getDoubleWithClock(5,21, string(green) + string(bold) + "Enter the value of b1/coefficient of y in first equation:" + cc + " ");
	gotoxy(5,22);
	C1 = getDoubleWithClock(5,22, string(green) + string(bold) + "Enter the value of c1/constant in first equation:" + cc + " ");
	gotoxy(5,23);
	A2 = getDoubleWithClock(5,23, string(green) + string(bold) + "Enter the value of a2/coefficient of x in second equation:" + cc + " ");
	gotoxy(5,24);
	Bi2 = getDoubleWithClock(5,24, string(green) + string(bold) + "Enter the value of b2/coefficient of y in second equation:" + cc + " ");
	gotoxy(5,25);
	C2 = getDoubleWithClock(5,25, string(green) + string(bold) + "Enter the value of c2/constant term in second equation:" + cc + " ");

	n=((A1*Bi2) -(A2*Bi1));
	if(A1*Bi2 != A2*Bi1)
		get_Side();
	else if(A1/A2 == Bi1/Bi2 && A1/A2==C1/C2)
	{
		gotoxy(5,26);
		cout<<"Solution can be given only to equations with unique solution.";
		gotoxy(5,27);
		cout<<"Your entered equations have infinitely many solutions and represent coincident lines on graph.";
		waitForAnyKey();
	}
	else if(A1/A2 == Bi1/Bi2 && A1/A2!=C1/C2)
	{
		gotoxy(5,26);
		cout<<"Solution can be given only to equations with unique solution.";
		gotoxy(5,27);
		cout<<"Your entered equations have no solutions and represent parallel lines on graph.";
		waitForAnyKey();
	}
}

// TicTacToe helper – read move (returns -1 for cheat, 1-9 otherwise)
int getTicTacToeMove(int x, int y, const string &prompt) {
    string input;
    fd_set fds;
    struct timeval tv;
    enableRawMode();
    while (true) {
        updateDateTimeLine();
        gotoxy(x, y);
        cout << "\033[K" << prompt << input;
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
                // Cheat 'w'
                if (input == "w") {
                    disableRawMode();
                    return -1;
                }
                char* end;
                long val = strtol(input.c_str(), &end, 10);
                if (end != input.c_str() && *end == '\0' && val >= 1 && val <= 9) {
                    disableRawMode();
                    return (int)val;
                } else {
                    gotoxy(x, y+1);
                    cout << "\033[KInvalid move. Enter 1-9.";
                    input.clear();
                    usleep(500000);
                    gotoxy(x, y+1);
                    cout << "\033[K";
                }
            } else if (c == 127 || c == '\b') {
                if (!input.empty()) input.pop_back();
            } else if (isdigit(c) || c == 'w') {
                input.push_back(c);
            }
        }
    }
}

void selector_t()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout << "\t\t\t\t\t"<<bold<<UNDERLINE<<RED<<"Select Game Mode(1/2)."<< CLOSEUNDERLINE<<cc<<CLOSEUNDERLINE;
	gotoxy(5,9);
	cout << "  \t\t\t\t\t\x1B[94m1. Computer VS Player.";
	gotoxy(5,10);
	cout << "  \t\t\t\t\t2. Player VS Player." << CLOSEUNDERLINE;

    // Loop until a valid mode (1 or 2) is entered
    while (true) 
    {
        gotoxy(5,11);
        cout << "                                                       " << endl; // clear line
        char ch = getCharWithClock(5,11, "\x1B[93mENTER YOUR CHOICE: ");
        cout << cc;
        if (ch == '1') {
            mode = 1;
            break;
        } else if (ch == '2') {
            mode = 2;
            break;
        }
        // Invalid input: show error
        gotoxy(5,15);
        cout << "                                                "; // clear error line
        gotoxy(5,15);
        cout << RED << bold << "Invalid choice. Please enter 1 or 2." << cc << endl;
        sleep(1); // brief pause
        gotoxy(5,15);
        cout << "                                                       " << endl; // clear error
        gotoxy(5,11); // back to prompt line
    }

	switch(mode)
	{
	case 1 :
		gotoxy(5,12);
		cout<<RED<<bold<<"Enter Game type:"<<cc;
		gotoxy(5,13);
		cout<<yellow<<"\ta.)Simple.";
		gotoxy(5,14);
		cout<<"\tb.)Difficult."<<cc;
		do {
			gotoxy(5,15);
			cout<<"                                     ";
			gotoxy(5,15);
			cout<<"Enter Your Choice: ";
			Difficult = getStringWithClock(5,15, "", false);
			if (Difficult != "a" && Difficult != "b") {
				gotoxy(5,16);
				cout << "Invalid choice. Please enter 'a' or 'b'." << endl;
			}
		} while (Difficult != "a" && Difficult != "b");
		if (Difficult == "a") {
			Difficult = "1";
			computer_vs_player();
		} else {
			Difficult = "2";
			computer_vs_player();
		}
		break;
	case 2:
		player_vs_player();
		break;
	}
}

void computer_vs_player() {
	string player_name;
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<red<<bold<<"Please fill in the following details:"<<CLOSEUNDERLINE;
	gotoxy(5,8);
	cout <<yellow<< "Enter Your Name: "<<CLOSEUNDERLINE;
	cin >> player_name;   // blocking – one string, acceptable
	while(true) {
		system("clear");
		show_board();
		if(count_board('X') == count_board('O')) {
			gotoxy(5,22);
			cout << player_name << "'s Turn." << endl;
			get_x_player_choice();
		}
		else
		{
			if(Difficult=="1") get_computer_choice_e();
			else if(Difficult=="2") get_computer_choice_h();
		}
		char winner = check_winner();
		if(winner == 'X') {
			system("clear");
			show_board();
			gotoxy(5,22);
			cout << player_name <<" Won The Game."<< endl;
			waitForAnyKey();
			break;
		}
		else if(winner == 'O') {
			system("clear");
			show_board();
			gotoxy(5,22);
			cout << "Computer Won The Game." << endl;
			waitForAnyKey();
			break;
		}
		else if(winner == 'D') {
			system("clear");
			show_board();
			gotoxy(5,22);
			cout << "Game is Draw." << endl;
			waitForAnyKey();
			break;
		}
	}
	getchar();
	system("clear");
	cout<<"\nThe program is shutting down to prevent any file corruption.";
	exit(0);
}

void get_computer_choice_e() {
	srand(time(0));
	int choice;
	do {
		choice = rand()%10;
	}
	while(board[choice] != ' ');
	board[choice] = 'O';
}

void get_computer_choice_h() {
	while(true)
	{
		if(board[0] == board[1] && board[2] == ' ' && board[0]=='O') {
			board[2]='O';
			break;
		}
		else if(board[3] == board[4] && board[5] == ' '&& board[3]=='O') {
			board[5]='O';
			break;
		}
		else if(board[6] == board[7] && board[8] == ' '&& board[6]=='O') {
			board[8]='O';
			break;
		}
		else if(board[0] == board[2] && board[1] == ' '&& board[0]=='O') {
			board[1]='O';
			break;
		}
		else if(board[3] == board[5] && board[4] == ' '&& board[3]=='O') {
			board[4]='O';
			break;
		}
		else if(board[6] == board[8] && board[7] == ' '&& board[6]=='O') {
			board[7]='O';
			break;
		}
		else if(board[7] == board[8] && board[6] == ' '&& board[7]=='O') {
			board[6]='O';
			break;
		}
		else if(board[5] == board[4] && board[3] == ' '&& board[5]=='O') {
			board[3]='O';
			break;
		}
		else if(board[1] == board[2] && board[0] == ' '&& board[1]=='O') {
			board[0]='O';
			break;
		}
		else if(board[0] == board[3] && board[6] == ' '&& board[0]=='O') {
			board[6]='O';
			break;
		}
		else if(board[1] == board[4] && board[7] == ' '&& board[1]=='O') {
			board[7]='O';
			break;
		}
		else if(board[2] == board[5] && board[8] == ' '&& board[5]=='O') {
			board[8]='O';
			break;
		}
		else if(board[0] == board[6] && board[3] == ' '&& board[0]=='O') {
			board[3]='O';
			break;
		}
		else if(board[1] == board[7] && board[4] == ' '&& board[1]=='O') {
			board[4]='O';
			break;
		}
		else if(board[2] == board[8] && board[5] == ' '&& board[2]=='O') {
			board[5]='O';
			break;
		}
		else if(board[3] == board[6] && board[0] == ' '&& board[3]=='O') {
			board[0]='O';
			break;
		}
		else if(board[4] == board[7] && board[1] == ' '&& board[4]=='O') {
			board[1]='O';
			break;
		}
		else if(board[8] == board[5] && board[2] == ' '&& board[5]=='O') {
			board[2]='O';
			break;
		}
		else if(board[8] == board[0] && board[4] == ' '&& board[0]=='O') {
			board[4]='O';
			break;
		}
		else if(board[8] == board[4] && board[0] == ' '&& board[4]=='O') {
			board[0]='O';
			break;
		}
		else if(board[4] == board[0] && board[8] == ' '&& board[0]=='O') {
			board[8]='O';
			break;
		}
		else if(board[2] == board[6] && board[4] == ' '&& board[2]=='O') {
			board[4]='O';
			break;
		}
		else if(board[2] == board[4] && board[6] == ' '&& board[4]=='O') {
			board[6]='O';
			break;
		}
		else if(board[4] == board[6] && board[2] == ' '&& board[4]=='O') {
			board[2]='O';
			break;
		}
		else if(board[0] == board[1] && board[2] == ' ' && board[0]=='X') {
			board[2]='O';
			break;
		}
		else if(board[3] == board[4] && board[5] == ' '&& board[3]=='X') {
			board[5]='O';
			break;
		}
		else if(board[6] == board[7] && board[8] == ' '&& board[6]=='X') {
			board[8]='O';
			break;
		}
		else if(board[0] == board[2] && board[1] == ' '&& board[0]=='X') {
			board[1]='O';
			break;
		}
		else if(board[3] == board[5] && board[4] == ' '&& board[3]=='X') {
			board[4]='O';
			break;
		}
		else if(board[6] == board[8] && board[7] == ' '&& board[6]=='X') {
			board[7]='O';
			break;
		}
		else if(board[7] == board[8] && board[6] == ' '&& board[7]=='X') {
			board[6]='O';
			break;
		}
		else if(board[5] == board[4] && board[3] == ' '&& board[5]=='X') {
			board[3]='O';
			break;
		}
		else if(board[1] == board[2] && board[0] == ' '&& board[1]=='X') {
			board[0]='O';
			break;
		}
		else if(board[0] == board[3] && board[6] == ' '&& board[0]=='X') {
			board[6]='O';
			break;
		}
		else if(board[1] == board[4] && board[7] == ' '&& board[1]=='X') {
			board[7]='O';
			break;
		}
		else if(board[2] == board[5] && board[8] == ' '&& board[5]=='X') {
			board[8]='O';
			break;
		}
		else if(board[0] == board[6] && board[3] == ' '&& board[0]=='X') {
			board[3]='O';
			break;
		}
		else if(board[1] == board[7] && board[4] == ' '&& board[1]=='X') {
			board[4]='O';
			break;
		}
		else if(board[2] == board[8] && board[5] == ' '&& board[2]=='X') {
			board[5]='O';
			break;
		}
		else if(board[3] == board[6] && board[0] == ' '&& board[3]=='X') {
			board[0]='O';
			break;
		}
		else if(board[4] == board[7] && board[1] == ' '&& board[4]=='X') {
			board[1]='O';
			break;
		}
		else if(board[8] == board[5] && board[2] == ' '&& board[5]=='X') {
			board[2]='O';
			break;
		}
		else if(board[8] == board[0] && board[4] == ' '&& board[0]=='X') {
			board[4]='O';
			break;
		}
		else if(board[8] == board[4] && board[0] == ' '&& board[4]=='X') {
			board[0]='O';
			break;
		}
		else if(board[4] == board[0] && board[8] == ' '&& board[0]=='X') {
			board[8]='O';
			break;
		}
		else if(board[2] == board[6] && board[4] == ' '&& board[2]=='X') {
			board[4]='O';
			break;
		}
		else if(board[2] == board[4] && board[6] == ' '&& board[4]=='X') {
			board[6]='O';
			break;
		}
		else if(board[4] == board[6] && board[2] == ' '&& board[4]=='X') {
			board[2]='O';
			break;
		}
		else if(board[4]=='X')
		{
			if(' '==board[0]) {
				board[0]='O';
				break;
			}
			else if(' '==board[1]) {
				board[1]='O';
				break;
			}
			else if(' '==board[2]) {
				board[2]='O';
				break;
			}
			else if(' '==board[3]) {
				board[3]='O';
				break;
			}
			else if(' '==board[4]) {
				board[4]='O';
				break;
			}
			else if(' '==board[5]) {
				board[5]='O';
				break;
			}
			else if(' '==board[6]) {
				board[6]='O';
				break;
			}
			else if(' '==board[7]) {
				board[7]='O';
				break;
			}
			else if(' '==board[8]) {
				board[8]='O';
				break;
			}
		}
		else if('X'==board[0]||'X'==board[2]||'X'==board[6]||'X'==board[8])
		{
			if(' '==board[0]) {
				board[0]='O';
				break;
			}
			else if(' '==board[2]) {
				board[2]='O';
				break;
			}
			else if(' '==board[6]) {
				board[6]='O';
				break;
			}
			else if(' '==board[8]) {
				board[8]='O';
				break;
			}
		}
		else if('X'==board[1]||'X'==board[3]||'X'==board[7]||'X'==board[5])
		{
			if(' '==board[1]) {
				board[1]='O';
				break;
			}
			else if(' '==board[3]) {
				board[3]='O';
				break;
			}
			else if(' '==board[7]) {
				board[7]='O';
				break;
			}
			else if(' '==board[5]) {
				board[5]='O';
				break;
			}
		}
	}
}

void get_x_player_choice() {
	int move = getTicTacToeMove(5,20, "Select Your Position (1 - 9): ");
	if (move == -1) {
		// cheat
		board[1]=board[4]=board[7]=board[2]=board[3]='X';
		board[0]=board[6]=board[8]=board[5]='O';
		system("clear");
		show_board();
		gotoxy(5,17);
		cout<<"You win the game, Computer/player 2 lost the game";
		waitForAnyKey();
		exit(0);
	}
	move--;
	if (move < 0 || move > 8) {
		gotoxy(5,21);
		cout << "Please Select Your Choice From (1 - 9)." << endl;
		waitForAnyKey();
	} else if (board[move] != ' ') {
		gotoxy(5,21);
		cout << "Please Select An Empty Position." << endl;
		waitForAnyKey();
	} else {
		board[move] = 'X';
	}
}

void get_o_player_choice() {
	int move = getTicTacToeMove(5,20, "Select Your Position (1 - 9): ");
	if (move == -1) {
		// cheat
		board[1]=board[4]=board[7]=board[2]=board[3]='O';
		board[0]=board[6]=board[8]=board[5]='X';
		system("clear");
		show_board();
		gotoxy(5,20);
		cout<<"You win the game, player 1 lost the game";
		waitForAnyKey();
		exit(0);
	}
	move--;
	if (move < 0 || move > 8) {
		gotoxy(5,21);
		cout << "Please Select Your Choice From (1 - 9)." << endl;
		waitForAnyKey();
	} else if (board[move] != ' ') {
		gotoxy(5,21);
		cout << "Please Select An Empty Position." << endl;
		waitForAnyKey();
	} else {
		board[move] = 'O';
	}
}

void player_vs_player() {
	string x_player_name, o_player_name;
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<red<<bold<<"Please fill in the following details:"<<cc;
	gotoxy(5,8);
	cout <<yellow<<"Enter X Player Name: " <<CLOSEUNDERLINE;
	cin >> x_player_name;
	gotoxy(5,9);
	cout << yellow<<"Enter O Player Name: "<<CLOSEUNDERLINE ;
	cin >> o_player_name;
	while(true) {
		system("clear");
		show_board();
		if(count_board('X') == count_board('O')) {
			gotoxy(5,19);
			cout << x_player_name << "'s Turn."<< endl;
			get_x_player_choice();
		}
		else {
			gotoxy(5,19);
			cout << o_player_name << "'s Turn." << endl;
			get_o_player_choice();
		}
		char winner = check_winner();
		if(winner == 'X') {
			system("clear");
			show_board();
			gotoxy(5,23);
			cout << x_player_name << " Won The Game." << endl;
			waitForAnyKey();
			break;
		}
		else if(winner == 'O') {
			system("clear");
			show_board();
			gotoxy(5,23);
			cout << o_player_name << " Won The Game." << endl;
			waitForAnyKey();
			break;
		}
		else if(winner == 'D') {
			gotoxy(5,23);
			cout << "Game is Draw." << endl;
			waitForAnyKey();
			break;
		}
	}
	getchar();
	system("clear");
	gotoxy(5,1);
	cout<<RED<<bold<<"The program is shutting down to prevent any file corruption.";
	exit(0);
}

int count_board(char symbol) {
	int total=0;
	for(int i=0; i<9; i++) if(board[i]==symbol) total++;
	return total;
}

char check_winner() {
	if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ') return board[0];
	if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ') return board[3];
	if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ') return board[6];
	if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ') return board[0];
	if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ') return board[1];
	if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ') return board[2];
	if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ') return board[0];
	if(board[2]==board[4] && board[4]==board[6] && board[2]!=' ') return board[2];
	if(count_board('X')+count_board('O')<9) return 'C';
	return 'D';
}

void show_board()
{
	layout();
	gotoxy(5,7);
	cout<<green<<"   "<<"    |   "<<"    |   "<<cc;
	gotoxy(5,8);
	cout<<green<<"   "<<cc<<red<<board[0]<<cc<<green<<"   |   "<<cc<<red<<board[1]<<cc<<green<<"   |   "<<cc<<red<<board[2]<<cc;
	gotoxy(5,9);
	cout<<green<<"   "<<"    |   "<<"    |   ";
	gotoxy(5,10);
	cout<<"-----------------------";
	gotoxy(5,11);
	cout<<"   "<<"    |   "<<"    |   ";
	gotoxy(5,12);
	cout<<cc<<"   "<<red<<board[3]<<cc<<green<<"   |   "<<cc<<red<<board[4]<<cc<<green<<"   |   "<<cc<<red<<board[5]<<cc;
	gotoxy(5,13);
	cout<<green<<"   "<<"    |   "<<"    |   ";
	gotoxy(5,14);
	cout<<"-----------------------";
	gotoxy(5,15);
	cout<<"   "<<"    |   "<<"    |   ";
	gotoxy(5,16);
	cout<<"   "<<cc<<red<<board[6]<<cc<<green<<"   |   "<<cc<<red<<board[7]<<cc<<green<<"   |   "<<cc<<red<<board[8]<<cc;
	gotoxy(5,17);
	cout<<green<<"   "<<"    |   "<<"    |   "<<cc;
}

//CALCULATOR
void calc()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<"!!!!!!!!!!!!!!This is a calculator!!!!!!!!!!!!!"<<endl;
	double a,b,c,d,e,f,g;
	char A,B,C;
	a = getDoubleWithClock(5,11, "Enter first number: ");
	getValidOperator(A,5,12,"Enter first operator: ");
	b = getDoubleWithClock(5,13, "Enter second number: ");
	getValidOperator(B,5,14,"Enter second operator: ");
	c = getDoubleWithClock(5,15, "Enter third number: ");
	getValidOperator(C,5,16,"Enter third operator: ");
	d = getDoubleWithClock(5,17, "Enter fourth number: ");
	gotoxy(5,18);
	cout<<"Expression you entered is:"<<a<<A<<b<<B<<c<<C<<d<<endl;
	switch(A) {
	case '+': e=a+b; break;
	case '-': e=a-b; break;
	case '/': e=a/b; break;
	case '*': e=a*b; break;
	default: gotoxy(5,21); cout<<"Invalid input";
	}
	switch(B) {
	case '+': f=e+c; break;
	case '-': f=e-c; break;
	case '/': f=e/c; break;
	case '*': f=e*c; break;
	default: gotoxy(5,21); cout<<"Invalid input";
	}
	switch(C) {
	case '+': g=f+d; gotoxy(5,21); cout<<"Result is :"<<g<<endl; break;
	case '-': g=f-d; gotoxy(5,21); cout<<"Result is :"<<g<<endl; break;
	case '/': g=f/d; gotoxy(5,21); cout<<"Result is :"<<g<<endl; break;
	case '*': g=f*d; gotoxy(5,21); cout<<"Result is :"<<g<<endl; break;
	default: gotoxy(5,21); cout<<"Invalid input";
	}
	gotoxy(5,23);
	cout<<"\t\t\t<<PRESS ANY KEY TO EXIT>>"<<endl;
	waitForAnyKey();
	prompt();
}

//TEMPERATURE_CONVERTER
void tc()
{
	system("clear");
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<yellow<<UNDERLINE<<bold"TEMPERATURE_CONVERTER_PROGRAM_VER: 4.05"<<cc<<cc;
	char choice;
	int temp,temp_c;
	gotoxy(5,9);
	choice = getCharWithClock(5,9, string(green) + string(bold) + "Enter your desired unit of temperature:(C/F/K):" + cc);
	gotoxy(5,10);
	temp = getIntWithClock(5,10, string(cyan) + string(bold) + "Enter temperature (" + choice + "): " + cc);
	if(choice=='C'||choice=='c')
	{
		temp_c=(temp*1.8)+32;
		gotoxy(5,11);
		cout<<"Temperature in B0F is:"<<temp_c;
		gotoxy(5,12);
		cout<<"Temperature in K is:"<<temp+273;
	}
	else if(choice=='F'||choice=='f')
	{
		temp_c=(temp-32)*5/9;
		gotoxy(5,11);
		cout<<"Temperature in B0C is:"<<temp_c;
		gotoxy(5,12);
		cout<<"Temperature in K is:"<<temp_c+273;
	}
	else if(choice=='K'||choice=='k')
	{
		temp_c=temp-273;
		gotoxy(5,11);
		cout<<"Temperature in B0C is:"<<temp_c;
		temp_c=(temp_c*1.8)+32;
		gotoxy(5,12);
		cout<<"Temperature in B0F is:"<<temp_c;
	}
	else {
		gotoxy(5,11);
		cout<<red<<bold"INVALID INPUT"<<cc;
	}
	waitForAnyKey();
	cout<<cc;
	prompt();
}

//THE QUIZ (LARGEST)
int A,B,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5,bo1,bo2,bo3,bo4,bo5,bo6,bo7,bo8,r;
char p1,o1,p2,o2,p3,o3,o4,p4,o5,p5,o6,p6,o7,p7,o8,p8;

int printerror1()
{
	system("clear");
	gotoxy(5,8);
	cout<<bold;
	printf("\x1B[31m\t\t\t\tThis cheat code is for entertainment only\033[0m\t\t");
	gotoxy(5,9);
	printf("\x1B[34m\nPlease restart the program\033[0m\t\t");
	waitForAnyKey();
	system("clear");
	return 0;
}

int printawon()
{
	A=45;
	B=0;
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<"Correct Answers:";
	gotoxy(5,8);
	cout<<"1.) C";
	gotoxy(5,9);
	cout<<"2.) A";
	gotoxy(5,10);
	cout<<"3.) C";
	gotoxy(5,11);
	cout<<"4.) D";
	gotoxy(5,12);
	cout<<"5.) B";
	gotoxy(5,13);
	cout<<"6.) A";
	gotoxy(5,14);
	cout<<"A won";
	gotoxy(5,15);
	cout<<" A="<<A<<"\tB="<<B;
	waitForAnyKey();
	printerror1();
	return 0;
}

int printbwon()
{
	B=45;
	A=0;
	gotoxy(1,1);
	layout();
	gotoxy(5,7);
	cout<<"Correct Answers:";
	gotoxy(5,8);
	cout<<"1.) C";
	gotoxy(5,9);
	cout<<"2.) A";
	gotoxy(5,10);
	cout<<"3.) C";
	gotoxy(5,11);
	cout<<"4.) D";
	gotoxy(5,12);
	cout<<"5.) B";
	gotoxy(5,13);
	cout<<"6.) A";
	gotoxy(5,14);
	cout<<"B won";
	gotoxy(5,15);
	cout<<" A="<<A<<"\tB="<<B;
	return 0;
}

int scrbrd()
{
	system ("clear");
	layout();
	gotoxy(64,9);
	cout << "Score(Rnd-" << r << ")";
	gotoxy(57,10);
	cout << "|______Score Board______|";
	gotoxy(57,11);
	cout << "|_____A_____|_____B_____|";
	gotoxy(57,12);
	cout<<"| ";
	if(a1==10) cout<<a1;
	else if(a1==-5) cout<<a1;
	else cout<<"+"<<a1;
	cout<<"  | +"<<bo2<<"  | ";
	if(b1==10) cout<<b1;
	else if(b1==-5) cout<<b1;
	else cout<<"+"<<b1;
	cout<<"  | +"<<bo1<<"  | ";
	gotoxy(57,13);
	cout<<"| ";
	if(a2==10) cout<<a2;
	else if(a2==-5) cout<<a2;
	else cout<<"+"<<a2;
	cout<<"  | +"<<bo4<<"  | ";
	if(b2==10) cout<<b2;
	else if(b2==-5) cout<<b2;
	else cout<<"+"<<b2;
	cout<<"  | +"<<bo3<<"  |";
	gotoxy(57,14);
	cout<<"| ";
	if(a3==10) cout<<a3;
	else if(a3==-5) cout<<a3;
	else cout<<"+"<<a3;
	cout<<"  | +"<<bo6<<"  | ";
	if(b3==10) cout<<b3;
	else if(b3==-5) cout<<b3;
	else cout<<"+"<<b3;
	cout<<"  | +"<<bo5<<"  |";
	gotoxy(57,15);
	cout<<"| ";
	if(a4==10) cout<<a4;
	else if(a4==-5) cout<<a4;
	else cout<<"+"<<a4;
	cout<<"  | +"<<bo8<<"  | ";
	if(b4==10) cout<<b4;
	else if(b4==-5) cout<<b4;
	else cout<<"+"<<b4;
	cout<<"  | +"<<bo7<<"  |";
	waitForAnyKey();
	if(r==4) scr();
	return 0;
}

int scr()
{
	A = a1+a2+a3+a4+bo8+bo6+bo2+bo4;
	B = b1+b2+b3+b4+bo7+bo5+bo1+bo3;
	cout<<green<<bold;
	if(A>B) {
		gotoxy(64,16);
		cout<<"!!!A won!!!";
		gotoxy(62,17);
		cout<<" A="<<A<<"\tB="<<B;
	}
	else if(B>A) {
		gotoxy(64,16);
		cout<<"!!!B won!!!";
		gotoxy(62,17);
		cout<<" A="<<A<<"\tB="<<B;
	}
	else {
		gotoxy(64,16);
		cout<<"!!!!Tie.!!!!";
		gotoxy(62,17);
		cout<<" A="<<A<<"\tB="<<B;
	}
	cout<<cc;
	waitForAnyKey();
	return 0;
}

int printrndfour()
{
	a4=0;
	b4=0;
	bo7=0;
	bo8=0;
	r=4;
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: A";
	gotoxy(5,9);
	cout<<"7.) Who discovered neutron ?";
	gotoxy(5,10);
	cout<<" a.) James Chadwick.";
	gotoxy(5,11);
	cout<<" b.) Einstein.";
	gotoxy(5,12);
	cout<<" c.) Newton.";
	gotoxy(5,13);
	cout<<" d.) Haris.";
	char g;
	timerO();
	g = getCharWithClock(5,15, "");
	switch(g)
	{
	case 'a': a4=10; break;
	case 'z': printawon();
	case'u':
		a3=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p7 = getCharWithClock(5,18, "");
		switch(p7)
		{
		case 'y':
			timerB();
			o7 = getCharWithClock(5,22, "");
			if(o7=='a') bo7=5; else bo7=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		a4=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p7 = getCharWithClock(5,18, "");
		switch(p7)
		{
		case 'y':
			timerB();
			o7 = getCharWithClock(5,22, "");
			if(o7=='a') bo7=5; else bo7=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	waitForAnyKey();
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: B"<<endl;
	gotoxy(5,9);
	cout<<"8.) Who discovered electron?";
	gotoxy(5,10);
	cout<<" a.) Purkinje.";
	gotoxy(5,11);
	cout<<" b.) J.J. Thompson.";
	gotoxy(5,12);
	cout<<" c.) Brown.";
	gotoxy(5,13);
	cout<<" d.) Rutherford.";
	char h;
	timerO();
	h = getCharWithClock(5,15, "");
	switch(h)
	{
	case 'b': b4=10; break;
	case 'z': printbwon();
	case'u':
		b4=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p8 = getCharWithClock(5,18, "");
		switch(p8)
		{
		case 'y':
			timerB();
			o8 = getCharWithClock(5,22, "");
			if(o8=='b') bo8=5; else bo8=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		b4=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p8 = getCharWithClock(5,18, "");
		switch(p8)
		{
		case 'y':
			timerB();
			o8 = getCharWithClock(5,22, "");
			if(o8=='b') bo6=5; else bo6=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	scrbrd();
	return 0;
}

int printrndthree()
{
	a3=0;
	b3=0;
	bo5=0;
	bo6=0;
	r=3;
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: A";
	gotoxy(5,9);
	cout<<"5.) Who discovered e=mc^2 ?";
	gotoxy(5,10);
	cout<<" a.) Einstein.";
	gotoxy(5,11);
	cout<<" b.) James.";
	gotoxy(5,12);
	cout<<" c.) Goebbels.";
	gotoxy(5,13);
	cout<<" d.) Haris.";
	char e;
	timerO();
	e = getCharWithClock(5,15, "");
	switch(e)
	{
	case 'a': a3=10; break;
	case'u':
		a3=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p5 = getCharWithClock(5,18, "");
		switch(p5)
		{
		case 'y':
			timerB();
			o5 = getCharWithClock(5,22, "");
			if(o5=='a') bo5=5; else bo5=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		a3=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p5 = getCharWithClock(5,18, "");
		switch(p5)
		{
		case 'y':
			timerB();
			o5 = getCharWithClock(5,22, "");
			if(o5=='a') bo5=5; else bo5=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	waitForAnyKey();
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: B"<<endl;
	gotoxy(5,9);
	cout<<"6.) Who coined the term protoplasm?";
	gotoxy(5,10);
	cout<<" a.) Rutherford.";
	gotoxy(5,11);
	cout<<" b.) Purkinje.";
	gotoxy(5,12);
	cout<<" c.) Brown.";
	gotoxy(5,13);
	cout<<" d.) Bohr.";
	char f;
	timerO();
	f = getCharWithClock(5,15, "");
	switch(f)
	{
	case 'b': b3=10; scrbrd(); break;
	case'u':
		b3=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p6 = getCharWithClock(5,18, "");
		switch(p6)
		{
		case 'y':
			timerB();
			o6 = getCharWithClock(5,22, "");
			if(o6=='b') { bo6=5; scrbrd(); } else { bo6=0; scrbrd(); }
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		b3=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p6 = getCharWithClock(5,18, "");
		switch(p6)
		{
		case 'y':
			timerB();
			o6 = getCharWithClock(5,22, "");
			if(o6=='b') { bo6=5; scrbrd(); } else { bo6=0; scrbrd(); }
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
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
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: A";
	gotoxy(5,9);
	cout<<"3.) Conio.h refera to :";
	gotoxy(5,10);
	cout<<" a.) console in out.";
	gotoxy(5,11);
	cout<<" b.) header file.";
	gotoxy(5,12);
	cout<<" c.) both a and b.";
	gotoxy(5,13);
	cout<<" d.) None.";
	char c;
	timerO();
	c = getCharWithClock(5,15, "");
	switch(c)
	{
	case 'c': a2=10; break;
	case'u':
		a2=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p3 = getCharWithClock(5,18, "");
		switch(p3)
		{
		case 'y':
			timerB();
			o3 = getCharWithClock(5,22, "");
			if(o3=='c') bo3=5; else bo3=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		a2=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p3 = getCharWithClock(5,18, "");
		switch(p3)
		{
		case 'y':
			timerB();
			o3 = getCharWithClock(5,22, "");
			if(o3=='c') bo3=5; else bo3=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	waitForAnyKey();
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: B"<<endl;
	gotoxy(5,9);
	cout<<"4.) Which king ruled France during 1774?";
	gotoxy(5,10);
	cout<<" a.) Louis XX.";
	gotoxy(5,11);
	cout<<" b.) Louis XVI.";
	gotoxy(5,12);
	cout<<" c.) Louis XV.";
	gotoxy(5,13);
	cout<<" d.) Louis XIV.";
	char d;
	timerO();
	d = getCharWithClock(5,15, "");
	switch(d)
	{
	case 'b': b2=10; scrbrd(); break;
	case'u':
		b2=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p4 = getCharWithClock(5,18, "");
		switch(p4)
		{
		case 'y':
			timerB();
			o4 = getCharWithClock(5,22, "");
			if(o4=='b') { bo4=5; scrbrd(); } else { bo4=0; scrbrd(); }
			printrndthree();
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		b2=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p4 = getCharWithClock(5,18, "");
		switch(p4)
		{
		case 'y':
			timerB();
			o4 = getCharWithClock(5,22, "");
			if(o4=='b') { bo4=5; scrbrd(); } else { bo4=0; scrbrd(); }
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
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
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: A";
	gotoxy(5,9);
	cout<<"1.) Who was the first propaganda minister of hitler?";
	gotoxy(5,10);
	cout<<" a.) James.";
	gotoxy(5,11);
	cout<<" b.) Gary.";
	gotoxy(5,12);
	cout<<" c.) Goebbels.";
	gotoxy(5,13);
	cout<<" d.) Haris.";
	timerO();
	char a,b;
	a = getCharWithClock(5,15, "");
	switch(a)
	{
	case 'c': a1=10; break;
	case 'u':
		a1=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p1 = getCharWithClock(5,18, "");
		switch(p1)
		{
		case 'y':
			timerB();
			o1 = getCharWithClock(5,22, "");
			if(o1=='c') bo1=5; else bo1=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		a1=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p1 = getCharWithClock(5,18, "");
		switch(p1)
		{
		case 'y':
			timerB();
			o1 = getCharWithClock(5,22, "");
			if(o1=='c') bo1=5; else bo1=0;
			break;
		case 'n': break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	system("clear");
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"Group: B";
	gotoxy(5,9);
	cout<<"2.) When French Revolution Started?";
	gotoxy(5,10);
	cout<<" a.) 1764";
	gotoxy(5,11);
	cout<<" b.) 1665.";
	gotoxy(5,12);
	cout<<" c.) 1122.";
	gotoxy(5,13);
	cout<<" d.) 1789.";
	timerO();
	b = getCharWithClock(5,15, "");
	switch(b)
	{
	case 'd': b1=10; scrbrd(); break;
	case 'u':
		b1=0;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p2 = getCharWithClock(5,18, "");
		switch(p2)
		{
		case 'y':
			timerB();
			o2 = getCharWithClock(5,22, "");
			if(o2=='d') bo2=5; else bo2=0;
			scrbrd();
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
		break;
	default:
		b1=-5;
		gotoxy(5,18);
		cout<<"Do you want bonus round(y/n):";
		p2 = getCharWithClock(5,18, "");
		switch(p2)
		{
		case 'y':
			timerB();
			o2 = getCharWithClock(5,22, "");
			if(o2=='d') bo2=5; else bo2=0;
			scrbrd();
			break;
		case 'n': scrbrd(); break;
		default:
			gotoxy(5,19);
			cout<<"Invalid Input";
			waitForAnyKey();
			printerror();
		}
	}
	if(trial==0) printrndtwo();
	else {
		scr();
		gotoxy(5,35);
		cout<<RED<<bold"TRIAL OVER. PRESS ENTER TO RETURN OR E TO EXIT"<<cc<<cc;
		waitForAnyKey();
		int co = getCharWithClock(5,35, "");
		if(co=='e'||co=='E') {
			system("clear");
			cout<<"Thank You for using !!";
			exit(0);
		}
		system("clear");
		layout();
		reg_edit();
	}
	return 0;
}

int about()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<UNDERLINE"\x1B[34m\nAbout:\033[0m"<<CLOSEUNDERLINE;
	cout<<" This is quiz app version 10.8 developed by Subhajit Halder";
	gotoxy(5,9);
	printf("       This is console based application. \t\t");
	gotoxy(5,10);
	cout<<"\x1B[32m\n\n\n\n\n\t\tTo raise a suggestion for the new version please write to subhajithalder327@outlook.com\033[0m";
	waitForAnyKey();
	printrndone();
	return 0;
}

int evaluator()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,10);
	cout<<"Evaluated By: Ritabrata Saha";
	waitForAnyKey();
	prompt();
	return 0;
}

int cheatcode()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<"\x1B[31mEvery Game has certain cheat codes or cheat sheets\033[0m";
	gotoxy(5,9);
	cout<<"Quiz ver:10.8 is also having it as it is a quiz game.";
	gotoxy(5,10);
	cout<<"List of All correct answers.";
	gotoxy(5,11);
	cout<<"Correct Answers:";
	gotoxy(5,12);
	cout<<"\n1.) C";
	gotoxy(5,13);
	cout<<"\n2.) D";
	gotoxy(5,14);
	cout<<"\n3.) C";
	gotoxy(5,15);
	cout<<"\n4.) B";
	gotoxy(5,16);
	cout<<"\n5.) A";
	gotoxy(5,17);
	cout<<"\n6.) B";
	gotoxy(5,18);
	cout<<"\n7.) A";
	gotoxy(5,19);
	cout<<"\n8.) B";
	waitForAnyKey();
	printrndone();
	return 0;
}

int start()
{
	gotoxy(1,1);
	layout();
	gotoxy(20,8);
	cout <<" "<<blue<<bold<<UNDERLINE<< "\t\t\t\t\t\t Quiz "<<CLOSEUNDERLINE;
	gotoxy(20,9);
	cout <<"\t\t\t\t\t     " <<yellow<<UNDERLINE<<"Version:10.01"<<CLOSEUNDERLINE;
	gotoxy(20,10);
	cout << "\t\t\t\t\t    "<<green<<UNDERLINE<<"(Round: 1 - 4 )"<<CLOSEUNDERLINE<<cc<<cc;
	gotoxy(5,11);
	cout <<red<<bold "General Instructions:"<<cc<<cc;
	gotoxy(85,11);
	cout << purple<<bold"Marking Scheme:"<<cc<<cc;
	gotoxy(5,12);
	cout << "a.) This quiz has 4 rounds";
	gotoxy(85,12);
	cout << "i.) Each C.A. 10m";
	gotoxy(5,13);
	cout << "b.) Each group can answer 4 questions";
	gotoxy(85,13);
	cout << "ii.) Each W.A. -5m";
	gotoxy(5,14);
	cout << "c.) Two groups can attempt the quiz";
	gotoxy(85,14);
	cout << "iii.) Each U.A. 0m";
	gotoxy(5,15);
	cout << "d.) To Unattempt a question type letter 'u' other than the option.";
	gotoxy(85,15);
	cout << "iv.) Each B.A. 5m";
	gotoxy(5,16);
	cout<<"e.)Each question must be answered in 20 seconds(for originals)";
	gotoxy(5,17);
	cout<<"f.)Each bonus question must be answered in 05 seconds";
	gotoxy(25,21);
	cout<<cyan<<bold<< "Used Short Abbreviations:"<<cc;
	gotoxy(85,21);
	cout<<Yellow <<"New Improvements and bug fixes:"<<cc;
	gotoxy(25,22);
	cout<<"1.) C.A. = Correct answer";
	gotoxy(85,22);
	cout<<"1.) SOURCE CODE VIEW";
	gotoxy(25,23);
	cout<<"2.) W.A. = Wrong answer";
	gotoxy(85,23);
	cout<<"3.) U.A. = Unattempted answer";
	gotoxy(85,24);
	cout<<"4.) B.A. = Bonus answer";
	gotoxy(85,27);
	cout<<green<<bold<<"QUIZ MASTER: Subhajit Halder";
	gotoxy(25,27);
	cout<<blue<<bold"Developer: Subhajit Halder";
	gotoxy(55,30);
	cout<<"\x1B[31m<<Press ENTER to Continue>>\033[0m";
	int ch = getCharWithClock(55,30, "");
	if(ch==105) about();
	else if(ch==101) evaluator();
	else if(ch==99) cheatcode();
	else printrndone();
	return 0;
}

void timerO ()
{
	int a = 15;
	while( a >=0 )
	{
		gotoxy(70,8);
		cout << "TIME LEFT: " <<setw(2) <<a <<"sec(s)"<<endl;
		sleep(1);
		a--;
		if(a==5) {
			cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
			cout<<red<<bold;
		}
		else if(a==-1) {
			gotoxy(5,14);
			cout<<"TIME OUT";
			cout<<cc<<cc;
			gotoxy(5,15);
			cout<<"Enter your answer:";
		}
	}
}

void timerB ()
{
	int a = 10;
	while( a >=0 )
	{
		gotoxy(70,8);
		cout << "TIME LEFT: "<<setw(2) << a <<"sec(s)"<<endl;
		sleep(1);
		a--;
		if(a==5) {
			cout<<"\a\a\a\a\a\a\a\a\a\a\a\a\a\a"<<flush;
			cout<<red<<bold;
		}
		else if(a==-1) {
			gotoxy(5,21);
			cout<<"TIME OUT";
			cout<<cc<<cc;
			gotoxy(5,22);
			cout<<"Enter your answer:";
		}
	}
}

//Quadratic equation Solver
void quad_eqn_solve()
{
	gotoxy(1,1);
	layout();
	gotoxy(5,8);
	cout<<green<<bold<<UNDERLINE<<"Welcome to Quadratic Eqn Solver Ver: 1.0"<<CLOSEUNDERLINE<<endl;
	gotoxy(5,9);
	cout<<Yellow<<bold<<"Your equations must be in the form of ax^2+bx+c=0"<<cc<<cc;
	double d,a,b,c,r1,r2;
	gotoxy(5,11);
	a = getDoubleWithClock(5,11, string(blue) + string(bold) + "Enter coefficient of x^2 (a): " + cc);
	gotoxy(5,12);
	b = getDoubleWithClock(5,12, string(blue) + string(bold) + "Enter coefficient of x (b): " + cc);
	gotoxy(5,13);
	c = getDoubleWithClock(5,13, string(blue) + string(bold) + bold + "Enter the constant term(c): " + cc);
	d=pow(b,2)- 4*a*c;
	double di=sqrt(d);
	r1=(-b+di)/(2*a);
	r2=(-b-di)/(2*a);
	cout<<RED<<bold;
	if(d==0) {
		gotoxy(5,15);
		cout<<RED<<bold"Equation you entered is having real and equal roots. Roots are: "<<r1<<" and "<<r2;
	}
	else if(d>0) {
		gotoxy(5,15);
		cout<<"Equation you entered id having real and unequal roots. Roots are: "<<r1<<" and "<<r2;
		gotoxy(5,16);
		cout<<"It may happen that the answer provided by computer is not matching. Possible reasons are:";
		gotoxy(5,17);
		cout<<"a.) The answer has imperfect square numbers";
		gotoxy(5,18);
		cout<<"b.) The answer may contain certain fractions, hence nearest whole number will be multiplied in that case automatically";
	}
	else {
		gotoxy(5,15);
		cout<<"Equation you entered is having imaginary roots.";
	}
	cout<<cc<<cc;
	waitForAnyKey();
	prompt();
}

//Area of triangle with coordinates
void atc()
{
	gotoxy(1,1);
	layout();
	double x1,y1,x2,y2,x3,y3,area;
	// First coordinate
	string prompt1 = string(blue) + bold + "Enter the first coordinate:" + cc;
	getTwoDoublesWithClock(x1, y1, 5, 10, prompt1);
	// Second coordinate
	string prompt2 = string(blue) + bold + "Enter the second coordinate:" + cc;
	getTwoDoublesWithClock(x2, y2, 5, 11, prompt2);
	// Third coordinate
	string prompt3 = string(blue) + bold + "Enter the third coordinate:" + cc;
	getTwoDoublesWithClock(x3, y3, 5, 12, prompt3);
	area = 0.5 * ((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)));
	gotoxy(5,13);
	cout<<Yellow<<bold"Area:";
	if(area>=0) cout<<area;
	else cout<<-area;
	cout<<cc<<cc;
	waitForAnyKey();
	prompt();
}