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
	list<complex<double>> ltNoisePlusData;

	Coder cd;
	MOD mod;
	Channel ch;
	double gen;
	int data;

	for(int i=0;i<100;i++)
	{
		gen=Uniform();
		if(gen>0.&& gen<0.25)
			data=0;
		if(gen>=0.25 && gen<0.5)
			data=1;
		if(gen>=0.5&& gen<0.75)
			data=2;
		if(gen>=0.75&& gen<1)
			data=3;
		ltData.push_back(data);
	}

	cout<<"dane wejsciowe"<<endl;
	for(list<int>::iterator it=ltData.begin();it!=ltData.end();++it)
		cout<<*it<<endl;
	cout<<"..................."<<endl;

	mod.encodeAndMod(&cd,&ltData,&ltEncoAndMod);
	cout<<"..................."<<endl;
	cout<<"dane zakodowane i z odwzorowaniem"<<endl;
	for(list <complex<double>>::iterator it=ltEncoAndMod.begin();it!=ltEncoAndMod.end();++it)
		cout<<*it<<endl;
	
	double eSignal=ch.eSignal(&ltEncoAndMod);
	double amplitude=ch.amplitude(eSignal,1);
	
	for(list<complex<double>>::iterator it=ltEncoAndMod.begin();it!=ltEncoAndMod.end();++it)
		ltNoisePlusData.push_back(*it+ch.partOfNoise(amplitude));
	cout<<"..................."<<endl;

	cout<<"Dane zaszumione"<<endl;
	for(list<complex<double>>::iterator it=ltNoisePlusData.begin();it!=ltNoisePlusData.end();++it)
		cout<<*it<<endl;
	cout<<"..................."<<endl;

	return 0;
	
}
/////////////////////////////////////////////////
//***********************************************