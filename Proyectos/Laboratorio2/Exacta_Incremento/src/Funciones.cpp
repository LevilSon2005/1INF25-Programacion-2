//
// Created by binny on 10/09/2025.
//

#include "Funciones.hpp"

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if ( not input.is_open() ) {
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else {
        cout<<"El archivo - "<<name<<" se abrio"<<endl;
    }
}
void apertura_escritura(ofstream &ouput, const char* name) {
    ouput.open(name, ios::out);
    if ( not ouput.is_open() ) {
        cout<<"El archivo "<<name<<" no se abrio"<<endl;
    }else {
        cout<<"El reporte - "<<name<<" se abrio"<<endl;
    }
}

int leer_int(ifstream &input) {
    int aux;
    input>>aux;
    input.get();
    return aux;
}

char* leer_cadena(ifstream &input, char del) {
    char* cadena;
    char buffer[200]{};
    input.getline(buffer, 200, del);
    cadena = new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}


char* asignar_cadena(char* buffer) {
    char* cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}
//MEMORIA EXACTA

/* 1. Creamos buffer con cada tipo de dato
 * 2. Necesitamos algo que nos ayude a contar como "n_datos",
        excepto si es cadena, porque ahi ya hay strlen
 * 3. Creamos una funcion de cargar() donde leemos y añadimos al buffer
        tambien aumentamos nuestro n_datos
*  4. En otra funcion de copiar(): - creamos memoria exacta con tu n_datos
        - asignamos los datos del buffer a la nueva memoria
 */
void leer_tweets(int* &fechas, char** &tweets, const char* name) {
    ifstream input;
    apertura_lectura(input, name);

    int buffer_fechas[MAX_TWEETS]{};
    char* buffer_tweets[MAX_TWEETS]{};
    int n_tweets = 0;
    cargar_tweets(input, n_tweets, buffer_tweets, buffer_fechas);
    copiar_tweets(tweets,buffer_tweets, n_tweets,
                    fechas, buffer_fechas);
}

void cargar_tweets(ifstream &input,int &n_tweets,
                    char** buffer_tweets, int* buffer_fechas) {
    int fecha;
    while (true) {
        fecha = leer_int(input);
        if (input.eof()) break;
        buffer_fechas[n_tweets] = fecha;
        buffer_tweets[n_tweets] = leer_cadena(input, '\n');
        n_tweets++;
    }
}

//RESERVAR MEMORIA EXACTA A SEGUNDO NIVEL con ayuda de nuestro contador
void copiar_tweets(char** &tweets,char** buffer_tweets,int n_tweets,
                   int* &fechas, int* buffer_fechas) {
    //Reservo memoria exacta
    tweets = new char*[n_tweets+1]{};
    fechas = new int[n_tweets+1]{};
    //Asigno los valores
    for (int i=0;i<n_tweets;i++) {
        fechas[i] = buffer_fechas[i];
        tweets[i] = asignar_cadena(buffer_tweets[i]);
    }
}


void imprimir_tweets(int* fechas,char** tweets,
                    const char* name){
    ofstream output;
    apertura_escritura(output, name);
    for (int i=0;fechas[i];i++) {
        output << fechas[i] << " ->  "<<tweets[i]<<endl;
    }
}

int busquedaFecha(int fecha, int* fechas){
    for (int i=0; fechas[i];i++) {
        if (fecha = fechas[i]) return i;
    }
    return -1;
}

void anadirHashtag(char* hastag ,char** &hashtags_tweet,int &n_hashtags_por_tweet) {
    hashtags_tweet[n_hashtags_por_tweet] = hastag;
    n_hashtags_por_tweet++;
}

void leer_hashtags(ifstream &input, char***&hashtags,int* fechas,
                    int* n_hashtags_por_tweet){
    int fecha, posFecha=0;
    char* hastag;
    while (true) {
        fecha = leer_int(input);
        if (input.eof()) break;
        hastag = leer_cadena(input, '\n');
        posFecha =  busquedaFecha(fecha, fechas);
        if (posFecha != -1) {
            anadirHashtag(hastag,hashtags[posFecha],n_hashtags_por_tweet[posFecha]);
        }
    }
}

void leer_hashtags(int* fechas, char*** hashtags, const char* name){
    ifstream input;
    apertura_lectura(input, name);
    int n_tweets = 0;
    for (int i=0;fechas[i];i++) n_tweets++;

    hashtags =  new char**[n_tweets]{}; //char***

    int nums_hashtags_por_tweet[n_tweets];
    //como es memoria exacta incializamos y asumimos un máx de 20 hashtags por tweet
    for (int i=0;i<n_tweets; i++){
        nums_hashtags_por_tweet[i]=0;
        hashtags[i] = new char*[20]{};
    }
    leer_hashtags(input, hashtags,fechas,nums_hashtags_por_tweet);
}