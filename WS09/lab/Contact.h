// ===================================================================================
//  Workshop: #9
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2021-11-25
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
#include "Person.h"
#include "Utils.h"

namespace sdds {

	class Contact : public Person
	{
		char* m_address{};
		char* m_city{};
		char m_province[3]{};
		char m_postalCode[7]{};
	public:
		Contact();
		Contact(const Contact& copyFrom);
		Contact& operator=(const Contact& RightOperand);
		~Contact();

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

		// returns true if the name is valid; 
	 // a valid name has a first and a last name
	 // and they are not empty
		virtual operator bool()const;
		// deallocates the dynamic memory
		virtual void operator~();

	};
}

#endif
