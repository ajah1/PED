#include "tvectorcalendario.h"


TCalendario 
TVectorCalendario::operator[] (int pos) const
{
    TCalendario vacio;

    if (pos < _tamano && _c != nullptr && pos >= 1)
        return _c[pos - 1];
    else
        return vacio;
}

std::ostream& 
operator << (std::ostream& os, const TVectorCalendario& v)
{
	os << "[";
	
    for (int i = 0; i < v._tamano; ++i)
	{
		os << "(" << i+1 << ") ";
		os << v[i];
		
		if (i < v._tamano-1)
			os << ", ";
	}
	
	os << "]";

	return os;
}
