//
//  mensaje.hpp
//  
//
//  Created by Paloma on 18/05/18.
//

#ifndef mensaje_hpp
#define mensaje_hpp

#include <stdio.h>

#define TAM_MAX_DATA 4000

struct mensaje{
    int messageType;                // 0 = Solicitud, 1 = Respuesta
    unsigned int requestId;         //Identificador del mensaje
    char IP[16];
    int puerto;
    int operationId;                //Identificador de la operación
    char arguments[TAM_MAX_DATA];
};

#endif /* mensaje_hpp */
