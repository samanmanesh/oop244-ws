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


		 void drawShape(std::ostream& ostr)const ;

		 void readShape(std::istream& istr);




	};

	void rectangleLabel::readShape(std::istream& istr) {
	
		labelShape::readShape(istr);
		istr >> m_width;
		istr.get();
		istr >> m_spaces;
		istr.ignore(10000, '\n');
	};


}
#endif


