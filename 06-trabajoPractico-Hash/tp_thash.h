#ifndef TP_ARBOLES_H
#define TP_ARBOLES_H

#include <stdbool.h>
#include <unistd.h>
#include "../libs/TipoElemento/headers/tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/nodo.h"
#include "../libs/arboles/headers/arbol-avl.h"
#include "../libs/hash/headers/tabla_hash.h"
//Auxiliares:///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void limpiar_buffer();

void limpiar_consola();

long long obtener_tiempo_en_nanosegundos();

bool esPrimo(int num);

int encontrarPrimoMasCercano(int num);

static int valorModulo;

int funcionHash(int clave);

typedef struct Persona{
    char nombre[20];
    char apellido[20];
    char DNI[9];
    int dia;
    int mes;
    int anio;
}Persona;

struct Date {
    int day;
    int month;
    int year;
};

struct Alumno {
    int legajo;
    char apellido[20];
    char nombres[20];
    char domicilio[20];
    int telefono;
};


static const int MAX = 100;
static const int NRO_PRIMO = 107;
static int cantidad;
static int cantidadAlumnosArchivo = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
4. Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 
*/

struct Alumno inputAlumno();

struct Alumno consultaAlumnoArchivo(FILE * archivo, int posicionFisicaArchivo);

bool altaAlumno(struct Alumno alumno, FILE * archivo, int posicionFisicaArchivo, TablaHash tabla);

void editAlumno(FILE * archivo, TablaHash tabla);

void mostrarAlumno(struct Alumno alumno);

void mostrarAlumnosDesdeArchivo(FILE * archivo);

void eliminarAlumno(FILE * archivo, TablaHash tabla);
//////////////////////////////////////////
void th_ej4_abm();

void consultarAlumno(FILE * archivo, TablaHash tabla);

void procesarMenu(FILE * archivo, TablaHash tabla);

/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cuál es el rango de las claves a generar.   
   Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/
void th_ej5_comparacion(ArbolAVL A, TablaHash thash, int q_claves, int q_repeticiones, int rango_desde, int rango_hasta, long long * totalTiempoTabla, long long * totalTiempoArbol);


/**
6. Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.  
   Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
   De cada persona se guarda básicamente el DNI, Apellido y Nombre.  
   Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
   que se vacunaron en esa fecha. 
*/
/*
Auxiliares p6:
*/
int es_dni_valido(const char *dni);

int is_leap_year(int year);

int days_in_month(int month, int year);

int days_since_start(struct Date date);


int calcular_clave(int dia, int mes, int anio);

void cargar_paciente_tabla(TablaHash tabla, struct Persona persona);

////Funciones principales punto 6:

void cargar_paciente(TablaHash tabla);

void recuperar_paciente(TablaHash tabla);

void th_ej6_covid(TablaHash tablita, int opcion);

#endif // TP_ARBOLES_H
