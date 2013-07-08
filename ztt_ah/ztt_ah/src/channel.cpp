/********************************************//**
 * \file   channel.cpp
 * \brief  Kana³
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
//-----------------------------------------------
void Channel::addNoise(list<complex<double>>*ptrlistMod)
{
	calcNoisePower();
	
	for(list<complex<double>>::iterator it=ptrlistMod->begin();it!=ptrlistMod->end();++it)
	{
		
		lst.push_back(complex<double>((noisePower/2)*Uniform()+it->real(),(noisePower/2)*Uniform()+it->imag()));
	}
	
}
//-----------------------------------------------
void Channel::disp()
{
	for(list<complex<double>>::iterator it=lst.begin();it!=lst.end();++it)
	{
		cout<<(*it)<<endl;
	}
	cout<<endl;
}
/////////////////////////////////////////////////
//***********************************************