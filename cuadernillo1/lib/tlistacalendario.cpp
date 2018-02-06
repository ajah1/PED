#include "tlistacalendario.h"

//---------------------------------------------------------------->Nodo
TNodoCalendario::
TNodoCalendario (TNodoCalendario& nodo)
{
	_c = nodo.Calendario();
	_sig = nodo.Siguiente();
}


TNodoCalendario&
TNodoCalendario::operator = (TNodoCalendario& nodo)
{
	this->~TNodoCalendario();
	
	_c = nodo.Calendario();
	_sig = nodo.Siguiente();

	return *this;
}


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


//---------------------------------------------------------------->Pos
TListaPos::TListaPos() :
	_pos(nullptr)
{}


TListaPos::TListaPos(TListaPos& p)
{
	_pos = p.Posicion();
}


// Si eliminamos la posicion tambien se va el nodo????'
TListaPos::~TListaPos()
{
}


TListaPos& 
TListaPos::operator=(TListaPos &)
{
	
	return *this;
}
















