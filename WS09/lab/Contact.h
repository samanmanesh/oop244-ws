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

	Contact::Contact() :Person()
	{
	};

	Contact::Contact(const Contact& copyFrom) :Person(copyFrom) {
		operator=(copyFrom);
	};

	Contact& Contact::operator=(const Contact& RightOperand){
		if (this != &RightOperand) {
			Person::operator=(RightOperand);
			delAlloCopy(m_address, RightOperand.m_address);
			delAlloCopy(m_city, RightOperand.m_city);
			strcpy(m_province, RightOperand.m_province);
			strcpy(m_postalCode, RightOperand.m_postalCode);
		}
		return *this;
	}

	Contact::~Contact()
	{
		~*this;
	}
	
	std::istream& Contact::read(std::istream& istr) {
		Person::read(istr);
		~*this;
		m_address = dynRead(istr, ',');
		m_city = dynRead(istr, ',');
		istr.getline(m_province, 2 + 1,',');
		if ( strlen(m_province) != 2)
		{
			istr.setstate(std::ios::failbit);
			istr.ignore(100, ',');
		}
		istr.getline(m_postalCode, 6 + 1, '\n');
		if (strlen(m_postalCode) != 6)
		{
			istr.setstate(std::ios::failbit);
		}

		if (istr.fail()) ~*this;
		return istr;
	}


	void Contact::operator~() {
		delete[] m_address;
		delete[] m_city;
		m_address = m_city = nullptr;
	}
}

#endif
