#include <iostream>

#include "tvectorcalendario.h"

std::ostream& 
operator << (std::ostream& os, const TVectorCalendario& v)
{
	os << "hola que tal";

	return os;
}
