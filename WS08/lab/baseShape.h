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
#ifndef SDDS_BASESHAPE_H
#define SDDS_BASESHAPE_H
#include <iostream>

namespace sdds
{
	class baseShape
	{
	public:

		virtual void drawShape(std::ostream& ostr)const = 0;

		virtual void readShape(std::istream& istr) = 0;

		virtual ~baseShape();
	};

	std::ostream& operator<<(std::ostream& ostr, const baseShape& RO);

	std::istream& operator>>(std::istream& istr, baseShape& RO);
}
#endif


