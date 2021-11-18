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


	};

	

	lineLabel::~lineLabel()
	{
	}
	

}
#endif




