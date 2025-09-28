//
// Created by binny on 04/09/2025.
//

#ifndef FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP
#define FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP

#include <cstring>
#include "AperturaDeArchivos.hpp"
#include "Estructuras.h"

int leer_int(ifstream &input);
double leer_double(ifstream &input);
char leer_char(ifstream &input);
void leer_cadena(ifstream &input, char del, char* cadena);
void operator>>(ifstream &input, struct Plato& plato);
void operator>>(ifstream &input, struct Repartidor& repartidor);
void operator>>(ifstream &input, struct Pedido& pedido);
bool operator<=(struct Pedido& pedido, struct Plato* arregloPlatos);
void operator<=(struct Repartidor* arregloRepartidores, struct Pedido& pedido);
void agregar_cliente_repetido(const struct Pedido &pedido,struct OrdenDeCompra &orden);
void agregar_cliente_nuevo(const struct Pedido &pedido,struct OrdenDeCompra &orden);


#endif //FUENTES_BIBLIOTECA_2024_2_SOBRECARGAS_HPP