//
// Created by binny on 26/08/2025.
//

#ifndef SOBRECARGA_LECTURA_ESCRITURA_SOBRECARGA_HPP
#define SOBRECARGA_LECTURA_ESCRITURA_SOBRECARGA_HPP

#include "FuncionesAux.hpp"
#include "Reviews.hpp"
void operator>>(ifstream &input, struct Review& review);
void operator>>(const char* name, struct Reviews &reviews);


#endif //SOBRECARGA_LECTURA_ESCRITURA_SOBRECARGA_HPP