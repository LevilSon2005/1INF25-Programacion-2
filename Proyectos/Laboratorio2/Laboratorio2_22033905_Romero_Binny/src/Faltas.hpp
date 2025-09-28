//
// Created by binny on 11/09/2025.
//

#ifndef LABORATORIO2_22033905_ROMERO_BINNY_FALTAS_HPP
#define LABORATORIO2_22033905_ROMERO_BINNY_FALTAS_HPP
#include "Conductores.hpp"
#include "Infracciones.hpp"
struct Faltas{
    struct Conductores conductores;
    struct Infracciones infracciones;

    char*** placas; // *
    int* capacidades;//
};
#endif //LABORATORIO2_22033905_ROMERO_BINNY_FALTAS_HPP