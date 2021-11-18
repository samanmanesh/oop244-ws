#ifndef SDDS_LINELABEL_H
#define SDDS_LINELABEL_H
#include <iostream>
#include "labelShape.h"
#include "baseShape.h"
namespace sdds
{
	class lineLabel :public labelShape
	{
		int m_length;

	public:
		lineLabel();

		lineLabel(const char* label, int length);

		~lineLabel();

		void readShape(std::istream& istr);

		void drawShape(std::ostream& ostr)const;



	};

	void lineLabel::readShape(std::istream& istr) {
	
		labelShape::readShape(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	};

	void lineLabel::drawShape(std::ostream& ostr)const {
		//in case we use pointer
		//if (m_length > 0 &&  label() != nullptr)
		if (m_length > 0 &&  label() != NULL)
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
#endif




