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
#include "lineLabel.h"
using namespace sdds;
using namespace std;

namespace sdds
{
	lineLabel::lineLabel() :labelShape()
	{
		m_length = 0;
	}

	lineLabel::lineLabel(const char* label, int length) : labelShape(label) {
		m_length = length;
	};


	lineLabel::~lineLabel() {}

	void lineLabel::readShape(std::istream& istr) {

		labelShape::readShape(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	};

	void lineLabel::drawShape(std::ostream& ostr)const {
	
		if (m_length > 0 &&  label() != nullptr)
			{
			ostr << label();
			ostr << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << "=";
			ostr.fill(' ');
		}
	};

}


