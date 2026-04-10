#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"
//Funciones de gestion de datos

void aut(char **output) {
    int i;
    for ( i = 0; i < 100; i++) {
        output[i] = malloc(200);
        output[i][0] = '\0';
    }
}
//----- funcion para liberar datos ------------
void liberaMemoria(char **output){
    int i;
    for (i = 0; i < 100; i++)
        free(output[i]);
}
//----- funcion de cargar datos ------------
int cargaDeDatos(int *a) {
    //---- variables---
    int tam = 0;
    char num[100]; // variable para guardar entrada
    long num2;
    char *cade;
    int encontrado;

    printf("Ingresa numeros naturales (usa -1 para terminar):\n");
    while (1) {
        fgets(num, 100, stdin);//con fgets se controla la input.
        num[strlen(num)-1] = '\0';//strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice
        trim(num);// quita los espacio en blanco en el inicio y final
        if (strcmp(num, "-1") == 0) break;
         if (!esNumero(num)) { // controla si es numero
            printf("Error: entrada invalida.\n");

            continue; // vuelve a pedir
        }
        num2 = strtol(num, &cade, 10);
         if(num2<=0){
             printf("Entrada invalida.\n");
             continue;
        }
        if (num2 >= INT_MAX) { printf("Numero demasiado grande.\n"); continue; } // aca se controla que el numero no se mayor de un tipo int en decimal
//-- aca se controla si no es repetido---
        encontrado = 0;
        int i;
        for (i = 0; i < tam; i++)
            if (a[i] == (int)num2) encontrado = 1;

        if (!encontrado) a[tam++] = (int)num2;
        else printf("No se permiten numeros repetidos\n");

        if (tam >= 100) break;
    }

    printf("Ingresaste %d numeros:\n", tam);
    int i;
    for (  i = 0; i < tam; i++) printf("%d ", a[i]);
    printf("\n");
    return tam;
}

void imprimir_explosion(int result[]) {
    printf("[");
    int i = 0;
    while (result[i] != 0) {
        printf("%d ", result[i]);
        i++;
    }
    printf("]\n");
}


