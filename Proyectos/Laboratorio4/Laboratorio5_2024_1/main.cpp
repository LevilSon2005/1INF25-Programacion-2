#include "src/BibliotecaGenerica.hpp"
#include "src/FuncionEnteros.hpp"
#include "src/BibliotecaRegistro.hpp"

int main() {
    void* lista1, *lista2, *listaFinal;
    creaLista(lista1, leenum, clonarnum,"Data/RegistroNum1.txt");
    imprimeLista(lista1, imprimenum, "Reporte/ReporteNum1.txt");

    creaLista(lista2, leereg, clonarreg,"Data/Pedidos31.csv");
    imprimeLista(lista1, imprimereg, "Reporte/ReporteRegistro1.txt");
    return 0;
}