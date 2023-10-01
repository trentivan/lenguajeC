//Nombre del archivo:   practica5.c
//Autor: Hernandez Cesena Ivan Fernando
//Fecha de creación: 30 de septiembre de 2023
//Descripción: Este archivo contiene el código principal de mi programa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
int msg(void);
int validar(char msge[], int li,int ls);

int generarNumeroLoteria(void);
void loteria(void);
void carrera(void);
void iniciarCarrera(void);

int main() // la funcion principal. 
{
    menu(); //manda a llamar a menu que es quien controla el codigo
}

int msg() // funcion que muestra menajes y retorna la opcion elegida
{
    int op;
    printf("MENU\n");
    printf("1) loteria\n");
    printf("2) carrera de coches\n");
    printf("0) terminar programa\n ");
    
    op = validar("elije una opcion\n", 0, 2);
    return op;
}

// esta es la funcion menu que controla las opciones elegidas
void menu()
{
    int op;
    do
    {
        op = msg();
        switch(op)
        {
            case 1:
            loteria();
            break;

            case 2:
            iniciarCarrera();
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

// funcion loteria
// aqui se genera el numero ganador 
// se llama a la funcion que genera el numero para ver si el usuario gano o perdio
//se comparan los dos numeros. si son iguales gana el usuario
void loteria()
{
    int num;
    static int numeroGanador = 4;
    num = generarNumeroLoteria();

    printf("%d\n", num);
    
    if(num == numeroGanador)
    {
        printf("felicidades, ganaste la loteria\n");
    }
    else
    {
        printf("lo siento no ganaste esta vez\n");
    }
}

// esta funcion es la que genera el numero ganador
int generarNumeroLoteria()
{
    int n;
    srand(time(NULL));
    n = (rand()% 100) + 1;

    return n;
}

// funcion de la carrera
//se genera aleatoriamente la velocidad de los 3 carros
// se calcula el tiempo de recorrido de la carrera en segundos (2000 metros) 

void iniciarCarrera()
{
    srand(time(NULL));

    register int coche1 = rand()%100 +1; // velocidad del coche 1
    register int coche2 = rand()%100 +1; // velocidad del coche 2
    register int coche3 = rand()%100 +1; // velocidad del coche 3

    printf("el coche que llego primero a la meta en una distancia de 2000 metros\nes:\n");
    int tiempo1= 2000 / coche1; // tiempos
    int tiempo2= 2000 / coche2;
    int tiempo3= 2000 / coche3;

    if(coche1 > coche2)
    {
        if(coche2 > coche3)
        {
            
            printf("resultados\n");
            printf("1- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d\n",coche1, tiempo1);
            printf("2- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d\n",coche2, tiempo2);
            printf("3- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d\n",coche3, tiempo3);
        }
        else
        {
            if(coche1 > coche3)
            {
                printf("resultados\n");
                printf("1- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche1, tiempo1);
                printf("2- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche3, tiempo3);
                printf("3- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche2, tiempo2);
            }
            else
            {
                printf("resultados\n");
                printf("1- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche3, tiempo3);
                printf("2- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche1, tiempo1);
                printf("3- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche2, tiempo2);
            }
        }
    }
    else
    {
        if(coche1 > coche3)
        {
            printf("resultados\n");
            printf("1- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche2, tiempo2);
            printf("2- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche1, tiempo1);
            printf("3- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche3, tiempo3);
        }
        else
        {
            if(coche2 > coche3)
            {
                printf("resultados\n");
                printf("1- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche2, tiempo2);
                printf("2- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche3, tiempo3);
                printf("3- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche1, tiempo1);
            }
            else
            {
                printf("resultados\n");
                printf("1- coche 3\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche3, tiempo3);
                printf("2- coche 2\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche2, tiempo2);
                printf("3- coche 1\n\tvelocidad= %d km/h\n\ttiempo de llegada= %d segundos\n",coche1, tiempo1);
            }
            
        }
    }
}