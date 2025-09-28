//
// Created by binny on 10/09/2025.
//

#ifndef EXACTA_INCREMENTO_FUNCIONES_HPP
#define EXACTA_INCREMENTO_FUNCIONES_HPP

#include "Utils.hpp"

void leer_tweets(int* &fechas, char** &tweets, const char* name);
void cargar_tweets(ifstream &input,int &n_tweets,
                    char** buffer_tweets, int* buffer_fechas) ;
void copiar_tweets(char** &tweets,char** buffer_tweets,int n_tweets,
                   int* &fechas, int* buffer_fechas);
void imprimir_tweets(int* fechas,char** tweets,
                    const char* name);
void leer_hashtags(int* fechas, char*** hashtags, const char* name);


#endif //EXACTA_INCREMENTO_FUNCIONES_HPP