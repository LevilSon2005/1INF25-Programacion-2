//
// Created by binny on 30/09/2025.
//

#ifndef EJERCICIO_BIBGENERICA_BIBCADAVARIABLE_BIBLIOTECAGENERICA_HPP
#define EJERCICIO_BIBGENERICA_BIBCADAVARIABLE_BIBLIOTECAGENERICA_HPP

#include "Utils.hpp"

void crearLista(const char* name, void* &lista_pedido,
                void* (*leer) (ifstream&));
void generarLista(void* &lista_pedido);
bool esListaVacia(const void* lista);
void insertar(void* dato, void* &lista_pedido);
void imprimirLista(const char* name,const void* lista_pedido,void(*imprimir)(const void*, ofstream&));
void combinaLista(void* lista1, void* lista2, void*& lista_final, int(*comparar)( void*, void*));
#endif //EJERCICIO_BIBGENERICA_BIBCADAVARIABLE_BIBLIOTECAGENERICA_HPP