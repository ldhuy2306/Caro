#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <conio.h>
#include <Windows.h>
//Group: 06 (18APCS2)
/*Members: +Lam Duc Huy (ID: 18125131)
		   +Huynh Mac Khai (ID: 18125084)
		   +Le Tuan Khanh (ID: 18125087)*/
		   //Project: GOMOKU

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
using namespace std;

//Menu
void menu(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
void select(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
// board
void drawbroad(int t, int h);
void setchess(int n, int board[109][109], bool cont);
void check(int y, int x, int board[109][109], int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3);
// PvP
void gameplay(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
void again(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
//statictics
void statistics(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
// save and load
void save(int n, int w, int l, int board[109][109]/*, int bo*/, bool cont);
void load(int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont);
//PvC
void check2(int y, int x, int board[109][109], int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
void again2(int n, int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
void PvC(int n, int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
void Comturn(int n, int board[109][109], int w, int l, char m1, char m2, char m3, int b, int d, int w1, int w2, int w3, int draw, bool cont, int full);
int checkpoint(int y, int x, int board[109][109], int n);
int verticalAtkp(int y, int x, int board[109][109], int n);
int horizontalAtkp(int y, int x, int board[109][109], int n);
int crosshAtkp(int y, int x, int board[109][109], int n);
int crosssAtkp(int y, int x, int board[109][109], int n);
int verticalDefp(int y, int x, int board[109][109], int n);
int horizontalDefp(int y, int x, int board[109][109], int n);
int crosshDefp(int y, int x, int board[109][109], int n);
int crosssDefp(int y, int x, int board[109][109], int n);
void gotoxy(int x, int y);

#endif