/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - LAB4
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds
{
	class Movie
	{
		std::string m_title = "";
		std::string m_description = "";
		size_t m_year = 0;

		void delim(std::string& str);
		std::string trim(std::string& str);

	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& temp);
	};

}
#endif // !SDDS_MOVIE_H


