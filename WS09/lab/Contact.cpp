
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
		Person::read(istr);
		~*this;
		m_address = dynRead(istr, ',');
		if (!m_address || !m_address[0])
			istr.setstate(std::ios::failbit);
		m_city = dynRead(istr, ',');
		if (!m_city[0] || !m_city ) 
			istr.setstate(std::ios::failbit);
		istr.getline(m_province, 2 + 1, ',');
		
		if (strlen(m_province) != 2 && m_province[0] == '\0' )
		//if (!m_province )
		{
			istr.setstate(ios::failbit);
			//istr.setstate(std::ios::failbit);
			//istr.ignore(100, ',');
		}
		istr.getline(m_postalCode, 6 + 1, '\n');
		if (strlen(m_postalCode) != 6 && m_postalCode[0]=='\0')
		//if (!m_postalCode)
		{
			istr.setstate(std::ios::failbit);
		}
		//if(this)istr.setstate(std::ios::failbit);

		if (istr.fail()) ~*this;
		return istr;
 	}

	std::ostream& Contact::write(std::ostream& ostr)const {

		if (*this) {

			Person::write(ostr);
			ostr << endl;
			ostr << m_address << endl;
			ostr << m_city << " " << m_province << endl;
			
						
			for (int i = 0; i < strlen(m_postalCode)/2; i++)
			{
				ostr << m_postalCode[i];
			}
			//ostr << m_postalCode;
			ostr << " ";
			for (int i = strlen(m_postalCode) / 2; i < strlen(m_postalCode) ; i++)
			{
				ostr << m_postalCode[i];
			}
			ostr << endl;
		}
		return ostr;


	};

	void Contact::operator~() {
		delete[] m_address;
		delete[] m_city;
		m_province[0] = { 0 };
		m_postalCode[0] = { 0 };

		m_address = m_city = nullptr;
	}

	Contact::operator bool()const {
		return m_address && m_city && m_province[0] && m_postalCode[0];
	};

}
