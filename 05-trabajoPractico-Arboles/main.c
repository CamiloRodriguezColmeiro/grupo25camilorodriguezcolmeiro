#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <ctype.h>
#include "tp_arboles.h"
///////AUX////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ingresoEntero(int* n){
    char s[10];
    int resultado =0;
    *n=0;
    printf("Ingrese una clave numerica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = 1;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
            else{resultado=2;}
        }
    }
    return resultado;
}

void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    int b;
    if(!a_es_lleno(A)){
        if(sa == -1) {
                printf("Ingrese el hijo izquierdo de %i.\n", N->datos->clave);
            }
            else if(sa == 1) {
                printf("Ingrese el hijo derecho de %i.\n", N->datos->clave);
            }
            else {
                printf("Ingrese la raiz.\n");
            }
        b= ingresoEntero(&n);
        if (b==0){
            X= te_crear(n);

            if(sa == -1) {
                N1 = a_conectar_hi(A, N, X);
            }
            else if(sa == 1) {
                N1 = a_conectar_hd(A, N, X);
            }
            else {
                N1 = a_establecer_raiz(A, X);
            }

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }else if(b==2){
            printf("Ingrese algo valido (valor fuera de rango).\n");
            Cargar_SubArbol(A, N,sa);
        }
    }
}
void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}

////////////////////////////////////////////////////////////////

void Cargar_SubArbol_Nario(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int cant_nodos= 0;
    int n;
    int b;
    if(!a_es_lleno(A)){
        if(sa == -1) {
                printf("Ingrese el hijo izquierdo de %i.\n", N->datos->clave);
            }
            else if(sa == 1) {
                printf("Ingrese el hijo derecho de %i.\n", N->datos->clave);
            }
            else {
                printf("Ingrese la raiz.\n");
            }
        b= ingresoEntero(&n);
        if (b==0){
            X= te_crear(n);
            
            if (sa == 1 && N != NULL && N == a_raiz(A) && cant_nodos < 1) {
                printf("No se permite agregar un hijo derecho a la raíz.Ingrese '.' para nulo.\n");
                Cargar_SubArbol(A, N, sa);
                return;
            }

            if(sa == -1) {
                N1 = a_conectar_hi(A, N, X);
                cant_nodos ++;
            }
            else if(sa == 1) {
                N1 = a_conectar_hd(A, N, X);
                cant_nodos ++;
            }
            else {
                N1 = a_establecer_raiz(A, X);
                cant_nodos ++;
            }

            Cargar_SubArbol_Nario(A, N1, -1);
            Cargar_SubArbol_Nario(A, N1, 1);
        }else if(b==2){
            printf("Ingrese algo valido (valor fuera de rango).\n");
            Cargar_SubArbol_Nario(A, N,sa);
        }
    }
}

