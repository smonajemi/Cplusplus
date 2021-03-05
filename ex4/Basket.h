/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	March 10, 2020
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H


namespace sdds
{
	   
	class Basket
	{
		char* m_fuitName; // representing the name of the fruit
		int m_qty; // quanity of fruits
		double m_price; // prince of the basket

	public:

		Basket(); // default constructor
		Basket(const char*, int, double); // 3 arguement constructor
		Basket(const Basket&); // copy constructor
	   ~Basket(); // destructor	   
	   

		//bool isValid() const; // validating the member variables
	    bool isValid() const; // if valid
		bool isempty() const; // if empty
		bool addPrice(double); // add price +=

		void setEmpty(); // setting to safe empty state
		void setName(const char*); // set name function
		void setQty(int); // set quanitity of fruits function
		void setPrice(double); // set price of basket
		void clearMemory(); // delete memory for allocation
		//void createMemory(const char* x);
		   		 	  	  	   
		std::ostream& display(std::ostream&) const; // ostream to display
		Basket& operator=(const Basket&); // object = current object 

		bool operator==(const Basket&); // compares the baskets 
		bool operator!=(const Basket&); // compares the baskets after priced increased
	};

	std::ostream& operator<<(std::ostream&, const Basket&); // Operator overloaded to allow "Cout << " to be used

}
#endif // !SDDS_BASKET_H
