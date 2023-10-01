#include <stdio.h>

void menu(void);
int validar(char msge[], int li,int ls);

void automatica(void);

void estatica(void);
void registro(void);
void global(void);
void local(void);

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
        printf("3) variable estatica\n");
        printf("4) variable de registro\n");
        printf("5) global, local pi\n");
        printf("0) terminar programa\n ");
        
        op = validar("elije una opcion\n", 0, 5);

        switch(op)
        {
            case 1:
            for(int i=0; i<=10; i++)
            {
                automatica();
            }    
            break;

            case 2:
            break;

            case 3:
           for(int i=0; i<=10; i++)
            {
                estatica();
            }
            break;

            case 4:
            registro();
            break;

            case 5:
            global();
            local();
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

    for(int i=0; i<2; i++)
    {
        variableAutomatica ++;
        printf("%d ", variableAutomatica);
    }
    // esta variable se destruye al terminar esta funcion o bloque de codigo
}


void estatica()
{
    static int estatica=1;
    printf("%d ", estatica);

    // lo que sucede con la variable al salir de la funcion conserva su valor solo que no se puede usar
    // fuera de la funcion donde fue declarada

    // difiere con la automatica en que la automatica se destruye despues de terminar su funcion y la estatica mantiene su valor.
}

void registro()
{
    register int temp=1;
    int valor=1;
    temp ++;
    valor ++;
    printf("%d\n", temp);
    printf("%d\n", valor);

    // usaria una variable de registro por la rapidez en la que se accede a esta y por que no se destruye al terminar su bloque de codigo (funncion)
}

# define PI 3.14159

void global()
{
    int num = PI;
    printf("%d\n", num);
}

void local()
{
    int pi = 3.14159;
    printf("%d\n", pi);
}