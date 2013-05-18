/********************************************//**
 * \file   airport.h
 * \brief  Definicja obiektu koder.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#ifndef CODER_H
#define CODER_H
/////////////////////////////////////////////////
/*! \brief Koder.
 *
 *	Implementacja Koder.
 *
 */
struct dataCod
{
	int value;	//!< Warto��.
	int nextState;	//!< Nast�pny stan kodera.
	//! Konsturktor domy�lny.
	dataCod();
	//! Konstruktor.
	dataCod(int val,int stat):value(val),nextState(stat)
	{
	};
};

class Coder
{
	

public:
	 dataCod* tab[4][4];

	Coder();

private:

};

/////////////////////////////////////////////////
//***********************************************
#endif /*CODER_H*/