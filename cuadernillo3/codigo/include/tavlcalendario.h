#pragma once

#include "tcalendario.h"
#include "tvectorcalendario.h"

////// FORWARD DECLARATION ////
class TNodoAVL;

class TAVLCalendario
{
  friend class TNodoAVL;

private:
  TNodoAVL* _raiz;

  ////////////////// FUNCIONES AUXILIARES //////////////
  void InordenAux (TVectorCalendario &, int &) const;
  void PreordenAux (TVectorCalendario &, int &) const;
  void PostordenAux (TVectorCalendario &, int &) const;

  bool InsertarAux(const TCalendario&, bool&);
  bool insertaraux(const TCalendario&, bool&);
  bool BorrarAux(const TCalendario&, bool&);

  bool ComprobarHoja () const;

  void II();
  void DD();
  void DI();
  void ID();

  void CreceDerecha (bool &);
  void CreceIzquierda (bool &);
	void DecreceIzq (bool &);
	void DecreceDer (bool &);

  void CopiarNodoAVL (const TNodoAVL&);
  void CopiarAVL (const TAVLCalendario&);

  void BorrarHoja ();
  void BorrarConCriterio ();

  void Reestructuracion (
    bool&, bool&, bool&, bool&
  );

  TCalendario BuscarMayor() const;


public:
  TAVLCalendario ();
  TAVLCalendario (const TAVLCalendario &);
  ~TAVLCalendario ();

  TAVLCalendario& operator= (const TAVLCalendario &);

  bool operator== (const TAVLCalendario &) const;
  bool operator!= (const TAVLCalendario& p_avl) const;

  bool Insertar (const TCalendario &);
  bool Borrar (const TCalendario &);
  bool Buscar (const TCalendario &) const;
  bool EsVacio () const;

  int Nodos () const;
  int Altura () const;
  int NodosHoja () const;

  TCalendario Raiz() const;

  TVectorCalendario Inorden () const;
  TVectorCalendario Preorden () const;
  TVectorCalendario Postorden () const;
};


class TNodoAVL
{
friend class TAVLCalendario;

private:
  TCalendario _item;

  TAVLCalendario _iz;
  TAVLCalendario _de;

  int _fe;

  ///////////////////////// AUXILIAR ///////////
  void CopiarNodoAVL (const TNodoAVL &);

public:
  TNodoAVL ();
  TNodoAVL (const TNodoAVL &);
  ~TNodoAVL ();
  TNodoAVL& operator=(const TNodoAVL &);
};
