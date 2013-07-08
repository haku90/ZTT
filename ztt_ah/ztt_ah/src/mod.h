/********************************************//**
 * \file   mod.h
 * \brief  Plik naglowkowy dla modulatora.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-07-05
 ***********************************************/
#ifndef MOD_H
#define MOD_H
/////////////////////////////////////////////////
/*! \brief Modulator.
 *
 *	Implementacja Modulatora
 *
 */
class Mod
{
public:
	Mod();
	compx ModTab[4];
	list<complex<double>>lst;

	compx execute(int input){return ModTab[input];}
	void create(list<int>*ptrlst);
	void disp();

};

/////////////////////////////////////////////////
//***********************************************
#endif /*MOD_H */
