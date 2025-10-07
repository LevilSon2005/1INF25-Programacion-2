//
// Created by binny on 01/10/2025.
//

#include "BibliotecaGenerica.hpp"

//TAMBIEN FUNCIONA ESTA FUNCION generaLista
/*void generaLista(void* &lista) {

    void** casteo_lista = new void*[2]{};

    casteo_lista[INICIO1] = new void*[2]{};
    casteo_lista[INICIO2] = new void*[2]{};

    void* nodo_inicio1 = casteo_lista[INICIO1];
    void* nodo_inicio2 = casteo_lista[INICIO2];

    void** casteo_nodo_inicio1 = (void**)nodo_inicio1;
    void** casteo_nodo_inicio2 = (void**)nodo_inicio2;

    casteo_nodo_inicio1[DATO] = nullptr;
    casteo_nodo_inicio1[SIGUIENTE] = casteo_nodo_inicio2;

    casteo_nodo_inicio2[DATO] = nullptr;
    casteo_nodo_inicio2[SIGUIENTE] = nullptr;

    lista = casteo_lista;
}*/


void generaLista(void* &lista) {
    // Creamos el arreglo de dos punteros (INICIO1, INICIO2)
    void** arr_lista = new void*[2]{};

    // Creamos los nodos para cada inicio
    arr_lista[INICIO1] = new void*[2]{};
    arr_lista[INICIO2] = new void*[2]{};

    // Casteamos cada nodo
    void** casteo_nodo_inicio1 = (void**)arr_lista[INICIO1];
    void** casteo_nodo_inicio2 = (void**)arr_lista[INICIO2];

    // Enlazamos
    casteo_nodo_inicio1[DATO] = nullptr;
    casteo_nodo_inicio1[SIGUIENTE] = casteo_nodo_inicio2;

    casteo_nodo_inicio2[DATO] = nullptr;
    casteo_nodo_inicio2[SIGUIENTE] = nullptr;

    // Asignamos la lista al parámetro de salida
    lista = arr_lista;
}


bool esNodoVacio(void* nodo) {
    void** casteo_nodo = (void**)nodo;
    return (casteo_nodo[DATO] == nullptr);
}

void insertar(void* &lista, void* dato, int bloque) {

    //tenemos solo el dato, Necesitamos CREAR TODO EL NODO donde esta el dato
    void** casteo_lista = (void**)lista;
    void* nodo_inicio1 = casteo_lista[INICIO1];
    void* nodo_inicio2 = casteo_lista[INICIO2];
    void** casteo_nodo_inicio1 = (void**)nodo_inicio1;
    void** casteo_nodo_inicio2 = (void**)nodo_inicio2;

    if (bloque==1) {
        if (esNodoVacio(nodo_inicio1)) //si inicio1 vacio
            casteo_nodo_inicio1[DATO] = dato;
        else {
            //CREAMOS EL NUEVO_NODO DONDE ESTA EL DATO
            void** nuevo_nodo = new void*[2]{};
            nuevo_nodo[DATO] = dato;
            nuevo_nodo[SIGUIENTE] = nullptr; //esto solo es momentaneo, solo es por costumbre
            //
            void** recorrido = (void**)nodo_inicio1;
            while (recorrido[SIGUIENTE]!= nodo_inicio2) {
                recorrido = (void**)recorrido[SIGUIENTE];
            }
            recorrido[SIGUIENTE] = nuevo_nodo;
            nuevo_nodo[SIGUIENTE] = nodo_inicio2;
        }
    }
    else{ //(bloque==2)
        if (esNodoVacio(nodo_inicio2)) //si inicio2 vacio
            casteo_nodo_inicio2[DATO] = dato;
        else {
            //CREAMOS EL NUEVO_NODO DONDE ESTA EL DATO
            void** nuevo_nodo = new void*[2]{};
            nuevo_nodo[DATO] = dato;
            nuevo_nodo[SIGUIENTE] = nullptr; //esto solo es momentaneo, solo es por costumbre
            //
            void** recorrido = (void**)nodo_inicio2;
            while (recorrido[SIGUIENTE]!= nullptr) {
                recorrido = (void**)recorrido[SIGUIENTE];
            }
            recorrido[SIGUIENTE] = nuevo_nodo;
        }
    }
}

void crearLista(void *&lista, void *(*leer)(ifstream &), int(*clasificar)(void *dato), const char *name) {

    generaLista(lista);
    if (lista == nullptr) cout<<"No se resevó memoria"<<endl;
    //apertura archivo
    ifstream input(name, ios::in);
    if (not input.is_open()) cout<<"Error opening file: "<<name<<endl;
    else cout<<"Archivo abierto: "<<name<<endl;

    void* dato;
    while (true) {
        dato = leer(input);
        if (input.eof()) break;
        int bloque = clasificar(dato);
        insertar(lista, dato, bloque);
    }
}

void imprimeLista(void *&lista, void(*imprimir)(ofstream &output, void *), const char *name) {
    void** casteo = (void**)lista;
    void** recorrido = (void**)casteo[INICIO1];

    ofstream output(name, ios::out);
    if ( not output.is_open()) cout<<"Error opening report: "<<name<<endl;
    else cout<<"Reporte abierto: "<<name<<endl;

    while (recorrido) {
        imprimir(output, recorrido[DATO]);
        recorrido = (void**)recorrido[SIGUIENTE];
    }
}


