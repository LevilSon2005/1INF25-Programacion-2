//
// Created by binny on 11/09/2025.
//

#include "Funciones.hpp"

int leer_int(ifstream &input) {
    int aux;
    input>>aux;
    input.get();
    return aux;
}
double leer_double(ifstream &input) {
    double aux;
    input>>aux;
    input.get();
    return aux;
}
char leer_char(ifstream &input) {
    char aux;
    input>>aux;
    input.get();
    return aux;
}

char* leer_cadena(ifstream &input, char del) {
    char* cadena;
    char buffer[200]{};
    input.getline(buffer, 200, del);
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(const char* buffer) {
    char* cadena;
    cadena =  new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (not input.is_open()) {
        cout<<"El archivo - "<<name<<"no se abre"<<endl;
    }else {
        cout<<"El archivo - "<<name<<" se abre"<<endl;
    }
}
void apertura_escritura(ofstream &ouput, const char* name) {
    ouput.open(name, ios::out);
    if (not ouput.is_open()) {
        cout<<"El reporte - "<<name<<"no se abre"<<endl;
    }else {
        cout<<"El reporte - "<<name<<" se abre"<<endl;
    }
}

void leer_conductores(ifstream &input, int &n_conductores,
                    int* buffer_dnis, char** buffer_nombres){
    int dni;
    while (true) {
        dni = leer_int(input);
        if (input.eof()) break;
        buffer_dnis[n_conductores] = dni;
        buffer_nombres[n_conductores] = leer_cadena(input, '\n');
        n_conductores++;
    }
}

void copiar_conductores(int* &dnis, int* buffer_dnis,
                        char** &nombres, char** buffer_nombres,
                        int n_conductores) {
    dnis = new int[n_conductores+1]{};
    nombres = new char*[n_conductores+1]{};

    for (int i=0;i<n_conductores;i++) {
        dnis[i] = buffer_dnis[i];
        nombres[i] = buffer_nombres[i];
    }
}

//memoria exacta
void operator+=(struct Conductores& arr_conductores, const char* name) {
    ifstream input;
    apertura_lectura(input, name);

    int buffer_dnis[120]{};
    char* buffer_nombres[120]{};
    arr_conductores.cantidad=0;

    leer_conductores(input,arr_conductores.cantidad, buffer_dnis, buffer_nombres);
    copiar_conductores(arr_conductores.dnis, buffer_dnis,
                        arr_conductores.nombres, buffer_nombres,
                        arr_conductores.cantidad);
}

void leer_infracciones(ifstream &input, int& n_infracciones,
                      int* buffer_codigos,char** buffer_descripciones,
                      char**buffer_tipos, double* buffer_valores){
    int codigo;
    while (true) {
        codigo = leer_int(input);
        if (input.eof()) break;
        buffer_codigos[n_infracciones] = codigo;
        buffer_descripciones[n_infracciones] = leer_cadena(input, ',');
        buffer_tipos[n_infracciones] = leer_cadena(input, ',');
        buffer_valores[n_infracciones] = leer_double(input);
        n_infracciones++;
    }
}

void copiar_infracciones(int* &codigos,int* buffer_codigos,
                        char** &descripciones,char** buffer_descripciones,
                        char** &tipos, char** buffer_tipos,
                        double* &valores, double* buffer_valores,
                        int cantidad) {

    codigos = new int[cantidad+1]{};
    descripciones = new char*[cantidad+1]{};
    tipos = new char*[cantidad+1]{};
    valores = new double[cantidad+1]{};

    for (int i=0;i<cantidad;i++) {
        codigos[i] = buffer_codigos[i];
        descripciones[i]=buffer_descripciones[i];
        tipos[i]=buffer_tipos[i];
        valores[i]=buffer_valores[i];
    }
}

void operator+=(struct Infracciones& infracciones, const char* name){
    ifstream input;
    apertura_lectura(input, name);

    int buffer_codigos[120]{};
    char* buffer_descripciones[120]{};
    char* buffer_tipos[120]{};
    double buffer_valores[120]{};

    leer_infracciones(input, infracciones.cantidad,
                      buffer_codigos,buffer_descripciones,buffer_tipos, buffer_valores);
    copiar_infracciones(infracciones.codigos,buffer_codigos,
                        infracciones.descripciones,buffer_descripciones,
                        infracciones.tipos, buffer_tipos,
                        infracciones.valores, buffer_valores,
                        infracciones.cantidad);
}

int busquedaDni(int* arr_dnis, int n_dnis, int dni){
    for (int i=0;i<n_dnis;i++) {
        if (arr_dnis[i] == dni) return i;
    }
    return -1;
}

int leer_fecha(ifstream &input) {
    int d,m,a,fecha;
    char c;
    input>>a>>c>>m>>c>>d;
    input.get();
    fecha = a*10000+m*100+d;
    return fecha;
}

int CalcularPlacas(char** placas) {
    int contador=0;
    for (int i=0;placas[i]!=nullptr;i++) {
        contador++;
    }
    return contador;
}

void incrementar_memoria(char**& placas,int& capacidad){
    capacidad += 2;
    if (placas == nullptr) {
        placas = new char*[capacidad+1]{};
    }else {
        char** aux_placas;
        aux_placas = new char*[capacidad+1];
        int n_placas_UnConductor = CalcularPlacas(placas);
        for (int i=0;i<n_placas_UnConductor;i++) {
            placas[i] = aux_placas[i];
        }
    }
}

void insertarPlaca(char** &placas_UnConductor,int &capacidad_conductor, char* placa) {
    int n_placas;
    if (placas_UnConductor == nullptr) n_placas=0;
    else  n_placas = CalcularPlacas(placas_UnConductor);
    if (capacidad_conductor == n_placas)
        incrementar_memoria(placas_UnConductor,capacidad_conductor);
    placas_UnConductor[n_placas] = asignar_cadena(placa);
}

void cargar_faltas(ifstream &input,struct Faltas& faltas){
    int dni, codInfraccion, fecha;
    char* placa;
    int capacidad;
    while (true) {
        dni = leer_int(input);
        if (input.eof()) break;
        placa = leer_cadena(input, ',');
        fecha = leer_fecha(input);
        codInfraccion = leer_int(input);
        int posConductor = busquedaDni(faltas.conductores.dnis, faltas.conductores.cantidad, dni);
        if (posConductor != -1) {
            insertarPlaca(faltas.placas[posConductor],faltas.capacidades[posConductor], placa );
        }
    }
}

//dniConductor   placa   fecha   codInfraccion
void cargar_faltas_de_los_conductores(struct Faltas &faltas) {
    ifstream inputFaltas;
    apertura_lectura(inputFaltas, "Data/Faltas.csv");

    faltas.conductores += "Data/Conductores.csv";
    faltas.infracciones += "Data/Infracciones.csv";
    faltas.placas =  new char**[faltas.conductores.cantidad]{};
    faltas.capacidades = new int[faltas.conductores.cantidad]{};

    for (int i=0;i<faltas.conductores.cantidad;i++) {
        faltas.placas[i] = nullptr;
    }

    cargar_faltas(inputFaltas, faltas);


}


//exacta -  un buffer para cada dato
// void cargar_conductores(struct Conductores &conductores, const char* name) {
//
// }