#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "time.h"
#include "tp_thash.h"

/**
4. Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 

*/
struct Alumno inputAlumno(){
    struct Alumno alumno;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el apellido del alumno: ");

        if (scanf("%s", alumno.apellido) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el nombre del alumno: ");

        if (scanf("%s", alumno.nombres) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    while (seguirAgregando)
{
    printf(" Ingrese el domicilio del alumno: ");
    while (getchar() != '\n');
    if (fgets(alumno.domicilio, sizeof(alumno.domicilio), stdin) != NULL)
    {
        // Eliminar salto de línea si quedó
        alumno.domicilio[strcspn(alumno.domicilio, "\n")] = '\0';

        if (strlen(alumno.domicilio) > 0) {
            seguirAgregando = false;
        } else {
            printf("Debe ingresar un domicilio no vacío.\n");
        }
    }
    else
    {
        printf("Debe ingresar un valor válido.\n");
    }
}
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el telefono del alumno: (11........)");

        if (scanf("%i", &alumno.telefono) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el legajo del alumno: (6 digitos)");

        if (scanf("%i", &alumno.legajo) > 0)
        {
            if (alumno.legajo >= 100000 && alumno.legajo<= 999999){
            seguirAgregando = false;
            } else{
            printf(" Debe ingresar un valor valido de 6 digitos.\n");
            fflush(stdin);
            }
        }
        else
        {
            printf(" Debe ingresar un valor valido de 6.\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    return alumno;
}

struct Alumno consultaAlumnoArchivo(FILE * archivo, int posicionFisicaArchivo){
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    
    struct Alumno alumno;
    fread(&alumno, sizeof(struct Alumno), 1, archivo);

    return alumno;
}

bool altaAlumno(struct Alumno alumno, FILE * archivo, int posicionFisicaArchivo, TablaHash tabla){
    fflush(archivo);
    if(th_recuperar(tabla, alumno.legajo) != NULL){
        printf(" El legajo ingresado ya pertenece a un alumno.\n");
        return false;
    }
    fseek(archivo, sizeof(struct Alumno) * posicionFisicaArchivo, SEEK_SET);
    fwrite(&alumno, sizeof(struct Alumno), 1, archivo);
    th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) posicionFisicaArchivo));///
    printf(" El alumno ha sido guardado en el archivo!\n");
    fflush(archivo);
    return true;
}

void editAlumno(FILE * archivo, TablaHash tabla){
    int legajo;
    TipoElemento elementoAlumno;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el legajo del alumno a editar (6 dígitos): ");

        if (scanf("%d", &legajo) == 1)
        {
            if (legajo >= 100000 && legajo <= 999999) {
                elementoAlumno = th_recuperar(tabla, legajo);
                if (elementoAlumno != NULL) {
                    seguirAgregando = false;  // Todo OK, salir del loop
                } else {
                    printf(" El legajo ingresado no pertenece a ningun alumno.\n");
                }
            } else {
                printf(" El legajo debe tener exactamente 6 dígitos.\n");
            }
        }
        else
        {
            printf(" Entrada invalida. Intente de nuevo.\n");
            while (getchar() != '\n'); // Limpia el buffer
        }
    }

    struct Alumno alumno = consultaAlumnoArchivo(archivo, (int) elementoAlumno->valor);

    seguirAgregando= true;
    while (seguirAgregando)
    {
        printf("Ingrese el apellido del alumno (%s): ", alumno.apellido);

        if (scanf("%s", alumno.apellido) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("Ingrese el nombre del alumno (%s): ", alumno.nombres);

        if (scanf("%s", alumno.nombres) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("Ingrese el domicilio del alumno (%s): ", alumno.domicilio);

        if (scanf("%s", alumno.domicilio) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    seguirAgregando = true;

    while (seguirAgregando)
    {
        printf("Ingrese el telefono del alumno (%i): ", alumno.telefono);
        fflush(stdin);
        if (scanf("%i", &alumno.telefono) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf("Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
    
    th_eliminar(tabla, legajo);

    altaAlumno(alumno, archivo, (int) elementoAlumno->valor, tabla);
}

void mostrarAlumno(struct Alumno alumno){
    printf("\n Datos de Alumno: \n");
    printf(" > Legajo: %i \n", alumno.legajo);
    printf(" > Nombre: %s \n", alumno.nombres);
    printf(" > Apellido: %s \n", alumno.apellido);
    printf(" > Domicilio: %s \n", alumno.domicilio);
    printf(" > Telefono: %i \n\n", alumno.telefono);
}

void mostrarAlumnosDesdeArchivo(FILE * archivo){
    rewind(archivo);
    int indiceAlumnoActual = 0;
    struct Alumno alumno;
    while(fread(&alumno, sizeof(struct Alumno), 1, archivo)){
        //struct Alumno alumno = consultaAlumnoArchivo(archivo, indiceAlumnoActual);
        //th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) indiceAlumnoActual));
        mostrarAlumno(alumno);
        indiceAlumnoActual++;
    }

    if(indiceAlumnoActual == 0){
        printf(" No hay ningun alumno cargado!\n");
    }
}

void eliminarAlumno(FILE * archivo, TablaHash tabla){
    int legajo;
    bool seguirAgregando = true;

    while (seguirAgregando)
    {
        printf(" Ingrese el legajo del alumno a eliminar: ");

        if (scanf("%i", &legajo) > 0)
        {
            seguirAgregando = false;
        }
        else
        {
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    TipoElemento elementoAlumno = th_recuperar(tabla, legajo);

    if (elementoAlumno == NULL) {
        printf(" Alumno no encontrado.\n");
        return;
    }

    int posicion = (int) elementoAlumno->valor;
    struct Alumno alumno;

    // Mover todos los registros siguientes una posición hacia atrás
    fseek(archivo, sizeof(struct Alumno) * (posicion + 1), SEEK_SET);
    while (fread(&alumno, sizeof(struct Alumno), 1, archivo)) {
        fseek(archivo, sizeof(struct Alumno) * (posicion), SEEK_SET);
        fwrite(&alumno, sizeof(struct Alumno), 1, archivo);
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, (void*) posicion));////
        posicion = (int) th_recuperar(tabla, alumno.legajo)->valor;
        fseek(archivo, sizeof(struct Alumno) * (posicion + 1), SEEK_SET);
    }

    // Truncar el archivo para eliminar el último registro duplicado
    fseek(archivo, sizeof(struct Alumno) * (posicion), SEEK_SET);
    fflush(archivo);
    int resultado = ftruncate(fileno(archivo), sizeof(struct Alumno) * (cantidadAlumnosArchivo-1));
    fflush(archivo);
    if (resultado == 0) {
        printf(" Alumno eliminado!\n");
    } else {
        printf(" Error al truncar el archivo.\n");
    }

    th_eliminar(tabla, legajo);
    cantidadAlumnosArchivo--;
}


void th_ej4_abm(){
    printf(" [MENU]\n\n");
    printf(" 1 - Mostrar todos los alumnos.\n");
    printf(" 2 - Cargar nuevo alumno.\n");
    printf(" 3 - Ver alumno por legajo.\n");
    printf(" 4 - Editar alumno por legajo.\n");
    printf(" 5 - Eliminar alumno por legajo.\n");
    printf(" 6 - Mostrar tabla hash.\n\n");
}

void consultarAlumno(FILE * archivo, TablaHash tabla){
    bool seguirAgregando = true;
    int legajo;

    while(seguirAgregando){
        printf(" Ingrese el legajo a consultar: ");

        if(scanf("%d", &legajo) > 0){
            seguirAgregando = false;
        }
        else{
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }

    TipoElemento elementoAlumno = th_recuperar(tabla, legajo);

    if(elementoAlumno == NULL){
        printf(" El alumno ingresado no existe.\n");
        return;
    }

    struct Alumno alumno = consultaAlumnoArchivo(archivo, (int) elementoAlumno->valor);

    mostrarAlumno(alumno);
}

void procesarMenu(FILE * archivo, TablaHash tabla){
    bool seguirAgregando = true;
    int clave;

    while(seguirAgregando){
        th_ej4_abm();

        if(scanf("%d", &clave) > 0 && clave >= 1 && clave <= 6){
            switch(clave){
                case 1: {
                    mostrarAlumnosDesdeArchivo(archivo);
                    break;
                }
                case 2: {
                    struct Alumno alumno = inputAlumno();
                    if(altaAlumno(alumno, archivo, cantidadAlumnosArchivo, tabla)) cantidadAlumnosArchivo++;;
                    break;
                }
                case 3: {
                    consultarAlumno(archivo, tabla);
                    break;
                }
                case 4: {
                    editAlumno(archivo, tabla);
                    break;
                }
                case 5: {
                    eliminarAlumno(archivo, tabla);
                    break;
                }
                case 6: {
                    th_mostrar(tabla);
                    break;
                }
                default: {
                    printf(" Debe ingresar un valor valido.\n");
                    break;
                }
            }
        }
        else{
            printf(" Debe ingresar un valor valido.\n");
            fflush(stdin);
        }
    }
}
/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cuál es el rango de las claves a generar.   
   Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 

*/

//Auxiliares Punto 5://///////////////////////////////////////////////////////////////////////////////////////////////////// 
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

long long obtener_tiempo_en_nanosegundos() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    return (start.QuadPart * 1000000000) / frequency.QuadPart;
}

#else
#include <sys/time.h>
#include <unistd.h>

#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC 1
#endif

long long obtener_tiempo_en_nanosegundos() {
    struct timespec tiempo;
    clock_gettime(CLOCK_MONOTONIC, &tiempo);
    return (long long) tiempo.tv_sec * 1000000000LL + (long long) tiempo.tv_nsec;
}

#endif

bool esPrimo(int num){
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) 
            return false;
    return true;
}

int encontrarPrimoMasCercano(int num) {
    if (num <= 1) return 2;
    else if (esPrimo(num)) return num;

    int menorPrimo = num - 1;
    int mayorPrimo = num + 1;

    while (true) {
        if (esPrimo(menorPrimo)) return menorPrimo;
        else if (esPrimo(mayorPrimo)) return mayorPrimo;

        menorPrimo--;
        mayorPrimo++;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void th_ej5_comparacion(ArbolAVL A, TablaHash thash, int q_claves, int q_repeticiones, int rango_desde, int rango_hasta, long long * totalTiempoTabla, long long * totalTiempoArbol){
        srand(time(NULL));

    int rango = rango_hasta - rango_desde + 1;
    bool *usado = calloc(rango, sizeof(bool)); 

    int clavesGeneradas = 0;
    while (clavesGeneradas < q_claves) {
        int numeroGenerado = rand() % rango + rango_desde;  

        if (!usado[numeroGenerado - rango_desde]) {
            usado[numeroGenerado - rango_desde] = true;

            TipoElemento nuevo = te_crear(numeroGenerado);
            avl_insertar(A, nuevo);
            th_insertar(thash, nuevo);

            clavesGeneradas++;
        }
    }

    for (int i = 0; i < q_repeticiones; i++) {
        int claveBuscada = rand() % rango + rango_desde;

        long long tiempoInicio1 = obtener_tiempo_en_nanosegundos();
        TipoElemento elementoBuscadoArbol = avl_buscar(A, claveBuscada);
        long long tiempoFin1 = obtener_tiempo_en_nanosegundos();

        *totalTiempoArbol += (tiempoFin1 - tiempoInicio1);
    }

    for (int i = 0; i < q_repeticiones; i++) {
        int claveBuscada2 = rand() % rango + rango_desde;

        long long tiempoInicio2 = obtener_tiempo_en_nanosegundos();
        TipoElemento elementoBuscadoTabla = th_recuperar(thash, claveBuscada2);
        long long tiempoFin2 = obtener_tiempo_en_nanosegundos();

        *totalTiempoTabla += (tiempoFin2 - tiempoInicio2);
    }

    free(usado); 
}

/*
6. Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha determinada se presentaron a vacunar contra el COVID.
Es decir dada una fecha determinada debería obtener quienes se vacunaron. De cada persona se guarda básicamente el DNI, Apellido y Nombre.
Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas que se vacunaron en esa fecha. 
*/
//Auxiliares pto6://////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int es_dni_valido(const char *dni) {
    // Verifica que tenga exactamente 8 caracteres y que todos sean dígitos
    if (strlen(dni) != 8) return 0;

    for (int i = 0; i < 8; i++) {
        if (!isdigit(dni[i])) return 0;
    }
    return 1;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int days_in_month(int month, int year) {
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_per_month[month - 1];
}

int days_since_start(struct Date date) {
    struct Date start_date = {1, 4, 2020};
    int days = 0;

    for (int year = start_date.year; year < date.year; year++) {
        days += is_leap_year(year) ? 366 : 365;
    }

    for (int month = 1; month < date.month; month++) {
        days += days_in_month(month, date.year);
    }
    days += date.day - 1;

    for (int month = 1; month < start_date.month; month++) {
        days -= days_in_month(month, start_date.year);
    }
    days -= (start_date.day - 1);

    return days;
}

void limpiar_consola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int calcular_clave(int dia, int mes, int anio) {
    struct Date date = {dia, mes, anio};
    int dias_transcurridos = days_since_start(date);
    int posicion_hash = dias_transcurridos; // % MAX?
    return posicion_hash;
}

void cargar_paciente_tabla(TablaHash tabla, struct Persona persona) {
    int clave = calcular_clave(persona.dia, persona.mes, persona.anio);

    struct Persona* nueva_persona = (struct Persona*)malloc(sizeof(struct Persona));
    if (nueva_persona == NULL) {
        printf("[ERROR] No se pudo asignar memoria para la nueva persona.\n");
        return;
    }
    *nueva_persona = persona;

    TipoElemento te = te_crear_con_valor(clave, nueva_persona);
    TipoElemento old = th_recuperar(tabla, clave);

    if (old == NULL) {
        Lista lista = l_crear();
        l_agregar(lista, te);
        if (th_insertar(tabla, te_crear_con_valor(clave, (void*) lista))) {
            printf("[INFO] Persona cargada exitosamente.\n");
        } else {
            printf("[ERROR] No se pudo cargar la persona.\n");
        }
    } else {
        Lista lista = (Lista) old->valor;
        l_agregar(lista, te);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargar_paciente(TablaHash tabla){
    struct Persona persona;
    bool continuar = true;

    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &persona.anio) > 0 && persona.anio >= 2020){
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &persona.mes) == 1 && ((persona.anio == 2020 && persona.mes >= 4) || (persona.anio > 2020 && persona.mes > 0 && persona.mes <= 12))) {
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &persona.dia) == 1 && persona.dia > 0 && persona.dia <= 31){
            continuar = false;

        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin); 
        }

    }

    fflush(stdin); 

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el nombre del paciente: \n");
        if(fgets(persona.nombre, sizeof(persona.nombre), stdin) != NULL){
            persona.nombre[strcspn(persona.nombre, "\n")] = '\0';
            if(strlen(persona.nombre) > 0) {
                continuar = false;
            }
            else {
                printf("[ERROR] Debe ingresar un valor válido. \n");
            }
        }  
        else{
            printf("[ERROR] Debe ingresar un valor válido. \n");
            fflush(stdin);
        }
    }

    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el apellido del paciente: \n");
        if(fgets(persona.apellido, sizeof(persona.apellido), stdin) != NULL){
            persona.apellido[strcspn(persona.apellido, "\n")] = '\0';
            if(strlen(persona.apellido) > 0) {
                continuar = false;
            }
            else{
                printf("[ERROR] Debe ingresar un valor válido. \n");
            }
        }
        else{
            printf("[ERROR] Debe ingresar un valor válido. \n");
            fflush(stdin);
        }

    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el DNI del paciente (Sin puntos): \n");
        if (fgets(persona.DNI, sizeof(persona.DNI), stdin) != NULL){
            persona.DNI[strcspn(persona.DNI, "\n")] = '\0'; // Eliminar el salto de línea

            if (es_dni_valido(persona.DNI)) {
                continuar = 0; // Salir del bucle si es válido
            } else {
                printf("[ERROR] El DNI debe contener exactamente 8 dígitos numéricos.\n");
            }
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido. \n");
            fflush(stdin); 
        }

    }
    //persona.clave = calcular_clave(persona.dia,persona.mes, persona.anio);
    cargar_paciente_tabla(tabla, persona);
    return;
}

void recuperar_paciente(TablaHash tabla){
    bool continuar = true;
    int dia, mes, anio, clave;
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el anio de vacunacion: \n");
        if(scanf("%d", &anio)== 1 && anio >= 2020){
            limpiar_buffer();
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el mes de vacunacion: \n");
        if (scanf("%d", &mes) == 1 && ((anio == 2020 && mes >= 4) || (anio > 2020 && mes > 0 && mes <= 12))) {
            limpiar_buffer();
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }
    continuar = true;
    while (continuar){
        printf("[INFO] Ingrese el dia de vacunacion: \n");
        if (scanf("%d", &dia) == 1 && dia > 0 && dia <= 31){
            limpiar_buffer();
            continuar = false;
        } 
        else{
            printf("[ERROR] Debe ingresar un valor valido mayor al 01/04/2020. \n");
            fflush(stdin);
        }
    }

    clave = calcular_clave(dia, mes, anio);
    TipoElemento elemento = th_recuperar(tabla, clave);
    limpiar_consola();
    if (elemento != NULL) {
        Lista lista = (Lista) elemento->valor;
        Iterador iter = iterador(lista);
        while(hay_siguiente(iter)){
            TipoElemento sig = siguiente(iter);
            struct Persona* persona = (struct Persona*) sig->valor;
            printf("[INFO] Datos de la persona vacunada:\n");
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("DNI: %s\n", persona->DNI);
            printf("\n");
        }
    } else {
        printf("[ERROR] No se encontró ninguna persona vacunada en esa fecha.\n");
    }
    return;
}

void th_ej6_covid(TablaHash tablita, int opcion){
    if(opcion == 1){
        cargar_paciente(tablita);
    }
    if (opcion == 2){
        recuperar_paciente(tablita);
        
    }
    return;
}
