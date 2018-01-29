#pragma once

#include "tcalendario.h"

#include <iostream>

class TVectorCalendario {

    // Sobrecarga del operador salida
    friend std::ostream& operator << (std::ostream&, const TVectorCalendario&);

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
	
	// Sobrecarga del operador corchete (parte DERECHA)
    TCalendario operator[](int) const;
	
	// Tamaño del vector (posiciones TOTALES)
	int Tamano() {return _tamano;};
	
	// Cantidad de posiciones OCUPADAS (no vacías) en el vector
    int Ocupadas();
	
	
	
};

TVectorCalendario::TVectorCalendario ()
{
	_tamano = 0;
	_c = nullptr;
}

TVectorCalendario::TVectorCalendario (int size)
{
	if (size <= 0)
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
		delete[] _c;
		
	_c = nullptr;
	_tamano = 0;
}






















