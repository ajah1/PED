/************************************************************
** INSERTAR, ALTURA, PREORDEN
*************************************************************/
#include <iostream>
#include "tavlcalendario.h"

using namespace std;

int
main(void)
{
  TAVLCalendario a;
  TCalendario cal1(1,1,2011,(char *)"uno");
  TCalendario cal2(2,1,2011,(char *)"dos");
  TCalendario cal3(3,1,2011,(char *)"tres");
  TCalendario cal4(4,1,2011,(char *)"cuatro");


  a.Insertar(cal3);

  a.Insertar(cal2);
  /*
  std::cout << boolalpha << "buscar: " << a.Buscar (cal2) << endl;
  std::cout << "nodos: " << a.Nodos() << endl;
  std::cout << a.Inorden () << endl;
  std::cout << "***************" << endl;
  */

  a.Insertar(cal1);
  std::cout << a.Inorden () << endl;
  /*
  if (a.Insertar(cal4))
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;
  if (a.Insertar(cal3))
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  cout << "Altura: " << a.Altura() << endl;
  cout << a.Preorden() <<endl;
  */
  return 0;
}
