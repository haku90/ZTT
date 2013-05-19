/********************************************//**
 * \file   channel.h
 * \brief  Definicja obiektu odbiornik.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#ifndef RECEIVER_H
#define	RECEIVER_H
/////////////////////////////////////////////////
/*! \brief Odbiornik.
 *
 *	Implementacja Odbiornika.
 *
 */
class Receiver:public MOD,public Coder
{
public:

	Receiver();					//!< Konstruktor.
	
	double tabActualDist[8];	//!< Tablica akutalnych odleg³oœci.

	void calcSurviever(list <complex<double>>* pDataWithNoise);
	void calcDistance(complex<double> num);
	int min();				//!< Funkcja zwraca indeks najmniejszego elementu w tablicy.

private:

};
/////////////////////////////////////////////////
//***********************************************
#endif /*RECEIVER_H*/