/********************************************//**
 * \file   mod.h
 * \brief  Definicja obiektu modulator.
 * \author Adam Hakowski (adam.hakowski@gmail.com)
 * \date   2013-04-21
 ***********************************************/
#ifndef MOD_H
#define MOD_H
/////////////////////////////////////////////////
/*! \brief Modulator.
 *
 *	Implementacja Modulatora.
 *
 */
class MOD
{
	
public:
	 complex<double>* tab[8];
	MOD();
	// Metoda która koduje dane i moduluje dla jednej ramki.
	void encodeAndMod(Coder* pCode,list<int>* pLtData,list<complex<double>>* plLtEncoAndMod);
private:

};
/////////////////////////////////////////////////
//***********************************************
#endif /*MOD_H*/