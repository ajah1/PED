#include "tavlcalendario.h"
#include "tabbcalendario.h"

////////////////////////////////////
//            TNodoAVL            //
////////////////////////////////////

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




////////////////////////////////////
//         TAVLCalendario         //
////////////////////////////////////


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


TAVLCalendario&
TAVLCalendario::operator= (const TAVLCalendario& p_avl)
{
  if (this != &p_avl)
    CopiarAVL (p_avl);

  return *this;
}


////////////////// INSERTAR  ////////////////////////
bool
TAVLCalendario::Insertar (const TCalendario& p_cal)
{
  bool creceDer = false;
  bool creceIzq = false;
  bool crece = false;

  if (!Buscar (p_cal))
  {
    // Insertar en arbol vacio
    if (!_raiz)
    {
      _raiz = new TNodoAVL();
      _raiz->_item = p_cal;
    }

    else
    {
      InsertarHoja (p_cal, creceDer, creceIzq);
    }

    return true;
  }

  return false;
}


void TAVLCalendario::II ()
{
}

////////////////// BUSCAR NODOS  ////////////////////////
bool
TAVLCalendario::Buscar (const TCalendario& p_cal) const
{
  if (_raiz == NULL)
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


//////////// RECORRIDOS EN PROFUNDIDAD ///////////////
TVectorCalendario
TAVLCalendario::Inorden() const
{
  int posicion = 1;

	TVectorCalendario v (Nodos());
	InordenAux (v, posicion);

	return v;
}


void
TAVLCalendario::InordenAux (TVectorCalendario& p_v, int& p_pos) const
{
  if (_raiz)
	{
		_raiz->_iz.InordenAux (p_v, p_pos);
		p_v[p_pos++] = _raiz->_item;
		_raiz->_de.InordenAux (p_v, p_pos);
	}
}


///////////////////// AUXILIARES /////////////////////
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
TAVLCalendario::InsertarHoja (
    const TCalendario& p_cal,
    bool& creceDer, bool& creceIzq)
{
  if (Hoja())
  {
    if (p_cal < _raiz->_item)
    {
      _raiz->_iz._raiz = new TNodoAVL();
      _raiz->_iz._raiz->_item = p_cal;
      creceIzq = true;
    }
    else
    {
      _raiz->_de._raiz = new TNodoAVL();
      _raiz->_de._raiz->_item = p_cal;
      creceDer = true;
    }
  }

  else if (p_cal < _raiz->_item)
    _raiz->_iz.InsertarHoja (p_cal, creceDer, creceIzq);

  else
    _raiz->_de.InsertarHoja (p_cal, creceDer, creceIzq);
}
