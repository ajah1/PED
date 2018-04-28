#include "tabbcalendario.h"
#include "tvectorcalendario.h"

#include <algorithm> // std::max

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


////////SOBRECARGAS OPERADORES////////////
bool
TABBCalendario::operator== (const TABBCalendario& p_abb) const
{
	//if (NodosHoja() == p_abb.NodosHoja())
		if (Inorden() == p_abb.Inorden())
			return true;

	return false;
}


TABBCalendario
TABBCalendario::operator+ (const TABBCalendario& p_abb) const
{
	TABBCalendario aux_abb (*this);

	if (!p_abb._raiz)
		return aux_abb;

	TVectorCalendario aux_vector;
	aux_vector = p_abb.Inorden();

	for (int i = 1; i <= p_abb.Nodos(); ++i)
		aux_abb.Insertar (aux_vector[i]);

	return aux_abb;
}


TABBCalendario
TABBCalendario::operator- (const TABBCalendario& p_abb) const
{
	TABBCalendario aux_abb;
	return aux_abb;
}


////////RECORRIDOS INORDEN PREORDEN POSTORDEN NIVELES//
TVectorCalendario
TABBCalendario::Inorden () const
{
	int posicion = 1;

	TVectorCalendario v(Nodos());
	InordenAux(v, posicion);

	return v;
}


TVectorCalendario
TABBCalendario::Preorden () const
{
	int posicion = 1;

	TVectorCalendario v(Nodos());
	PreordenAux(v, posicion);

	return v;
}


TVectorCalendario
TABBCalendario::Postorden () const
{
	int posicion = 1;

	TVectorCalendario v(Nodos());
	PostordenAux(v, posicion);

	return v;
}


void
TABBCalendario::InordenAux
	(TVectorCalendario& p_v, int& p_pos) const
{
	if (_raiz)
	{
		_raiz->_iz.InordenAux(p_v, p_pos);
		p_v[p_pos] = _raiz->_item;
		p_pos++;
		_raiz->_de.InordenAux(p_v, p_pos);
	}
}


void
TABBCalendario::PreordenAux
	(TVectorCalendario& p_v, int& p_pos) const
{
	if (_raiz != nullptr)
	{
		p_v[p_pos] = _raiz->_item;
		p_pos++;
		_raiz->_iz.PreordenAux(p_v, p_pos);
		_raiz->_de.PreordenAux(p_v, p_pos);
	}
}


void
TABBCalendario::PostordenAux
	(TVectorCalendario& p_v, int& p_pos) const
{
	if (_raiz)
	{
		_raiz->_iz.PostordenAux(p_v, p_pos);
		_raiz->_de.PostordenAux(p_v, p_pos);
		p_v[p_pos] = _raiz->_item;
		p_pos++;
	}
}


////////ALTURA NODOS NODOSHOJA/////////////////////////
int
TABBCalendario::Nodos () const
{
	if (_raiz)
		return 1 + _raiz->_iz.Nodos()
			     + _raiz->_de.Nodos();
	else
		return 0;
}


int
TABBCalendario::Altura () const
{
	if (_raiz)
		return 1 + std::max (_raiz->_iz.Altura(),
		  					 _raiz->_de.Altura());
	else
		return 0;
}


int
TABBCalendario::NodosHoja () const
{
	if (!Hoja())
		return _raiz->_iz.NodosHoja() +
			   _raiz->_de.NodosHoja();
	else
		return 1;
}


////////ESVACIO INSERTAR BORRAR BUSCAR/////////////////
bool
TABBCalendario::EsVacio () const
{
	return (!_raiz);
}

bool
TABBCalendario::Buscar (const TCalendario& p_c) const
{
	if (_raiz)
	{
		if (_raiz->_item == p_c)
			return true;

		return _raiz->_iz.Buscar(p_c) ||
				_raiz->_de.Buscar(p_c);
	}
	return false;
}


bool
TABBCalendario::Insertar (const TCalendario& p_c)
{
	if (!Buscar(p_c))
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
			return (_raiz->_de).Insertar (p_c);
	}

	return false;
}


bool
TABBCalendario::Borrar (const TCalendario& p_cal)
{
	//borrar( crea_arbin( ), x ) = crea_arbin( )
	if (Buscar(p_cal))
	{
		/*si ( y < x ) entonces
		enraizar( borrar( i, y ), x, d )*/
		if (p_cal < _raiz->_item)
			_raiz->_iz.Borrar (p_cal);

		/*si no si ( y > x ) entonces
		enraizar( i, x, borrar( d, y ) ) fsi*/
		else if (p_cal > _raiz->_item)
			_raiz->_de.Borrar (p_cal);

		/* si ( y==x ) */
		else if (p_cal == _raiz->_item)
		{
			// C1. el nodo a borrar es hoja
			if (Hoja())
        BorrarHoja ();

			// C2. el nodo a borrar solo tiene un hijo
			else if (_raiz->_iz.EsVacio() || _raiz->_iz.EsVacio())
        BorrarHijo ();

			// C3. no esvacio( d ) y no esvacio( i )
			else
        BorrarConCriterio ();
		}

		return true;
	}

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
TABBCalendario::CopiarArbol (const TABBCalendario& p_abb)
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


TCalendario
TABBCalendario::MenorDerecha () const
{
  TCalendario c_izq;
  TCalendario c_der;

  if (Hoja())
    return _raiz->_item;

  else
  {
    c_izq = _raiz->_iz.MenorDerecha();
    c_der = _raiz->_de.MenorDerecha();

    if (_raiz->_item < c_izq && _raiz->_item < c_izq)
      return _raiz->_item;

    else if (c_izq < _raiz->_item && c_izq < _raiz->_item)
      return c_izq;

    else
      return c_der;
  }

	return _item_error;
}


bool
TABBCalendario::Hoja () const
{
	if (!_raiz->_iz._raiz && !_raiz->_de._raiz)
		return true;

	return false;
}


void
TABBCalendario::BorrarHoja ()
{
  delete _raiz;
  _raiz = NULL;
}


void
TABBCalendario::BorrarConCriterio ()
{
  TCalendario menorDerecha = MenorDerecha();

  _raiz->_iz.Borrar (menorDerecha);
  _raiz->_item = menorDerecha;
}


void
TABBCalendario::BorrarHijo ()
{
  TNodoABB* aux_raiz;

  if (_raiz->_iz.EsVacio())
  {
    // borrar el nodo apuntando la raiz al hijo no vacio
    aux_raiz = _raiz;
    _raiz = _raiz->_de._raiz;
    // liberar memoria del nodo a borrar
    aux_raiz->_de._raiz = NULL;
    delete aux_raiz;
    aux_raiz = NULL;
  }

  else if (_raiz->_de.EsVacio())
  {
    aux_raiz = _raiz;
    _raiz = _raiz->_iz._raiz;

    aux_raiz->_iz._raiz = NULL;
    delete aux_raiz;
    aux_raiz = NULL;
  }
}
