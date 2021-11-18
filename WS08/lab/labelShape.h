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

		labelShape( const char* label);
		
		labelShape(const labelShape& lbs) = delete;

		void operator = (const labelShape& lbs) = delete;

		//labelShape& operator = (const labelShape& lbs) = delete;

		~labelShape();

		void readShape(std::istream& istr);


	protected:
		char* label()const;
	/*protected:
		char label()const;*/

	};

	/*char* labelShape::label()const {
		return  (*m_label);
	};*/

	
	

}
#endif