int main() {
    char entrada[100];
    int opcion_principal = 0;
    int sub_opcion=0;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ejercicio 1: Palindromo\n");
        printf("2. Ejercicio 2: Producto\n");
        printf("3. Ejercicio 3: Serie de Fibonacci\n");
        printf("4. Ejercicio 4: Division\n");
        printf("5. Ejercicio 5: Separador de Miles\n");
        printf("6. Ejercicio 6: Reunion Mafia\n");
        printf("7. Ejercicio 7: Onda Digital\n");
        printf("8. Ejercicio 8: Subconjuntos que suman N\n");
        printf("9. Ejercicio 9: Divisible por 7\n");
        printf("10. Ejercicio 10: Explosion de numeros\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
          fgets(entrada, sizeof(entrada), stdin);//con fgets se controla la input.
          entrada[strcspn(entrada, "\n")] = '\0';//strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice

          trim(entrada);// quita los espacio en blanco en el inicio y final

      //  scanf("%s", entrada);
        if (esNumero(entrada)) opcion_principal = atoi(entrada);//se contola si es un numero
        else { printf("Entrada invalida.\n"); continue; }

        switch (opcion_principal) {
            case 1: {
                char cadena[100];
                leerCadena("Ingrese cadena: ", cadena);

                printf(palindromo(cadena) ? "Es palindromo\n" : "No es palindromo\n");
                break;
            }

            case 2: {
                int A = leerEntero("Ingrese A: ");

                int B = leerEntero("Ingrese B: ");



                printf("Resultado: %d\n", producto(A, B));
                break;
            }

            case 3: {
                int n = leerEntero("Ingrese n (>=0): ");

                while (n < 0) {
                    printf("Error: n debe ser >= 0\n");
                    n = leerEntero("Ingrese n: ");// llamo a leer un numero
                }

                printf("Resultado: %d\n", terminoSerieFibonacci(n));// se imprime el resultado
                break;
            }

            case 4: {
                int m = leerEntero("Dividendo: "); // llamo a leer un numero
                int n = leerEntero("Divisor (!=0): ");// llamo a leer un numero
                int p = leerEntero("Precision (>=0): ");// llamo a leer un numero

                while (n == 0) {
                    printf("Error: no se puede dividir por cero\n");
                    n = leerEntero("Divisor: ");
                }

                while (p <=0 || p>10) {
                    printf("Error: precision invalida\n");
                    p = leerEntero("Precision: ");
                }

                float resultado = division(m, n, p);


                printf("Resultado: %.*g\n", p+1, resultado);
                break;
            }

            case 5: {
                char num[100];

                do {
                    printf("Ingrese numero (solo digitos): ");
                    fgets(num, sizeof(num), stdin);// se obtiene entrada
                    trim(num);// quita los espacio en blanco en el inicio y final

                    if (tieneEspaciosInternos(num)) {
                        printf("Error: no se permiten espacios\n");
                        continue;
                    }

                    if (!esNumero(num)) {
                        printf("Error: solo se permiten digitos\n");
                    }

                } while (!esNumero(num) || tieneEspaciosInternos(num));

                char* res = agregarSeparadorMiles(num);
                printf("Resultado: %s\n", res);
                free(res);
                break;
            }

            case 6: {
                int nivel = leerEntero("Nivel (>=1 y <=100): ");

                while (nivel < 1 || nivel >=100) {
                    printf("Error: nivel invalido\n");
                    nivel = leerEntero("Nivel: ");
                }

                char* res = reunionMafia(nivel);
                printf("%s\n", res);
                free(res);
                break;
            }

            case 7: {
                char senial[1000];

                do {
                    printf("Ingrese senial (solo H/L): ");
                    fgets(senial, sizeof(senial), stdin);
                    trim(senial); // quita los espacio en blanco en el inicio y final

                    if (tieneEspaciosInternos(senial)) {
                        printf("Error: no se permiten espacios\n");
                        continue;
                    }

                    if (!esSenialValida(senial)) {
                        printf("Error: solo se permiten H y L\n");
                    }

                } while (!esSenialValida(senial) || tieneEspaciosInternos(senial));

                char* res = ondaDigital(senial);
                printf("%s\n", res);
                free(res);
                break;
            }
            case 8: {
                // --- Submenu Ejercicio 8 ---
                int a[100], tam = 0, n = 0, sub_opcion;
                char *output[100];

                do {
                    printf("\n--- Ejercicio 8 ---\n");
                    printf("1. Cargar conjunto de numeros\n");
                    printf("2. Elegir numero objetivo\n");
                    printf("3. Generar subconjuntos\n");
                    printf("4. Volver al menu principal\n");
                    printf("Seleccione una opcion: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0'; //strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice para truncar entrada
                    trim(entrada);// quita los espacio en blanco en el inicio y final
                    if (esNumero(entrada)) {//se contola si es un numero
                            sub_opcion = atoi(entrada);
                            } else {
                        printf("Entrada invalida.\n");
                        sub_opcion = 0; // fuerza default
                        }
                    switch (sub_opcion) {
                        case 1: tam = cargaDeDatos(a); break; /// se llama a cargar datos
                        case 2:
                            if (tam > 0) {
                                printf("Ingrese numero objetivo: ");

                              fgets(entrada, sizeof(entrada), stdin);
                               entrada[strcspn(entrada, "\n")] = '\0';
                                trim(entrada);
                                if (esNumero(entrada)) n = atoi(entrada);//se contola si es un numero

                                else printf("Entrada invalida.\n");
                            } else printf("Primero carga los numeros.\n");
                            break;
                        case 3:
                            if (tam > 0 && n > 0) { // se controla tamanio
                                aut(output);
                                subconjuntosQueSumanN(a, tam, n, output);
                                liberaMemoria(output);
                                tam = 0; n = 0;
                            } else printf("Faltan datos o numero objetivo.\n");
                            break;
                        case 4: break;
                        default: printf("Opcion invalida.\n");
                    }
                } while (sub_opcion != 4);
            } break;

            case 9: {
                // --- Submenu Ejercicio 9 ---
                long num;
                bool resultado;
                int sub_opcion;
                do {
                    printf("\n--- Ejercicio 9 ---\n");
                    printf("1. Cargar numero para saber si es divisible por 7\n");
                    printf("2. Volver al menu principal\n");
                    printf("Seleccione una opcion: ");

                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';//strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice
                    trim(entrada);// quita los espacio en blanco en el inicio y final
                    if (esNumero(entrada)) {//se contola si es un numero
                            sub_opcion = atoi(entrada);
                            } else {
                        sub_opcion = 0; // fuerza default
                        }
                    if (sub_opcion == 1) {
                        printf("Ingrese numero: ");

                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';//strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice
                    trim(entrada);// quita los espacio en blanco en el inicio y final

                       //  scanf("%s", entrada);
                        if (esNumero(entrada)) {//se contola si es un numero
                            num = strtol(entrada, NULL, 10);//transformo la entrada a numero.
                            if (limiteSup(num)) continue;//controlo el limite del numero
                            resultado = divisiblePor7((int)num);
                            printf("%s\n", resultado ? "Es divisible por 7" : "No es divisible por 7");
                        } else printf("Entrada invalida.\n");
                    } else if (sub_opcion == 2) break;
                    else printf("Opcion invalida.\n");
                } while (1);
            } break;

            case 10: {
                // --- Submenu Ejercicio 10 ---
                //----Variables---
                int n1 = 0, n2 = 0;
                int bandera1 = 0, bandera2 = 0;
                int sub_opcion;
                //--- sub Menu--
                do {
                    printf("\n--- Ejercicio 10 ---\n");
                    printf("1. Cargar numero explosivo\n");
                    printf("2. Cargar numero bomba\n");
                    printf("3. Calcular explosion\n");
                    printf("4. Volver al menu principal\n");
                    printf("Seleccione una opcion: ");
                    fgets(entrada, sizeof(entrada), stdin);
                       entrada[strcspn(entrada, "\n")] = '\0';//strcspn me la ultima posicion donde aparece "\n" y lo utilizo como indice
                           trim(entrada);// quita los espacio en blanco en el inicio y final
                    if (!esNumero(entrada)) continue;
                    sub_opcion = atoi(entrada);

                    switch (sub_opcion) {
                        case 1:
                            n1 = leerNatural("Ingresar numero explosivo: "); bandera1 = 1;// llamo a leer un numero

                            break;
                        case 2:
                            n2 = leerNatural("Ingrese numero bomba: "); bandera2 = 1;// llamo a leer un numero
                            break;
                        case 3:
                            if (bandera1 && bandera2) {
                                int *res = explosion(n1, n2);
                                imprimir_explosion(res);
                                free(res);
                            } else printf("Faltan cargar los numeros.\n");
                            break;
                        case 4: break;
                        default: printf("Opcion invalida.\n");
                    }
                } while (sub_opcion != 4);
            } break;

            case 0: printf("Saliendo del programa.\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion_principal != 0);

    return 0;
}
