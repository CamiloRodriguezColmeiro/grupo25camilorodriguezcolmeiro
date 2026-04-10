#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include "tp_1_recursividad.h"

// --- Funciones Ejercicio 1 ---

bool paliAux(char *c, int inicio, int final){
    if (inicio > final){
        return true;
    } else {
        if (tolower(c[inicio]) != tolower(c[final-1])){
            return false;
        } else {
            return paliAux(c, inicio + 1, final - 1);
        }
    }
}

bool palindromo(char *cadena){
    int len = strlen(cadena);
    return paliAux(cadena, 0, len);
}

// --- Funciones Ejercicio 2---

int producto(int n1, int n2) {
    if (n2 == 0 || n1 == 0) {
        return 0;
    } else if (n2 > 0) {
        return n1 + producto(n1, n2 - 1);
    } else {
        // si n2 es negativo, multiplicamos por el valor positivo y cambiamos el signo
        return -producto(n1, -n2);
    }
}

// --- Funciones Ejercicio 3---

int terminoSerieFibonacci(int k) {
    if (k == 0) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    return terminoSerieFibonacci(k - 1) + terminoSerieFibonacci(k - 2);
}

// --- Funciones Ejercicio 4---
int divisionEntera(int n1, int n2){
    if (n1 < n2) return 0;
    return 1 + divisionEntera(n1 - n2, n2);
}

float divisionDecimal(int resto, int divisor, int profundidad){
    if (profundidad == 0 || resto == 0) return 0.0;

    resto *= 10;
    int cociente = divisionEntera(resto, divisor);
    int nuevoResto = resto - cociente * divisor;

    return (cociente / 10.0) + (divisionDecimal(nuevoResto, divisor, profundidad - 1) / 10.0);
}

float division(int n1, int n2, int n){

    float resul = 0.0;
    if (n2 == 0){
        return 0;
    }
    // Determinar signo
    float signo = ((n1 < 0) ^ (n2 < 0)) ? -1 : 1;

    // Uso valores absolutos
    n1 = abs(n1);
    n2 = abs(n2);

    int parteEntera = divisionEntera(n1, n2); // se calcula la parte entera
    int resto = n1 - parteEntera * n2;

//  se analiza si el resto da cero o no
    if (resto == 0){
       return signo * parteEntera;
    } else {
        float parteDecimal = divisionDecimal(resto, n2, n);
        resul= parteEntera + parteDecimal;
        return  signo * resul;
    }

}

// --- Funciones Ejercicio 5---

char* agregarSeparadorMiles(char* num) {
    int len = strlen(num);

    // Manejar signo
    int esNegativo = (num[0] == '-');// se analiza si es negativo
    const char* parteNumerica = esNegativo ? num + 1 : num;

    int lenNum = strlen(parteNumerica);

    if (lenNum <= 3) {
        char* res = (char*) malloc(lenNum + 1);// crea puntero  para guardar las distintas partes
        if (esNegativo) {
            sprintf(res, "-%s", parteNumerica);
        } else {
            strcpy(res, parteNumerica);
        }
        return res;
    }

    char izquierda[101];
    strncpy(izquierda, parteNumerica, lenNum - 3);
    izquierda[lenNum - 3] = '\0';

    char ultimos3[4];
    strncpy(ultimos3, parteNumerica + lenNum - 3, 3);
    ultimos3[3] = '\0';

    char* parteRec = agregarSeparadorMiles(izquierda);// se llama a funcion recursiva

    int nuevoLen = strlen(parteRec) + 1 + 3 + (esNegativo ? 1 : 0);
    char* resultado = (char*) malloc(nuevoLen + 1);
//-- se analiza si es negatico o no para incoporara el signo
    if (esNegativo) {
        sprintf(resultado, "-%s.%s", parteRec, ultimos3);
    } else {
        sprintf(resultado, "%s.%s", parteRec, ultimos3);
    }

    free(parteRec);
    return resultado;
}

