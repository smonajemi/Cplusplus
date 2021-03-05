/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#include "ConfirmationSender.h"
using namespace std;
namespace sdds
{
	void ConfirmationSender::setEmpty()
	{
		m_ResArray = nullptr;
		m_cnt = 0u;
	}
	void ConfirmationSender::clearMemory()
	{
		delete[] m_ResArray;
		m_ResArray = nullptr;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		clearMemory();
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		setEmpty();
		*this = src;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		setEmpty();
		if (this != &src)
		{
			m_cnt = src.m_cnt;
			clearMemory();
			m_ResArray = new const Reservation*[m_cnt];
			for (size_t i = 0u; i < m_cnt; i++)
			{
				m_ResArray[i] = src.m_ResArray[i];
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)noexcept
	{
		*this = move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)noexcept
	{
		if (this != &src)
		{
			m_cnt = src.m_cnt;
			clearMemory();
			m_ResArray = src.m_ResArray;
			src.setEmpty();
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool exit = false;
		for (auto i = 0u; i < m_cnt; i++)
			if (&res == m_ResArray[i])
				exit = true;

		if (exit == false)
		{
			const sdds::Reservation** temp = nullptr; // pointer to an object temp of type Reservation 
			temp = new const Reservation*[m_cnt + 1]; // Re-sizing
			for (size_t i = 0u; i < m_cnt; i++) {
				temp[i] = m_ResArray[i]; // deep copying
			}
			temp[m_cnt] = &res; // storing the address of res
			++m_cnt;
			clearMemory();
			m_ResArray = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0u; i < m_cnt; i++)
			if (&res == m_ResArray[i])
				m_ResArray[i] = nullptr;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send" << endl;
		os << "--------------------------\n";
		if (sender.m_cnt == 0)
			os << "The object is empty!" << endl;
		for (size_t i = 0u; i < sender.m_cnt; i++)
			if(sender.m_ResArray[i] != nullptr)
			os << *(sender.m_ResArray[i]);
		os << "--------------------------\n";
		return os;
	}
}