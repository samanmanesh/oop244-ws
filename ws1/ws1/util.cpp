// ===================================================================================
//  Workshop: #1
//  Part: 1 (Lab) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Course Section: OOP244-NAA
// ===================================================================================

#include <iostream>
#include "util.h"
using namespace std;


namespace sdds {

	bool confirm() {
		char choice = cin.get();
		clearBuffer();
		return choice == 'Y';
	}

	void clearBuffer() {
		while (cin.get() != '\n');
	}
}