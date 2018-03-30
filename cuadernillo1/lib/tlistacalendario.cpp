#include "tlistacalendario.h"

#include <stdlib.h>

//
// ----------------------------------------- tNodoCalendario
//

TNodoCalendario::
TNodoCalendario () :
    _sig(NULL)
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
	_sig=NULL;
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
    _pos(NULL)
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
    _pos = NULL;
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
    return _pos == NULL;
}




//
// ----------------------------------------- TListaCalendario
//

TListaCalendario::
TListaCalendario () :
    _primero(NULL)
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
    
    _primero = NULL;
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
    return _primero == NULL;
}


ostream & 
operator<<(ostream& os, const TListaCalendario& l) 
{ 

	TListaPos actual = l.Primera();

	os << "<";

	while (!actual.EsVacia()) 
	{
		os << l.Obtener(actual);
		actual = actual.Siguiente();

		if (!actual.EsVacia())
			os << " ";
	}

	os << ">";

	return os;
}


bool 
TListaCalendario::Insertar (const TCalendario& c) 
{
	TNodoCalendario* nodo = new TNodoCalendario();
	nodo->_c = c;

	// "INSERTAR: en lista vacia \n";
	if(_primero == NULL) 
	{
		_primero = nodo;
		return true;
	}
	
	// "Calendario no encontrado, pasando a insertar \n";
	else if (!Buscar(c))
	{
		    // "INSERTAR: en cabeza \n";
		if (c < _primero->_c)
		{
		    nodo->_sig = _primero;
		    _primero = nodo;
		    return true;
		}
		
		//buscando posicion a insertar \n";
		TNodoCalendario* it = _primero;
		while (it->_sig != NULL)
		{
		    if ((c > it->_c) && (c < it->_sig->_c))
		    {
		        // "INSERTAR: intermedia \n";
		        nodo->_sig = it->_sig;
		        it->_sig = nodo;
		        return true;
		    }
		    it = it->_sig;
        }
        
        // "INSERTAR: ultimo \n";
        it->_sig = nodo;
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
	while (it._pos != NULL)
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
           _primero = siguiente._pos;
           return true;
        }
           
        while (!siguiente.EsVacia())
        {
            // encontramos el calendario en la siguiente
            if (c == Obtener(siguiente))
            {
                if (siguiente == Ultima())
                    actual._pos->_sig = NULL;
                else
                    actual._pos->_sig = siguiente._pos->_sig;
                    
                delete siguiente._pos;
                return true;
            }
            
            actual = siguiente;
            siguiente = siguiente.Siguiente();
        }
        
    }
    
    return false;
}


bool
TListaCalendario::Borrar (const TListaPos& p)
{
    TCalendario c = Obtener(p);

    if (!EsVacia() || Buscar(c))
    {   
        TListaPos actual = Primera();
        TListaPos siguiente = actual.Siguiente();
    
        // borrar primera posicion
        if (c == Obtener(Primera()))
        {
           _primero = siguiente._pos;
           return true;
        }
           
        while (!siguiente.EsVacia())
        {
            // encontramos el calendario en la siguiente
            if (c == Obtener(siguiente))
            {
                if (siguiente == Ultima())
                    actual._pos->_sig = NULL;
                else
                    actual._pos->_sig = siguiente._pos->_sig;
                    
                delete siguiente._pos;
                return true;
            }
            
            actual = siguiente;
            siguiente = siguiente.Siguiente();
        }
    
    }
    
    return false;
}


bool
TListaCalendario::Borrar (const int d, const int m, const int a)
{
    const char* men = NULL;
    TCalendario c(d,m,a,men);

    // lista no vacia
    // Al menos un calendario anterior a la fecha pasada
    if (!EsVacia() && c > (Obtener(Primera())))
    {
        //"Borrar solo primera posicion \n";
        if (c < _primero->_sig->_c)
        {
            _primero = _primero->_sig;
            return true;
        }
        
        // "Borrar todas las posiciones \n";
        else if (c > Ultima()._pos->_c)
        {
            _primero = NULL;
            return true;
        }
        
        // "Buscando posiciones anteriores \n";
        TNodoCalendario* it = _primero->_sig;
        while (c > it->_sig->_c)
            it = it->_sig;
        
        _primero = it->_sig;
        
        return true;
    }

    return false;
}
