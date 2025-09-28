#include "src/Funciones.hpp"

// EXACTA - EXACTA (El nombre de la carpeta es un error)
int main() {
    int* fechas;
    char** tweets;
    char*** hashtags;

    leer_tweets(fechas, tweets, "Data/Tweets.csv");
    imprimir_tweets(fechas, tweets, "Reportes/Reporte_fecha_tweets.txt");
    leer_hashtags(fechas, hashtags, "Data/Hashtags.csv");
    return 0;
}