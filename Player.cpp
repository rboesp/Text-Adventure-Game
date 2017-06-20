#include "Player.hpp"


/**********************************************************
**Description: This is the getCurrentLocation function. This 
function accepts no arguments and returns a Room ptr that
represents the Room the player is currently in.
**********************************************************/
Room * Player::getCurrentLocation()
{
	return location;
}


/**********************************************************
**Description: This is the changeLocation function. This 
void function accepts a Room ptr and uses that to assign
the location of the player. This function is how the player
changes rooms.
**********************************************************/
void Player::changeLocation(Room * input)
{
	location = input;
}


/**********************************************************
**Description: This is the addAccessCode function. This void
function accepts a string argument and adds it to the notebook
(STL queue). If the notebook is already full, prints error message.
**********************************************************/
void Player::addAccessCode(string input)
{
	if (notebook.size() < 3)
	{
		notebook.push(input);
	}
	else
	{
		cout << "\n---> Notebook full!! Try to DEFUSE bomb to empty!\n" << endl;
	}
}


/**********************************************************
**Description: This is the removeAccessCode function. This 
void function accepts no arguments and removes the first(top)
item in the notebook (STL queue).
**********************************************************/
void Player::removeAccessCode()
{
	notebook.pop();
}


/**********************************************************
**Description: This is the displayAccessCode function. This 
void function accepts no arguments and displays the first item
of the notebook (STL queue).
**********************************************************/
void Player::displayAccessCode()
{
	cout << notebook.front() << endl; 
}


/**********************************************************
**Description: This is the addAccessCode function. This 
function accepts no arguments and returns a string that
represents the first access code in the notebook(STL queue). 
**********************************************************/
string Player::getAccessCode() 
{
	return notebook.front();
}


/**********************************************************
**Description: This is the notebookFull function. This function
accepts no arguments and returns a bool that represents if 
the notebook (STL queue) is full. True means full.
**********************************************************/
bool Player::notebookFull()
{
	if (notebook.size() < noteBookSize)
	{
		return false;
	}
	return true;
}

