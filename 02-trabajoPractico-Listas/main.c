#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"

#define TAMANIO  100

Lista listaAleatoria(int n) {
    Lista l = l_crear();
int i;
    for ( i = 0; i < n; i++) {
        l_agregar(l, te_crear(rand() % 50));
    }

    return l;
}

Lista rellenarLista(int n) {
    Lista l = l_crear();
int i ;
    for ( i = 0; i < n; i++) {
        int val = leerEntero("Ingrese valor: ");
        l_agregar(l, te_crear(val));
    }

    return l;
}

int main() {
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("2 - Operaciones con listas aleatorias\n");
        printf("3 - Multiplo\n");
        printf("4 - Comparar listas\n");
        printf("5 - Polinomio\n");
        printf("6 - Sublista\n");
        printf("0 - Salir\n");

        opcion = leerEntero("Opcion: ");

        if (opcion == 2) {

            int n = leerEntero("Cantidad de elementos tiene que ser mayor 0 y menor o igual a 100: ");
              while(n> TAMANIO ||n<=0){
                    printf("Error:  tiene que ser un numero mayor que cero y menor o igual a 100\n");

                 n = leerEntero("Cantidad de elementos tiene que ser mayor 0 y menor o igual a 100:  ");
                }

            Lista l1 = listaAleatoria(n);
            Lista l2 = listaAleatoria(n);

            printf("\nL1:\n"); l_mostrar(l1);
            printf("\nL2:\n"); l_mostrar(l2);

            int subopcion;

            do {
                printf("\n--- SUBMENU LISTAS ---\n");
                printf("1 - L1 - L2\n");
                printf("2 - L2 - L1\n");
                printf("3 - Interseccion\n");
                printf("4 - Promedio\n");
                printf("5 - Valor minimo\n");
                printf("0 - Volver\n");

                subopcion = leerEntero("Opcion: ");

                switch (subopcion) {

                    case 1:
                        printf("\nL1 - L2:\n");
                        l_mostrar(verElementosQueNoSeRepiten(l1, l2));
                        break;

                    case 2:
                        printf("\nL2 - L1:\n");
                        l_mostrar(verElementosQueNoSeRepiten(l2, l1));
                        break;

                    case 3:
                        printf("\nInterseccion:\n");
                        l_mostrar(verElementosRepetidos(l1, l2));
                        break;

                    case 4: {
                        int cual = leerEntero("Promedio de que lista? (1 o 2): ");
                        float r;

                        if (cual == 1) {
                            r = promedio(l1);
                            printf("Promedio L1 = %.2f\n", r);
                        } else if (cual == 2) {
                            r = promedio(l2);
                            printf("Promedio L2 = %.2f\n", r);
                        } else {
                            printf("Opcion invalida\n");
                        }
                        break;
                    }

                    case 5: {
                        ResultadoValorMinimo min = valorMinimo(l1, l2);
                        printf("Minimo Lista 1: %d Pos %d\n", min.valor, min.pos);
                        printf("Minimo Lista 2: %d Pos %d\n", min.valor_2, min.pos_2);
                        break;
                    }

                    case 0:
                        break;

                    default:
                        printf("Opcion invalida\n");
                }

            } while (subopcion != 0);
        }

        else if (opcion == 3 || opcion == 4) {
            int n = leerEntero("Cantidad de elementos(misma longitud) tiene que ser mayor 0 y menor o igual a 100: ");
                    while(n > TAMANIO || n<=0){
                    printf("Error:  tiene que ser un numero mayor que cero y menor o igual a 100\n");
                   // n=0;
                 n = leerEntero("Cantidad de elementos tiene que ser mayor 0 y menor o igual a 100: : ");
                }
            printf("\n--- CARGA LISTA 1 ---\n");
            Lista l1 = rellenarLista(n);

            printf("\n--- CARGA LISTA 2 ---\n");
            Lista l2 = rellenarLista(n);

            if (opcion == 3) {
                ResultadosMul r = multiplo(l1, l2);

                if (r.esMultiplo){
                    printf("Es multiplo.\n");
                    if(r.escalar){
                        printf("Escalar constante: %d\n", r.numEscalar);
                    }else{
                        printf("No tiene escalar constante.\n");
                    }
                }else{
                printf("No tiene  multiplo.\n");
                }

                if(l_buscar(l1, 0)!=NULL){

                    printf("Un elemento de la primera lista es 0, imposibilitando la division.\n");

                }
            }

            else {
                int r = CompararListas(l1, l2);
                int r2 = 0;
                if (r == 1) r2 = 2;
                if (r == 2) r2 = 1;
                if (r != 0){
                    printf("La lista %d es mas grande que la lista %d\n", r, r2);
                }
                else{
                    printf("Ambas listas son iguales\n");
                }
            }
        }

        else if (opcion == 5) {
            Lista polinomio = l_crear();

            hacerPolinomio(polinomio);

            printf("\n=== EVALUAR POLINOMIO ===\n");
            double x = leerDouble("Ingrese valor de x: ");

            float resultado = evaluarPolinomio(polinomio, (float)x);
            printf("Resultado: %.2f\n", resultado);

            printf("\n=== CALCULO EN RANGO ===\n");

            double desde = leerDouble("Desde: ");
            double hasta = leerDouble("Hasta: ");
            double paso  = leerDouble("Paso: ");

            Lista resultados = calcularRango(polinomio, desde, hasta, paso);

            if (!l_es_vacia(resultados)){
                printf("\nResultados:\n");
            }

            Iterador it = iterador(resultados);
            double val = desde;

            while (hay_siguiente(it)) {
                TipoElemento te = siguiente(it);
                float res = *((float*) te->valor);

                printf("f(%.2f) = %.2f\n", val, res);

                val += paso;
            }
        }

       else if (opcion == 6) {
            int n1 = leerEntero("Cantidad elementos L1 tiene que ser mayor 0 y menor o igual a 100: ");
             while(n1>TAMANIO || n1<=0){
                    printf("Error:  tiene que ser un numero mayor que cero y menor o igual a 100\n");
                   // n=0;
                 n1 = leerEntero("Cantidad elementos L1 tiene que ser mayor 0 y menor o igual a 100: : ");
                }
            int n2 = leerEntero("Cantidad elementos L2 tiene que ser mayor 0 y menor o igual a 100: : ");
             while(n2 > TAMANIO || n2<0){
                    printf("Error:  tiene que ser un numero mayor que cero valor menor o igual a 100\n");
                   // n=0;
                 n2 = leerEntero("Cantidad elementos L2 tiene que ser mayor 0 y menor o igual a 100: : ");
                }

            printf("\n--- CARGA LISTA 1 ---\n");
            Lista l1 = rellenarLista(n1);

            printf("\n--- CARGA LISTA 2 ---\n");
            Lista l2 = rellenarLista(n2);

            if (esSublista(l1, l2)) {
                printf("L2 es sublista de L1\n");
            } else {
                printf("L2 NO es sublista de L1\n");
            }
        }





    } while (opcion != 0);

    return 0;
}
