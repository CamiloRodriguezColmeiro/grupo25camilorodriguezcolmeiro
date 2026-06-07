
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "tp_3_pilas.h"
#include "../libs/validaciones/headers/validaciones.h"

void cargarPilaManual(Pila p){
    int cantidad = leerEntero("Ingrese cantidad de elementos (Entre 0 y 100): ");
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

void cargarPilaRandom(Pila p,int cantidad){
    int i;
    for(i = 0; i < cantidad; i++){
        int valor = rand()%10;
        p_apilar(p,te_crear(valor));
    }
}

void mostrarResultadoBool(bool r){
    if(r){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
}

void submenuEj2(){
    int opcion2;
    do{
        printf("\n====================================\n");
        printf("EJERCICIO 2\n");
        printf("====================================\n");
        printf("1 - 2A Existe clave\n");
        printf("2 - 2B Colocar elemento\n");
        printf("3 - 2C Eliminar clave\n");
        printf("4 - 2D Intercambiar posiciones\n");
        printf("5 - 2E Duplicar pila\n");
        printf("6 - 2F Cantidad elementos\n");
        printf("0 - Volver\n");
        opcion2 = leerEntero("Seleccione opcion: ");
        switch(opcion2){
            case 1:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA:\n");
                p_mostrar(p);
                int clave = leerEntero("Clave a buscar: ");
                bool existe = p_ej2_existeclave(p,clave);
                printf("\nResultado: ");

                if(existe ){
                     printf("\nValor encontrado ");
                }else{
                 printf("\nValor NO encontrado ");
                }
               // mostrarResultadoBool(existe);


                printf("\nPila original:\n");
                p_mostrar(p);
                break;
            }
            case 2:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                int pos = leerNatural("Posicion ordinal: ");
                int valor = leerEntero("Valor nuevo: ");
                Pila nueva = p_ej2_colocarelemento(p, pos, te_crear(valor));
                printf("\nPILA RESULTADO:\n");
                p_mostrar(nueva);
                break;
            }
            case 3:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                int clave = leerEntero("Clave a eliminar: ");
                Pila nueva = p_ej2_eliminarclave(p,clave);
                printf("\nPILA RESULTADO:\n");
                p_mostrar(nueva);
                break;
            }
            case 4:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                int pos1 = leerNatural("Posicion 1: ");
                int pos2 = leerNatural("Posicion 2: ");
                Pila nueva = p_ej2_intercambiarposiciones(p, pos1, pos2);
                printf("\nPILA RESULTADO:\n");
                p_mostrar(nueva);
                break;
            }
            case 5:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                Pila duplicada = p_ej2_duplicar(p);
                printf("\nPILA DUPLICADA:\n");
                p_mostrar(duplicada);
                break;
            }
            case 6:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA:\n");
                p_mostrar(p);
                int cantidad = p_ej2_cantidadelementos(p);
                printf("\nCantidad de elementos: %d\n",cantidad);
                break;
            }
            case 0:
                printf("\nVolviendo al menu principal...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
        }
    }while(opcion2!=0);
}

