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

class TListaPos {

private:

	TNodoCalendario* _pos;

public:

	// Constructor por defecto
	TListaPos();
	// Constructor de copia
	TListaPos(TListaPos &);
	// Destructor
	~TListaPos();
	// Sobrecarga del operador asignación
	TListaPos & operator=(TListaPos &);
	
	// getters
	TNodoCalendario Posicion() { return _pos; }	

};
