#include "src/BibliotecaEnteros.hpp"
#include "src/BibliotecaGenerica.hpp"
#include "src/BibliotecaRegistros.hpp"

int main() {
    void* lista;

    crearLista(lista, leenum, clasificaentero, "Data/numeros2.txt");
    imprimeLista(lista, imprimenum, "Reporte/Repnum.txt");
    //
    crearLista(lista, leeregistro, clasificaregistro, "Data/RegistroDeFaltas1.csv");
    imprimeLista(lista, imprimeregistro, "Reporte/Repfalta.txt");
    return 0;
}