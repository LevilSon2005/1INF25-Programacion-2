//
// Created by binny on 10/09/2025.
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

void leer_usuario(ifstream &input, char** &reg_usuario) {
    //creo un tipo de dato solo para leer, aun no se asigna
    char* usuario =  leer_cadena(input, ',');
    char* nombre = leer_cadena(input, ',');
    char* correo = leer_cadena(input, ',');
    char* facultad = leer_cadena(input, ',');
    //reservo memori exacta
    reg_usuario =  new char*[4]{};
    //asigno los datos creados para lectura al registro original
    reg_usuario[USUARIO] = usuario;
    reg_usuario[NOMBRE] = nombre;
    reg_usuario[CORREO] = correo;
    reg_usuario[FACULTAD] = facultad;

    //NOTA: Evaluar si esa asignacion es estatica o no
}

void leer_fechas(ifstream &input, int* &reg_fecha){
    //lectura
    int d,m,a,edad, fecha;
    char c;
    input>>a>>c>>m>>c>>d>>c;
    input>>edad;
    fecha = a*10000+m*100+d;
    //reserva de memoria
    reg_fecha = new int[2]{};
    //asignamos
    reg_fecha[FECHA] = fecha;
    reg_fecha[EDAD] = edad;
}

void incremento_arr_reg_usuarios(char*** &arr_reg_usuarios, int capacidad, int n_usuarios){
    if (arr_reg_usuarios == nullptr) {
        arr_reg_usuarios = new char**[capacidad+1]{};
    }else {
        char*** aux;
        aux = new char**[capacidad]{};
        for (int i=0;i<n_usuarios;i++) {
            aux[i] = arr_reg_usuarios[i];
        }
        delete[] arr_reg_usuarios;
        arr_reg_usuarios = aux;
    }
}

void incremento_arr_reg_fechas(int** &arr_reg_fechas,int capacidad,int n_usuarios) {
    if (arr_reg_fechas==nullptr) {
        arr_reg_fechas = new int*[capacidad+1]{};
    }else {
        int** aux;
        aux = new int*[capacidad+1]{};
        for (int i=0;i<n_usuarios;i++) {
            aux[i] = arr_reg_fechas[i];
        }
        delete[] arr_reg_fechas;
        arr_reg_fechas = aux;
    }
}

//se agrega al & porque para insertar de manera ordenada vamos a ir cambiando
// la direccion de memoria en cada indice hasta que se ordene

/*reg_usuario :  new_usuario   y   reg_fecha =  new_fecha*/
void insertar_ordenado(char*** &arr_reg_usuarios, char** reg_new_usuario,
                      int** &arr_reg_fechas, int* reg_new_fecha,
                      int n_usuarios) {
    int i;
    //hallamos el indice
    for (i=n_usuarios-1;i>=0;i--) {
        char** usuario = arr_reg_usuarios[i];
        char* nombreUsuario = usuario[NOMBRE];
        if (strcmp(reg_new_usuario[NOMBRE],nombreUsuario)>0) break;
        arr_reg_fechas[i+1] = arr_reg_fechas[i] ;
        arr_reg_usuarios[i+1] = arr_reg_usuarios[i] ;
    }

    //para la primera vez
    arr_reg_fechas[i+1] = reg_new_fecha;
    arr_reg_usuarios[i+1] = reg_new_usuario;
}

//por incremento - char*** arr_reg_usuarios y int** arr_reg_fechas
void cargar_usuarios(char*** &arr_reg_usuarios,int** &arr_reg_fechas, const char* name){
    ifstream input;
    apertura_lectura(input, name);

    //INCIALIZACIONES NECESARIAS DE RESERVA INCREMENTAL
    int n_usuarios=0; //lo mismo que para fechas
    int capacidad =0;
    arr_reg_usuarios = nullptr;
    arr_reg_fechas = nullptr;

    //Como no tenemos donde leer directamente creamos el tipo de dato a leer
    //En una linea hay dos tipos de registros : reg_usuario y reg_fecha
    char** reg_usuario;
    int* reg_fecha;
    while(true) {
        //solo leo en los reg_dato creado solo para la lectura
        // es decir, todavia no se inserta en el arreglo total de registros
        leer_usuario(input, reg_usuario);
        if (input.eof()) break;
        leer_fechas(input, reg_fecha);
        //aumentamos memoria por incremento antes de la asignación
        if (n_usuarios == capacidad) {
            capacidad += INCREMENTO;
            incremento_arr_reg_usuarios(arr_reg_usuarios, capacidad, n_usuarios);
            incremento_arr_reg_fechas(arr_reg_fechas,capacidad,n_usuarios);
        }
        insertar_ordenado(arr_reg_usuarios, reg_usuario,
                          arr_reg_fechas, reg_fecha,
                          n_usuarios);
        n_usuarios++;
    }
}


