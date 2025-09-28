//
// Created by binny on 04/09/2025.
//

#ifndef UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP
#define UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP

#include "Sobrecargas.hpp"
#include "AperturaDeArchivos.hpp"
#include <fstream>
#include <iomanip>
#define NO_ENCONTRADO (-1)

void leerLibros(struct Libro* arregloLibros , int &cantLibros, const char* name);
void leerClientes(struct Cliente* arregloClientes,int &cantClientes, const char* name);
void leerPedidos(struct Libro* arregloLibros , int cantLibros,
               struct Cliente* arregloClientes,int cantClientes,
               const char* name);
void asignarPedido(int numPedido, int dni, char* codigo,
                struct Libro* arregloLibros , int cantLibros,
                struct Cliente* arregloClientes,int cantClientes);
int busquedaDNI(int dni, struct Cliente* arregloClientes,int cantClientes);
void asignar_pagos(struct Cliente* arregloClientes,int cantClientes);
void imprimir_reporte(struct Libro* arregloLibros , int cantLibros,
               struct Cliente* arregloClientes,int cantClientes,
               const char* name);
void imprimir_linC(ofstream &output, char c);
void imprimir_titulo(ofstream &output,const char* titulo );
void imprimir_reporte_libros(ofstream& output, struct Libro* arregloLibros , int cantLibros);
void imprimir_reporte_clientes(ofstream& output, struct Cliente* arregloClientes,int cantClientes);

#endif //UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP