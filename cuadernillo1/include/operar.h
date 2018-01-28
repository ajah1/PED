#pragma once

#include "tcalendario.h"
#include <inttypes.h>

namespace operar
{
    // devuelve 1 si la fecha es mayor
    int8_t mayorFecha (TCalendario&, const TCalendario&);
    
    // devuelve 1 si el mesanje es mayor
    bool mayorMensaje (char*, char*);
    
    // devuelve true si la fecha es correcta
    bool comprobarFecha (int, int, int);
}
