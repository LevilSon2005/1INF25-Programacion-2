//
// Created by binny on 26/08/2025.
//

#ifndef SOBRECARGA_LECTURA_ESCRITURA_REVIEWS_HPP
#define SOBRECARGA_LECTURA_ESCRITURA_REVIEWS_HPP

#include "Review.hpp"

struct Reviews{
    struct Review reviews[MAX_REVIEW];
    int n_reviews;
    //ESTADISTICAS DE COMENTARIOS
    int n_negative;
    int n_positive;
    int n_neutral;
};

#endif //SOBRECARGA_LECTURA_ESCRITURA_REVIEWS_HPP