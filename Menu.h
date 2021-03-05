/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds
{
	// MAX number of items per Menu
	const int MAX_NO_OF_ITEMS = 10;

	// forward declaration for class Menu
	class Menu;

	class MenuItem
	{
		// Varibles - char pointer and its size for memory allocation
		char* m_menuitem = nullptr;

		// private void functions to initialize and free, clear and set
		void setEmpty();		
		void setItem(const char*);
		void clearMemory();
		bool isEmpty() const;

		// class Menu is a friend of class MenuItem which owns the members of class MenuItem
		friend class Menu;

	public:

		// constructors ( default, char pointer, Passing MenuItem as a reference to call its objects, destructor ) 
		MenuItem();
		MenuItem(const char*);
		MenuItem(const MenuItem&) = delete; // copy constructor signature // preventing to be re-used
		~MenuItem();

		// member operator ( assignemnt, display )
		MenuItem& operator=(const MenuItem& src) = delete; // = delete to prevent self copying
		std::ostream& display(std::ostream& = std::cout) const;
	};

	class Menu
	{
		//variables - char pointer, number of menuitems, spacing for the output
		char* m_menu_title = nullptr;
		int m_menu_num = 0;
		int m_ind = 0;	
		
		// class pointer array that holds 10 items max
		MenuItem* m_item[MAX_NO_OF_ITEMS]{}; // {} if class type with no default constructor or deleted default constructor then the object is default initialized

	protected:

		void setTitle(const char*);
		void set(const Menu&);
		void clearMemory();		
		void indentation(std::ostream&, int) const;
		bool isEmpty() const;				

	public:
		//constructors ( default, char pointer and the indentation, passing Menu as a reference to call its objects, destructor )
		Menu();                                                     
		Menu(const char*, int ind = 0); 
		Menu(const Menu&); //copy constructor signature
		~Menu();

		// assignment operator and insertion operator 
		Menu& operator=(const Menu&);
		Menu& operator<<(const char*);
		
		// operator int and bool cast overloaded to return either and an integer or trues
		operator int() const;
		operator bool() const;

		// public member functions to display, add and accept data(run)
		void add(const char*);
		int run() const;

		std::ostream& display(std::ostream & = std::cout) const;
	};
	
}
#endif // !SDDS_MENU_H
