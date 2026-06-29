#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "tp_conjunto.h"


// Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave)
// verifique las operaciones de Unión, Intersección, Diferencia y Pertenencia. p2
Conjunto c_ej2_union(Conjunto A, Conjunto B){
    Conjunto Union=cto_crear();
    Union=cto_union(A,B);
    return Union;
}
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    Conjunto Interseccion=cto_crear();
    Interseccion=cto_interseccion(A,B);
    return Interseccion;
}
Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    Conjunto Diferencia=cto_crear();
    Diferencia=cto_diferencia(A,B);
    return Diferencia;
}
void operaciones(Conjunto A,Conjunto B){
    Conjunto Union= c_ej2_union(A,B);
    Conjunto Interseccion= c_ej2_interseccion(A, B);
    Conjunto Diferencia=c_ej2_diferencia(A, B);
    Conjunto PertenenciaA=cto_crear();
    Conjunto PertenenciaB=cto_crear();
    int clave=0;
    
    printf("\nIngrese la clave para mostrar pertenencia en los conjuntos ");
    scanf("%d",&clave);

    if(cto_pertenece(A,clave)){
        printf("\nEl elemento %d pertenece al conjunto A \n",clave);
    }else{
        printf("La clave no esta en el conjunto A\n");
    }
    if(cto_pertenece(B,clave)){
        printf("\nEl elemento %d pertenece al conjunto B \n",clave);
    }else{
        printf("La clave no esta en el conjunto B\n\n");
    }

    printf("\nLos elementos que tienen Union son: \n");
    cto_mostrar(Union);
    printf("\n\nLos elementos que tienen Interseccion son: \n");
    cto_mostrar(Interseccion);
    printf("\n\nLos elementos que tienen Dieferencia son: \n");
    cto_mostrar(Diferencia);
}
/////////////////////////////////////////////////////////////////////////////////// 
/**
3.	Desarrollar un algoritmo que dada una colección de conjuntos de elementos tipo numérico (clave) 
	realice las operaciones de Unión e Intersección.
	La lista contendra la coleccion de conjuntos.  Cada campo void apunta a un conjunto.
*/
Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Iterador iterador1=iterador(l_de_conjuntos);
    bool bandera=true;
    Conjunto conjuntoA=cto_crear();

    while(hay_siguiente(iterador1)){

        if(bandera){
            TipoElemento elementoAux=siguiente(iterador1);
            conjuntoA=elementoAux->valor;
            bandera=false;
        }else{
            TipoElemento elementoaux=siguiente(iterador1);
            conjuntoA=cto_union(conjuntoA,elementoaux->valor);
        }

    }
    return conjuntoA;

}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto conjuntoB=cto_crear();
    bool bandera=true;
    Iterador iterador2=iterador(l_de_conjuntos);
    while(hay_siguiente(iterador2)){

        if(bandera){
            TipoElemento elementoAux=siguiente(iterador2);
            conjuntoB=elementoAux->valor;
            bandera=false;
        }else{
            TipoElemento elementoaux=siguiente(iterador2);
            conjuntoB=cto_interseccion(conjuntoB,elementoaux->valor);
        }

    }

    return conjuntoB;
}
void operaciones3(Lista coleccion){

    if(l_longitud(coleccion)<3){
        printf("[ERROR] Debe cargar como minimo 3 conjuntos.");
        return;
    }

    Conjunto conjuntoA= c_ej3_uniones(coleccion);
    printf("\n[OUTPUT] Resultado de la UNION de los conjuntos:\n");
    cto_mostrar(conjuntoA);
    
    Conjunto conjuntoB=c_ej3_intersecciones(coleccion);
    printf("[OUTPUT] Resultado de la INTERSECCION entre los conjuntos:\n");
    cto_mostrar(conjuntoB);
}

/////////////////////////////////////////////////////////////////////////////////// 
/*
4. Desarrollar un algoritmo que dado tres conjuntos puedan demostrar la propiedad de la
    transitividad: “si A es subconjunto de B y B a su vez es subconjunto de C, entonces A
    es subconjunto de C”.
*/

