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

#ifndef SDDS_CITY_H
#define SDDS_CITY_H

namespace sdds {

	class City
	{
		const int POPULATION = 20000; //max population of a city
		char m_cityName[31];// holds the city name up to 30 chars
		int m_population;//number of people. A city can have zero population.

	public:
		
		City();
		
		City(const char* name, int population);

		void setEmpty();

	};

}

#endif