#include <iostream>
using namespace std;

int suma(int x, int y) {
    return x+y;
}

double promedio(int suma, int n) {
    return (double)suma/n;
}

int main() {
    int x=6, y=7, n=2;
    int (*ptr_suma)(int, int);
    double(*ptr_promedio)(int, int);

    ptr_suma = suma;
    cout<<(void*)ptr_suma<<endl;
    return 0;
}