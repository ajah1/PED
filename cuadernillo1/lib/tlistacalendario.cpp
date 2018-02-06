#include "tlistacalendario.h"

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

