#include "MeetingRoom.hpp"



//constructor
MeetingRoom::MeetingRoom()
{
	name = "Meeting Room ";
}




/********************************************************************
** Description: This is the playTicTacToe function. This void function 
accepts no arguments and has the user play tictactoe against the computer. 
If the user wins, the "special action" for the room activates and the 
lever is pulled, unlocking the doors in the room and puts an access code 
in the user's notebook.
********************************************************************/
void MeetingRoom::playTicTacToe()
{
	createBoard();
	pickFirstCharacter();
	printBoard();

	//while the game is not over,
	//keep looping and asking the player their move
	while (!gameOver)
	{
		cout << "USER: " << playerTurn << endl;
		getPlayerMove(playerTurn);
		checkGameState();
		if (!gameOver)
		{
			getComputerMove(computerTurn);
			checkGameState();
		}
	}
	numMoves = 0;
	gameOver = false;
}




/********************************************************************
** Description: This is menu function for the meeting room. This
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int MeetingRoom::menu()
{
	int menuChoice = 0;
	bool validInput = false;
	while (!validInput)
	{
		cout << "\n----->MEETING Room \n";
		cout << "\t" << MENU_CHOICE_LEVER << ") Pull lever \n";
		cout << "\t" << MENU_CHOICE_COPY << ") Go to COPY room \n";
		cout << "\t" << MENU_CHOICE_SECURITY << ") Go to SECURITY room \n";
		cout << "\t" << MENU_CHOICE_MAIL << ") Go to MAIL room \n"; 
		cout << "\t" << MENU_CHOICE_STORAGE << ") Go to STORAGE room \n";
		cout << "--------> ";
		cin.ignore(); 
		is_int(&menuChoice); 
		validInput = validRange(MENU_CHOICE_STORAGE, MENU_CHOICE_LEVER, menuChoice);
		if (!validInput)
		{
			cout << "\n----> Please enter a menu option (int 1-5)\n" << endl;
		}
	}
	return menuChoice;
}





/********************************************************************
** Description: This is the specialAction() function for the Meeting
Room. This function overrides the pure virtual function in the base
Room class. The function unlocks the doors in the Meeting Room by
the user pulling a lever on the wall so they can access other rooms.
********************************************************************/
void MeetingRoom::specialAction()//unlock door
{
	cout << "\n YOU ARE ACTIVATING THE LEVER! \n" << endl;
	leverPulled = true;
	if (leverPulled)
	{
		cout << "\n---> Doors UNLOCKING! \n" << endl;
	}
}





/********************************************************************
** Description: This is the createBoard function. This void function
accepts no arguments and creates the tictactoe board the user plays
tictactoe on against the computer. 
********************************************************************/
void MeetingRoom::createBoard()
{
	//start with row 1 and loop through 
	//columns, then go to next row  
	for (auto & count : tictactoeBoard)
	{
		for (char & stop : count)
		{
			stop = '.';
		}
	}
}




/********************************************************************
** Description: This is the makeMove function. This void function
accepts two integer arguments and one char argument and makes a move 
for the user in the tictactoe game by placing an 'x' or 'o' on the board.
********************************************************************/
bool MeetingRoom::makeMove(int row, int column, char playerTurn)
{
	//if the location on board has an X   
	if (tictactoeBoard[row][column] == 'X')
		return false;

	//if the location on board is an O 
	else if (tictactoeBoard[row][column] == 'O')
		return false;

	//else it is unoccupied
	else
	{
		tictactoeBoard[row][column] = playerTurn;
		return true;
	}
}




/********************************************************************
** Description: This is the checkGameState function. This void function
accepts no arguments and checks the state of the game. The four states
can be X_Won, O_Won, DRAW or unfinished which means the gae is still going.
********************************************************************/
void MeetingRoom::checkGameState()
{
	//check the current state of the board for a
	//win or a draw, if so, end the game
	int state = gameState();
	if (state == X_WON)
	{
		if (computerTurn != 'X')
		{
			cout << "\n ---> X WON! \n";
			specialAction();
		}
		else
		{
			cout << "\n ---> COMPUTER WON. Try Again!\n";
		}
		gameOver = true;
	}


	else if (state == O_WON)
	{
		if (computerTurn != 'O')
		{
			cout << "\n ---> O WON!\n";
			specialAction();
		}
		else
		{
			cout << "\n ---> COMPUTER WON. Try Again!\n";
		}
	}

	else if (state == DRAW)
	{
		cout << "\n ---> DRAW. Try Again! \n";
		gameOver = true;
	}
}




