//
// Created by binny on 26/08/2025.
//

#ifndef SOBRECARGA_LECTURA_ESCRITURA_FUNCIONESAUX_HPP
#define SOBRECARGA_LECTURA_ESCRITURA_FUNCIONESAUX_HPP

#include "Utils.hpp"
#include "Reviews.hpp"

void open_read(ifstream &input, const char* name) ;
void open_write(ofstream &ouput, const char* name) ;
int read_fecha(ifstream &input);
char* read_string(ifstream &input, char del);
#endif //SOBRECARGA_LECTURA_ESCRITURA_FUNCIONESAUX_HPP