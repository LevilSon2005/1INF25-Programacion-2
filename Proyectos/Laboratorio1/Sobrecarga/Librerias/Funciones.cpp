//
// Created by binny on 19/08/2025.
//

#include "Funciones.hpp"

char*  leer_cadena(ifstream &input, char del) {
    char* cadena, buffer[200];
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

struct Vector2D operator+(struct Vector2D a, struct Vector2D b) {
    struct Vector2D aux;
    aux.x = a.x +b.x;
    aux.y = a.y + b.y;
    return aux;
}

void llenarVector(struct Vector2D &V) {
    int rango = 100;
    V.x = 1 + rand() % rango;
    V.y = 1 + rand() % rango;

    cout<<V.x<<" "<<V.y<<endl;
}


