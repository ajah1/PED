#include <iostream>

using namespace std;

#include "tcalendario.h"


int
main()
{

   TCalendario cal1(29,02,2008, (char*) "Fecha correcta");
   
   cout<<cal1-30<<endl;
  
}
