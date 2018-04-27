#include <iostream>

#include "tabbcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

int
main(void)
{
/***************************************************/
/***************** SUMA,INORDEN 	           */
/***************************************************/
  TABBCalendario a,b, suma;
  TVectorCalendario vec;

  TCalendario c1(1,1,2011,"Fecha1");
  TCalendario c2(2,1,2011,"Fecha2");
  TCalendario c3(3,1,2011,"Fecha3");
  TCalendario c4(4,1,2011,"Fecha4");
  TCalendario c5(5,1,2011,"Fecha5");

  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);

  b.Insertar(c4);
  b.Insertar(c5);

  suma = a+b;

  vec = suma.Inorden();

	cout << "a: " << a.Inorden() << endl;
	cout << "b: " << b.Inorden() << endl;
	cout <<"a + b = "<< vec << endl;
	
  return 0; 

}

/*
Inorden Suma: [(1) 01/01/2011 "Fecha1", (2) 02/01/2011 "Fecha2", (3) 03/01/2011 "Fecha3", (4) 04/01/2011 "Fecha4", (5) 05/01/2011 "Fecha5"]

*/
