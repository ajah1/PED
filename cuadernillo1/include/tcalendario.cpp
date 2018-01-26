#include "tcalendario.h"

#include <iostream>

TCalendario::TCalendario () :
	_dia(1),
	_mes(1), 
	_anyo(1990),
	_mensaje(nullptr)
{
	std::cout << "Por defecto calendario" << std::endl;
}

TCalendario::TCalendario (int dia, int mes, int anyo, char* msj) :
	_dia(dia),
	_mes(mes), 
	_anyo(anyo),
	_mensaje(msj)
{
	std::cout << "Parametrizado calendario" << std::endl;
}
