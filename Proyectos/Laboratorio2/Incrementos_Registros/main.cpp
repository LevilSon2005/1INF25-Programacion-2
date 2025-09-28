#include "src/Funciones.hpp"

int main() {
    //@jperez,Juan Perez,juan.perez@pucp.edu.pe,FCI,2020-12-12,22
    //usuario , nombre ,  correo , facultad , fecha ,  edad
    //char*   ,  char*  , char*  , char*  , int  , int
    // ----------char**----------------, ----int*--------

    char*** arr_registros_usuarios;
    int** arr_registros_fechas;
    cargar_usuarios(arr_registros_usuarios,arr_registros_fechas, "Data/usuarios.csv");
    imprimir_usuarios(arr_registros_usuarios, arr_registros_fechas, "Reportes/Reporte_usuarios.txt");

    //1,2024-02-02,@psalazar,[@jperez] Realizando un estudio sobre redes neuronales.
    // indice , fecha , usuario , <menciones> texto
    //  int ,  int    , char*   , < char* >   char*
    //                          ---char**---
    //-----int*-------, ---------          --char**---------

    int** arr_registros_fechasId;
    char*** arr_registros_publicaciones;
    char*** arr_registros_menciones;
    cargar_publicaciones(arr_registros_fechasId, arr_registros_publicaciones,
                        arr_registros_menciones, "Data/publicaciones.csv");

    return 0;
}