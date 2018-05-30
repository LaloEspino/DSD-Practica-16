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
        cout << "./client IP PORT CADENA OPERACION" << endl;
        cout << "***********************************************" << endl;

        exit(1);
    }
        
    Solicitud sol;
    
    char IP[16];
    char cadena[4000];
    
    strcpy(IP, argv[1]);
    int port = atoi(argv[2]);
    strcpy(cadena, argv[3]);
    int operacion = atoi(argv[4]);

//    char IP[] = "10.100.66.80";
//    int port = 9091;
//    char cadena[] = "Eduardo Espino y Victor Estrada";
//    int invierteCadena = 1;

    char * respuesta = sol.doOperation(IP, port, operacion, cadena);
    
    cout << respuesta << endl;
    
    return 0;
    
}
