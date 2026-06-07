#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../libs/colas/headers/colas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_colas.h"

void cargarPilaManual(Pila p){
    int cantidad = leerEntero("Ingrese cantidad de elementos de pila (Entre 0 y 100): ");
    while(cantidad > 100 || cantidad < 0){
        printf("Error, usted ha ingresado un numero fuera de los limites\n");
        cantidad = leerEntero("Ingrese cantidad de elementos (Entre 0 y 100): ");
    }
    int i;
    for(i = 0; i < cantidad; i++){
        int valor;
        printf("Elemento %d\n",i+1);
        valor = leerEntero("Ingrese valor: ");
        p_apilar(p,te_crear(valor));
    }
}
Cola crearCola() {
    Cola c = c_crear();

    int cantidad = leerEntero("Cantidad de elementos de la Cola (0-100): ");

    while(cantidad < 0 || cantidad > 100) {
        printf("\nLa cantidad de elementos solo puede estar entre 0 y 100\n");
        cantidad = leerEntero("Cantidad de elementos (0-100): ");
    }
    int i;
    for ( i = 1; i <= cantidad; i++) {
        int valor;
        printf("Elemento %d\n", i);
        valor = leerEntero("Ingrese clave: ");
        TipoElemento te = te_crear(valor);
        c_encolar(c, te);
    }

    return c;
}

Pila crearPila() {
    Pila p = p_crear();
    int cantidad = leerEntero("Cantidad de elementos (0-100): ");
    while (cantidad < 0 || cantidad > 100) {
        printf("\nLa cantidad de elementos solo puede estar entre 0 y 100\n");
        cantidad = leerEntero("Cantidad de elementos (0-100): ");
    }
    int i;
    for (  i = 1; i <= cantidad; i++) {
        int valor;
        printf("Elemento %d\n", i);
        valor = leerEntero("Ingrese clave: ");
        TipoElemento te = te_crear(valor);
        p_apilar(p, te);
    }
    return p;
}

void mostrarListaValores(Lista l) {
    Iterador it = iterador(l);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        printf("%d%s\n", te->clave,(char*)te->valor);
    }
}

void mostrarColaClientes(Cola c) {
    Cola aux = c_crear();
    while (!c_es_vacia(c)) {
        TipoElemento te = c_desencolar(c);
        printf("%s\n", (char*)te->valor);
        c_encolar(aux, te);
    }
    while (!c_es_vacia(aux)) {
        c_encolar(c, c_desencolar(aux));
    }
}

void menuEjercicio2() {

    int opcion;

    do {

        printf("\n============================");
        printf("\n      EJERCICIO 2");
        printf("\n============================");
        printf("\n1 - Existe clave");
        printf("\n2 - Colar elemento");
        printf("\n3 - Sacar elemento");
        printf("\n4 - Contar elementos");
        printf("\n5 - Copiar cola");
        printf("\n6 - Invertir cola");
        printf("\n0 - Volver");
        printf("\n============================\n");

        opcion = leerEntero("Opcion: ");

        switch(opcion) {

            case 1: {
                Cola c = crearCola();

                int clave = leerEntero("Clave a buscar: ");

                if(c_ej2_existeclave(c, clave)){
                    printf("\nLa clave existe.\n");
                }else{
                    printf("\nLa clave NO existe.\n");
                }
                printf("\nCola Original\n");
                c_mostrar(c);
                break;
            }

            case 2: {
                Cola c = crearCola();

                int pos = leerNatural("Posicion ordinal: ");
                int clave = leerEntero("Clave del nuevo elemento: ");

                TipoElemento te = te_crear(clave);

                Cola resultado = c_ej2_colarelemento(c, pos, te);

                printf("\nElemento insertado.\n");

                printf("\nCola Resultado\n");
                c_mostrar(resultado);

                printf("\nCola Original\n");
                c_mostrar(c);

                break;
            }

            case 3: {
                Cola c = crearCola();

                int clave = leerEntero("Clave a eliminar: ");

                Cola resultado = c_ej2_sacarelemento(c, clave);

                printf("\nCola Resultado\n");
                c_mostrar(resultado);

                printf("\nCola Original\n");
                c_mostrar(c);

                break;
            }

            case 4: {
                Cola c = crearCola();

                int cantidad = c_ej2_contarelementos(c);

                printf("\nCantidad de elementos: %d\n", cantidad);

                printf("\nCola Original\n");
                c_mostrar(c);

                break;
            }

            case 5: {
                Cola c = crearCola();

                Cola copia = c_ej2_copiar(c);

                printf("\nCola original:\n");
                c_mostrar(c);

                printf("\nCola copia:\n");
                c_mostrar(copia);

                break;
            }

            case 6: {
                Cola c = crearCola();

                Cola invertida = c_ej2_invertir(c);

                printf("\nCola original:\n");
                c_mostrar(c);

                printf("\nCola invertida:\n");
                c_mostrar(invertida);

                break;
            }

        }

    } while(opcion != 0);
}

