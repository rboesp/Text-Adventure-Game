#include "Game.hpp"


//default constructor links rooms through ptr's
Game::Game()
{
	reception->setRightPtr(meetingRoom);
	reception->setLeftPtr(mailRoom);
	reception->setForwardPtr(copyRoom);   //6 rooms x 4 pointers each
	reception->setBackPtr(securityRoom); 

	mailRoom->setRightPtr(meetingRoom);
	mailRoom->setLeftPtr(storageRoom);
	mailRoom->setForwardPtr(securityRoom);  
	mailRoom->setBackPtr(copyRoom);
	
	meetingRoom->setRightPtr(storageRoom);
	meetingRoom->setLeftPtr(mailRoom);
	meetingRoom->setForwardPtr(copyRoom);
	meetingRoom->setBackPtr(securityRoom);

	storageRoom->setRightPtr(meetingRoom);
	storageRoom->setLeftPtr(mailRoom);
	storageRoom->setForwardPtr(copyRoom);
	storageRoom->setBackPtr(securityRoom);

	securityRoom->setRightPtr(mailRoom);
	securityRoom->setLeftPtr(copyRoom);
	securityRoom->setForwardPtr(meetingRoom);
	securityRoom->setBackPtr(storageRoom);

	copyRoom->setRightPtr(securityRoom);
	copyRoom->setLeftPtr(meetingRoom);
	copyRoom->setForwardPtr(mailRoom);
	copyRoom->setBackPtr(storageRoom);
}


//destructor de-allocates dynamic memory
Game::~Game()
{
	delete reception;
	delete mailRoom;
	delete meetingRoom;
	delete storageRoom; 
	delete copyRoom;
	delete securityRoom;
}



/********************************************************************
** Description: This is the startGame function. This void function
accepts no arguments and runs the mechanics of the game. 
********************************************************************/
void Game::startGame()
{

	displayPrompt();

	//initializes starting location, only time player location is set without using 
	//pointers (left, right) because initializing the game, and user not in any room yet
	player.changeLocation(reception);

	//start time 
	begin = system_clock::now();  


	/*PLAY GAME*/

	//while the bomb is not defused, time has not run out, and the user has not exited
	while (bombNotDefused() && time_is_left() && !userExit)
	{
		cout << "\n\t\t\t**TIME LEFT: " << timeLeft() << " seconds! " << endl;
		playGame();
	}



	/*IF HERE, GAME OVER*/

	cout << "\n\n*************************************************";

	//if user exited 
	if (userExit)
	{
		cout << "\nYou picked to exit!! \n" << endl;
	}

	//if user defused the bomb
	else if (!bombNotDefused())
	{
		cout << "\n---> You defused the bomb!! YOU ARE THE OFFICE **HERO**!!" << endl;
		cout << "\n\n\nIt took you: " << elapsedTime() << " seconds!" << endl;
		cout << "You had: " << timeLeft() << " seconds left!" << endl;
	}

	//else time must have run out
	else
	{
		storageRoom->specialAction(); //blow up bomb
		cout << "\nYOU TOOK TOO LONG!! BOMB EXPLODED! YOUR OFFICE BUILDING COLLAPSES! --> Elapsed time: " << elapsedTime() << " seconds! " << endl;
	}
}



/********************************************************************
** Description: This is the playGame function. This void function
accepts no arguments. This function gets the current room location of 
the player and brings the user to the appropriate room menu function.
********************************************************************/
void Game::playGame()
{
	playerLocation = player.getCurrentLocation();

	if (playerLocation == reception)
	{
		playReceptionRoom();
	}
	else if (playerLocation == mailRoom)
	{
		playMailRoom();
	}
	else if (playerLocation == storageRoom)
	{
		playStorageRoom();
	}
	else if (playerLocation == meetingRoom)
	{
		playMeetingRoom();
	}
	else if (playerLocation == securityRoom)
	{
		playSecurityRoom();
	}
	else if (playerLocation == copyRoom)
	{
		playCopyRoom();
	}
}




/********************************************************************
** Description: This is the displayPrompt function. this void function
displays the prompts the user sees every time they choose to play the 
game.
********************************************************************/
void Game::displayPrompt()
{
	cout << "\nWelcome to the game!!!\n" << endl;
	cout << "\nYou wake up in a dark room. You are unsure how you got here.\n"
		<< "You know terrorists have taken over your office, and have put\n"
		<< "a bomb in the storage room that threatens to take down the building!!!\n"
		<< "\n"
		<< "You feel a piece of paper in your pocket (DIRECTIONS).\n" 
		<< "When you reach for it, you start off a clock ticking that sounds like a timer!\n"
		<< "It's dark, but you know your room contains the electrical box with breakers for the building...\n" 
		<< "\n\n\n---> Press any key to start time: ";
	string pause;
	cin >> pause;
}



