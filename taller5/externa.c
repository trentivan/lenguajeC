//Nombre del archivo:   taller5.c
//Autor: Hernandez Cesena Ivan Fernando
//Fecha de creación: 30 de septiembre de 2023
//Descripción: Este archivo contiene el código principal de mi programa.

#include <stdio.h>

extern int saldo;
void modificarSaldo(void);
void restaSaldo(int cantidad);
void sumaSaldo(int cantidad);

int main()
{
    saldo = 0;

    // invocacion de la funcion
    modificarSaldo();

    printf("saldo final: %d\n", saldo);
    return 0;
}

int saldo;

void modificarSaldo()
{
    saldo += 100;
}

void restaSaldo(int cantidad)
{
    saldo -= cantidad;
}

void sumaSaldo(int cantidad)
{
    saldo += cantidad;
}