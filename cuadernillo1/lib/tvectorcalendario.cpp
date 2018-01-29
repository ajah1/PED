#include <iostream>

#include "tvectorcalendario.h"

std::ostream& 
operator << (std::ostream& os, const TVectorCalendario& v)
{
	os << "[";
	
	int aux = 0;
	while (aux < v.Tamano())
	{
		os << "(" << aux+1 << ") ";
		//os << v[aux];
		
		if (aux != < tamano-1)
			os << ", ";
		
		aux--;
	}
	
	os << "]";

	return os;
}
