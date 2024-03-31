#pragma once
#include "util.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath>
using namespace std;
class bullet
{
	bool bulletFlag;
	bool MbulletFLag;
	bool LbulletFLag;
	int dirFlag;
	int deflectionCounter;
	int dfcounterM;
	int temp1, temp2;//private data members
	int bCoorX;
	int bCoorY;
	int bMCoorX;
	int bMCoorY;
	int bLCoorX;
	int bLCoorY;
	int MbulletCounter;
	int LbulletCounter;
public:
	bullet();
	void setBulletFlag(bool a);
	bool getBulletFlag();
	//getters setters contructors
	void setbCoorX(int a);
	int getbCoorX();
	void setbCoorY(int a);
	int getbCoorY();

	void setbMCoorX(int a);
	int getbMCoorX();
	void setbMCoorY(int a);
	int getbMCoorY();

	void setDirFlag(int a);
	int getDirFlag();

	void setDeflectionCounter(int a);
	int getDeflectionCounter();

	void setdfcounter(int a);
	int getdfcounter();
};