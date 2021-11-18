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
#ifndef SDDS_RECTANGLELABEL_H
#define SDDS_RECTANGLELABEL_H
#include <iostream>
#include "labelShape.h"
namespace sdds
{
	class rectangleLabel : public labelShape
	{
		int m_width;
		int m_spaces;

	public:
		rectangleLabel();

		rectangleLabel(const char* label, int width, int space);

		~rectangleLabel();

		void drawShape(std::ostream& ostr)const;

		void readShape(std::istream& istr);
	};




}
#endif


