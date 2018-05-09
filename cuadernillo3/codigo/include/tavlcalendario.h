#pragma once

#include "tcalendario.h"

class TNodoAVL;

class TAVLCalendario
{
friend class TNodoAVL;

private:
  // Puntero al nodo raíz
  TNodoAVL* _raiz;

  // codigo repetitivo
  void CopiarAVL (const TAVLCalendario &);

public:
  // Constructor por defecto
  TAVLCalendario ();
  // Constructor de copia
  TAVLCalendario (const TAVLCalendario &);
  // Destructor
  ~TAVLCalendario ();

  // Sobrecarga del operador asignación
  TAVLCalendario& operator= (const TAVLCalendario &);
};


class TNodoAVL
{
friend class TAVLCalendario;

private:
  // El elemento (etiqueta) del nodo
  TCalendario _item;

  // Subárbol izquierdo y derecho
  TAVLCalendario _iz;
  TAVLCalendario _de;

  // Factor de equilibrio
  int _fe;

  // codigo que se repite en la forma canonica
  void CopiarNodoAVL (const TNodoAVL &);

public:
  //Constructor por defecto
  TNodoAVL ();
  //Constructor copia
  TNodoAVL (const TNodoAVL &);
  //Destructor
  ~TNodoAVL ();
  // Sobrecarga del operador asignación
  TNodoAVL& operator=(const TNodoAVL &);

};
