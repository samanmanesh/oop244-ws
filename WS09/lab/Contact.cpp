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

#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "Person.h"
#include "Contact.h"
using namespace sdds;
using namespace std;
namespace sdds {

	Contact::Contact() :Person()
	{
	};

	Contact::Contact(const Contact& copyFrom) :Person(copyFrom) {
		operator=(copyFrom);
	};

	Contact& Contact::operator=(const Contact& RightOperand) {
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
		~*this;
		Person::read(istr);
		m_address = dynRead(istr, ',');
		if (!m_address || !m_address[0])
			istr.setstate(std::ios::failbit);
		m_city = dynRead(istr, ',');
		if (!m_city || !m_city[0] )  // bad boy, lazy eveluation under considration ALWAYS
			istr.setstate(std::ios::failbit);
		istr.getline(m_province, 2 + 1, ',');
		if (strlen(m_province) != 2 )
		{
			istr.setstate(ios::failbit);
		}
		istr.getline(m_postalCode, 6 + 1, '\n');
		if (strlen(m_postalCode) != 6)
		{
			istr.setstate(std::ios::failbit);
		}

		if (istr.fail()) ~*this;
		return istr;
 	}

	std::ostream& Contact::write(std::ostream& ostr)const {

		if (*this) {

			Person::write(ostr);
			ostr << endl;
			ostr << m_address << endl;
			ostr << m_city << " " << m_province << endl;
			
			int i = 0;
			for ( i = 0; size_t(i) < strlen(m_postalCode)/2; i++)
			{
				ostr << m_postalCode[i];
			}
			ostr << " ";
			for ( i = strlen(m_postalCode) / 2; size_t(i) < strlen(m_postalCode) ; i++)
			{
				ostr << m_postalCode[i];
			}
			ostr << endl;
		}
		return ostr;


	};

	void Contact::operator~() {
		Person::operator~();
		delete[] m_address;
		delete[] m_city;
		m_province[0] = 0;
		m_postalCode[0] =  0;
		m_address = m_city = nullptr;
	}

	Contact::operator bool()const {
		return m_address && m_city && m_province[0] && m_postalCode[0];
	};

}
