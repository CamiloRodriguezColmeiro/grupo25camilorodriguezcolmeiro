#include "../libs/colas/headers/colas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/listas/headers/listas.h"
#include "tp_colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool c_ej2_existeclave(Cola c, int clave){
    TipoElemento e;
    bool encontrado=false;
    Cola cola1 = c_crear();
    while(!c_es_vacia(c)){
        e= c_desencolar(c);
        if(clave == e->clave){
            encontrado = true;
        }
        c_encolar(cola1, e);
    }
    while(!c_es_vacia(cola1)){
        e= c_desencolar(cola1);
        c_encolar(c, e);
    }
    return encontrado;
}

Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    int pos= 1;
    TipoElemento e;
    Cola cola1 = c_crear();
    Cola cola2 = c_crear();
    while(!c_es_vacia(c) ){
        e= c_desencolar(c);
        if(pos== posicionordinal){
            c_encolar(cola1, X);
        }
        pos++;
        c_encolar(cola1, e);
        c_encolar(cola2, e);
    }
    while(!c_es_vacia(cola1)){
        e= c_desencolar(cola1);
        c_encolar(c, e);
    }
    return c;
}

Cola c_ej2_sacarelemento(Cola c, int clave){
    TipoElemento e;
    Cola cola1 = c_crear();
    Cola cola2 = c_crear();
    while(!c_es_vacia(c)){
        e=c_desencolar(c);
        if(e->clave != clave){
            c_encolar(cola1, e);
        }
        c_encolar(cola2, e);
    }
    while(!c_es_vacia(cola2)){
        e=c_desencolar(cola2);
        c_encolar(c, e);
    }
    return cola1;
}

int c_ej2_contarelementos(Cola c) {
    if (c_es_vacia(c)) {
        return 0;
    }
    Cola aux = c_crear();
    int contador = 0;
    while (!c_es_vacia(c)) {
        TipoElemento te = c_desencolar(c);
        contador++;
        c_encolar(aux, te);
    }
    while (!c_es_vacia(aux)) {
        TipoElemento te = c_desencolar(aux);
        c_encolar(c, te);
    }
    return contador;
}

Cola c_ej2_copiar(Cola c) {
    Cola copia = c_crear();
    if (c_es_vacia(c)) {
        return copia;
    }
    Cola aux = c_crear();
    while (!c_es_vacia(c)) {
        TipoElemento te = c_desencolar(c);
        c_encolar(aux, te);
        c_encolar(copia, te);
    }
    while (!c_es_vacia(aux)) {
        TipoElemento te = c_desencolar(aux);
        c_encolar(c, te);
    }
    return copia;
}

Cola c_ej2_invertir(Cola c){
    TipoElemento e;
    Cola cola1 = c_crear();
    Cola cola2  = c_crear();
    Pila pila = p_crear();
    while (!c_es_vacia(c)){
        e= c_desencolar(c);
        c_encolar(cola1, e);
        p_apilar(pila,e);
    }
   while (!p_es_vacia(pila)){
        e=p_desapilar(pila);
        c_encolar(c , e);
    }
    return c;
}

bool c_ej3_iguales(Cola c1, Cola c2){
    bool iguales = true;
    TipoElemento e1,e2;
    Cola colaAux = c_crear();
    while(!c_es_vacia(c1)  &&!c_es_vacia(c2) ){
        e1= c_desencolar(c1);
        e2= c_desencolar(c2);
        if(e1->clave !=e2->clave  ){
            return false;
        }else{
            c_encolar(colaAux,e1);
        }
    }
    if( !c_es_vacia(c1)){
        return false;
    }else if( !c_es_vacia(c2)){
        return false;
    }
    while(!c_es_vacia(colaAux)){
        e1= c_desencolar(colaAux);
        c_encolar(c1,e1);
        c_encolar(c2,e1);
    }
    return iguales;
}

Cola c_ej4_colanorepetidos(Cola c) {
    Cola resultado = c_crear();
    Cola aux = c_crear();
    TipoElemento e;

    while (!c_es_vacia(c)) {
        e = c_desencolar(c);
        c_encolar(aux, e);
    }

    while (!c_es_vacia(aux)) {
        e = c_desencolar(aux);
        int contador = 1;

        Cola temp = c_crear();
        TipoElemento e2;

        while (!c_es_vacia(aux)) {
            e2 = c_desencolar(aux);
            if (e->clave == e2->clave) {
                contador++;
            } else {
                c_encolar(temp, e2);
            }
        }

        if (contador == 1) {
            c_encolar(resultado, e);
        }
        while (!c_es_vacia(temp)) {
            e2 = c_desencolar(temp);
            c_encolar(aux, e2);
        }
    }
    return resultado;
}

