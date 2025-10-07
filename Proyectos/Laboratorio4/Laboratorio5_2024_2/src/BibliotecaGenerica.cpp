//
// Created by binny on 02/10/2025.
//

#include "BibliotecaGenerica.hpp"

void construir(void *&lista) {

    void** casteo_lista;
    casteo_lista =  new void*[3]{};

    /*casteo_lista[INICIO] = new void*[2]{}; //DUPLA Y SIGUIENTE
    casteo_lista[FIN] = new void*[2]{}; //DUPLA Y SIGUIENTE
    casteo_lista[CANT_NODOS] = new int*[1]{}; //PARA LA CANTIDA DE NODOS

    void** casteo_inicio = (void**)casteo_lista[INICIO];
    void** casteo_fin = (void**)casteo_lista[FIN];

    casteo_inicio[DUPLA]=nullptr;
    casteo_inicio[SIGUIENTE] = casteo_fin;
    casteo_fin[DUPLA] = nullptr;
    casteo_fin[SIGUIENTE] = nullptr;*/

    casteo_lista[INICIO] = nullptr;
    casteo_lista[FIN]= nullptr;
    casteo_lista[CANT_NODOS] = new int*[1]{};

    lista = casteo_lista;
}

bool esListaVacia(void *lista) {
    void** casteo_lista= (void**)lista;
    return (casteo_lista[INICIO] == nullptr & casteo_lista[FIN] == nullptr);
}


void creaLista(void *&lista, void *(*leer)(ifstream &), const char *name) {
    construir(lista);
    if (lista == nullptr) cout<<"Lista no inicializada"<<endl;

    //apertura
    ifstream input(name, ios::in);
    if (not input.is_open()) cout<<"El archivo no se abrio<<: "<<name<<endl;
    else cout<<"El archivo se abrio: "<<name<<endl;
    //

    void* dato;
    while(true) {
        dato = leer(input);
        if (input.eof()) break;
        // insertar(dato,lista);
    }
}
