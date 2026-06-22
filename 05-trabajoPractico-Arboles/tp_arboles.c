#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <ctype.h>
#include "tp_arboles.h"


/**
2.	Dado un árbol binario no vacío determinar:  
 */

//  a.	Retornar una lista con todos los nodos terminales u hojas.
void a_ej2_hojasaux(NodoArbol nodo1, Lista terminales){
    if (nodo1 == NULL) {
        return;
    }

    if (nodo1->hd == NULL && nodo1->hi == NULL){
        l_agregar(terminales, nodo1->datos);
        return;
    }
    else {
        a_ej2_hojasaux(nodo1->hd, terminales);
        a_ej2_hojasaux(nodo1->hi, terminales);
    }
}

Lista a_ej2_hojas(ArbolBinario A){
    Lista terminales= l_crear();
    a_ej2_hojasaux(a_raiz(A), terminales);

    return terminales;
}

//  b.	Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)

void a_ej2_interiores_aux(NodoArbol nodo, Lista resultado, NodoArbol raiz){
    if (nodo == NULL) {
        return;
    }
    if ((nodo != raiz) && (nodo->hd != NULL || nodo->hi != NULL)){
        l_agregar(resultado, nodo->datos);
    }

    a_ej2_interiores_aux(nodo->hd, resultado, raiz);
    a_ej2_interiores_aux(nodo->hi, resultado, raiz);
}


Lista a_ej2_interiores(ArbolBinario A){
    Lista resultado = l_crear ();
    a_ej2_interiores_aux (a_raiz(A), resultado, a_raiz(A));
    return resultado;
}

//  c.	Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
void a_ej2_buscarclave_aux (NodoArbol nodo, int clave, Lista resultado){
    if (nodo == NULL){
        return;
    }
    
    if (nodo->datos->clave == clave){
        TipoElemento aux = te_crear_con_valor(clave, nodo);
        l_agregar (resultado,aux);
    }
    a_ej2_buscarclave_aux (nodo->hd, clave, resultado);
    a_ej2_buscarclave_aux (nodo->hi, clave, resultado);
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista resultado = l_crear ();
    a_ej2_buscarclave_aux (a_raiz(A), clave, resultado);
    return resultado;
}

/**
3.	Para un nodo del árbol binario determinado:

 */

// a.	Indicar el nombre del nodo padre (clave).
void a_ej3_clavepadre_aux(NodoArbol nodo, int clavehijo,
                          NodoArbol padre, int *resultado){

    if (nodo == NULL || *resultado != -1){
        return;
    }

    if (nodo->datos->clave == clavehijo){
        if (padre != NULL){
            *resultado = padre->datos->clave;
        }
        return;
    }

    a_ej3_clavepadre_aux(nodo->hi, clavehijo, nodo, resultado);
    a_ej3_clavepadre_aux(nodo->hd, clavehijo, nodo, resultado);
}

int a_ej3_clavepadre(ArbolBinario A, int clavehijo){

    if (a_raiz(A) == NULL){
        return -1;
    }

    if (a_raiz(A)->datos->clave == clavehijo){
        printf("La clave es la raiz, no tiene padre.\n");
        return -1;
    }

    int resultado = -1;

    a_ej3_clavepadre_aux(a_raiz(A), clavehijo, NULL, &resultado);

    if (resultado == -1){
        printf("Clave no encontrada.\n");
    }

    return resultado;
}

// b.	Listar los hijos (solo las clave/s).
void a_ej3_hijos_aux(NodoArbol nodo, Lista resultado, int clavepadre){
    if(nodo== NULL){
        return;
    }
    if(nodo->datos->clave == clavepadre){
        if (nodo->hi != NULL){
            l_agregar(resultado, te_crear(nodo->hi->datos->clave));
        }
        if (nodo->hd != NULL){
            l_agregar(resultado, te_crear(nodo->hd->datos->clave));
        }
        return;
    }
    else{
        a_ej3_hijos_aux(nodo->hi, resultado, clavepadre);
        a_ej3_hijos_aux(nodo->hd, resultado, clavepadre);
    }
}
 
Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista resultado= l_crear();
    a_ej3_hijos_aux(a_raiz(A), resultado, clavepadre);
    return resultado;
}

