#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tlistacalendario.h"

int
main(void)
{
   TListaCalendario l2;
   TListaCalendario l1;
   TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
   TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");
   
   //l1.Insertar(l1);
   //std::cout << l1 << "\n";
   
   std::cout << std::boolalpha << l1.EsVacia() << "\n";
   std::cout << std::boolalpha << l1.Insertar(c1);
   //std::cout << std::boolalpha << l1.Buscar(c1) << "\n";
   std::cout << l1;
   return 0;
}