/********************************************************************
** Description: This is the gameState function. This void function
accepts no arguments and makes a move for the user in the tictactoe 
game by placing an 'x' or 'o' on the board.
********************************************************************/
int MeetingRoom::gameState()
{
	int gameState = checkRows();
	if (gameState == -1)
	{
		gameState = checkColumns();
		if (gameState == -1)
		{
			gameState = checkDiagonals();
			if (gameState == -1)
			{
				gameState = checkDraw();
				if (gameState == -1)
				{
					return UNFINISHED;
				}
			}
		}
	}
	return gameState;
}




/********************************************************************
** Description: This is the checkRows function. This function accepts
no arguments and returns an integer that represents whether there is 
three in a row in any of the rows on the board. Returning -1 means
that three in a row of either character was not found in rows.
********************************************************************/
int MeetingRoom::checkRows()
{
	//check for three in a row by looping
	//through the rows of the board
	for (auto & row : tictactoeBoard)
	{
		//declare counters to keep track 
		//of X's and O's 
		int x_count = 0,
			o_count = 0;

		for (char val : row)
		{
			//if spot is an X increase x_counter	
			if (val == 'X')
			{
				x_count++;
				/*cout << "row x_count: " << x_count << endl;*/
				//if three X's in a row, return X_WON
				if (x_count == 3)
				{
					gameOver = true;
					return X_WON;
				}
			}

			//if spot is an O increase o_counter
			else if (val == 'O')
			{
				o_count++;
				/*cout << "row o_count: " << o_count << endl;*/
				//if three O's in a row, return O_WON	
				if (o_count == 3)
				{
					gameOver = true;
					return O_WON;
				}
			}
		}
	}
	return -1;
}




/********************************************************************
** Description: This is the checkColumns function. This function accepts
no arguments and returns an integer that represents whether there is
three in a row in any of the columns on the board. Returning -1 means
that three in a row of either character was not found in columns.
********************************************************************/
int MeetingRoom::checkColumns()
{
	//since three in a row have not been found, 
	//loop through the columns of the board 
	for (int val = 0; val < 3; val++)
	{
		//X and O counters
		int x_count = 0,
			o_count = 0;

		for (auto & column : tictactoeBoard) //range-based for loop
		{
			if (column[val] == 'X')
			{
				x_count++;

				//if three X's in a row, return X_WON
				if (x_count == 3)
				{
					gameOver = true;
					return X_WON;
				}
			}
			else if (column[val] == 'O')
			{
				o_count++;

				//if three O's in a row, return O_WON
				if (o_count == 3)
				{
					gameOver = true;
					return O_WON;
				}
			}
		}
	}
	return -1;
}




/********************************************************************
** Description: This is the checkDiagonals function. This function accepts
no arguments and returns an integer that represents whether there is
three in a row in any of the diagonals on the board. Returning -1 means
that three in a row of either character was not found in diagonals.
********************************************************************/
int MeetingRoom::checkDiagonals()
{
	//ascending spots 2,0 - 1,1 - 0,2 on board
	if (tictactoeBoard[2][0] == 'X' && tictactoeBoard[1][1] == 'X' && tictactoeBoard[0][2] == 'X')
	{
		gameOver = true;
		return X_WON;
	}

	if (tictactoeBoard[2][0] == 'O' && tictactoeBoard[1][1] == 'O' && tictactoeBoard[0][2] == 'O')
	{
		gameOver = true;
		return O_WON;
	}


	//descending spots 0,0 - 1,1 - 2,2 on board
	if (tictactoeBoard[0][0] == 'X' && tictactoeBoard[1][1] == 'X' && tictactoeBoard[2][2] == 'X')
	{
		gameOver = true;
		return X_WON;
	}

	if (tictactoeBoard[0][0] == 'O' && tictactoeBoard[1][1] == 'O' && tictactoeBoard[2][2] == 'O')
	{
		gameOver = true;
		return O_WON;
	}

	return -1;

}




/********************************************************************
** Description: This is the getRandomInt function. This function
returns an integer that represents a random integer between 0 - 2,
which are the indexes o the tic tac toe board. 
********************************************************************/
int MeetingRoom::getRandomInt()
{
	int random = rand() % 3; //random int 0-2
	return random;
}




