//Nombre del archivo:   externa.c
//Autor: Hernandez Cesena Ivan Fernando
//Fecha de creación: 30 de septiembre de 2023
//Descripción: Este archivo contiene el código principal de mi programa.

#include <stdio.h>

int saldo = 100;



void restaSaldo(int cantidad)
{
    saldo -= cantidad;
    printf("externa.c - saldo final: %d\n", saldo);
}

void sumaSaldo(int cantidad)
{
    saldo = 100;
    saldo += cantidad;
    printf("externa.c - saldo final: %d\n", saldo);
}