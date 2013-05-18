/********************************************//**
 * \file   channel.cpp
 * \brief  Definicja obiektu kana³.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////

//-----------------------------------------------
Channel::Channel(){}
//-----------------------------------------------
double Channel::eSignal(list<complex<double>>* plt)
{
	double e=0;
	for(list<complex<double>>::iterator it=plt->begin();it!=plt->end();++it)
		e+=(pow(it->imag(),2))+(pow(it->real(),2));
	return e;
}
//----------------------------------------------
double Channel::amplitude(double eSignal,double N0)
{
	double eS=0;
	eS=eSignal/8;

	return 0.5*sqrt(eS*pow(10,-(eS/N0)/10));

}
//----------------------------------------------
complex<double>Channel::partOfNoise(double amplitude)
{
	return complex<double>(amplitude*Normal(),amplitude*Normal());
}
/////////////////////////////////////////////////
//***********************************************
