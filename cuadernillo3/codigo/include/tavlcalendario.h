#pragma once

#include "tcalendario.h"
#include "tvectorcalendario.h"

class TNodoAVL;

class TAVLCalendario
{
  friend class TNodoAVL;

private:
  TNodoAVL* _raiz;

  void InordenAux (TVectorCalendario &, int &) const;
  void PreordenAux (TVectorCalendario &, int &) const;
  void PostordenAux (TVectorCalendario &, int &) const;

  void CopiarAVL (const TAVLCalendario &);

  void II();
  void DD();
  void DI();
  void ID();

  bool InsertarAux(const TCalendario&, bool&);

public:
  TAVLCalendario ();
  TAVLCalendario (const TAVLCalendario &);
  ~TAVLCalendario ();

  TAVLCalendario& operator= (const TAVLCalendario &);

  bool operator== (const TAVLCalendario &) const;
  bool operator!= (const TAVLCalendario& p_avl) const;

  bool Insertar (const TCalendario &);
  bool Buscar (const TCalendario &) const;
  bool Hoja () const;

  int Nodos () const;
  int Altura () const;

  TVectorCalendario Inorden () const;
  TVectorCalendario Preorden () const;
  TVectorCalendario Postorden () const;

  void CreceDerecha (bool &);
  void CreceIzquierda (bool &);

  int NodosHoja () const;

  TCalendario Raiz() const;
};


class TNodoAVL
{
friend class TAVLCalendario;

private:
  TCalendario _item;

  TAVLCalendario _iz;
  TAVLCalendario _de;

  int _fe;

  void CopiarNodoAVL (const TNodoAVL &);

public:
  TNodoAVL ();
  TNodoAVL (const TNodoAVL &);
  ~TNodoAVL ();
  TNodoAVL& operator=(const TNodoAVL &);
};
