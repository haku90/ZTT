/********************************************//**
 * \file   mod.cpp
 * \brief  Modulator
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-05
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
//-----------------------------------------------
Mod::Mod()
{
	ModTab[0]=complex<double>(-1,-1);
	ModTab[1]=complex<double>(-1,1);
	ModTab[2]=complex<double>(1,-1);
	ModTab[3]=complex<double>(1,1);
}
//-----------------------------------------------
void Mod::create(list<int>*ptrlst)
{
	for(list<int>::iterator it=ptrlst->begin();it!=ptrlst->end();++it)
	{
		lst.push_back(execute((*it)));
	}
}
//-----------------------------------------------
void Mod::disp()
{
	for(list<complex<double>>::iterator it=lst.begin();it!=lst.end();++it)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;
}
/////////////////////////////////////////////////
//***********************************************