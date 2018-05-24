#include <iostream>
#include "tabbcalendario.h"
#include "tcalendario.h"
#include "tlistacalendario.h"

using namespace std;

int
main(void)
{
  TABBCalendario a;

  TCalendario c1(1,1,2011,"Fecha1");
  TCalendario c2(2,1,2011,"Fecha2");
  TCalendario c3(3,1,2011,"Fecha3");
  TCalendario c4(4,1,2011,"Fecha4");
  TCalendario c5(5,1,2011,"Fecha5");
  TCalendario c6(6,1,2011,"Fecha6");
  TCalendario c7(7,1,2011,"Fecha7");

  a.Insertar(c3);
  a.Insertar(c4);
  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c5);
  a.Insertar(c6);

  std::cout << "ARBOL A RECORRER: " << endl;
  cout << a.Inorden() << "\n\n";

  TListaCalendario l;
  l.Insertar (c5);
  l.Insertar (c1);
  std::cout << "LISTA DE LOS HIJOS: \n" << l << endl;

  std::cout << "\nLISTADO DE PADRES: \n";
  TVectorCalendario resultado_padres;
  resultado_padres = a.PadresDe (l);
  std::cout << resultado_padres;
  cout << "\n\n";

  return 0;
}
