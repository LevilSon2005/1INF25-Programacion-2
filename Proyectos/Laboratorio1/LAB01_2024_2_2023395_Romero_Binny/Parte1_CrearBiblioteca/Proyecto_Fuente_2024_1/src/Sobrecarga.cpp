//
// Created by binny on 01/09/2025.
//

#include "Sobrecarga.hpp"
#include <cstring>
#define NO_ENCONTRADO (-1)
#define TAMREPORTE (180)
#define COLUMNAS (7)

void leer_cadena(ifstream &input, char *cadena, int n, char del) {
    input.getline(cadena,n, del );
}

int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    input.get();
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get();
    return dato;
}

char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get();
    return dato;
}

//AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
void operator>>(ifstream &input, struct Plato &plato) {
    AperturaDeUnArchivoDeTextosParaLeer(input, "Data/PlatosOfrecidos.csv");
    char buffer[50]{};
    leer_cadena(input, plato.codigo,7,',');
    if (input.eof()) return;
    leer_cadena(input, plato.nombre,60,',');
    plato.precio = leer_double(input);
    leer_cadena(input,buffer,50,'\n');
    //inicializacion
    plato.totalDePedidos =0;
    plato.totalRecaudado =0.0;

}

//JNV387,Justino Norabuena Virginia Karina,Motocicleta
void operator >>(ifstream &input, struct Repartidor &repartidor) {
    // AperturaDeUnArchivoDeTextosParaLeer(input, "Data/RepartidoresContratados.csv");

    leer_cadena(input, repartidor.codigo,7,',');
    if (input.eof()) return;
    leer_cadena(input, repartidor.nombre,60, ',');
    leer_cadena(input, repartidor.tipoDeVehiculo,15,'\n');
    //inicializacion
    repartidor.cantidadDeOrdenes =0;
    repartidor.pagoPorEntregas =0.0;
}

// 15290194  BR-283    1    MCE193    11.69
void operator>>(ifstream& input, struct Pedido& pedido) {
    // AperturaDeUnArchivoDeTextosParaLeer(input, "Data/OrdenesDeCompra.txt");
    int aux;
    input>>aux;
    if (input.eof()) return;
    pedido.dniDelCliente = aux;
    input>>pedido.codigoDelPlato;
    input>>pedido.cantidad;
    input>>pedido.codigoDelRepartidor;
    input>>pedido.distanciaARecorrer;
    //inicializacion
    pedido.precio =0.0;
}

//determina el precio de un plato
bool operator<=(struct Pedido &pedido, struct Plato* arregloPlatos) {
    for (int i=0;strcmp(arregloPlatos[i].codigo, "FIN")!=0;i++) {
        if (arregloPlatos[i].precio >= 0) {
            pedido.precio = arregloPlatos[i].precio;
            arregloPlatos[i].totalDePedidos++;
            arregloPlatos[i].totalRecaudado += (pedido.cantidad*pedido.precio);
            return true;
        }
    }
    return false;
}

//solo asignar los campos - primera vez del cliente
void agregar_orden_no_repetida(const struct Pedido &pedido, struct OrdenDeCompra &compra) {
    compra.dniDelCliente = pedido.dniDelCliente;
    compra.distancia = pedido.distanciaARecorrer;
    int n_plato = compra.cantidadDePlatos;
    //
    struct PlatoSolicitado &plato = compra.platosSolicitados[n_plato];
    strcpy(plato.codigo,pedido.codigoDelPlato);
    plato.cantidad = pedido.cantidad;
    plato.precio = pedido.precio;
    //
    compra.cantidadDePlatos = 1;
    compra.montoPorCobrar = pedido.precio * pedido.cantidad;
}

int busquedaPlatoSolicitado(const char* codigo, int cant_platos, const struct PlatoSolicitado* platos) {
    for (int i=0;i<cant_platos;i++) {
        if (strcmp(codigo,platos[i].codigo) == 0) return i;
    }
    return NO_ENCONTRADO;
}

