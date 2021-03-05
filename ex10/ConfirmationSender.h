/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#include <iostream>
#include "Reservation.h"
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
namespace sdds
{
	class ConfirmationSender
	{
		const sdds::Reservation** m_ResArray = nullptr;
		size_t m_cnt = 0u;

		void setEmpty();
		void clearMemory();
	public:
		//(de)-constructors/
		ConfirmationSender() {};
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		//move constructor
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;	
		//
		ConfirmationSender& operator +=(const Reservation& res);
		ConfirmationSender& operator -=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H
