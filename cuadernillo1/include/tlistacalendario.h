#pragma once

#include "tcalendario.h"

class TNodoCalendario 
{
    friend class TListaPos;
    friend class TListaCalendario;

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
};

class TListaPos 
{
    friend class TListaCalendario;
    
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
    // Sobrecarga del operador igualdad
    bool operator==(TListaPos &);
    // Sobrecarga del operador desigualdad
    bool operator!=(TListaPos &);
    // Devuelve la posición siguiente
    TListaPos Siguiente();
    // Posición vacía
    bool EsVacia();
};

class TListaCalendario {

	//friend ostream & operator<<(ostream &, const TListaCalendario &);

private:

	TNodoCalendario *primero;

public:

	TListaCalendario();
	TListaCalendario(const TListaCalendario &);
	~TListaCalendario();
	TListaCalendario & operator=(const TListaCalendario &);
	
	bool EsVacia() const;
};
