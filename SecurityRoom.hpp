#pragma once

#include "Room.hpp"


/**********************************************************
** Description: This is the SecurityRoom class. This class is a
derived class from the base Room class. This class represents
the SecurityRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
**********************************************************/
class SecurityRoom :
	public Room
{
private:
	void promptUserToRoll();
	void findWinner();
	void resetGame();
	int getRandomInt(int max, int min);

	int userWins = 0;
	int computerWins = 0;

	int userRoll;
	int computerRoll;

	const int MENU_CHOICE_LEVER = 1;
	const int MENU_CHOICE_COPY = 2;
	const int MENU_CHOICE_MEETING = 3;
	const int MENU_CHOICE_MAIL = 4;
	const int MENU_CHOICE_STORAGE = 5;

public:
	bool leverPulled = false;

	SecurityRoom();

	virtual int menu() override;
	virtual void specialAction() override; //special action pulls lever to unlock doors

	void playDiceWar();

};

