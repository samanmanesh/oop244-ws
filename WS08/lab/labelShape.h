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

		~labelShape();

	/*protected:
		char* label()const;*/
	protected:
		char label()const;

	};

	/*char* labelShape::label()const {
		return  (*m_label);
	};*/

	char labelShape::label()const {
		const char cp_label = *m_label;
		return  (cp_label);
	};

	labelShape::labelShape()
	{
	}

	labelShape::~labelShape()
	{
	}

}
#endif


