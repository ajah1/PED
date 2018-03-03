#include "tcalendario.h"

#include <inttypes.h>

namespace operar
{
    bool igualFecha (const TCalendario& c1, const TCalendario& c2)
    {
        bool iguales = c1.Dia() == c2.Dia() &&
                       c1.Mes() == c2.Mes() &&
                       c1.Anyo() == c2.Anyo();

        return iguales;
    }

    bool mayorFecha (const TCalendario& t1, const TCalendario& t2)
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
  
  
    bool mayorMensaje (const char* c1, const char* c2)
    {
        if (c1 == nullptr && c2 != nullptr)
	        return false;
	
	    else if (c1 != nullptr && c2 == nullptr)
	        return true;
        
        
        bool c2vacio = c2 == "" && c2 == " ";
        bool c1vacio = c1 == "" && c1 == " ";
        bool otro    = c2 == "" && c1 == " ";
        
        if (!c1vacio && c2vacio)
            return true;
            
        else if (!c1vacio && !c2vacio)
            if ( *c1 > *c2)
                return true;
                
        else if (otro || (c2 == " " && !c1vacio))
            return true;
    
        return false;
    }
    
    
    bool comprobarFecha (const int d, const int m, const int a)
    {
        bool low  = d < 1  || m < 1;
        bool pass = d > 31 || m > 12;
        
        if (low || pass || a < 1900)
            return false;
    
        bool bisiesto = a % 4 == 0;
        bool mesPar   = m % 2 == 0;
        
        
        if (bisiesto && m == 2 && d > 29)
            return false;
            
        else if (!bisiesto && m == 2 && d > 28)
            return false;
            
        else if (mesPar && m < 8 && d > 30)
            return false;
        
        else if (!mesPar && m > 7 && d > 30)
            return false;
                  
        return true;
    }
    
    
    int8_t diasMes(const int m)
    {
        int8_t dias_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return dias_mes[m-1];
    }
}