// c.	Listar el hermano (solo la clave).
void a_ej3_hermano_aux(NodoArbol nodo, int clave,
                       NodoArbol padre, int *resultado){

    if (nodo == NULL || *resultado != -1){
        return;
    }

    if (nodo->datos->clave == clave){

        if (padre == NULL){
            return;
        }

        if (padre->hi != NULL &&
            padre->hi->datos->clave != clave){

            *resultado = padre->hi->datos->clave;
            return;
        }

        if (padre->hd != NULL &&
            padre->hd->datos->clave != clave){

            *resultado = padre->hd->datos->clave;
            return;
        }

        *resultado = -2;
        return;
    }

    a_ej3_hermano_aux(nodo->hi, clave, nodo, resultado);
    a_ej3_hermano_aux(nodo->hd, clave, nodo, resultado);
}

int a_ej3_hermano(ArbolBinario A, int clave){

    if (a_raiz(A) == NULL){
        return -1;
    }

    if (a_raiz(A)->datos->clave == clave){
        printf("La raiz no tiene hermanos.\n");
        return -1;
    }

    int resultado = -1;

    a_ej3_hermano_aux(a_raiz(A), clave, NULL, &resultado);

    if (resultado == -1){
        printf("Clave no encontrada.\n");
    }

    return resultado;
}

// d.	Calcular el nivel en el que se encuentra.

int a_ej3_nivel_aux(NodoArbol nodo, int clave, int nivel){

    if (nodo == NULL){
        return -1;
    }

    if (nodo->datos->clave == clave){
        return nivel;
    }

    int aux = a_ej3_nivel_aux(nodo->hi, clave, nivel + 1);

    if (aux != -1){
        return aux;
    }

    return a_ej3_nivel_aux(nodo->hd, clave, nivel + 1);
}

int a_ej3_nivel(ArbolBinario A, int clave){

    int resultado =
        a_ej3_nivel_aux(a_raiz(A), clave, 0);

    if (resultado == -1){
        printf("Clave no encontrada.\n");
    }

    return resultado;
}

// e.	Calcular la altura de su rama (Altura del Subárbol)
NodoArbol a_ej3_buscarnodo(NodoArbol nodo, int clave){

    if (nodo == NULL){
        return NULL;
    }

    if (nodo->datos->clave == clave){
        return nodo;
    }

    NodoArbol aux =
        a_ej3_buscarnodo(nodo->hi, clave);

    if (aux != NULL){
        return aux;
    }

    return a_ej3_buscarnodo(nodo->hd, clave);
}

int altura_subarbol(NodoArbol nodo){

    if (nodo == NULL){
        return -1;
    }

    int hi = altura_subarbol(nodo->hi);
    int hd = altura_subarbol(nodo->hd);

    return 1 + ((hi > hd) ? hi : hd);
}

int a_ej3_alturarama(ArbolBinario A, int clave){

    NodoArbol nodo =
        a_ej3_buscarnodo(a_raiz(A), clave);

    if (nodo == NULL){
        printf("Nodo no encontrado.\n");
        return -1;
    }

    return altura_subarbol(nodo);
}

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
void a_ej3_clavesmismonivel_aux (NodoArbol nodo, int nivel, Lista resultado, int nivelnodo){
    if (nodo == NULL){
        return;
    }
    if (nivelnodo == nivel){
        TipoElemento aux = te_crear (nodo->datos->clave);
        l_agregar (resultado, aux);
    }
    else{
        a_ej3_clavesmismonivel_aux (nodo->hd, nivel, resultado, nivelnodo+1);
        a_ej3_clavesmismonivel_aux (nodo->hi, nivel, resultado, nivelnodo+1);
    }
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){
    Lista resultado = l_crear ();
    if (0 > nivel){
        printf ("Nivel inferior al minimo (0).");
        return resultado;
    }
    a_ej3_clavesmismonivel_aux (a_raiz(A), nivel, resultado,0);
    return resultado;
}

/**
4.	Para Árboles “N-arios”:*/
// a.    Dado un árbol n-ario, devolver en forma de lista el resultado del recorrido en anchura del árbol  (solo las claves).
void a_ej4_anchura_aux(NodoArbol nodo, Lista resultado, Cola caux){ 
    if (nodo == NULL){
        return ;
    }

    c_encolar(caux,te_crear_con_valor(nodo->datos->clave,nodo));


    while(!c_es_vacia(caux)){
    TipoElemento aux = c_desencolar(caux);
    NodoArbol actual = (NodoArbol)aux->valor;

    l_agregar (resultado,actual->datos);

    NodoArbol hijo = actual->hi;
    while(hijo != NULL){
        c_encolar(caux,te_crear_con_valor(hijo->datos->clave,hijo));
        hijo = hijo->hd;
    }

    }

}

