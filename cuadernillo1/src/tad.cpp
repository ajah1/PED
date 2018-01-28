#include <iostream>

using namespace std;

#include "tcalendario.h"


int
main()
{
   char* fi = (char*) "Fecha incorrecta";
   char* fc = (char*) "Fecha correcta";
      
   TCalendario cal1(31,12,2006, fc);
   TCalendario cal2(05,01,1900, fi);
   
   cal2=cal1++;
   cout<<cal2<<endl;
   cout<<cal1<<endl;
   
   /*
   cal2=++cal1;
   cout<<cal2<<endl;
   cout<<cal1<<endl;*/
}
