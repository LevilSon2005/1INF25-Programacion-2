//
// Created by binny on 12/09/2025.
//

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << nombre_archivo << endl;
        exit(1);
    }
}

void apertura_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "El archivo no se pudo abrir: " << nombre_archivo << endl;
        exit(1);
    }
}

int leer_int(ifstream &input) {
    int i;
    input >> i;
    input.get();
    return i;
}

double leer_double(ifstream &input) {
    double d;
    input >> d;
    input.get();
    return d;
}

char *leer_cadena(ifstream &in, char delim) {
    char *str;
    char buffer[100];
    in.getline(buffer, 100, delim);
    str = new char[strlen(buffer) + 1]{};
    strcpy(str, buffer);
    return str;
}

char *asignar_cadena(char* source) {
    char *str;
    str = new char[strlen(source) + 1]{};
    strcpy(str, source);
    return str;
}

void leer_usuarios(ifstream &input, char** &RegUsuario) {
    char* usuario = leer_cadena(input, ',');
    char* nombre = leer_cadena(input, ',');
    char* correo = leer_cadena(input, ',');
    char* facultad = leer_cadena(input, ',');

    RegUsuario =  new char*[4]{};
    RegUsuario[USUARIO] = asignar_cadena(usuario);
    RegUsuario[NOMBRE] = asignar_cadena(nombre);
    RegUsuario[CORREO] = asignar_cadena(correo);
    RegUsuario[FACULTAD] = asignar_cadena(facultad);
}

int leer_fecha(ifstream &input) {
    int d,m,a,fecha;
    char c;
    input>>a>>c>>m>>c>>d>>c;
    fecha = a*10000+m*100+d;
    return fecha;
}

void leer_fechas(ifstream &input, int*& RegFecha) {
    int fecha = leer_fecha(input);
    int edad = leer_int(input);
    RegFecha = new int[2]{};
    RegFecha[FECHA] = fecha;
    RegFecha[EDAD] = edad;
}

void reservar_memoria_incremento(char*** &arrRegUsuarios,int capacidad, int n_usuarios) {
    if (arrRegUsuarios == nullptr) {
        arrRegUsuarios = new char**[capacidad+1]{};
    }else {
        char*** AuxUsuarios;
        AuxUsuarios = new char**[capacidad+1]{};
        for (int i=0;i<n_usuarios;i++) {
             AuxUsuarios[i] = arrRegUsuarios[i] ;
        }
        delete[] arrRegUsuarios;
        arrRegUsuarios = AuxUsuarios;
    }
}

void reservar_memoria_incremento(int** &arrRegFechas,int capacidad, int n_usuarios){
    if (arrRegFechas == nullptr) {
        arrRegFechas = new int*[capacidad+1]{};
    }else {
        int** AuxFecha;
        AuxFecha = new int*[capacidad+1]{};
        for (int i=0;i<n_usuarios;i++) {
            AuxFecha[i] = arrRegFechas[i];
        }
        delete[] arrRegFechas;
        arrRegFechas = AuxFecha;
    }
}

void  insertarOrdenado(char*** &arrRegUsuarios, char** NewgUsuario,
                        int** &arrRegFechas, int* NewFecha,
                        int n_usuarios){
    int i;
    for (i=n_usuarios-1;i>=0;i--) {
        int* RegFecha = arrRegFechas[i];
        if (NewFecha[FECHA] > RegFecha[FECHA]) break;
        arrRegUsuarios[i+1] = arrRegUsuarios[i];
        arrRegFechas[i+1]=arrRegFechas[i];
    }
    arrRegUsuarios[i+1] = NewgUsuario;
    arrRegFechas[i+1]=NewFecha;
}

void cargar_usuarios(int** &arrRegFechas,char***&arrRegUsuarios,const char* name) {
    ifstream input;
    apertura_lectura(input, name);
    int n_usuarios=0;
    int capacidad=0;
    arrRegFechas = nullptr;
    arrRegUsuarios =  nullptr;
    char** RegUsuario;
    int* RegFecha;
    while (true) {
        leer_usuarios(input, RegUsuario);
        if (input.eof()) break;
        leer_fechas(input, RegFecha);
        //reserva de memoria
        if (capacidad==n_usuarios) {
            capacidad+=5;
            reservar_memoria_incremento(arrRegUsuarios, capacidad, n_usuarios);
            reservar_memoria_incremento(arrRegFechas, capacidad, n_usuarios);
        }
        insertarOrdenado(arrRegUsuarios, RegUsuario,
                        arrRegFechas, RegFecha,
                        n_usuarios);

        n_usuarios++;
    }
}