/********************************************************************
** Description: This is the getAccessCode function. This function
accepts no arguments and returns an string that represents the access
code that will defuse the bomb.
********************************************************************/
string Game::getAccessCode()
{
	return storageRoom->getAccessCode(); 
}



/********************************************************************
** Description: This is the showAccessCodeCount function. This void
function prints the number of access codes gathered by the user
in their notebook.
********************************************************************/
void Game::showAccessCodeCount()
{
	cout << "\n\t\t\t" << "**Access Codes in notebook: " << player.notebook.size();
}



/********************************************************************
** Description: This is the bombNotDefused function. This function
returns a bool value that represents whether or not the bomb is defused.
If it is defused, returns false. If not defused, returns true;
********************************************************************/
bool Game::bombNotDefused()
{
	if (storageRoom->bombDefused) //bomb defused
	{
		return false;
	}

	return true; //not defused
}




/********************************************************************
** Description:
********************************************************************/
int Game::elapsedTime()
{
	/*SEE Game.hpp HEADER - idea inspired from stack overflow user betabandido (first answer)*/
	//https://stackoverflow.com/questions/11062804/measuring-the-runtime-of-a-c-code
	end = system_clock::now();
	auto time_difference = std::chrono::duration_cast<std::chrono::seconds>(end - begin);
	auto timeSince_ProgramStart = int(time_difference.count());
	return timeSince_ProgramStart;
}



/********************************************************************
** Description: This is the timeLeft function. This function accepts
no arguments and returns an integer that represents the number of 
seconds left in the game before the bomb goes off.
********************************************************************/
int Game::timeLeft()
{
	return timeAvailable - elapsedTime();
}



/********************************************************************
** Description: This is the bool function time_isLeft. This function
returns a value that represents whether or not there is still time
left on the clock, or if the timer has run out.
********************************************************************/
bool Game::time_is_left()
{
	if (elapsedTime() < timeAvailable)
	{
		return true;
	}
	return false;
}



/********************************************************************
** Description: This is the playReceptionRoom function. This void
function controls the mechanics of the reception room.
********************************************************************/
void Game::playReceptionRoom()
{
	nextPLayerMove = reception->menu();

	if (nextPLayerMove == 1)
	{
		reception->specialAction(); //toggle light switch
	}
	else if (nextPLayerMove == 2)
	{
		reception->readDirections(); //read directions
	}
	else if (nextPLayerMove == 3)
	{
		player.changeLocation(reception->right); //go to meeting room
	}
	else if (nextPLayerMove == 4)
	{
		player.changeLocation(reception->left); //go to mail room
	}
	else if (nextPLayerMove == 5)
	{
		player.changeLocation(reception->forward); //go to copy
	}
	else if (nextPLayerMove == 6)
	{
		player.changeLocation(reception->back); //go to security
	}
	else if (nextPLayerMove == 7)	//exit
	{
		cout << "\nElapsed time: " << elapsedTime() <<  " seconds!" << endl;
		userExit = true;
	}
}



