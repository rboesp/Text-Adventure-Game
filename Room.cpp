#include "Room.hpp"


Room::Room() 
= default;

//virtual destructor to stop undefined behavior
Room::~Room()
= default;



//prints room name
void Room::printName()
{
	cout << "Name: " << name << endl;
}


//sets room's right ptr to Room ptr passed in as argument
void Room::setRightPtr(Room * nextRoom)
{
	right = nextRoom;
}


//sets room's left ptr to Room ptr passed in as argument
void Room::setLeftPtr(Room * nextRoom)
{
	left = nextRoom;
}


//sets room's forward ptr to Room ptr passed in as argument
void Room::setForwardPtr(Room * nextRoom)
{
	forward = nextRoom;
}


//sets room's back ptr to Room ptr passed in as argument
void Room::setBackPtr(Room * nextRoom)
{
	back = nextRoom;
}


