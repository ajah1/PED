#include "tabbcalendario.h"

////////////////////////////////////
//            TNodoABB            //
////////////////////////////////////

TNodoABB::TNodoABB () {}

TNodoABB::TNodoABB (const TNodoABB& p_nodo) 
{
    if (this != &p_nodo)
    {
        _item = p_nodo._item;
        _iz = p_nodo._iz;
        _de = p_nodo._de;
    }
}

TNodoABB::~TNodoABB () 
{
    _item.~TCalendario();
    _iz.~TABBCalendario();
    _de.~TABBCalendario();
}

TNodoABB& TNodoABB::operator= (const TNodoABB& p_nodo) 
{
    if (this != &p_nodo)
    {
        _item = p_nodo._item;
        _iz = p_nodo._iz;
        _de = p_nodo._de;        
    }

    return *this;
}



////////////////////////////////////
//            TABBCalendario      //
////////////////////////////////////


//////////FORMA CANONICA////////////

TABBCalendario::TABBCalendario () :
    _raiz(NULL)
{}

TABBCalendario::TABBCalendario (const TABBCalendario& p_abb) 
{
	if (this != &p_abb && _raiz)
		CopiarArbol(p_abb);
	else
		_raiz = NULL;
}

TABBCalendario::~TABBCalendario () 
{
    if (_raiz)
    {
        if (_raiz->_de._raiz)
            _raiz->_de.~TABBCalendario();
            
        if (_raiz->_iz._raiz)
            _raiz->_iz.~TABBCalendario();
            
        delete _raiz;
        _raiz = NULL;
    }
}

TABBCalendario&
TABBCalendario::operator= (const TABBCalendario& p_abb)
{
    if (this != &p_abb)
    {
        this->~TABBCalendario();
        CopiarArbol(p_abb);
    }
    
    return *this;
}


////////SOBRECARGAS OPERADORES <,>, ==, +,-////////////

////////RECORRIDOS INORDEN PREORDEN POSTORDEN NIVELES//

////////ALTURA NODOS NODOSHOJA/////////////////////////

////////ESVACIO INSERTAR BORRAR BUSCAR/////////////////
bool
TABBCalendario::Insertar (const TCalendario& p_c)
{	
	//Insertar( crea_arbin( ), x ) =
		//enraizar( crea_arbin( ), x, crea_arbin( ) )
	if (!_raiz)
	{
		_raiz = new TNodoABB();
		_raiz->_item = p_c;
		return true;
	}
	
	//si ( y < x ) entonces
		//insertar( enraizar( i, x, d ), y ) =
			//enraizar( insertar( i, y ), x, d )
	else if (p_c < _raiz->_item)
		return (_raiz->_iz).Insertar (p_c);
		
	//si no si ( y > x ) 
		//insertar( enraizar( i, x, d ), y ) =
			//	enraizar( i, x, insertar( d, y ) )
	else if (p_c > _raiz->_item)
		(_raiz->_de).Insertar(p_c);
		
	return false;
}

/////////////////////GETTERS///////////////////////////
TCalendario 
TABBCalendario::Raiz () const
{
	if (_raiz)
    	return _raiz->_item;
	else
		return _item_error;
}

////////FUNCIONES AUXILIARES///////////////////////////
void 
TABBCalendario::CopiarArbol (const TABBCalendario p_abb)
{
    // caso resursivo: arbol no vacio
    if (p_abb._raiz)
    {
        // nuevo nodo del arbol
        TNodoABB* nabb_aux = new TNodoABB();
        nabb_aux->_item = p_abb._raiz->_item;
        
        // apuntar a la copia del nodo
        _raiz = nabb_aux;
    
        // llamar a copiar iz/de
        (_raiz->_iz).CopiarArbol(p_abb._raiz->_iz);
        (_raiz->_de).CopiarArbol(p_abb._raiz->_de);
    }
    // caso base: arbol vacio
    else
        _raiz = NULL;
}