void cargar_arbol_nario(ArbolBinario A){
    Cargar_SubArbol_Nario(A, NULL, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main2a(){
    printf("Este ejercicio retorna una lista con todos los nodos terminales u hojas. \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    Lista resul= l_crear();
    resul= a_ej2_hojas(A);

    printf("La lista con los nodos terminales u hojas es: \n");
    l_mostrar(resul);
    printf("\nLa complejidad algoritmica es O(n)\n");
}

void main2b(){
    printf("Este ejercicio retorna en una estructura todos los nodos interiores (los que no son ni hojas ni raíz) \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    Lista resul= l_crear();
    resul= a_ej2_interiores(A);

    if(l_es_vacia(resul)){
        printf("La clave no posee nodos interiores. \n");
    }
    printf("La lista con los nodos interiores es: \n");
    l_mostrar(resul);
    printf("\nLa complejidad algoritmica es O(n)\n");

    return;
}

void main2c(){
    printf("Este ejercicio busca todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo). \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    Lista resul= l_crear();

    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Lista lista = a_ej2_buscarclave(A, clave);

    if (l_es_vacia(lista)){
        printf("\nNo hay ocurrencias con esa clave en el arbol.\n");
    }
    else{
        printf("\nEn la siguiente lista se encuentran los punteros a los nodos de la ocurrencia buscada.\n");
        l_mostrar(lista);
    }

    printf("\nLa complejidad algoritmica es O(n)\n");
    return;
}

void submenu2(){
    int opcion2;
    do{
        printf("\n--- Bienvenido al Submenu del punto 2 --- \n");
        printf("1. Ejercicio 2a \n");
        printf("2. Ejercicio 2b \n" );
        printf("3. Ejercicio 2c \n");
        printf("4. Salir\n");
        scanf("%d", &opcion2);

        switch(opcion2){
            case 1:
                main2a();
                return;
                break;
            case 2:
                main2b();
                return;
                break;
            case 3:
                main2c();
                return;
                break;
            default:
                break;
        }
    } while(opcion2 != 4);
    fflush(stdin);
    printf("\n saliendo del menu... \n");
    system("pause");
    return;
}

///////////////////////////////////////////

void main3a(){
    printf(" Este ejercicio indica el nombre del nodo padre (clave).\n");
    ArbolBinario A= a_crear();
    int clavehijo;

    cargar_arbol_binario(A);
   
    bool seguirAgregando = true;


    while(seguirAgregando){
        printf("Ingrese la clave de la cual desea encontrar el padre: \n");

        if(scanf("%d", &clavehijo) > 0 && clavehijo >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    int padre= a_ej3_clavepadre(A, clavehijo);

    printf("La clave del padre del nodo es: %d", padre);
    return;
}

void main3b(){
    printf("Este ejercicio Lista los hijos de una clave dada: \n");
    Lista resul= l_crear();
    int clavepadre;
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    
    bool seguirAgregando = true;
    while(seguirAgregando){
        printf("Ingrese el nodo del cual quiere buscar los hijos: \n");

        if(scanf("%d", &clavepadre) > 0 && clavepadre >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    resul= a_ej3_hijos(A, clavepadre);
    if(l_es_vacia(resul)){
        printf("La lista no contiene al elemento. \n");
    }
    else{
        printf("Los hijos son: \n");
        l_mostrar(resul);
    }
    return;
}

void main3c(){
    printf(" Este ejercicio indica el nombre del nodo hermano (clave).\n");
    ArbolBinario A= a_crear();
    int clavenodo;

    cargar_arbol_binario(A);
    
    
    bool seguirAgregando = true;

    while(seguirAgregando){
        printf("Ingrese la clave de la cual desea encontrar el hermano: \n");

        if(scanf("%d", &clavenodo) > 0 && clavenodo >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    int hermano= a_ej3_hermano(A, clavenodo);

    printf("La clave del hermano del nodo es: %d", hermano);
    return;
}

void main3d(){
    printf("Este ejercicio calcula el nivel en el que se encuentra la clave de un arbol. \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);

    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    int nivelNodo=a_ej3_nivel(A,clave);

    if(nivelNodo == -1){
        printf("El nodo no se encuentra");
    }
    else{
        printf("El nivel del nodo es: %d", nivelNodo);
    }
    
    return;
}

void main3e(){
    printf("Este punto calcula la altura de un nodo. \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);

    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    int claveRama=a_ej3_alturarama(A,clave);

    if(claveRama==-1){
        printf("La rama es nula.");
    }
    else
    {
        printf("La altura de la rama de %d es %d ", clave, claveRama);
    }

    return;
}

void main3f(){
    printf("Este punto lista todos los nodos que están en el mismo nivel (solo la clave) \n");
    ArbolBinario A= a_crear();
    Lista resultado= l_crear();
    cargar_arbol_binario(A);

    bool seguirAgregando = true;
    int nivel;

    while(seguirAgregando){
        printf("Ingrese el nivel a buscar: ");

        if(scanf("%d", &nivel) > 0 && nivel >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Lista claveNivel=a_ej3_clavesmismonivel(A,nivel);

    if(l_es_vacia(claveNivel)){
        printf("No hay elementos en ese nivel.");
    }
    else{
        l_mostrar(claveNivel);
    }
    return;
}

void submenu3(){
    int opcion3;
    do{
        printf("\n--- Bienvenido al Submenu del punto 3 --- \n");
        printf("1. Ejercicio 3a \n");
        printf("2. Ejercicio 3b \n" );
        printf("3. Ejercicio 3c \n");
        printf("4. Ejercicio 3d \n");
        printf("5. Ejercicio 3e \n");
        printf("6. Ejercicio 3f \n");
        printf("7. Salir\n");
        scanf("%d", &opcion3);

        switch(opcion3){
            case 1:
                main3a();
                return;
                break;
            case 2:
                main3b();
                return;
                break;
            case 3:
                main3c();
                return;
                break;
            case 4:
                main3d();
                return;
                break;
            case 5:
                main3e();
                return;
                break;
            case 6:
                main3f();
                return;
                break;
            default:

                break;
        }
    } while(opcion3 != 7);
    fflush(stdin);
    printf("\n saliendo del menu... \n");
    system("pause");
    return;
}

///////////////////////////////////////////
void main4a(){
    printf("\n Este punto muestra en forma de lista el recorrido de la anchura del arbol. \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    Lista resultado= l_crear();

    resultado= a_ej4_anchura(A);
    printf("El recorrido en anchura del arbol es: \n");
    l_mostrar(resultado);

    return;
}

void main4b(){
    printf("\nEste punto cuenta las hojas de un arbol n-ario: \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    int resultado;

    resultado= a_ej4_q_hojas(A);
    printf("La cantidad de hojas del arbol es: %d", resultado);

    return;
}

void main4c(){
    printf("\n Este punto determina si dos arboles son iguales en estructura sin tener en cuenta su interior: \n");
    ArbolBinario A= a_crear();
    printf("\n --- CARGANDO ARBOL 1 --- \n");
    cargar_arbol_binario(A);
    ArbolBinario B= a_crear();
    printf("\n --- CARGANDO ARBOL 2 --- \n");
    cargar_arbol_binario(B);
    
    if (a_ej4_similares(A,B)){
        printf("\n Los arboles son similares\n");
    }
    else{
        printf("\n Los arboles NO son similares\n");
    }

    return;
}

void main4d(){
    printf("Este punto indica el padre de un nodo dentro de un arbol n-ario: \n");
    ArbolBinario A= a_crear();
    cargar_arbol_binario(A);
    TipoElemento resultado;

    TipoElemento padreNodo=te_crear(0);

    bool seguirAgregando = true;
    int nodoHijo;

    while(seguirAgregando){
        printf("\nSelecciona un nodo para buscar a su nodo padre: ");

        if(scanf("%i", &nodoHijo) > 0 && nodoHijo >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    padreNodo=a_ej4_padre(A, nodoHijo);
    
    if (padreNodo != NULL){
        printf("El padre del nodo seleccionado es: %i\n", padreNodo->clave);
    }
    else{
        printf("No se pudo encontrar el padre del nodo que seleccionaste.\n");
    }
    return ;
}

void main4e(){
    printf("Este punto lista los hermanos de un nodo. \n");
    ArbolBinario arbol = a_crear();
    cargar_arbol_binario(arbol);

    bool seguirAgregando = true;
    int nodo;

    while(seguirAgregando){
        printf("\nSelecciona un nodo para buscar a sus nodos hermanos: ");

        if(scanf("%i", &nodo) > 0 && nodo >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    Lista her=a_ej4_hermanos(arbol,nodo);

    if (l_es_vacia(her)){
        printf("\nEl nodo seleccionado no tiene hermanos.\n");
    }
    else{
        printf("\nLos nodos hermanos del nodo seleccionado estan en la siguiente lista.\n");
        l_mostrar(her);
    }
    return;
}

void submenu4(){
    int opcion4;
    do{
        printf("\n--- Bienvenido al Submenu del punto 4 --- \n");
        printf("1. Ejercicio 4a \n");
        printf("2. Ejercicio 4b \n" );
        printf("3. Ejercicio 4c \n");
        printf("4. Ejercicio 4d \n");
        printf("5. Ejercicio 4e \n");
        printf("7. Salir\n");
        scanf("%d", &opcion4);

        switch(opcion4){
            case 1:
                main4a();
                return;
                break;
            case 2:
                main4b();
                return;
                break;
            case 3:
                main4c();
                return;
                break;
            case 4:
                main4d();
                return;
                break;
            case 5:
                main4e();
                return;
                break;
            default:
                break;
        }
    } while(opcion4 != 6);
    fflush(stdin);
    printf("\n saliendo del menu... \n");
    system("pause");
    return;
}

///////////////////////////////////////////

void main7(){
    printf("\n Este punto determina si dos arboles son equivalentes. \n ");
    ArbolBinario A= a_crear();
    printf("\n --- Carga del primer arbol --- \n");
    cargar_arbol_binario(A);

    ArbolBinario B= a_crear();
    printf("\n --- Carga del segundo arbol --- \n ");
    cargar_arbol_binario(B);

    bool resultado;
    resultado= a_ej7_equivalente(A, B);
    if(resultado == true){
        printf("Los arboles SON equivalentes. \n");
        return;
    }
    else{
        printf("Los arboles NO SON equivalentes. \n");
        return;
    }
}

//////////////////////////////////////////

void main8a(ArbolBinario A){
    printf("Este ejercicio devuelve la altura del arbol. \n");
    int resultado= a_ej8_altura(A);
    printf("La altura del arbol es: %d", resultado);

    return;
}

void main8b(ArbolBinario A){
    printf("Este ejercicio devuelve el nivel de un nodo. \n");
    int resultado;
    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        printf("Ingrese la clave a buscar: ");

        if(scanf("%d", &clave) > 0 && clave >= 0){
            seguirAgregando = false;
        }
        else{
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    resultado= a_ej8_nivel(A, clave);
    printf("El nodo se encuentra en el nivel: %d", resultado);

    return;
}

void main8c(ArbolBinario A){
    printf("Este punto lista los nodos internos del arbol. \n");
    Lista resultado= l_crear();

    resultado= a_ej8_internos(A);
    if(l_es_vacia(resultado)){
        printf("No hay nodos internos.");
        return;
    }
    printf("Los nodos internos son: \n");
    l_mostrar(resultado);
    return;
}

void main8d(ArbolBinario A){ 
    printf("Este ejercicio comprueba si todas las hojas del arbol estan al mismo nivel");
    bool hojasMismoNivel = a_ej8_hojasmismonivel(A);

    if(hojasMismoNivel){
        printf("Si estan al mismo nivel.");
    }else{
        printf("No estan al mismo nivel");
    }

    return;
}

void submenu8(){
    int opcion8;
    printf("\nEn este punto se usara el mismo arbol para cada ejercicio a realizar, primero cargue el arbol. \n");
    ArbolBinario A= a_crear();
    cargar_arbol_nario(A);
    do{
        printf("\n--- Bienvenido al Submenu del punto 8 --- \n");
        printf("1. Ejercicio 8a \n");
        printf("2. Ejercicio 8b \n" );
        printf("3. Ejercicio 8c \n");
        printf("4. Ejercicio 8d \n");
        printf("5. Salir\n");
        scanf("%d", &opcion8);

        

        switch(opcion8){
            case 1:
                main8a(A);
                break;
            case 2:
                main8b(A);
                break;
            case 3:
                main8c(A);
                break;
            case 4:
                main8d(A);
                break;
            default:

                break;
        }
    } while(opcion8 != 5);
    fflush(stdin);
    printf("\n saliendo del menu... \n");
    system("pause");
    return;
}

////////////////////////////////////////////////////////////////////
void main9(){
    printf("este punto transforma un arbol binario en avl y compara la altura del avl con el binario original.\n");

    ArbolBinario AB = a_crear();
    cargar_arbol_binario(AB);

    int alturaAB = alturaArbol(a_raiz(AB));
    printf("Altura del arbol binario: %d\n", alturaAB);

    ArbolAVL AVL = a_ej9_construiravl(AB);

    int alturaAVL = AVL->raiz ? AVL->raiz->FE : -1;
    printf("Altura del arbol AVL: %d\n", alturaAVL);

    int diferencia = a_ej9_diferenciaalturas(AB, AVL);
    printf("Diferencia de altura (Binario - AVL): %d\n", diferencia);

    printf("\nLa complejidad algoritmica es O(n log n)\n");
}

////////////////////////////////////////////////////////////////////
void main10(){
    int repeticiones, cantidad_claves, min, max;
    printf("=== Comparación de altura entre ABB y AVL ===\n");

    do {
        printf("Ingrese la cantidad de repeticiones (> 0): ");
        scanf("%d", &repeticiones);
        if (repeticiones <= 0) {
            printf("La cantidad de repeticiones debe ser mayor que cero.\n");
        }
    } while (repeticiones <= 0);

    do {
        printf("Ingrese la cantidad de claves por prueba (> 0): ");
        scanf("%d", &cantidad_claves);
        if (cantidad_claves <= 0) {
            printf(" La cantidad de claves debe ser mayor que cero.\n");
        }
    } while (cantidad_claves <= 0);

    do {
        printf("Ingrese el valor mínimo del rango: ");
        scanf("%d", &min);
        printf("Ingrese el valor máximo del rango: ");
        scanf("%d", &max);

        if (max < min) {
            printf(" El valor máximo debe ser mayor o igual al mínimo.\n");
        } else if ((max - min + 1) < cantidad_claves) {
            printf(" El rango no permite generar %d claves únicas. Rango disponible: %d\n", cantidad_claves, max - min + 1);
        }
    } while (max < min || (max - min + 1) < cantidad_claves);
    srand((unsigned int) time(NULL));
    Lista diferencias = a_ej10_comparacionarboles(repeticiones, min, max, cantidad_claves);
    printf("\n Diferencias de altura (ABB - AVL) en cada repetición:\n");
    l_mostrar(diferencias);
    Iterador it = iterador(diferencias);
    int suma = 0;
    while (hay_siguiente(it)) {
        TipoElemento t = siguiente(it);
        suma += t->clave;
    }
    float promedio = (float)suma / repeticiones;
    printf("\n Promedio de diferencia de altura: %.2f\n", promedio);
    printf("\nLa complejidad algoritmica es: O(n log n)  \n");
    return;
}

////////////////////////////////////////////////////////////////////
int main(){
    int opcion;

    do {
        printf("\n--- Menu de Opciones ---\n");
        printf("1. salir\n");
        printf("2. Ejercicio 2 (Submenu) \n");
        printf("3. Ejercicio 3 (Submenu) \n");
        printf("4. Ejercicio 4 (Submenu) \n");
        printf("5. Ejercicio 7\n");
        printf("6. Ejercicio 8 (submenu) \n");
        printf("7. Ejercicio 9\n");
        printf("8. Ejercicio 10\n");
        printf("Seleccione una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                break;
            case 2:
                submenu2();
                return 0;
                break;
            case 3:
                submenu3();
                return 0;
                break;
            case 4:
                submenu4();
                return 0;
                break;
            case 5:
                main7();
                return 0;
                break;
            case 6:
                submenu8();
                return 0;
                break;
            case 7:
                main9();
                return 0;
                break;
            case 8:
                main10();
                return 0;
                break;
            default:
                printf("\nNo elegiste una opcion valida, por favor ingresa un dato valido. \n");
        }

    }while(opcion != 8);

    return 0;
}