void imprimir_usuario_y_fecha(ofstream &output, char** registro_usuario,int*  registro_fecha){
    output<<"Datos de usuario: "<<endl;
    output<<registro_usuario[USUARIO]<<" - "
    <<registro_usuario[NOMBRE]<<" - "
    <<registro_usuario[CORREO]<<" - "
    <<registro_usuario[FACULTAD]<<endl;

    output<<"Datos de fechas: "<<endl;
    output<<registro_fecha[EDAD]<<" - "
    <<registro_fecha[FECHA]<<endl;

    output<<"--------------------------------------------------------"<<endl;
}

void imprimir_usuarios(char*** arr_registros_usuarios,int** arr_registros_fechas, const char* name) {
    ofstream output;
    apertura_escritura(output, name);

    for (int i=0;arr_registros_usuarios[i];i++) {
        imprimir_usuario_y_fecha(output, arr_registros_usuarios[i], arr_registros_fechas[i]);
    }
};

void leer_fechasId(ifstream &input,int* &reg_fechaId){
    //lectura
    int indice, fecha_pub,d,a,m;
    char c;
    indice = leer_int(input);
    input>>a>>c>>m>>c>>d>>c;
    fecha_pub = a*10000+m*100+d;
    //reserva de memoria
    reg_fechaId =  new int[2]{};
    //asignacion
    reg_fechaId[INDICE] = indice;
    reg_fechaId[FECHA] = fecha_pub;
}

//va a validar si se puede leer
//si es que SI se puede leer, lo lee
bool leer_mencion(ifstream &input, char* &mencion) {
    char buffer_mencion[15]{};
    int n_chars=0;
    //primero validamos si empieza con ']' porque significaria que ya no puede seguir leyendo
    if (input.peek() == ']') {
        input.get(); //para consumir
        return false;
    }
    //leemos siempre y cuando sea distinto de ' ' o ']'
    while (input.peek() != ' ' and input.peek() != ']') {
        char c = input.get();
        buffer_mencion[n_chars++]= c;
    }
    buffer_mencion[n_chars]='\0';

    //si es que aun no es el ultimo, el sig caracter es ' ',
    //leemos ese ' ' para que la siguiente vez que entre sea de frente del user
    if (input.peek() == ' ') input.get();

    //reservamos memoria y asginamos lo del buffer
    mencion =  new char[n_chars+1]{};
    strcpy(mencion, buffer_mencion);
    return true;
}

//char** reg_menciones -> memoria exacta
void cargar_menciones(ifstream &input, char** &reg_menciones) {
    char* bufferMenciones[10]{};
    int n_menciones=0;
    char* mencion;
    //lectura de cada mencion siempre que se pueda leer
    while (true) {
        if (!leer_mencion(input, mencion)) break;
        bufferMenciones[n_menciones++]= mencion;
    }
    //reservamos memoria
    reg_menciones = new char*[n_menciones+1]{};
    //asignamos del buffer al real
    for (int i=0;i<n_menciones;i++) {
        reg_menciones[i] = bufferMenciones[i];
    }
}

void leer_publicacion(ifstream &input, char** &reg_publicacion, char** &reg_menciones) {
    char* usuario = leer_cadena(input, ',');
    input.get(); //consume el '['
    //adentro consumo las menciones y ']' .... no consumo el '['
    cargar_menciones(input,reg_menciones);
    if (input.peek()==' ')input.get(); //para consumir el ' '
    char* texto = leer_cadena(input, '\n');

    reg_publicacion = new char*[2]{};
    reg_publicacion[USUARIO_PUB] = usuario;
    reg_publicacion[TEXTO] = texto;
}

//reserva de memoria por incremento
void cargar_publicaciones(int** &arr_reg_fechasId, char*** &arr_reg_publicaciones,
                          char*** &arr_reg_menciones, const char* name) {
    int n_publicaciones=0;
    int capacidad =0;
    arr_reg_fechasId=nullptr;
    arr_reg_publicaciones = nullptr;
    arr_reg_menciones = nullptr;

    ifstream input;
    apertura_lectura(input, name);

    int* reg_fechaId;
    char** reg_publicacion;
    char** reg_menciones;

    while (true) {
        leer_fechasId(input,reg_fechaId);
        if (input.eof()) break;
        // while (input.get() != '\n');
        leer_publicacion(input, reg_publicacion, reg_menciones);

        // if (capacidad == n_publicaciones) {
        //     capacidad += INCREMENTO;
        //     incremento_fechasId(arr_reg_fechasId, capacidad, n_publicaciones);
        //     incrmento_publicaciones(arr_reg_publicaciones, capacidad, n_publicaciones);
        //     incremento_menciones(arr_reg_menciones, capacidad, n_publicaciones);
        // }
        // insertarOrdenado(arr_reg_publicaciones, reg_publicacion,
        //                   arr_reg_menciones, reg_mencion,
        //                   arr_reg_fechasId, reg_fechaId,
        //                   n_publicaciones);
        n_publicaciones++;
    }
}