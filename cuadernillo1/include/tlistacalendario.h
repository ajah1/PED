#pragma once

#include "tcalendario.h"

class TNodoCalendario {

private:
	
	TCalendario _c;
	TNodoCalendario* _sig;
	
public:

	// Constructor por defecto
	TNodoCalendario ();
	// Constructor de copia
	TNodoCalendario (TNodoCalendario&);
	// Destructor
	~TNodoCalendario ();
	// Sobrecarga del operador asignación
	TNodoCalendario& operator= (TNodoCalendario&);
	
	// getters
	TCalendario Calendario() { return _c; }
	TNodoCalendario* Siguiente() { return _sig; }
};	

TNodoCalendario::TNodoCalendario() :
	_sig(nullptr)
{}

TNodoCalendario::~TNodoCalendario()
{
	_c.~TCalendario();
	
	if (!_sig)
	{
		delete[] _sig;
		_sig = nullptr;	
	}
}

