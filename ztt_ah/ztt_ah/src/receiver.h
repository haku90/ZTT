/********************************************//**
 * \file   receiver.h
 * \brief  Plik naglowkowy dla odbiornika.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-05
 ***********************************************/
#ifndef RECEIVER_H
#define RECEIVER_H
/////////////////////////////////////////////////
/*! \brief Odbiornik.
 *
 *	Implementacja odbiornika.
 *
 */
class Receiver
{
public:

	Receiver();

	int tabEncoder[6];
	compx ModTab[4];
	double cost[64][64];


	int nextState(int input);
	void loadEncoder(int state);
	void dispTabencoder()
	{
		for(int i=0;i<6;i++)
			cout<<tabEncoder[i]<<" ";
		cout<<endl;
	}
	double calcE(complex<double> y,complex<double> x){return sqrt(pow((y.real()-x.real()),2)+pow((y.imag()-x.imag()),2));}
	void calcCost(complex<double> y);
	int sCalc(int input);
};
/////////////////////////////////////////////////
//***********************************************
#endif /*RECEIVER_H */
