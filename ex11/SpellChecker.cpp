
/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - LAB4
*/
#include <iostream>
#include <fstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
	SpellChecker::SpellChecker(const char* file)
	{
		ifstream fin(file);
		if (fin.fail() || !fin.is_open())
		{
			throw "Bad file name!";
		}
		else
		{
			while (fin.is_open())
			{
				for (size_t i = 0; i < 5; i++)
				{
					fin >> m_badWords[i];
					fin >> m_goodWords[i];
				}
			}
		}
	}

	void SpellChecker::operator()(std::string& text) const
	{
		size_t check;
		for (int i = 0; i < 5; i++)
		{
			while ((check = text.find(m_badWords[i])) != string::npos)
			{
				text.replace(check, m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}

}
