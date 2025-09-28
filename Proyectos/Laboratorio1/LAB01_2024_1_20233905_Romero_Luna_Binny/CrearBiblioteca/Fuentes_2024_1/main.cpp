#include "src/Sobrecargas.hpp"

int main() {

    //PARA LIBRO - Lectura e Impresion:
    //input >> libro;
    struct Libro arregloLibros[10]{};
    ifstream inputLibro;
    ofstream outputLibro;
    AperturaDeUnArchivoDeTextosParaLeer(inputLibro, "Data/Libros.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(outputLibro, "Reportes/reporteLibro.txt");
    int cantLibro=0;//contador
    while(true) {
        if (!(inputLibro>>arregloLibros[cantLibro])) {
            strcpy(arregloLibros[cantLibro].codigo, "FIN");
            break;
        }
        cantLibro++;
    }
    // for (int i=0;i<=cantLibro;i++) cout<<arregloLibros[i].codigo<<endl;
    //Sobrecarga para impresion de libro - output<<libro;
    for (int i=0;i<cantLibro;i++) outputLibro<<arregloLibros[i];


    //PARA CLIENTE - Lectura
    ifstream inputCliente;
    ofstream outputCliente;
    AperturaDeUnArchivoDeTextosParaLeer(inputCliente, "Data/Cientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(outputCliente, "Reportes/reporteCliente.txt");
    int cantCliente=0;
    struct Cliente arregloClientes[14]{};
    while(true) {
        if (!(inputCliente>>arregloClientes[cantCliente])) break;
        cantCliente++;
    }

    //PARA PEDIDOS - determinar si se puede atender un pedido
    struct LibroSolicitado libroPedido{};
    strcpy(libroPedido.codigoDelLibro, "IIM5175");
    for (int i=0;i<=2;i++) {//2 es el stock inicial de ese libro - el for es para probar ambos casos
        //cuando el stock llega a cero, el campo "atendido" del struct se vuelve falso
        libroPedido>>arregloLibros;
        if (libroPedido.atendido) cout<<"Todavia queda stock"<<endl;
        else cout <<"El stock ya se acabo"<<endl;
    }

    cout<<"------------------"<<endl;
    //PARA agregar un pedido a un cliente
    struct Cliente cliente = {
        54393647,
        "Reyes Tang Edward",
        {},
        0,
        0.0
    };
    struct LibroSolicitado librosSolicitados[3]{};
    strcpy(librosSolicitados[0].codigoDelLibro, "ETZ8565");
    librosSolicitados[0].numeroDePedido = 00001;
    librosSolicitados[0]>>arregloLibros;

    strcpy(librosSolicitados[1].codigoDelLibro, "YDK7687");
    librosSolicitados[1].numeroDePedido = 00002;
    librosSolicitados[1]>>arregloLibros;

    strcpy(librosSolicitados[2].codigoDelLibro, "ZOY6470");
    librosSolicitados[2].numeroDePedido = 00003;
    librosSolicitados[2]>>arregloLibros;

    if(cliente<<librosSolicitados[0] )cout<<"Se asigno el pedido al cliente"<<endl;
    else cout<<"No se agrego"<<endl;
    cliente<<librosSolicitados[1];
    cliente<<librosSolicitados[2];

    //PARA DETERMINAR CUANTO DEBE PAGAR EL CLIENTE
    ++cliente;

    //PARA CLIENTES  - Impresion
    outputCliente<<cliente;
    return 0;
}