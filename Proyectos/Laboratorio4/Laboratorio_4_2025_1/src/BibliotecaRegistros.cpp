//
// Created by binny on 01/10/2025.
//

#include "BibliotecaRegistros.hpp"

char* leer_cadena(ifstream &input, char del) {
    char* cadena, buffer[200]{};
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}

int leer_fecha(ifstream &input) {
    int fecha,d,m,a;
    input>>d;
    input.get();
    input>>m;
    input.get();
    input>>a;
    input.get();
    fecha = a*10000+m*100+d;
    return fecha;
}

int leer_int(ifstream &input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

//licencia  placa   fecha   falta   nombre
//26522329,U5W-825,22/11/2019,101,SANCHEZ DEL CASTILLO FIORELLA ROSARIO
void * leeregistro(ifstream &input) {
    void** registro;
    int* ptr_licencia, licencia, *ptr_fecha, fecha, *ptr_falta, falta;
    char* placa, *nombre;

    licencia = leer_int(input);
    placa = leer_cadena(input, ',');
    fecha = leer_fecha(input);
    falta = leer_int(input);
    nombre = leer_cadena(input, '\n');

    ptr_licencia = new int[1]{};
    ptr_fecha = new int[1]{};
    ptr_falta = new int[1]{};

    *ptr_licencia = licencia;
    *ptr_fecha = fecha;
    *ptr_falta = falta;

    registro = new void*[4]{};
    registro[FECHA] = ptr_fecha;
    registro[LICENCIA] = ptr_licencia;
    registro[NOMBRE] = nombre;
    registro[FALTA] = ptr_falta;

    return registro;
}

int clasificaregistro(void *dato) {
    void** registro = (void**) dato;
    int* ptr_falta = (int*) registro[FALTA];
    int primer_digito = (*ptr_falta)/100;

    return (primer_digito==1)?(1):(2);
}

void imprimir_fecha(ofstream &output, int fecha, int tam){
    int d,m,a;
    d = fecha%100;
    a = fecha/10000;
    m = (fecha/100)%100;

    output<<left<<setfill('0')<<setw(2)<<d<<"/"
    <<setw(2)<<m<<"/"<<setw(4)<<a<<setfill(' ');
    output<<setw(tam-10)<<"";
}

//imprime solo una linea del reporte
void imprimeregistro(ofstream &output, void *dato) {
    int tam= TAMREPORTE/COLUMNAS;
    void** registro = (void**) dato;

    int* ptr_fecha = (int*)registro[FECHA];
    int* ptr_licencia = (int*)registro[LICENCIA];
    char* nombre = (char*)registro[NOMBRE];
    int* ptr_falta = (int*)registro[FALTA];

    imprimir_fecha(output, *ptr_fecha, tam);
    output<<left<<setw(tam)<<*ptr_licencia
    <<setw(2*tam)<<nombre
    <<setw(tam)<<*ptr_falta<<endl;

}
