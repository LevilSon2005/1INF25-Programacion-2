//
// Created by binny on 29/09/2025.
//

#ifndef LISTA_BIBLIOTECAGENERICA_HPP
#define LISTA_BIBLIOTECAGENERICA_HPP
#include "Utils.hpp"

void crear_lista_empleados(const char* name, void* &lista,
                            void* (*leer)(ifstream &), int (*comparar)(const void*, const void*));
void insertar(void* &lista,void* registro, int (*comparar)(const void*, const void*));
void imprimir(void* lista, void(*imprimir)(void*, ofstream &));
#endif //LISTA_BIBLIOTECAGENERICA_HPP