#include "tavlcalendario.h"
#include "tabbcalendario.h"
#include "tvectorcalendario.h"

////////////////////////////////////
//            TNodoAVL            //
////////////////////////////////////

TNodoAVL::TNodoAVL ()
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
