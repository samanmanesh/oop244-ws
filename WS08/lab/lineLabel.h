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
#ifndef SDDS_LINELABEL_H
#define SDDS_LINELABEL_H
#include <iostream>
#include "labelShape.h"
#include "baseShape.h"
namespace sdds
{
	class lineLabel :public labelShape
	{
		int m_length{};

	public:
		lineLabel();

		lineLabel(const char* label, int length);

		~lineLabel();

		void readShape(std::istream& istr);

		void drawShape(std::ostream& ostr)const;

	};

}
#endif




