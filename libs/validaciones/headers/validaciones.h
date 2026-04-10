#include <stdbool.h>

#ifndef validaciones
#define validaciones

//Validaciones

// Limpia buffer
void limpiarBuffer();

// Leer entero validado
int leerEntero(const char* mensaje);

// Leer natural validado
int leerNatural(const char* mensaje);

//Leer cadena
void leerCadena(const char* mensaje, char* destino);

// Validar señal H/L
int esSenialValida(char* s);

// Leer si la cadena es un numero
int esNumero(const char *cadena);

//Limite de valor int
int limiteSup(long num2);

//Quitar espacios en cadenas
void trim(char *str);

//Ver si tiene espacios intermedios y continua la cadena
bool tieneEspaciosInternos(const char *str);

#endif