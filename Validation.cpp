#include "Validation.hpp"


/**************************************************************
** Description: This is the input validation function is_int.
This void function takes a pointer to an integer that is to be
assigned the user input if it passes the user validation. The
function prompts the user for input, if input is an integer,
assign value of passed in pointer argument to to user input.
***************************************************************/
void is_int(int *toBeAssigned)
{
	//flag loops until valid input is entered
	bool flag = true;

	//input variable captures user input
	double input;

	while (flag) //while true
	{
		//get input from cin
		cin >> input;

		//if input to cin is not a number, cannot assign to a double, so print error message,
		//this was inspired by user Chemistpp on stack overflow (second answer down)
		//http://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer
		while (cin.fail())
		{
			cout << "Not a number, please enter a number!" << std::endl;
			cin.clear();
			cin.ignore(BUFFER_IGNORE, '\n');

			//ask again
			cin >> input;
		}


		//if user input not equal to its floor, then it must be a decimal number,
		//this idea was inspired from user tj111 on stack overflow (second answer down)
		//http://stackoverflow.com/questions/1521607/check-double-variable-if-it-contains-an-integer-and-not-floating-point
		if (input != floor(input))
		{
			cout << "Not an integer, please enter an integer! " << endl;
		}
		else
		{
			flag = false;
		}
	}

	//if here, flag false, good input, so assign toBeAssigned to input
	*toBeAssigned = input;
}


bool validRange(int max, int min, int num)
{
	if (num > max || num < min)
	{
		return false;
	}
	return true;
}

