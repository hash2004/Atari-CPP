#pragma once
#include "util.h"
#include "menu.h"
#include "butllets.h"
#include "player.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath>
using namespace std;
class coldets : public bullet
{
	bullet* bakar;
	players* player;
	
	int lv;
public:
	coldets(int lvl,bullet *a,players* play);
	void bGoLeft(int xb, int yb1, int yb2);
	void bGoRight(int xb, int yb1, int yb2);//explained in cpp file
	void bGoDown(int xb1, int xb2, int yb);
	void bGoUp(int xb1, int xb2, int yb);
	void colsdetsMAPo();//for map3
	void colsdetsMAPi();//for map 2
	void colsdetsMAPu();//map1

	
};