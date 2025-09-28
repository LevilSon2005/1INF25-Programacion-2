//
// Created by binny on 09/09/2025.
//

#ifndef MEMORIA_INCREMENTOS_ORDENADO_FUNCIONES_HPP
#define MEMORIA_INCREMENTOS_ORDENADO_FUNCIONES_HPP

#include "Utils.hpp"
void leer_datos(const char* name, int *&codigos);
void incrementar_memoria(int* &codigos, int &capacidad, int n_codigos);
void insertar_ordenado(int codigo, int* codigos, int n_codigos);
void apertura_escritura(ofstream &ouput, const char* name);

#endif //MEMORIA_INCREMENTOS_ORDENADO_FUNCIONES_HPP