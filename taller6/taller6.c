#include <stdio.h>
#include "ivan.h"

void apuntador(int *ptr);
void multiplicarPorDos(int *num);
void modificarVector(int vector[], int n, int *apuntarVector);

 int main()
{
    int x=4;

    int n=7, i;
    int vector[n];
    int *apuntarVector;
    apuntarVector = &vector;
    
    apuntador(&x);

    multiplicarPorDos(&x);

    printf("el = %d\n\n", x);
    vectorAleatorioSinRepetir(vector, n, 1, 50);
    for(i=0; i<n; i++)
    {
        printf("%d\n", vector[i]);
        apuntarVector++;
    }
    printf("\n");

    modificarVector(vector, n, *apuntarVector);

    for( i = 0; i<n; i++)
    {
        printf("%d\n", vector[i]);
        
    }
    return 0;
}

void apuntador(int *ptr)
{
    printf("ptr = %p\n\n", ptr);
}

void multiplicarPorDos(int *num)
{
    *num= *num * 2;
    printf("el apuntador num = %d \n", *num);
}

void modificarVector(int vector[], int n, int *apuntarVector)
{
    int sumar=7, i;

    for(i=0; i<n; i++)
    {
        apuntarVector=&vector[i];
        *apuntarVector= *apuntarVector + sumar;
    }
}