#include "src/Funciones.hpp"
int main() {
    int* codigos;
    leer_datos("Data/Codigos.txt", codigos);

    ofstream ouput;
    apertura_escritura(ouput, "Reporte_Ordenado/Reporte_Ordenado.txt");
    for(int i=0;i<7;i++) {
        ouput<<codigos[i]<<endl;
    }

    return 0;
}