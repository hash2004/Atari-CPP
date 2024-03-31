#include "menu.h"
menu::menu()
{
	controls = 0;
	highScore = 0;
	credits = 0;
	playerMODE = 0;
	levels[0] = true;
	levels[1] = false;
	levels[2] = false;//the levels bool was used to shift between levels
	vehicle[0] = true;//the vehicle bool array was used , however not successfully
	vehicle[1] = false;
	vehicle[2] = true;
}
void menu::offmenu(int a)
{
	levels[a - 1] = false;
}
void menu:: setControls(bool a)
{
	controls = a;
}
bool  menu:: getContorls()
{
	return controls;
}

void  menu::setHighScore(bool a)
{
	controls = a;
}
bool  menu::getHighScore()
{
	return highScore;
}

void  menu::setCredits(bool a)
{
	credits = a;
}
bool  menu::getCredits()
{
	return credits;
}

void menu:: setplayerMODE(bool a)
{
	playerMODE = a;
}
bool menu::getplayerMODE()
{
	return playerMODE;
}

bool menu::getLevel(int a)
{
	return levels[a - 1];
}
void menu::setLevel(int a)
{
	levels[a - 1] = true;
}
void menu::setv(int a)
{
	vehicle[a] = true;
}
bool menu::getv(int a)
{
	return vehicle[a-1];
}
void menu::offv(int a)//used to tunr off the functionality of other levels
{
	vehicle[a] = false;
}