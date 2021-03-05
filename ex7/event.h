/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca

	May 31, 2020


*/
#include<iostream>
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

// Global Variable
extern unsigned int g_sysClock; // visible throughout the program

namespace sdds
{
	// constant variables
	const int COUNTER = 3;
	class Event
	{
		char* m_desc = nullptr;
		unsigned int m_time = 0;
		bool isEmpty() const;
		void setEmpty();
		void clearMemory();

	public:
		Event() {};
		~Event();
		void setDescription(const char*);
		void display() const;		

		Event(const Event&);
		Event& operator=(const Event&) = delete;
	};

}
#endif // !SDDS_EVENT_H
