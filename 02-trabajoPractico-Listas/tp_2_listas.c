#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp_2_listas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2) {
    Lista res = l_crear();
    Iterador it = iterador(l1);

    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);

        if (l_buscar(l2, e->clave) == NULL) {
            l_agregar(res, te_crear(e->clave));
        }
    }
    return res;
}

Lista verElementosRepetidos(Lista l1, Lista l2) {
    Lista res = l_crear();
    Iterador it = iterador(l1);

    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);

        if (l_buscar(l2, e->clave) != NULL) {
            l_agregar(res, te_crear(e->clave));
        }
    }
    return res;
}

float promedio(Lista l1) {
    Iterador it = iterador(l1);
    int suma = 0, cant = 0;

    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        suma += e->clave;
        cant++;
    }

    return (cant == 0) ? 0 : (float)suma / cant;
}

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2) {
    ResultadoValorMinimo r;

    int min = 999999, pos = 0, min_2 = 999999, pos_2 = 0;
    int i = 1;

    Iterador it = iterador(l1);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        if (e->clave < min) {
            min = e->clave;
            pos = i;
        }
        i++;
    }

    i = 1;
    it = iterador(l2);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        if (e->clave < min_2) {
            min_2 = e->clave;
            pos_2 = i;
        }
        i++;
    }

    r.valor = min;
    r.pos = pos;
    r.valor_2 = min_2;
    r.pos_2 = pos_2;

    return r;
}

ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul r;
    r.esMultiplo = true;
    r.escalar = true;
    r.numEscalar = -1;

    if (l_longitud(l1) != l_longitud(l2)) {
        r.esMultiplo = false;
        return r;
    }

    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(l2);

    while (hay_siguiente(it1)) {
        TipoElemento e1 = siguiente(it1);
        TipoElemento e2 = siguiente(it2);

        if (e1->clave == 0 || e2->clave % e1->clave != 0) {
            r.esMultiplo = false;
            r.escalar = true;
            if (e1->clave == 0){
                r.escalar = false;
            }
            return r;
        }

        int esc = e2->clave / e1->clave;

        if (r.numEscalar == -1) {
            r.numEscalar = esc;
        } else if (r.numEscalar != esc) {
            r.escalar = false;
        }
    }

    return r;
}

int CompararListas(Lista l1, Lista l2) {
    int mayor = 0, menor = 0, r = 0;

    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(l2);

    while (hay_siguiente(it1) && hay_siguiente(it2)) {
        TipoElemento e1 = siguiente(it1);
        TipoElemento e2 = siguiente(it2);

        if (e1->clave > e2->clave) mayor++;
        else if (e1->clave < e2->clave) menor++;
    }

    if (mayor > menor) r = 1;
    else if (menor > mayor) r = 2;
    else r = 0;

    printf("Complejidad: O(n)\n");
    return r;
}

void hacerPolinomio(Lista list) {
    int grado;
    double coef;

    printf("=== CARGA DEL POLINOMIO ===\n");

    grado = leerEntero("Ingrese grado del termino (-1 para terminar): ");

    while (grado != -1) {

        while (grado < -1) {
            printf("Error: el grado debe ser >= 0 o -1 para terminar.\n");
            grado = leerEntero("Ingrese grado del termino: ");
        }
        if (grado == -1){
            break;
        }
        coef = leerDouble("Ingrese coeficiente: ");

        float* valor = (float*) malloc(sizeof(float));
        if (valor == NULL) {

             fprintf(stderr, "Error: no se pudo reservar memoria\n");
        return NULL;
           }

        *valor = (float) coef;

        TipoElemento te = te_crear_con_valor(grado, valor);
        l_agregar(list, te);

        grado = leerEntero("Ingrese grado del termino (-1 para terminar): ");
    }
}

float evaluarPolinomio(Lista list, float x) {
    float resultado = 0;

    Iterador it = iterador(list);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);

        int exp = te->clave;
        float coef = *((float*) te->valor);

        resultado += coef * pow(x, exp);
    }

    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando) {
    Lista resultados = l_crear();
    int i = 0;

    if (sumando <= 0) {
        printf("Error: el paso debe ser mayor a 0.\n");
        return resultados;
    }

    if (x > y) {
        printf("Error: el valor inicial debe ser menor o igual al final.\n");
        return resultados;
    }
    double val;
    for (  val = x; val <= y; val += sumando) {
        float res = evaluarPolinomio(list, (float) val);

        float* valor = (float*) malloc(sizeof(float));
        if (valor == NULL) {

                    fprintf(stderr, "Error: no se pudo reservar memoria\n");
                    return NULL;
                }

        *valor = res;

        TipoElemento te = te_crear_con_valor(i, valor);
        l_agregar(resultados, te);

        i++;
    }

    return resultados;
}

bool esSublista(Lista l1, Lista l2) {
    Iterador it = iterador(l2);

    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);

        if (l_buscar(l1, e->clave) == NULL) {
            return false;
        }
    }
    printf("Complejidad: O(n x m)\n");
    return true;
}
