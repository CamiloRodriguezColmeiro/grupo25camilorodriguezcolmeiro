// --- funciones auxiliares ---
int esNumero(const char *cadena) {
    if (cadena == NULL || *cadena == '\0') return 0;
    int i;
    for (  i = 0; cadena[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cadena[i])) return 0;
    }
    return 1;
}

bool Validacion(int n) {
    if (n < 1) {
        printf("Error al ingresar un numero.\n");
        return false;
    }
    return true;
}

int limiteSup(long num2){
    int supe=0;
 if (num2>=INT_MAX) {
            printf("Error: numero demasiado grande debe ser menor a 2.147.483.647.\n");
          //  num2=0;
          supe=1;

        }

return supe;

}




