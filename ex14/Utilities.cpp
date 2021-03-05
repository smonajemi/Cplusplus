
/*
	SINA MONAJEMI
	SMONAJEMI@MYSENECA.CA
	021-324-124
	DIY 8
*/
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (unsigned int i = 0; i < desc.size(); i++)
		{
			for (unsigned int j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* p = new Product(desc[i].desc, price[j].price);
					try
					{								
						p->validate(); 
					}
					catch (const std::string& e)
					{			
						delete p;
						p = nullptr;						
						throw e;
					}	
					//p->validate();
					priceList += p;
					delete p;
					p = nullptr;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (unsigned int i = 0; i < desc.size(); i++)
		{
			for (unsigned int j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					p->validate();
					priceList += move(p);
				}
			}
		}

		return priceList;
	}
}

