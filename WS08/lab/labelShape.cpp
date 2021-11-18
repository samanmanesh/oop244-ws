// ===================================================================================
//  Workshop: #8
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2021-11-18
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================
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
		
	};
}