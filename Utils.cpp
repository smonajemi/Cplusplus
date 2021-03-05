/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
#include "Utils.h"

namespace sdds
{
	int yes()
	{
		char input[10] = { 0 };
		bool done = false;	

		while (!done) // while its true
		{
			cin.getline(input,10,'\n');
			input[0] = toupper(input[0]);
			if (strlen(input) == 1)
			{
				if (input[0] == 'Y')
				{
					done = true;
					break;
				}
				if (input[0] == 'N')
					done = false;
					break;				
			}
			else
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		}
		return done;
	}
}