#ifndef SDDS_BASESHAPE_H
#define SDDS_BASESHAPE_H
#include <iostream>

namespace sdds
{
	
	class baseShape
	{


	public:
		//baseShape();

		virtual void drawShape(std::ostream& ostr)const =0;

		virtual void readShape(std::istream& istr) = 0;


		virtual ~baseShape();

	};

	std::ostream& operator<<(std::ostream& ostr, const baseShape& RO);
	
	std::istream& operator>>(std::istream& istr, baseShape& RO);

	/*baseShape::baseShape()
	{
	}*/

	
	
	
}
#endif