/********************************************************************
** Description: This is the playMailRoom function. This void
function controls the mechanics of the mail room.
********************************************************************/
void Game::playMailRoom()
{
	showAccessCodeCount();
	nextPLayerMove = mailRoom->menu();

	if (nextPLayerMove == 1)
	{
		bool unlock = mailRoom->playGuessingGame();
		if (unlock)
		{
			cout << "\n---> You are granted an access code! \n";
			cout << "\nAccess code added to notebook \n" << endl;
			if (!player.notebookFull()) 
			{
				player.addAccessCode("xyz");
			}
			else
			{
				cout << "\n---> Notebook full! Try defusing to empty... \n" << endl; //make sure to implement this everywhere
			}
		}
	}
	else if (nextPLayerMove == 2)
	{
		if (mailRoom->leverPulled)
		{
			player.changeLocation(mailRoom->right); //meeting 
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 3)
	{
		if (mailRoom->leverPulled)
		{
			player.changeLocation(mailRoom->forward); //security 
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 4)
	{
		if (mailRoom->leverPulled)
		{
			player.changeLocation(mailRoom->back); //copy
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 5)
	{
		if (mailRoom->leverPulled)
		{
			player.changeLocation(mailRoom->left);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
}


/********************************************************************
** Description: This is the playStorageRoom function. This void
function controls the mechanics of the storage room.
********************************************************************/
void Game::playStorageRoom()
{
	showAccessCodeCount();
	nextPLayerMove = storageRoom->menu();

	if (nextPLayerMove == 1)
	{
		tryDefusingBomb(); 
	}
	else if (nextPLayerMove == 2)
	{
		player.changeLocation(storageRoom->left);
	}
	else if (nextPLayerMove == 3)
	{
		player.changeLocation(storageRoom->forward);
	}
	else if (nextPLayerMove == 4)
	{
		player.changeLocation(storageRoom->right);
	}
	else if (nextPLayerMove == 5)
	{
		player.changeLocation(storageRoom->back);
	}
}



/********************************************************************
** Description: This is the playMeetingRoom function. This void
function controls the mechanics of the meeting room.
********************************************************************/
void Game::playMeetingRoom()
{
	showAccessCodeCount();
	nextPLayerMove = meetingRoom->menu();

	if (nextPLayerMove == 1)//play tictactoe
	{
		meetingRoom->playTicTacToe();
		if (meetingRoom->leverPulled)
		{
			cout << "\n---> Access code is put in notepad! \n" << endl;
			if (!player.notebookFull()) 
			{
				player.addAccessCode("xxx");
			}
			else
			{
				cout << "\n---> Notebook full! Try defusing to empty... \n" << endl; 
			}
		}
	}
	else if (nextPLayerMove == 2)
	{
		if (meetingRoom->leverPulled)
		{
			player.changeLocation(meetingRoom->forward);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 3)
	{
		if (meetingRoom->leverPulled)
		{
			player.changeLocation(meetingRoom->back);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 4)
	{
		if (meetingRoom->leverPulled)
		{
			player.changeLocation(meetingRoom->left);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 5)
	{
		if (meetingRoom->leverPulled)
		{
			player.changeLocation(meetingRoom->right);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
}



/********************************************************************
** Description: This is the playCopyRoom function. This void
function controls the mechanics of the copy room.
********************************************************************/
void Game::playCopyRoom()
{
	showAccessCodeCount();
	nextPLayerMove = copyRoom->menu();

	if (nextPLayerMove == 1)//play rock, paper, scissors
	{
		copyRoom->playRockPaperScissors();
		if (copyRoom->leverPulled)
		{
			cout << "\n---> Access code is put in notepad! \n" << endl;
			if (!player.notebookFull())
			{
				player.addAccessCode("xxx");
			}
			else
			{
				cout << "\n---> Notebook full! Try defusing to empty... \n" << endl; 
			}
		}
	}
	else if (nextPLayerMove == 2)
	{
		if (copyRoom->leverPulled)
		{
			player.changeLocation(copyRoom->right); //security 
		}
		else
		{
			cout << "\n----> Door locked! Pull lever to unlock!! \n" << endl;
		}
	}
	else if (nextPLayerMove == 3)
	{
		if (meetingRoom->leverPulled)
		{
			player.changeLocation(copyRoom->left); //meeting
		}
		else
		{
			cout << "\n----> Door locked! Pull lever to unlock!! \n" << endl;
		}
	}
	else if (nextPLayerMove == 4)
	{
		if (copyRoom->leverPulled)
		{
			player.changeLocation(copyRoom->forward); //mail
		}
 		else
 		{
 			cout << "\n----> Door locked! Pull lever to unlock!! \n" << endl;
 		}
	}
	else if (nextPLayerMove == 5)
	{
		if (copyRoom->leverPulled)
		{
			player.changeLocation(copyRoom->back); //storage
		}
		else
		{
			cout << "\n----> Door locked! Pull lever to unlock!! \n" << endl;
		}
	}
}



/********************************************************************
** Description: This is the playSecurityRoom function. This void
function controls the mechanics of the security room.
********************************************************************/
void Game::playSecurityRoom()
{
	showAccessCodeCount();
	nextPLayerMove = securityRoom->menu(); 

	if (nextPLayerMove == 1)//play dice war
	{
		securityRoom->playDiceWar();
		if (securityRoom->leverPulled)
		{
			cout << "\n---> You are granted an access code! \n" << endl;
			if (!player.notebookFull())
			{
				player.addAccessCode("xxx");
			}
			else
			{
				cout << "\n---> Notebook full! Try defusing to empty... \n" << endl; 
			}
		}
	}
	else if (nextPLayerMove == 2)
	{
		if (securityRoom->leverPulled)
		{
			player.changeLocation(securityRoom->left);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 3)
	{
		if (securityRoom->leverPulled)
		{
			player.changeLocation(securityRoom->forward);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 4)
	{
		if (securityRoom->leverPulled)
		{
			player.changeLocation(securityRoom->right);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
	else if (nextPLayerMove == 5)
	{
		if (securityRoom->leverPulled)
		{
			player.changeLocation(securityRoom->back);
		}
		else
		{
			cout << "\n---> Door locked! Pull lever on wall to unlock!!!\n" << endl;
		}
	}
}



/********************************************************************
** Description: This is the tryDefusinBomb function. This void 
function accepts no arguments. This function represents the player
trying to defuse the bomb with the access codes gather in their 
notebook (STL queue container).
********************************************************************/
void Game::tryDefusingBomb()
{
	while (!player.notebook.empty())
	{
		string userAccessCode = player.getAccessCode();
		player.removeAccessCode();
		storageRoom->defuseBomb(userAccessCode);
	}
}

