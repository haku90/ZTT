/********************************************//**
 * \file   encoder.h
 * \brief  Plik naglowkowy dla kodera.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-03
 ***********************************************/
#ifndef ENCODER_H
#define ENCODER_H
/////////////////////////////////////////////////
/*! \brief koder.
 *
 *	Implementacja kodera
 *
 */
class Encoder
{
public:

	Encoder();
	int tab[6];
	list<int> lst;
	int encode(int input);
	void next();
	void create(int size);
	void disp();
	void dispTabEncoder()
	{
		for(int i=0;i<6;i++)
			cout<<tab[i]<<" ";
			cout<<endl;
	}
};

/////////////////////////////////////////////////
//***********************************************
#endif /*ENCODER_H */
