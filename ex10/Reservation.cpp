/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#include <iomanip>
#include <string>
#include <algorithm> 
#include "Reservation.h"

using namespace std;
namespace sdds
{
	std::string Reservation::trim(std::string& str)
	{
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		return str;
	}
	Reservation::Reservation(const std::string& res)
	{
		size_t pos = 0;
		size_t poe = res.find(':');
	//	this->trim(m_rezId = res.substr(pos, poe - pos));
		this->trim(m_rezId = res.substr(0, res.find(':')));

		pos = poe + 1;
		poe = res.find(',', pos);
		this->trim(m_rezName = res.substr(pos, poe - pos));

		pos = poe + 1;
		poe = res.find(',', pos);
		this->trim(m_rezEmail = res.substr(pos, poe - pos));

		pos = poe + 1;
		poe = res.find(',', pos);
		m_numofParty = stoi(res.substr(pos, poe - pos));

		pos = poe + 1;
		poe = res.find(',', pos);
		m_day = stoi(res.substr(pos, poe - pos));

		pos = poe + 1;
		poe = res.find(',', pos);
		m_time = stoi(res.substr(pos, poe - pos));
		
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		string inden = "    ";
		string email = "<" + res.m_rezEmail + ">";
		
		os << "Reservation " << res.m_rezId << ": " << setw(10) << right << res.m_rezName << "  " << setw(20) << left << email << right;

		if (6 <= res.m_time && res.m_time <= 9)
			os << inden << "Breakfast ";
		else if (11 <= res.m_time && res.m_time <= 15)
			os << inden << "Lunch ";
		else if (17 <= res.m_time && res.m_time <= 21)
			os << inden << "Dinner ";
		else
			os << inden << "Drinks ";
		os << "on day " << res.m_day << " @ " << res.m_time << ":00 for " << res.m_numofParty << " people." << endl;
		return os;
	}
}