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


	template<typename type>
	bool check(const Collection<type>* arrOfTmpObj, int index, const type* keyValue) {
		bool result = false;

		result = arrOfTmpObj[index] == keyValue ? true : false;

		return result;
	}



	template<typename type>
	bool search(const Collection<type>* arrOfTmpObj, int sizeOfArr, const type* keyValue, const Collection<type>& Cl) {
		bool result = false;

		for (int i = 0; i < sizeOfArr; i++)
		{
			if (check(arrOfTmpObj, i, keyValue)) {
				//arrOfTmpObj[i] == keyValue;
				Cl = arrOfTmpObj[i];
				result = true;
			}
		}

		return result;
	}


	template <typename type>
	void listArrayElements(const char* title, const type* arrayOfTemp, int numOfElm) {

		std::cout << title << endl;
		for (int i = 0; i < numOfElm; i++)
		{
			std::cout << i + 1 << ": " << arrayOfTemp[i] << endl;
		}

	}

	template <typename type>
	bool sizeCheck(const Collection<type>& leftC, const Collection<type>& rightC) {
		return leftC.size() > rightC.size();
	};






}
#endif // !SDDS_SEARCH_H_

