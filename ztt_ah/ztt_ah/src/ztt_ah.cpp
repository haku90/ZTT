/********************************************//**
 * \file   ztt_ah.cpp
 * \brief  ZTT Symulacja program g³ówny
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-02-28
 ***********************************************/
#include "ztt_ah.h"
/////////////////////////////////////////////////
ofstream cost1;
	
int main(int argc, char *argv[])
{
	cout<<"...........ZTT Symulacja............."<<endl;
	//deklaracja zmiennych
	Encoder *ptEncoder=new Encoder();
	Mod		*ptMod=new Mod();
	Channel *ptChannel=new Channel(100);
	Receiver *ptReceiver=new Receiver();
	cost1.open("./output/cost1.csv", ios_base::out | ios_base::trunc);
	/*
	//plik konfiguracyjny
	int param[1]={0};
	ifstream config;
	config.open("config.txt");
	string s;
	int a;
	config >> s >> a;
	int k=0;
	if(config.good())
	{
	while(k<1)
	{
	
	if(s=="SNR")
		param[SNR]=a;
	
	config >> s >> a;
	k++;
	}
	config.close();

	*/
	



	//generowanie bitow i kodowanie
	ptEncoder->create(10);
	//kodowania 
	cout<<"...........Kodowanie..........."<<endl;
	ptEncoder->disp();
	//Modulacja
	cout<<"...........Modulacja................."<<endl;
	ptMod->create(&ptEncoder->lst);
	ptMod->disp();
	cout<<"...........Kanal....................."<<endl;
	ptChannel->addNoise(&ptMod->lst);
	ptChannel->disp();
	cout<<"...........Odbiornik................."<<endl;
	/*
	cout<<ptReceiver->nextState(1)<<endl;
	ptReceiver->dispTabencoder();
	ptReceiver->loadEncoder(8);
	ptReceiver->dispTabencoder();
	*/
	
	ptReceiver->calcCost(ptChannel->lst.front());
	ptChannel->lst.pop_front();
	
	cost1.close();
	return 0;

}
/////////////////////////////////////////////////
//***********************************************