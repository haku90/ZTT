/********************************************//**
 * \file   coder.cpp
 * \brief  Definicja obiektu koder.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////

//-----------------------------------------------
Coder::Coder()
{
	tab[0][0]=new dataCod(0,0);
	tab[1][0]=new dataCod(2,2);
	tab[2][0]=new dataCod(4,0);
	tab[3][0]=new dataCod(6,2);

	tab[0][1]=new dataCod(2,0);
	tab[1][1]=new dataCod(0,2);
	tab[2][1]=new dataCod(6,0);
	tab[3][1]=new dataCod(4,2);

	tab[0][2]=new dataCod(1,1);
	tab[1][2]=new dataCod(3,3);
	tab[2][2]=new dataCod(5,1);
	tab[3][2]=new dataCod(7,3);

	tab[0][3]=new dataCod(3,1);
	tab[1][3]=new dataCod(1,3);
	tab[2][3]=new dataCod(7,1);
	tab[3][3]=new dataCod(5,3);
	


}

/////////////////////////////////////////////////
//***********************************************
