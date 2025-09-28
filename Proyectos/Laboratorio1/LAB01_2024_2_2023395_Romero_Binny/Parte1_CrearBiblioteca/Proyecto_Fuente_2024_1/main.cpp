#include "src/Sobrecarga.hpp"
#include <cstring>
int main() {
    ifstream input;
    ofstream output;
    //
    AperturaDeUnArchivoDeTextosParaLeer(input, "Data/PlatosOfrecidos.csv");
    struct Plato platos[120]{};
    int numPlatos = 0;
    while(true){
        if (input.eof()) {
            strcpy(platos[numPlatos].codigo, "FIN");
            break;
        };
        input>>platos[numPlatos];
        numPlatos++;
    }
    cout<<"Lectura exitosa"<<endl;

    AperturaDeUnArchivoDeTextosParaEscribir(output, "Reportes/reporte_platos.txt");
    for (int i=0;i<platos[i].totalDePedidos;i++) {
        output<<platos[i];
    }
    cout<<"Impresion exitosa"<<endl;


    //
    // AperturaDeUnArchivoDeTextosParaLeer(input, "Data/RepartidoresContratados.csv");
    // AperturaDeUnArchivoDeTextosParaLeer(input, "Data/OrdenesDeCompra.txt");

    return 0;
}