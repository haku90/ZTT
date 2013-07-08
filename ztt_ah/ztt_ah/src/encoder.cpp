/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  ZTT Symulacja program g³ówny
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
//-----------------------------------------------
Encoder::Encoder()
{
	for(int i=0;i<6;i++)
		tab[i]=0;
}
//-----------------------------------------------
int Encoder::encode(int input)
{
	int ans=0;
	int lsb=0; //dol
	int msb=0; //gora
	lsb=input^tab[0]^tab[1]^tab[2]^tab[5];
	msb=input^tab[1]^tab[2]^tab[4]^tab[5];
		int mask=1;
		ans=mask*lsb;
		mask<<=1;
		ans+=mask*msb;
		next();
		tab[0]=input;
	return ans;
}
//-----------------------------------------------
void Encoder::next()
{
	for(int i=5;i>0;i--)
		tab[i]=tab[i-1];
}
//-----------------------------------------------
void Encoder::create(int size)
{
	double bit=0;
	
	for(int i=0;i<size;i++)
	{
	bit=Normal();
	if(bit>0.5)
		bit=1;
	if(bit<0.5)
		bit=0;
	lst.push_back(encode(bit));
	dispTabEncoder();
	}
}
//-----------------------------------------------
void Encoder::disp()
{

	for(list<int>::iterator it=lst.begin();it!=lst.end();++it)
	{
		cout<<(*it)<<" ";
	}
	cout<<endl;

}
/////////////////////////////////////////////////
//***********************************************