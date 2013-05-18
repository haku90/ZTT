/********************************************//**
 * \file   channel.h
 * \brief  Definicja obiektu kana�.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#ifndef CHANNEL_H
#define	CHANNEL_H
/////////////////////////////////////////////////
/*! \brief Kana�.
 *
 *	Implementacja Kana�u.
 *
 */
class Channel
{
public:

	Channel();	//<! Konstruktor.
	double eSignal(list<complex<double>>* plt);
	double amplitude(double eSignal,double N0);
	complex<double> partOfNoise(double amplitude);
private:

};
/////////////////////////////////////////////////
//***********************************************
#endif /*CHANNEL_H*/