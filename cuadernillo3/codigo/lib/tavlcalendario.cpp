#include "tavlcalendario.h"
#include "tabbcalendario.h"

#include <algorithm>

///////////////////////////////////////////////////////////////////////////////
//                          TNodoAVL                                         //
///////////////////////////////////////////////////////////////////////////////

TNodoAVL::TNodoAVL () :
  _fe(0)
{}


TNodoAVL::TNodoAVL (const TNodoAVL& p_nodo)
{
  CopiarNodoAVL(p_nodo);
}


TNodoAVL::~TNodoAVL ()
{
  _item.~TCalendario();
  _iz.~TAVLCalendario();
  _de.~TAVLCalendario();
}


TNodoAVL &
TNodoAVL::operator= (const TNodoAVL& p_nodo)
{
    if (this != &p_nodo)
      CopiarNodoAVL (p_nodo);

    return *this;
}


///////////////////// AUXILIARES /////////////////////
void
TNodoAVL::CopiarNodoAVL (const TNodoAVL& p_nodo)
{
  _item = p_nodo._item;
  _iz = p_nodo._iz;
  _de = p_nodo._de;
}



///////////////////////////////////////////////////////////////////////////////
//                          TAVLCalendario                                   //
///////////////////////////////////////////////////////////////////////////////

TAVLCalendario::TAVLCalendario () :
  _raiz(NULL)
{}


TAVLCalendario::TAVLCalendario (const TAVLCalendario& p_avl)
{
  CopiarAVL (p_avl);
}


TAVLCalendario::~TAVLCalendario ()
{
  if (_raiz)
  {
      if (_raiz->_de._raiz)
          _raiz->_de.~TAVLCalendario();

      if (_raiz->_iz._raiz)
          _raiz->_iz.~TAVLCalendario();

      delete _raiz;
      _raiz = NULL;
  }
}

/////////////////////////////////////////////// SOBRECARGAS ////////////////////
TAVLCalendario&
TAVLCalendario::operator= (const TAVLCalendario& p_avl)
{
  if (this != &p_avl)
    CopiarAVL (p_avl);

  return *this;
}

bool
TAVLCalendario::operator== (const TAVLCalendario& p_avl) const
{
  return Inorden() == p_avl.Inorden();
}

bool
TAVLCalendario::operator!= (const TAVLCalendario& p_avl) const
{
  return !(Inorden() == p_avl.Inorden());
}


//////////////////////////////////////////// INSERTAR  ////////////////////////
bool
TAVLCalendario::Insertar (const TCalendario& p_cal)
{
	bool crece;

  if (!Buscar(p_cal))
	 return InsertarAux (p_cal, crece);

  else
    return false;
}

bool
TAVLCalendario::Borrar (const TCalendario& p_cal)
{
  bool decrece = false;
  return BorrarAux (p_cal, decrece);
}

bool
TAVLCalendario::BorrarAux (const TCalendario& p_cal, bool& decrece)
{
  TCalendario mayor;

  bool decreceDer = false;
  bool decreceIzq = false;
  bool borrado = false;

  if (_raiz != NULL)
  {
    if (p_cal < _raiz->_item)
      _raiz->_iz.BorrarAux (p_cal, decreceIzq);

    else if (p_cal > _raiz->_item)
      _raiz->_de.BorrarAux (p_cal, decreceDer);

    else if (_raiz->_item == p_cal)
    {
      if (Hoja())
      {
        delete _raiz;
        _raiz = NULL;
        decrece = true;
        borrado = true;
      }

      else if (_raiz->_de.EsVacio())
      {
        _raiz = _raiz->_iz._raiz;
        decrece = true;
        borrado = true;
      }

      else if (_raiz->_iz.EsVacio())
      {
        _raiz = _raiz->_de._raiz;
        decrece = true;
        borrado = true;
      }

      else
      {
        TNodoAVL* aux_nodo;
        mayor = _raiz->_iz.MayorIzquierda();
        aux_nodo = _raiz;
        borrado = BorrarAux (mayor, decrece);
        aux_nodo->_item = mayor;
      }
    }

    Reestructuracion (
      borrado, decreceDer, decreceIzq, decrece
    );
  }

  return borrado;
}

bool TAVLCalendario::Reestructuracion(
  bool& borrado, bool& decreceDe, bool& decreceIz, bool& decrece)
{
	if(borrado)
	{
		if(decreceIz)
      DecreceIzquierda (decrece);

		else if(decreceDe)
      DecreceDerecha (decrece);
	}
}


///////////////////// REESTRUCTURACIONES /////////////////////
void
TAVLCalendario::DecreceIzquierda (bool& decrece)
{
  _raiz->_fe++;

  if(_raiz->_fe == 0)
    decrece = true;

  else if(_raiz->_fe == 1)
    decrece = false;

  else if(_raiz->_fe == 2)
  {
    if (_raiz->_de._raiz->_fe == -1)
    {
      DI();
      decrece = true;
    }
    else if (_raiz->_de._raiz->_fe == 0)
    {
      DD();
      decrece = false;
    }
    else if (_raiz->_de._raiz->_fe == 1)
    {
      DD();
      decrece = true;
    }
  }
}

