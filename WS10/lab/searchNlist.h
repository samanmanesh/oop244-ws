//Name:
//ID:
//Email:
// Date:
//Section:

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
namespace sdds {

	template <typename type>
	bool sizeCheck(const Collection<type>& leftC, const Collection<type>& rightC) {
		return leftC.size() > rightC.size();
	};


	template <typename type>
	void listArrayElements(const char* title, const type* arrayOfTemp, int numOfElm) {
	
	
	}



}
#endif // !SDDS_SEARCH_H_

