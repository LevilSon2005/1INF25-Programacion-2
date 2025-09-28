//
// Created by binny on 01/09/2025.
//

#ifndef PROYECTO_FUENTE_2024_1_SOBRECARGA_HPP
#define PROYECTO_FUENTE_2024_1_SOBRECARGA_HPP
#include "Estructuras.h"
#include "AperturaDeArchivos.hpp"


int leer_int(ifstream &input);
void leer_cadena(ifstream &input, char *cadena);
double leer_double(ifstream &input);
char leer_char(ifstream &input) ;
void operator>>(ifstream &input, struct Plato &plato);
void operator>>(ifstream &input, struct Pedido &pedido);
void operator >>(ifstream &input, struct Repartidor &repartidor);
bool operator<=(struct Pedido &pedido, struct Plato* arregloPlatos);
void operator<=(struct Repartidor* arregloRepartidores, const struct Pedido &pedido) ;
void agregar_orden_no_repetida(const struct Pedido &pedido, struct OrdenDeCompra &compra);
void agregar_orden_repetida(const struct Pedido &pedido, struct OrdenDeCompra &compra);
int busquedaPlatoSolicitado(const char* codigo, int cant_platos, const struct PlatoSolicitado* platos) ;
double calcular_monto_por_distancia(double distancia);
void operator! (struct OrdenDeCompra &compra);
void operator!(struct Repartidor &repartidor);
void operator<<(ofstream &output, const struct Repartidor &repartidor);
void operator<<(ofstream &output, const struct Plato &plato);
void imprimir_orden(ofstream &output, const struct OrdenDeCompra &compra, int tam);
void  imprimir_plato(ofstream &output,const struct PlatoSolicitado &plato, int tam);

#endif //PROYECTO_FUENTE_2024_1_SOBRECARGA_HPP