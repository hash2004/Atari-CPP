//============================================================================
// Name        : .cpp
// Author      : Hashim M Nadeem
// Version     :  2022
// Copyright   : (c) Reserved 
// Description : ATARI
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include "menu.h"
#include "bots.h"
#include "player.h"
#include "butllets.h"
#include "coldet.h"
#include <iostream>
#include<string>
#include<sstream>  
#include <cstring>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
bot b13(0, 0);
bot b14(0, 0);
bot b15(0, 0);
bot b10(450, 450);
bot b11(300, 0);
bot b12(900, 0);
//the global variables used ,only score is useful, the rest were being used for additional features, which i could not complete
int BcanconCounter[] = { 0,1,3 };
bool powerupCounter = false;
int score = 0;
bool bulletarr[] = { false,false };//bullet//
int bulletcounters[] = { 0,0 };//
//int mediumbulletcoordinates[] = { xI + 25, yI - 10 };//
players pp;
bullet bb;
players p;
menu m1;
coldets testing(1,&bb,&pp);
players p2(300, 300);
bullet b;
coldets test(1, &b, &p2);

void deflect()
{
	//only gets deflected when the deflection counter is a multiple of 3 and not 0
	//we used not 0 because 0 is also multiple of 3
	if (bb.getDeflectionCounter() % 3 == 0 && bb.getDeflectionCounter() != 0)
	{
		bb.setBulletFlag(false);
	}
}

void deflectM()
{
	//medium bullet deflection
	if (bb.getdfcounter() % 3 == 0 && (bb.getdfcounter () != 0))
	{
	bulletcounters[0]++;
	}
}

void drawMediumBullet()
{//medium bullet drawing
	DrawSquare(bb.getbMCoorX(), bb.getbMCoorY(), 10, colors[LIGHT_GOLDEN_ROD_YELLOW]);
	glutPostRedisplay();

}
void drawBullet()
{//bullet drawing
	DrawSquare(bb.getbCoorX(), bb.getbCoorY(), 5, colors[LIGHT_GOLDEN_ROD_YELLOW]);
	glutPostRedisplay();
}
void drawBullet2()
{//2nd player bullet
	DrawSquare(b.getbCoorX(), b.getbCoorY(), 5, colors[LIGHT_GOLDEN_ROD_YELLOW]);
	glutPostRedisplay();
}
void drawEZbot()
{//bot for level 1
	DrawRectangle(b10.getBotX(), b10.getbotY(), 20, 20, colors[BLACK]);
}
void drawMbot()
{//bot for level 2
	DrawRectangle(b11.getBotX(), b11.getbotY(), 20, 20, colors[DARK_BLUE]);	
}
void drawMbot2()
{//bot for level2
	DrawRectangle(b12.getBotX(), b12.getbotY(), 20, 20, colors[DARK_BLUE]);
}
void drawBot1()
{//bot for level 3
	DrawRectangle(b13.getBotX(), b13.getbotY(), 20, 20, colors[RED]);
	glutPostRedisplay();
}
void drawBot2()
{//bot for level 3
	DrawRectangle(b14.getBotX(), b14.getbotY(), 20, 20, colors[RED]);
	glutPostRedisplay();
}
void drawBot3()
{//bot for level 3
	DrawRectangle(b15.getBotX(), b15.getbotY(), 20, 20, colors[RED]);
	glutPostRedisplay();
}

