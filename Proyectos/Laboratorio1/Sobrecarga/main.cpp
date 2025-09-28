#include "Librerias/Funciones.hpp"
//OPERADORES SOBRECARGADOS

/**/

int main() {
    // unsigned int q = 0;
    // cout << q++ << " " << q++ << endl;
    // cout << q << " " << q++ << endl;
    // cout << q++ << " " << q << endl;
    // cout << ++(q += ++q) << " " << ++ ++q << endl;
    // return 0;

    struct Vector2D V1;
    struct Vector2D V2;
    struct Vector2D V3;
    cout<<"V1 : "<<endl;
    llenarVector(V1);
    cout<<"V2 : "<<endl;
    llenarVector(V2);
    //Operadores matematicos

    V3 = V1+V2;
    cout<<"V3 : "<<endl;
    cout<<V3.x<<" "<<V3.y<<endl;
}
