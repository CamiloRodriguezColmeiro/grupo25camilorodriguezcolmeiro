#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <ctype.h>
#include "tp_conjunto.h"

void main2(){
    bool seguiragregando=true;
    int clave=0;
    char claveChar;
    int indice=1;

    Conjunto A=cto_crear();
    while(seguiragregando){
        printf("[INPUT] Ingrese el elemento %d del conjunto A ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(A,te_crear(clave));
            indice++;
        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto A.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }

    seguiragregando = true;
    indice = 1;          // <-- agregado

    Conjunto B=cto_crear();
    while(seguiragregando){
        printf("[INPUT] Ingrese el elemento %d del conjunto B ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(B,te_crear(clave));
            indice++;
        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("[INFO] Terminando ingreso del conjunto B.\n");
            }else{
                printf("[ERROR] Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
    }

    cto_mostrar(A);
    cto_mostrar(B);

    operaciones(A,B);
}
/////////////////////////////////////////////////////////////////////////////////////////

void main3(){
    bool seguirconju=true;
    bool seguiragregando=true;
    int clave=0;
    char claveChar;
    int indice=1;
    int indicecon=1;
    Lista coleccion=l_crear();
    bool otroconju=true;

    while(seguirconju){
        Conjunto conju=cto_crear();
        while(seguiragregando){
            
            printf("[INPUT] Ingrese el elemento %d del conjunto %d ('n' para terminar de cargar el conjunto):",indice,indicecon);
            if(scanf("%d",&clave)>0){
                cto_agregar(conju,te_crear(clave));
                indice++;

            }else{
                if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                    seguiragregando = false;
                    printf("[INFO] Terminando ingreso del conjunto.\n");
                }
                else{
                    printf("[ERROR] Debe ingresar un valor valido.\n");
                }

                fflush(stdin);

            }
            
        }
        l_agregar(coleccion,te_crear_con_valor(0,conju));
        indicecon++;
        indice=1;
        otroconju=true;
        while(otroconju){
            printf("[INPUT] Desea agregar otro conjunto? (1 para SI, 2 para NO):");
            if(scanf("%d",&clave)>0 && (clave==1 || clave ==2)){
                if(clave==1){
                    seguirconju=true;
                    seguiragregando=true;
                    otroconju=false;
                }else if(clave==2){
                    seguirconju=false;
                    otroconju=false;
                }
            }else{
                printf("[ERROR] ingrese una opcion valida.\n");
            }
            fflush(stdin);
        }
        
    }

    operaciones3(coleccion);
    return; 
}
/////////////////////////////////////////////////////////////////////////////////////////
void main4(){
     Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf(" Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf(" Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoC=cto_crear();
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del tercer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoC,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    c_ej4_transitividad(conjuntoA, conjuntoB, conjuntoC);
    
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void main5(){
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }   
    Conjunto resu= cto_crear();
    resu= c_ej5_dif_simetrica(conjuntoA, conjuntoB);
    printf("\nEl resultado de la diferencia simetrica entre los dos conjuntos es:\n");
    cto_mostrar(resu);

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void main6(){
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf(" Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf(" Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }

    bool resultado= c_ej6_subconjuntopropio(conjuntoA, conjuntoB);
    if(resultado == true){
        printf("\nEl conjunto A es subconjunto del conjunto B\n\n");
    }
    else{
        printf("\nEl conjunto A no es subconjunto de B\n\n");
    }


    printf("La complejidad algoritmica depende del TAD utilizado. Si se utiliza Conjuntos de listas la complejidad sera de O(n^2), ya que se utiliza la operacion de cto_diferencia() la cual recorre la lista de forma lineal. En cambio al utilizar el TAD de conjuntos con arboles AVL la complejidad pasara a ser O(n log n) ya que el recorrido de un arbol AVL es mas eficiente y no hace falta recorrer todo el arbol.");
    return;

}
/////////////////////////////////////////////////////////////////////////////////////////
void main7(){
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            TipoElemento elem1 = te_crear(clave);
            cto_agregar(conjuntoA,elem1);
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf(" Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            TipoElemento elem2 = te_crear(clave);
            cto_agregar(conjuntoB,elem2);
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoC=cto_crear();
    while(seguiragregando){
            
        printf(" Ingrese el elemento %d del tercer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            TipoElemento elem3 = te_crear(clave);
            cto_agregar(conjuntoC,elem3);
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    c_ej7_subconjtotalparcial(conjuntoA, conjuntoB, conjuntoC);
    printf("La complejidad algorítmica es constante sin tener en cuena las implementaciones. Teniendo en cuentas las implementaciones vistas en clase, cuando usemos conjuntos implementados con AVL vamos a tener una complejidad de O(n log n) ya que se utilizan funciones como 'diferencia'. Y si utilazamos la implementacion de listas la complejidad seria de O(n2) (n al cuadrado).");

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void main8(){
    Conjunto conjuntoA=cto_crear();
    bool seguiragregando=true;
    int indice=1;
    int clave=0;
    char claveChar;
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del primer conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoA,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }
    
    seguiragregando=true;
    indice=1;

    Conjunto conjuntoB=cto_crear();
    while(seguiragregando){
            
        printf("Ingrese el elemento %d del segundo conjunto ('n' para terminar de cargar el conjunto):",indice);
        if(scanf("%d",&clave)>0){
            cto_agregar(conjuntoB,te_crear(clave));
            indice++;

        }else{
            if(scanf("%c", &claveChar) > 0 && claveChar == 'n'){
                seguiragregando = false;
                printf("Terminando ingreso del conjunto.\n");
            }
            else{
                printf("Debe ingresar un valor valido.\n");
                }

            fflush(stdin);

        }
    }

    if (c_ej8_soniguales(conjuntoA, conjuntoB)){
        printf("\n> Los conjuntos son iguales.");
    }
    else{
        printf("\n> Los conjuntos no son iguales.");
    }
    printf("\nla complejidad algoritmica de la solucion es O(n**2), siendo n la cantidad de elementos del uno de los conjuntos si los dos conjuntos son iguales. La complejidad es la misma con las dos implementaciones.");
    return ;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main() {
    int opcion;

    do {
        printf("\n==== MENÚ DE OPCIONES ====\n");
        printf("1. Punto 2\n");
        printf("2. Punto 3\n");
        printf("3. Punto 4\n");
        printf("4. Punto 5\n");
        printf("5. Punto 6\n");
        printf("6. Punto 7\n");
        printf("7. Punto 8\n");
        printf("8. Salir\n");
        printf("Seleccione una opción (1-8): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                main2();
                
                break;
            case 2:
                main3();
                
                break;
            case 3:
                main4();
                
                break;
            case 4:
                main5();
                
                break;
            case 5:
                main6();
                
                break;
            case 6:
                main7();
                
                break;
            case 7:
                main8();
                
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 8);

    return 0;
}
