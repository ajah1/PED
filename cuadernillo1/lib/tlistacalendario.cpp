#include "tlistacalendario.h"

//------------------------TNodoCalendario
TNodoCalendario::
TNodoCalendario () :
    _sig(nullptr)
{}

TNodoCalendario::TNodoCalendario 
(TNodoCalendario& nodo)
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
    _c.~TCalendario();
    _sig = nullptr;
}


TNodoCalendario & TNodoCalendario::
operator= (TNodoCalendario& nodo)
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

//------------------------TListaPos
TListaPos::
TListaPos() :
    _pos(nullptr)
{}

TListaPos::
TListaPos (TListaPos& lpos)
{
    if (this != &lpos)
    {
        if (!_pos)
            delete _pos;
            
        _pos = lpos._pos;
    }
}

TListaPos::
~TListaPos()
{
    if (!_pos)
        delete _pos;
        
    _pos = nullptr;
}

TListaPos & TListaPos::
operator= (const TListaPos& lpos)
{
    if (this != &lpos)
    {
        _pos = lpos._pos;
    }
    
    return *this;
}

bool 
TListaPos::operator== (TListaPos& lpos)
{
    return (this == &lpos);
}


bool 
TListaPos::operator!= (TListaPos& lpos)
{
    return !(*this == lpos);
}


TListaPos
TListaPos::Siguiente () const
{
    TListaPos sig;
    
    if (!_pos)
        sig._pos = _pos->_sig;
    
    return sig;
}


bool
TListaPos::EsVacia ()
{
    return _pos == nullptr;
}

//------------------------TListaCalendario
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
~TListaCalendario()
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
TListaCalendario::EsVacia() const
{
    return (_primero == nullptr);
}

std::ostream & 
operator<< (std::ostream& os, const TListaCalendario& l)
{
	os << "<";
	
	TListaPos paux;
	
	paux = l.Primera();
	while (!paux.EsVacia())
	{
		os << paux.Pos()->C();
		
		paux = paux.Siguiente();
		if (!paux.EsVacia())
			std::cout << " ";
	}
	os << ">";

	return os;
}

bool 
TListaCalendario::Buscar (TCalendario& c)
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

bool
TListaCalendario::Insertar (TCalendario& c)
{
    //  nodo a insertar con el complejo pasado
	TNodoCalendario* n = new TNodoCalendario();
	n->_c = c;
	
	// insertar en lista vacia
	if (EsVacia())
	{
	    n->_sig = nullptr;
		_primero = n;
		return true;
	}
	
	// no admite repetidos
	else if (!Buscar(c))
	{
		// insertar en la cabeza
		if (c < Primera()._pos->_c)
		{
			n->_sig = new TNodoCalendario(*_primero);
			_primero = n;
			return true;
		}
		
		//buscar posición a insertar
	}
	
	return false;
}























