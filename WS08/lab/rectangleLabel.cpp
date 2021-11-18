
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "rectangleLabel.h"
using namespace sdds;
using namespace std;

namespace sdds
{

	rectangleLabel::rectangleLabel() :labelShape()
	{
		m_width = 0;
		m_spaces = 0;
	}

	rectangleLabel::rectangleLabel(const char* label, int width, int spaces) :labelShape(label) {

		m_width = width;
		m_spaces = spaces;
		
		int strLen = strlen(labelShape::label());
		if (m_width < strLen + m_spaces + 2)     
			m_width = 0;
	};

	rectangleLabel::~rectangleLabel() {}


	void rectangleLabel::readShape(std::istream& istr) {

		labelShape::readShape(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_spaces;
		istr.ignore(10000, '\n');
	};

	void rectangleLabel::drawShape(std::ostream& ostr)const {

		if (m_width && m_spaces)
		{
			//first line
			ostr << "+";
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << "-";
			ostr.fill(' ');
			ostr << "+" << endl;
			//second line
			ostr << "|";
			ostr.width(m_spaces);
			ostr << " ";
			ostr.width(m_width - m_spaces-2);
			ostr.setf(ios::left);
			ostr << label();
			ostr.unsetf(ios::left);
			ostr << "|" << endl;
			
			//last line
			ostr << "+";
			ostr.width(m_width - 2);
			ostr.fill('-');
			ostr << "-";
			ostr.fill(' ');
			ostr << "+" << endl;
		}

	};
}


