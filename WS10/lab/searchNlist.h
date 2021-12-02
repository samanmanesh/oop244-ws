// ===================================================================================
//  Workshop: #10
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2021-12-2
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
namespace sdds {

	/*
	The check template requires:
	1- two different types
	2- a pointer of an array of template object
	3- overloaded operator[] of type1 (Collection)
	4- address of type2 for comparison
	5- == operator
	*/
	template<typename type1, typename type2>
	bool check(const type1* arrOfTmpObj, int index, const type2& keyValue) {
		bool result = false;

		result = arrOfTmpObj[index] == keyValue ? true : false;

		return result;
	}


	/*
	The search template requires:
	1- two different types
	2- a pointer of an array of template object
	3- overloaded operator[] of type1 (Collection)
	4- a reference of type1 for inserting and changing data
	*/
	template<typename type1, typename type2>
	bool search(const type1* arrOfTmpObj, int sizeOfArr, const type2& keyValue, Collection<type1>& Cl) {
		bool result = false;
		for (int i = 0; i < sizeOfArr; i++)
		{
			if (check(arrOfTmpObj, i, keyValue)) {
				Cl.add(arrOfTmpObj[i]);
				result = true;
			}
		}
		return result;
	}

	/*
	The listArrayElements template requires:
	1- overloaded operator[] of type
	*/
	template <typename type>
	void listArrayElements(const char* title, const type* arrayOfTemp, int numOfElm) {

		std::cout << title << std::endl;
		for (int i = 0; i < numOfElm; i++)
		{
			std::cout << i + 1 << ": " << arrayOfTemp[i] << std::endl;
		}

	}

	/*
	 The listArrayElements template requires:
	 1- reference of two instance of the same compound type.

	*/

	template <typename type>
	bool sizeCheck(const Collection<type>& leftC, const Collection<type>& rightC) {
		return leftC.size() > rightC.size();
	};
}
#endif // !SDDS_SEARCH_H_