Lista a_ej4_anchura(ArbolBinario A){
    Lista resultado = l_crear();
    Cola caux = c_crear();

    a_ej4_anchura_aux(a_raiz(A),resultado,caux);

    return resultado;
}

// b.	Escribir una función que, dado un árbol n-ario, devuelva el número (cantidad) de hojas de dicho árbol.

void a_ej4_q_hojas_aux(NodoArbol nodo, int *cantidad){
    if (nodo == NULL){
        return;
    }

    if (nodo->hi == NULL){
        (*cantidad)++;
    }

    a_ej4_q_hojas_aux(nodo->hi, cantidad);
    a_ej4_q_hojas_aux(nodo->hd, cantidad);
}

int a_ej4_q_hojas(ArbolBinario A){
    int cantidad = 0;
    a_ej4_q_hojas_aux(a_raiz(A), &cantidad);
    return cantidad;
}

// c.	Escribir una función booleana que dados dos árboles generales determine si tienen la misma estructura, sin importar los datos del mismo (árbol similar).
bool a_ej4_similares_aux (NodoArbol nodo1, NodoArbol nodo2){
    if (nodo1 == NULL && nodo2 == NULL){
        return true;
    }
    if (nodo1 == NULL || nodo2 == NULL){
        return false;
    }

    return a_ej4_similares_aux(nodo1->hi, nodo2->hi) &&
           a_ej4_similares_aux(nodo1->hd, nodo2->hd);
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B){
    return a_ej4_similares_aux(a_raiz(A), a_raiz(B));
}

// d.	Retornar el padre de un nodo del árbol (tipo_elemento).
void a_ej4_padre_aux (NodoArbol nodo, int clave, NodoArbol padre, TipoElemento *resultado, int *encontrado){
    if (nodo == NULL){
        return;
    }
    if (nodo->datos->clave == clave){
        *resultado = padre->datos;
        *encontrado = 1;
    }
    a_ej4_padre_aux (nodo->hd, clave, padre, resultado, encontrado);
    padre = nodo;
    a_ej4_padre_aux (nodo->hi, clave, padre, resultado, encontrado);
}

NodoArbol a_ej4_padre_nodo_aux(NodoArbol nodo, int clave){
    if (nodo == NULL){
        return NULL;
    }

    NodoArbol hijo = nodo->hi;
    while (hijo != NULL){
        if (hijo->datos->clave == clave){
            return nodo;
        }
        hijo = hijo->hd;
    }

    hijo = nodo->hi;
    while (hijo != NULL){
        NodoArbol encontrado = a_ej4_padre_nodo_aux(hijo, clave);
        if (encontrado != NULL){
            return encontrado;
        }
        hijo = hijo->hd;
    }

    return NULL;
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz (A);
    if (raiz == NULL){
        return NULL;
    }
    if (clave == raiz->datos->clave){
        printf ("La clave es la raiz, no tiene padre.");
        return NULL; 
    }

    NodoArbol padre = a_ej4_padre_nodo_aux(raiz, clave);
    if (padre == NULL){
        printf ("Nodo no encontrado.");
        return NULL;
    }

    return padre->datos;
}

// e.	Retornar los hermanos de un nodo del árbol (lista de hermanos).
void a_ej4_hermanos_aux (NodoArbol nodo, int clave, NodoArbol padre, NodoArbol *resultado){
    if (nodo == NULL){
        return;
    }
    if (nodo->datos->clave == clave){
        *resultado = padre;
        return;
    }
    a_ej4_hermanos_aux (nodo->hd, clave, padre, resultado);
    padre = nodo;
    a_ej4_hermanos_aux (nodo->hi, clave, padre, resultado);
}

void a_ej4_hermanos_aux_2 (NodoArbol nodo, Lista resultado, int clave){
    if (nodo == NULL){
        return;
    }
    if (nodo->datos->clave != clave){
        TipoElemento temp = te_crear (nodo->datos->clave);
        l_agregar (resultado,temp);
    }
    a_ej4_hermanos_aux_2 (nodo->hd, resultado, clave);
}

Lista a_ej4_hermanos(ArbolBinario A, int clave){
    Lista lresultado = l_crear();
    NodoArbol raiz = a_raiz (A);
    if (raiz == NULL){
        return lresultado;
    }
    if (raiz->datos->clave == clave){
        printf ("La clave es de la raiz, no tiene hermanos.");
        return lresultado;
    }

    NodoArbol padre = a_ej4_padre_nodo_aux(raiz, clave);
    if (padre == NULL){
        printf ("Nodo no encontrado");
        return lresultado;
    }

    NodoArbol hermano = padre->hi;
    while (hermano != NULL){
        if (hermano->datos->clave != clave){
            l_agregar(lresultado, te_crear(hermano->datos->clave));
        }
        hermano = hermano->hd;
    }

    return lresultado;
}