void drawCar() 
{//players car,//the conditons were for tanks,helicopters,planes
	if (m1.getv(0)==true)
	DrawSquare(pp.getX(), pp.getY(), 20, colors[WHITE]);
	if (m1.getv(1) == true)
		DrawSquare(pp.getX(), pp.getY(), 20, colors[RED]);
	if (m1.getv(3) == true)
		DrawSquare(pp.getX(), pp.getY(), 20, colors[WHITE]);
	glutPostRedisplay();
}
void drawp2()
{//player 2
	DrawSquare(p2.getX(), p2.getY(), 20, colors[WHITE]);
	glutPostRedisplay();
}
void coldet1()
{
	if (bb.getbCoorX() >= pp.getX() - 10 && bb.getbCoorX() <= pp.getX() + 10 && bb.getbCoorY() >= pp.getY() - 10 && bb.getbCoorY() <= pp.getY() + 10)
	{//players own bullet hits himself
		{
			if (bb.getDeflectionCounter() == 0 && bb.getDirFlag() == 1)
			{//this is for, when the direction is set to left, and the bullet is fired, it would hit itself, however in this case, we give no points
			}
			else
				score--;
		}
	}
	if (m1.getLevel(3) == true)
	{//collision detection between level 3 bots and bullet
		if (bb.getbCoorX() >= b13.getBotX() - 10 && bb.getbCoorX() <= b13.getBotX() + 10 && bb.getbCoorY() >= b13.getbotY() - 10 && bb.getbCoorY() <= b13.getbotY() + 10)
		{
			score += 5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}
		if (bb.getbCoorX() >= b14.getBotX() - 10 && bb.getbCoorX() <= b14.getBotX() + 10 && bb.getbCoorY() >= b14.getbotY() - 10 && bb.getbCoorY() <= b14.getbotY() + 10)
		{
			score += 5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}
		if (bb.getbCoorX() >= b15.getBotX() - 10 && bb.getbCoorX() <= b15.getBotX() + 10 && bb.getbCoorY() >= b15.getbotY() - 10 && bb.getbCoorY() <= b15.getbotY() + 10)
		{
			score += 5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}

		if (pp.getX() >= b13.getBotX() - 10 && pp.getX() <= b13.getBotX() + 10 && pp.getY() >= b13.getbotY() - 10 && pp.getY() <= b13.getbotY() + 10)
			score--;//if bot hits player, it gets minus points
		if (pp.getX() >= b14.getBotX() - 10 && pp.getX() <= b14.getBotX() + 10 && pp.getY() >= b14.getbotY() - 10 && pp.getY() <= b14.getbotY() + 10)
			score--;
		if (pp.getX() >= b15.getBotX() - 10 && pp.getX() <= b15.getBotX() + 10 && pp.getY() >= b15.getbotY() - 10 && pp.getY() <= b15.getbotY() + 10)
			score--;


		testing.bGoDown(120, 240, 750);// this function is explained in class
		testing.bGoUp(120, 240, 780);
		testing.bGoRight(240, 750, 780);//used for deflection of bullets
		testing.bGoLeft(120, 750, 780);

		testing.bGoLeft(400, 750, 780);
		testing.bGoRight(960, 750, 780);
		testing.bGoDown(400, 960, 750);
		testing.bGoUp(400, 960, 780);

		testing.bGoUp(240, 720, 230);
		testing.bGoDown(240, 720, 200);
		testing.bGoLeft(240, 200, 230);
		testing.bGoRight(720, 200, 230);

		testing.bGoLeft(120, 600, 630);
		testing.bGoRight(205, 600, 630);
		testing.bGoDown(120, 205, 600);
		testing.bGoUp(120, 205, 630);

		testing.bGoLeft(800, 400, 700);
		testing.bGoRight(840, 400, 700);
		testing.bGoDown(800, 840, 400);
		testing.bGoUp(800, 840, 700);

		testing.bGoRight(805, 600, 630);
		testing.bGoLeft(560, 600, 630);
		testing.bGoUp(560, 805, 630);
		testing.bGoDown(560, 805, 600);

		testing.bGoRight(120, 50, 550);
		testing.bGoLeft(80, 50, 550);
		testing.bGoUp(80, 120, 550);
		testing.bGoDown(80, 120, 50);

		testing.bGoLeft(360, 300, 330);
		testing.bGoRight(880, 300, 330);
		testing.bGoDown(360, 880, 300);
		testing.bGoUp(360, 880, 330);


		testing.bGoLeft(280, 450, 570);
		testing.bGoRight(320, 450, 570);
		testing.bGoDown(280, 320, 450);
		testing.bGoUp(280, 320, 570);

		testing.colsdetsMAPo();//obstacle  detection,explained in class
	}
	if (m1.getLevel(2) == true)
	{
		if (bb.getbCoorX() >= b11.getBotX() - 20 && bb.getbCoorX() <= b11.getBotX() + 20 && bb.getbCoorY() >= b11.getbotY() - 20 && bb.getbCoorY() <= b11.getbotY() + 10)
		{
			score += 5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}
		if (bb.getbCoorX() >= b12.getBotX() - 20 && bb.getbCoorX() <= b12.getBotX() + 20 && bb.getbCoorY() >= b12.getbotY() - 20 && bb.getbCoorY() <= b12.getbotY() + 10)
		{
			score += 5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}
		if (pp.getX() >= b11.getBotX() - 10 && pp.getX() <= b11.getBotX() + 10 && pp.getY() >= b11.getbotY() - 10 && pp.getY() <= b11.getbotY() + 10)
			score--;
		if (bb.getbCoorX() >= b12.getBotX() - 20 && bb.getbCoorX() <= b12.getBotX() + 20 && bb.getbCoorY() >= b12.getbotY() - 20 && bb.getbCoorY() <= b12.getbotY() + 10)
			score++;
		if (pp.getX() >= b12.getBotX() - 10 && pp.getX() <= b12.getBotX() + 10 && pp.getY() >= b12.getbotY() - 10 && pp.getY() <= b12.getbotY() + 10)
			score--;

		//DrawRectangle(150, 200, 400, 30, colors[DARK_BLUE]);
		testing.bGoLeft(150, 200, 230);
		testing.bGoRight(550, 200, 230);
		testing.bGoDown(150, 550, 200);
		testing.bGoUp(150, 550, 230);
		//DrawRectangle(450, 400, 400, 30, colors[DARK_BLUE]);
		testing.bGoLeft(450, 400, 430);
		testing.bGoRight(850, 400, 430);
		testing.bGoDown(450, 850, 400);
		testing.bGoUp(450, 850, 430);
		//DrawRectangle(150, 300, 30, 200, colors[DARK_BLUE]);
		testing.bGoLeft(150, 300, 500);
		testing.bGoRight(180, 300, 500);
		testing.bGoDown(150, 180, 300);
		testing.bGoUp(150, 180, 500);

		//	DrawRectangle(150, 700, 800, 30, colors[DARK_BLUE]);
		testing.bGoLeft(150, 700, 730);
		testing.bGoRight(950, 700, 730);
		testing.bGoDown(150, 950, 700);
		testing.bGoUp(150, 950, 730);

		testing.colsdetsMAPu();


	}
	if (m1.getLevel(1) == true )
	{
		if (bb.getbCoorX() >= b10.getBotX() - 20 && bb.getbCoorX() <= b10.getBotX() + 20 && bb.getbCoorY() >= b10.getbotY() - 20 && bb.getbCoorY() <= b10.getbotY() + 10)
		{
			score+=5;
			bb.setDeflectionCounter(0);
			bb.setBulletFlag(false);
		}

		if (pp.getX() >= b10.getBotX() - 10 && pp.getX() <= b10.getBotX() + 10 && pp.getY() >= b10.getbotY() - 10 && pp.getY() <= b10.getbotY() + 10)
			score--;
		testing.bGoLeft(150, 200, 250);
		testing.bGoRight(550, 200, 250);
		testing.bGoDown(150, 550, 200);
		testing.bGoUp(150, 550, 250);

		testing.bGoLeft(500, 650, 700);
		testing.bGoRight(900, 650, 700);
		testing.bGoDown(500, 900, 650);
		testing.bGoUp(500, 900, 700);

		testing.colsdetsMAPi();
		if (m1.getplayerMODE() == true)
		{
			if (bb.getbCoorX() >= p2.getX() - 20 && bb.getbCoorX() <= p2.getX() + 20 && bb.getbCoorY() >= p2.getY() - 20 && bb.getbCoorY() <=p2.getY() + 10)
			{
				cout << "Enter" << endl;
				score += 5;
				bb.setDeflectionCounter(0);
				bb.setBulletFlag(false);
			}
			if (b.getbCoorX() >= pp.getX() - 20 && b.getbCoorX() <= pp.getX() + 20 && b.getbCoorY() >= pp.getY() - 20 && b.getbCoorY() <= p2.getY() + 10)
			{
				b.setBulletFlag(false);

				cout << "enter" << endl;
				score += 1;
				b.setDeflectionCounter(0);
				b.setBulletFlag(false);
			}


			testing.bGoLeft(150, 200, 250);
			testing.bGoRight(550, 200, 250);
			testing.bGoDown(150, 550, 200);
			testing.bGoUp(150, 550, 250);
			testing.bGoLeft(500, 650, 700);
			testing.bGoRight(900, 650, 700);
			testing.bGoDown(500, 900, 650);
			testing.bGoUp(500, 900, 700);
			testing.colsdetsMAPi();

			test.bGoLeft(150, 200, 250);
			test.bGoRight(550, 200, 250);
			test.bGoDown(150, 550, 200);
			test.bGoUp(150, 550, 250);
			test.bGoLeft(500, 650, 700);
			test.bGoRight(900, 650, 700);
			test.bGoDown(500, 900, 650);
			test.bGoUp(500, 900, 700);
			test.colsdetsMAPi();
		}
	}
	
}

