
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
}


