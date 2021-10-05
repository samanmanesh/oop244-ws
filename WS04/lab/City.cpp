

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "City.h"
using namespace std;
using namespace sdds;

namespace sdds {
	
	City::City() {

		m_cityName[0] = '\0';
		m_population = -1;
	};
	
	City::City(const char* name, int population) {
		
		if (name != nullptr && name[0] != 0 && population >= 0) {

			strcpy(m_cityName, name);
			m_population = population;
		}
		else
		{
			setEmpty();
		}

	};


	void City::setEmpty() {

		m_cityName[0] = '\0';
		m_population = -1;
	};

}