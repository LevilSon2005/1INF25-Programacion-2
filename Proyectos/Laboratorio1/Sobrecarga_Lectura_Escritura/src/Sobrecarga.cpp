//
// Created by binny on 26/08/2025.
//

#include "Sobrecarga.hpp"



// input>>review;
void operator>>(ifstream &input, struct Review& review) {
    review.fecha = read_fecha(input);
    input.get();
    input.getline(review.comentario, COMENTARIO_SIZE,',');
    input>>review.calificacion;
    input.get();

    cout<<"Termino la lectura"<<endl;
}

// "data/reviews.txt">>reviews;
void operator>>(const char* name, struct Reviews &reviews) {
    ifstream input;
    open_read(input, name);
    struct Review review{};
    while(true){
        input>>review;
        if (input.eof()) break;
        reviews.reviews[reviews.n_reviews] = review;
        reviews.n_reviews++;
    }
}