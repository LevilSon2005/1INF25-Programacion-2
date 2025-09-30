//
// Created by binny on 29/09/2025.
//

#include "ListaEmpleados.hpp"


int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    input.get();
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get();
    return dato;
}

char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get();
    return dato;
}

char* leer_cadena(ifstream &input, char del) {
    char* cadena, buffer[80]{};
    input.getline(buffer, 80, del);
    cadena = new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}

// CODIGO, NOMBRE, SUELDO
//378708,SAENZ ARANDA WILMER,23455.6
void* leer_empleado (ifstream &input) {
    void** registro;
    int codigo, *ptr_codigo;
    char* nombre;
    double sueldo, *ptr_sueldo;

    //lectura
    codigo = leer_int(input);
    if (input.eof()) return nullptr;
    nombre = leer_cadena(input, ',');
    sueldo = leer_double(input);

    //asignar punteros a los datos leidos
    ptr_codigo =  new int{};
    ptr_sueldo = new double{};
    *ptr_codigo = codigo;
    *ptr_sueldo = sueldo;

    registro = new void*[3]{};
    registro[CODIGO] = ptr_codigo;
    registro[NOMBRE] = nombre;
    registro[SUELDO] = ptr_sueldo;

    return registro;
}

int comparar_empleados_nombres(const void *empleado_1, const void *empleado_2) {
    void** registro_1 = (void**)empleado_1;
    void** registro_2 = (void**)empleado_2;

    char* nombre_1 = (char*)registro_1[NOMBRE];
    char* nombre_2 = (char*)registro_2[NOMBRE];

    return strcmp(nombre_1, nombre_2);
}

void imprimir_empleado(void * empleado, ofstream &output) {

    void** registro = (void**) empleado;
    char* nombre = (char*) registro[NOMBRE];
    int* ptr_codigo = (int*) registro[CODIGO];
    double* ptr_sueldo = (double*) registro[SUELDO];


    output << right << setw(30) << *ptr_codigo
        << setw(30) << *ptr_sueldo
        << setw(60) << nombre << endl;

}
