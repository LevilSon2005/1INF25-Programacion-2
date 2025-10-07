//
// Created by binny on 01/10/2025.
//

#ifndef LABORATORIO_4_2025_1_BIBLIOTECAGENERICA_HPP
#define LABORATORIO_4_2025_1_BIBLIOTECAGENERICA_HPP

#include "Utils.hpp"

void generaLista(void* &lista);
void insertar(void* &lista, void* dato, int bloque);
void crearLista(void* &lista, void* (*leer)(ifstream &input),
                int(*clasifica)(void* dato), const char* name);
void imprimeLista(void* &lista, void(*imprimir)(ofstream &output,void* ),
                const char* name);


#endif //LABORATORIO_4_2025_1_BIBLIOTECAGENERICA_HPP