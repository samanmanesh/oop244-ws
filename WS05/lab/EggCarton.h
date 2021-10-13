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
		
	   EggCarton(int size , int noOfEggs, bool jumboSize );

	   // I think I should use this one 
	    std::ostream& display(std::ostream& ostr = std::cout) const;
	   //std::ostream& display(std::ostream& ostr) const;


	   std::istream& read(std::istream& istr = std::cin);

       operator bool() const;
	   operator int() const;
	   operator double() const;

	   EggCarton& operator--();
	   EggCarton& operator++();
	   EggCarton& operator--(int);
	   EggCarton& operator++(int);


	   EggCarton& operator=(int value);
	   EggCarton& operator+=(int value);
	   EggCarton& operator+=(EggCarton& right);
	   bool operator==(const EggCarton& right) const;
   };

   int operator+(int left, const EggCarton& right);

   std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);

   istream& operator>>(istream& istr, EggCarton& right);
}
#endif