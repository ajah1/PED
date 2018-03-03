#pragma once

#include "tcalendario.h"
#include <inttypes.h>

namespace operar
{
    // devuelve 1 si la fecha es mayor
    int8_t mayorFecha (const TCalendario&, const TCalendario&);
    
    // devuelve 1 si el mesanje es mayor
    bool mayorMensaje (const char*, const char*);
    
    // devuelve true si la fecha es correcta
    bool comprobarFecha (const int, const int, const int);
    
    // dias que tiene el mes
    int8_t diasMes (const int);

    // devuelve true si las fechas son iguales
    bool igualFecha (const TCalendario&, const TCalendario&);
}
