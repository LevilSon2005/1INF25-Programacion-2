//
// Created by binny on 02/09/2025.
//

#include "Sobrecargas.hpp"

int leer_int(ifstream &input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input>>dato;
    input.get();
    return dato;
}

char leer_char(ifstream &input) {
    char dato;
    input>>dato;
    input.get();
    return dato;
}

void leer_cadena(ifstream &input, char del, char* cadena) {
    input.getline(cadena, 100, del);
}

bool operator>>(ifstream &input, struct Libro &libro) {
    char aux[10]{};
    leer_cadena(input, ',', aux);
    if (input.eof()) return false;
    strcpy(libro.codigo, aux);
    leer_cadena(input, ',', libro.tiltulo);
    leer_cadena(input, ',', libro.autor);
    libro.stock = leer_int(input);
    libro.precio = leer_double(input);
    return true;
}

bool operator>>(ifstream &input, struct Cliente &cliente) {
    int aux= leer_int(input);
    if (input.eof()) return false;
    cliente.dni = aux;
    leer_cadena(input, '\n', cliente.nombre);
    //inicializacion
    cliente.cantDeLibros =0;
    cliente.pagoTotal = 0.0;
    return true;
}

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

//imprimir un libro
void operator<<(ofstream &output, const struct Libro& libro) {
    int tam=TAMREPORTE/COLUMNAS;
    output<<fixed<<setprecision(2);

    output<<left<<setw(tam)<<libro.codigo
    <<left<<setw(2*tam)<<libro.tiltulo
    <<left<<setw(2*tam)<<libro.autor
    <<right<<setw(tam)<<libro.stock
    <<right<<setw(tam)<<libro.precio<<endl;

}

void imprimir_encabecazado_libros_pedidos(ofstream &output, int tam) {
    output<<setw(tam)<<"";
    output<<right<<setw(tam)<<"N° Pedido"
    <<setw(tam)<<"Codigo"
    <<setw(tam)<<"Precio"<<endl;
}

void imprimir_libros_no_entregados(ofstream &output, const struct Cliente& cliente,int tam) {
    output<<"Libros no entregados por falta de stock"<<endl;
    output<<left<<setw(tam)<<""
    <<setw(tam)<<"Pedido"
    <<setw(tam)<<"Codigo"<<endl;

    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (not cliente.librosSolicitados[i].atendido) {
            output<<left<<setw(tam)<<""
            <<setw(tam)<<cliente.librosSolicitados[i].numeroDePedido
            <<setw(tam)<<cliente.librosSolicitados[i].codigoDelLibro<<endl;
        }
    }
}

//imprime un cliente
void operator<<(ofstream &output,const struct Cliente& cliente ) {
    int tam=TAMREPORTE/COLUMNAS;
    output<<fixed<<setprecision(2);
    output<<right<<setw(tam)<<cliente.dni<<setw(tam)<<""
    <<left<<setw(2*tam)<<cliente.nombre<<endl;
    output<<"Libros entregados: "<<endl;
    imprimir_encabecazado_libros_pedidos(output, tam);
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido) {
            output<<setw(tam)<<"";
            output<<right<<setw(tam)<<cliente.librosSolicitados[i].numeroDePedido
            <<setw(tam)<<cliente.librosSolicitados[i].codigoDelLibro
            <<setw(tam)<<cliente.librosSolicitados[i].precio<<endl;
        }
    }
    output<<"Total a Pagar : "<<cliente.pagoTotal<<endl<<""<<endl;
    imprimir_libros_no_entregados(output, cliente, tam);

    output<<endl<<endl;
}