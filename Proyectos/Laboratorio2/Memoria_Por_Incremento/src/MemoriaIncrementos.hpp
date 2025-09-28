//
// Created by binny on 09/09/2025.
//

#ifndef MEMORIA_POR_INCREMENTO_MEMORIAINCREMENTOS_HPP
#define MEMORIA_POR_INCREMENTO_MEMORIAINCREMENTOS_HPP

#include "Utils.hpp"
void apertura_lectura(ifstream &input, const char* name) ;
void apertura_escritura(ofstream &ouput, const char* name);
int leer_int(ifstream &input);
void leer_datos(const char* name, int* &codigos, int& n_codigos);
void incrementar_memoria(int *&codigos,int n_codigos, int &capacidad);



#endif //MEMORIA_POR_INCREMENTO_MEMORIAINCREMENTOS_HPP