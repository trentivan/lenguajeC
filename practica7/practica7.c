

#include "ivan.h"

int msg();
void ordenar();
void operaciones(int matriz[][3], int m, int n);

int main(int argc, char *argv[]) 
{

    // convertimos los argumentos obtenidos a numeros
    int numero1 = atoi(argv[1]);
    int numero2 = atoi(argv[2]);

    // realizamos y mostramos el resultado
    printf("Suma: %d + %d = %d\n", numero1, numero2, numero1+numero2);
    printf("Resta: %d - %d = %d\n", numero1, numero2, numero1-numero2);
    printf("Multiplicacion: %d * %d = %d\n", numero1, numero2, numero1*numero2);
    if (numero2 != 0)
    {
        printf("Division: %d / %d = %.2f\n", numero1, numero2, (float)numero1/numero2);
    }
    else
    {
        printf("ERROR - VALORES INVALIDOS");
    }

    int op, i, j;
    int matriz[3][3];


    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            matriz[i][j] = (rand()% 100) +1;
        }
    }

    do{
        op = msg();
        switch(op)
        {
            case 1:
            ordenar();
            break;

            case 2:
            operaciones(matriz, 3, 3);
            break;
        }
    }while(op != 3);


    
    return 0;
}

int msg()  // funcion que muestra el menu
{
    int op;
    printf("menu\n");
    printf("1) ordenar palabras\n");
    printf("2) matriz multidimensional\n");
    printf("3) terminar programa\n");
    op = validacionNumero("elige una opcion", 1, 3);
    return op;
}

void ordenar() // esta funcion ordena una lista de palabras en orden alfabetico
{
    // Inicializamos el arreglo de palabras
    char *palabras[] = {"manzana", "banana", "cereza", "uva", "naranja"};
    // obtenemos el tamanio del vector
    int tamano = sizeof(palabras) / sizeof(palabras[0]);

    // Ciclo para ordenar las palabras en orden alfabético
    for (int i = 0; i < tamano - 1; i++)
    {
        for (int j = i + 1; j < tamano; j++)
        {
            //Si la comparacion entre ambas cadenas es mayor que cero significa que
            //no estan en el orden correcto
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                // Ordenamos mediante el metodo de la burbuja
                char *temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    // Imprimir las palabras ordenadas
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", palabras[i]);
    }
}

void operaciones(int matriz[][3], int m, int n)
{
    int mayor = matriz[0][0];
    int suma = 0;
    int fila, columna;
    int *ptr = &matriz[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Sumar el elemento actual a la suma total
            suma += *ptr;

            // Comprobar si el elemento actual es mayor que el maximo encontrado hasta ahora
            if (*ptr > mayor)
            {
                mayor = *ptr;
                fila = i;
                columna = j;
            }

            // Avanzar al siguiente elemento de la matriz
            ptr++;
        }
    }
    printf("suma: %d\n", suma);
    printf("elemento mas grande: %d\n", mayor);
    printf("en la posicion: %d %d\n", fila, columna);
}