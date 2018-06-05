//
//  server.cpp
//  
//
//  Created by Lalo Espino on 16/05/18.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Respuesta.hpp"
#include "mensaje.hpp"

using namespace std;

int main() {

    Respuesta res(9091);
    unsigned int nbd = 0;
    
    
    while (true) {
        cout << endl << "Esperando conexión... 🙄" << endl;
        struct mensaje msg = *res.getRequest();
        
        //int longitud = strlen(msg.arguments);
        //char invertido[longitud];
        
        /* Se realiza la operación según la operación solicitada */
        
        switch (msg.operationId) {
            case 1:
                cout << "Bienvenido"<<endl;
                cout << "Usted desea consultar su saldo"<<endl;
                nbd = 1;
                nbd++;

            //Operacion de lectura
            break;

            case 2:
            //Operacion de escritura
            break;
            /*case 1:
                 Invierte cadena 

                longitud = strlen(msg.arguments);
                invertido[longitud];

                for (int x = 0, y = longitud - 1; x < longitud; x ++, y --) {
                    invertido[x] = msg.arguments[y];
                }

                invertido[longitud] = '\0';

                strcpy(msg.arguments, invertido);
                
                 Invierte cadena 
                
                break;*/
                
            default:
                char ERROR [] = "ERROR";
                cout << ERROR << endl;
                strcpy(msg.arguments, ERROR);
                break;
        }
        
        cout << "IP " << msg.IP << "PT " << msg.puerto << endl;
        
        res.sendReply(msg.arguments, msg.IP, msg.puerto);

    }

    return 0;
}
