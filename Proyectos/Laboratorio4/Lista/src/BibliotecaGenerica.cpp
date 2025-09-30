//
// Created by binny on 29/09/2025.
//

#include "BibliotecaGenerica.hpp"

void apertura_escritura(ofstream &output, const char* name) {
    output.open(name, ios::out);
    if (not output.is_open()) {
        cout<<"El reporte no se abrio: "<<name<<endl;
    }else
        cout<<"El reporte se abrio correctamente: "<<name<<endl;
}

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (!input.is_open()) {
        cout << "Error opening file! : " <<name<<" " <<endl;
    }else {
        cout << "El archivo "<<name<<" se abrio correctamente"<<endl;
    }
}

void crear_lista_empleados(const char *name, void *&lista, void* (*leer)(ifstream &),
                            int(*comparar)(const void *, const void *)) {

    ifstream input;
    apertura_lectura(input, name);
    void* registro;

    //INCIALIZANDO LISTA - SIEMPRE IMPORTANTE
    lista = nullptr;
    while (true) {
        registro = leer(input);
        if (input.eof()) break;
        insertar(lista, registro, comparar); //insertar en orden
    }
}

//INSERTAR ORDENADO
void insertar(void *&lista, void *registro, int(*comparar)(const void *, const void *)) {
    //CREAMOS EL NUEVO NODO
    void** nuevo_nodo = new void*[2]{};
    nuevo_nodo[ELEMENTO] = registro;
    nuevo_nodo[SIGUIENTE] = nullptr;
    //

    void **recorrido = (void **) lista; //void** porque luego necesitamos acceder a ELEMENTO
    void **anterior = nullptr; //porque luego necesitamos igualarlo con recorrido que tambien es void**
    while (recorrido) {
        if (comparar(nuevo_nodo[ELEMENTO], recorrido[ELEMENTO])) break;
        anterior = recorrido;
        recorrido = (void **) recorrido[SIGUIENTE];
    }

    nuevo_nodo[SIGUIENTE] = recorrido;
    if (anterior != nullptr)anterior[SIGUIENTE] = nuevo_nodo;
    else lista = nuevo_nodo; //por si el nuevo_nodo se debe insertar al inicio

}

void imprimir(void *lista, void(*imprimir)(void *, ofstream &)) {
    ofstream output;
    apertura_escritura(output, "Reporte/Reporte_empleados.txt");
    void** recorrido = (void**)lista;
    while (recorrido) {
        imprimir(recorrido[ELEMENTO], output);
        recorrido = (void**) recorrido[SIGUIENTE];
    }
    cout << endl;
}


