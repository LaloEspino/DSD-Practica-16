//
//  client.cpp
//
//
//  Created by Lalo Espino on 16/05/18.
//

/*
 *  Invierte cadena -> 1
 */

#include "Solicitud.hpp"
#include <iostream>

using namespace std;

int main(int argc, char ** argv) {
    
    if (argc < 2) {
        
        cout << "***********************************************" << endl;
        cout << "Faltan argumentos necesarios, intente de nuevo." << endl;
        cout << "Ejecute de la siguiente forma:" << endl;
        cout << "./client IP PORT OPERATION_ID" << endl;
        cout << "***********************************************" << endl;

        exit(1);
    }
        
    Solicitud sol;
    
    char IP[16];
    //char dineros[4000];
    char monto[4000];
    
    strcpy(IP, argv[1]);
    int port = atoi(argv[2]);
    int operation_id = atoi(argv[3]);

    if(operation_id == 1)
    {
        cout << "Ingrese su monto" <<endl;
        cin >> monto;
        memcpy(monto, sol.doOperation(IP, port, 1, monto), sizeof(monto));
        printf("El saldo es : %s\n", monto);
    }else{
        memcpy(monto, sol.doOperation(IP, port, 2, monto), sizeof(monto));
        printf("El saldo es : %s\n", monto);
    }

        

//    char IP[] = "10.100.66.80";
//    int port = 9091;
//    char cadena[] = "Eduardo Espino y Victor Estrada";
//    int invierteCadena = 1;

  /*  char * respuesta = sol.doOperation(IP, port, 1, peso);
    cout <<"Lectura:"<<respuesta << endl;
    char * respuesta2 = sol.doOperation(IP, port, 2, peso);
    cout << "Escrituta:"<<respuesta2 << endl;*/
    
    return 0;
    
}
