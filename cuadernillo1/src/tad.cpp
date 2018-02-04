#include <iostream>

using namespace std;

#include "tvectorcalendario.h"

int
main(void)
{
   TVectorCalendario a(3), b(3);
   
   TCalendario ca1(1,1,2006, (char*) "uno"), 
               ca2(1,2,2006, (char*) "dos"), 
               ca3(1,3,2006, (char*) "tres");
   
   
   TCalendario cb1(1,1,2006, (char*) "uno"), 
               cb2(1,2,2006, (char*) "dos"), 
               cb3(1,3,2006, (char*) "tres");
   
   a[1] = ca1;
   a[2] = ca2;
   a[3] = ca3;
   
   
   b[1] = cb1;
   b[2] = cb2;
   b[3] = cb3;
   
    std::cout << std::boolalpha << (a==b) << std::endl;
   
   return 0;
}
