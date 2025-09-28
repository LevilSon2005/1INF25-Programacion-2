#include "src/Funciones.hpp"
/*Nombre: Binny Benigna Romero
 * Codigo: 20233905
 */
int main() {
    //conductores  e   infracciones  -> asignacion exacta
    //faltas : incremento
    struct Conductores conductores{};
    struct Infracciones infracciones{};
    struct Faltas faltas{};

    conductores += "Data/Conductores.csv";
    // cargar_conductores(arr_conductores, "DataConductores.csv");
    infracciones += "Data/Infracciones.csv";
    cargar_faltas_de_los_conductores(faltas);
    return 0;
}