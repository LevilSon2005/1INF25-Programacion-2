//
// Created by binny on 03/10/2025.
//

#ifndef LABORATORIO5_2024_1_BIBLIOTECAGENERICA_HPP
#define LABORATORIO5_2024_1_BIBLIOTECAGENERICA_HPP

#include "Utils.hpp"

void creaLista(void* &lista, void* (*leer) (ifstream&input),
                void*(*clonar)(void*), const char* name);
void insertar(void* &lista, void* dato, void*(*clonar)(void*));
void imprimeLista(void* lista, void (*imprimir)(ofstream &, void* lista),
                    const char* name);

#endif //LABORATORIO5_2024_1_BIBLIOTECAGENERICA_HPP