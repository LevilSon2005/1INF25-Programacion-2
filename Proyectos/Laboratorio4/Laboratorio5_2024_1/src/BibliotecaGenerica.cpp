//
// Created by binny on 03/10/2025.
//

#include "BibliotecaGenerica.hpp"

void generaLista(void* &lista) {
    void** casteo_lista = (void**)lista;
    casteo_lista = new void*[2]{};
    casteo_lista[INICIO] = nullptr;
    casteo_lista[FIN] = nullptr;
    casteo_lista[CANT_NODO] = new int*[1]{};
    *(int*)casteo_lista[CANT_NODO] = 0;

    lista = casteo_lista;
}

bool esListVacia(void* lista) {
    void** casteo_lista = (void**)lista;
    return (casteo_lista[INICIO]==nullptr and casteo_lista[FIN]==nullptr);
}

//insertar al final
void insertar(void* &lista, void* dato, void*(*clonar)(void*)) {
    //CLONAMOS EL REGISTRO / DATO;
    void* nuevo_dato = clonar(dato);
    //CREAMOS NUEVO NODO
    void** nuevo_nodo = new void*[2]{};
    nuevo_nodo[DATO] = nuevo_dato;
    nuevo_nodo[SIGUIENTE] = nullptr;
    //
    void** casteo_lista = (void**)lista;
    if (esListVacia(lista)) {
        casteo_lista[INICIO] = nuevo_nodo;
        casteo_lista[FIN] = nuevo_nodo;
    }else {
        void** ultimo_nodo = (void**)casteo_lista[FIN];
        ultimo_nodo[SIGUIENTE] = nuevo_nodo;
        casteo_lista[FIN] = nuevo_nodo;
    }
}


void imprimeLista(void *lista, void(*imprimir)(ofstream &, void *lista), const char *name) {
    void** casteo_lista = (void**)lista;
    void** recorrido = (void**)casteo_lista[INICIO];

    ofstream output(name, ios::out);
    if (not output.is_open()) cout << "Error opening file: " <<name<< endl;
    else cout<<"Archivo abierto: "<<name<<endl;

    while (recorrido) {
        imprimir(output, recorrido[DATO]);
        recorrido = (void**)recorrido[SIGUIENTE];
    }
}

void creaLista(void *&lista, void *(*leer)(ifstream &input),
               void*(*clonar)(void*), const char *name) {
    generaLista(lista);
    // if (esListVacia(lista)) cout<<"Falta inicializar"<<endl;
    void* dato;

    //lectura
    ifstream input(name, ios::in);
    if (not input.is_open()) cout << "Error opening file: " <<name<< endl;
    else cout<<"Archivo abierto: "<<name<<endl;
    //

    while (true) {
        dato = leer(input);
        void**casteo = (void**)dato;

        if (input.eof()) break;
        cout<<*(int*)casteo[0]<<endl;
        insertar(lista, dato, clonar);
    }
}