/********************************************************************
** Description: This is the checkDraw function. This function accepts
no arguments and returns an integer that represents whether the game
is a draw. Returning -1 means that no draw has been found.
********************************************************************/
int MeetingRoom::checkDraw()
{
	//if nine moves played and 
	//no winner then must be a tie
	if (numMoves == 9)
	{
		gameOver = true;
		return DRAW;
	}
	return -1;
}



/********************************************************************
** Description: This is the pickFirstCharacter function This void 
function accepts no arguments and has the user pick either 'x' or 
'o' in the tic tac toe game.
********************************************************************/
void MeetingRoom::pickFirstCharacter()
{
	int input = 0;
	bool valid = false;
	while (!valid)
	{
		cout << "\n   Pick who goes first \n";
		cout << 1 << ": X \n";
		cout << 2 << ": O " << endl;
		cout << "---> ";
		is_int(&input);
		valid = validRange(2, 1, input);
	}
	if (input == 1)
	{
		playerTurn = 'X';
		computerTurn = 'O';
	}
	else if (input == 2)
	{
		playerTurn = 'O';
		computerTurn = 'X';
	}
}



/********************************************************************
** Description: This the printBoard function. This void function
accepts no arguments and prints the current tic tac toe board to the
screen.
********************************************************************/
void MeetingRoom::printBoard()
{
	cout << "\n\t";

	//print indexes of tictactoe board
	cout << "   " << 0 << " " << 1 << " " << 2 << "\n" << endl;

	//loop through spots on board and print spot
	for (int start = 0; start < 3; start++)
	{
		cout << "\t" << start << " ";
		for (int stop = 0; stop < 3; stop++)
		{
			cout << " " << tictactoeBoard[start][stop];
		}
		cout << "\n\t"
			<< "\n";

	}
	cout << endl;
}



/********************************************************************
** Description: This is the getPlayerMove function. This void function
accepts a char argument that represents the user character in the tic
tac toe game, and gets the next move from the user. If the square
on the board is already taken, then a message is printed to screen.
********************************************************************/
void MeetingRoom::getPlayerMove(char firstTurn)
{
	tictactoeMenu(firstTurn);

	//if spot taken
	bool validMove = makeMove(row, column, firstTurn);

	while (!validMove)
	{
		cout << "\n";
		cout << "---> That square is already taken. \n";
		printBoard();
		tictactoeMenu(firstTurn);
		validMove = makeMove(row, column, firstTurn);
	}
	numMoves++;
	printBoard();
}



/********************************************************************
** Description: This is the getComputerMove function. This void function
accepts a char argument that represents the character the computer is 
using to play with. This function gets the computer's next move and 
plays it on the board. If the square is taken, the function prints
that the computer is thinking.
********************************************************************/
void MeetingRoom::getComputerMove(char computerTurn)
{
	computerRow = getRandomInt();
	cout << "\n---> Computer's turn!" << endl;
	computerColumn = getRandomInt();

	bool taken = makeMove(computerRow, computerColumn, computerTurn);

	while (!taken)
	{
		computerRow = getRandomInt();
		cout << "\n---> Computer thinking...!" << endl;
		computerColumn = getRandomInt();
		taken = makeMove(computerRow, computerColumn, computerTurn);
	}
	numMoves++;
	printBoard();
}




/********************************************************************
** Description: This is the tictactoeMenu function. This void function
accepts a char argument that represents which character the user is 
playing with in the game. The function gets the user input that
represents the user's move on the board. 
********************************************************************/
void MeetingRoom::tictactoeMenu(char firstTurn)
{
	bool validRow = false;
	bool validColumn = false;

	cout << "\n---> Player " << firstTurn << endl;
	cout << "Enter a row position \n";
	cout << "Row: \n";
	cout << "-> 0 \n";
	cout << "-> 1 \n";
	cout << "-> 2 \n";
	is_int(&row); 
	validRow = validRange(2, 0, row);
	while (!validRow)
	{
		cout << "Please enter an integer 0-2 \n" << endl;
		is_int(&row);
		validRow = validRange(2, 0, row);
	}

	cout << "\nEnter a column position \n";
	cout << "Column: \n";
	cout << "-> 0 \n";
	cout << "-> 1 \n";
	cout << "-> 2 \n";
	is_int(&column); 
	validColumn = validRange(2, 0, column);
	while (!validColumn)
	{
		cout << "Please enter an integer 0-2 \n" << endl;
		is_int(&column);
		validColumn = validRange(2, 0, column);
	}
}