int main(){
    srand(time(NULL));
    int opcion;
    do{
        printf("\n====================================\n");
        printf("TP PILAS\n");
        printf("====================================\n");
       printf("1 - Ejercicio 2\n");
        printf("2 - Ejercicio 3. Se compara si son iguales dos pilas \n");
        printf("3 - Ejercicio 4. Convertir numero decimal a base binario a Hexadecimal.\n");
        printf("4 - Ejercicio 5. Invertir Pila.\n");
        printf("5 - Ejercicio 6. Eliminar elemento de pila.\n");
        printf("6 - Ejercicio 7. Elementos en comun de las pilas.\n");
        printf("7 - Ejercicio 8. Valores Repetidos de la lista\n");
        printf("0 - Salir\n");
        opcion=leerNatural("Seleccione opcion: ");
        printf("\n");
        switch(opcion){
            case 1:{
                submenuEj2();
                break;
            }
            case 2:{
                Pila p1 = p_crear();
                Pila p2 = p_crear();
                printf("CARGA PILA 1\n");
                cargarPilaManual(p1);
                printf("\nCARGA PILA 2\n");
                cargarPilaManual(p2);
                printf("\nPILA 1:\n");
                p_mostrar(p1);
                printf("\nPILA 2:\n");
                p_mostrar(p2);
                bool iguales = p_ej3_iguales(p1,p2);
                printf("\nResultado: ");
                printf("\nPILA 1:\n");
                p_mostrar(p1);
                printf("\nPILA 2:\n");
                p_mostrar(p2);


                if (p_ej3_iguales(p1,p2) ){
                   printf("Las pilas son iguales.\n");
                        } else {
                                printf("Las pilas no son iguales.\n");
                            }
                printf("La complejidad  algoritmica es O(n).\n");


              //  mostrarResultadoBool(iguales);
                break;
            }
            case 3:{
                int numero = leerEntero("Numero decimal: ");
                int base = leerNatural("Base destino (2-16): ");
                char* convertido = p_ej4_cambiarbase(numero,base);
                printf("\nResultado: %s\n",convertido);
                 printf("La complejidad  algoritmica es O(log n).\n");
                free(convertido);
                break;
            }
            case 4:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                Pila invertida = p_ej5_invertir(p);
                printf("\nPILA INVERTIDA:\n");
                p_mostrar(invertida);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                printf("La complejidad  algoritmica es O(n).\n");
                break;
            }
            case 5:{
                Pila p = p_crear();
                int cantidad = leerEntero("Cantidad random de elementos (0 a 100): ");
                while(cantidad > 100 || cantidad < 0){
                    cantidad = leerEntero("Usted ha excedido los limites de elementos en la pila, inserte un numero valido (0 a 100): ");
                }
                cargarPilaRandom(p,cantidad);
                printf("\nPILA RANDOM:\n");
                p_mostrar(p);
                int clave = leerEntero("\nClave a eliminar:");
                Pila nueva = p_ej6_eliminarclave(p,clave);
                Pila nuevarecursiva = p_ej6_eliminarclave(p,clave);
                printf("\nPILA RESULTADO:\n");
                p_mostrar(nueva);
                printf("\nPILA RESULTADO RECURSIVO:\n");
                p_mostrar(nuevarecursiva);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                printf("La complejidad  algoritmica es O(n) en ambos casos.\n");
                break;
            }
            case 6:{
                Pila p1 = p_crear();
                Pila p2 = p_crear();
                printf("CARGA PILA 1\n");
                cargarPilaManual(p1);
                printf("\nCARGA PILA 2\n");
                cargarPilaManual(p2);
                printf("\nPILA 1:\n");
                p_mostrar(p1);
                printf("\nPILA 2:\n");
                p_mostrar(p2);
                Pila comunes = p_ej7_elementoscomunes(p1,p2);
                printf("\nELEMENTOS COMUNES:\n");
                p_mostrar(comunes);
                  printf("La complejidad  algoritmica es O(n^2).\n");
                break;
            }
            case 7:{
                Pila p = p_crear();
                cargarPilaManual(p);
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                Pila resultado = p_ej8_sacarrepetidos(p);
                printf("\nPILA RESULTADO:\n");
                while(!p_es_vacia(resultado)){
                    TipoElemento x = p_desapilar(resultado);
                    printf("%d:%d, ", x->clave, (int)(long)x->valor);
                }
                if(p_es_vacia(resultado))
                {
                   printf("\nLa pila esta vacia.\n");
                }
                printf("\nPILA ORIGINAL:\n");
                p_mostrar(p);
                printf("La complejidad  algoritmica es O(n^2).\n");
                break;
            }
            case 0:
                printf("\nFin del programa.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }
    }while(opcion!=0);

    return 0;
}
