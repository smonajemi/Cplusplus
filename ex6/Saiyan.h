#pragma once
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__

namespace sdds
{
	
	class Saiyan
	{
		char* m_name;
		int m_size;
		int m_dob;
		int m_power;
		int m_level;

		bool m_super;		

	public:
		Saiyan();
		Saiyan(const char*, int, int);		
		~Saiyan();

		bool isSuper() const;
		bool isValid() const;
		bool hasLost(Saiyan& other);
	
		void setEmpty();
		void display() const;
		void set(const char* ,int ,int ,int level = 0 ,bool super = false);
		//void setValid(const char*, int, int);
		void powerup();
		void clearMemory();
		
	};




}
#endif // !SDDS_SAIYAN_H__

#pragma once
