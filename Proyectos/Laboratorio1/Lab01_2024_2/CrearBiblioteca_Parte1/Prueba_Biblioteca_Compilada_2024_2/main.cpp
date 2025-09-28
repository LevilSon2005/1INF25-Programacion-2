#include "src/Sobrecargas.hpp"
int main() {

    ifstream inputPlato;
    AperturaDeUnArchivoDeTextosParaLeer(inputPlato, "Data/PlatosOfrecidos.csv");
    struct Plato plato{};
    inputPlato>>plato;
    cout<<"Plato: "<<endl;
    cout<<plato.codigo<<"-"<<plato.nombre<<"-"<<plato.precio<<"-"<<plato.tipoDePlato<<endl;

    ifstream inputRepartidor;
    AperturaDeUnArchivoDeTextosParaLeer(inputRepartidor, "Data/RepartidoresContratados.csv");
    struct Repartidor repartidor{};
    inputRepartidor>>repartidor;
    cout<<"Repartidor: "<<endl;
    cout<<repartidor.codigo<<"-"<<repartidor.nombre<<"-"<<repartidor.tipoDeVehiculo<<endl;

    ifstream inputPedido;
    AperturaDeUnArchivoDeTextosParaLeer(inputPedido, "Data/OrdenesDeCompra.txt");
    struct Pedido pedido{};
    inputPedido>>pedido;
    cout<<"Pedido: "<<endl;
    cout<<pedido.dniDelCliente<<"/";
    cout<<pedido.codigoDelPlato<<"/";
    cout<<pedido.cantidad<<"/";
    cout<<pedido.precio<<"/";
    cout<<pedido.codigoDelRepartidor<<"/";
    cout<<pedido.distanciaARecorrer<<endl;

    //para:  pedido<=arregloPlatos
    struct Plato arregloPlatos[5]{};
    inputPlato>>arregloPlatos[0];
    inputPlato>>arregloPlatos[1];
    inputPlato>>arregloPlatos[2];
    inputPlato>>arregloPlatos[3];
    strcpy(arregloPlatos[4].codigo, "FIN");
    cout<<"Prueba para asignar el precio de un pedido: "<<endl;
    pedido<=arregloPlatos;
    cout<<pedido.precio<<"/";
    cout<<arregloPlatos[2].totalDePedidos<<"/"<<arregloPlatos[2].totalRecaudado<<endl;


    return 0;
}