#include<iostream>
#include <windows.h>
#include <vector>

using namespace std;

int game = 0;
int playerx = 0;
int playery = 0;
int bulletx = 0;
int bullety = 0;
char KeyPressed;
int enemyx = 70;
int enemyy = 20;
vector <int> PastPos;
vector <int> PastPosBullet;
vector <int> PastEnemyPost;
vector <int> noKeyPress;

void gotoxy(int x, int y){//http://www.dreamincode.net/forums/topic/66841-gotoxyint-x-int-y%3B/

	COORD coord; // coordinates
	coord.X = x; coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

void clear()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // gets the window handle
	COORD coord = { 0, 0 }; // sets coordinates to 0,0
	DWORD count;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi); // gets the buffer info (screen)

												// fill all characters as ' ' (empty the screen)
	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

	// resets the cursor position
	SetConsoleCursorPosition(hStdOut, coord);
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void shootPlayer(char key) {
	if (key == 'W') {
		for (int i = 0; i <= 40; i++) {
			bulletx = bulletx;
			bullety = bullety - 1;
			gotoxy(bulletx, bullety);
			cout << "*";
			PastPosBullet.push_back(bulletx);
			PastPosBullet.push_back(bullety);
			Sleep(50);
			gotoxy(PastPosBullet[0], PastPosBullet[1]);
			cout << " ";
			PastPosBullet.clear();
			if (bullety <= 1) {
				bullety = 1;
			}

		}

	}

	if (key == 'A') {
		for (int i = 0; i <= 40; i++) {
			bulletx = bulletx - 1;
			bullety = bullety;
			gotoxy(bulletx, bullety);
			cout << "*";
			PastPosBullet.push_back(bulletx);
			PastPosBullet.push_back(bullety);
			Sleep(50);
			gotoxy(PastPosBullet[0], PastPosBullet[1]);
			cout << " ";
			PastPosBullet.clear();
			if (bulletx <= 1) {
				bulletx = 1;
			}
		}

	}

	if (key == 'S') {
		for (int i = 0; i <= 40; i++) {
			bulletx = bulletx;
			bullety = bullety + 1;
			gotoxy(bulletx, bullety);
			cout << "*";
			PastPosBullet.push_back(bulletx);
			PastPosBullet.push_back(bullety);
			Sleep(50);
			gotoxy(PastPosBullet[0], PastPosBullet[1]);
			cout << " ";
			PastPosBullet.clear();
		}

	}

	if (key == 'D') {
		for (int i = 0; i <= 40; i++) {
			bulletx = bulletx + 1;
			bullety = bullety;
			gotoxy(bulletx, bullety);
			cout << "*";
			PastPosBullet.push_back(bulletx);
			PastPosBullet.push_back(bullety);
			Sleep(50);
			gotoxy(PastPosBullet[0], PastPosBullet[1]);
			cout << " ";
			PastPosBullet.clear();
		}

	}
}

void EnemeyMovement() {
	for (int i = 0; i <= 3; i++) {
		enemyx = enemyx + 1;
		enemyy = enemyy;
		gotoxy(enemyx, enemyy);
		cout << "O";
		PastEnemyPost.push_back(enemyx);
		PastEnemyPost.push_back(enemyy);
		Sleep(50);
		gotoxy(PastEnemyPost[0], PastEnemyPost[1]);
		cout << " ";
		PastEnemyPost.clear();
	}
	for (int i = 0; i <= 3; i++) {
		enemyx = enemyx - 1;
		enemyy = enemyy;
		gotoxy(enemyx, enemyy);
		cout << "O";
		PastEnemyPost.push_back(enemyx);
		PastEnemyPost.push_back(enemyy);
		Sleep(50);
		gotoxy(PastEnemyPost[0], PastEnemyPost[1]);
		cout << " ";
		PastEnemyPost.clear();
	}
}




void main() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	hidecursor();
	gotoxy(70, 20);
	cout << "O";
	//cout << "0";
	while (game == 0) {
		if (GetKeyState('W') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			KeyPressed = 'W';
			noKeyPress.clear();
			gotoxy(playerx, playery);
			cout << " ";
			while (GetKeyState('W') & 0x8000) {
				//if (playery < 0) {
				playerx = playerx;
				playery = playery - 1;
				gotoxy(playerx, playery);

				PastPos.push_back(playerx);
				PastPos.push_back(playery);

				cout << "0";
				Sleep(50);
				gotoxy(PastPos[0], PastPos[1]);
				cout << " ";
				PastPos.clear();
			}

		}
		

		if (GetKeyState('A') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			KeyPressed = 'A';
			noKeyPress.clear();
			gotoxy(playerx, playery);
			cout << " ";
			while (GetKeyState('A') & 0x8000) {
				playerx = playerx - 1;
				playery = playery;
				gotoxy(playerx, playery);

				PastPos.push_back(playerx);
				PastPos.push_back(playery);


				cout << "0";
				Sleep(50);
				gotoxy(PastPos[0], PastPos[1]);
				cout << " ";
				PastPos.clear();
			}
		}
		

		if (GetKeyState('S') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			KeyPressed = 'S';
			noKeyPress.clear();
			gotoxy(playerx, playery);
			cout << " ";
			while (GetKeyState('S') & 0x8000) {
				playerx = playerx;
				playery = playery + 1;
				gotoxy(playerx, playery);

				PastPos.push_back(playerx);
				PastPos.push_back(playery);


				cout << "0";
				Sleep(50);
				gotoxy(PastPos[0], PastPos[1]);
				cout << " ";
				PastPos.clear();
			}


		}

		if (GetKeyState('D') & 0x8000/*check if high-order bit is set (1 << 15)*/)
		{
			KeyPressed = 'D';
			noKeyPress.clear();
			gotoxy(playerx, playery);
			cout << " ";
			while (GetKeyState('D') & 0x8000) {
				playerx = playerx + 1;
				playery = playery;
				gotoxy(playerx, playery);

				PastPos.push_back(playerx);
				PastPos.push_back(playery);

				cout << "0";
				Sleep(50);
				gotoxy(PastPos[0], PastPos[1]);
				cout << " ";
				PastPos.clear();
			}

				
		}

		if (GetKeyState(VK_SPACE) & 0x8000) {
			bulletx = noKeyPress[0];
			bullety = noKeyPress[1];
			shootPlayer(KeyPressed);
		}
		noKeyPress.push_back(playerx);
		noKeyPress.push_back(playery);
		gotoxy(playerx,playery);
		cout << "0";
	



				//system("CLS");
			}
		}