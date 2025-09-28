
#include "src/Funciones.hpp"

int main() {

    struct Libro arregloLibros[270]{};
    struct Cliente arregloClientes[60]{};
    int cantLibros=0, cantClientes=0;
    leerLibros(arregloLibros, cantLibros, "Data/Libros.csv");
    leerClientes(arregloClientes,cantClientes, "Data/Cientes.csv" );
    leerPedidos(arregloLibros, cantLibros,
               arregloClientes,cantClientes,
               "Data/Pedidos.txt");
    imprimir_reporte(arregloLibros, cantLibros,
                    arregloClientes,cantClientes,
                    "Reportes/Reporte.txt");
    return 0;
}