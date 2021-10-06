// ===================================================================================
//  Workshop: #4
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_COUNTRY_H
#define SDDS_COUNTRY_H
#include "City.h"
namespace sdds {

	class Country
	{
		const int MAX_CITY = 20; //maximum number of cities
		
		char* m_name;//points to a dynamically allocated Cstring holding the Country name
		
		int m_noOfCity;//size of the dynamically allocated array of cities
		
		City* m_city = nullptr;//pointer to the dynamically allocated array of cities

		void setEmpty();

	public:
		
		Country();

		Country(const char* name, int noOfCity, const City* cities);

		void setName(const char* name);
		
		Country& addCity(const City& c);

		Country& migrate(int people);

		bool isEmpty()const;

		~Country();

		void display()const;


	};

}

#endif