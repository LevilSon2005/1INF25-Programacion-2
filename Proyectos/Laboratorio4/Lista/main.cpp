#include <iostream>
#include "src/BibliotecaGenerica.hpp"
#include "src/ListaEmpleados.hpp"

int main() {
    void* lista_empleados;
    crear_lista_empleados("Data/personal.csv", lista_empleados,
                        leer_empleado, comparar_empleados_nombres);
    imprimir(lista_empleados, imprimir_empleado);
    return 0;
}