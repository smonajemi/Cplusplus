/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 2
*/
#include <iostream>
#include <chrono>
#include <string>

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

namespace sdds
{
	const int MAX_RECORDS = 7;
	class TimedEvents
	{
		int nr{ 0 };
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			std::string msg{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_RECORDS];

	public:
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif // !SDDS_TIMEDEVENTS_H
