/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

namespace sdds
{
	class ReadWritable
	{
		bool m_flag = 0;

	public:
		ReadWritable() {};
		virtual ~ReadWritable() {};

		bool isCsv() const;
		void setCsv(bool value);

		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
		virtual std::istream& read(std::istream& is = std::cin) = 0;
	};

	std::ostream& operator<<(std::ostream& os, const ReadWritable& R);
	std::istream& operator>>(std::istream& is, ReadWritable& R);

}
#endif // !SDDS_READWRITABLE_H
