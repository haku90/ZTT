/********************************************//**
 * \file   mod.cpp
 * \brief  Definicja obiektu modulator.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////

//-----------------------------------------------
MOD::MOD()
{
	tab[0]=new complex<double>(-0.7071,-0.7071);
	tab[1]=new complex<double>(-1.,0.);
	tab[2]=new complex<double>(0.,1.);
	tab[3]=new complex<double>(-0.7071,0.7071);
	tab[4]=new complex<double>(0.,-1.);
	tab[5]=new complex<double>(0.7071,-0.7071);
	tab[6]=new complex<double>(0.7071,0.7071);
	tab[7]=new complex<double>(1,0);
	
}
//-----------------------------------------------
void MOD::encodeAndMod(Coder* pCode,list<int>* pLtData,list<complex<double>>* plLtEncoAndMod)
{
	int state=0;
	int data;
	int val;

	for(list<int>::iterator it=pLtData->begin();it!=pLtData->end();++it)
	{
	data=*it;
	val=pCode->tab[data][state]->value;
	cout<<"wartosc po zakodowaniu: "<<val<<endl;
	state=pCode->tab[data][state]->nextState;
	plLtEncoAndMod->push_back(*tab[val]);
	
	}
}
/////////////////////////////////////////////////
//***********************************************
