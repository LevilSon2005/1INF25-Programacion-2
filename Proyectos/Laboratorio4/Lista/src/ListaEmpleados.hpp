//
// Created by binny on 29/09/2025.
//

#ifndef LISTA_LISTAEMPLEADOS_HPP
#define LISTA_LISTAEMPLEADOS_HPP

#include "Utils.hpp"

void* leer_empleado (ifstream &input);
int comparar_empleados_nombres(const void* a, const void* b);
void imprimir_empleado(void* lista, ofstream &output);

#endif //LISTA_LISTAEMPLEADOS_HPP