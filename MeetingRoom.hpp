#pragma once

#include "Room.hpp"
#include "Validation.hpp"


/**********************************************************
** Description: This is the MeetingRoom class. This class is a
derived class from the base Room class. This class represents
the MeetingRoom in the player's office building. This class
contains the necessary member functions and variables needed
to run the mechanics of the room.
**********************************************************/
class MeetingRoom : public Room
{
private:
	int numMoves = 0;
	char tictactoeBoard[3][3];
	char playerTurn;
	char computerTurn;
	bool gameOver = false;
	int row = 0;
	int column = 0;
	int computerRow = 0;
	int computerColumn = 0;
	enum Gamestates { X_WON, O_WON, DRAW, UNFINISHED };
	bool makeMove(int row, int column, char playerTurn);
	void checkGameState();
	int gameState();
	int checkRows();
	int checkColumns();
	int checkDiagonals();
	int getRandomInt();
	int checkDraw();
	void pickFirstCharacter();
	void printBoard();
	void getPlayerMove(char playerTurn);
	void getComputerMove(char computerTurn);
	void tictactoeMenu(char playerTurn);
	void createBoard();

	const int THREE_IN_ROW = 3;
	const int MENU_CHOICE_LEVER = 1;
	const int MENU_CHOICE_COPY = 2;
	const int MENU_CHOICE_SECURITY = 3;
	const int MENU_CHOICE_MAIL = 4;
	const int MENU_CHOICE_STORAGE = 5;

public:
	bool leverPulled = false;

	MeetingRoom();
	void playTicTacToe();
	virtual int menu() override;
	virtual void specialAction() override; //special action pulls lever to unlock doors
};

