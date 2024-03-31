#include "butllets.h"


bullet::bullet()
{
	bulletFlag = false;
	MbulletFLag = false;
	LbulletFLag = false;
	dirFlag = 0;
	deflectionCounter = 0;
	dfcounterM = 0;
	temp1 = 320;
	temp2 = 765;
	bCoorX = temp1;
	bCoorY = temp2;
	bMCoorX = 375;
	bMCoorY = 750;
	bLCoorX = 0;
	bLCoorY = 0;
	MbulletCounter = 0;
	LbulletCounter = 0;
}//standard getter setters

void bullet::setBulletFlag(bool a)
{
	bulletFlag = a;
}
bool bullet::getBulletFlag()
{
	return bulletFlag;
}

void bullet::setbCoorX(int a)
{
	bCoorX = a;
}
int bullet::getbCoorX()
{
	return bCoorX;
}
void bullet::setbCoorY(int a)
{
	bCoorY = a;
}
int bullet::getbCoorY()
{
	return bCoorY;
}

void bullet::setbMCoorX(int a)
{
	bMCoorX = a;
}
int bullet::getbMCoorX()
{
	return bMCoorX;
}
void bullet::setbMCoorY(int a)
{
	bMCoorY = a;
}
int bullet::getbMCoorY()
{
	return bMCoorY;
}

void bullet::setDirFlag(int a)
{
	dirFlag = a;
}
int bullet::getDirFlag()
{
	return dirFlag;
}

void bullet::setDeflectionCounter(int a)
{
	deflectionCounter = a;
}
int bullet::getDeflectionCounter()
{
	return deflectionCounter;
}

void bullet::setdfcounter(int a)
{
	dfcounterM = a;
}
int bullet::getdfcounter()
{
	return dfcounterM;
}