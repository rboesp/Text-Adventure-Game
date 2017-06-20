#include "StorageRoom.hpp"


//constructor
StorageRoom::StorageRoom()
{
	name = "Storage Room";
}



/********************************************************************
** Description: This is menu function for the storage room. This
function overrides the pure virtual function in the base Room class.
This menu function prints the menu options for the user to pick from
and returns the user pick, validated for an integer in correct range.
********************************************************************/
int StorageRoom::menu()
{
	int choice = 0;
	bool valid = false;

	while (!valid)
	{
		cout << "\n----->STORAGE room \n";
		cout << "\t" << 1 << ") Defuse the BOMB \n";
		cout << "\t" << 2 << ") Go back to MAIL room\n";
		cout << "\t" << 3 << ") Go back to COPY room\n";
		cout << "\t" << 4 << ") Go back to MEETING room\n";
		cout << "\t" << 5 << ") Go back to SECURITY room\n";
		cout << "-------> ";
		cin.ignore();

		is_int(&choice);
		valid = validRange(5, 1, choice);

		if (!valid)
		{
			cout << "\nPlease enter a menu option \n" << endl;
		}
	}
	return choice;
}



/********************************************************************
** Description: This is the getAccessCode function. This function
returns a string that represents the access code that defuses the bomb.
********************************************************************/
string StorageRoom::getAccessCode()
{
	return accessCode;
}



/********************************************************************
** Description: This is the specialAction() function for the Storage
Room. This function overrides the pure virtual function in the base
Room class. The function unlocks the doors in the Meeting Room by
the user pulling a lever on the wall so they can access other rooms.
********************************************************************/
void StorageRoom::specialAction() //blow up bomb
{
	bombBlownUp = true;
}



/********************************************************************
** Description: This is the defuseBomb function. This void function
checks to see if the string argument passed into the function is 
equal to the access code that defuses the bomb. If it is, the bomb is 
defused and the game is over.
********************************************************************/
void StorageRoom::defuseBomb(string input)
{
	cout << "\n---> ENTERING ACCESS CODE...\n" << endl;
	if (input == accessCode)
	{
		bombDefused = true;
	}
	else
	{
		cout << "\n---> INVALID ACCESS CODE!! ACCESS CODE REMOVED!! \n" << endl; 
	}
}

