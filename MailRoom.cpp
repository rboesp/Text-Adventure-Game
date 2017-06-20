#include "MailRoom.hpp"


//constructor
MailRoom::MailRoom()
{
	name = "Mail Room ";
}



/********************************************************************
** Description:: This is the specialAction() function for the Mail
Room. This function overrides the pure virtual function in the base
Room class. The function unlocks the doors in the Meeting Room by
the user pulling a lever on the wall so they can access other rooms.
********************************************************************/
void MailRoom::specialAction() 
{
	cout << "\n YOU ARE ACTIVATING THE LEVER! \n" << endl;
	leverPulled = true;
	if (leverPulled)
	{
		cout << "\n---> Doors UNLOCKING! \n" << endl;
	}
}


/********************************************************************
** Description: This is menu function for the mail room. This
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int MailRoom::menu()
{
	int userChoice = 0;
	bool validInput = false;
	while (!validInput)
	{
		cout << "\n-----> MAIL Room \n"; 
		cout << "\t" << MENU_CHOICE_LEVER << ") Pull Lever \n";
		cout << "\t" << MENU_CHOICE_MEETING << ") Go to MEETING room \n";
		cout << "\t" << MENU_CHOICE_SECURITY << ") Go to SECURITY room \n";
		cout << "\t" << MENU_CHOICE_COPY << ") Open door to the COPY room \n"; 
		cout << "\t" << MENU_CHOICE_STORAGE << ") Take stairs to STORAGE room (Bomb) \n"; 
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
** Description: This is the playGuessingGame function. This
void function accepts no arguments and has the user play the guessing
game against the computer. If the user wins, the "special action"
for the room activates and the lever is pulled, unlocking the doors
in the room and puts an access code in the user's notebook.
********************************************************************/
bool MailRoom::playGuessingGame()
{
	int guess;
	int count = 5;
	int TARGET = rand() % 20 + 1;
	//for testing print target user is tying to guess
/*	cout << "\nTarget: " << TARGET << endl;*/
	while (count > 0)
	{
		bool valid = false;
		cout << "\nGuess an INTEGER between 1-20 (binary search?): \n" << endl;
		cout << count << " guesses left!!" << endl;
		cout << "---> ";
		while (!valid)
		{
			is_int(&guess);
			valid = validRange(20, 1, guess);
			if (!valid)
			{
				cout << "---> \nPlease enter an INTEGER between 1-20!!\n" << endl;
			}
		}
		if (guess > TARGET)
		{
			cout << "\n--> Too high! Try again... " << endl;
		}
		else if (guess < TARGET)
		{
			cout << "\n--> Too low! Try again... " << endl;
		}
		else
		{
			cout << "\n---> SUCCESS! YOU GUESSED IT \n" << endl;
			specialAction();
			return true;
		}
		count--;
	}
	cout << "\n---> You failed! Try Again... \n" << endl;
	return false;
}


