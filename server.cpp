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
        struct mensaje local;
        memcpy(&local, &msg, sizeof(msg));
        //int longitud = strlen(msg.arguments);
        //char invertido[longitud];
        
        /* Se realiza la operación según la operación solicitada */
        
        if(msg.operationId == 1)
        {
            cout<< "Que esta pasando"<<endl;
            char *saldo = new char;
                sprintf(saldo,"%i",nbd);
                //cout << saldo;
                strcpy(local.arguments, saldo);
                cout << "ARGS: " << local.arguments << endl;
                
            //Operacion de lectura
        }else{
            cout<< "Que esta pasando"<<endl;
            int nbd1 = atoi(local.arguments);
            //cout << "VALOR DE NBD1: " << nbd1;
                nbd += nbd1;

           // printf("VALOR DE LA SUMA: %d \n", nbd += nbd1);
            
                char *saldo1 = new char;
                sprintf(saldo1,"%i",nbd);
            //cout << "VALOR DE SALDO1: " << saldo1;
                strcpy(local.arguments, saldo1);
                cout << "ARGS: " << local.arguments << endl;
            //Operacion de escritura
                

        }

        cout << "Valor en la cuenta :" << local.arguments << endl;
        res.sendReply(local.arguments, local.IP, local.puerto);

        
        














        /*switch (msg.operationId) {
            case 0:
                char *saldo = new char;
                sprintf(saldo,"%i",nbd);
                //cout << saldo;
                strcpy(local.arguments, saldo);
                cout << "ARGS: " << local.arguments << endl;
                cout << "Valor en la cuenta :" << local.arguments << endl;
                res.sendReply(local.arguments, local.IP, local.puerto);
            //Operacion de lectura
            break;

            case 1:
                int nbd1 = atoi(local.arguments);
            //cout << "VALOR DE NBD1: " << nbd1;
                nbd += nbd1;

           // printf("VALOR DE LA SUMA: %d \n", nbd += nbd1);
            
                char *saldo1 = new char;
                sprintf(saldo1,"%i",nbd);
            //cout << "VALOR DE SALDO1: " << saldo1;
                strcpy(local.arguments, saldo1);
                cout << "ARGS: " << local.arguments << endl;
            //Operacion de escritura
                cout << "Valor en la cuenta :" << local.arguments << endl;
                res.sendReply(local.arguments, local.IP, local.puerto);

            break;
            
                
            default:
                char ERROR [] = "ERROR";
                cout << ERROR << endl;
                strcpy(msg.arguments, ERROR);
            break;
        }*/
        
       // cout << "IP " << msg.IP << "PT " << msg.puerto << endl;
        //res.sendReply(msg.arguments, msg.IP, msg.puerto);

    }

    return 0;
}
