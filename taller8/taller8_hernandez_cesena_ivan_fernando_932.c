// taller8.c
// Hernandez Ceseña Ivan Fernando
// 08/11/2023
// este codigo compara el tiempo de iteracion de diferentes metodos de busqueda

#include "ivan.h"

int msg();
void metodo1(int *p, int m, int n);
void metodo2(int v[], int m, int n);
void metodo3(int A[][3], int m, int n);
void metodo4(int *p[], int m, int n);
void metodo5(int **q, int m, int n);

int main()  // funcion principal que controla todo el programa
{
    srand(time(NULL));
    int n, m, i, j, op, iteracion;
    n = (rand()% 15) +1;
    m = (rand()% 100) +1;
    int matriz[m][n];
    int vector[m];
    int *q[m];
    int **t = q;
    clock_t inicio, fin;
    double tiempo;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            matriz[i][j] = (rand()% 100) +1;
        }
    }

    for(i=0; i<m; i++)
    {
        vector[i] = (rand()% 100) +1;
    }

    do{
        op = msg();
        tiempo = 0;
        switch(op)
        {
            case 1:
            iteracion = validacionNumero("cuantas veces lo quieres iterar?", 1, 5000);
            for(i=0; i<iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo1(&matriz[0][0], m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

            case 2:
            iteracion = validacionNumero("cuantas veces lo quieres iterar?", 1, 5000);
            for(i=0; i<iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo2(vector, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

            case 3:
            iteracion = validacionNumero("cuantas veces lo quieres iterar?", 1, 5000);
            for(i=0; i<iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo3(matriz, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

            case 4:
            iteracion = validacionNumero("cuantas veces lo quieres iterar?", 1, 5000);
            for(i=0; i<m; i++)
            {
                q[i] = &matriz[i][0];
            }
            for(i=0; i<iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo4(q, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;

            case 5:
            iteracion = validacionNumero("cuantas veces lo quieres iterar?", 1, 5000);
            for(i=0; i<iteracion; i++)
            {
                inicio = clock();
                busquedaLineal_Metodo5(t, m, n);
                printf("\n");
                fin = clock();
                tiempo += (double)(fin - inicio) / CLOCKS_PER_SEC;
            }
            printf("tiempo de ejecucion: %f seg.", tiempo);
            printf("\n\n");
            break;
        }
    }while(op != 6);

    return 0;
}

int msg()  // funcion que muestra el menu
{
    int op;
    printf("menu\n");
    printf("1) metodo 1\n");
    printf("2) metodo 2\n");
    printf("3) metodo 3\n");
    printf("4) metodo 4\n");
    printf("5) metodo 5\n");
    printf("6) terminar programa\n");
    op = validacionNumero("elige una opcion", 1, 6);
    return op;
}

void busquedaLineal_Metodo1(int *p, int m, int n)  // funcion del metodo 1 de busqueda
{
    int i, j;
    printf("metodo 1\n");
    printf("Matriz\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", *(p+i*n+j));
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo2(int v[], int m, int n)  // funcion del metodo 2 de busqueda
{
    int i, j;
    printf("metodo 2\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", v[i*n+j]);
        }
        // printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo3(int A[][3], int m, int n)  // funcion del metodo 3 de busqueda
{
    int i, j;
    printf("metodo 3\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo4(int *p[], int m, int n)  // funcion del metodo 4 de busqueda
{
    int i, j;
    printf("metodo 4\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void busquedaLineal_Metodo5(int **q, int m, int n)  // funcion del metodo 5 de busqueda
{
    int i, j;
    printf("metodo 5\n");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}