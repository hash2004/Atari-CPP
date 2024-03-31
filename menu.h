#pragma once
#include "util.h"
#include "butllets.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath>
using namespace std;
class menu
{
	bool controls;
	bool highScore;
	bool credits;
	bool playerMODE;
	bool levels[3];
	bool vehicle[3];
public:
	menu();
	void setControls(bool a);
	bool getContorls();
	void setHighScore(bool a);
	bool getHighScore();
	void setCredits(bool a);
	bool getCredits();
	void setplayerMODE(bool a);
	bool getplayerMODE();
	bool getLevel(int a);
	void setLevel(int a);
	void offmenu(int a);
	bool getv(int a);
	void setv(int a);
	void offv(int a);
};