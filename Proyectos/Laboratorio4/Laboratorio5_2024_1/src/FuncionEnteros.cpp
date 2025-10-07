//
// Created by binny on 03/10/2025.
//

#include "FuncionEnteros.hpp"

void * leenum(ifstream &input) {
    void** dato;
    int* ptr_num, num;
    input>>num;
    if (input.eof()) return nullptr;
    ptr_num = new int[1]{};
    *ptr_num = num;
    dato = new void*[1]{};
    dato[0] = ptr_num;

    return dato;
}

void * clonarnum(void *dato) {
    void** casteo_dato = (void**)dato;
    int* num_original = (int*)casteo_dato[0];

    int* ptr_num = new int[1]{};
    *ptr_num = *num_original;

    void** nuevo_dato = new void*[1]{};
    nuevo_dato[0] = ptr_num;

    return nuevo_dato;
}

void imprimenum(ofstream &output, void *dato) {
    void** casteo_dato = (void**)dato;

    int* num=(int*)casteo_dato[0];
    cout<<*num<<endl;
    output<<*num<<endl;
}
