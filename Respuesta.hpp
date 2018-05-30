//
//  Respuesta.hpp
//  
//
//  Created by Paloma on 18/05/18.
//

#ifndef Respuesta_hpp
#define Respuesta_hpp

#include <stdio.h>
#include "SocketDatagrama.h"
#include "mensaje.hpp"

class Respuesta{
public:
    Respuesta(int pl);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
    SocketDatagrama *socketlocal;
};

#endif /* Respuesta_hpp */