Cola c_ej5_divisortotal(Cola c) {

    Cola resultado = c_crear();
    Cola aux = c_crear();

    TipoElemento e, e2;

    int n = 0;

    while (!c_es_vacia(c)) {
        e = c_desencolar(c);
        c_encolar(aux, e);
        n++;
    }

    while (!c_es_vacia(aux)) {
        e = c_desencolar(aux);
        c_encolar(c, e);
    }

    int procesados = 0;

    while (procesados < n) {

        e = c_desencolar(c);
        int divisor = e->clave;

        int divisibles = 0;
        int contador = 0;

        while (contador < n - 1) {

            e2 = c_desencolar(c);

            if (e2->clave % divisor == 0) {
                divisibles++;
            }

            c_encolar(aux, e2);
            contador++;
        }

        while (!c_es_vacia(aux)) {
            e2 = c_desencolar(aux);
            c_encolar(c, e2);
        }

        c_encolar(c, e);

        if (divisibles == n - 1) {
            int* valor = malloc(sizeof(int));
            *valor = 1; 
            TipoElemento nuevo = te_crear_con_valor(divisor, valor);
            c_encolar(resultado, nuevo);
        }
        else if (divisibles >= (n - 1) / 2.0) {
            int* valor = malloc(sizeof(int));
            *valor = 0; 
            TipoElemento nuevo = te_crear_con_valor(divisor, valor);
            c_encolar(resultado, nuevo);
        }

        procesados++;
    }

    return resultado;
}

Lista c_ej6_comunesapilaycola(Pila pila, Cola cola){
    TipoElemento ep, ec;
    Pila paux = p_crear();
    Cola coaux = c_crear();
    Lista listaR = l_crear();
    int pospi = 1;
    while (!p_es_vacia(pila)) {
        ep = p_desapilar(pila);
        int posco = 1;
        while (!c_es_vacia(cola)) {
            ec = c_desencolar(cola);
            if (ep->clave == ec->clave){

               char *salida = malloc(50);
                sprintf(salida, ":%d:%d",   pospi, posco);
                l_agregar(listaR, te_crear_con_valor(ep->clave, salida));
            }
            posco++;
            c_encolar(coaux, ec);
        }
        while (!c_es_vacia(coaux)) {
            ec = c_desencolar(coaux);
            c_encolar(cola, ec);
        }
        p_apilar(paux, ep);
        pospi++;
    }
    while (!p_es_vacia(paux)) {
        ep = p_desapilar(paux);
        p_apilar(pila, ep);
    }
    return listaR;
}

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int  tiempoatencion){
    Cola resultado = c_crear();
    int q = tiempoatencion;
    int nroCliente1 = 1;
    int nroCliente2 = 1;
    int nroCliente3 = 1;
    while (!c_es_vacia(c1) || !c_es_vacia(c2) || !c_es_vacia(c3)){
        if (!c_es_vacia(c1)){
            TipoElemento e = c_desencolar(c1);
            if (e->clave <= q){
                char *texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 1", nroCliente1);
                c_encolar(resultado, te_crear_con_valor(1, texto));
                nroCliente1++;
            }
            else{
                e->clave -= q;
                c_encolar(c1, e);
            }
        }
        if (!c_es_vacia(c2)){
            TipoElemento e = c_desencolar(c2);
            if (e->clave <= q){
                char *texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 2", nroCliente2);
                c_encolar(resultado, te_crear_con_valor(2, texto));
                nroCliente2++;
            }
            else{
                e->clave -= q;
                c_encolar(c2, e);
            }
        }
        if (!c_es_vacia(c3)){
            TipoElemento e = c_desencolar(c3);
            if (e->clave <= q){
                char *texto = malloc(50);
                sprintf(texto, "Cliente %d Cola 3", nroCliente3);
                c_encolar(resultado, te_crear_con_valor(3, texto));
                nroCliente3++;
            }
            else{
                e->clave -= q;
                c_encolar(c3, e);
            }
        }
    }
    return resultado;
}
