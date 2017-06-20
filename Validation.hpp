#pragma once

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

/**********************************************************
** Description: This is the header file for the validation
function is_int.
**********************************************************/

//constant
const int BUFFER_IGNORE = 256;

//prototypes
void is_int(int *);

bool validRange(int max, int min, int num);
