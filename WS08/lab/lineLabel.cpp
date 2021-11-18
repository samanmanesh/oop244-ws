
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
		//in case we use pointer
		if (m_length > 0 &&  label() != nullptr)
		//if (m_length > 0 && label() != NULL)
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