void moveBullet() 
{
	if (bb.getDirFlag() == 0)//bullet moves with direction, given from direction counter
		bb.setbCoorX(bb.getbCoorX() + 5);
	if (bb.getDirFlag() == 1)
		bb.setbCoorX(bb.getbCoorX() - 5);
	if (bb.getDirFlag() == 3)
		bb.setbCoorY(bb.getbCoorY() + 5);
	if (bb.getDirFlag() == 4)
		bb.setbCoorY(bb.getbCoorY() - 5);
}
void moveBullet2()
{
	if (b.getDirFlag() == 0)
		b.setbCoorX(b.getbCoorX() + 5);
	if (b.getDirFlag() == 1)
		b.setbCoorX(b.getbCoorX() - 5);
	if (b.getDirFlag() == 3)
		b.setbCoorY(b.getbCoorY() + 5);
	if (b.getDirFlag() == 4)
		b.setbCoorY(b.getbCoorY() - 5);
}
void MmoveBullet()
{
	if (bb.getDirFlag() == 0)
	{
		int temp = bb.getbMCoorX() + 5;
		bb.setbMCoorX(temp);
	}
	if (bb.getDirFlag() == 1)
	{
		int temp = bb.getbMCoorX() - 5;
		bb.setbMCoorX(temp);
	}
	if (bb.getDirFlag() == 3)
	{
		int temp = bb.getbMCoorY() + 5;
		bb.setbMCoorY(temp);
	}
	if (bb.getDirFlag() == 4)
	{
		int temp = bb.getbMCoorY() - 5;
		bb.setbMCoorY(temp);
	}
}
/*
 * Main Canvas drawing function.
 * */
