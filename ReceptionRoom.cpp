#include "ReceptionRoom.hpp"


//constructor
ReceptionRoom::ReceptionRoom()
{
	name = "Reception Room ";
}



/********************************************************************
** Description: This is menu function for the reception room. This 
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int ReceptionRoom::menu()
{
	int userInput = 0;
	bool validInput = false;
	while (!validInput)
	{
		cout << "\n--> You're in the RECEPTION room!\n" << endl;
		cout << "\t" << MENU_CHOICE_LIGHTS << ") TOGGLE breaker that controls the LIGHTS in office building\n";
		if (lightSwitch)
		{
			cout << "\t" << MENU_CHOICE_DIRECTIONS << ") READ piece of paper in pocket (DIRECTIONS)\n";
			cout << "\t" << MENU_CHOICE_MEETING << ") Go to the MEETING room \n";
			cout << "\t" << MENU_CHOICE_MAIL << ") Go to the MAIL room \n";
			cout << "\t" << MENU_CHOICE_COPY << ") Go to the COPY room \n";
			cout << "\t" << MENU_CHOICE_SECURITY << ") Go to the SECURITY room \n";
		}
		cout << "\t" << MENU_CHOICE_EXIT << ") END GAME\n";
		cout << "--------> ";
		is_int(&userInput);
		validInput = validRange(MENU_CHOICE_EXIT, MENU_CHOICE_LIGHTS, userInput);
		if (!validInput)
		{
			cout << "\n\n-----> Please enter a menu option \n\n" << endl;
		}
	}
	return userInput;
}



/********************************************************************
** Description: This is the reception room special action function.
This void function overrides the pure virtual function in the base 
room class. This special action toggles the lights in the office building.
********************************************************************/
void ReceptionRoom::specialAction() //toggle light switch
{
	lightSwitch = !lightSwitch;
}




/********************************************************************
** Description: This is the readDirections function This void function
prints the directions to the screen foe the user to read. 
********************************************************************/
void ReceptionRoom::readDirections()
{
	if (lightSwitch)
	{
		cout << "\n\n**READ CAREFULLY** \n\n";
		cout << "\n\nDirections: " << endl;
		cout << "\n\tGet to the Storage Room and defuse the bomb.\n\tGet access " <<
			"codes throughout the rooms in the office building to defuse the bomb.\n\n" <<
			"\tIn every room, pulling the lever will toggle the status of the doors leading out.\n" <<
			"\tThe terrorists have hacked the levers so you must play a game to activate them.\n" <<
			"\tOnce you pull the lever, the doors will stay unlocked, but you cannot exit a game \n\twhen started...\n\n" <<
			"\tYou can have only three access codes in your notebook or it is full.\n" <<
			"\tWhen you try to defuse the bomb, your access codes will go away," << "\n\tIf the access codes you tried " << 
			"don't defuse, none of those are the right access codes!\n\n\tFind the right access code to defuse the bomb... \n "
			<< "**(there is only ONE out of the four that will work!)\n" << endl;
		cout << "Press any key to continue: " << endl;
		cout << "---> ";
		string pause;
		cin >> pause;
	}
	else
	{
		cout << "\n---> Too dark to read!!\n " << endl;
	}
}


