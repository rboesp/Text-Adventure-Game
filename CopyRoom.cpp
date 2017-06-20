#include "CopyRoom.hpp"


//constructor
CopyRoom::CopyRoom()
{
	name = "Copy Room";
}




/********************************************************************
** Description: This is menu function for the copy room. This
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int CopyRoom::menu()
{
	int menuChoice = 0;
	bool validInput = false;
	while (!validInput)
	{
		cout << "\n----->COPY Room \n";
		cout << "\t" << MENU_CHOICE_LEVER << ") Pull lever \n";
		cout << "\t" << MENU_CHOICE_SECURITY << ") Go to SECURITY room \n";
		cout << "\t" << MENU_CHOICE_MEETING << ") Go to MEETING room \n";
		cout << "\t" << MENU_CHOICE_MAIL << ") Go to MAIL room \n";
		cout << "\t" << MENU_CHOICE_STORAGE << ") Go to STORAGE room (Bomb) \n";
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
** Description: This is the specialAction() function for the Copy
Room. This function overrides the pure virtual function in the base
Room class. The function unlocks the doors in the Meeting Room by
the user pulling a lever on the wall so they can access other rooms.
********************************************************************/
void CopyRoom::specialAction()
{
	cout << "\n YOU ARE ACTIVATING THE LEVER! \n" << endl;
	leverPulled = true;
	if (leverPulled)
	{
		cout << "\n---> Doors UNLOCKING! \n" << endl;
	}

}



/********************************************************************
** Description: This is the playRockPaperScissors function. This 
void function accepts no arguments and has the user play rock, paper,
scissors against the computer. If the user wins, the "special action"
for the room activates and the lever is pulled, unlocking the doors
in the room and puts an access code in the user's notebook.
********************************************************************/
void CopyRoom::playRockPaperScissors()
{
	cout << "\n---> Win three games of rock, paper, scissors \n" << 
		    "against the computer to activate lever!!\n" << endl;

	string rps[] = { "Rock", "Paper", "Scissors" };
	while (computerWins < 3 && userWins < 3)
	{
		bool valid = false;
		random = rand() % 3;
		computerChoice = rps[random];
		
		cout << "\nChoices: [0 - Rock, 1 - Paper, 2 - Scissors]\n" << endl;
		while (!valid)
		{
			cout << "---> ";
			is_int(&userChoice);
			valid = validRange(2, 0, userChoice);
			if (!valid)
			{
				cout << "\n---> Enter a valid choice!!!\n" << endl;
			}
			assignUserChoice(userChoice);
		}
		roundCount++;
		findRoundWinner();
	}

	if (computerWins == 3)
	{
		cout << "\n---> Computer Won, Try again!!\n" << endl;
		resetGame();
	}
	else
	{
		cout << "\n---> YOU WIN!!! \n" << endl;
		specialAction();
		resetGame();
	}
}



/********************************************************************
** Description: This is the findRoundWinner function. This void 
function accepts no arguments and checks to see who won the current
round of rock paper scissors against the computer. The stats of the 
current game are then printed to screen.
********************************************************************/
void CopyRoom::findRoundWinner()
{
	if (choice == "Rock")
	{
		if (computerChoice == "Paper")
		{
			computerWins++;
		}
		else if (computerChoice == "Scissors")
		{
			userWins++;
		}
		else
		{
			cout << "\n---> Tie!! No Winner!!\n" << endl;
		}
	}
	if (choice == "Paper")
	{
		if (computerChoice == "Scissors")
		{
			computerWins++;
		}
		else if (computerChoice == "Rock")
		{
			userWins++;
		}
		else
		{
			cout << "\n---> Tie!! No Winner!!\n" << endl;
		}
	}
	if (choice == "Scissors")
	{
		if (computerChoice == "Rock")
		{
			computerWins++;
		}
		else if (computerChoice == "Paper")
		{
			userWins++;
		}
		else
		{
			cout << "\n---> Tie!! No Winner!!\n" << endl;
		}
	}

	cout << "********************************" << endl;
	cout << "----> ROUND: " << roundCount << endl;
	cout << "\n--> User pick: " << choice << endl;
	cout << "--> Computer pick: " << computerChoice << endl;
	cout << "\nUser wins: " << userWins << endl;
	cout << "Computer wins: " << computerWins << endl;
	cout << "********************************" << endl;
}



/********************************************************************
** Description: This is the assignMenuChoice function. This void 
function accepts one integer argument that represents user pick
of either rock, paper, or scissors for the game. The function
assigns the argument to the choice variable that holds the user's 
choice.
********************************************************************/
void CopyRoom::assignUserChoice(int menuChoice)
{
	if (menuChoice == 0)
	{
		choice = "Rock";
	}
	else if (menuChoice == 1)
	{
		choice = "Paper";
	}
	else
	{
		choice = "Scissors";
	}
}



/********************************************************************
** Description: This is the resetGame function. This void function
accepts no arguments and resets the game so the user can play again.
********************************************************************/
void CopyRoom::resetGame()
{
	userWins = 0;
	computerWins = 0;
	roundCount = 0;
}
