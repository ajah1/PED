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
operator= (TListaPos& lpos)
{
    if (this != &lpos)
    {
        _pos = lpos._pos;
    }
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
TListaPos::Siguiente ()
{
    TListaPos aux;
    
    if (!_pos)
    {
        aux._pos = _pos->_sig;
    }
    
    return aux;
}


bool
TListaPos::EsVacia ()
{
    return _pos == nullptr;
}
