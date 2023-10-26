// nombre del archivo: taller7.c
// autor: Hernandez Ceseña Ivan Fernando
// fecha creacion 25- 10- 23
// este archivo contiene el codigo principal de mi programa. la libreria contiene funciones para validar
// imprime nombres ya definidos en un vet\ctor de cadenas.
// pide al usuario que escriba nombres
// imprime los nombres ingresados y los ya definidos
// ordena 10 palabras en orden alfabetico con el metodo de ordenacion de la brubuja.

#include "ivan.h"

void menu();
int  msg();

int main()
{
    menu();
    return 0;
}

int msg()
{
    int op;
    printf("menu\n");
    printf("1) imprimir nombres\n");
    printf("2) escribir nombres\n");
    printf("3) ordenar palabras\n");
    op = validacionNumero("elige una opcion", 1, 6);
    return op;
}

void menu()
{
    int op;

    do{
        op = msg();

        switch(op)
        {
            case 1:
            imprimirNombres();
            break;

            case 2:
            escribirNombres();
            break;

            case 3:
            ordenar();
            break;
        }
    }while(op != 6);
}


void imprimirNombres()
{
    char *nombres[3] = {"ivan", "fernando", "compadre diego"};
    int i;

    imprimirNombres2(nombres);
}

void escribirNombres()
{
    char *nombres[3];
    int i;

    for(i=0; i<3; i++)
    {
        char nombre[10];
        printf("dame un nombre\n");
        fgets(nombre, sizeof(nombre), stdin);
        nombres[i] = strdup(nombre);
    }

    imprimirNombres2(nombres);
}

void imprimirNombres2(char *nombre[3])
{
    int i;
    for(i=0; i<3; i++)
    {
        printf("%s\n", nombre[i]);
    }
}

void ordenar()
{
    int i, j, num=10;
    char *palabras[num];
    char temp[num];
    char buffer[10];
    for(i=0; i<num; i++)
    {
        palabras[i] = (char *)malloc(10);
        printf("dame una palabra de maximo 10 caracteres\n");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(palabras[i], buffer);
    }

    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if (strcmp(palabras[j], palabras[i]) < 0)
            {
                strcpy(temp, palabras[i]);
                strcpy(palabras[i], palabras[j]);
                strcpy(palabras[j], temp);
            }
        }
    }

    for(i=0; i<num; i++)
    {
        printf("%s\n", palabras[i]);
    }
}