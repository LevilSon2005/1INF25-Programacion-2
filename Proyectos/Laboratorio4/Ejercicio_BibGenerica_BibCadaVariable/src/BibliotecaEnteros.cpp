//
// Created by binny on 30/09/2025.
//

#include "BibliotecaEnteros.hpp"


void* leer_dato_int(ifstream &input) {
    int* ptr_dato, dato;
    input>>dato;
    if (input.eof()) return nullptr;
    ptr_dato = new int;
    *ptr_dato = dato;
    return ptr_dato;
}


void imprimir_nodo_int(const void *dato, ofstream &output) {
    int* num = (int*)dato;
    output<<*num<<endl;
}
