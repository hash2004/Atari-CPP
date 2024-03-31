#include "bots.h"
bot::bot()
{
	botFlag = false;
	destinationCounter = 0;
	destination = 0;
	botX = 400;
	botY = 400;

}
bot :: bot(int a, int b)
{
	botX = a;
	botY = b;
}
void bot::setBotFlag(bool a)
{
	botFlag = a;
}
bool bot::getBotFlag()
{
	return botFlag;
}
void bot::setDestinationCounter(int a)
{
	destinationCounter = a;
}
int bot::getDestinationCounter()
{
	return destinationCounter;
}
void bot::setDestination(int a)
{
	destination = a;
}
int bot::getDestination()
{
	return destination;
}
void bot::setbotX(int a)
{
	botX = a;
}
int bot::getBotX()
{
	return botX;
}
void bot::setbotY(int a)
{
	botY = a;
}
int bot::getbotY()
{
	return botY;
}
void bot::moveBot(int level)
{ 
	if (level == 3)
	{// this function is true random movement for bots
		//in this function, the bot will get a destination, and the flag will only become true if it reaches that destination
		//otherwise, the bot wont get a new destination, and keep chasing it
		//the destinantion counter is used to get the bot moving in two different directions
		if (botFlag == true)
			destination = GetRandInRange(70, 850);
		if ((botX <= destination + 5 && botX >= destination - 5 && destinationCounter % 2 != 0) || (botY <= destination + 5 && botY >= destination - 5 && destinationCounter % 2 == 0))
		{
			botFlag = true;
			destinationCounter++;
		}
		else
			botFlag = false;

		if (botX <= destination && destinationCounter % 2 != 0)
			botX = botX + 5;
		if (botY <= destination && destinationCounter % 2 == 0)
			botY += 5;
		if (botY >= destination && destinationCounter % 2 == 0)
			botY -= 5;
		if (botX >= destination && destinationCounter % 2 != 0)
			botX -= 5;
	}
	if (level == 1)
	{//standard fixed horizonatal movement
		if (botX > 100 && !botFlag) {
			botX -= 5;
			if (botX < 250)

				botFlag = true;

		}
		else if (botX < 800 && botFlag) {
			botX += 5;
			if (botX > 700)
				botFlag = false;
		}

	}
	if (level == 2)//standard vertical movement, with random coordinates
	{
		if (botFlag == true)
			destination = GetRandInRange(300, 600);
		if ((botX <= destination + 5 && botX >= destination - 5 ) || (botY <= destination + 5 && botY >= destination - 5 ))
		{
			botFlag = true;
			destinationCounter++;
		}
		else
			botFlag = false;

		if (botY <= destination)
			botY = botY + 5;
		if (botY >= destination)
			botY -= 5;
	}
}


