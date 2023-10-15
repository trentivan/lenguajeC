#include <stdio.h>
#include "ivan.h"

 void apuntador(int *ptr)
 {
    // int x=2;
    // int *ptr;
    // ptr= &x;
    // printf("x = %d\n", x);
    printf("ptr = %p\n", ptr);
 }

void multiplicarPorDos(int *num)
{
    *num= *num * 2;
    printf("el apuntador num = %d \n", *num);
}

void modificarVector(int vector[], int n, int *apuntarVector)
{
    int sumar=7, i;
    apuntarVector= &vector;

    for(i=0; i<n; i++)
    {
        printf("%d", i);
        vector[*apuntarVector] = vector[*apuntarVector] + sumar;
        apuntarVector++;
    }
}

 int main()
{
    // int *numero;
    int x=4;
    // numero = &x;

    int n=7, i;
    int vector[n];
    int *apuntarVector;
    apuntarVector = &vector;
    
    apuntador(&x);
    multiplicarPorDos(&x);
    printf("el = %d\n", x);
    vectorAleatorioSinRepetir(vector, n, 1, 50);
    for(i=0; i<n; i++)
    {
        printf("%d\n", *apuntarVector);
        apuntarVector++;
    }
    printf("\n");

    
    for(i=0; i<n; i++)
    {
        modificarVector(vector, n, &apuntarVector);
        printf("%d\n", *apuntarVector);
        apuntarVector++;
    }

    return 0;
}