void leer_indices(ifstream &input, int* &RegIndice) {
    int indice = leer_int(input);
    int fecha = leer_fecha(input);

    RegIndice = new int[2]{};

    RegIndice[INDICE] = indice;
    RegIndice[FECHA_PUB] = fecha;
}

//leemos caracter por caracter - leemos usuario y consumimos el espacio mas cercano
bool leer_mencion(ifstream &input, char*&mencion) {
    char buffer_chars[20]{};
    int n_chars=0;
    //porque es la ultima vez que entra, ya no puede leer
    if (input.peek () == ']') {
        input.get(); //']'
        return false;
    }

    while (input.peek() != ' ' and input.peek()!= ']') {
        buffer_chars[n_chars++] = input.get();
    }

    if (input.peek() == ' ') input.get(); //consumimos el ' ' junto al usuario

    //reservamos memoria
    mencion = new char[n_chars+1]{};
    strcpy(mencion, buffer_chars);
    return true;
}

void cargar_menciones(ifstream &input, char** &RegMenciones) {
    char* buffer_menciones[10]{};
    int n_menciones=0;
    char* mencion;

    input.get();//para el '['
    while (leer_mencion(input, mencion)) {
        buffer_menciones[n_menciones++] = mencion;
    }

    RegMenciones = new char*[n_menciones+1]{};
    for (int i=0;i<n_menciones;i++) {
        RegMenciones[i] = buffer_menciones[i];
    }


}

void leer_publicaciones(ifstream &input, char** &RegPublicacion, char** &RegMenciones) {
    char* usuario = leer_cadena(input, ',');
    cargar_menciones(input, RegMenciones);
    if (input.peek() ==' ') input.get();
    char* texto = leer_cadena(input, '\n');

    RegPublicacion = new char*[2]{};
    RegPublicacion[USUARIO_PUB] = usuario;
    RegPublicacion[TEXTO] = texto;
}

void incrementar_indices(int** &arrRegIndices,int  capacidad, int n_publicaciones){
    if (capacidad==n_publicaciones) {
        arrRegIndices = new int*[capacidad+1]{};
    }else {
        int** aux;
        aux =  new int*[capacidad+1]{};
        for (int i=0;i<n_publicaciones;i++) {
            aux[i] = arrRegIndices[i];
        }
        delete[] arrRegIndices;
        arrRegIndices = aux;
    }
}

void incrementar_publicaciones(char*** &arrRegPublicaciones,int capacidad, int n_publicaciones){
    if (arrRegPublicaciones==nullptr) {
        arrRegPublicaciones =  new char**[capacidad+1]{};
    }else {
        char*** aux;
        aux = new char**[capacidad+1]{};
        for (int i=0;i<n_publicaciones;i++) {
            aux[i] = arrRegPublicaciones[i];
        }
        delete[] arrRegPublicaciones;
        arrRegPublicaciones = aux;
    }
}

void icrementar_menciones(char ***&menciones, int num, int capacidad) {
    if (menciones == nullptr) {
        menciones = new char **[capacidad + 1]{};
    } else {
        char ***aux = new char **[capacidad + 1]{};
        for (int i = 0; i < num; i++) {
            aux[i] = menciones[i];
        }
        delete[] menciones;
        menciones = aux;
    }
}

void  cargar_publicaciones(int**& arrRegIndices,char*** &arrRegPublicaciones,
                            char*** &arrRegMenciones, const char* name) {
    ifstream input;
    apertura_lectura(input, name);

    arrRegIndices=nullptr;
    arrRegPublicaciones=nullptr;
    arrRegMenciones=nullptr;
    int n_publicaciones=0, capacidad=0;

    int* RegIndice;
    char** RegPublicacion;
    char** RegMenciones;
    while (true){
        leer_indices(input, RegIndice);
        if (input.eof()) break;
        leer_publicaciones(input,RegPublicacion, RegMenciones);

        if (capacidad= n_publicaciones) {
            capacidad += 2;
            incrementar_indices(arrRegIndices, capacidad, n_publicaciones);
            incrementar_publicaciones(arrRegPublicaciones, capacidad, n_publicaciones);
            icrementar_menciones(arrRegMenciones, capacidad, n_publicaciones);
        }

        // insertarOrdenado(arrRegIndices, RegIndice,
        //                 arrRegPublicaciones,RegPublicacion,
        //                 arrRegMenciones);
        n_publicaciones++;
    }

}