void
TAVLCalendario::DecreceDerecha (bool& decrece)
{
  _raiz->_fe--;

  if(_raiz->_fe == 0)
    decrece = true;

  else if(_raiz->_fe == -1)
      decrece = false;

  else if(_raiz->_fe == -2)
  {
    if(_raiz->_de._raiz->_fe == -1)
    {
      II();
      decrece = true;
    }
    else if(_raiz->_iz._raiz->_fe == 0)
    {
      II();
      decrece = false;
    }
    else if(_raiz->_iz._raiz->_fe == 1)
    {
      ID();
      decrece = true;
    }
  }
}


void
TAVLCalendario::CreceIzquierda (bool& crece)
{
  _raiz->_fe--;
  if (_raiz->_fe == 0)
      crece = false;

  else if (_raiz->_fe == -1)
      crece = true;

  else if (_raiz->_fe == -2)
  {
      crece = false;
      if (_raiz->_iz._raiz->_fe == -1)
          II();

      if (_raiz->_iz._raiz->_fe == 1)
          ID();
  }
}

void
TAVLCalendario::CreceDerecha (bool& crece)
{
  _raiz->_fe++;

  if (_raiz->_fe == 0)
      crece = false;

  else if (_raiz->_fe == 1)
      crece = true;

  else if (_raiz->_fe == 2)
  {
      crece = false;
      if (_raiz->_de._raiz->_fe == -1)
          DI();

      if (_raiz->_de._raiz->_fe == 1)
          DD();
  }
}

//////////////////////////////// ROTACIONES II DD ID DI ///////////////////////
void
TAVLCalendario::II ()
{
	// TNodoAVL auxiliar
	TNodoAVL *nodoraiz;

	// reordenar
	nodoraiz = _raiz;
	_raiz = nodoraiz->_iz._raiz;
	nodoraiz->_iz._raiz = _raiz->_de._raiz;
	_raiz->_de._raiz = nodoraiz;

	// recalcular f.equilibrio
	if (_raiz->_fe == 0)
	{
		_raiz->_fe = 1;
		_raiz->_de._raiz->_fe = -1;
	}
	else
	{
		_raiz->_fe = 0;
		_raiz->_de._raiz->_fe = 0;
	}
}


void
TAVLCalendario::DD()
{
	TNodoAVL *nodoraiz;

	nodoraiz = _raiz;
	_raiz = nodoraiz->_de._raiz;
	nodoraiz->_de._raiz = _raiz->_iz._raiz;
	_raiz->_iz._raiz = nodoraiz;

	if (_raiz->_fe == 0)
	{
		_raiz->_fe = -1;
		_raiz->_iz._raiz->_fe = 1;
	}
	else
	{
		_raiz->_fe = 0;
		_raiz->_iz._raiz->_fe = 0;
	}
}


void
TAVLCalendario::ID ()
{
	TNodoAVL *auxR, *auxIz, *auxDe;

	auxR = _raiz;
	_raiz = _raiz->_iz._raiz->_de._raiz;
	auxIz = _raiz->_iz._raiz;
	auxDe = _raiz->_de._raiz;

	_raiz->_iz._raiz = auxR->_iz._raiz;
	_raiz->_de._raiz = auxR;
	auxR->_iz._raiz = auxDe;
	_raiz->_iz._raiz->_de._raiz = auxIz;

	if (_raiz->_fe == 0)
		_raiz->_fe = _raiz->_iz._raiz->_fe = _raiz->_de._raiz->_fe = 0;

  else if(_raiz->_fe == -1)
	{
		_raiz->_fe = 0;
		_raiz->_iz._raiz->_fe = 0;
		_raiz->_de._raiz->_fe = 1;
	}

	else
	{
		_raiz->_fe = 0;
		_raiz->_iz._raiz->_fe = -1;
		_raiz->_de._raiz->_fe = 0;
	}
}


void
TAVLCalendario::DI()
{
	TNodoAVL *auxR, *auxIz, *auxDe;

	auxR = _raiz;
	_raiz = _raiz->_de._raiz->_iz._raiz;
	auxIz = _raiz->_iz._raiz;
	auxDe = _raiz->_de._raiz;

	_raiz->_de._raiz = auxR->_de._raiz;
	_raiz->_iz._raiz = auxR;
	auxR->_de._raiz = auxIz;
	_raiz->_de._raiz->_iz._raiz = auxDe;

	if (_raiz->_fe == 0)
		_raiz->_fe = _raiz->_iz._raiz->_fe = _raiz->_de._raiz->_fe = 0;

	else if (_raiz->_fe == -1)
	{
		_raiz->_fe = 0;
		_raiz->_iz._raiz->_fe = 0;
		_raiz->_de._raiz->_fe = 1;
	}

	else
	{
		_raiz->_fe = 0;
		_raiz->_iz._raiz->_fe = -1;
		_raiz->_de._raiz->_fe = 0;
	}
}


