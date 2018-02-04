#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tvectorcalendario.h"


int
main(void)
{
   TVectorCalendario a(3);
   TVectorCalendario b(3);
   
   TCalendario a1(1,1,2006, (char*) "uno"), 
               a2(1,2,2006, (char*) "dos"), 
               a3(1,3,2006, (char*) "tres");
   
   TCalendario b1(1,1,2006, (char*) "uno"), 
               b2(1,2,2006, (char*) "dos"), 
               b3(1,3,2006, (char*) "tres");;

   a[1]=a1;
   a[2]=a2;
   a[3]=a3;
   
   b[1]=b1;
   b[2]=b2;
   b[3]=b3;
   
   bool k;
   for (int i = 1; i <= 3; ++i)
   {
        k = a[i] == b[i];
        std::cout << std::boolalpha << k << std::endl;
   }
   
   return 0;
}
