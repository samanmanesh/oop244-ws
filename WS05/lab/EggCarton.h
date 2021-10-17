// ===================================================================================
//  Workshop: #5
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-14
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
namespace sdds {

	const int RegularEggWieght = 50;
	const int JumboEggWieght = 75;

	class EggCarton {

		int m_size;
		int m_noOfEggs;
		bool m_jumboSize;

		void setBroken();

	public:

		EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

		std::ostream& display(std::ostream& ostr = std::cout) const;

		std::istream& read(std::istream& istr = std::cin);

		operator bool() const;
		operator int() const;
		operator double() const;

		EggCarton& operator--();
		EggCarton& operator++();
		EggCarton operator--(int);
		EggCarton operator++(int);


		EggCarton& operator=(int value);
		EggCarton& operator+=(int value);
		EggCarton& operator+=(EggCarton& right);
		bool operator==(const EggCarton& right) const;
	};

	int operator+(int left, const EggCarton& right);

	std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);

	std::istream& operator>>(std::istream& istr, EggCarton& right);
}
#endif
