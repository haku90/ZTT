/********************************************//**
 * \file   receiver.cpp
 * \brief  Definicja obiektu odbiornik.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
//-----------------------------------------------
Receiver::Receiver()
{
	
}
//-----------------------------------------------
void Receiver::calcSurviever(list <complex<double>>* pDataWithNoise)
{
	int state=0;
	for(list<complex<double>>::iterator it=pDataWithNoise->begin();it!=pDataWithNoise->end();++it)
	{
		calcDistance(*it);
		
	}

}
//-----------------------------------------------
void Receiver::calcDistance(complex<double> num)
{
		for(int i=0;i<8;i++)
		tabActualDist[i]=sqrt(pow(num.imag()-MOD::tab[i]->imag(),2)+pow(num.real()-MOD::tab[i]->real(),2));
}
//-----------------------------------------------
int Receiver::min()
{
	double min=tabActualDist[0];
	int indeks=0;
	for(int i=0;i<8;i++)
	{
		if(min>tabActualDist[i])
		{
			min=tabActualDist[i];
			indeks=i;
		}
	
	}
	return indeks;
}
/////////////////////////////////////////////////
//***********************************************