string intToStr(int num)
{
	//this function is used to convert the score to string, before passing it to the drawsrtring function
	string str; 
	stringstream ss;
	ss << num;
	ss >> str;
	return str;

}

void GameDisplay1()/**/{

	if (m1.getLevel(3) == true)
	{
		// set the background color using function glClearColor.
		// to change the background play with the red, green and blue values below.
		// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors


		//Display Score
		DrawString(50, 800, intToStr(score / 5), colors[MISTY_ROSE]);

		for (int counter = 40; counter < 1000; counter = counter + 40)
		{
			DrawLine(counter, 0, counter, 1020, 2, colors[DARK_CYAN]);
		}
		//These Rectangles are the walls that the car cannot go through
		DrawRectangle(120, 750, 120, 30, colors[RED]);
		DrawRectangle(400, 750, 560, 30, colors[RED]);
		DrawRectangle(120, 600, 85, 30, colors[RED]);
		DrawRectangle(800, 400, 40, 300, colors[RED]);
		DrawRectangle(560, 600, 245, 30, colors[RED]);
		DrawRectangle(80, 50, 40, 500, colors[RED]);
		DrawRectangle(240, 200, 480, 30, colors[RED]);
		DrawRectangle(360, 300, 520, 30, colors[RED]);
		DrawRectangle(280, 450, 40, 120, colors[RED]);
		drawCar();
		drawBot1();
		drawBot3();
		drawBot2();
	}
	else if (m1.getLevel(2) == true)
	{
		glClearColor(0/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(50, 800, intToStr(score / 5), colors[MISTY_ROSE]);
		for (int counter = 40; counter < 1000; counter = counter + 40)
		{
			DrawLine(counter, 0, counter, 1020, 2, colors[DARK_BLUE]);
		}
		DrawRectangle(150, 200, 400, 30, colors[DARK_BLUE]);
		DrawRectangle(450, 400, 400, 30, colors[DARK_BLUE]);
		DrawRectangle(150, 300, 30, 200, colors[DARK_BLUE]);
		DrawRectangle(150, 700, 800, 30, colors[DARK_BLUE]);

		drawCar();
		drawMbot();
		drawMbot2();

	}

	else if(m1.getLevel(1)==true)
	{
		// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

		glClearColor(0/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors


		//Display Score
		DrawString(50, 800, intToStr(score / 5), colors[MISTY_ROSE]);

		for (int counter = 40; counter < 1000; counter = counter + 40)
		{
			DrawLine(counter, 0, counter, 1020, 2, colors[BLACK]);
		}
		
		DrawRectangle(150, 200, 400, 50, colors[DARK_GREEN]);
		DrawRectangle(500, 650, 400, 50, colors[DARK_GREEN]);
		drawCar();
		drawEZbot();
	}
	if (bulletarr[0] == true)
	drawMediumBullet();

	if (bb.getBulletFlag() == true)
	{
		drawBullet();
	}
	
	if (bb.getbCoorX() < 2)//boundary collision , reappears from other side of map
	{
		bb.setbCoorX(980);
	}
	if (bb.getbCoorX() > 980)
	{
		bb.setbCoorX(5);
	}
	if (bb.getbCoorY() > 815)
	{
		bb.setbCoorY(5);
	}
	if (bb.getbCoorY() < 5)
	{
		bb.setbCoorY(815);
	}
	deflect();
	glutSwapBuffers(); // do not modify this line..

}
void GameDisplay2(){
	glClearColor(1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	//menu
	DrawString(350, 750, "Welcome to Hashim's ATARI", colors[BLACK]);
	DrawString(375, 600, "CONTROLS (PRESS 1)", colors[BLACK]);
	DrawString(360, 500, "HIGH SCORES (PRESS 2)", colors[BLACK]);
	DrawString(385, 400, "CREDITS (PRESS 3)", colors[BLACK]);
	DrawString(360, 300, "1 PLAYER GO (PRESS 4)", colors[BLACK]);
	DrawString(360, 200, "2 PLAYER GO (PRESS 5)", colors[BLACK]);
	DrawString(360, 100, "ENTER NAME...........", colors[BLACK]);

	
	if (m1.getContorls() == true)
	{
		DrawString(50, 750, "1 PLAYER", colors[BLACK]);
		DrawString(50, 720, "movement by gluts", colors[BLACK]);
		DrawString(50, 700, "tfgh for bot direction", colors[BLACK]);
		DrawString(50, 680, "p for powerup", colors[BLACK]);
		DrawString(50, 660, "b to shoot", colors[BLACK]);
		DrawString(50, 640, "m to shoot medium bullet", colors[BLACK]);
		DrawString(50, 620, "l to shoot large bullet", colors[BLACK]);
		DrawString(50, 600, "bots can surpase obstacles in lv3", colors[BLACK]);

		DrawString(50, 550, "2 PLAYER", colors[BLACK]);
		DrawString(50, 530, "GLUT FOR PLAYER1", colors[BLACK]);
		DrawString(50, 510, "WASD FOR PLAYER2", colors[BLACK]);
	}
	if (m1.getCredits() == true)
	{
		DrawString(680, 675, "Hashim made this game", colors[BLACK]);
	}
	glutSwapBuffers(); // do not modify this line..

}
void GameDisplay3() {
	if (score != 10)
	{
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors


		//Display Score
		DrawString(50, 800, intToStr(score / 5), colors[MISTY_ROSE]);
		DrawString(945, 800, intToStr(score / 5), colors[MISTY_ROSE]);

		for (int counter = 40; counter < 1000; counter = counter + 40)
		{
			DrawLine(counter, 0, counter, 1020, 2, colors[DARK_BLUE]);
		}

		DrawRectangle(150, 200, 400, 50, colors[DARK_MAGENTA]);
		DrawRectangle(500, 650, 400, 50, colors[DARK_MAGENTA]);
		drawCar();
		drawp2();
		if (bb.getBulletFlag() == true)
		{
			drawBullet();
		}
		if (bb.getbCoorX() < 2)
		{
			bb.setbCoorX(980);
		}
		if (bb.getbCoorX() > 980)
		{
			bb.setbCoorX(5);
		}
		if (bb.getbCoorY() > 815)
		{
			bb.setbCoorY(5);
		}
		if (bb.getbCoorY() < 5)
		{
			bb.setbCoorY(815);
		}


		if (b.getBulletFlag() == true)
		{
			drawBullet2();
		}
		if (b.getbCoorX() < 2)
		{
			b.setbCoorX(980);
		}
		if (b.getbCoorX() > 980)
		{
			b.setbCoorX(5);
		}
		if (b.getbCoorY() > 815)
		{
			b.setbCoorY(5);
		}
		if (b.getbCoorY() < 5)
		{
			b.setbCoorY(815);
		}

		glutSwapBuffers(); // do not modify this line..
	}
	else
	{
		glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors

		DrawString(400, 400, "GAME FINISHED", colors[BLACK]);


		glutSwapBuffers(); // do not modify this line..

	}

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if (powerupCounter == true)
		{
			pp.setX(pp.getX() - 20);//20 used for powerup (speed increase)
			BcanconCounter[0]++;
		}
		else
			pp.setX(pp.getX() - 10);

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (powerupCounter == true)
		{
			pp.setX(pp.getX() + 20);
			BcanconCounter[0]++;
		}
		else
			pp.setX(pp.getX() + 10);
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if (powerupCounter == true)
		{
			pp.setY(pp.getY() + 20);
			BcanconCounter[0]++;
		}
		else
			pp.setY(pp.getY() + 10);
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (powerupCounter == true)
		{
			pp.setY(pp.getY() -20);
			BcanconCounter[0]++;
		}
		else
			pp.setY(pp.getY() - 10);
	}
	
	coldet1();

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == ' ') 
	{
		drawBullet();
		//bullet gets the coordintes of the player to draw itself
		bb.setbCoorX(pp.getX() + 20);
		bb.setbCoorY(pp.getY() + 5);
	
		bb.setBulletFlag(true);
		bb.setDeflectionCounter(0);

	}
	if (key == 'q')
	{
		//used for p2
		drawBullet2();
		b.setbCoorX(p2.getX() + 20);
		b.setbCoorY(p2.getY() + 5);

		b.setBulletFlag(true);
		b.setDeflectionCounter(0);

	}
	if (key == '1')
	{
		if (m1.getContorls() == false)
		m1.setControls(true);
		else
		m1.setControls(false);

	}
	if (key == '3')
	{
		if (m1.getCredits() == false)
			m1.setCredits(true);
		else
			m1.setCredits(false);
	}
	if (key == '4') {
		score = 0;
		glutDisplayFunc(GameDisplay1);
	}
	if (key == '5')
	{
		score = 0;
		m1.setplayerMODE(true);
		glutDisplayFunc(GameDisplay3);
	}
	if (key == '7')
	{
		m1.setv(0);
		m1.offv(1);
		m1.offmenu(2);
	}
	if (key == '8')
	{
		m1.setv(1);
		m1.offv(0);
		m1.offmenu(2);
	}
	if (key == '9')
	{
		m1.setv(2);
		m1.offv(1);
		m1.offmenu(3);
	}
	if (key == 'm')
	{
		bulletcounters[0]++;
		bb.setbMCoorX(pp.getX() + 25);
		bb.setbMCoorY(pp.getY() - 10);
		
		if (bulletcounters[0]<4)
			bulletarr[0] = true;
		else
		{
			bulletarr[0] = false;
			drawMediumBullet();
		}
	}
	if (key == 't')
	{
		bb.setDirFlag(3);
	}
	if (key == 'h')
	{
		bb.setDirFlag(0);
	}
	if (key == 'f')
	{
		bb.setDirFlag(1);
	}
	if (key == 'g')
	{
		bb.setDirFlag(4);
	}
	if (key == 'p')
	{

		if (BcanconCounter[0] < 20)
		{
			powerupCounter = true;
		}
		else
			powerupCounter = false;
	}
	if (key == 'd')
		p2.setX(p2.getX() + 10);
	if (key == 'a')
		p2.setX(p2.getX() - 10);
	if (key == 'w')
		p2.setY(p2.getY() + 10);
	if (key == 's')
		p2.setY(p2.getY() - 10);
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here  		
	if (score == 50)
	{
		if (m1.getLevel(1) == true)
		{//everything is reset when the level changes
			BcanconCounter[0] = 0;
			m1.offmenu(1);
			m1.setLevel(2);
			score = 0;
		}
	}
	if (score == 50)
	{
		if (m1.getLevel(2) == true)
		{
			BcanconCounter[0] = 0;
			m1.offmenu(2);
			m1.setLevel(3);
			score = 0;
		}
	}

	if (bb.getBulletFlag() == true)
	{
		drawBullet();
		moveBullet();//moves bullet only if its flag is true
	}
	else
	{
		bb.setbCoorX(1200);
		bb.setbCoorY(1200);
	}
	if (b.getBulletFlag() == true)
	{
		drawBullet2();
		moveBullet2();
	}
	if (bulletarr[0] == true)
	{
		drawMediumBullet();
		MmoveBullet();

	}
	
	if (m1.getLevel(3) == true)
	{
		b13.moveBot(3);
		b14.moveBot(3);
		b15.moveBot(3);//the bots move according to the level
	}
	if (m1.getLevel(2) == true)
	{
		b12.moveBot(2);
		b11.moveBot(2);
	}
	if (m1.getLevel(1) == true && m1.getplayerMODE()==false)
	{
		b10.moveBot(1);
	}


	coldet1();
	deflect();
	if (BcanconCounter[0] > 30)
		powerupCounter = false;
	//loop to check the time for powerup, however that made the game crash, so we will use another method
	/*for (int i = 0; i < 10000; i++)
	{
		cout << i << endl;
	}*/

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;

	}
}
	
	



int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ATARI-2022 EDITION"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	//glutDisplayFunc(GameDisplay2); // tell library which function to call for drawing Canvas.

	
	
	//if( gameMaps.getLevel()==1)
		glutDisplayFunc(GameDisplay2); // tell library which function to call for drawing Canvas.
		
		string name;
		cin >> name;
	//if (gameMaps.getLevel() == 2)
	//	glutDisplayFunc(GameDisplay2); // tell library which function to call for drawing Canvas.



	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(50.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* ATARI */
