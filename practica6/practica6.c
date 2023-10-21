// nombre del archivo: practica6.c
// autor: Hernandez Ceseña Ivan Fernando
// fecha creacion 20- 10- 23
// este archivo contiene el codigo principal de mi programa. la libreria contiene funciones para validar

#include "ivan.h" 

void menu(void);
int msg(void);

int sumaElementos(int *(vector), int n);
void copiarVector(int *origen, int *destino, int n);
void concatenarVector(int *arreglo1, int *arreglo2, int *arregloConcatenado, int n1, int n2);
int compararVector(int *arreglo1, int *arreglo2, int n);
int encontrarMaximo(int *arreglo, int n);

int main()
{
    menu();

    return 0;
}

int msg()  // esta funcion muestra las opciones en pantalla y guarda tu eleccion
{
    int op;
    printf("MENU\n");
    printf("1) suma de elementos del vector\n");
    printf("2) carrera de coches\n");
    printf("3) concatenar arreglos\n");
    printf("4) comparar arreglos\n");
    printf("5) encontrar valor maximo\n");
    printf("0) terminar programa\n ");
    
    op = validacionNumero("elije una opcion\n", 0, 5);
    return op;
}

void menu()  // esta funcion controla todo el programa
{
    int op;
    int n=5, suma, i;
    int vector[] = {1, 2, 3, 4, 5};
    int vector2[n];
    int vectorConcatenado[n + n];
    int iguales, maximo;

    do{
        op = msg();
        switch(op)
        {
            case 1:
            suma = sumaElementos(vector, n);
            printf("%d\n\n", suma);
            break;

            case 2:
            copiarVector(vector, vector2, n);
            for(i=0; i<n; i++)
            {
                printf("%d ", vector2[i]);
            }
            printf("\n\n");
            break;

            case 3:
            concatenarVector(vector, vector2, vectorConcatenado, n, n);

            for (int i = 0; i < n + n; i++) {
                printf("%d ", vectorConcatenado[i]);
            }
            printf("\n\n");
            break;
            case 4:
            iguales = compararVector(vector, vector2, n);
            if (iguales == 1) 
            {
                printf("Los arreglos son iguales.\n\n");
            } else 
            {
                printf("Los arreglos no son iguales.\n\n");
            }
            break;

            case 5:
            maximo = encontrarMaximo(vector,  n);
            printf("el valor maximo es: %d\n\n", maximo);
            break;

        }
    }while(op != 0);
}

int sumaElementos(int *(vector), int n)  // esta funcion suma los elementos del vector
{
    int suma = 0;
    int i;

    for(i=0; i<n; i++)
    {
        suma = suma + *(vector + i);
    }
    return suma;
}

void copiarVector(int *origen, int *destino, int n) // esta funcion copia los elementos de un vector a otro
{
    for (int i = 0; i < n; i++) 
    {
        *(destino + i) = *(origen + i);
    }
}

void concatenarVector(int *arreglo1, int *arreglo2, int *arregloConcatenado, int n1, int n2) // esta funcion concatena los elementos de dos vectores en otro nuevo
{
    for (int i = 0; i < n1; i++) 
    {
        *(arregloConcatenado + i) = *(arreglo1 + i);
    }
    for (int i = 0; i < n2; i++) 
    {
        *(arregloConcatenado + n1 + i) = *(arreglo2 + i);
    }
}

int compararVector(int *arreglo1, int *arreglo2, int n)  // esta funcion compara dos vectores y retorna valores para cuando son iguales y cuando no
{
    for (int i = 0; i < n; i++) 
    {
        if (*(arreglo1 + i) != *(arreglo2 + i)) 
        {
            return 0;
        }
    }
    return 1;
}

int encontrarMaximo(int *arreglo, int n)  // esta funcion encuentra el valor maximo de un vector y lo retorna
{
    if (n <= 0) 
    {
        return -1;
    }

    int maximo = arreglo[0];

    for (int i = 1; i < n; i++) 
    {
        if (arreglo[i] > maximo) 
        {
            maximo = arreglo[i];
        }
    }
    return maximo;
}