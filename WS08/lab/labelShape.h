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
#ifndef SDDS_LABELSHAPE_H
#define SDDS_LABELSHAPE_H
#include <iostream>
#include "baseShape.h"
namespace sdds
{

	class labelShape : public baseShape
	{
		char* m_label{};

	public:
		labelShape();

		labelShape(const char* label);

		labelShape(const labelShape& lbs) = delete;

		void operator = (const labelShape& lbs) = delete;

		~labelShape();

		void readShape(std::istream& istr);

	protected:
		char* label()const;
	};
}
#endif


