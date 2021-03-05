/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - LAB4
*/

#include <iostream>
#include <string>
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[5]{};
		std::string m_goodWords[5]{};
	public:

		SpellChecker(const char* file);
		void operator()(std::string& text) const;
	};


}
#endif // !SDDS_SPELLCHECKER_H


