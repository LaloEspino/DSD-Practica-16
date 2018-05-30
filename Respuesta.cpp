//
//  Respuesta.cpp
//  
//
//  Created by Paloma on 18/05/18.
//

#include "Respuesta.hpp"
#include "SocketDatagrama.h"
#include "mensaje.hpp"

Respuesta::Respuesta(int pl) {
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje *Respuesta::getRequest(void) {
    
    /* Para comprobar que recibio un dato */
    int size = sizeof(struct mensaje);
    PaqueteDatagrama pack(size);
    
    socketlocal->recibe(pack);
    cout << "¡Ya conecto! 🤓" << endl;
    cout << "Recibio paquete 📦" << endl;
    
    struct mensaje msg;
    
    // Copia los datos recibidos a una estructura
    memcpy(&msg, pack.obtieneDatos(), size);
    
    strcpy(msg.IP, pack.obtieneDireccion());

    // Imprime valores recibidos
    cout << "********** Values **********" << endl;
    cout << "msg.TP: " << msg.messageType << endl;
    cout << "msg.ID: " << msg.requestId << endl;
    cout << "msg.IP: " << msg.IP << endl;
    cout << "msg.PT: " << msg.puerto << endl;
    cout << "msg.OP: " << msg.operationId << endl;
    cout << "msg.AR: " << msg.arguments << endl;
    cout << "****************************" << endl;
        
	return &msg;
}


void Respuesta::sendReply(char *respuesta, char *ipClient, int puertoCliente) {
    
    SocketDatagrama *sck = new SocketDatagrama(puertoCliente);
    
    int size = strlen(respuesta);
    
    PaqueteDatagrama paq(respuesta, size, ipClient, puertoCliente);
    sck->envia(paq);
    
    cout << "Enviado ✈️" << endl;
}
