/********************************************//**
 * \file   e4_rk_ha.cpp
 * \brief  ZTT Symulacja program g³ówny
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	cout<<"...........ZTT Symulacja............."<<endl;
	list<int> ltData;
	list<complex<double>> ltEncoAndMod;
	for(int i=0;i<10;i++)
		ltData.push_back(i%4);
	Coder cd;
	MOD mod;
	cout<<"dane wejsciowe"<<endl;
	for(list<int>::iterator it=ltData.begin();it!=ltData.end();++it)
		cout<<*it<<endl;
	cout<<"..................."<<endl;
	mod.encodeAndMod(&cd,&ltData,&ltEncoAndMod);
	cout<<"..................."<<endl;
	cout<<"dane zakodowane i z odwzorowaniem"<<endl;
	for(list <complex<double>>::iterator it=ltEncoAndMod.begin();it!=ltEncoAndMod.end();++it)
		cout<<*it<<endl;
	

	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************