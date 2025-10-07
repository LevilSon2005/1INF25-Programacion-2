

//
// Created by binny on 01/10/2025.
//

#ifndef LABORATORIO_4_2025_1_BIBLIOTECAREGISTROS_HPP
#define LABORATORIO_4_2025_1_BIBLIOTECAREGISTROS_HPP

#include "Utils.hpp"
void* leeregistro(ifstream &input);
int clasificaregistro(void* dato);
void imprimeregistro(ofstream &output, void *dato);

#endif //LABORATORIO_4_2025_1_BIBLIOTECAREGISTROS_HPP