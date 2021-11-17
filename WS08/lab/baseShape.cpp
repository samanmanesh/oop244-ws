#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "baseShape.h"
using namespace sdds;
using namespace std;

namespace sdds
{
	/*void baseShape::drawShape(ostream& ostr)const {
	};

	void baseShape::readShape(istream& istr) {
	
	};*/

	ostream& operator<<(ostream& ostr, const baseShape& RO) {
		RO.drawShape(ostr);
		return ostr;
	};

	istream& operator>>(istream& istr, baseShape& RO) {
	 RO.readShape(istr);	
	 return istr;
	};
}