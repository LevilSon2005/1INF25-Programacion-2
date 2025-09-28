//
// Created by binny on 10/09/2025.
//

#ifndef INCREMENTOS_REGISTROS_FUNCIONES_HPP
#define INCREMENTOS_REGISTROS_FUNCIONES_HPP

#include "Utils.hpp"

void cargar_usuarios(char*** &arr_reg_usuarios,int** &arr_registros_fechas, const char* name);
void imprimir_usuarios(char*** arr_registros_usuarios,int** arr_registros_fechas, const char* name);
void cargar_publicaciones(int** &arr_reg_fechasId, char*** &arr_reg_publicaciones,
                          char*** &arr_reg_menciones, const char* name);




#endif //INCREMENTOS_REGISTROS_FUNCIONES_HPP