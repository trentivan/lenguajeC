



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(void);
int msg(void);
int validar(char msge[], int li,int ls);

int generarNumeroLoteria(void);
void loteria(void);
void carrera(void);
int iniciarCarrera(void);

int main()
{
    menu();
}

int msg()
{
    int op;
    printf("MENU\n");
    printf("1) loteria\n");
    printf("2) carrera de coches\n");
    printf("0) terminar programa\n ");
    
    op = validar("elije una opcion", 0, 2);
}

void menu(void)
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
            carrera();
            break;
        }
       op = validar("quieres elegir otra opcion?\n1)si\n0)no", 0, 1);
    } while (op != 0);
    
}

int validar(char msge[], int li, int ls)
{
    int num;
    do
    {
        printf("%s", msge);
        scanf("%d", num);
    } while (num < li || num > ls);
    
    return num;
}

void loteria()
{
    int num;
    static int numeroGanador = 4;
    num = generarNumeroLoteria();

    printf("%d", num);
    if(num == numeroGanador)
    {
        printf("felicidades, ganaste la loteria\n");
    }
    else
    {
        printf("lo siento no ganaste esta vez\n");
    }
    return 0;
}

int generarNumeroLoteria()
{
    int n;
    srand(time(NULL));
    n = (rand()% 100) + 1;

    return n;
}

void carrera()
{

}

int iniciarCarrera()
{
    srand(time(NULL));

    register int coche1 = rand()%100 +1;
    register int coche2 = rand()%100 +1;
    register int coche3 = rand()%100 +1;

    printf("el coche que llego primero a la meta en una distancia de 2000 metros\nes:\n");
    int tiempo1= coche1 / 2000;
    int tiempo2= coche2 / 2000;
    int tiempo3= coche3 / 2000;

    if(coche1 > coche2)
    {
        if(coche2 > coche3)
        {
            
            printf("resultados\n");
            printf("1- coche 1\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
            printf("2- coche 2\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche2, tiempo2);
            printf("3- coche 3\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche3, tiempo3);
        }
        else
        {
            printf("resultados\n");
            printf("1- coche 1\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
            printf("2- coche 3\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche3, tiempo3);
            printf("3- coche 2\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche2, tiempo2);
        }
        
        else
        {
            printf("resultados\n");
            printf("1- coche 3\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche3, tiempo3);
            printf("2- coche 2\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche2, tiempo2);
            printf("3- coche 1\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
        }
    }
    else
    {
        if(coche1 > coche3)
        {
            printf("resultados\n");
            printf("1- coche 2\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche2, tiempo2);
            printf("2- coche 1\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
            printf("3- coche 3\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche3, tiempo3);
        }
        else
        {
            printf("resultados\n");
            printf("1- coche 2\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
            printf("2- coche 3\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche3, tiempo3);
            printf("3- coche 1\n\tvelocidad= %d\n\ttiempo de llegada= %d",coche1, tiempo1);
            
        }
    }
}