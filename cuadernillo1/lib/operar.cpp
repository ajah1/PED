#include "tcalendario.h"

#include <inttypes.h>

namespace operar
{
    int8_t mayorFecha (TCalendario& t1, const TCalendario& t2)
    {
        if ( t1.Anyo() > t2.Anyo() )
            return 1;
            
        else if ( t2.Anyo() > t1.Anyo() )
            return 2;
    
        else if ( t1.Anyo() == t2.Anyo() )
        {
            if ( t1.Mes() > t2.Mes() )
                return 1;
                
            else if ( t2.Mes() > t1.Mes() )
                return 2;
                
            else if ( t1.Dia() > t2.Dia() )
                return 1;
                
            else if ( t2.Dia() > t1.Dia() )
                return 2;
        }
        
        return 0;
    }
    
    int8_t mayorMensaje (char c1, char c2)
    {
        
        if ( !c1 && c2 )
            return 1;
        
        else if  
    
        return 0;
    }
}
