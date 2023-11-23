#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hola, mundo!";
    char destination[20];

    // Copia el contenido de source a destination
    char *result = strcpy(destination, source);

    // Imprime la cadena de destino
    printf("Cadena de destino: %s\n", destination);

    // Imprime el valor retornado por strcpy (apunta a destination)
    printf("Valor retornado por strcpy: %d\n", (void *)result);

    return 0;
}
