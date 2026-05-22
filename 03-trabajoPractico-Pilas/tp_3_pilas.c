#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"

bool p_ej2_existeclave(Pila p, int clave){
    Pila aux = p_crear();
    TipoElemento Taux;
    bool existe = false;
    while(!p_es_vacia(p)){
        Taux = p_desapilar(p);
        if(clave == Taux->clave){
            existe = true;
        }
        p_apilar(aux,Taux);
    }
    while(!p_es_vacia(aux)){
        Taux = p_desapilar(aux);
        p_apilar(p, Taux);
    }
    return existe;
}

int p_ej2_cantidadelementos(Pila p){
    Pila aux = p_crear();
    TipoElemento Taux;
    int c = 0;
    while(!p_es_vacia(p)){
        c++;
        Taux = p_desapilar(p);
        p_apilar(aux, Taux);
    }
    while(!p_es_vacia(aux)){
        Taux = p_desapilar(aux);
        p_apilar(p, Taux);
    }
    return c;
}

Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    int cantidad = p_ej2_cantidadelementos(p);
    Pila n = p_crear();
    Pila aux = p_crear();
    TipoElemento Taux;
    if (posicionordinal < 1){
        printf("Su posicion es 0 o menor, imposibilitando la colocacion\n");
        return p;
    }
    if(posicionordinal > cantidad){
         printf("La posicion que intenta colocar(no existe) es mayor a la cantidad de elementos, se coloco en la ultima posicion.");
    }

    if (cantidad < posicionordinal){
        while(!p_es_vacia(p)){
            Taux = p_desapilar(p);
            p_apilar(aux, Taux);
        }
        p_apilar(n, x);
        while(!p_es_vacia(aux)){
            Taux = p_desapilar(aux);
            p_apilar(p, Taux);
            p_apilar(n, Taux);
        }
    }else{
        while(!p_es_vacia(p)){
            Taux = p_desapilar(p);
            p_apilar(aux, Taux);
        }
        while(!p_es_vacia(aux)){
            Taux = p_desapilar(aux);
            p_apilar(n, Taux);
            p_apilar(p, Taux);
            if (cantidad == posicionordinal){
                p_apilar(n, x);
            }
            cantidad--;
        }
    }
    return n;
}

Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila aux = p_crear();
    Pila n = p_crear();
    TipoElemento Taux;
    bool encontrado = false;
    bool eliminado = false;
    while(!p_es_vacia(p)){
        Taux = p_desapilar(p);
        if (Taux->clave == clave){
            encontrado = true;
        }
        p_apilar(aux, Taux);
    }
    while(!p_es_vacia(aux)){
        Taux = p_desapilar(aux);
        if (!eliminado && Taux->clave == clave) {
            eliminado = true;
        } else {
            p_apilar(n, Taux);
        }
        p_apilar(p, Taux);
    }
    if (encontrado){
        return n;
    }else{
        return p;
    }
}

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
    int cantidad = p_ej2_cantidadelementos(p);
    if (pos1 < 1 || pos2 < 1 || pos1 > cantidad || pos2 > cantidad) {
        printf("Posiciones invalidas\n");
        return p;
    }
    Pila aux = p_crear();
    Pila nueva = p_crear();
    TipoElemento actual;
    TipoElemento elem1 = NULL;
    TipoElemento elem2 = NULL;
    int posicion = 1;
    while (!p_es_vacia(p)) {
        actual = p_desapilar(p);
        if (posicion == pos1) {
            elem1 = actual;
        }
        if (posicion == pos2) {
            elem2 = actual;
        }
        p_apilar(aux, actual);
        posicion++;
    }
    posicion = cantidad;
    while (!p_es_vacia(aux)) {
        actual = p_desapilar(aux);
        if (posicion == pos1) {
            p_apilar(nueva, elem2);
        }
        else if (posicion == pos2) {
            p_apilar(nueva, elem1);
        }
        else {
            p_apilar(nueva, actual);
        }
        p_apilar(p, actual);
        posicion--;
    }
    return nueva;
}

Pila p_ej2_duplicar(Pila p){
    Pila n = p_crear();
    Pila aux = p_crear();
    TipoElemento te;
    while(!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(aux, te);
    }
    while(!p_es_vacia(aux)){
        te = p_desapilar(aux);
        p_apilar(p, te);
        p_apilar(n, te);
    }
    return n;
}

