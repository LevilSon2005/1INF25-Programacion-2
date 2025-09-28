//
// Created by binny on 04/09/2025.
//

#include "Funciones.hpp"

void imprimir_titulo(ofstream &output,const char* titulo ) {
    output<<setw((TAMREPORTE+strlen(titulo))/2)<<titulo<<endl;
}

void imprimir_linC(ofstream &output, char c) {
    output<<setfill(c)<<setw(TAMREPORTE)<<""<<setfill(' ')<<endl;
}

void leerLibros(struct Libro* arregloLibros , int &cantLibros, const char* name) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, name);

    while (true) {
        if (!(input>>arregloLibros[cantLibros])){
            strcpy(arregloLibros[cantLibros].codigo, "FIN");
            break;
        }
        cantLibros++;
    }
}

void leerClientes(struct Cliente* arregloClientes,int &cantClientes, const char* name) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, name);

    while (true) {
        if (!(input>>arregloClientes[cantClientes]))break;
        cantClientes++;
    }
    // for (int i=0;i<cantClientes;i++) cout<<arregloClientes[i].dni<<endl;
}

//libroPedido >> arregloLibros - si es que se puede atender pedido
//cliente << libroPedido - agregar un pedido a un cliente
//++cliente - pagos del cliente

int busquedaDNI(int dni, struct Cliente* arregloClientes,int cantClientes) {
    for (int i=0; i<cantClientes; i++) {
        if (dni == arregloClientes[i].dni) return i;
    }
    return NO_ENCONTRADO;
}

void asignarPedido(int numPedido, int dni, char* codigo,
                struct Libro* arregloLibros , int cantLibros,
                struct Cliente* arregloClientes,int cantClientes) {
    struct LibroSolicitado libroPedido{};
    libroPedido.numeroDePedido = numPedido;
    strcpy(libroPedido.codigoDelLibro, codigo);
    if (libroPedido>>arregloLibros) {
        int posCliente = busquedaDNI(dni, arregloClientes, cantClientes);
        if (posCliente != NO_ENCONTRADO) {
            arregloClientes[posCliente]<<libroPedido;
        }
    }
}

/* ESTA SECCION ES SOLO PARA GUIARME, NO SE USA EN ESTE PROYECTO

//si se puede atender un pedido
bool operator>>(struct LibroSolicitado &libroPedido, struct Libro* arregloLibros){
    for (int i=0;strcmp(arregloLibros[i].codigo, "FIN") != 0;i++) {//recorrer todos los libros
        if (strcmp(arregloLibros[i].codigo, libroPedido.codigoDelLibro)==0){//encuentro los datos de ESE libroPedido
            if (arregloLibros[i].stock>0) {//si el pedido puede ser atendido - todavia quedan ejemplares
                arregloLibros[i].stock--;
                // strcpy(libroPedido.codigoDelLibro, arregloLibros[i].codigo);
                libroPedido.precio = arregloLibros[i].precio;
                libroPedido.atendido = true;
                return true;
            }else {//si ya no hay ejemplares - no puede ser atendido - stock<0
                libroPedido.atendido = false;
                return false;
            }
        }
    }
    return false;
}

//Agregar pedido a un cliente
bool operator<<(struct Cliente& cliente,const struct LibroSolicitado &libroPedido) {
    if (libroPedido.atendido) {//stock positivo
        int &n_libroPedido = cliente.cantDeLibros;
        cliente.librosSolicitados[n_libroPedido]=libroPedido;//asignar directamente la estructura
        n_libroPedido++;
        return true;
    }else {
        return false;
    }
}

void operator++(struct Cliente& cliente) {
    for (int i=0;i<cliente.cantDeLibros;i++) {
        cliente.pagoTotal += cliente.librosSolicitados[i].precio;
    }
}

 */

void asignar_pagos(struct Cliente* arregloClientes,int cantClientes) {
    for (int i=0; i<cantClientes; i++) {
        ++arregloClientes[i];
    }
}

// NumPedido   -  dni -  {librosPedidos}
void leerPedidos(struct Libro* arregloLibros , int cantLibros,
               struct Cliente* arregloClientes,int cantClientes,
               const char* name) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, name);
    int numPedido, dni;
    char codigo[50];
    while (true) {
        numPedido = leer_int(input);
        if (input.eof()) break;
        dni = leer_int(input);
        while (true) {
            if (input.get() == '\n') break;
            input>>ws>>codigo;
            asignarPedido(numPedido, dni, codigo,
                        arregloLibros, cantLibros,
                        arregloClientes,cantClientes);
        }
    }
    asignar_pagos(arregloClientes, cantClientes);
}


void imprimir_reporte_libros(ofstream& output, struct Libro* arregloLibros , int cantLibros){
    int tam=TAMREPORTE/COLUMNAS;
    imprimir_titulo(output, "REPORTE DE PRUEBA DE LIBROS");
    imprimir_linC(output, '-');
    // codigo   titulo   autor   stock  precio
    output<<left<<setw(tam)<<"CODIGO"
    <<left<<setw(2*tam)<<"TITULO"
    <<left<<setw(3*tam)<<"AUTOR"
    <<left<<setw(tam)<<"STOCK"
    <<left<<setw(tam)<<"PRECIO"<<endl;
    imprimir_linC(output, '-');
    for ( int i=0;i<cantLibros;i++) {
        output<<arregloLibros[i];
    }
}
void imprimir_reporte_clientes(ofstream& output, struct Cliente* arregloClientes,int cantClientes) {
    int tam=TAMREPORTE/COLUMNAS;
    imprimir_titulo(output, "REPORTE DE PRUEBA DE CLIENTES ");
    imprimir_linC(output, '-');
    output<<right<<setw(tam)<<"DNI"
    <<setw(3*tam)<<"NOMBRE"<<endl;
    imprimir_linC(output, '-');
    for (int i=0;i<cantClientes;i++) {
        output<<arregloClientes[i];
    }
}
void imprimir_reporte(struct Libro* arregloLibros , int cantLibros,
               struct Cliente* arregloClientes,int cantClientes,
               const char* name) {
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output, name);

    imprimir_reporte_libros(output, arregloLibros, cantLibros);
    imprimir_linC(output, '=');
    imprimir_reporte_clientes(output, arregloClientes, cantClientes);

}