/**
7.	Determinar si dos árboles binarios son equivalentes.
 */
void a_ej7_equivalente_aux(NodoArbol a, NodoArbol b, int *resultado){
    if (*resultado == 0){
        return;
    }
    if (a == NULL && b == NULL){
        return;
    }
    if (a == NULL || b == NULL){
        *resultado = 0;
        return;
    }

    TipoElemento temp1 = a->datos;
    TipoElemento temp2 = b->datos;
    if (temp1->clave != temp2->clave){
        *resultado = 0;
        return;
    }

    a_ej7_equivalente_aux (a->hd, b->hd, resultado);
    a_ej7_equivalente_aux (a->hi, b->hi, resultado);  
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    int resultado= 1;
    bool equivalentes;
    if(a_cantidad_elementos(A) != a_cantidad_elementos(B)){
        printf("Los arboles no tienen la misma cantidad de elementos.");
        equivalentes = false;
        return equivalentes;
    }
    a_ej7_equivalente_aux(a_raiz(A), a_raiz(B), &resultado);
    if(resultado == 1){
        equivalentes= true;
    }
    else{
        equivalentes= false;
    }

    return equivalentes;
}

/**
8.	Dado un árbol “n-ario” se pide:
 */
// a.	Determinar la altura del mismo.
int a_ej8_altura_aux(NodoArbol nodo){

    if (nodo == NULL){
        return -1;
    }

    int max_hijos = -1;

    NodoArbol hijo = nodo->hi;

    while (hijo != NULL){

        int altura_hijo =
            a_ej8_altura_aux(hijo);

        if (altura_hijo > max_hijos){
            max_hijos = altura_hijo;
        }

        hijo = hijo->hd;
    }

    return max_hijos + 1;
}

int a_ej8_altura(ArbolBinario A){

    return a_ej8_altura_aux(a_raiz(A));
}

// b.	Determinar el nivel de un nodo.
int a_ej8_nivel_aux(NodoArbol nodo, int clave, int nivel){

    if (nodo == NULL){
        return -1;
    }

    if (nodo->datos->clave == clave){
        return nivel;
    }

    int aux = a_ej8_nivel_aux(nodo->hi, clave, nivel + 1);

    if (aux != -1){
        return aux;
    }

    return a_ej8_nivel_aux(nodo->hd, clave, nivel + 1);
}

int a_ej8_nivel(ArbolBinario A, int clave){
    return a_ej8_nivel_aux(a_raiz(A), clave, 0);
}

// c.	Listar todos los nodos internos (solo las claves).
void a_ej8_internos_aux (NodoArbol nodo, Lista resultado, ArbolBinario A){
    if (nodo == NULL){
        return;
    }
    if ((nodo->hi != NULL) && (nodo != a_raiz(A))){
        TipoElemento temp = nodo->datos;
        l_agregar (resultado,temp);
    }
    a_ej8_internos_aux (nodo->hd,resultado, A);
    a_ej8_internos_aux (nodo->hi, resultado, A);
}

Lista a_ej8_internos(ArbolBinario A){
    Lista resultado = l_crear ();
    a_ej8_internos_aux (a_raiz(A), resultado, A);
    return resultado;
}

// d.	Determinar si todas las hojas están al mismo nivel.
void a_ej8_hojasmismonivel_aux (NodoArbol nodo, int nivel, int *resultado, int *nivelgeneral){
    if (nodo == NULL){
        return;
    }
    if (nodo->hi == NULL){
        if (*nivelgeneral == -1){
            *nivelgeneral = nivel;
        }
        else{
            if (nivel != *nivelgeneral){
                *resultado = 0;
            }
        }
    }
    a_ej8_hojasmismonivel_aux (nodo->hd, nivel,resultado,nivelgeneral);
    a_ej8_hojasmismonivel_aux (nodo->hi, nivel+1,resultado,nivelgeneral);
}

bool a_ej8_hojasmismonivel(ArbolBinario A){
    int resultado = 1;
    int nivelgeneral = -1;
    a_ej8_hojasmismonivel_aux (a_raiz(A), 0,&resultado,&nivelgeneral);
    return resultado;
}

/*
9.	Generar un algoritmo, recursivo o no, que permita construir un árbol binario de búsqueda balanceado (AVL) 
	a partir de un árbol binario sin un orden determinado.  
	Comparar las alturas de ambos árboles. Determinar la complejidad algorítmica.
 */
