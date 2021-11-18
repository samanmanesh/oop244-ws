
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
		// there is some note I didn't get from instructions! m_width =0 ?

	};

	rectangleLabel::~rectangleLabel() {}
}


