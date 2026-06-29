#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <ctype.h>
#include "tp_thash.h"

int funcionHash(int clave) {
    return clave % valorModulo;
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void main4(){
    cantidad = 2000;
    valorModulo = encontrarPrimoMasCercano(cantidad);

    TablaHash tabla = th_crear(cantidad, &funcionHash);
    FILE * archivo = fopen("archivo.bin", "wb+");
    
    procesarMenu(archivo, tabla);

    fclose(archivo);
    
    return;

}

void main5(){
    int q_claves;
    bool cantidadClavesCorrecta = false;
    while (!cantidadClavesCorrecta) {
        printf("[INPUT] Cuantas claves desea generar (1-2000): ");
        if (scanf("%i", &q_claves) > 0 && q_claves >= 1 && q_claves <= 2000) {
            cantidadClavesCorrecta = true;
        } else {
            printf("[ERROR] Debe ingresar un numero de claves que se encuentre entre 1 y 2000.\n");
            fflush(stdin);
        }
    }

    bool cantidadRepeticionesCorrecta = false;
    int q_repeticiones;
    while (!cantidadRepeticionesCorrecta) {
        printf("[INPUT] Cuantas repeticiones desea hacer: ");
        if (scanf("%i", &q_repeticiones) > 0) {
            cantidadRepeticionesCorrecta = true;
        } else {
            printf("[ERROR] Debe ingresar un numero para las repeticiones.\n");
            fflush(stdin);
        }
    }

    int rango_desde, rango_hasta;
    bool intervaloCorrecto = false;
    while (!intervaloCorrecto) {
        bool minimoCorrecto = false;
        while (!minimoCorrecto) {
            printf("[INPUT] Ingrese el minimo del intervalo para generar las claves: ");
            if (scanf("%i", &rango_desde) > 0) {
                minimoCorrecto = true;
            } else {
                printf("[ERROR] Debe ingresar un numero minimo para el intervalo.\n");
                fflush(stdin);
            }
        }

        bool maximoCorrecto = false;
        while (!maximoCorrecto) {
            printf("[INPUT] Ingrese el maximo del intervalo para generar las claves: ");
            if (scanf("%i", &rango_hasta) > 0 && rango_hasta > rango_desde) {
                maximoCorrecto = true;
            } else {
                printf("[ERROR] Debe ingresar un numero maximo para el intervalo, mayor que el numero minimo ya ingresado.\n");
                fflush(stdin);
            }
        }

 
        if ((rango_hasta - rango_desde + 1) >= q_claves) {
            intervaloCorrecto = true;
        } else {
            printf("[ERROR] El intervalo definido no permite generar %d claves únicas. Aumente el rango o disminuya la cantidad de claves.\n", q_claves);
        }
    }

    valorModulo = encontrarPrimoMasCercano(q_claves);
    ArbolAVL A = avl_crear();
    TablaHash thash = th_crear(q_claves, &funcionHash);

    long long totalTiempoArbol = 0;
    long long totalTiempoTabla = 0;
    
    th_ej5_comparacion(A, thash, q_claves, q_repeticiones, rango_desde, rango_hasta, &totalTiempoTabla, &totalTiempoArbol);

    float promedioTiempoArbol = totalTiempoArbol / (float) q_repeticiones;
    float promedioTiempoTabla = totalTiempoTabla / (float) q_repeticiones;

    printf("\n[OUTPUT] El promedio de tiempo de ejecucion del arbol es %.1f nanosegundos.\n", promedioTiempoArbol);
    printf("[OUTPUT] El promedio de tiempo de ejecucion de la tabla hash es %.1f nanosegundos.\n", promedioTiempoTabla);

    if (promedioTiempoTabla < promedioTiempoArbol){
        printf("[CONCLUSION] La Tabla Hash obtuvo un menor tiempo promedio de acceso que el Arbol AVL.\n");
    }
    else if (promedioTiempoTabla > promedioTiempoArbol){
        printf("[CONCLUSION] El Arbol AVL obtuvo un menor tiempo promedio de acceso que la Tabla Hash.\n");
    }
    else{
        printf("[CONCLUSION] Ambas estructuras obtuvieron el mismo tiempo promedio de acceso.\n");
}

    return;
}

int funcionHash6(int clave){
    return (clave % NRO_PRIMO);
}

void mostrarmenu(){
    printf("\n----------MENU----------\n 1 - Cargar nueva persona vacunada.\n 2 - Recuperar persona vacunada por fecha.\n 3 - Salir.\n");
    return;
}

void main6(){
    TablaHash tablita = th_crear(MAX, &funcionHash6);
    
    bool agregar = true;
    int clave;
    while (agregar){

        mostrarmenu();
        if(scanf("%d", &clave) > 0 && clave >= 1 && clave <= 3){
            limpiar_buffer();
            switch (clave){
                case 1:{
                    th_ej6_covid(tablita, 1);
                    break;
                }
                case 2:{
                    th_ej6_covid(tablita, 2);
                    break;
                }
                case 3:{
                    agregar = false;
                    break;
                }
                default:{
                    printf("[ERROR] Debe ingresar una opcion valida.\n");
                }
                
            }
        }
    }
    return;

}

int main(){
    int opcion;

    do {
        printf("\n--- Menu de Opciones ---\n");
        printf("1. salir\n");
        printf("2. Ejercicio 4 (Submenu) \n");
        printf("3. Ejercicio 5 (Submenu) \n");
        printf("4. Ejercicio 6 (Submenu) \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                break;
            case 2:
                main4();
                return 0;
                break;
            case 3:
                main5();
                return 0;
                break;
            case 4:
                main6();
                return 0;
                break;
            default:
                break;
        }

    }while(opcion != 4);

    return 0;
}
