//
//  Solicitud.hpp
//  
//
//  Created by Paloma on 18/05/18.
//

#ifndef Solicitud_hpp
#define Solicitud_hpp

#include <stdio.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

class Solicitud{
public:
    Solicitud();
    char * doOperation(char *IP, int puerto, int operationId, char *arguments);
private:
    SocketDatagrama *socketlocal;
};

#endif

/* Solicitud_hpp */
