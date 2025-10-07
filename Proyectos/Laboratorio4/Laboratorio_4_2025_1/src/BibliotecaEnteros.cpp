//
// Created by binny on 01/10/2025.
//

#include "BibliotecaEnteros.hpp"

void * leenum(ifstream &input) {
    void** dato =  new void*[1]{};
    int num, *ptr_num;
    input >> num;
    ptr_num = new int;
    *ptr_num = num;
    dato[0]=ptr_num;
    return dato;
}

int clasificaentero(void *dato) {
    void** casteo_dato = (void**)dato;
    int* ptr_num = (int*)casteo_dato[0];
    int num = *ptr_num;
    if ( num<10) return 1;
    else return 2;
}

void imprimenum(ofstream &output, void *dato) {
    void** casteo_dato = (void**)dato;
    int* ptr_num = (int*)casteo_dato[0];
    int num = *ptr_num;
    output << num << endl;
}
