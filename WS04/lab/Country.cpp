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
#include "Country.h"
using namespace std;
using namespace sdds;

namespace sdds {

	Country::Country() {
		setEmpty();
	};

	Country::Country(const char* name, int noOfCity, const City* cities) {
		
		setEmpty();
		
		if (name != nullptr && name[0] != 0 && noOfCity < MAX_CITY && noOfCity > 0 && cities != nullptr)
		{
			setName(name);
			m_noOfCity = noOfCity;
			m_city = new City[m_noOfCity];	  

			for (int i = 0; i < m_noOfCity; i++)
			{	
				m_city[i] = cities[i];
			}
		}
	};

	void Country::setEmpty() {
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	};

	void Country::setName(const char* name) {
		delete m_name;
		m_name = nullptr;
		if (name != nullptr && name[0] != 0)
		{
			char* newName = nullptr;
			newName = new char[strlen(name) + 1];
			strcpy(newName, name);
			m_name = newName;
			newName = nullptr;

		}
		else
		{
			delete[] m_city;
			setEmpty();
		}


	};


	Country& Country::addCity(const City& c) {

		if (!c.isEmpty()) {
			City* newCity = nullptr;
			newCity = new City[m_noOfCity + 1];

			for (int i = 0; i < m_noOfCity; i++)
			{
				newCity[i] = m_city[i];		
			}

			delete[] m_city;
			newCity[m_noOfCity] = c;
			m_noOfCity++;
			m_city = newCity;
			newCity = nullptr;

		}
		return *this;
	};

	Country& Country::migrate(int people) {
		
		for (int i = 0; i < m_noOfCity; i++)
		{
			if (m_city[i].getPeople() < POPULATION) {

				m_city[i].addPopulation(people);
			}
		}
		return *this;
	};

	bool Country::isEmpty()const {
	
		return (m_name == nullptr);
	};

	Country::~Country() {
		delete m_name;
		delete[] m_city;
	};


	void Country::display()const {
		
		if (!isEmpty()) {

			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout.width(32);
			cout.setf(ios::left);
			cout << "City name";
			cout.unsetf(ios::left);
			cout << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i].display();
			}
		}
		else
		{
			cout << "Invalid country object" << endl;
		}

	};


}