//verificar si el plato no se repite y si no se repite acumular estadisticas
void agregar_orden_repetida(const struct Pedido &pedido, struct OrdenDeCompra &compra) {
    int cant_platos = compra.cantidadDePlatos;

    int indicePlato =  busquedaPlatoSolicitado(pedido.codigoDelPlato,cant_platos,compra.platosSolicitados);
    struct PlatoSolicitado &plato = compra.platosSolicitados[indicePlato];
    if (indicePlato == NO_ENCONTRADO) {//plato no repetido
        strcpy(plato.codigo,pedido.codigoDelPlato);
        plato.cantidad = pedido.cantidad;
        plato.precio = pedido.precio;
    }else {
        plato.cantidad += pedido.cantidad;
        plato.precio += pedido.precio;
    }
    compra.cantidadDePlatos++;
    compra.montoPorCobrar += plato.precio*plato.cantidad;
}

//Asigan un pedido a un repartidor
void operator<=(struct Repartidor* arregloRepartidores, const struct Pedido &pedido) {
    for (int i=0;strcmp(arregloRepartidores[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arregloRepartidores[i].codigo, pedido.codigoDelRepartidor)==0) {//encuentro al repartidor
            struct Repartidor &repartidor = arregloRepartidores[i];
            int n_pedidoDeUnRepartidor = repartidor.cantidadDeOrdenes; //el numero de ordenes que tiene actualmente

            for (int k=0;k<n_pedidoDeUnRepartidor;k++) {
                struct OrdenDeCompra &compra = repartidor.ordenesDeCompra[n_pedidoDeUnRepartidor]; //una orden en especifico
                if (pedido.dniDelCliente == compra.dniDelCliente) {
                    agregar_orden_repetida(pedido, compra);//recuerda verificar si el plato se repite o no
                }else {//si es una orden nueva - cliente no repetido
                    agregar_orden_no_repetida(pedido, compra);
                }
            }

        }
    }
}

double calcular_monto_por_distancia(double distancia) {
    if (distancia<8) return 10.5;
    else if (distancia<12) return 14.8;
    else if (distancia<20) return 23.6;
    else return 31.70;
}

void operator! (struct OrdenDeCompra &compra) {
    compra.pagoPorEnvio = calcular_monto_por_distancia(compra.distancia);
    //anteriomente el montoPorCobrar solo tenia el pago por platos ahora se le agrega envio
    compra.montoPorCobrar = compra.pagoPorEnvio + compra.montoPorCobrar;
}

void operator!(struct Repartidor &repartidor) {
    repartidor.pagoPorEntregas =0.0;
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        repartidor.pagoPorEntregas += repartidor.ordenesDeCompra[i].montoPorCobrar;
    }
}

void operator<<(ofstream &output, const struct Plato &plato) {
    int tam = TAMREPORTE/COLUMNAS;
    output<<fixed<<setprecision(2);

    output<<setw(tam)<<right<<plato.codigo
        <<setw(3* tam)<<left<<plato.nombre
        <<setw(tam)<<right<<plato.precio
        <<setw(tam)<<plato.totalDePedidos
        <<setw(tam)<<plato.totalRecaudado<<endl;
}

void  imprimir_plato(ofstream &output,const struct PlatoSolicitado &plato, int tam){
    output<<fixed<<setprecision(2);
    output<<"- "<<setw(tam-2)<<right<<plato.codigo
    <<setw(tam)<<plato.precio
    <<setw(tam)<<plato.cantidad
    <<setw(tam)<<plato.precio*plato.cantidad<<endl;
}

void imprimir_orden(ofstream &output,const struct OrdenDeCompra &compra, int tam) {
    output<<fixed<<setprecision(2);

    output<<setw(tam)<<right<<compra.dniDelCliente
    <<setw(tam)<<compra.distancia
    <<setw(tam)<<right<<compra.montoPorCobrar
    <<setw(tam)<<right<<compra.pagoPorEnvio<<endl;

    output<<"Platos solicitados: "<<endl;

    for (int i=0;i<compra.cantidadDePlatos;i++) {
        imprimir_plato(output,compra.platosSolicitados[i],tam);
    }
}

void operator<<(ofstream &output, const struct Repartidor &repartidor) {
    int tam = TAMREPORTE/COLUMNAS;
    output<<fixed<<setprecision(2);

    output<<setw(tam)<<right<<repartidor.codigo
    <<setw(3* tam)<<left<<repartidor.nombre
    <<setw(2* tam)<<left<<repartidor.tipoDeVehiculo
    <<setw(tam)<<right<<repartidor.pagoPorEntregas<<endl;

    output<<"ORDENES ENTRAGADAS: "<<endl;
    for (int i=0;i<repartidor.cantidadDeOrdenes;i++) {
        imprimir_orden(output, repartidor.ordenesDeCompra[i], tam);
    }
}