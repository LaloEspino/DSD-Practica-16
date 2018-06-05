//
//  Solicitud.cpp
//  
//
//  Created by Paloma on 18/05/18.
//

#include "Solicitud.hpp"
#include "mensaje.hpp"
#include <string.h>

Solicitud::Solicitud() {
    socketlocal = new SocketDatagrama(9091);
    cout << "Se creo socket 🙂" << endl;
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
    
    struct mensaje msg;
    unsigned int size = sizeof(struct mensaje);
    char guardate[4000];

    /* Se pasan los atributos a la estructura msg */

    msg.messageType = 0;
    msg.requestId = 0;
    strcpy(msg.IP, IP);
    msg.puerto = 9091;
    msg.operationId = operationId;
    memcpy(msg.arguments, arguments, strlen(arguments));
    
    cout << "Se copiaron los argumentos a la estructura 📩" << endl;

    /* Se envia la estructura  */
    
    cout << "Se crea el paquete 📦" << endl;
    for(int i=0; i<=7; i++)
    {
        /* Se envia la estructura  */
        PaqueteDatagrama paq((char *)&msg, size, IP, puerto);
        socketlocal->envia(paq);
        
        cout << "Se envia el paquete 🛫" << endl;

        PaqueteDatagrama pack(strlen(arguments));

        cout << "Se crea el paquete 📦" << endl;

        socketlocal->recibe(pack);

        cout << "Recibe paquete 🛬" << endl;

        memcpy(guardate, pack.obtieneDatos(), sizeof(guardate));

        if(guardate != NULL)
            return guardate;
    }
    
    /*cout << "Se envia el paquete 🛫" << endl;

    Se recibe la respuesta  

    PaqueteDatagrama paq1(strlen(arguments));
    
    cout << "Se crea el paquete 📦" << endl;

    socketlocal->recibeTimeout(paq1, 1, 1);
    
    cout << "Recibe paquete 🛬" << endl;

    char * respuesta = (char *)paq1.obtieneDatos();

    return respuesta;*/
    
}
