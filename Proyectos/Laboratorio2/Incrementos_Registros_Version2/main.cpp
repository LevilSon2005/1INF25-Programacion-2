#include "src/Funciones.hpp"

int main() {
    int** arr_reg_fechas;
    char*** arr_reg_usuarios;
    cargar_usuarios(arr_reg_fechas,arr_reg_usuarios,"Data/usuarios.csv");
    int** arr_indices;
    char*** arr_publicaciones;
    char*** arr_menciones;
    cargar_publicaciones(arr_indices,arr_publicaciones,arr_menciones, "Data/publicaciones.csv");
    return 0;
}