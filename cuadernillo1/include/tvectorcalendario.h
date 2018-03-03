#pragma once

#include "tcalendario.h"

#include <iostream>

class TVectorCalendario {

    // Sobrecarga del operador salida
    friend std::ostream& operator << (std::ostream&, const TVectorCalendario&);

private:

	TCalendario* _c;
	TCalendario  _error;
	
	int _tamano;
		

public:
	
	inline TVectorCalendario();
	inline TVectorCalendario(const int);
	// Constructor de copia
	//TVectorCalendario(TVectorCalendario &);
	inline ~TVectorCalendario();
	
    TVectorCalendario & operator=(TVectorCalendario &);
	
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
	
};

TVectorCalendario::TVectorCalendario ()
{
	_tamano = 0;
	_c = nullptr;
}

TVectorCalendario::TVectorCalendario (const int size)
{
	if (size < 0)
	{
	    _c = nullptr;
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
	if (_c != nullptr)
	{
		delete[] _c;
		_c = nullptr;
	}	
	_tamano = 0;
}






