// --- Funciones Ejercicio 6 ---

// se Puede usar funcion auxiliar
char *mafiaAux(int n, char buffer[]) {
    if (n == 1) {
        strcat(buffer, "(-.-)");
    } else {
        strcat(buffer, "(-.");
        mafiaAux(n - 1, buffer);
        strcat(buffer, ".-)");

    }
    return buffer;
}


char *reunionMafia(int n){
        char* buffer = malloc(1000);

 buffer[0] = '\0';

    if(n>0){


    mafiaAux(n , buffer);


    }
return buffer;

}

// --- Funciones Ejercicio 7 ---
char* ondaDigital( char* cade) {
    if (*cade == '\0') {
        char* vacio = malloc(1);
        vacio[0] = '\0';
        return vacio;
    }

    char* buffer = malloc(1000);
    buffer[0] = '\0';

    if (*cade == 'H') {
        strcat(buffer, "-");
        if (*(cade+1) != '\0' && *(cade+1) != *cade) {
            strcat(buffer, "|");
        }
    } else if (*cade == 'L') {
        strcat(buffer, "_");
        if (*(cade+1) != '\0' && *(cade+1) != *cade) {
            strcat(buffer, "|");
        }
    }

    // Aca concateno  con el resultado de la recursi�n
    char* resto = ondaDigital(cade+1);
    strcat(buffer, " ");
    strcat(buffer, resto);
    free(resto);

    return buffer;
}


// --- Funciones Ejercicio 8 ---
int count_global = 0;
void buscar(int a[], int tamanio, int n, int index, int suma, char *buffer, char **output, int *count) {
    if (suma == n) {
        strcpy(output[*count], buffer);
        (*count)++;
        return;
    }
    if (index >= tamanio || suma > n) return;

    char nuevo[200];
    if (strlen(buffer) == 0)
        sprintf(nuevo, "%d", a[index]);
    else
        sprintf(nuevo, "%s,%d", buffer, a[index]);

    buscar(a, tamanio, n, index + 1, suma + a[index], nuevo, output, count);
    buscar(a, tamanio, n, index + 1, suma, buffer, output, count);
}

void imprimir_subconjuntos(char **output, int count) {
    printf("{");
    int i;
    for (  i = 0; i < count; i++)
        if (strlen(output[i]) > 0)
            printf("{%s}", output[i]);
    printf("}\n");
}

void subconjuntosQueSumanN(int a[], int tamanio, int n, char **output) {
    int count = 0;
    char buffer[200] = "";// se crea un buffer
    buscar(a, tamanio, n, 0, 0, buffer, output, &count);// se llama a funcion auxiliar
    imprimir_subconjuntos(output, count);
}

// --- Funciones Ejercicio 9 ---
bool divisiblePor7(int n) {
    if (n < 0) n = -n;
    if (n == 0) return true;
    if (n < 100)
        return (n % 7 == 0);// se calcual si n es divible de 7  atraves del modulo

    int resto = n % 10;
    int acum = (n / 10) - 2 * resto;
    return divisiblePor7(acum);// se llama a funcion auxiliar
}

// --- Funciones Ejercicio 10 ---
void auxiliar(int a, int b, int *result, int *indice) {
    if (a > b) {
        int n1 = a / b;
        int n2 = a - n1;
        auxiliar(n1, b, result, indice);// se llama a funcion auxiliar
        auxiliar(n2, b, result, indice);// se llama a funcion auxiliar
    } else {
        result[*indice] = a;
        (*indice)++;// indice lo utilizo para guardar en la posicion correspondiente y lo incremento
    }
}

int *explosion(int a, int b) {
    int *result = malloc(1000 * sizeof(int));// se crea puntero
    if (!result) return NULL;
    memset(result, 0, 1000 * sizeof(int));// se rellena de cero resul
    int indice = 0;
    if (a > 0 && b > 0) auxiliar(a, b, result, &indice);// se llama a funcion auxiliar
    return result;
}
