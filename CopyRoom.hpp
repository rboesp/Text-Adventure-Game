#pragma once

#include "Room.hpp"

/*************************************************************
**Description: This is the CopyRoom class. This class is a
derived class from the base Room class. This class represents
the CopyRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
*************************************************************/
class CopyRoom : public Room
{
private:
	int userWins = 0;
	int computerWins = 0;
	int roundCount = 0;
	int random;
	string computerChoice;
	int userChoice;
	string choice;

	void findRoundWinner();
	void assignUserChoice(int menuChoice);
	void resetGame();

	const int MENU_CHOICE_LEVER = 1;
	const int MENU_CHOICE_SECURITY = 2;
	const int MENU_CHOICE_MEETING = 3;
	const int MENU_CHOICE_MAIL = 4;
	const int MENU_CHOICE_STORAGE = 5;

public:
	bool leverPulled = false;

	CopyRoom();
	virtual int menu() override;
	virtual void specialAction() override; //special action pulls lever to unlock doors
	void playRockPaperScissors();
};

