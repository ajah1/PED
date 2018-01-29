#pragma once

#include "tcalendario.h"

#include <iostream>

class TVectorCalendario {

	private:

	TCalendario* _c;
	TCalendario _error;
	
	int _tamano;
		

	public:
	
	// Constructor por defecto
	inline TVectorCalendario();
	// Constructor a partir de un tamaño
	inline TVectorCalendario(int);
	// Constructor de copia
	//TVectorCalendario(TVectorCalendario &);
	// Destructor
	inline ~TVectorCalendario();
	
	// Tamaño del vector (posiciones TOTALES)
	int const Tamano() {return _tamano;};
	
	// Sobrecarga del operador salida
	friend std::ostream& operator << (std::ostream&, const TVectorCalendario&);
	
	
};

TVectorCalendario::TVectorCalendario ()
{
	_tamano = 0;
	_c = new TCalendario[_tamano];
}

TVectorCalendario::TVectorCalendario (int size)
{
	if (size <= 0)
		_tamano = 0;
	
	_c = new TCalendario[_tamano];
}

TVectorCalendario::~TVectorCalendario ()
{
	_tamano = 0;

	if (_c != nullptr)
	{
		delete[] _c;
		_c = nullptr;
	}
}






















