#include <iostream>
#include "EggCarton.h"
using namespace std;
using namespace sdds;



namespace sdds {

	EggCarton::EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false) {
		
		if (((m_size % 6) == 0) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
		{
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumboSize = jumboSize;
		}
		else
		{
			setBroken();

		}

	};

	void EggCarton::setBroken() {
		m_size = -1;
		m_noOfEggs = -1;
	}

	ostream& EggCarton::display(std::ostream& ostr) const {
		
		std::cout << "check" << bool();
		 
		if (bool()) {
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumboSize ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else
		{
			cout << "Broken Egg Carton!" << endl;
		}

		return ostr;
	};
 

	istream& EggCarton::read(std::istream& istr) {
		char singleLetter;
		cin >> singleLetter;
		cin.ignore(1, ',');
		cin >> m_size;
		cin.ignore(1, ',');
		cin >> m_noOfEggs;

		singleLetter == 'j' ? m_jumboSize = true : m_jumboSize = false;

		if (!(((m_size % 6) == 0) && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size)) setBroken();

	}

	 EggCarton::operator bool() const { return(m_size > 0); };

	 

}