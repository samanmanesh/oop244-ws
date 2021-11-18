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

	private:

	};

	


}
#endif


