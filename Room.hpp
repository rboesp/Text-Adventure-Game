#pragma once

#include "Validation.hpp"
#include <iostream>
#include <string>
using std::string;

/**********************************************************
** Description: This is the base abstract Room class. This 
class has two pure virtual functions, a specialAction() which
changes the status of every room and the menu() function
which every room has to help the user decide what to do next.

The class also has four pointers that represent the four 
directions in every room: Right, left, forward, back. Every
pointer is used to link the rooms together, and the user uses 
the pointers to go from room to room.
**********************************************************/
class Room
{
public:
	std::string name;
	Room * right = nullptr;
	Room * left = nullptr;
	Room * forward = nullptr;
	Room * back = nullptr;
	
	Room();
	virtual ~Room();
	void printName();
	void setRightPtr(Room * nextRoom);
	void setLeftPtr(Room * nextRoom);
	void setForwardPtr(Room * nextRoom);
	void setBackPtr(Room * nextRoom);
	virtual int menu() = 0;
	virtual void specialAction() = 0; //special action pure virtual function
};


