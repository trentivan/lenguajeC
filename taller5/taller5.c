//Nombre del archivo:   taller5.c
//Autor: Hernandez Cesena Ivan Fernando
//Fecha de creación: 30 de septiembre de 2023
//Descripción: Este archivo contiene el código principal de mi programa.

#include <stdio.h>
//#include "archivo.h"

void menu(void);
int validar(char msge[], int li,int ls);

void automatica(void);
void externa(void);
void sumaSaldo(int cantidad);
void restaSaldo(int cantidad);

int main()
{
    menu();
}

void menu()
{
    int op;
    do
    {
        printf("MENU\n");
        printf("1) variable automatica\n");
        printf("2) variable externa\n");
        printf("0) terminar programa\n ");
        
        op = validar("elije una opcion\n", 0, 2);

        switch(op)
        {
            case 1:
            automatica();
            break;

            case 2:
            externa();
            break;
        }
        // al terminar la condicion selectiva.
        // se le pregunta al ususario si quiere elegir otra ocion o si quiere terminar el programa
       op = validar("quieres elegir otra opcion?\n1)si\n0)no\n", 0, 1);
    } while (op != 0);
}

// funcion para validar las opciones, que no se pongan otros valores fuera de las opciones dadas
int validar(char msge[], int li, int ls)
{
    int num;
    do
    {
        printf("%s", msge);
        scanf("%d",& num);
    } while (num < li || num > ls);
    
    return num;
}

void automatica()
{
    int variableAutomatica  = 10;

    for(int i=0; i<10; i++)
    {
        variableAutomatica ++;
        printf("%d", variableAutomatica);
    }
    // esta variable se destruye al terminar esta funcion o bloque de codigo
}

void externa()
{
    extern int saldo; // se extrae la variable de otro archivo. en este caso es mi "externa.c"
    sumaSaldo(100); // se suma el parametro a mi saldo en el otro archivo. saldo =100. saldo = 100 + 100.
    restaSaldo(20); // se resta el 20 a mi saldo previamente alterado.
}