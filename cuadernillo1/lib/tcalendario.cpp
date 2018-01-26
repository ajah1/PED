#include "tcalendario.h"

#include <iostream>

TCalendario::TCalendario () :
	_dia(1),
	_mes(1), 
	_anyo(1900),
	_mensaje(nullptr)
{}

TCalendario::TCalendario (int dia, int mes, int anyo, char* msj) :
	_dia(dia),
	_mes(mes), 
	_anyo(anyo),
	_mensaje(msj)
{}

TCalendario::~TCalendario ()
{
	_dia = 1;
	_mes = 1;
	_anyo = 1900;
	_mensaje = nullptr;
}

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
	// T1 > F2 cuando ...
	
	/*
		1. T1 posterior T2
		2. t1 == t2, t1.m > t2.m
			----> t1 == t2, t1.m == t2.m <--- FALSE
		3. null < "" < " " < otra
	*/

	return false;
}	