//========================================================
// MAIN
//========================================================

int main() {

    int opcion;

    do {

        printf("\n=================================");
        printf("\n TP COLAS - MENU PRINCIPAL");
        printf("\n=================================");
        printf("\n2 - Ejercicio 2");
        printf("\n3 - Ejercicio 3");
        printf("\n4 - Ejercicio 4");
        printf("\n5 - Ejercicio 5");
        printf("\n6 - Ejercicio 6");
        printf("\n7 - Ejercicio 7");
        printf("\n0 - Salir");
        printf("\n=================================\n");

        opcion = leerEntero("Seleccione opcion: ");

        switch(opcion) {

            case 2:
                menuEjercicio2();
                break;

            case 3: {

                printf("\n--- EJERCICIO 3 ---\n");

                printf("\nCARGA COLA 1\n");
                Cola c1 = crearCola();

                printf("\nCARGA COLA 2\n");
                Cola c2 = crearCola();

                if(c_ej3_iguales(c1, c2))
                    printf("\nLas colas son iguales.\n");
                else
                    printf("\nLas colas NO son iguales.\n");



                printf("\nLa complejidad algoritmica es O(n) \n");
                printf("\nCola Original 1\n");
                c_mostrar(c1);

                printf("\nCola Original 2\n");
                c_mostrar(c2);
                break;
            }

            case 4: {

                printf("\n--- EJERCICIO 4 ---\n");

                Cola c = crearCola();

                Cola resultado = c_ej4_colanorepetidos(c);

                printf("\nElementos no repetidos:\n");

                c_mostrar(resultado);
                printf("\nLa complejidad algoritmica es O(n^2) \n");
                printf("\nCola Original\n");
                c_mostrar(c);
                break;
            }

            case 5: {

                printf("\n--- EJERCICIO 5 ---\n");

                Cola c = crearCola();

                Cola resultado = c_ej5_divisortotal(c);

                printf("\nDivisores encontrados:\n");

                Cola aux = c_crear();

                while (!c_es_vacia(resultado)) {
                    TipoElemento te = c_desencolar(resultado);
                    int esTotal = *((int*)te->valor);
                    printf("Clave: %d - Tipo: %s\n",   te->clave, esTotal ? "TOTAL" : "PARCIAL");
                    c_encolar(aux, te);
                }
                while (!c_es_vacia(aux)) {
                    TipoElemento te = c_desencolar(aux);
                    c_encolar(resultado, te);
                }
                printf("\nLa complejidad algoritmica es O(n^2) \n");
                printf("\nCola Original\n");
                c_mostrar(c);
                break;
            }

            case 6: {

                printf("\n--- EJERCICIO 6 ---\n");
                Pila p = p_crear();
                cargarPilaManual( p);
                printf("\nPila Original\n");
                p_mostrar(p);
                printf("\n");
                Cola c = crearCola();
                printf("\nCola Original\n");
                c_mostrar(c);
                printf("\n");
                Lista resultado = c_ej6_comunesapilaycola(p, c);
                printf("\nValores encontrados:\n");
                mostrarListaValores(resultado);
                printf("\n");
                printf("\nLa complejidad algoritmica es O(n^2) \n");
                printf("\n");
                printf("\nPila Original\n");
                p_mostrar(p);
                printf("\n");
                printf("\nCola Original\n");
                c_mostrar(c);
                break;
            }

            case 7: {

                printf("\n--- EJERCICIO 7 ---\n");

                printf("\nCOLA 1\n");
                Cola c1 = crearCola();

                printf("\nCOLA 2\n");
                Cola c2 = crearCola();

                printf("\nCOLA 3\n");
                Cola c3 = crearCola();

                int q = leerNatural("Tiempo de atencion (Q): ");

                Cola resultado = c_ej7_atenderclientes(c1, c2, c3, q);

                printf("\nOrden de atencion:\n");
                mostrarColaClientes(resultado);
                printf("\nLa complejidad algoritmica es O(n) \n");
                break;
            }

            case 0:
                printf("\nFin del programa.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}
