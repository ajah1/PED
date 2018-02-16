#include "tlistacalendario.h"

//---------------------------------------------------------------->Nodo
TNodoCalendario::TNodoCalendario() :
{
	_sig = nullptr;
	_c = new TCalendario();
}

TNodoCalendario::
TNodoCalendario (TNodoCalendario& nodo)
{
	_c = nodo.Calendario();
	_sig = nodo.Siguiente();
}

	
TNodoCalendario&
TNodoCalendario::operator = (TNodoCalendario& nodo)
{
	if (&nodo != this)
	{
		this->~TNodoCalendario();
		_c = nodo.Calendario();
		_sig = nodo.Siguiente();
	}

	return *this;
}


TNodoCalendario::~TNodoCalendario()
{
	_c.~TCalendario();
	
	if (!_sig)
	{
		delete[] _sig;
		_sig = nullptr;	
	}
}


//---------------------------------------------------------------->Pos
TListaPos::TListaPos() :
	_pos(nullptr)
{}

// Si eliminamos la posicion tambien se va el nodo????'
TListaPos::~TListaPos()
{
	_pos->~TNodoCalendario();
	_pos = nullptr;
}

TListaPos::TListaPos(TListaPos& p)
{
	if (this != &p)
	{
		this->~TListaPos();
		_pos = p.Posicion();	
	}
}


TListaPos& 
TListaPos::operator=(TListaPos &)
{
	
	return *this;
}
















