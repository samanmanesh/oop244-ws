// ===================================================================================
//  Workshop: #4
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-7
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "City.h"
using namespace std;
using namespace sdds;

namespace sdds {
	
	City::City() {
		setEmpty();
	};
	
	City::City(const char* name, int population) {
		
		if (name != nullptr && name[0] != 0 && population >= 0) {
			setCityName(name);
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

	void City::setCityName(const char* name) {
	
		if (name != nullptr) {
			strcpy(m_cityName, name);
		}
		else {
			m_cityName[0] = '\0';
		}
	
	};

	void City::setPopulation(int population) {
		if (population < POPULATION) {
			m_population = population;
		}
		else {
			m_population = -1;
		};
	
	};

	void City::addPopulation(int population) {

		if (population < POPULATION) {

			m_population += population;
		};

		if (m_population > POPULATION) {

			m_population = POPULATION;
		};
	};


	bool City::isEmpty()const {
		return(m_cityName[0] == 0 || m_population < 0);
	};

	int City::getPeople()const {
		return m_population;
	};

	

	void City::display()const {
		
		if (!isEmpty())
		{
			cout << "|";
			cout.width(30);
			cout.setf(ios::left);
			cout << m_cityName;
			cout.unsetf(ios::left);
			cout << "|";
			cout.width(10);
			cout << m_population;
			cout << "|" << endl;

		}else
		{
			cout << "Invalid city" << endl;
		}
	};


}