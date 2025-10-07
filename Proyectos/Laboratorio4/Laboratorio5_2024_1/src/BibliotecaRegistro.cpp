//
// Created by binny on 03/10/2025.
//

#include "BibliotecaRegistro.hpp"
int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    input.get();
    return dato;
}

void* asignar_num(int*dato) {
    int* nuevo_num = new int[1]{};
    int dato_copy = *dato;
    *nuevo_num = dato_copy;
    return nuevo_num;
}

void* clonar_cadena(char* buffer) {
    char * cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}
char* leer_cadena(ifstream &input, char del) {
    char* cadena,  buffer[80];
    input.getline(buffer, 80, del);
    cadena =  new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void * leereg(ifstream &input) {
    void** registro;
    int* ptr_numPedido, numPedido, *ptr_dni,dni;
    char* codLibro;
    ptr_numPedido = new int[1]{};
    ptr_dni = new int[1]{};

    numPedido = leer_int(input);
    dni = leer_int(input);
    codLibro = leer_cadena(input, '\n');

    *ptr_numPedido = numPedido;
    *ptr_dni = dni;

    registro= new void*[3]{};
    registro[NUM_PEDIDO] = ptr_numPedido;
    registro[DNI] = ptr_dni;
    registro[COD_LIBRO] = codLibro;

    return registro;
}

void * clonarreg(void *dato) {
    void** registroAux;
    void** casteo_dato = (void**)dato;

    registroAux = new void*[3]{};
    registroAux[NUM_PEDIDO] = asignar_num((int*)casteo_dato[NUM_PEDIDO]);
    registroAux[DNI] = asignar_num((int*)casteo_dato[DNI]);
    registroAux[COD_LIBRO] = clonar_cadena((char*)casteo_dato[COD_LIBRO]);

    return registroAux;
}

void imprimereg(ofstream &output, void *dato) {
    void** registro = (void**)dato;

    int* numPedido = (int*)registro[NUM_PEDIDO];
    int* dni       = (int*)registro[DNI];
    char* codLibro = (char*)registro[COD_LIBRO];

    cout << setw(5) << *numPedido
         << setw(12) << *dni
         << "  " << codLibro << endl;

    output << setw(5) << *numPedido
           << setw(12) << *dni
           << "  " << codLibro << endl;
}