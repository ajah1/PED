#include "tvectorcalendario.h"


TCalendario 
TVectorCalendario::operator[] (int pos) const
{
    TCalendario vacio;

    bool rango = pos >= 1 && pos <= _tamano;
    if ( rango && _c != nullptr)
        return _c[pos-1];
    else
        return vacio;
}


std::ostream&
operator << (std::ostream& os, const TVectorCalendario& v)
{
	os << "[";
	
    for (int i = 1; i <= v._tamano; ++i)
	{
		os << "(" << i << ") ";
		os << v[i];
		
		if (i < v._tamano)
			os << ", ";
	}
	
	os << "]";

	return os;
}


int 
TVectorCalendario::Ocupadas() const
{
    int ocupa = 0;
 
    TCalendario vacio;
    
    if (_c != nullptr)
    {
		for (int i = 0; i < _tamano; ++i)
			if ( _c[i] == vacio)
				ocupa++;
	}
	
    return ocupa; 
}


TCalendario&
TVectorCalendario::operator[] (int pos)
{
    bool rango = pos >= 1 && pos <= _tamano;
    
    if (rango && _c != nullptr)
        return _c[pos-1];
    else
        return _error;
}


TVectorCalendario& 
TVectorCalendario::operator=(TVectorCalendario& v)
{
	this->~TVectorCalendario();
	
	_tamano = v.Tamano();
	
	// si v no está vacio
	if (v.Calendarios() != nullptr)
	{
		_c = new TCalendario[_tamano];

		for (int i = 0; i < v.Tamano(); ++i)
			_c[i] = v[i+1];
	}
	else
		_c = nullptr;
	
	return *this;
}










