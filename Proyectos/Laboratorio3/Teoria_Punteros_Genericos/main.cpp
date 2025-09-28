#include "src/Funciones.hpp"

int main() {
    //Alumnos.csv
    // codigo  ,  nombre  ,  cursos ,  notas
    void* alumnos;
    cargarAlumnos(alumnos, "Data/Alumnos_PunterosGenericos.csv");
    probarCarga(alumnos, "Reportes/Prueba_Alumnos.txt");
    cargas_cursos(alumnos, "Data/CursosNotas.csv");

    /*
     * REGLAS PRACTICAS:
     *-> GENERAL:
     *Si necesitas recorrer usa void**
     * Todos los void** al final terminan en un void* porque ese es genérico
     *
     * -> PARA LECTURA:
     * No se castea, porque puedes crear otra variable y llenarlo ahi, porque
     * la variable original no tiene nada
     * Siempre leemos con REGISTRO, luego ya lo asignamos al arreglo
     *
     * ->PARA RECUPERAR DATOS:
     * Se castea, porque la variable si tiene data acumulado. Necesitas esa info,
     * entonces creas un variable que apunte a la data que ya tenias antes
     */
    return 0;
}