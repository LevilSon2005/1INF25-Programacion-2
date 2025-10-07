//
// Created by binny on 30/09/2025.
//

#include "BibliotecaGenerica.hpp"

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (not input.is_open()) {
        cout << "Error abriendo el archivo! : " << name << endl;
    }else
        cout<<" El archivo se abrio: " << name << endl;
}


void apertura_escritura(ofstream &output, const char* name) {
    output.open(name, ios::out);
    if (not output.is_open()) {
        cout << "Error abriendo el reporte! : " << name << endl;
    }else
        cout<<" El reporte se abrio: " << name << endl;
}

bool esListaVacia(const void* lista){
    void** lista_2= (void**)lista;
    return (lista_2[INICIO] == nullptr and lista_2[FIN]== nullptr);
}

/*Para crear lista: inicializar -- leer -- crear nuevo nodo -- insertar */
void crearLista(const char *name, void *&lista_pedido, void *(*leer)(ifstream &)) {
    ifstream input;
    apertura_lectura(input, name);

    //INICIALIZAMOS LISTA -  reservamos memoria para tener INICIO y FINAL
    generarLista(lista_pedido);
    void* dato;
    while (true) {
        dato = leer(input);
        if (input.eof()) break;
        // cout<<*(int*)dato<<endl;
        insertar(dato, lista_pedido);
    }
}

//para que la dirección de memoria del arreglo donde reservamos memoria se mantenga
//lista_pedido es necesario mandarlo con &
void generarLista(void *&lista_pedido) {
    void** lista ;
    lista = new void*[2]{};
    lista[INICIO] = nullptr;
    lista[FIN] = nullptr;
    /*Le damos a lista_pedido la direccion del arreglo de lista que si tiene memoria
     * y espacios ya reservado. Asi que ahora si puede acceder */
    lista_pedido = lista; //reservaste memoria  en lista e inicialista ahi tambie


    /*//TAMBIEN SE PODRIA HACER
    lista_pedido = new void*[2]{}; //hacemos que apunte a un arreglo que ya tiene memoria
    void** aux = (void**)lista; //aterrizamos para poder asignar su INICIO y FIN
    aux[INICIO] = nullptr;
    aux[FIN] = nullptr;
    //Ya no se hace     lista_pedido =  aux   porque accediste de manera directa
    a la memora de lista_pedido y modificaste el mismo lista_pedido*/

}

//insertar al final
//CREAMOS NODO  - INSERTAMOS
void insertar(void *dato, void *&lista_pedido) {

    void** lista = (void**)lista_pedido;
    cout<<"Insertar: "<<*(int*)dato<<endl;

    //CREAMOS NODO
    void** nodo = new void*[2]{};
    nodo[DATO] = dato;
    nodo[SIGUIENTE] = nullptr;

    if (esListaVacia(lista)) {//el primer nodo, lista vacia
        lista[INICIO] = nodo;
        lista[FIN]= nodo;
    }
    else {//a partir del segundo, lista no vacia
        void** ultimo = (void**)lista[FIN];
        ultimo[SIGUIENTE] = nodo;
        lista[FIN] = nodo;
    }
    cout<<"Nodo: "<<*(int*)nodo[DATO]<<endl;
}

void imprimirLista(const char* name,const void *lista_pedido, void(*imprimir)(const void *, ofstream &)) {
    ofstream output;
    apertura_escritura(output, name);
    void** lista = (void**)lista_pedido;
    void** recorrido = (void**)lista[INICIO];
    // void** recorrido = (void**)lista_pedido;  INCORRECTOOOOOO
    while (recorrido) {
        cout<<*(int*)recorrido[DATO]<<endl;
        imprimir(recorrido[DATO], output); //imprime un dato
        recorrido =(void**)recorrido[SIGUIENTE];
    }
}

//crea un nuevo nodo para la lista combinada y elimino el nodo de la lista original
void* quitar_nodo(void* &lista) {
    void** nodo,*dato;
    void** casteo_lista = (void**)lista;
    nodo = (void**)casteo_lista[INICIO]; //
    dato = nodo[DATO];
    casteo_lista[INICIO] = nodo[SIGUIENTE];

    //el final solo lo actualizo cuando ya está saca el ultimo y de ahi sig vacio
    if (casteo_lista[INICIO] == nullptr) casteo_lista[FIN] = nullptr;
    delete nodo;
    return dato;
}

void combinaLista(void *pedidos1, void *pedidos2, void *&pedidos_combinados,
                  int(*comparar)(void *, void *)) {
    void **lista1 = (void **) pedidos1;
    void **lista2 = (void **) pedidos2;
    generarLista(pedidos_combinados);
    void* nuevo_dato;

    while (not esListaVacia(lista1) and not esListaVacia(lista2)) {
        void **inicio1 = (void **) lista1[INICIO];
        void **inicio2 = (void **) lista2[INICIO];
        int comparacion = comparar(inicio1[DATO], inicio2[DATO]);
        if (comparacion > 0) {
            nuevo_dato= quitar_nodo(pedidos1);
        }else if (comparacion < 0) {
            nuevo_dato= quitar_nodo(pedidos2);
        }else {
            nuevo_dato = quitar_nodo(pedidos1);
            nuevo_dato = quitar_nodo(pedidos2);
        }
        void* dato = nuevo_dato;
        //la funcion insertar es un insertar ordenado, aqui mismo se crea memoria
        //y se evalua los casos si es primero, final, o etc
        insertar(dato, pedidos_combinados);
    }
    void** casteo_combinado = (void**)pedidos_combinados;
    while (not esListaVacia(pedidos1)) {
        void* dato = quitar_nodo(pedidos1);
        insertar(dato, pedidos_combinados);
    }
    while (not esListaVacia(pedidos2)) {
        void* dato = quitar_nodo(pedidos2);
        insertar(dato, pedidos_combinados);
    }
}


