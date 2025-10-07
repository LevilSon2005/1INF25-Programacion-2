//
// Created by binny on 02/10/2025.
//

#ifndef LABORATORIO5_2024_2_BIBLIOTECAGENERICA_HPP
#define LABORATORIO5_2024_2_BIBLIOTECAGENERICA_HPP

#include "Utils.hpp"

void creaLista(void*&, void* (*leer)(ifstream &),const char* name);
void construir(void*&lista);
bool esListaVacia(void* lista);


#endif //LABORATORIO5_2024_2_BIBLIOTECAGENERICA_HPP