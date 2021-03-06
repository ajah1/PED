#pragma once

#include "tcalendario.h"

#include <iostream>
#include <inttypes.h>

class TVectorCalendario 
{
    friend 
    std::ostream& operator << (std::ostream&, const TVectorCalendario&);

private:

	TCalendario* _c;
	TCalendario  _error;
	
	int _tamano;
		

public:
	
	inline TVectorCalendario();
	inline TVectorCalendario(const int);
	//TVectorCalendario(TVectorCalendario &);
	inline ~TVectorCalendario();
	
    TVectorCalendario & operator=(const TVectorCalendario &);
	
    TCalendario operator[](const int) const;
    TCalendario& operator[](const int);
	
	bool operator == (const TVectorCalendario&) const;
	bool operator != (const TVectorCalendario&) const;
	
	bool ExisteCal(TCalendario&);	
	bool Redimensionar(const int&);
	
	int Tamano() const {return _tamano;};
    int Ocupadas() const;

	
	void MostrarMensajes(const int, const int, const int);
	
	TCalendario* Calendarios() const {return _c;};
	
	
    // devuelve true si las fechas son iguales
    bool igualFechas (const TCalendario&, const TCalendario&);
    // devuelve 1 si la fecha es mayor
    bool mayorFechas (const TCalendario&, const TCalendario&);
	
};

TVectorCalendario::TVectorCalendario ()
{
	_tamano = 0;
	_c = NULL;
}

TVectorCalendario::TVectorCalendario (const int size)
{
	if (size < 0)
	{
	    _c = NULL;
		_tamano = 0;
	}
	else
	{
	    _tamano = size;
	    _c = new TCalendario[_tamano];
    }
}

TVectorCalendario::~TVectorCalendario ()
{
	if (_c != NULL)
	{
		delete[] _c;
		_c = NULL;
	}	
	_tamano = 0;
}
