//
// Created by binny on 11/09/2025.
//

#ifndef LABORATORIO2_22033905_ROMERO_BINNY_FUNCIONES_HPP
#define LABORATORIO2_22033905_ROMERO_BINNY_FUNCIONES_HPP

#include "Utils.hpp"
// void cargar_conductores(struct Conductores &arr_conductores, const char* name);
void operator+=(struct Conductores& arr_conductores, const char* name);
void operator+=(struct Infracciones& infracciones, const char* name);
void cargar_faltas_de_los_conductores(struct Faltas &faltas);

#endif //LABORATORIO2_22033905_ROMERO_BINNY_FUNCIONES_HPP