#include"Function.h"

int n, board[109][109];
// MENU
void menu(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	select(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
}

void select(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	int c;
	cout << "1-Play\n2-Options\n3-Credits\n4-Exit\n\nSelect: ";
	cin >> c;

	system("cls");

	switch (c)
	{
		// PLAY
	case 1:
	{
		cout << "1/P-P mode\n2/P-C mode\n3/Load saved game\n4/Statistics\n5/Back\n\nSelect: ";
		cin >> c;

		system("cls");

		// Gamemode

		switch (c)
		{
		case 1:
		{
			n = 20;
			system("cls");
			again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			system("pause");
		}
		case 2:
		{

			n = 20;
			system("cls");
			again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			system("pause");
		}
		case 3:
		{
			load(board, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont);
			break;
		}
		case 4:
		{
			statistics(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 5:
		{
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		}
		break;
	}

	case 2:
	{
		cout << "OPTIONS\n";
		cout << "1/Change players signs\n2/Adjust board sides\n3/Change rule\n4/Back\n\nSelect: ";
		cin >> c;

		system("cls");

		//Your choice

		switch (c)
		{
		case 1:
		{
			char k = 127;
			cout << "Player 1's sign: " << endl;
			cout << "1/" << k << "\n2/@\n3/X\n4/O\n\nSelect: ";
			cin >> c;
			if (c == 1) m1 = 127; // ☐
			if (c == 2) m1 = 64; // @
			if (c == 3) m1 = 88; // X
			if (c == 4) m1 = 79; // O
			system("cls");
			cout << "Player 2's sign" << endl;
			cout << "1/" << k << "\n2/@\n3/X\n4/O\n\nSelect: ";
			cin >> c;
			if (c == 1) m2 = 127; // ☐
			if (c == 2) m2 = 64; // @
			if (c == 3) m2 = 88; // X
			if (c == 4) m2 = 79; // O
			system("cls");
			if (d == 1) // Player 3
			{
				cout << "Player 3's sign" << endl;
				cout << "1/" << k << "\n2/@\n3/X\n4/O\n\nSelect: ";
				cin >> c;
				if (c == 1) m3 = 127; // ☐
				if (c == 2) m3 = 64; // @
				if (c == 3) m3 = 88; // X
				if (c == 4) m3 = 79; // O
				system("cls");
			}
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 2:
		{
			cout << "BOARD" << endl;
			cout << "Number of rows: ";
			cin >> w;
			cout << "Number of columns: ";
			cin >> l;
			system("cls");
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 3:
		{
			cout << "Rule\n6-in-a-row mode: \n1/On\n2/Off\nSelect: ";
			cin >> b;
			system("cls");
			cout << "Rule\n3-Player mode: \n1/On\n2/Off\nSelect: ";
			cin >> d;
			system("cls");
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 4:
		{
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		}
		break;
	}

	case 3:
	{
		cout << "-- Group06 --\n";
		cout << "-Members:\n";
		cout << "+Lam Duc Huy (ID: 18125131)\n";
		cout << "+Huynh Mac Khai (ID: 18125084)\n";
		cout << "+Le Tuan Khanh (ID: 18125087)\n";
		system("pause");
		system("cls");
		menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);	}

	case 4: exit(0);
	}
	system("pause");
} // Options
// Draw Board
void drawbroad(int t, int h)
{
	int i;
	// Upper Edge
	printf("%c", 201);
	for (i = 1; i < t; i++)
		printf("%c%c%c%c", 205, 205, 205, 209);
	printf("%c%c%c%c\n", 205, 205, 205, 187);

	// Middle Part
	for (i = 1; i < h; i++)
	{
		//EMPT line
		printf("%c", 186);
		for (int o = 1; o < t; o++)
			printf("   %c", 179);
		printf("   %c\n", 186);

		// SP line
		printf("%c", 199);
		for (int o = 1; o < t; o++)
			printf("%c%c%c%c", 196, 196, 196, 197);
		printf("%c%c%c%c\n", 196, 196, 196, 182);
	}

	// Lower Edge
	printf("%c", 186);
	for (int o = 1; o < t; o++)
		printf("   %c", 179);
	printf("   %c\n", 186);
	printf("%c", 200);
	for (int i = 1; i < t; i++)
		printf("%c%c%c%c", 205, 205, 205, 207);
	printf("%c%c%c%c\n", 205, 205, 205, 188);
}

void setchess(int n, int board[109][109], bool cont) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			board[i][j] = 0;
		}
	}
}
//PVP or 3P
void check(int y, int x, int board[109][109], int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{

	int c;
	int ver = 0, hor = 0, crossh = 0, crosss = 0;
	int way0 = 0, way180 = 0, way45 = 0, way225 = 0, way270 = 0, way90 = 0, way135 = 0, way315 = 0;

	if (board[y][x] == 1)
	{// check how many X
		for (int i = 1; i <= 6; i++)
		{
			//check all 8 direction clockwise
			if (board[y + i][x] == board[y][x] && way0 == 0) ver++;//0
			if (board[y + i][x] != board[y][x]) way0 = 1;
			if (board[y - i][x] == board[y][x] && way180 == 0) ver++;//180
			if (board[y - i][x] != board[y][x]) way180 = 1;
			if (board[y + i][x + i] == board[y][x] && way45 == 0) crosss++;//45
			if (board[y + i][x + i] != board[y][x]) way45 = 1;
			if (board[y - i][x - i] == board[y][x] && way225 == 0) crosss++;//225
			if (board[y - i][x - i] != board[y][x]) way225 = 1;
			if (board[y][x - i] == board[y][x] && way270 == 0) hor++;//270
			if (board[y][x - i] != board[y][x]) way270 = 1;
			if (board[y][x + i] == board[y][x] && way90 == 0) hor++; //90
			if (board[y][x + i] != board[y][x]) way90 = 1;
			if (board[y - i][x + i] == board[y][x] && way135 == 0) crossh++;//135
			if (board[y - i][x + i] != board[y][x]) way135 = 1;
			if (board[y + i][x - i] == board[y][x] && way315 == 0) crossh++;//315
			if (board[y + i][x - i] != board[y][x]) way315 = 1;

		}
	}

	if (board[y][x] == -1)
	{// check how many 0
		for (int i = 1; i <= 6; i++)
		{
			// Check Block 2 ends 
		//check all 8 direction clockwise
			if (board[y + i][x] == board[y][x] && way0 == 0) ver++;//0
			if (board[y + i][x] != board[y][x]) way0 = 1;
			if (board[y - i][x] == board[y][x] && way180 == 0) ver++;//180
			if (board[y - i][x] != board[y][x]) way180 = 1;
			if (board[y + i][x + i] == board[y][x] && way45 == 0) crosss++;//45
			if (board[y + i][x + i] != board[y][x]) way45 = 1;
			if (board[y - i][x - i] == board[y][x] && way225 == 0) crosss++;//225
			if (board[y - i][x - i] != board[y][x]) way225 = 1;
			if (board[y][x - i] == board[y][x] && way270 == 0) hor++;//270
			if (board[y][x - i] != board[y][x]) way270 = 1;
			if (board[y][x + i] == board[y][x] && way90 == 0) hor++; //90
			if (board[y][x + i] != board[y][x]) way90 = 1;
			if (board[y - i][x + i] == board[y][x] && way135 == 0) crossh++;//135
			if (board[y - i][x + i] != board[y][x]) way135 = 1;
			if (board[y + i][x - i] == board[y][x] && way315 == 0) crossh++;//315
			if (board[y + i][x - i] != board[y][x]) way315 = 1;
		}
	}

	if (board[y][x] == 2) // Player 3
	{// check how many 0
		for (int i = 1; i <= 6; i++)
		{
			// Check Block 2 ends 
		//check all 8 direction clockwise
			if (board[y + i][x] == board[y][x] && way0 == 0) ver++;//0
			if (board[y + i][x] != board[y][x]) way0 = 1;
			if (board[y - i][x] == board[y][x] && way180 == 0) ver++;//180
			if (board[y - i][x] != board[y][x]) way180 = 1;
			if (board[y + i][x + i] == board[y][x] && way45 == 0) crosss++;//45
			if (board[y + i][x + i] != board[y][x]) way45 = 1;
			if (board[y - i][x - i] == board[y][x] && way225 == 0) crosss++;//225
			if (board[y - i][x - i] != board[y][x]) way225 = 1;
			if (board[y][x - i] == board[y][x] && way270 == 0) hor++;//270
			if (board[y][x - i] != board[y][x]) way270 = 1;
			if (board[y][x + i] == board[y][x] && way90 == 0) hor++; //90
			if (board[y][x + i] != board[y][x]) way90 = 1;
			if (board[y - i][x + i] == board[y][x] && way135 == 0) crossh++;//135
			if (board[y - i][x + i] != board[y][x]) way135 = 1;
			if (board[y + i][x - i] == board[y][x] && way315 == 0) crossh++;//315
			if (board[y + i][x - i] != board[y][x]) way315 = 1;
		}
	}


	if (b == 2) // b to check 6 moves win or no
	{
		if (ver == 4) ver = 5;
		if (hor == 4) hor = 5;
		if (crossh == 4) crossh = 5;
		if (crosss == 4) crosss = 5;
	}

	// find the way have 4 X or 4 O
	if (ver >= 5 || hor >= 5 || crossh >= 5 || crosss >= 5)
	{
		system("Color 0B");
		//check if X or O win
		if (board[y][x] == 1)
		{
			w1++;
			system("cls");
			cout << "\n\n\n\n";
			cout << "                  PPPPPPP        11           www            WWW    III                                OXO           \n";
			cout << "                  PPP    PP    1111           WWW            WWW                                       XOX           \n";
			cout << "                  PPP     PP     11            WWW          WWW     III    NN NNNNN     SSSSSS        OXO            \n";
			cout << "                  PPP    PP      11            WWW    WW    WWW     III    NNNN  NNN   SS             XOX            \n";
			cout << "                  PPPPPPP        11             WWW  WWWW  WWW      III    NN     NN     SSSS         OXO            \n";
			cout << "                  PPP            11             WWW WW  WW WWW      III    NN     NN         SS                      \n";
			cout << "                  PPP           1111             WWW      WWW       III    NN     NN    SSSSSS       OXO             \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				n = 2;
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}

		}
		if (board[y][x] == -1)
		{

			w2++;
			system("cls");
			cout << "\n\n\n\n";
			cout << "                  PPPPPPP       2222222       www            WWW    III                                OXO            \n";
			cout << "                  PPP    PP    22     22      WWW            WWW                                       XOX            \n";
			cout << "                  PPP     PP         22        WWW          WWW     III    NN NNNNN     SSSSSS        OXO             \n";
			cout << "                  PPP    PP        22          WWW    WW    WWW     III    NNNN  NNN   SS             XOX             \n";
			cout << "                  PPPPPPP         22            WWW  WWWW  WWW      III    NN     NN     SSSS         OXO             \n";
			cout << "                  PPP           22              WWW WW  WW WWW      III    NN     NN         SS                       \n";
			cout << "                  PPP          222222222         WWW      WWW       III    NN     NN    SSSSSS       OXO              \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				n = 2;
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
		}
		if (board[y][x] == 2) // Player 3
		{
			w3++;
			system("cls");
			cout << "\n\n\n\n";
			cout << "                  PPPPPPP      333333        www            WWW    III                                OXO           \n";
			cout << "                  PPP    PP   33    33       WWW            WWW                                       XOX           \n";
			cout << "                  PPP     PP       33         WWW          WWW     III    NN NNNNN     SSSSSS        OXO            \n";
			cout << "                  PPP    PP      333          WWW    WW    WWW     III    NNNN  NNN   SS             XOX            \n";
			cout << "                  PPPPPPP          33          WWW  WWWW  WWW      III    NN     NN     SSSS         OXO            \n";
			cout << "                  PPP         33    33         WWW WW  WW WWW      III    NN     NN         SS                      \n";
			cout << "                  PPP          333333           WWW      WWW       III    NN     NN    SSSSSS       OXO             \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				n = 2;
				system("pause");
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("pause");
				system("cls");
				again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
		}

	}
	else if (full == w * l && ver < 5 && hor < 5 && crossh < 5 && crosss < 5)
	{
		draw++;
		system("cls");
		system("Color 0B");
		cout << "\n\n\n\n";
		cout << "                  DDDDDDDD      RRRRRRRR          AAA      www            WWW         OXO            \n";
		cout << "                  DDD     DD    RRR     RR       AAAAA     www            WWW         XOX            \n";
		cout << "                  DDD      DD   RRR     RR      AA   AA     WWW          WWW         OXO             \n";
		cout << "                  DDD      DD   RRRRRRRR       AA     AA    WWW    WW    WWW         XOX             \n";
		cout << "                  DDD      DD   RRRRRR         AAAAAAAAA     WWW  WWWW  WWW          OXO             \n";
		cout << "                  DDD     DD    RRR  RRR      AAA     AAA    WWW WW  WW WWW                          \n";
		cout << "                  DDDDDDDD      RRR    RRR   AAA       AAA    WWW      WWW          OXO              \n\n\n\n";

		system("pause");
		system("cls");
		cout << "1 - Play again.\n";
		cout << "2 - Return to menu.\n";
		cout << "Select: ";
		cin >> c;
		if (c == 2)
		{
			cont = 0;
			system("cls");
			again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		if (c == 1)
		{
			system("cls");
			again(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
	}
}

void gameplay(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full) {
	HANDLE Output;
	COORD cursor;
	cursor.X = 2;
	cursor.Y = 4;
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, cursor);
	int i = 1;
	while (true)
	{
		//MOVEMENT
		int a = _getch();
		switch (a)
		{
		case 72: //U
			cursor.Y -= 2;
			break;
		case 75: //L
			cursor.X -= 4;
			break;
		case 77: //R
			cursor.X += 4;
			break;
		case 80: //D
			cursor.Y += 2;
			break;
		case 27: //ESC
		{
			system("Color 0B");
			system("cls");
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 115: //save current game
			save(n, w, l, board, cont);
		}
		int y = (cursor.Y + 1) / 2;
		int x = (cursor.X - 1) / 4 + 1;
		if (a == 13 && board[y][x] == 0 && y <= n && x <= n && i == 1)
		{
			board[y][x] = 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << m1;
			full++;
			i = -1;
		}

		if (a == 13 && board[y][x] == 0 && y <= n && x <= n && i == -1)
		{
			board[y][x] = -1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << m2;
			full++;
			if (d == 1)
				i = 2;
			else
				i = 1;
		}

		// Player 3
		if (d == 1)
			if (a == 13 && board[y][x] == 0 && y <= n && x <= n)
			{
				board[y][x] = 2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << m3;
				full++;
				i = 1;
			}

		check(y, x, board, n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		if (n == 1 || n == 2)
			Output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(Output, cursor);
	}
}

void again(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	if (n == 20)
	{
		setchess(n, board, cont);
		cout << " - - - Save game: s - - - - Return to menu: Esc - - -\n";
		cout << " - - - - - - Use arrow keys to move cursor  - - - - - \n";
		cout << " - P1's sign(" << m1 << "): Enter - - - P2's sign(" << m2 << "): Spacebar -";
		if (d == 1)
		{
			cout << "--P3's sign(" << m3 << "): m-";
		}
		cout << endl;
		drawbroad(w, l);
		gameplay(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
	}
	else menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
}
// Statistics
void statistics(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	cout << "|     Player1's wins     |        Player2's wins      |";
	if (d == 1) cout << "        Player3's Win         |";
	cout << "           Draws         |" << endl;
	cout << "|          " << w1 << "             |             " << w2 << "              |";
	if (d == 1) cout << "               " << w3 << "              |";
	cout << "           " << draw << "             |" << endl;
	cout << endl;
	system("pause");
	system("cls");
	menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
}
// Save and Load
void save(int n, int w, int l, int board[109][109]/*, int bo*/, bool cont)
{
	ofstream save;
	save.open("save.txt");
	save << w << endl;
	save << l << endl;
	for (int i = 2; i < 111; i++)
	{
		for (int t = 1; t < 110; t++)
			save << board[i][t] << " ";
		save << endl;
	}
	save.close();
	//		gotoXY(bo * 3 + 20, 8);
}

void load(int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont)
{
	ifstream load;
	load.open("save.txt");
	load >> w >> l;
	for (int i = 3; i < 112; i++)
	{
		for (int t = 0; t < 109; t++)
			load >> board[i][t];
	}
	setchess(n, board, cont);
	cout << " - - - Save game: s - - - - Return to menu: Esc - - -\n";
	cout << " - - - - - - Use arrow keys to move cursor  - - - - - \n";
	cout << " - P1's sign(" << m1 << "): Enter - - - P2's sign(" << m2 << "): Spacebar -";
	if (d == 1)
	{
		cout << "--P3's sign(" << m3 << "): m-";
	}
	cout << endl;
	drawbroad(w, l);

	HANDLE Output;
	COORD cursor;
	cursor.X = 2;
	cursor.Y = 4;
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, cursor);
	int y = (cursor.Y + 1) / 2;
	int x = (cursor.X - 1) / 4 + 1;
	for (int i = 0; i < 109; i++)
	{
		for (int t = 0; t < 109; t++)
		{
			if (board[i][t] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << m1;
			}
			if (board[i][t] == -1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << m2;
			}
		}
	}
	load.close();

	/*	if (n == 1 || n == 2)
			Output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(Output, cursor
		*/
}

// PVC
void gotoxy(int x, int y)
{
	HANDLE Output;
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, cursor);
}

void check2(int y, int x, int board[109][109], int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{

	int c;
	int ver = 0, hor = 0, crossh = 0, crosss = 0;
	int way0 = 0, way180 = 0, way45 = 0, way225 = 0, way270 = 0, way90 = 0, way135 = 0, way315 = 0;

	if (board[y][x] == 1)
	{// check how many X
		for (int i = 1; i <= 6; i++)
		{
			//check all 8 direction clockwise
			if (board[y + i][x] == board[y][x] && way0 == 0) ver++;//0
			if (board[y + i][x] != board[y][x]) way0 = 1;
			if (board[y - i][x] == board[y][x] && way180 == 0) ver++;//180
			if (board[y - i][x] != board[y][x]) way180 = 1;
			if (board[y + i][x + i] == board[y][x] && way45 == 0) crosss++;//45
			if (board[y + i][x + i] != board[y][x]) way45 = 1;
			if (board[y - i][x - i] == board[y][x] && way225 == 0) crosss++;//225
			if (board[y - i][x - i] != board[y][x]) way225 = 1;
			if (board[y][x - i] == board[y][x] && way270 == 0) hor++;//270
			if (board[y][x - i] != board[y][x]) way270 = 1;
			if (board[y][x + i] == board[y][x] && way90 == 0) hor++; //90
			if (board[y][x + i] != board[y][x]) way90 = 1;
			if (board[y - i][x + i] == board[y][x] && way135 == 0) crossh++;//135
			if (board[y - i][x + i] != board[y][x]) way135 = 1;
			if (board[y + i][x - i] == board[y][x] && way315 == 0) crossh++;//315
			if (board[y + i][x - i] != board[y][x]) way315 = 1;

		}
	}

	if (board[y][x] == -1)
	{// check how many 0
		for (int i = 1; i <= 6; i++)
		{
			// Check Block 2 ends 
		//check all 8 direction clockwise
			if (board[y + i][x] == board[y][x] && way0 == 0) ver++;//0
			if (board[y + i][x] != board[y][x]) way0 = 1;
			if (board[y - i][x] == board[y][x] && way180 == 0) ver++;//180
			if (board[y - i][x] != board[y][x]) way180 = 1;
			if (board[y + i][x + i] == board[y][x] && way45 == 0) crosss++;//45
			if (board[y + i][x + i] != board[y][x]) way45 = 1;
			if (board[y - i][x - i] == board[y][x] && way225 == 0) crosss++;//225
			if (board[y - i][x - i] != board[y][x]) way225 = 1;
			if (board[y][x - i] == board[y][x] && way270 == 0) hor++;//270
			if (board[y][x - i] != board[y][x]) way270 = 1;
			if (board[y][x + i] == board[y][x] && way90 == 0) hor++; //90
			if (board[y][x + i] != board[y][x]) way90 = 1;
			if (board[y - i][x + i] == board[y][x] && way135 == 0) crossh++;//135
			if (board[y - i][x + i] != board[y][x]) way135 = 1;
			if (board[y + i][x - i] == board[y][x] && way315 == 0) crossh++;//315
			if (board[y + i][x - i] != board[y][x]) way315 = 1;
		}
	}

	if (b == 1) // b to check 6 moves win or no
	{
		if (ver > 4) ver = 4;
		if (hor > 4) hor = 4;
		if (crossh > 4) crossh = 4;
		if (crosss > 4) crosss = 4;
	}

	// find the way have 4 X or 4 O
	if (ver == 4 || hor == 4 || crossh == 4 || crosss == 4)
	{
		system("Color 0B");
		//check if X or O win
		if (board[y][x] == 1)
		{
			w1++;
			system("cls");
			cout << "\n\n\n\n";
			cout << "                  PPPPPPP        11           www            WWW    III                                OXO           \n";
			cout << "                  PPP    PP    1111           WWW            WWW                                       XOX           \n";
			cout << "                  PPP     PP     11            WWW          WWW     III    NN NNNNN     SSSSSS        OXO            \n";
			cout << "                  PPP    PP      11            WWW    WW    WWW     III    NNNN  NNN   SS             XOX            \n";
			cout << "                  PPPPPPP        11             WWW  WWWW  WWW      III    NN     NN     SSSS         OXO            \n";
			cout << "                  PPP            11             WWW WW  WW WWW      III    NN     NN         SS                      \n";
			cout << "                  PPP           1111             WWW      WWW       III    NN     NN    SSSSSS       OXO             \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				n = 2;
				system("pause");
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("pause");
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}

		}
		if (board[y][x] == -1)
		{

			w2++;
			system("cls");
			cout << "\n\n\n\n";
			cout << "                  PPPPPPP       2222222       www            WWW    III                                OXO            \n";
			cout << "                  PPP    PP    22     22      WWW            WWW                                       XOX            \n";
			cout << "                  PPP     PP         22        WWW          WWW     III    NN NNNNN     SSSSSS        OXO             \n";
			cout << "                  PPP    PP        22          WWW    WW    WWW     III    NNNN  NNN   SS             XOX             \n";
			cout << "                  PPPPPPP         22            WWW  WWWW  WWW      III    NN     NN     SSSS         OXO             \n";
			cout << "                  PPP           22              WWW WW  WW WWW      III    NN     NN         SS                       \n";
			cout << "                  PPP          222222222         WWW      WWW       III    NN     NN    SSSSSS       OXO              \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				n = 2;
				system("pause");
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("pause");
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
		}
		else if (full == w * l && ver < 5 && hor < 5 && crossh < 5 && crosss < 5)
		{
			draw++;
			system("cls");
			system("Color 0B");
			cout << "\n\n\n\n";
			cout << "                  DDDDDDDD      RRRRRRRR          AAA      www            WWW         OXO            \n";
			cout << "                  DDD     DD    RRR     RR       AAAAA     www            WWW         XOX            \n";
			cout << "                  DDD      DD   RRR     RR      AA   AA     WWW          WWW         OXO             \n";
			cout << "                  DDD      DD   RRRRRRRR       AA     AA    WWW    WW    WWW         XOX             \n";
			cout << "                  DDD      DD   RRRRRR         AAAAAAAAA     WWW  WWWW  WWW          OXO             \n";
			cout << "                  DDD     DD    RRR  RRR      AAA     AAA    WWW WW  WW WWW                         \n";
			cout << "                  DDDDDDDD      RRR    RRR   AAA       AAA    WWW      WWW          OXO              \n\n\n\n";

			system("pause");
			system("cls");
			cout << "1 - Play again.\n";
			cout << "2 - Return to menu.\n";
			cout << "Select: ";
			cin >> c;
			if (c == 2)
			{
				cont = 0;
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}
			if (c == 1)
			{
				system("cls");
				again2(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			}

		}
	}
}

void again2(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	if (n == 20)
	{
		setchess(n, board, cont);
		cout << " - - - Save game: s - - - - Return to menu: Esc - - -\n";
		cout << " - - - - - - Use arrow keys to move cursor  - - - - - \n";
		cout << " - P1's sign(" << m1 << "): Enter - - - P2's sign(" << m2 << "): Spacebar -";
		cout << endl;
		drawbroad(w, l);
		PvC(n, board, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
	}
	else menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
}

void PvC(int n, int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	HANDLE Output;
	COORD cursor;
	cursor.X = 2;
	cursor.Y = 2;
	Output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Output, cursor);
	int i = 1;
	while (true)
	{
		//MOVEMENT
		int a = _getch();
		switch (a)
		{
		case 72: //U
			cursor.Y -= 2;
			break;
		case 75: //L
			cursor.X -= 4;
			break;
		case 77: //R
			cursor.X += 4;
			break;
		case 80: //D
			cursor.Y += 2;
			break;
		case 27: //ESC
		{
			system("Color 0B");
			system("cls");
			menu(n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		case 115: // save current game
			save(n, w, l, board, cont);

		}
		int y = (cursor.Y + 1) / 2;
		int x = (cursor.X - 1) / 4 + 1;
		if (a == 13 && (board[y][x]) == 0)
		{
			(board[y][x]) = 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << m1;
			full++;
			check2(y, x, board, n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
			Comturn(n, board, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
		}
		if (n == 1 || n == 2)
			Output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(Output, cursor);
	}
}

void Comturn(int n, int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full)
{
	int MaxP = 0, Temp = 0, maxx = 0, maxy = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (board[i][j] == 0)
				Temp = checkpoint(i, j, board, n);
			if (Temp > MaxP)
			{
				MaxP = Temp;
				maxx = j;
				maxy = i;
			}
		}
	}

	board[maxy][maxx] = -1;
	check2(maxy, maxx, board, n, w, l, m1, m2, m3, b, d, w1, w2, w3, draw, cont, full);
	maxx = (maxx - 1) * 4 + 2; //xm = (x - 1) / 4 + 1;
	maxy = maxy * 2;	   //ym = (y + 1) / 2;
	gotoxy(maxx, maxy);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << m2;
	full++;
}

int checkpoint(int y, int x, int board[109][109], int n)
{
	long Point;
	long AtkPoint = verticalAtkp(y, x, board, n) + horizontalAtkp(y, x, board, n) + crosshAtkp(y, x, board, n) + crosssAtkp(y, x, board, n);
	long DefPoint = verticalDefp(y, x, board, n) + horizontalDefp(y, x, board, n) + crosshDefp(y, x, board, n) + crosssDefp(y, x, board, n);

	if (DefPoint > AtkPoint)
		Point = DefPoint;
	else
		Point = AtkPoint;

	return Point;
}

int verticalAtkp(int y, int x, int board[109][109], int n)
{

	long AttackPoint[6] = { 0,9,54,162,1458,13112 };
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int ver = 0;

	int verE = 0;
	for (int i = 1; i < 6 && y + i < n; ++i)
	{
		if (board[y + i][x] == -1) ver++;//0
		else if (board[y + i][x] == 1)
		{
			verE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0; ++i)
	{
		if (board[y - i][x] == -1) ver++;//180
		else if (board[y + i][x] == 1)
		{
			verE++;
			break;
		}
		else break;
	}

	if (verE == 2)
		return 0;
	Total -= DefencePoint[verE] * 2;
	Total += AttackPoint[ver];
	return Total;
}

int horizontalAtkp(int y, int x, int board[109][109], int n)
{

	long AttackPoint[6] = { 0,9,54,162,1458,13112 };
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int hor = 0;
	int horE = 0;
	for (int i = 1; i < 6 && x + i < n; ++i)
	{
		if (board[y][x - i] == -1) hor++;//270
		else if (board[y][x - i] == 1)
		{
			horE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0; ++i)
	{
		if (board[y][x + i] == -1) hor++;//90
		else if (board[y][x - i] == 1)
		{
			horE++;
			break;
		}
		else break;
	}

	if (horE == 2)
		return 0;
	Total -= DefencePoint[horE] * 2;
	Total += AttackPoint[hor];
	return Total;
}

int crosshAtkp(int y, int x, int board[109][109], int n)
{

	long AttackPoint[6] = { 0,9,54,162,1458,13112 };
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int crossh = 0;
	int crosshE = 0;
	for (int i = 1; i < 6 && x + i < n&&y - i >= 0; ++i)
	{
		if (board[y - i][x + i] == -1) crossh++;//135
		else if (board[y - i][x + i] == 1)
		{
			crosshE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y + i < n&&x - i >= 0; ++i)
	{
		if (board[y + i][x - i] == -1) crossh++;//315
		else if (board[y + i][x - i] == 1)
		{
			crosshE++;
			break;
		}
		else break;
	}

	if (crosshE == 2)
		return 0;
	Total -= DefencePoint[crosshE] * 2;
	Total += AttackPoint[crossh];
	return Total;
}

int crosssAtkp(int y, int x, int board[109][109], int n)
{

	long AttackPoint[6] = { 0,9,54,162,1458,13112 };
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int crosss = 0;
	int crosssE = 0;
	for (int i = 1; i < 6 && x + i < n && y + i < n; ++i)
	{
		if (board[y + i][x + i] == -1) crosss++;//45
		else if (board[y + i][x + i] == 1)
		{
			crosssE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0 && x - i >= 0; ++i)
	{
		if (board[y - i][x - i] == -1) crosss++;//225
		else if (board[y - i][x - i] == 1)
		{
			crosssE++;
			break;
		}
		else break;
	}

	if (crosssE == 2)
		return 0;
	Total -= DefencePoint[crosssE] * 2;
	Total += AttackPoint[crosss];
	return Total;
}

int verticalDefp(int y, int x, int board[109][109], int n)
{
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int ver = 0;
	int verE = 0;

	for (int i = 1; i < 6 && y + i < n; ++i)
	{
		if (board[y + i][x] == 1) ver++;//0
		else if (board[y + i][x] == -1)
		{
			verE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0; ++i)
	{
		if (board[y - i][x] == 1) ver++;//180
		else if (board[y + i][x] == -1)
		{
			verE++;
			break;
		}
		else break;
	}

	if (verE == 2)
		return 0;
	Total += DefencePoint[ver];
	return Total;
}

int horizontalDefp(int y, int x, int board[109][109], int n)
{
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int hor = 0;
	int horE = 0;
	for (int i = 1; i < 6 && x + i < n; ++i)
	{
		if (board[y][x - i] == 1) hor++;//270
		else if (board[y][x - i] == -1)
		{
			horE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0; ++i)
	{
		if (board[y][x + i] == 1) hor++;//90
		else if (board[y][x - i] == -1)
		{
			horE++;
			break;
		}
		else break;
	}

	if (horE == 2)
		return 0;
	Total += DefencePoint[hor];
	return Total;
}

int crosshDefp(int y, int x, int board[109][109], int n)
{
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int crossh = 0;
	int crosshE = 0;
	for (int i = 1; i < 6 && x + i < n&&y - i >= 0; ++i)
	{
		if (board[y - i][x + i] == 1) crossh++;//135
		else if (board[y - i][x + i] == -1)
		{
			crosshE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y + i < n&&x - i >= 0; ++i)
	{
		if (board[y + i][x - i] == 1) crossh++;//315
		else if (board[y + i][x - i] == -1)
		{
			crosshE++;
			break;
		}
		else break;
	}

	if (crosshE == 2)
		return 0;
	Total += DefencePoint[crossh];
	return Total;
}

int crosssDefp(int y, int x, int board[109][109], int n)
{
	long DefencePoint[6] = { 0,3,27,99,729,6561 };
	long Total = 0;
	int crosss = 0;
	int crosssE = 0;
	for (int i = 1; i < 6 && x + i < n && y + i < n; ++i)
	{
		if (board[y + i][x + i] == 1) crosss++;//45
		else if (board[y + i][x + i] == -1)
		{
			crosssE++;
			break;
		}
		else break;
	}

	for (int i = 1; i < 6 && y - i >= 0 && x - i >= 0; ++i)
	{
		if (board[y - i][x - i] == 1) crosss++;//225
		else if (board[y - i][x - i] == -1)
		{
			crosssE++;
			break;
		}
		else break;
	}

	if (crosssE == 2)
		return 0;
	Total += DefencePoint[crosss];
	return Total;
}