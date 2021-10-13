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

	ostream& EggCarton::display(std::ostream& ostr = std::cout) const {

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


	EggCarton::operator int() const {
		int result;
		
		if (bool()) {
			result = m_noOfEggs;
		}
		else
		{
			result = -1;
		}

		return result;
	};

	EggCarton::operator double() const {

		double totalWeight;

		if (!bool()) return -1;


		if (m_jumboSize)
		{
			//(noOfEggs x WeightOfOnEgg) / 1000.0

			totalWeight = (m_noOfEggs * JumboEggWieght) / 1000.0;

		}
		else {
			totalWeight = (m_noOfEggs * RegularEggWieght) / 1000.0;
		}

		/*if (bool())
		{ return totalWeight; }
		else
		{
			return -1;
		} */
		return totalWeight;
	};


	EggCarton& EggCarton::operator--() {

		if (bool() && m_noOfEggs > 0) {

			m_noOfEggs--;
		}
		return *this;
	};

	EggCarton& EggCarton::operator++() {

		if (bool()) {

			m_noOfEggs++;
		}

		if (m_noOfEggs > m_size) { setBroken(); };

		return *this;
	};

	//returns the local copy by value.! Mybe needs to send the m_noOfEggs

	EggCarton& EggCarton::operator--(int) {

		EggCarton copy = *this;
		--(*this);
		return copy;
	};


	EggCarton& EggCarton::operator--(int) {

		EggCarton copy = *this;
		++(*this);
		return copy;
	};


	EggCarton& EggCarton::operator=(int value) {

		m_noOfEggs = value;
		if (m_noOfEggs > m_size) { setBroken(); }
		return *this;
	}

	EggCarton& EggCarton::operator+=(int value) {

		m_noOfEggs += value;
		if (m_noOfEggs > m_size) { setBroken(); };

		return *this;
	};

	EggCarton& EggCarton::operator+=(EggCarton& right) {

		if (bool())
		{
			m_noOfEggs += right.m_noOfEggs;

			if (m_noOfEggs > m_size)
			{
				right.m_noOfEggs = m_noOfEggs - m_size;
			}
		}
		return *this;
	};

	bool EggCarton::operator==(const EggCarton& right) const {
		bool result;
		double currentWeight;
		double rightWeight;

		currentWeight = m_jumboSize ? (m_noOfEggs * JumboEggWieght/ 1000.0) : (m_noOfEggs * RegularEggWieght / 1000.0);
		
		rightWeight = right.m_jumboSize ? (right.m_noOfEggs * JumboEggWieght / 1000.0) : (right.m_noOfEggs * RegularEggWieght / 1000.0);
			
		double difference = currentWeight - rightWeight;
		if (difference>= -0.001 && difference <= 0.001 )
		{
			result = true;
		}
		else
		{
			result = false;
		}

		return result;
	}

	int operator+(int left, const EggCarton& right) {

		int result;
		if (right)
		{
			// OOP - 2217 OOP244 NAA missing Session time : 1:05:00 youtube video to watch
			//result = left + (int)right;

			result = EggCarton(left + (int)right);
		}
		else
		{
			result = left;
		}

		return result;
	}

	ostream& operator<<(ostream& ostr, const EggCarton& right) {

		return (right.display(ostr));
	};
}