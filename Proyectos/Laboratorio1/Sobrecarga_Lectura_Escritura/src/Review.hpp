//
// Created by binny on 26/08/2025.
//

#ifndef SOBRECARGA_LECTURA_ESCRITURA_REVIEW_HPP
#define SOBRECARGA_LECTURA_ESCRITURA_REVIEW_HPP

#include "Utils.hpp"

struct Review {
    int fecha;
    char comentario[COMENTARIO_SIZE]{};
    double calificacion;
};
#endif //SOBRECARGA_LECTURA_ESCRITURA_REVIEW_HPP