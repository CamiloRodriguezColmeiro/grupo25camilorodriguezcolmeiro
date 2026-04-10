#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "../headers/validaciones.h"

void limpiarBuffer() {
    while (getchar() != '\n');
}

void trim(char *str) {
    char *inicio = str;
    char *fin;

    while (isspace((unsigned char)*inicio)) {
        inicio++;
    }

    if (*inicio == '\0') {
        *str = '\0';
        return;
    }

    fin = inicio + strlen(inicio) - 1;

    while (fin > inicio && isspace((unsigned char)*fin)) {
        fin--;
    }

    *(fin + 1) = '\0';

    if (inicio != str) {
        memmove(str, inicio, strlen(inicio) + 1);
    }
}

bool tieneEspaciosInternos(const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            return true;
        }
    }
    return false;
}

int leerEntero(const char* mensaje) {
    char buffer[100];
    char *endptr;
    int x;

    while (1) {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        x = strtol(buffer, &endptr, 10);

        // Verificar que no haya basura despues del numero
        if (endptr == buffer || (*endptr != '\n' && *endptr != '\0')) {
            printf("Error: debe ingresar un numero entero valido.\n");
        } else {
            return x;
        }
    }
}

void leerCadena(const char* mensaje, char* destino) {
    printf("%s", mensaje);
    scanf("%s", destino);
    limpiarBuffer();
}

int leerNatural(const char* mensaje) {
    int x;

    do {
        x = leerEntero(mensaje);

        if (x <= 0) {
            printf("Error: debe ingresar un numero natural mayor que 0.\n");
        }

    } while (x <= 0);

    return x;
}

int esSenialValida(char* s) {
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] != 'H' && s[i] != 'L') return 0;
    }
    return 1;
}

int esNumero(const char *cadena) {
    if (cadena == NULL || *cadena == '\0')
        return 0;
    int i;
    if(cadena[0]=='-'){
        for (i = 1; cadena[i] != '\0'; i++)
            if (!isdigit((unsigned char)cadena[i])) return 0;
    return 1;
    }else{
     for (i = 0; cadena[i] != '\0'; i++)
        if (!isdigit((unsigned char)cadena[i])) return 0;
    return 1;
    }
}

int limiteSup(long num2) {
    if (num2 >= INT_MAX) {
            printf("Numero demasiado grande\n");
    return 1;
    }
    return 0; 
}