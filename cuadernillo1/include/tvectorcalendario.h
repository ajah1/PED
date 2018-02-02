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
	
    int Ocupadas() const;
	
	inline TVectorCalendario();
	inline TVectorCalendario(int);
	// Constructor de copia
	//TVectorCalendario(TVectorCalendario &);
	inline ~TVectorCalendario();
	
    TVectorCalendario & operator=(TVectorCalendario &);
	
    TCalendario operator[](int) const;
    TCalendario& operator[](int);
	
	bool ExisteCal(TCalendario&);
	
	bool Redimensionar(int);
	
	int Tamano() {return _tamano;};
	
	// mensajes en el vector, fecha IGUAL/POSTERIOR a la pasada
	void MostrarMensajes(int,int,int);
	
	// Calendarios
	TCalendario* Calendarios() {return _c;};
	
};

TVectorCalendario::TVectorCalendario ()
{
	_tamano = 0;
	_c = nullptr;
}

TVectorCalendario::TVectorCalendario (int size)
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






















