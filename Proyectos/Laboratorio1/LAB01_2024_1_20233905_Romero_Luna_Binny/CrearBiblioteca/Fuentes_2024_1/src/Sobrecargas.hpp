//
// Created by binny on 02/09/2025.
//

#ifndef FUENTES_2024_1_SOBRECARGAS_HPP
#define FUENTES_2024_1_SOBRECARGAS_HPP

#include "AperturaDeArchivos.hpp"
#include "Estructuras.h"
#include <cstring>
#include <iomanip>

using namespace std;

#define COLUMNAS 7
#define TAMREPORTE 160
int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
bool operator>>(ifstream &input, struct Libro &libro);
bool operator>>(struct LibroSolicitado &libroPedido, struct Libro* arregloLibros);
bool operator>>(ifstream &input, struct Cliente &cliente);
bool operator<<(struct Cliente& cliente,const struct LibroSolicitado &libroPedido);
void operator++(struct Cliente& cliente);
void operator<<(ofstream &output, const struct Libro& libro);
void imprimir_encabecazado_libros_pedidos(ofstream &output, int tam);
void imprimir_libros_no_entregados(ofstream &output, const struct Cliente& cliente,int tam);
void operator<<(ofstream &output,const struct Cliente& cliente );
#endif //FUENTES_2024_1_SOBRECARGAS_HPP