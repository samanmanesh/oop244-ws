#include <iostream>
#include "EggCarton.h"
using namespace std;
using namespace sdds;



namespace sdds {

	EggCarton::EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false) {
		
		if (size % 6 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
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

 
}