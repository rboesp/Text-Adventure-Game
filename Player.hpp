#pragma once

#include "Room.hpp"
#include <iostream>
#include <string>
#include <queue>
using std::queue;

/***************************************************************
**Description: This is the Player class. This class represents
the player in the game. This class has a STL queue representing 
the notebook the player uses to gather access codes with a max
size of three acess codes. 
***************************************************************/
class Player
{
private:
	Room * location;
	

public:
	/*container to hold items gathered in rooms*/
	unsigned int noteBookSize = 3;
	queue<string> notebook;


	
	Room * getCurrentLocation(); /*THIS FUNCTION TRACKS USER LOCATION*/
	void changeLocation(Room *);


	//notebook functions
	void addAccessCode(string);
	void removeAccessCode();
	void displayAccessCode();
	string getAccessCode();
	bool notebookFull();

};


