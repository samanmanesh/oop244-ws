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


	template<typename type1, typename type2>
	bool check(const type1* arrOfTmpObj, int index, const type2& keyValue) {
		bool result = false;

		result = arrOfTmpObj[index] == keyValue ? true : false;

		return result;
	}



	template<typename type1, typename type2>
	bool search(const type1* arrOfTmpObj, int sizeOfArr, const type2& keyValue, Collection<type1>& Cl) {
		bool result = false;

		//Cl.resize(0);
		for (int i = 0; i < sizeOfArr; i++)
		{
			if (check(arrOfTmpObj, i, keyValue)) {
				//arrOfTmpObj[i] == keyValue;
				//Cl = arrOfTmpObj[i];
				Cl.add(arrOfTmpObj[i]);
				result = true;
			}
		}
		return result;
	}


	template <typename type>
	void listArrayElements(const char* title, const type* arrayOfTemp, int numOfElm) {

		std::cout << title << std::endl;
		for (int i = 0; i < numOfElm; i++)
		{
			std::cout << i + 1 << ": " << arrayOfTemp[i] << std::endl;
		}

	}

	template <typename type>
	bool sizeCheck(const Collection<type>& leftC, const Collection<type>& rightC) {
		return leftC.size() > rightC.size();
	};






}
#endif // !SDDS_SEARCH_H_

