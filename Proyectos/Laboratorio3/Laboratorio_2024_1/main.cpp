#include "src/Funciones_Genericas.hpp"

int main() {
    void* clientes, *reserva;
    carga_clientes(clientes);
    muestra_clientes(clientes);
    crear_reserva(reserva);
    muestre_reserva(reserva);
    if (clientes == nullptr) cout<<"Debo volver a TP"<<endl;
    carga_reserva(clientes, reserva);
    // reporte_final(reserva);

    return 0;
}