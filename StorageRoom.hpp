#pragma once

#include "Room.hpp"


/**********************************************************
** Description: This is the StorageRoom class. This class is a
derived class from the base Room class. This class represents
the StorageRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
**********************************************************/
class StorageRoom : public Room
{
private:
	bool bombBlownUp = false;
	string accessCode = "xyz";
	string userInput;

public:
	StorageRoom();
	bool bombDefused = false;
	virtual int menu() override;
	string getAccessCode();
	virtual void specialAction() override; //special action blows up bomb
	void defuseBomb(string input); 

};