/////////////////////////////////  BOORRARAUX; INSERTARAUX /////////////////////

bool
TAVLCalendario::InsertarAux (const TCalendario& p_cal, bool& crece)
{
  bool insertado = false;
  bool creceiz = false;
  bool crecede = false;

  if (!_raiz)
  {
      _raiz = new TNodoAVL;
      _raiz->_fe = 0;
      _raiz->_item = p_cal;
      insertado = true;
      crece = true;
  }

  if (p_cal > _raiz->_item)
      insertado = _raiz->_de.InsertarAux(p_cal, crecede);

  else if (p_cal < _raiz->_item)
      insertado = _raiz->_iz.InsertarAux(p_cal, creceiz);

  // RECALCULAR FE Y ROTAR
  if (creceiz)
    CreceIzquierda (crece);

  else if (crecede)
    CreceDerecha (crece);

  return insertado;
}


/////////////////////// CONSULTORAS ////////////////////////////////////////////
TCalendario
TAVLCalendario::Raiz() const
{
  return _raiz->_item;
}

bool
TAVLCalendario::EsVacio () const
{
  return _raiz == NULL;
}

///////////////////////RAIZ NODOSHOJA BUSCAR NODOS ALTURA //////////////////////
bool
TAVLCalendario::Buscar (const TCalendario& p_cal) const
{
  if (!_raiz)
    return false;

  else if (_raiz->_item == p_cal)
    return true;

  else
    return _raiz->_iz.Buscar (p_cal) ||
           _raiz->_de.Buscar (p_cal);
}


int
TAVLCalendario::Nodos () const
{
  if (_raiz)
		return 1 + _raiz->_iz.Nodos()
			       + _raiz->_de.Nodos();
	else
		return 0;
}


int
TAVLCalendario::Altura () const
{
	if (_raiz)
		return 1 + std::max (
                 _raiz->_iz.Altura(),
		  					 _raiz->_de.Altura());
	else
		return 0;
}


int
TAVLCalendario::NodosHoja () const
{
  if (_raiz== NULL)
    return 0;

	else if (Hoja())
    return 1;

  else
    return _raiz->_iz.NodosHoja() +
          _raiz->_de.NodosHoja();
}

TCalendario
TAVLCalendario::MayorIzquierda () const
{
  if (Hoja())
    return _raiz->_item;

  else if (!_raiz->_de.EsVacio())
    return _raiz->_de.MayorIzquierda();

  else
    return _raiz->_iz.MayorIzquierda();
}

///////////////////////////////////// RECORRIDOS EN PROFUNDIDAD ///////////////
TVectorCalendario
TAVLCalendario::Inorden() const
{
  int posicion = 1;

	TVectorCalendario v (Nodos());
	InordenAux (v, posicion);

	return v;
}

TVectorCalendario
TAVLCalendario::Preorden () const
{
	int posicion = 1;

	TVectorCalendario v(Nodos());
	PreordenAux(v, posicion);

	return v;
}

TVectorCalendario
TAVLCalendario::Postorden () const
{
	int posicion = 1;

	TVectorCalendario v(Nodos());
	PostordenAux(v, posicion);

	return v;
}


///////////////////////////// AUXILIARES //////////////////////////////////////
void
TAVLCalendario::CopiarAVL (const TAVLCalendario& p_avl)
{
  if (p_avl._raiz)
  {
      TNodoAVL* navl_aux = new TNodoAVL();
      navl_aux->_item = p_avl._raiz->_item;

      _raiz = navl_aux;

      (_raiz->_iz).CopiarAVL(p_avl._raiz->_iz);
      (_raiz->_de).CopiarAVL(p_avl._raiz->_de);
  }
  else
      _raiz = NULL;
}


bool
TAVLCalendario::Hoja () const
{
  return (!_raiz->_iz._raiz && !_raiz->_de._raiz);
}

void
TAVLCalendario::PreordenAux (
  TVectorCalendario& p_v, int& p_pos) const
{
	if (_raiz)
	{
		p_v[p_pos++] = _raiz->_item;
		_raiz->_iz.PreordenAux(p_v, p_pos);
		_raiz->_de.PreordenAux(p_v, p_pos);
	}
}


void
TAVLCalendario::PostordenAux (
  TVectorCalendario& p_v, int& p_pos) const
{
	if (_raiz)
	{
		_raiz->_iz.PostordenAux(p_v, p_pos);
		_raiz->_de.PostordenAux(p_v, p_pos);
		p_v[p_pos++] = _raiz->_item;
	}
}


void
TAVLCalendario::InordenAux (
  TVectorCalendario& p_v, int& p_pos) const
{
  if (_raiz)
	{
		_raiz->_iz.InordenAux (p_v, p_pos);
		p_v[p_pos++] = _raiz->_item;
		_raiz->_de.InordenAux (p_v, p_pos);
	}
}
