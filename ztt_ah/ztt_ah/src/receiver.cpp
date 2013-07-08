/********************************************//**
 * \file   receiver.cpp
 * \brief  Odbiornik
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-05
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
//-----------------------------------------------
Receiver::Receiver()
{
	for(int i=0;i<6;i++)
	tabEncoder[i]=0;

	ModTab[0]=complex<double>(-1,-1);
	ModTab[1]=complex<double>(-1,1);
	ModTab[2]=complex<double>(1,-1);
	ModTab[3]=complex<double>(1,1);
	for(int i=0;i<64;i++)
		for(int j=0;j<64;j++)
			cost[i][j]=0;
}
//-----------------------------------------------
int Receiver::nextState(int input)
{
	for(int i=5;i>0;i--)
		tabEncoder[i]=tabEncoder[i-1];
	
		tabEncoder[0]=input;
		int ans=0;
		int mask=32;
		for(int i=0;i<6;i++)
		{
			ans+=tabEncoder[i]*mask;
			mask>>=1;
		}
		return ans;
}
//-----------------------------------------------
void Receiver::loadEncoder(int state)
{
	int mask=32;
	for(int i=0;i<6;i++)
	{
		tabEncoder[i]=bool(mask&state);
		mask>>=1;
	}
}
//-----------------------------------------------
void Receiver::calcCost(complex<double> y)
{
	
	double temp,temp1;
	int s,State,State1;
	cost1<<"i"<<';'<<"Stan nastepny pod wplywem 0"<<';'<<"odleglosc"<<';'<<"stan nastepny pod wyplywem 1"<<';'<<"odleglosc"<<';'<<endl;
	for(int i=0;i<64;i++)
	{
		
			loadEncoder(i);
			s=sCalc(0);
			State=nextState(0);
			temp=cost[State][i]=calcE(y,ModTab[s]);
		
			loadEncoder(i);
			s=sCalc(1);
			State1=nextState(1);
			temp1=cost[State1][i]=calcE(y,ModTab[s]);
			cost1<<i<<';'<<State<<';'<<temp<<';'<<State1<<';'<<temp1<<';'<<endl;
			
		
		
	}
	
}
//-----------------------------------------------
int Receiver::sCalc(int input)
{
	int ans=0;
	int lsb=0; //dol
	int msb=0; //gora
	lsb=input^tabEncoder[0]^tabEncoder[1]^tabEncoder[2]^tabEncoder[5];
	msb=input^tabEncoder[1]^tabEncoder[2]^tabEncoder[4]^tabEncoder[5];
		int mask=1;
		ans=mask*lsb;
		mask<<=1;
		ans+=mask*msb;
		return ans;
}
/////////////////////////////////////////////////
//***********************************************