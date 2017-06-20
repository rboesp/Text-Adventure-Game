#include "SecurityRoom.hpp"


//constructor
SecurityRoom::SecurityRoom()
{
	name = "Security Room";
}




/********************************************************************
** Description: This is menu function for the security room. This
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int SecurityRoom::menu()
{
	int userChoice = 0;
	bool validInput = false;
	while (!validInput)
	{
		cout << "\n----->SECURITY Room \n";
		cout << "\t" << MENU_CHOICE_LEVER << ") Pull lever \n";
		cout << "\t" << MENU_CHOICE_COPY << ") Go to COPY room \n";
		cout << "\t" << MENU_CHOICE_MEETING << ") Go to MEETING room \n";
		cout << "\t" << MENU_CHOICE_MAIL << ") Go to MAIL room \n";
		cout << "\t" << MENU_CHOICE_STORAGE << ") Go to STORAGE room (Bomb)\n";
		cout << "--------> ";
		cin.ignore();
		is_int(&userChoice); 
		validInput = validRange(MENU_CHOICE_STORAGE, MENU_CHOICE_LEVER, userChoice);
		if (!validInput)
		{
			cout << "\n----> Please enter a menu option (int 1-5)\n" << endl;
		}
	}
	return userChoice;
}




/********************************************************************
** Description: This is the specialAction() function for the Security
Room. This function overrides the pure virtual function in the base
Room class. The function unlocks the doors in the Meeting Room by
the user pulling a lever on the wall so they can access other rooms.
********************************************************************/
void SecurityRoom::specialAction()
{
	cout << "\n YOU ARE ACTIVATING THE LEVER! \n" << endl;
	leverPulled = true;
	if (leverPulled)
	{
		cout << "\n---> Doors UNLOCKING! \n" << endl;
	} 
}




/********************************************************************
** Description: This is the playDiceWar function. This void function 
accepts no arguments and has the user play Dice War against the computer. 
If the user wins, the "special action" for the room activates and the lever 
is pulled, unlocking the doors in the room and puts an access code in the 
user's notebook.
*********************************************************************/
void SecurityRoom::playDiceWar()
{
	cout << "\n---> Welcome to the 'DICE WAR' game! " << endl;
	cout << "\n---> Beat computer three times with 10-sided die to activate lever! \n" << endl;
	do
	{
		computerRoll = getRandomInt(10, 1);

		promptUserToRoll();
		userRoll = getRandomInt(10, 1);

		cout << "\n****************************" << endl;
		cout << "USER ROLL: " << userRoll << endl;
		cout << "COMPUTER ROLL: " << computerRoll << endl;
		cout << "****************************" << endl;

		if (userRoll > computerRoll)
		{
			cout << "\n--> Winner: USER" << endl;
			userWins++;
		}
		else if (userRoll < computerRoll)
		{
			cout << "\n--> Winner: COMPUTER" << endl;
			computerWins++;
		}
		else
		{
			cout << "\n--> Tie!!!\n Go again..." << endl;
		}
		cout << "\nSCORE: " << endl;
		cout << "-----> User: " << userWins << endl;
		cout << "-----> Computer: " << computerWins << endl;
	} 
	while (computerWins < 3 && userWins < 3);
	findWinner();
	resetGame();
}




/********************************************************************
** Description: This is the promptUserToRoll function. This void 
function prompts the user to roll their die.
********************************************************************/
void SecurityRoom::promptUserToRoll()
{
	cout << "\n---> Your turn, ROLL! (Press any key!)\n" << endl;
	string pause;
	cin >> pause;
}




/********************************************************************
** Description: This is the findWinner function. This void function
checks to see if the user or the computer has won three rounds of die 
war. If so, that player is declared winner.
********************************************************************/
void SecurityRoom::findWinner()
{
	if (userWins == 3)
	{
		cout << "\n---> YOU WIN!! \n" << endl;
		specialAction();
	} 
	else if (computerWins == 3)
	{
		cout << "\n---> YOU LOSE!! TRY AGAIN... \n" << endl;
	}
}



/********************************************************************
** Description:This is the resetGame function. This void function 
accepts no arguments and resets the game so the user can pay again
if they so choose.
********************************************************************/
void SecurityRoom::resetGame()
{
	computerWins = 0;
	userWins = 0;
}



/********************************************************************
** Description: This is the getRandomInt function. This function
accepts two integer arguments and returns a random integer between
the two arguments passed into the function. 
********************************************************************/
int SecurityRoom::getRandomInt(int max, int min)
{
	return rand() % max + min;
}
