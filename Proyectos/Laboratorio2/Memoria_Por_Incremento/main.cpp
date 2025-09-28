#include "src/MemoriaIncrementos.hpp"

int main() {
    int* codigos;
    int n_codigos=0;//siempre incializa
    leer_datos("Data/Codigos.txt", codigos, n_codigos);

    //para comprobar - IMPRESION
    ofstream output;
    apertura_escritura(output, "Reporte/Reporte_codigos.txt");
    for (int i=0;i<n_codigos;i++) {
        output<<codigos[i]<<endl;
    }
    return 0;
}