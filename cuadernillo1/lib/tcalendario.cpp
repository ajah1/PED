#include "tcalendario.h"
#include "operar.h"

#include <iostream>
#include <inttypes.h>


void
TCalendario::Vacio ()
{
	_dia = 1;
    _mes = 1;
    _anyo = 1900;
    _mensaje = nullptr;
}

TCalendario::TCalendario (int dia, int mes, int anyo, char* msj)
{
    if ( operar::comprobarFecha(dia,mes,anyo) )
    {
        _dia = dia;
        _mes = mes;
        _anyo = anyo;
        _mensaje = msj;
    }
    else
        Vacio();
}


bool 
TCalendario::operator == (const TCalendario& c)
{
	bool fecha = (c.Dia()  == _dia) && 
				 (c.Mes()  == _mes) &&
				 (c.Anyo() == _anyo); 
	
	bool mensaje;
	if (_mensaje && c.Mensaje())
	    mensaje = true;
    
    else if (_mensaje && !c.Mensaje())
	    mensaje = false;
	
	else if (!_mensaje && c.Mensaje())
	    mensaje = false;
	    
	return fecha && mensaje;
}


bool
TCalendario::operator > (const TCalendario& c)
{
    bool rf  = operar::mayorFecha (*this, c);
    bool rms = operar::mayorMensaje (_mensaje, c.Mensaje());
    
    if (*this == c)
        return false;
    if (rf)
        return true;
    else if (rms)
        return true;
           
	return false;
}	


bool
TCalendario::operator < (const TCalendario& c)
{
    if ( (*this > c) || (*this == c) )
        return false;
        
    return true;
}


bool 
TCalendario::ModMensaje (char* m)
{
    _mensaje = m;
    return true;
}


std::ostream 
&operator << (std::ostream& os, const TCalendario& c)
{

    if (c.Dia() < 10)
        os << "0" << c.Dia() << "/";
    else
        os << c.Dia() << "/";
        
    if (c.Mes() < 10)
        os << "0" << c.Mes() << "/";
    else
        os << c.Mes() << "/";
        
    os << c.Anyo() << " ";
    
    if (c.Mensaje() == nullptr)
        os << '"' << '"';
    else    
        os << '"' << c.Mensaje() << '"';
    
    return os;
}


TCalendario& 
TCalendario::operator= (const TCalendario& c)
{
    _dia = c.Dia();
    _mes = c.Mes();
    _anyo = c.Anyo();
    _mensaje = c.Mensaje();

    return *this;
}


TCalendario
TCalendario::operator-- (int)
{
    TCalendario original(_dia,_mes,_anyo,_mensaje);
    
    bool bisiesto = _anyo % 4 == 0;
    
    if (_dia == 1 && _mes == 1 && _anyo == 1900)
        Vacio();
    
    else if (_dia == 1 && _mes == 1)
    {
        _anyo--;
        _mes = 12;
        _dia = 31;
    }
    
    else if (_dia == 1)
    {
        _mes--;
        _dia = operar::diasMes(_mes);
        
        if (bisiesto && _mes == 2) 
            _dia++;
    }
    else
        _dia--;
    
    return original;
}

TCalendario&
TCalendario::operator-- ()
{
     bool bisiesto = _anyo % 4 == 0;

    if (_dia == 1 && _mes == 1 && _anyo == 1900)
        Vacio();
    
    else if (_dia == 1 && _mes == 1)
    {
        _anyo--;
        _mes = 12;
        _dia = 31;
    }
    
    else if (_dia == 1)
    {
        _mes--;
        _dia = operar::diasMes(_mes);
        
        if (bisiesto && _mes == 2) 
            _dia++;
    }
    else
        _dia--;

    return *this;
}

















