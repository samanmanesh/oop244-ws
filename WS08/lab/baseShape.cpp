// ===================================================================================
//  Workshop: #8
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2021-11-18
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "baseShape.h"
using namespace sdds;
using namespace std;

namespace sdds
{

	baseShape::~baseShape()
	{
	}

	ostream& operator<<(ostream& ostr, const baseShape& RO) {
		RO.drawShape(ostr);
		return ostr;
	};

	istream& operator>>(istream& istr, baseShape& RO) {
	 RO.readShape(istr);	
	 return istr;
	};
}