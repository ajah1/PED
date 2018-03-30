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

	TNodoCalendario ();
	TNodoCalendario (const TNodoCalendario&);
	~TNodoCalendario ();
	TNodoCalendario& operator= (const TNodoCalendario&);
	
};



class TListaPos
{
	friend class TListaCalendario;

private:

	TNodoCalendario* _pos;

public:

	TListaPos();
	TListaPos(const TListaPos &);
	~TListaPos();
	TListaPos & operator=(const TListaPos &);
	
	bool operator==(const TListaPos &) const;
	bool operator!=(const TListaPos &) const;
	
	TListaPos Siguiente() const;
	
	bool EsVacia() const;

};



class TListaCalendario
{
	friend 
	std::ostream & operator<<(std::ostream &, const TListaCalendario &);

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
	bool Borrar (const TListaPos &);
	bool Borrar (const int, const int, const int);

	int Longitud() const;
	
	TListaPos Primera() const;
	TListaPos Ultima() const;
	
	TCalendario Obtener(const TListaPos &) const;
	TListaCalendario operator+ (const TListaCalendario &) const;
};
