#include "coldet.h"
coldets ::coldets(int lvl,bullet *a, players* play)
{
	lv = lvl;
	bakar = a;
	player = play;

}
void coldets::bGoLeft(int xb, int yb1, int yb2)
{//in this function, we get the minumum x value and the range of y, if it falls between that, it is deflected to left.
	if ((*bakar).getbCoorX() == xb && (*bakar).getbCoorY() >= yb1 && (*bakar).getbCoorY() <= yb2)
	{
		int tem = (*bakar).getbCoorX() - 5;
		(*bakar).setbCoorX(tem);
		(*bakar).setDirFlag(1);

		int t = (*bakar).getDeflectionCounter();
		(*bakar).setDeflectionCounter(t + 1);

		if ((*bakar).getbMCoorX() == xb && (*bakar).getbMCoorY() >= yb1 && (*bakar).getbMCoorY() <= yb2)
		{
			(*bakar).setbMCoorX((*bakar).getbMCoorX() - 5);
			(*bakar).setDirFlag(0);
			
			int t = (*bakar).getdfcounter();
			(*bakar).setdfcounter(t + 1);
		}
	}
}
void coldets :: bGoRight(int xb, int yb1, int yb2)
{
	// in this function, we get the max x valueand the range of y, if it falls between that, it is deflected to right.
	if ((*bakar).getbCoorX() == xb && (*bakar).getbCoorY() >= yb1 && (*bakar).getbCoorY() <= yb2)
	{
		int tem = (*bakar).getbCoorX() + 5;
		(*bakar).setbCoorX(tem);
		(*bakar).setDirFlag(0);

		int t = (*bakar).getDeflectionCounter();
		(*bakar).setDeflectionCounter(t + 1);

		if ((*bakar).getbMCoorX() == xb && (*bakar).getbMCoorY() >= yb1 && (*bakar).getbMCoorY() <= yb2)
		{
			(*bakar).setbMCoorX((*bakar).getbMCoorX() + 5);
			(*bakar).setDirFlag(0);

			int t = (*bakar).getdfcounter();
			(*bakar).setdfcounter(t + 1);
		}
	}
}
void coldets::bGoDown(int xb1, int xb2, int yb)
{//in this function, we get the range of x, and min y value, if it falls between that, it is deflected down
	if ((*bakar).getbCoorX() >= xb1 && (*bakar).getbCoorX() <= xb2 && (*bakar).getbCoorY() == yb)
	{
		(*bakar).setbCoorY((*bakar).getbCoorY() - 5);
		(*bakar).setDirFlag(4);
		int t = (*bakar).getDeflectionCounter();
		(*bakar).setDeflectionCounter(t + 1);
	}
	if ((*bakar).getbMCoorX() >= xb1 && (*bakar).getbMCoorX() <= xb2 && (*bakar).getbMCoorY() == yb)
	{
		(*bakar).setbMCoorY((*bakar).getbMCoorY() - 5);
		(*bakar).setDirFlag(4);

		int t = (*bakar).getdfcounter();
		(*bakar).setdfcounter(t + 1);
	}
}
void coldets::bGoUp(int xb1, int xb2, int yb)
{//in this function, we get the range of x, and max y value, if it falls between that, it is deflected up
	if ((*bakar).getbCoorX() >= xb1 && (*bakar).getbCoorX() <= xb2 && (*bakar).getbCoorY() == yb)
	{
		(*bakar).setbCoorY((*bakar).getbCoorY() + 5);
		(*bakar).setDirFlag(3);
		int t = (*bakar).getDeflectionCounter();
		(*bakar).setDeflectionCounter(t + 1);
	}
	if ((*bakar).getbMCoorX() >= xb1 && (*bakar).getbMCoorX() <= xb2 && (*bakar).getbMCoorY() == yb)
	{
		(*bakar).setbMCoorY((*bakar).getbMCoorY() + 5);
		(*bakar).setDirFlag(0);

		int t = (*bakar).getdfcounter();
		(*bakar).setdfcounter(t + 1);
	}
}
void coldets::colsdetsMAPo()
{//collision detection for map3
	for (int collision_counter_xA = 120; collision_counter_xA < 240; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 730 && (*player).getY() < 760)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 120; collision_counter_xA < 240; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 780 && (*player).getY() > 740)
			(*player).setY((*player).getY() + 10);
	}
	for (int collision_counter_xA = 400; collision_counter_xA < 960; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 730 && (*player).getY() < 760)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 400; collision_counter_xA < 960; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 780 && (*player).getY() > 740)
			(*player).setY((*player).getY() + 10);
	}

	for (int collision_counter_xA = 120; collision_counter_xA < 205; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 580 && (*player).getY() < 610)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 120; collision_counter_xA < 205; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 620 && (*player).getY() > 590)
			(*player).setY((*player).getY() + 10);
	}

	for (int collision_counter_xA = 240; collision_counter_xA < 720; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 180 && (*player).getY() < 210)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 240; collision_counter_xA < 720; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 220 && (*player).getY() > 190)
			(*player).setY((*player).getY() + 10);
	}

	for (int collision_counter_xA = 360; collision_counter_xA < 880; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 280 && (*player).getY() < 310)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 360; collision_counter_xA < 880; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 320 && (*player).getY() > 290)
			(*player).setY((*player).getY() + 10);
	}

	for (int collision_counter_xA = 560; collision_counter_xA < 805; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 580 && (*player).getY() < 610)
			(*player).setY((*player).getY() - 10);
	}
	for (int collision_counter_xA = 560; collision_counter_xA < 805; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() < 620 && (*player).getY() > 590)
			(*player).setY((*player).getY() + 10);
	}

	//for blocks with height much longer than width, we will use x coordinate to stpp the car
	for (int collision_counter_xA = 800; collision_counter_xA < 840; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 395 && (*player).getY() < 700)
			(*player).setX((*player).getX() - 10);
	}
	for (int collision_counter_xA = 840; collision_counter_xA < 841; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 399 && (*player).getY() < 700)
			(*player).setX((*player).getX() + 10);
	}

	for (int collision_counter_xA = 80; collision_counter_xA < 120; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 45 && (*player).getY() < 550)
			(*player).setX((*player).getX() - 10);
	}
	for (int collision_counter_xA = 120; collision_counter_xA < 121; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 49 && (*player).getY() < 550)
			(*player).setX((*player).getX() + 10);
	}

	for (int collision_counter_xA = 280; collision_counter_xA < 320; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 445 && (*player).getY() < 570)
			(*player).setX((*player).getX() - 10);
	}
	for (int collision_counter_xA = 320; collision_counter_xA < 321; collision_counter_xA++)
	{
		if ((*player).getX() == collision_counter_xA && (*player).getY() > 449 && (*player).getY() < 570)
			(*player).setX((*player).getX() + 10);
	}

	//collision detection for boundaries
	if ((*player).getX() < 2)
	{
		(*player).setX(980);

	}
	if ((*player).getX() > 980)
	{
		(*player).setX(10);
	}
	if ((*player).getY() > 820)
	{
		(*player).setY(5);

	}
	if ((*player).getY() < 1)
	{
		(*player).setX(820);
	}
}
void coldets::colsdetsMAPi()
{//for map 2
	if ((*player).getX() == 150 && (*player).getY() >= 200 && (*player).getY() <= 250)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() == 550 && (*player).getY() >= 200 && (*player).getY() <= 250)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() >= 150 && (*player).getX() <= 550 && (*player).getY() <=250 && (*player).getY() >= 230)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() >= 150 && (*player).getX() <= 550 && (*player).getY() >= 200 && (*player).getY() <= 225)
		(*player).setY((*player).getY() - 15);


	if ((*player).getX() == 500 && (*player).getY() >= 650 && (*player).getY() <= 700)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() == 900 && (*player).getY() >= 650 && (*player).getY() <= 700)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() >= 500 && (*player).getX() <= 900 && (*player).getY() <=700 && (*player).getY() >= 680)
		(*player).setY((*player).getY() + 15);

	if ((*player).getX() >= 500 && (*player).getX() <= 900 && (*player).getY() >= 650 && (*player).getY() <= 675)
		(*player).setY((*player).getY() - 15);

	if ((*player).getX() < 2)
	{
		(*player).setX(980);

	}
	if ((*player).getX() > 980)
	{
		(*player).setX(10);
	}
	if ((*player).getY() > 820)
	{
		(*player).setY(5);

	}
	if ((*player).getY() < 1)
	{
		(*player).setX(820);
	}
}
void coldets::colsdetsMAPu()
{//map 3
	(*player).coll(550, 230, 150, 200);
	(*player).coll(850, 430, 450, 400);
	(*player).coll(950, 730, 150, 700);
	(*player).collY(180, 500, 150, 300);

	

	if ((*player).getX() < 2)
	{
		(*player).setX(980);

	}
	if ((*player).getX() > 980)
	{
		(*player).setX(10);
	}
	if ((*player).getY() > 820)
	{
		(*player).setY(5);

	}
	if ((*player).getY() < 1)
	{
		(*player).setX(820);
	}
}