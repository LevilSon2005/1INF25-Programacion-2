//
// Created by binny on 18/09/2025.
//

#include "Funciones_Genericas.hpp"

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if ( not input.is_open()) {
        cout<<" El archivo "<<name<< " no se abrio"<<endl;
    }else {
        cout<<" El archivo "<<name<< " se abrio"<<endl;
    }
}

void apertura_escritura(ofstream &output, const char* name) {
    output.open(name, ios::out);
    if ( not output.is_open()) {
        cout<<" El reporte "<<name<< " no se abrio"<<endl;
    }else {
        cout<<" El reporte "<<name<< " se abrio"<<endl;
    }
}

int leer_int(ifstream &input) {
    int aux;
    input >> aux;
    input.get();
    return aux;
}

double leer_double(ifstream &input) {
    double aux;
    input >> aux;
    input.get();
    return aux;
}

char leer_char(ifstream &input) {
    char aux;
    input >> aux;
    input.get();
    return aux;
}

char* leer_string(ifstream &input, char del) {
    char* cadena, buffer[200]{};
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(char* buffer) {
    char* cadena;
    cadena =  new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}

void imprimir_titulo(ofstream& output, const char* titulo) {
    output<<setw((TAMREPORTE + strlen(titulo))/2)<<titulo<<endl;
}

void* leer_cliente(ifstream &input) {
    //54393647,Reyes Tang Edward
    void** registro;
    char* nombre;
    int* ptr_dni;
    ptr_dni = new int;

    *ptr_dni = leer_int(input);
    if (input.eof()) return nullptr;
    nombre = leer_string(input, '\n');

    registro = new void*[2]{};
    registro[DNI] = ptr_dni;
    registro[NOMBRE_CLIENTE] = nombre;

    return registro;
}

void incrementar_memoria(void** &arreglo, int &capacidad, int &n){
    capacidad += INCREMENTO;
    if (arreglo == nullptr) {
        arreglo = new void*[capacidad+1]{};
        // n =1;
    }else {
        void** aux;
        aux =  new void*[capacidad+1]{};
        for (int i=0;i<n;i++) {
            aux[i] = arreglo[i];
        }
        delete arreglo;
        arreglo = aux;
    }
}


void carga_clientes(void*& clientes){
    ifstream input;
    apertura_lectura(input, "Data/Clientes.csv");

    //arr_clientes y registro_clientes son auxiliares, el original es clientes
    //No olvidar asignar al final a clientes
    void** arr_clientes;
    arr_clientes = nullptr;
    int capacidad =0, n_clientes=0;
    void* registro_cliente;

    while (true) {
        registro_cliente = leer_cliente(input);
        if (input.eof()) break;
        if (capacidad == n_clientes) {
            incrementar_memoria(arr_clientes, capacidad, n_clientes);
        }
        arr_clientes[n_clientes] = registro_cliente;
        n_clientes++;
    }
    clientes = arr_clientes;

}

void imprimir_cliente(ofstream &output, void* cliente) {
    void** registro_cliente = (void**)cliente;
    int tam= TAMREPORTE/4;

     int* ptr_dni= (int*)registro_cliente[DNI] ;
    char* nombre= (char*)registro_cliente[NOMBRE_CLIENTE];

    output<<setw(2*tam)<<left<<nombre;
    output<<setw(tam)<<right<<*ptr_dni<<endl;
}

void muestra_clientes(void* clientes) {
    void** arr_clientes = (void**)clientes;
    ofstream output;
    apertura_escritura(output, "Reportes/Reporte_clientes.txt");
    imprimir_titulo(output, "REPORTE DE PRUEBA DE CLIENTES");
    for (int i=0;arr_clientes[i];i++) {
        imprimir_cliente(output, arr_clientes[i]);
    }
}

void reservar_memoria_pedidos(int cantidad, void*&pedidos){
    void** arr_pedidos = (void**)pedidos;
      arr_pedidos =  new void*[cantidad+1]{};
    for (int i=0;i<cantidad;i++) {
        arr_pedidos[i] = new void*[2]{};
    }
    pedidos = arr_pedidos;
}

void* leer_libro(ifstream &input){
    //IM5175,Diamantes y pedernales,Jose Maria Arguedas,2,30.23
    void** registro_libro;

    char* codLibro, * nombre,* autor;
    int* ptr_cantidad, cantidad;
    ptr_cantidad = new int;
    double precio;

    codLibro =  leer_string(input, ',');
    nombre = leer_string(input, ',');
    autor = leer_string(input, ',');
    cantidad = leer_int(input);
    *ptr_cantidad = cantidad;
    precio = leer_double(input);

    registro_libro = new void*[5]{};
    registro_libro[CODLIBRO] = codLibro;
    registro_libro[NOMBRE_LIBRO] = nombre;
    registro_libro[AUTOR] = autor;
    reservar_memoria_pedidos(cantidad, registro_libro[PEDIDOS]);
    registro_libro[CANTIDAD] = ptr_cantidad;

    return registro_libro;
}

void crear_reserva(void* &reserva){
    void** arr_libros;
    void* registro_libro;

    ifstream input;
    apertura_lectura(input, "Data/Libros.csv");
    arr_libros = nullptr;
    int capacidad = 0, n_reserva = 0;

    while (true) {
        registro_libro = leer_libro(input);
        if (input.eof()) break;
        if (capacidad == n_reserva) {
            incrementar_memoria(arr_libros, capacidad, n_reserva);
        }
        arr_libros[n_reserva] = registro_libro;
        n_reserva++;
    }
    reserva = arr_libros;
}

void imprimir_libro(ofstream &output, void* libro){
    void**  registro_libro = (void**)libro;
    int tam=TAMREPORTE/6;
    char* codLibro = (char*)registro_libro[CODLIBRO];
    char* nombre = (char*)registro_libro[NOMBRE_LIBRO];
    char* autor = (char*)registro_libro[AUTOR];
    int* ptr_cantidad = (int*)registro_libro[CANTIDAD];

    output<<setw(2*tam)<<left<<nombre
    <<setw(tam)<<codLibro
    <<setw(2*tam)<<autor
    <<setw(tam)<<right<<*ptr_cantidad<<endl;
}

void muestre_reserva(void* reserva) {
    void** arr_libros = (void**)reserva;
    ofstream output;
    apertura_escritura(output, "Reportes/Reporte_reserva.txt");
    imprimir_titulo(output, "REPORTE DE RESERVA");
    for (int i=0;arr_libros[i];i++) {
        imprimir_libro(output, arr_libros[i]);
    }
}

bool es_dni_igual(int dni, void* cliente) {
    void** registro_cliente = (void**)cliente;
    int* ptr_dni = (int*)registro_cliente[DNI];

    return (dni == *ptr_dni);
}

void imprimir_nombre(void* cliente) {
    void** registro_cliente = (void**)cliente;
    cout<<(char*)registro_cliente[NOMBRE_CLIENTE]<<endl;
}

int busquedaCliente(int dni, void* clientes) {
    int contador=0;
    void** arr_clientes = (void**)clientes;
    if (arr_clientes == nullptr) cout<<"F"<<endl;
    // for (int i=0;arr_clientes[i];i++) contador++;
    // cout<<contador<<endl;
    // imprimir_nombre(arr_clientes[56]);
    for (int i=0;arr_clientes[i];i++) {
        if (es_dni_igual(dni, arr_clientes[i])) return i;
    }
    return NO_ENCONTRADO;
}

bool es_codigo_igual(char* codLibro, void* libro) {
    void** registro_libro = (void**)libro;
    char* codigo_libro = (char*)registro_libro[CODLIBRO];
    return (strcmp(codLibro, codigo_libro));
}

int busquedaLibro(char* codLibro, void** arr_libros){
    for (int i=0;arr_libros[i];i++) {
        if (es_codigo_igual(codLibro, arr_libros[i])) return i;
    }
    return NO_ENCONTRADO;
}

void asignar_cliente_a_pedido(void* &pedido, void* cliente) {
    void** registro_pedido = (void**)pedido;
    void** registro_cliente = (void**)cliente;

    int* ptr_dni = (int*)registro_cliente[DNI];
    char* nombre = (char*)registro_cliente[NOMBRE_CLIENTE];

    registro_pedido =  new void*[2]{};
    registro_pedido[DNI] = ptr_dni;
    registro_pedido[NOMBRE_LIBRO] = asignar_cadena(nombre);
    pedido = registro_pedido;
}

void colocar_pedido(void* &libro, void* cliente, int &n_pedidos) {
    void** registro_libro = (void**)libro;

    void* pedidos = registro_libro[PEDIDOS];
    void** arr_pedidos = (void**)pedidos; //tiene memoria pero no esta asignado nada todavia

    void* pedido = arr_pedidos[n_pedidos];

    asignar_cliente_a_pedido(pedido, cliente);
    n_pedidos++;

}

void carga_reserva(void* clientes, void* reserva){
    ifstream input;
    apertura_lectura(input,"Data/Pedidos2.csv");
    void** arr_libros = (void**)reserva;
    void** arr_clientes = (void**)clientes;
    char* codLibro;
    int dni, posCliente, posLibro, n_pedidos[300]{};
    while (true) {
        dni =  leer_int(input);
        if (input.eof()) break;
        codLibro = leer_string(input, '\n');
        posCliente = busquedaCliente(dni, clientes);
        posLibro = busquedaLibro(codLibro, arr_libros);
        if (posCliente != NO_ENCONTRADO and posLibro != NO_ENCONTRADO) {
            colocar_pedido(arr_libros[posLibro], arr_clientes[posCliente], n_pedidos[posLibro]);
        }
    }

    // dni =  leer_int(input);
    // posCliente = busquedaCliente(dni, clientes);
    // cout<<posCliente<<endl;
}


// void reporte_final(void* reserva);