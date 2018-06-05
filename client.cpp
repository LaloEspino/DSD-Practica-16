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
        cout << "./client IP PORT NUM_CICLOS" << endl;
        cout << "***********************************************" << endl;

        exit(1);
    }
        
    Solicitud sol;
    
    char IP[16];
    char cadena[4000];
    char peso[2] = "1";
    
    strcpy(IP, argv[1]);
    int port = atoi(argv[2]);
    int num_ciclos = atoi(argv[3]);
    for(int i=0; i< num_ciclos; i++)
    {
        char * respuesta = sol.doOperation(IP, port, 1, peso);
        cout <<"Lectura:"<<respuesta << endl;
        char * respuesta2 = sol.doOperation(IP, port, 2, peso);
        cout << "Escrituta:"<<respuesta2 << endl;
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
