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
    return _primero == nullptr;
}


ostream & 
operator<<(ostream& os, const TListaCalendario& l) 
{ 

	TListaPos actual = l.Primera();

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
	TNodoCalendario* nodo = new TNodoCalendario();
	nodo->_c = c;

    // insertar en vacia
	if (EsVacia()) 
	{
	    std::clog << "Insertar en vacia \n";
		_primero=nodo;
		return true;
	}

	else if (!Buscar(c))
	{
	    TNodoCalendario* actual = _primero;
	    TNodoCalendario* siguiente = _primero->_sig;
	    
	    while (!siguiente)
	    {
    	    // insertar en la primera
	        if (c < _primero->_c)
	        {
	            std::clog << "Insertar en la primera \n";
	            nodo->_sig = _primero;
	            _primero = nodo;
	        }   
	        
	        actual = siguiente;
	        siguiente = siguiente->_sig;
	    }
	    
	    return true;
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
	TListaPos buscar;
	TCalendario caux;
	
	buscar = Primera();
	while (!buscar.EsVacia())
	{
		caux = buscar._pos->_c;
		if (caux == c)
			return true;
			
		buscar = buscar.Siguiente();
	}
	
	return false;
}


int
TListaCalendario::Longitud () const
{
	int l = 0;

	TListaPos it;

	it = Primera();
	while (it._pos != nullptr)
	{
		++l;
		it = it.Siguiente();
	}

	return l;
}



TListaPos 
TListaCalendario::Ultima() const 
{
    TListaPos ultima;
    
    if (!EsVacia())
    {
        ultima = Primera();
        while (!ultima._pos->_sig)
            ultima = ultima.Siguiente();
    }
    
    return ultima;
}


bool
TListaCalendario::Borrar (const TCalendario& c)
{
    if (!EsVacia() || Buscar(c))
    {   
        TListaPos actual = Primera();
        TListaPos siguiente = actual.Siguiente();
    
        // borrar primera posicion
        if (c == Obtener(Primera()))
        {
           _primero = _primero->_sig;
           delete siguiente._pos;
        }
           
        else
        {
            while (!siguiente.EsVacia())
            {
                // encontramos el calendario en la siguiente
                if (c == Obtener(siguiente))
                {
                    if (siguiente == Ultima())
                        actual._pos->_sig = nullptr;
                    else
                        actual._pos->_sig = siguiente._pos->_sig;
                        
                    delete siguiente._pos;
                    return true;
                }
                
                actual = siguiente;
                siguiente = siguiente.Siguiente();
            }
        }
    }
    
    return false;
}








