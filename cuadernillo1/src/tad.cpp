#include <iostream>

using namespace std;

#include "tcalendario.h"


int
main()
{
	 TCalendario c0();
   TCalendario c1(1,1,1, (char*) "");
   TCalendario c2(1,1,1, (char*) "");
   
   
   //if (c1==c2) cout<<"IGUALES"<<endl;
   if (c1>c2) cout<<"c1 mayor c2"<<endl;
   else cout << "error" << endl;
   //if (c1<c2) cout<<"ERROR2"<<endl;
    
    /* 
   c2.ModMensaje(NULL);
   if (c1==c2) cout<<"ERROR1"<<endl;
   if (c1>c2) cout<<"MAYOR"<<endl;
   if (c1<c2) cout<<"ERROR2"<<endl;
 */
}
