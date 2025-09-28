//
// Created by binny on 16/09/2025.
//

#include "Funciones.hpp"

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
    input.getline(buffer,200,del);
    cadena = new char[strlen(buffer)+1]{};
    strcpy(cadena,buffer);
    return cadena;
}

void ignorar(ifstream &input, char del) {
    while (input.get()!= del);
}

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (not input.is_open()) {
        cout<<"No se pudo abrir el archivo"<<name<<" "<<endl;
    }else {
        cout<<"El archivo abierto : "<<name<<" "<<endl;
    }
}

void apertura_escritura(ofstream &output, const char* name) {
    output.open(name, ios::out);
    if (not output.is_open()) {
        cout<<"No se pudo abrir el reporte - "<<name<<" "<<endl;
    }else {
        cout<<"El reporte abierto : "<<name<<" "<<endl;
    }
}

void* leer_alumnos(ifstream &input){
    void** registro;
    int codigo, *ptr_codigo;
    char* nombre;

    //lectura
    codigo = leer_int(input);
    if (input.eof()) return nullptr;
    nombre = leer_string(input,'\n');

    //asignacion de datos leidos a punteros
    ptr_codigo =  new int;
    *ptr_codigo = codigo;

    //reserva de memoria de registro del alumno
    registro = new void*[4]{};
    registro[NOMBRE] = nombre;
    registro[CODIGO] = ptr_codigo;
    registro[PROMEDIO] = nullptr;
    registro[CURSOS] = nullptr;

    return registro;
}

void incrementar_alumnos(void** &arrAlumnos, int &capacidad, int &n_alumnos){
    capacidad += INCREMENTO;
    if (arrAlumnos == nullptr) {
        arrAlumnos =  new void*[capacidad+1]{};
    }
    else {
        void** aux;
        aux =  new void*[capacidad+1]{};
        for (int i=0;i<n_alumnos;i++) {
            aux[i] = arrAlumnos[i];
        }
        delete[] arrAlumnos;
        arrAlumnos =  aux;
    }
}

void cargarAlumnos(void* &alumnos,const char* name){
    ifstream input;
    input.open(name, ios::in);

    /*Como vamos a llenar la data de varios alumnos necesitamos insertarlo en un
     * arreglo, dereferenciando poco a poco. Pero eso no se puede usar un void*
     * por eso se aterriza una variable  void** para el arreglo
     */

    //variable void** aterrizado para VARIOS ALUMNOS
    void** arrAlumnos;

    //Variables indispensables para incrementar
    int n_alumnos=0, capacidad=0;
    arrAlumnos = nullptr;

    //Variable para lectura de un alumno: registro (Tener en cuenta, que internamente
    //en la funcion registro tiene más data asi que leerá como void**, pero se retorna
    //afuera de la funcion como void*)
    void* registro;

    while (true) {
        registro = leer_alumnos(input);
        if (input.eof()) break;
        if (capacidad == n_alumnos) {
            incrementar_alumnos(arrAlumnos, capacidad, n_alumnos);
        }
        //void*  =  void*
        arrAlumnos[n_alumnos] =  registro;
        n_alumnos++;
    }
    //Hacemos que el puntero que antes estaba vacio al puntero de arreglo que tiene data
    alumnos = arrAlumnos; //  void* = void**
}

void imprimir_alumno(void* alumno, ofstream &output) {
    void** registro = (void**) alumno;

    int* codigo = (int*)registro[CODIGO];
    char* nombre = (char*)registro[NOMBRE];

    output<<"Alumno: "<< left << setw(50) << nombre
        << setw(10)<<*codigo<<endl;

}

void probarCarga(void* alumnos, const char* name) {
    ofstream output;
    apertura_escritura(output, name);

    void** arr_alumnos = (void**)alumnos;
    for (int i=0;arr_alumnos[i];i++) {
        imprimir_alumno(arr_alumnos[i], output);
    }
};

bool son_iguales(int codigo, void *alumno) {
    void **registro = (void **) alumno;
    int *codigo_ptr = (int *)registro[CODIGO];
    return codigo == *codigo_ptr; //int == int
}

int busquedaAlumnos(int codigo, void** arr_alumnos) {
    for (int i=0;arr_alumnos[i];i++) {
        if (son_iguales(codigo, arr_alumnos[i]))return i;
    }

    return NO_ENCONTRADO;
}

void* leer_curso(ifstream &input){
    void** registro_curso;
    int* ptr_nota =  new int;

    char* codCurso = leer_string(input, ',');
    *ptr_nota = leer_int(input);

    registro_curso =  new void*[2]{};
    registro_curso[CODCURSO] = codCurso;
    registro_curso[NOTA] = ptr_nota;

    return registro_curso;
}

void incrementar_memoria(void* &cursos, int &capacidad, int &cant_cursos){
    void** arr_cursos = (void**) cursos;
    capacidad += INCREMENTO;
    if (arr_cursos == nullptr) {
        arr_cursos =  new void* [capacidad+1]{};
    }else {
        void** aux;
        aux =  new void*[capacidad+1]{};
        for (int i=0;i<cant_cursos;i++) {
            aux[i] = arr_cursos[i];
        }
        delete[] arr_cursos;
        arr_cursos =  aux;
    }
    cursos = arr_cursos;
}

//LECTURA - MEMORIA - ASIGNAR
void colocarDataCurso(ifstream &input,void* alumno, int &capacidad, int &cant_cursos) {
    void** registro_alumno = (void**) alumno;
    void* curso;
    //LECTURA: para lectura siempre se usa un registro que todavia no está en ninguna
    //          parte del arreglo
    curso = leer_curso(input);

    //MEMORIA
    if (capacidad==cant_cursos) {
        incrementar_memoria(registro_alumno[CURSOS],capacidad, cant_cursos);
    }
    //ASIGNAR
    registro_alumno[cant_cursos] = curso;
    cant_cursos++;
    cout<<cant_cursos<<endl;
}

//sin &: porque ya reservé memoria en cargar_alumnos, cada registro tiene memoria
void cargas_cursos(void* alumnos, const char* name) {
    ifstream input;

    int codigo,posAlumno=0;

    apertura_lectura(input, name);
    //casteamos alumnos en otra variable para poder recorrer la info
    void** arr_alumnos = (void**) alumnos;

    //variables indispensable para reserva por incremento
    int cant_cursos[40]{0}, capacidad_cursos[40]{0};
    while (true) {
        codigo = leer_int(input);
        if (input.eof()) break;
        posAlumno = busquedaAlumnos(codigo, arr_alumnos);
        if (posAlumno != NO_ENCONTRADO) {
            cout<<"PosAlumno: "<<posAlumno<<"-";
            colocarDataCurso(input,arr_alumnos[posAlumno], capacidad_cursos[posAlumno], cant_cursos[posAlumno]);
        }else {
            while(input.get()!= '\n');
        }
    }
}