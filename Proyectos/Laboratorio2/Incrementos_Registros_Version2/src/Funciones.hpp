//
// Created by binny on 12/09/2025.
//

#ifndef INCREMENTOS_REGISTROS_VERSION2_FUNCIONES_HPP
#define INCREMENTOS_REGISTROS_VERSION2_FUNCIONES_HPP

#include "Utils.hpp"

void cargar_usuarios(int** &arrRegFechas,char***&arrRegUsuarios,const char* name);
void  cargar_publicaciones(int**& arrRegIndices,char*** &arrRegPublicaciones,
                            char*** &arrRegMenciones, const char* name);

#endif //INCREMENTOS_REGISTROS_VERSION2_FUNCIONES_HPP