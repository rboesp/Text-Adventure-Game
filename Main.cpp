#include "Game.hpp"
#include "Room.hpp"
#include "ReceptionRoom.hpp"
#include "MailRoom.hpp"
#include "CopyRoom.hpp"
#include "SecurityRoom.hpp"
#include "MeetingRoom.hpp"
#include "StorageRoom.hpp"

//prototypes
int menu();
void playGame();

//constants
const int PLAY = 1;
const int PLAY_AGAIN = 1;
const int EXIT = 0;


//MAIN FUNCTION
int main()
{
	//seed random number generator
	srand(time(nullptr));
	

	//bring user to menu
	int choice = menu();
	

	//if user picks to play
	if (choice == PLAY) 
	{
		playGame();
	}


	//user has exited game
	cout << "\nGOODBYE!!! \n" << endl;

	return 0;
}




/***********************************************
**Description: This is the menu function that 
controls the entire game. I accepts no arguments
and returns an integer that represents which option
the user picked.
***********************************************/
int menu()
{
	int userInput = 0;
	bool validInput = false;

	cout << "\nWELCOME!!" << endl;
	cout << "\t" << PLAY << ") Play Game \n";
	cout << "\t" << EXIT << ") Exit \n";
	cout << "------> ";

	while (!validInput)
	{
		is_int(&userInput);
		validInput = validRange(PLAY, EXIT, userInput);
		if (!validInput)
		{
			cout << "\n---> Please enter 1 to play and 0 to exit!! \n" << endl;
		}
	}
	return userInput;
}



/***********************************************
**Description: This is the playGame function. 
This void function runs when the user picks to
play the game in the menu function above. This 
function creates the Game object and starts the
game, and asks the user if they would like to play
again.
***********************************************/
void playGame()
{
	bool exit = false;
	while (!exit)
	{
		int userInput = 0;
		int validInput = false;

		//creates game object and plays the game
		Game game;
		game.startGame();

		cout << "\n---> Thank you for playing!! Would you like to go again?" << endl;
		cout << "---> Press 1 for yes and 0 for no \n" << endl;
		cout << "---> ";
		cin.ignore();

		while (!validInput)
		{
			is_int(&userInput);
			validInput = validRange(PLAY_AGAIN, EXIT, userInput);
			if (!validInput)
			{
				cout << "\n---> Please enter 1 to play again and 0 to exit!! \n" << endl;
			}
		}
		if (userInput == EXIT)
		{
			exit = true;
		}
	}
}
