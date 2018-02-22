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
    _sig->~TNodoCalendario();
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



