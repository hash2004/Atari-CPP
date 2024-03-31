#pragma once
#include "player.h"
players ::players()
{
	xI = 300;
	yI = 760;
}
players::players(int a, int b)
{
	xI = a;
	yI = b;
}
void players :: setX(int a)
{
	xI = a;

}
int players :: getX()
{
	return xI;
}
void players::setY(int a)
{
	yI = a;
}
int players::getY()
{
	return yI;
}
void players::coll(int Mx, int My, int mx, int my)
{// in this function we get the max x, min x, max y, min y and use push car accordingly
	if (xI == Mx && yI <= My && yI >= my)
		yI += 10;

	if (xI == mx && yI <= My && yI >= my)
		yI += 10;

	if (xI >= mx && xI <= Mx && yI >= My-5 && yI<=My+5)
		yI += 10;

	if (xI >= mx && xI <= Mx && yI >= my - 5 && yI <= my + 5)
		yI -= 10;
}
void players::collY(int Mx, int My, int mx, int my)
{
	// in this function we get the max x, min x, max y, min y and use push car accordingly, but for blocks with higher height

	if (xI >=Mx-5 && xI<=Mx+5 && yI <= My && yI >= my)
		xI+= 10;

	if (xI >= mx-5 && xI<=mx+5 && yI <= My && yI >= my)
		xI -= 10;

	if (xI >= mx+5 && xI <= Mx+5 && yI <=Mx+5 && yI>=My+5)
		xI += 15;

	if (xI >= mx+5 && xI <= Mx+5 && yI <=mx+5 && yI>=mx-5)
		xI += 15;
}