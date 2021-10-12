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





   };

}
#endif