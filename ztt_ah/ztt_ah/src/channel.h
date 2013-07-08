/********************************************//**
 * \file   mod.h
 * \brief  Plik naglowkowy dla kana³u.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-05
 ***********************************************/
#ifndef CHANNEL_H
#define CHANNEL_H
/////////////////////////////////////////////////
/*! \brief Kana³.
 *
 *	Implementacja Kana³u.
 *
 */
class Channel
{
public:
	double SNR;
	double noisePower;
	list<complex<double>>lst;
	Channel(double S):SNR(S){};
	void calcNoisePower(){noisePower=1/SNR;}
	void addNoise(list<complex<double>>*ptrlistMod);
	void disp();
	
};

/////////////////////////////////////////////////
//***********************************************
#endif /*CHANNEL_H */
