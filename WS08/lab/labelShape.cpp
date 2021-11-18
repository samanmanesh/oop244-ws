
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "labelShape.h"
using namespace sdds;
using namespace std;

namespace sdds
{
	char* labelShape::label()const {
		/*const char cp_label = *m_label;
		return  (cp_label);*/
		return(m_label);
	};

	labelShape::labelShape(){}

	labelShape::labelShape(const char* label) {
		delete[] m_label;
		if (label && label[0])
		{
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	};
	
	labelShape::~labelShape()
	{
		delete[] m_label;
	}

	void labelShape::readShape(std::istream& istr) {

		string tmp;
		getline(istr, tmp, ',');

		delete[] m_label;
		m_label = new char[strlen(tmp.c_str()) + 1];
		strcpy(m_label, tmp.c_str());
		
		//my own method to gets string without knowin size and usin <string>
		/*const int size = 128;
		char* tmp= new char[size];
		istr.getline(tmp, size, ',');

		if (istr.fail())
		{
			char* doubleTmp = new char[(size * 2) + 1];
			strcpy(doubleTmp, tmp);
			delete[] tmp;

		}*/
	};
}