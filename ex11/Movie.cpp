/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - LAB4
*/

#include <iostream>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds
{
	void Movie::delim(std::string& str)
	{
		size_t comma = str.find(",");
		string tk = str.substr(0, comma);
		str.erase(0, tk.size() + 1);
	}
	std::string Movie::trim(std::string& str)
	{
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		return str;
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		std::string copy = strMovie;
		std::string token;
		bool res;
		int occur = 0;
		do
		{
			bool del = false;
			for (unsigned i = 0; i < copy.size(); ++i)
			{
				if ((copy[i] == ' ' && copy[i + 1] == ' ') || (copy[i] == ',' && copy[i + 1] == ' '))
				{
					occur = i;
					del = true;
					break;
				}
			}
			if (del == true)
				copy.erase(occur + 1, 1);
			del = false;
			for (unsigned i = 0; i < copy.size(); ++i)
			{
				if (copy[i] == ' ' && copy[i + 1] == ',')
				{
					occur = i;
					del = true;
					break;
				}
			}
			if (del == true)
				copy.erase(occur, 1);
			res = true;
			for (unsigned i = 0; i < copy.size(); ++i)
			{
				if ((copy[i] == ' ' && copy[i + 1] == ' ') || (copy[i] == ',' && copy[i + 1] == ' '))
				{
					res = false;
				}
			}
		} while (res == false);
		size_t comma = copy.find(",");
		this->m_title = copy.substr(0, comma);
		for (int i = 0; i < 6; ++i)
		{
			if (m_title[i] == ' ')
			{
				std::cout << m_title << std::endl;
				this->m_title.erase(0, 1);
				if (m_title[i] != ' ')
					break;
			}
		}
		delim(copy);
		comma = copy.find(",");
		this->m_year = std::stoi(copy.substr(0, comma));
		delim(copy);
		comma = copy.find(".");
		this->m_description = copy.substr(0, comma + 1);

		std::string first;
		std::string space;
		std::string dele;
		bool result;
		do
		{
			result = true;
			for (unsigned i = 0; i < m_description.size(); ++i)
			{
				if (m_description[i] == ',' && m_description[i + 1] != ' ')
				{
					int del = m_description.find(',');
					first = m_description.substr(0, del + 1);
					dele = m_description.substr(0, del);
					m_description.erase(0, dele.size() + 1);
					first = first + " ";
					space += first;
					result = false;
				}
			}
		} while (result == false);
		space = space + m_description;
		m_description = space;

	}
	std::ostream& operator<<(std::ostream& os, const Movie& temp)
	{
		return os << setw(40) << temp.m_title << " | " << setw(4) << temp.m_year << " | " << temp.m_description << endl;
	}


}