
#include "src/FuncionesAux.hpp"
#include "src/Sobrecarga.hpp"
#include "src/Reviews.hpp"

/*Descripcion: Esta aplicacion lee los comentarios acerca de un restuarante y
 * procesa los datos resultando en un mini-reporte con las estadìsticas
 */

int main() {
    struct Reviews reviews{};
    reviews.n_reviews = 0; //por siaca, porque con los {} ya basta

    "Data/reviews.csv">>reviews;


    return 0;
}