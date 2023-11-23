/* nombre del archivo: hernandez_cesena_ivan_fernando
   autor: hernandez cesena ivan fernando
   fecha de creacion: 22/11/23
   descripcion: este codigo crea un inventario con un struct
   se realizzan varias operaciones con este inventario.
*/

#include "ivan.h"

#define N 3 // tamano del inventario

typedef struct producto{
    int status;
    char nombre[30];
    int cantidad;
    int precio;
} Tprod;

void msg() // eesta funcion muestra el menu en pantalla
{
    printf("MENU\n");
    printf("1) agregar elementos\n");
    printf("2) retirar elementos\n");
    printf("3) mostrar inventario\n");
    printf("4) calcular valor total del inventario\n");
    printf("5) salir\n");
}

void agregar(Tprod inv[], int i) // esta funcion agrega productos en el inventario
{
    char temp[30];  // variable temporal para escribir el nombre del producto

    validacionTexto("dame el nombre del producto", temp, 30);
    strcpy(inv[i].nombre, temp);
    inv[i].cantidad = validacionNumero("dame la cantidad a agregar", 1, 100);
    inv[i].precio = validacionNumero("dame el precio de una unidad", 1, 100000);
    inv[i].status = 1;
}

int eliminar(Tprod inv[], int i) // esta funcion elimina productos del inventario
{
    int j; // indice
    char prod[30];
    validacionTexto("dame el producto a eliminar", prod, 30);
    for(j=0; j<i; j++)
    {
        if(!(strcmp(prod, inv[j].nombre)))
        {
            inv[j].status = 0;
            return j;
        }
    }
    return -1;
}

void mostrar(Tprod inv[], int posicion) // esta funcion imprime el inventario en pantalla
{
    int i; // indice

    for(i=0; i<posicion; i++)
    {
        if(inv[i].status == 1)
        {
            printf("%30s %7d %8d\n", inv[i].nombre, inv[i].cantidad, inv[i].precio);
        }
    }
}

void calcularValor(Tprod inv[], int posicion) // esta funcion calcula el valor de todos los productos en el inventario
{
    int i, suma=0; // indice, variable para almacenar el valor total del inventario

    for(i=0; i<posicion; i++)
    {
        if(inv[i].status == 1)
        {
            suma = suma + (inv[i].cantidad * inv[i].precio);
        }
    }
    printf("valor total: %d\n", suma);
}

void menu()  // esta funcion controla todo el programa
{
    int op, posicion, eli; // opcion, posicion del registro, variable para saber si el producto a eliminar existe
    Tprod inv[N]; // declaracion del registro de inventario
    

    do
    {
        msg();
        op = validacionNumero("elije una opcion", 1, 5);

        switch(op)
        {
            case 1:
            if(posicion + 1 > N)
            {
                printf("inventario lleno\n");
            }
            else
            {
                agregar(inv, posicion);
            }
            posicion++;
            break;

            case 2:
            if(posicion - 1 < 0)
            {
                printf("inventario vacio. no se puede eliminar nada.\n");
            }
            else
            {
                eli = eliminar(inv, posicion);
                if(eli != -1)
                {
                    printf("producto eliminado correctamente\n");
                }
                else
                {
                    printf("el producto no esta en el inventario\n");
                }
            }
            posicion--;
            break;

            case 3:
            mostrar(inv, posicion);
            break;

            case 4:
            calcularValor(inv, posicion);
            break;
        }

    } while (op != 5);
    
}

int main()
{
    menu();
    return 0;
}