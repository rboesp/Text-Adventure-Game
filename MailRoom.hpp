#pragma once

#include "Room.hpp"


/**********************************************************
** Description: This is the MailRoom class. This class is a
derived class from the base Room class. This class represents
the MailRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
**********************************************************/
class MailRoom : public Room
{
private:
	const int MENU_CHOICE_LEVER = 1;
	const int MENU_CHOICE_MEETING = 2;
	const int MENU_CHOICE_SECURITY = 3;
	const int MENU_CHOICE_COPY = 4;
	const int MENU_CHOICE_STORAGE = 5;

public:
	bool leverPulled = false; 

	MailRoom();

	bool playGuessingGame();
	virtual int menu() override;
	virtual void specialAction() override; //special action pulls lever to unlock doors
};


