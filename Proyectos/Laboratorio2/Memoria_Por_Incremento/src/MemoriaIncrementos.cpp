//
// Created by binny on 09/09/2025.
//

#include "MemoriaIncrementos.hpp"

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

/*  Capacidad: es similar al "current"
 *  es como un aux que va aumentando y te ubica en relación con tu n_datos
 *
 */

// &codigos: porque se va a ir agregando memoria dinamica conforme va leyendo
// &n_codigos: porque actualmente está en cero y vamos sumando conforme leemos
void leer_datos(const char* name, int* &codigos, int& n_codigos){
    //inicializo y creo CAPACIDAD
    int capacidad=0;
    n_codigos=0;
    codigos=nullptr;
    //
    int codigo;
    ifstream input;
    apertura_lectura(input, name);

    while (true) {
        input>>codigo;
        if (input.eof()) break;
        //para darle memoria dinamica a ese puntero, utilizamos memoria por incremento
        if (n_codigos==capacidad) incrementar_memoria(codigos,n_codigos, capacidad);
        codigos[n_codigos] = codigo; /*lleno los datos al arreglo de codigo,
        luego cuando el arreglo se llene se van a copiar a aux
        y volveran aqui para ser el nuevo arreglo de codigos pero con mas espacios*/
        n_codigos++;
    }
}

void incrementar_memoria(int *&codigos,int n_codigos, int &capacidad) {
    int* aux;
    capacidad += INCREMENTO;

    //si es la primera vez
    if (codigos==nullptr) {
        codigos =  new int[capacidad]{};
    }else {//codigos ya tiene elementos
        aux = new int[capacidad]{};
        for (int i=0;i<n_codigos;i++) {
            aux[i] = codigos[i]; //copio los datos de codigos al arreglo aux
        }
        delete codigos; //borro a donde apunta el puntero codigos, es decir, borro la conexion a los datos
        codigos = aux; //codigos va a puntar a aux, ahora puede acceder a los datos
    }
}