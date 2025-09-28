//
// Created by binny on 04/09/2025.
//

#include "Sobrecargas.hpp"

int leer_int(ifstream &input){
    int dato;
    input>>dato;
    input.get();
    return dato;
}
double leer_double(ifstream &input) {
    double dato;
    input>>dato;
    input.get();
    return dato;
}
char leer_char(ifstream &input){
    char dato;
    input>>dato;
    input.get();
    return dato;
}

void leer_cadena(ifstream &input, char del, char* cadena) {
    input.getline(cadena, 100, del);
}


//AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
//
void operator>>(ifstream &input, struct Plato& plato) {
    char codigo[10];
    leer_cadena(input, ',', codigo);
    if (input.eof()) return;
    input.get();
    strcpy(plato.codigo, codigo);
    leer_cadena(input, ',', plato.nombre);
    plato.precio = leer_double(input);
    leer_cadena(input, '\n', plato.tipoDePlato);

    plato.totalDePedidos = 0;
    plato.totalRecaudado = 0.0;
}

//SYI157,Sam Yallico Ines ,Motocicleta
//
void operator>>(ifstream &input, struct Repartidor& repartidor) {
    char codigo[10];
    leer_cadena(input, ',',codigo);
    if (input.eof()) return;
    input.get();
    strcpy(repartidor.codigo, codigo);
    leer_cadena(input, ',', repartidor.nombre);
    leer_cadena(input,'\n', repartidor.tipoDeVehiculo);

    repartidor.cantidadDeOrdenes =0;
    repartidor.pagoPorEntregas = 0.0;
}

//15290194  BR-283    1    MCE193    11.69
//dni   codPlato  cantPedida codRepartidor   distancia
void operator>>(ifstream &input, struct Pedido& pedido) {
    int dni;
    input>>dni;
    if (input.eof()) return;
    pedido.dniDelCliente = dni;
    input>>pedido.codigoDelPlato;
    input>>pedido.cantidad;
    input>>pedido.codigoDelRepartidor;
    input>>pedido.distanciaARecorrer;
}

//Para determinar el precio del plato - arregloPlatos debe tener FIN
bool operator<=(struct Pedido& pedido, struct Plato* arregloPlatos) {
    for (int i=0;strcmp(arregloPlatos[i].codigo, "FIN")!=0;i++) {
        if (strcmp(pedido.codigoDelPlato, arregloPlatos[i].codigo)==0) {
            //encontró el codigo del plato del pedido en el arreglo
            //asignar el precio al pedido
            pedido.precio = arregloPlatos[i].precio;
            //incrementando totales del plato
            arregloPlatos[i].totalDePedidos++;
            arregloPlatos[i].totalRecaudado += pedido.precio;
            return true;
        }
    }
    return false;
}

/*
* struct Pedido{
    int dniDelCliente;
    char codigoDelPlato[7];
    int cantidad;
    double precio;
    char codigoDelRepartidor[7];
    double distanciaARecorrer;
};
 */

void agregar_cliente_repetido(const struct Pedido &pedido,struct OrdenDeCompra &orden) {

}

void agregar_cliente_nuevo(const struct Pedido &pedido,struct OrdenDeCompra &orden) {

}

//Agrega un pedido a un repartidor - ArregloRepartidores Debe tener FIN
//pedido de UN cliente -> varios platos - No repetir platos - acumular datos del plato
//Repartidor -> No se debe repetir Clientes en OrdenCompra -
void operator<=(struct Repartidor* arregloRepartidores, struct Pedido& pedido) {
    bool clienteEncontrado = false;
    int posCliente =0;
    for (int i=0;strcmp(arregloRepartidores[i].codigo, "FIN")!=0;i++) {
        if (pedido.codigoDelRepartidor == arregloRepartidores[i].codigo) {//se encontro el repartidor asignado de UN cliente
            struct Repartidor &repartidor = arregloRepartidores[i];
            int n_ordenes = repartidor.cantidadDeOrdenes;
            for (int i=0;i<n_ordenes;i++) //recorremos para ver si el dni del cliente esta o no
                if (repartidor.ordenesDeCompra[i].dniDelCliente == pedido.dniDelCliente) {
                    posCliente =i;
                    clienteEncontrado = true;
                }
            if (clienteEncontrado){
                agregar_cliente_repetido(pedido,repartidor.ordenesDeCompra[posCliente]);
            }else {
                agregar_cliente_nuevo(pedido,repartidor.ordenesDeCompra[n_ordenes]);
                repartidor.cantidadDeOrdenes++;
                repartidor.pagoPorEntregas += pedido.precio;
            }
        }
    }
}