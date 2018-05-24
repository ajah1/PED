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
	if (this != &p_abb)
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
	TABBCalendario aux_abb (*this);

  TVectorCalendario p_inorden;
  p_inorden = p_abb.Inorden();

  for (int i = 1; i <= p_abb.Nodos(); ++i)
  {
    if (Buscar(p_inorden[i]))
      aux_abb.Borrar (p_inorden[i]);
  }

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
	if (_raiz != NULL)
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
  if (_raiz== NULL)
    return 0;

	else if (Hoja())
    return 1;

  else
    return _raiz->_iz.NodosHoja() +
          _raiz->_de.NodosHoja();
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
			// C1. el _raiz a borrar es hoja
			if (Hoja())
        BorrarHoja ();

			// C2. el _raiz a borrar solo tiene un hijo
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
        // nuevo _raiz del arbol
        TNodoABB* nabb_aux = new TNodoABB();
        nabb_aux->_item = p_abb._raiz->_item;

        // apuntar a la copia del _raiz
        _raiz = nabb_aux;

        // llamar a copiar _iz/_de
        (_raiz->_iz).CopiarArbol(p_abb._raiz->_iz);
        (_raiz->_de).CopiarArbol(p_abb._raiz->_de);
    }
    // caso base: arbol vacio
    else
        _raiz = NULL;
}


TCalendario
TABBCalendario::MayorIzquierda () const
{
  if (Hoja())
    return _raiz->_item;

  else if (!_raiz->_de.EsVacio())
    return _raiz->_de.MayorIzquierda();

  else
    return _raiz->_iz.MayorIzquierda();
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
  TCalendario mayorizq = _raiz->_iz.MayorIzquierda();

  _raiz->_iz.Borrar (mayorizq);
  _raiz->_item = mayorizq;
}


void
TABBCalendario::BorrarHijo ()
{
  TNodoABB* aux_raiz = _raiz;

  if (_raiz->_iz.EsVacio())
    _raiz = _raiz->_de._raiz;

  else if (_raiz->_de.EsVacio())
    _raiz = _raiz->_iz._raiz;

  aux_raiz->_de._raiz = NULL;
  aux_raiz->_iz._raiz = NULL;

  delete aux_raiz;
  aux_raiz = NULL;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////// EJERCICIOS RANDOM /////////////////////////
///////////////////////////////////////////////////////////////////////////
/*
// EJERCICIO1
Devuelve una lista con los nodos que son hojas en el arbool _de los nodos del
vector pasado como parametro.
TLiscaCom listaHojas(const TVectorCom &up) const;
bool esHoja(const TComplejo &p_cal) const;
*/

// AUXILIAR: devuelve el puntero al _raiz, el calendario a buscar
// ya está previamente comprobado que esté en el abb
TNodoABB*
TABBCalendario::ObtenerPuntero (const TCalendario& p_cal) const
{
  if (_raiz->_item == p_cal)
    return _raiz;

  else if (_raiz->_iz.EsVacio())
    return _raiz->_de.ObtenerPuntero (p_cal);

  else if (_raiz->_de.EsVacio())
    return _raiz->_iz.ObtenerPuntero (p_cal);
}

TListaCalendario
TABBCalendario::ListaHojas (const TVectorCalendario& p_vec) const
{
  TCalendario aux_cal;
  TNodoABB* aux_nodo;
  TListaCalendario lista_hojas;

  for (int i = 1; i <= p_vec.Tamano(); ++i)
  {
    if (Buscar(p_vec[i]))
    {
      aux_cal = p_vec[i];
      aux_nodo = ObtenerPuntero (aux_cal);

      if (!aux_nodo->_iz._raiz && !aux_nodo->_de._raiz)
        lista_hojas.Insertar (p_vec[i]);
    }
  }
  return lista_hojas;
}


/*
// EJERCICIO2
Comprobar si los nodos _de la lista estan en el arbol. Devuelve una lista con las
 posiciones _de forma que si esta pone 1 sino pone 0
int *TABBCom::marcar(const TListaCom &lista) const;
*/
int*
TABBCalendario::Marcar (const TListaCalendario& p_l) const
{
  int* nodos_marcados = new int [p_l.Longitud()];
  int i = 0;

  TListaPos aux_i = p_l.Primera();

  while (!aux_i.EsVacia())
  {
    if (Buscar (aux_i.Obtener()))
      nodos_marcados[i] = 1;
    else
      nodos_marcados[i] = 0;

    aux_i = aux_i.Siguiente();
    i++;
  }

  return nodos_marcados;
}

/*
  EJERCICIO3
*/
TListaCalendario
TABBCalendario::Hijos (const TCalendario& p_cal) const
{
  TListaCalendario l;

  if (_raiz != NULL)
  {
    if (p_cal < _raiz->_item)
       _raiz->_iz.Hijos(p_cal);

    else if(p_cal > _raiz->_item)
      l=_raiz->_de.Hijos(p_cal);

    else
    {
      if (_raiz->_iz._raiz!=NULL)
        l.Insertar(_raiz->_iz._raiz->_item);

      if (_raiz->_de._raiz!=NULL)
        l.Insertar(_raiz->_de._raiz->_item);
    }
  }

  	return l;
}

/*
//devuelve verdadero si el Com esta en el nivel i del arbol
bool TABBCom::estaEnNivel(const TComplejo &lp, int niv)const
{
*/
bool
TABBCalendario::EstaEnNivel (const TCalendario& p_cal, int& p_nivel) const
{
  if (_raiz != NULL)
  {
    if (p_nivel == 1 && _raiz->_item == p_cal)
    {
      return true;
    }
    else if (p_cal < _raiz->_item)
      return _raiz->_iz.EstaEnNivel (p_cal, --p_nivel);

    else if (p_cal > _raiz->_item)
      return _raiz->_de.EstaEnNivel (p_cal, --p_nivel);
  }
  return false;
}

/*
// EJERCICIO5
devuelve un vector con los padres de los elementos en el arbol
si no tiene padre se le pondra vacion en su posicion
TComplejo soyTuPadre(const TComplejo& p) const;
TVectorCom padresDe(const TListaCom& lp) const;
*/

TVectorCalendario
TABBCalendario::PadresDe (const TListaCalendario& p_l) const
{
  TVectorCalendario padres (p_l.Longitud());
  TCalendario cal_vacio;

  TListaPos aux_pos = p_l.Primera();
  int16_t i= 1;
  while (!aux_pos.EsVacia())
  {
    padres [i] = SoyTuPadre (aux_pos.Obtener());

    aux_pos = aux_pos.Siguiente();
    i++;
  }

  return padres;
}


TCalendario
TABBCalendario::SoyTuPadre (const TCalendario& p_cal) const
{
  TCalendario padre;

  if (_raiz != NULL)
  {
    if (!_raiz->_iz.EsVacio() && _raiz->_iz._raiz->_item == p_cal) {
      return _raiz->_item;
    }
    else if (!_raiz->_de.EsVacio() && _raiz->_de._raiz->_item == p_cal) {
      return _raiz->_item;
    }
    else if (p_cal < _raiz->_item) {
      return _raiz->_iz.SoyTuPadre (p_cal);
    }
    else if (p_cal > _raiz->_item) {
      return _raiz->_de.SoyTuPadre (p_cal);
    }
  }
  return padre;
}
/*


















*/
