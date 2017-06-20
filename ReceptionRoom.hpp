#pragma once

#include "Room.hpp"


/**********************************************************
** Description: This is the ReceptionRoom class. This class is a
derived class from the base Room class. This class represents
the ReceptionRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
**********************************************************/
class ReceptionRoom : public Room
{
private:
	bool lightSwitch = false;
	const int MENU_CHOICE_LIGHTS = 1;
	const int MENU_CHOICE_DIRECTIONS = 2;
	const int MENU_CHOICE_MEETING = 3;
	const int MENU_CHOICE_MAIL = 4;
	const int MENU_CHOICE_COPY = 5;
	const int MENU_CHOICE_SECURITY = 6;
	const int MENU_CHOICE_EXIT = 7;

public:
	ReceptionRoom();
	virtual int menu() override;
	virtual void specialAction() override; //special action turns on the lights in office building
	void readDirections();
};

