

#include "ivan.h"

int msg();
void ordenar(char *palabras[5]);
void operaciones(int matriz[][3], int m, int n);

int main(int argc, char *argv[]) {

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
    char palabras[10][5] = ("manzana", "banana", "cereza", "uva", "naranja");


    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            matriz[i][j] = (rand()% 100) +1;
        }
    }
    op = msg();
    do{
        switch(op)
        {
            case 1:
            ordenar(&palabras);
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

void ordenar(char *palabras[5]) // esta funcion ordena una lista de palabras en orden alfabetico
{
    int i, j, num=10;
    char temp[5];
    char buffer[10];
    for(i=0; i<num; i++)
    {
        palabras[i] = (char *)malloc(10);
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

void operaciones(int matriz[][3], int m, int n)
{
    int mayor = matriz[0][0];
    int suma = 0;
    int fila, columna;
    int *ptr = &matriz[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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
    printf("");
    printf("");
}

// int sumaElementos(int *(vector), int m, int n)  // esta funcion suma los elementos del vector
// {
//     int suma = 0;
//     int i;

//     for(i=0; i<n; i++)
//     {
//         suma = suma + *(vector + i);
//     }
//     return suma;
// }

// int encontrarMaximo(int *arreglo[], int n)  // esta funcion encuentra el valor maximo de un vector y lo retorna
// {
//     if (n <= 0) 
//     {
//         return -1;
//     }

//     int maximo = arreglo[0];

//     for (int i = 1; i < n; i++) 
//     {
//         if (arreglo[i] > maximo) 
//         {
//             maximo = arreglo[i];
//         }
//     }
//     return maximo;
// }