//
// Created by binny on 26/08/2025.
//

#include "FuncionesAux.hpp"

void open_read(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (not input.is_open()){
        cout<<"El archivo "<<name<< "no se abrio"<<endl;
        exit(1);
    }
    else
        cout<<"El archivo "<<name<< "se abrio"<<endl;

}
void open_write(ofstream &ouput, const char* name) {
    ouput.open(name, ios::out);
    if (not ouput.is_open()) {
        cout<<"El archivo "<<name<< "no se abrio"<<endl;
        exit(1);
    }
    else
        cout<<"El archivo "<<name<< "se abrio"<<endl;
}
char* read_string(ifstream &input, char del){
    char *string, buffer[150];
    input.getline(buffer,150, del);
    string = new char[strlen(buffer)+1];
    strcpy(string, buffer);
    return string;
}

int read_fecha(ifstream &input){
    int d,m,a;

    input>>a;
    input.get();
    input>>m;
    input.get();
    input>>d;

    return a*1000+m*100+d;
}