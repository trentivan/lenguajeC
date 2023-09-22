

#include <stdio.h>
void menu(void);
void fibonacci(void);
int fibonacci_recursiva(int n);
void fibonacciR(void);
void trianguloPascal(void);
int Binomial(int n, int k);
int reintentar(void);

int main()
{
    menu();
    return 0;   
}

void menu()
{
    int op;
    do{
        printf("MENU\n");
        printf("1) fibonacci sin recursion\n");
        printf("2) fibonacci recursivo\n");
        printf("3) triangulo de pascal\n");
        scanf("%d",& op);

        switch(op)
        {
            case 1:
            fibonacci();
            break;

            case 2:
            fibonacciR();
            break;

            case 3:
            trianguloPascal();
        }
        op=reintentar();
    }while(op != 0);
}

void fibonacci()
{
    int repetir, anterior=-1, siguiente=1, resultado;
    printf("cuantas veces quieres que se realice el programa?\n");
    scanf("%d",& repetir);

    for (int i = 0; i <= repetir; i++)
    {
        // printf("%d ", anterior);
        resultado = siguiente + anterior;
        anterior = siguiente;
        siguiente = resultado;
    }
    printf("%d ", siguiente);
    // reintentar();
}

void fibonacciR()
{
    int numero, resultado;

    printf("dame el numero de veces que quieres repetir fibonacci:\n");
    scanf("%d",& numero);
    resultado =fibonacci_recursiva(numero);
    printf("%d\n", resultado);
    // reintentar();
}

int reintentar()
{
    int op;
    printf("quieres calcular otro termino?\n");
    printf("1) si.\n0) no.\n");
    scanf("%d",& op); 
    
    return op;
}

int fibonacci_recursiva(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fibonacci_recursiva(n-1) + fibonacci_recursiva(n-2);
    }
    // return 0;
}


// Función para calcular el coeficiente binomial C(n, k)
int Binomial(int n, int k) 
{
    if (k == 0 || k == n) 
    {
        return 1; // Caso base: C(n, 0) y C(n, n) siempre son 1
    } 
    else 
    {
        // Fórmula recursiva para calcular C(n, k)
        return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
    }
}

void trianguloPascal() 
{
    int n;
    printf("Ingrese el numero de filas para el Triangulo de Pascal:\n");
    scanf("%d", &n);

    // Bucle externo para las filas del Triángulo de Pascal
    for (int i = 0; i < n; i++) 
    {
        // Bucle interno para imprimir los coeficientes en una fila
        for (int j = 0; j <= i; j++) 
        {
            // Llama a la función para calcular el coeficiente binomial y lo imprime
            printf("%d ", Binomial(i, j));
        }
        printf("\n"); // Imprime un salto de línea al final de cada fila
    }
    // reintentar();
}
  //fin del codigo
void trianguloPascal() 
{
    int n;
    printf("Ingrese el numero de filas para el Triangulo de Pascal:\n");
    scanf("%d", &n);

    // Bucle externo para las filas del Triángulo de Pascal
    for (int i = 0; i < n; i++) 
    {
        // Bucle interno para imprimir los coeficientes en una fila
        for (int j = 0; j <= i; j++) 
        {
            // Llama a la función para calcular el coeficiente binomial y lo imprime
            printf("%d ", Binomial(i, j));
        }
        printf("\n"); // Imprime un salto de línea al final de cada fila
    }
    // reintentar();
}