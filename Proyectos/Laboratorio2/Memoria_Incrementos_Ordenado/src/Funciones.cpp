//
// Created by binny on 09/09/2025.
//

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if ( not input.is_open() ) {
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else {
        cout<<"El archivo - "<<name<<" se abrio"<<endl;
    }
}
void apertura_escritura(ofstream &ouput, const char* name) {
    ouput.open(name, ios::out);
    if ( not ouput.is_open() ) {
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else {
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
    }
}

int leer_int(ifstream &input) {
    int aux;
    input>>aux;
    return aux;
}

void leer_datos(const char* name, int *&codigos) {
    //el arreglo= nullptr -- n_datos y capacidad = 0
    int n_codigos=0;
    int capacidad=0;
    codigos = nullptr;
    //

    int codigo;
    ifstream input;
    apertura_lectura(input, name);

    while (true) {
        input>>codigo;
        if (input.eof()) break;
        if (n_codigos==capacidad) incrementar_memoria(codigos, capacidad, n_codigos);
        insertar_ordenado(codigo, codigos, n_codigos);
        n_codigos++;
    }

}

//cuando ya esta lleno o la primera vez
void incrementar_memoria(int* &codigos, int &capacidad, int n_codigos) {
    capacidad += INCREMENTO;

    //si es la primera vez -  arreglo vacio - puntero a nullptr
    if (codigos==nullptr) codigos = new int[capacidad]{};
    else {//cuando ya hay datos, pero se lleno la memoria que habia
        int* aux = new int[capacidad]{};
        for (int i=0;i<n_codigos;i++) {
            aux[i] = codigos[i];
        }
        delete codigos;
        codigos=aux;
    }
}

void insertar_ordenado(int dato, int* arr_datos, int n_datos) {
    //para hallar el indice donde debe detenerse(indice-1), y donde luego se va a reemplazar
    int i = n_datos - 1;
    for (i=n_datos-1;i>=0;i--){
        if (arr_datos[i]<dato) break;
        arr_datos[i+1] = arr_datos[i];
    }
    arr_datos[i+1] = dato;
}