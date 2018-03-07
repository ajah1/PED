#pragma once

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoCalendario 
{
	friend class TListaCalendario;
	friend class TListaPos;

private:

	TCalendario _c;
	TNodoCalendario* _sig;

public:

	// Constructor por defecto
	TNodoCalendario ();
	// Constructor de copia
	TNodoCalendario (const TNodoCalendario&);
	// Destructor
	~TNodoCalendario ();
	// Sobrecarga del operador asignación
	TNodoCalendario& operator= (const TNodoCalendario&);
	
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
	TListaPos(const TListaPos &);
	// Destructor
	~TListaPos();
	// Sobrecarga del operador asignación
	TListaPos & operator=(const TListaPos &);
	// Sobrecarga del operador igualdad
	bool operator==(const TListaPos &) const;
	// Sobrecarga del operador desigualdad
	bool operator!=(const TListaPos &) const;
	// Devuelve la posición siguiente
	TListaPos Siguiente() const;
	// Posición vacía
	bool EsVacia() const;

};

class TListaCalendario
{
	friend std::ostream & operator<<(std::ostream &, const TListaCalendario &);

private:

	TNodoCalendario* _primero;

public:

	TListaCalendario ();
	TListaCalendario (const TListaCalendario &);
	~TListaCalendario ();
	TListaCalendario & operator=(const TListaCalendario &);

	bool Insertar (const TCalendario &);
	bool EsVacia () const;
	bool Buscar (const TCalendario &) const;
    bool Borrar (const TCalendario &);
    

	int Longitud() const;

	TCalendario Obtener(const TListaPos &) const;

	TListaPos Primera() const;
	TListaPos Ultima() const;

};
