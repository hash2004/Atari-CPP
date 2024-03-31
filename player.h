#pragma once
#include "util.h"
#include "butllets.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath>
using namespace std;
class players
{
	int xI;
	int yI;
public:
	players();
	players(int a, int b);
	void setX(int a);
	int getX();
	void setY(int a);
	int getY();
	void coll(int Mx, int My, int mx, int my);
	void collY(int Mx, int My, int mx, int my);

};