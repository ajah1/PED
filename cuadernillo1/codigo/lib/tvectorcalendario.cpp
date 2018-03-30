
#include "tvectorcalendario.h"


TCalendario 
TVectorCalendario::operator[] (const int pos) const
{
    TCalendario vacio;

    bool rango = pos >= 1 && pos <= _tamano;
    if ( rango && _c != NULL)
        return _c[pos-1];
    else
        return vacio;
}


std::ostream&
operator << (std::ostream& os, const TVectorCalendario& v)
{	
	if (v._tamano == 0)
	    return os << "[]";

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
    
    if (_c != NULL)
    {
		for (int i = 0; i < _tamano; ++i)
			if ( _c[i] != vacio)
				ocupa++;
	}
	
    return ocupa; 
}


TCalendario&
TVectorCalendario::operator[] (const int pos)
{
    bool rango = pos >= 1 && pos <= _tamano;
    
    if (rango && _c != NULL)
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
	if (v.Calendarios() != NULL)
	{
		_c = new TCalendario[_tamano];

		for (int i = 0; i < v.Tamano(); ++i)
			_c[i] = v[i+1];
	}
	else
		_c = NULL;
	
	return *this;
}


bool
TVectorCalendario::ExisteCal (TCalendario& c)
{
	for (int i = 0; i < _tamano; ++i)
	{
		if (_c[i] == c)
			return true;
	}
	
	return false;
}

/*
Si el entero es mayor que 0 y mayor que el tamaño actual del vector, hay que copiar los
componentes del vector en el vector nuevo, que pasará a tener el tamaño que indica el entero.

Las nuevas posiciones serán vacías, es decir, objetos TCalendario inicializados a 1/1/1900 y
mensaje NULL

Si el entero es mayor que 0 y menor que el tamaño actual del vector, se deben eliminar los
TCalendario que sobren por la derecha, dejando el nuevo tamaño igual al valor del entero.
*/

bool 
TVectorCalendario::Redimensionar (const int& size)
{

	if (size > 0 && size > _tamano)
	{
	    //std::clog << "REDIMENSIONAR: mayor tamano \n";
	    TCalendario* v = new TCalendario[size];
	    
		for (int i = 0; i < size; ++i) 
		{
		    if (i < _tamano)
		        *(v + i) = *(_c + i);
	        else
	        {
	            TCalendario cal;
	            *(v + i) = cal;
	        }
		}
		
		delete [] _c;
		_tamano = size;
		_c = v;
		return true;
	}
	else if (size > 0 && size < _tamano)
	{
	    //std::clog << "REDIMENSIONAR: menor tamano \n";
	    TCalendario* v = new TCalendario[size];
	    
	    for (int i = 0; i < size; ++i)
	        *(v + i) = *(_c + i);
	        
        delete [] _c;
        _tamano = size;
        _c = v;
	    return true;
	}
	
	return false;
}


void
TVectorCalendario::MostrarMensajes (
	const int d, const int m, const int a)
{
    const char* men = NULL;
	TCalendario p_cal(d,m,a,men);

	bool mayor;
	bool igual;

	std::cout << "[";

	for (int i = 0; i < _tamano; ++i)
	{
		mayor = mayorFechas (_c[i],p_cal);
		igual = igualFechas (_c[i],p_cal);

		if (mayor || igual)
			std::cout << _c[i];

		if (i > 0 && i < _tamano - 1)
			std::cout << ", ";
	}
	
	std::cout << "]";
}

bool
TVectorCalendario::operator == (const TVectorCalendario& v) const
{
    if (_tamano == v.Tamano())
    {
        for (int i = 1; i <= _tamano; ++i)
        {
            if ( _c[i-1] != v[i])
                return false;
        }
    }
    else
        return false;
    
    return true;
}


bool
TVectorCalendario::operator != (const TVectorCalendario& v) const
{
    return !(*this == v);
}




//
//------------------------------------------------- FUNCIONES AUXILIARES
//

bool 
TVectorCalendario::igualFechas (const TCalendario& c1, const TCalendario& c2)
{
    bool iguales = c1.Dia() == c2.Dia() &&
                   c1.Mes() == c2.Mes() &&
                   c1.Anyo() == c2.Anyo();

    return iguales;
}

bool 
TVectorCalendario::mayorFechas (const TCalendario& t1, const TCalendario& t2)
{
    if ( t1.Anyo() > t2.Anyo() )
        return true;

    else if ( t1.Anyo() == t2.Anyo() )
    {
        if ( t1.Mes() > t2.Mes() )
            return true;
            
        else if ( t1.Dia() > t2.Dia() )
            return true;
    }
    return false;
}
