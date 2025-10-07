#include "src/BibliotecaEnteros.hpp"
#include "src/BibliotecaGenerica.hpp"

/* 1. CREA FUNCIONES PARA CREAR LISTA DE PEDIDOS, PRIMERO CON SOLO INT
 * GENERA DOS LISTAS, IMPRIME CADA UNA Y LUEGO COMBINA CON SU RESPECTIVA IMPRESIÓN
 *
 * NOTA: Al momento de insertar uno va a ser al final, otro al inicio y luego para
 * combinar se ordena(ahi recién utilizamos comparación)
 */
int main() {
    void* pedido1, *pedido2, *pedido_combinado;
    crearLista("Data/RegistroNum1.txt", pedido1,
                leer_dato_int);
    imprimirLista("Reporte/Reporte_num.txt", pedido1, imprimir_nodo_int);
    crearLista("Data/RegistroNum2.txt", pedido2,
                leer_dato_int);
    imprimirLista("Reporte/Reporte_num2.txt", pedido2, imprimir_nodo_int);
    // combinaLista(pedido1, pedido2, pedido_combinado, comparar_int);
    return 0;
}

// lee nodo, insertar(comparar)


/*APRENDIDO:
 *
 * No podemos castear una misma variable asignandole el mismo nombre, es decir
 * si paso por parametro lista, no se puede hacer esto
 *
 * funcion(void* &lista){
 *      lista = (void**)lista;
 * }
 */