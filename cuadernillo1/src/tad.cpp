#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tlistacalendario.h"

int
main(void)
{
   TListaCalendario l1;
   TCalendario c1;
   TCalendario c2(1, 1, 2002, (char*) "Fecha2");
   TCalendario c3(1, 1, 2003, (char*) "Fecha3");
   TCalendario c4(1, 1, 2004, (char*) "Fecha4");
   TCalendario c5(1, 1, 2005, (char*) "Fecha5");
   TCalendario c6(1, 1, 2006, (char*) "Fecha6");

   l1.Insertar(c3);
   l1.Insertar(c2); 
   
   std::cout << l1 << "\n";
   
   //cout << std::boolalpha <<l1.Borrar(c4) << endl;
  // cout << "\n" << l1 << endl;

   return 0;
}
