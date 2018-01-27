#include "tcalendario.h"
#include "operar.h"

#include <iostream>
#include <inttypes.h>

//  CONTROLAR FECHA CORRECTA
TCalendario::TCalendario (int dia, int mes, int anyo, char* msj) :
	_dia(dia),
	_mes(mes), 
	_anyo(anyo),
	_mensaje(msj)
{}

bool 
TCalendario::operator == (const TCalendario& c)
{
	bool fecha = (c.Dia()  == _dia) && 
				 (c.Mes()  == _mes) &&
				 (c.Anyo() == _anyo); 
	
	bool mensaje = (*c.Mensaje() == *_mensaje);
	
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











