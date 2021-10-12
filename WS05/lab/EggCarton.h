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
	   // std::ostream& display(std::ostream& ostr = std::cout) const;
	   std::ostream& display(std::ostream& ostr) const;


	   std::istream& read(std::istream& istr);



       operator bool() const;


   };

}
#endif