// Primero llamamos para construir el AVL
Cola ClavesPreorder(NodoArbol Nodo, Cola c_Arbol){
	if (Nodo == NULL) return c_Arbol;
	NodoArbol hijoizquierdo = n_hijoizquierdo(Nodo);
	NodoArbol hijoderecho = n_hijoderecho(Nodo);
	TipoElemento h;
	c_encolar(c_Arbol, Nodo->datos);
	ClavesPreorder(hijoizquierdo,c_Arbol);
	ClavesPreorder(hijoderecho,c_Arbol);
	return c_Arbol;
}


ArbolAVL a_ej9_construiravl(ArbolBinario A){
	NodoArbol nodo= a_raiz(A);
	Cola c_arbol = c_crear();
	TipoElemento x= te_crear(0);
	ArbolAVL AVl = avl_crear();
	ClavesPreorder(nodo,c_arbol);
	while (!c_es_vacia(c_arbol))
	{
		x=c_desencolar(c_arbol);
		avl_insertar(AVl, x);
	}
	return AVl;
};

// Luego con el resultado de la funcion anterior llamamos a una funcion para que nos retorne la diferencia de las alturas 
// comparadas como Altura(ArbolBinario) - Altura(ArbolAVL).
int alturaArbol(NodoArbol nodo){
	if (nodo == NULL) return -1;
	NodoArbol hijoizquierdo = n_hijoizquierdo(nodo);
	NodoArbol hijoderecho = n_hijoderecho(nodo);
	int altura_izq= alturaArbol(hijoizquierdo);
	int altura_der= alturaArbol(hijoderecho);
	int max_altura;
	if (altura_izq > altura_der) {
		max_altura = altura_izq;
	} else {
		max_altura = altura_der;
	}
	return 1 + max_altura;	
}


int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){

    NodoArbol raizAVL = avl_raiz(AVL);

    if (raizAVL == NULL){
        return 0;
    }

    int avlaltura = raizAVL->FE;
    int alturaAb = alturaArbol(a_raiz(A));

    return alturaAb - avlaltura;
};

/**
10.	Dada una serie de números generados al azar, cargar la misma serie en un árbol binario de búsqueda y en un árbol binario balanceado “AVL”.  
	Comparar la altura de ambos árboles.  
	Repetir el proceso “n” veces. 
	¿Qué puede concluir al respecto?
 */
// Generamos una lista con la serie de numeros (unicos no repetidos)
// Las claves se deben generar entre "valorminimo" y "valormaximo".
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo){
	Lista valores = l_crear();
    int rango = valormaximo - valorminimo + 1;

    if (rango < cantidadclavesagenerar) {
        printf("No es posible generar %d claves únicas en el rango dado.\n", cantidadclavesagenerar);
        return valores;
    }

    for (int i = 0; i < cantidadclavesagenerar; i++) {
        int clave;
        do {
            clave = rand() % rango + valorminimo;
        } while (l_buscar(valores, clave));

        l_agregar(valores, te_crear(clave));
    }
    return valores;
};

ArbolBinarioBusqueda a_ej10_crearABB(Lista L){
	ArbolBinarioBusqueda arbolBB = abb_crear();
    Iterador itera = iterador(L);
    while (hay_siguiente(itera)) {
        TipoElemento elemento_actual = siguiente(itera);
        abb_insertar(arbolBB, elemento_actual);
    }
    return arbolBB;
};

ArbolAVL a_ej10_crearAVL(Lista L){
	ArbolAVL AVl = avl_crear();
	TipoElemento x= te_crear(0);
	Iterador ite1= iterador(L);
	while (hay_siguiente(ite1)){
		x=siguiente(ite1);
		avl_insertar(AVl, x);
	}
	return AVl;
};

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL){

    NodoArbol raizAVL = avl_raiz(AVL);

    if (raizAVL == NULL){
        return 0;
    }

    int avlaltura = raizAVL->FE;
    int abbAltura = alturaArbol(abb_raiz(ABB));

    return abbAltura - avlaltura;
};


Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar){
	Lista diferencias = l_crear();
    for(int i=0; i<N_repeticiones; i++) {
        Lista L = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);
        ArbolBinarioBusqueda ABB = a_ej10_crearABB(L);
        ArbolAVL AVL = a_ej10_crearAVL(L);
        int dif_alturas = a_ej10_difalturas(ABB, AVL);
        l_agregar(diferencias, te_crear(dif_alturas));
    }
    return diferencias;
};
