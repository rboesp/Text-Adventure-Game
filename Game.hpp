#pragma once

#include "Room.hpp"
#include "StorageRoom.hpp"
#include "MailRoom.hpp"
#include "CopyRoom.hpp"
#include "ReceptionRoom.hpp"
#include "SecurityRoom.hpp"
#include "MeetingRoom.hpp"
#include "Player.hpp"
#include <ctime>
#include <chrono> 
using std::chrono::system_clock;


/**********************************************************
** Description: This is the game class. This class represents
the game that is being simulated. The game has six rooms,
a player, a location which represents which room the player is in,
the payer's next move in the game, and the appropriate member 
functions to successfully run the game.
**********************************************************/
class Game
{
private:
	/*Game contains six rooms, 
	a player to play the game, 
	his location (which room he/she is in), 
	and player's next move (change room, defuse bomb, etc.)*/
	ReceptionRoom * reception = new ReceptionRoom;
	MailRoom * mailRoom = new MailRoom;
	MeetingRoom * meetingRoom = new MeetingRoom;
	CopyRoom * copyRoom = new CopyRoom;
	SecurityRoom * securityRoom = new SecurityRoom;
	StorageRoom * storageRoom = new StorageRoom;

	Player player; 
	Room * playerLocation;
	int nextPLayerMove;


	//Original time code idea used in this project learned from 
	//stack overflow user betabandido (first answer) https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code

	//In my implementation, I changed the idea to use time functions (see below) instead of just putting start/end around the code in MAIN. 
	//For this, I did not want to use auto (because you need to initialize right away and can't declare in header without knowing value), 
	//so had to declare as time_point objects. The time_point objects were learned from 

	//stack overflow user mustafagonul (first answer) https://stackoverflow.com/questions/35826673/stdchronosystem-clocknow-without-auto
	std::chrono::time_point<system_clock> begin;
	std::chrono::time_point<system_clock> end;


	//time available to complete game in SECONDS, 600s = 10 minutes
	int timeAvailable = 600;				

	//if user decides to exit (reception menu choice 7) 
	//switches to true
	bool userExit = false;


public:
	Game();
	~Game();

	//control overall game mechanics
	void startGame();
	void playGame();
	void displayPrompt();

	//control bomb mechanics
	string getAccessCode();
	void showAccessCodeCount();
	bool bombNotDefused();
	void tryDefusingBomb();


	//time functions
	int elapsedTime();
	int timeLeft();
	bool time_is_left();

	//control room mechanics
	void playReceptionRoom();
	void playMailRoom();
	void playMeetingRoom();
	void playCopyRoom();
	void playSecurityRoom();
	void playStorageRoom();
};
