#include <iostream>
#include "tabbcalendario.h"
using namespace std;

int
main(void)
{
	/************************************************/
	/***************** INORDEN, PREORDEN, POSTORDEN */
	/************************************************/

	TABBCalendario a;
	TVectorCalendario vec1, vec2, vec3;

	TCalendario c1(1,1,2011,"Fecha1");
	TCalendario c2(2,1,2011,"Fecha2");
	TCalendario c3(3,1,2011,"Fecha3");
	TCalendario c4(4,1,2011,"Fecha4");
	TCalendario c5(5,1,2011,"Fecha5");
	TCalendario c6(6,1,2011,"Fecha6");

	a.Insertar(c5);
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
	a.Insertar(c6);

	
	vec1 = a.Inorden();
	vec2 = a.Preorden();
	vec3 = a.Postorden();

	cout << "Inorden:   " << vec1 << endl;
	cout << "Preorden:  " << vec2 << endl;
	cout << "Postorden: " << vec3 << endl;

	cout << boolalpha << (c2 > c1) << endl;
	cout << boolalpha << (c1 > c2) << endl;
	cout << boolalpha << (c2 < c1) << endl;
	cout << boolalpha << (c1 < c2) << endl;
	
	return 0;
}

/*
Inorden: [(1) 01/01/2011 "Fecha1", (2) 02/01/2011 "Fecha2", 
		 (3) 03/01/2011 "Fecha3", (4) 05/01/2011 "Fecha5", 
	 	(5) 06/01/2011 "Fecha6"]
	 	
Preorden: [(1) 05/01/2011 "Fecha5", (2) 02/01/2011 "Fecha2", 
		(3) 01/01/2011 "Fecha1", (4) 
		03/01/2011 "Fecha3", (5) 06/01/2011 "Fecha6"]
		
Postorden: [(1) 01/01/2011 "Fecha1", (2) 03/01/2011 "Fecha3", 
		(3) 02/01/2011 "Fecha2", (4) 06/01/2011 "Fecha6", 
		(5) 05/01/2011 "Fecha5"]
*/
