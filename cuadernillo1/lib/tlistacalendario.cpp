#include "tlistacalendario.h"

#include <stdlib.h>

//
// ----------------------------------------- tNodoCalendario
//

TNodoCalendario::
TNodoCalendario () :
    _sig(nullptr)
{}


TNodoCalendario::
TNodoCalendario (const TNodoCalendario& nodo)
{
    if (this != &nodo)
    {
        if (!_sig)
            delete _sig;
            
        _c = nodo._c;
        _sig = nodo._sig;
    }
}


TNodoCalendario::
~TNodoCalendario ()
{
	_sig=nullptr;
}


TNodoCalendario& TNodoCalendario::
operator= (const TNodoCalendario& nodo) 
{
    if (this != &nodo)
    {
        if (!_sig)
            delete _sig;
            
        if (!this)
        {
            _c = nodo._c;
            _sig = nodo._sig;
         }   
    }
    
    return *this;
}



//
// ----------------------------------------- TListaPos
//

TListaPos::
TListaPos () :
    _pos(nullptr)
{}

TListaPos::
TListaPos (const TListaPos& lpos)
{
    if (this != &lpos)
    {
        if (!_pos)
            delete _pos;

        else
        _pos = lpos._pos;
    }
}

TListaPos::
~TListaPos ()
{
    _pos = nullptr;
}

TListaPos & TListaPos::
operator= (const TListaPos& lpos)
{
    if (this != &lpos)
        _pos = lpos._pos;
    
    return *this;
}

bool 
TListaPos::operator== (const TListaPos& lpos) const
{
    return _pos == lpos._pos;
}


bool 
TListaPos::operator!= (const TListaPos& lpos) const
{
    return _pos != lpos._pos;
}


TListaPos
TListaPos::Siguiente () const
{
    TListaPos sig;
    
    if (!_pos || _pos)
        sig._pos = _pos->_sig;
    
    return sig;
}

bool
TListaPos::EsVacia () const
{
    return _pos == nullptr;
}


//
// ----------------------------------------- TListaCalendario
//

TListaCalendario::
TListaCalendario () :
    _primero(nullptr)
{}


TListaCalendario::
TListaCalendario (const TListaCalendario& l)
{
    TListaPos next;
	TListaPos current;

	if (this != &l) 
	{
		_primero = new TNodoCalendario(*l._primero);
		current = l.Primera();
		
		next = l.Primera();
		next = next.Siguiente();

		if (!next._pos) 
		{
			while (!next._pos) 
			{
				current.Siguiente();
				current._pos = new TNodoCalendario(*next._pos);
				current = next;
				
				next = next.Siguiente();
			}
		}
    }
}


TListaCalendario::
~TListaCalendario ()
{
    TListaPos p, q;
    
    q = Primera();
    while (!q.EsVacia())
    {
        p = q;
        q = q.Siguiente();
        delete p._pos;
    }
    
    _primero = nullptr;
}


TListaPos
TListaCalendario::Primera () const
{
    TListaPos primera;
    
    if (!EsVacia())
        primera._pos = _primero;

    return primera;
}


bool
TListaCalendario::EsVacia () const
{
    return (_primero == nullptr);
}


ostream & 
operator<<(ostream& os, const TListaCalendario& l) 
{ 

	TListaPos actual=l.Primera();

	os<<"<";

	while(!actual.EsVacia()) 
	{
		os << l.Obtener(actual);
		actual=actual.Siguiente();

		if(!actual.EsVacia())
			os << " ";
	}

	os<<">";

	return os;
}


//Inserta un Calendario en la Lista
bool 
TListaCalendario::Insertar(const TCalendario& c) 
{
    //  nodo a insertar con el complejo pasado
	TNodoCalendario* n = new TNodoCalendario();
	n->_c = c;
	
	// insertar en lista vacia
	if (EsVacia())
	{
		_primero = n;
		return true;
	}
	
	// no admite repetidos
	else if (!Buscar(c))
	{
		// insertar en la cabeza
		//if (c < Primera()._pos->_c)
		//{
			std::clog << "insertar primera" << "\n";
			n->_sig = Primera()._pos;
			_primero = n;
			return true;
		//}
		
		//buscar _posición a insertar
	}
	
	return false;
}


TCalendario
TListaCalendario::Obtener (const TListaPos& p) const 
{
	if(!p.EsVacia())
		return p._pos->_c;
}


bool
TListaCalendario::Buscar (const TCalendario& c) const
{
	TListaPos paux;
	TCalendario caux;
	
	paux = Primera();
	while (!paux.EsVacia())
	{
		caux = paux._pos->_c;
		if (caux == c)
			return true;
			
		paux = paux.Siguiente();
	}
	
	return false;
}