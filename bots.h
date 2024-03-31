#pragma once
#include "util.h"
#include "butllets.h"
#include "menu.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath>
using namespace std;
class bot 
{

	bool botFlag;
	int destinationCounter;
	int destination;
	int botX;
	int botY;
public:

	bot();
	bot(int a,int b);
	bot(int c);

	void setBotFlag(bool a);
	bool getBotFlag();

	void setDestinationCounter(int a);
	int getDestinationCounter();

	void setDestination(int a);
	int getDestination();

	void setbotX(int a);
	int getBotX();

	void setbotY(int a);
	int getbotY();

	void moveBot(int level);



};