bool BuscandoSubconjuntos(Conjunto C1, Conjunto C2) {     
    int nC1 = cto_cantidad_elementos(C1);
    int nC2 = cto_cantidad_elementos(C2);
    if (nC1 == 0 && nC2 == 0) return true;

    int contador = 0;
    TipoElemento X;

    for (int i = 1 ; i <= nC1 ; i++) {
        X = cto_recuperar(C1, i);
        if (cto_pertenece(C2, X->clave)) contador++;
    }

    if(contador == nC1){
        return true;
    }
    else{
        return false;
    }
}

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
    printf("\n/ Verificando propiedad de la transitividad . . .\n");

    bool AB = BuscandoSubconjuntos( A, B);
    bool BC = BuscandoSubconjuntos( B, C);
    bool AC = BuscandoSubconjuntos( A, C);

    if (AB){
        printf("\n> A es subconjunto de B");
    }
    else{
        printf("\n> A no es subconjunto de B");
    }

    if (BC){
        printf("\n> B es subconjunto de C");
    }
    else{
        printf("\n> B no es subconjunto de C");
    }
    if (AC){
        printf("\n> A es subconjunto de C");
    }
    else{
        printf("\n> A no es subconjunto de B");
    }    

    if (AB && BC && AC){
        printf("\n\n/ Conclusion: se verifica la propiedad de la transitividad . . .\n\n");
    }
    else{
        printf("\n\n/ Conclusion: no se verifica la propiedad de la transistividad . . .\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////
/**
5.	Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre dos conjuntos. 
	La diferencia simétrica es una operación entre dos conjuntos donde el conjunto resultante está conformado 
	por los elementos no comunes a los dos conjuntos.
*/
Conjunto c_ej5_dif_simetrica(Conjunto conjuntoA,Conjunto conjuntoB){
    Conjunto dif1=cto_diferencia(conjuntoA,conjuntoB);
    Conjunto dif2=cto_diferencia(conjuntoB,conjuntoA);

    Conjunto resultado=cto_union(dif1,dif2);
    return resultado;
}


/////////////////////////////////////////////////////////////////////////////////// p6

bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    bool subconjuntopropio;
    if(cto_es_vacio(A) && cto_es_vacio(B)){
        printf("\nAmbos conjuntos son vacios\n\n");
    }else if(cto_es_vacio(cto_diferencia(A, B))){
        
        subconjuntopropio= true;
        return subconjuntopropio;
    }else{
        
        subconjuntopropio= false;
        return subconjuntopropio;
    }
}



/////////////////////////////////////////////////////////////////////////////////// p7
/*
7. La complejidad algorítmica es constante sin tener en cuena las implementaciones.
    Teniendo en cuentas las implementaciones vistas en clase, cuando usemos conjuntos implementados con AVL vamos a tener una complejidad de
    O(n log n) ya que se utilizan funciones como "diferencia".
    Y si utilazamos la implementacion de listas la complejidad seria de O(n2) (n al cuadrado).
*/

bool  es_subconjunto_total(Conjunto X, Conjunto Y) {
    Conjunto resultado = cto_diferencia(X, Y);
    return cto_es_vacio(resultado);
}

bool es_subconjunto_parcial(Conjunto X, Conjunto Y) {
    int cantidad = cto_cantidad_elementos(X);
    Conjunto resultado = cto_diferencia(X, Y);
    int cantidad_f = cto_cantidad_elementos(resultado);
    
    return cantidad_f <= (cantidad / 2);

}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C) {
    Conjunto conjuntos[3] = {A, B, C};
    char* nombres[3] = {"A", "B", "C"};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                if (es_subconjunto_total(conjuntos[i], conjuntos[j])) {
                    printf("%s es un subconjunto total de %s\n", nombres[i], nombres[j]);
                } else if (es_subconjunto_parcial(conjuntos[i], conjuntos[j])) {
                    printf("%s es un subconjunto parcial de %s\n", nombres[i], nombres[j]);
                }
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////// p8
/*
8. la complejidad algoritmica de la solucion es O(n**2), 
    siendo n la cantidad de elementos del uno de los conjuntos si los dos conjuntos son iguales.
    La complejidad es la misma con las dos implementaciones.
*/
bool c_ej8_soniguales(Conjunto C1, Conjunto C2) {
    int nC1 = cto_cantidad_elementos(C1);
    int nC2 = cto_cantidad_elementos(C2);
    if (nC1 == 0 && nC2 == 0) return true;
    int contador = 0;
    TipoElemento X;

    if(nC1 == nC2){                       
        for (int i = 1 ; i <= nC1 ; i++) {
            X = cto_recuperar(C1, i);
            if (cto_pertenece(C2, X->clave)) contador++;
        }
    }
    else{
        return false;
    }

    if(contador == nC1){
        return true;
    }
    else{
        return false;
    }
}





//falta acomodar el 4, 3 y 2 y ver como poner el 6. Despues los main
