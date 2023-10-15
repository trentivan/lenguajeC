#include <stdio.h> 

void menu(void);

int main()
{
    menu();
}

void menu()
{
    int op;

    do{
        op = msg();
        switch(op)
        {
            case 1:

            break;

            case 2:

            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;
        }
    }while(op != 0);
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