bool p_ej3_iguales(Pila p1, Pila p2){
    Pila aux = p_crear();
    bool diferente = false;
    bool igualdad = true;
    if (p_ej2_cantidadelementos(p1) != p_ej2_cantidadelementos(p2)){
        return false;
    }
    TipoElemento t1, t2;
    while(!p_es_vacia(p1) && !diferente){
        t1 = p_desapilar(p1);
        t2 = p_desapilar(p2);
        if(t1->clave != t2->clave){
            p_apilar(aux, t1);
            p_apilar(aux, t2);
            diferente = true;
            igualdad = false;
        }else{
            p_apilar(aux, t1);
        }
    }
    while(!p_es_vacia(aux)){
        if (diferente){
            t2 = p_desapilar(aux);
            t1 = p_desapilar(aux);
            p_apilar(p1, t1);
            p_apilar(p2, t2);
            diferente = false;
        }else{
            t1 = p_desapilar(aux);
            p_apilar(p1, t1);
            p_apilar(p2, t1);
        }
    }
    return igualdad;
}

char* p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase) {
    if (nrootrabase < 2 || nrootrabase > 16){
        return NULL;
    }
    if (nrobasedecimal == 0) {
        char* r = malloc(2);
        strcpy(r, "0");
        return r;
    }
    Pila p = p_crear();
    char digitos[] = "0123456789ABCDEF";

   int negativo = nrobasedecimal < 0;
    if (negativo) {
        nrobasedecimal = -nrobasedecimal;
    }


    while (nrobasedecimal > 0) {
        int resto = nrobasedecimal % nrootrabase;
        p_apilar(p, te_crear(resto));
        nrobasedecimal = nrobasedecimal / nrootrabase;
    }

    char* resultado = malloc(100);
    int i = 0;
    if (negativo) resultado[i++] = '-';

    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        resultado[i++] = digitos[x->clave];
    }
    resultado[i] = '\0';
    return resultado;
}

Pila p_ej5_invertir(Pila p) {
    Pila aux = p_crear();
    Pila invertida = p_crear();
    Pila restaurar = p_crear();
    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        p_apilar(aux, x);
        p_apilar(restaurar, x);
    }
    while (!p_es_vacia(restaurar)) {
        p_apilar(p, p_desapilar(restaurar));
    }
    return aux;
}

Pila p_ej6_eliminarclave(Pila p, int clave) {
    Pila aux = p_crear();
    Pila resultado = p_crear();
    Pila restaurar = p_crear();
    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        p_apilar(aux, x);
        p_apilar(restaurar, x);
    }
    while (!p_es_vacia(aux)) {
        TipoElemento x = p_desapilar(aux);
        if (x->clave != clave) {
            p_apilar(resultado, x);
        }
    }
    while (!p_es_vacia(restaurar)) {
        p_apilar(p, p_desapilar(restaurar));
    }
    return resultado;
}

void p_ej6_recursivo_aux(Pila original, Pila resultado, int clave){
    if (p_es_vacia(original)){
        return;
    }
    TipoElemento x = p_desapilar(original);
    p_ej6_recursivo_aux(original, resultado, clave);
    if (x->clave != clave) {
        p_apilar(resultado, x);
    }
    p_apilar(original, x);
}

Pila p_ej6_eliminarclaverecursiva(Pila p, int clave){
    Pila resultado = p_crear();
    p_ej6_recursivo_aux(p, resultado, clave);
    return resultado;
}

Pila p_ej7_elementoscomunes(Pila p1, Pila p2) {
    Pila resultado = p_crear();
    Pila aux1 = p_crear();
    while (!p_es_vacia(p1)) {
        TipoElemento x = p_desapilar(p1);
        if (p_ej2_existeclave(p2, x->clave) && !p_ej2_existeclave(resultado, x->clave)){
            p_apilar(resultado, x);
        }
        p_apilar(aux1, x);
    }
    while (!p_es_vacia(aux1)) {
        p_apilar(p1, p_desapilar(aux1));
    }
    return resultado;
}

int contar_apariciones(Pila p, int valor) {
    Pila aux = p_crear();
    int contador = 0;
    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        if (x->clave == valor){
            contador++;
        }
        p_apilar(aux, x);
    }
    while (!p_es_vacia(aux)){
        p_apilar(p, p_desapilar(aux));
    }
    return contador;
}

Pila p_ej8_sacarrepetidos(Pila p) {
    Pila resultado = p_crear();
    Pila procesados = p_crear();
    Pila aux = p_crear();
    while (!p_es_vacia(p)) {
        TipoElemento x = p_desapilar(p);
        if (!p_ej2_existeclave(procesados, x->clave)) {
            int cant = contar_apariciones(p, x->clave) + 1;
            TipoElemento nuevo = te_crear(x->clave);
            nuevo->valor = (void*)(long)cant;
            p_apilar(resultado, nuevo);
            p_apilar(procesados, x);
        }
        p_apilar(aux, x);
    }
    while (!p_es_vacia(aux)) {
        p_apilar(p, p_desapilar(aux));
    }
    return resultado;
}
