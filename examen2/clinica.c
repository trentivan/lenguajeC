#include "ivan.h"

#define N 2500

typedef struct mascota{
    int numControl;
    char especie[30];
    char nombre[30];
    int edad;
    int sexo;
    int inicio;
} Tpets;

int almacenarDatos(Tpets reg[], int posicion, char archivoIni[], char archivoCod[], int inicio)
{
    char sexo[12];
    Tpets registro;
    FILE *fa, *fb;
    int i, temp;

    fa = fopen(archivoIni, "r");

    if(inicio == 0)
    {
        if(fa)
        {
            for(i=0; !(feof(fa)); i++)
            {
                fscanf(fa, "%d %s %s %d %s", &temp, registro.especie, registro.nombre, &registro.edad, sexo);
                if(sexo == "MACHO")
                {
                    reg[i].sexo = 1;
                }
                else
                {
                    if(sexo == "HEMBRA")
                    {
                        reg[i].sexo = 2;
                    }
                    else
                    {
                        reg[i].sexo = 3;
                    }
                }
                reg[i] = registro;
                posicion++;
            }
        }
        return posicion;
    }
    fclose(fa);

    fb = fopen(archivoCod, "w");
    if(fb)
    {
        for(i=0; !(feof(fb)); i++)
        {
            fprintf(fb, "%5d %30s %30s %4d ", i+1, reg[i].especie, reg[i].nombre, reg[i].edad);
            if(reg[i].sexo == 1)
            {
                fprintf(fb, "%12s\n", "MACHO");
            }
            else
            {
                if(reg[i].sexo == 2)
                {
                    fprintf(fb, "%12s\n", "HEMBRA");
                }
                else
                {
                    fprintf(fb, "%12s\n", "HERMAFRODITA");
                }
            }  
        }
    }
    fclose(fb);
    return posicion;
}

int msg()
{
    int op;
    printf("menu\n");
    printf("1) registrar\n");
    printf("2) historial (actualizar y mostrar\n");
    printf("3) consultar registro\n");
    printf("4) almacenar datos\n");
    printf("5) terminar programa\n");
    op = validacionNumero("elige una opcion", 1, 5);
    return op;
}

void menu(char archivoIni[])
{
    Tpets reg[N];
    int op;
    int posicion = 0;
    char almacenar[30];
    int inicio = 0;
    int cons;

    // posicion = almacenarDatos(reg, posicion, archivoIni, "nada", inicio);

    do
    {
        op = msg();
        // op = validacionNumero("elije una opcion", 1, 5);

        switch(op)
        {
            case 1:
            registrar(reg, posicion);
            posicion = posicion + 1;
            break;

            case 2:
            historial(reg, posicion);
            break;

            case 3:
            cons = consultar(reg, posicion);
            if(cons == -1)
            {
                printf("el registro no se encontro\n");
            }
            break;

            case 4:
            inicio = 1;
            validacionTexto("dame el nombre de tu archivo", almacenar, 30);
            almacenarDatos(reg, posicion, "nada", almacenar, inicio);
            break;
        }
    } while (op != 5);
    
}



void registrar(Tpets reg[], int i)
{
    char tempNom[30];
    char tempEspecie[30];
    validacionTexto("especie:", tempEspecie, 30);
    strcpy(reg[i].especie, tempEspecie);
    validacionTexto("nombre:", tempNom, 30);
    strcpy(reg[i].nombre, tempNom);

    reg[i].edad = validacionNumero("edad:", 1, 150);
    reg[i].sexo = validacionNumero("1) macho\n2)hembra\n3)hermafrodita.\nelije una opcion", 1, 3);

    reg[i].numControl = i+1;
}

void historial(Tpets reg[], int posicion)
{
    int i;

    for(i=0; i<posicion; i++)
    {
        printf("%5d %30s %30s %4d ", i+1, reg[i].especie, reg[i].nombre, reg[i].edad);
        if(reg[i].sexo == 1)
        {
            printf("%12s\n", "MACHO");
        }
        else
        {
            if(reg[i].sexo == 2)
            {
                printf("%12s\n", "HEMBRA");
            }
            else
            {
                printf("%12s\n", "HERMAFRODITA");
            }
        }
    }
}

int consultar(Tpets reg[], int posicion)
{
    int buscar, i, encontrar;

    buscar = validacionNumero("dame el numero de control:", 1, 2500);

    for(i=0; i<posicion; i++)
    {
        if(buscar == reg[i].numControl)
        {
            printf("numero de control: %d\n", reg[i].numControl);
            printf("especie: %s\n", reg[i].especie);
            printf("nombre: %s\n", reg[i].nombre);
            printf("especie: %d\n", reg[i].edad);
            printf("sexo: ");
            if(reg[i].sexo == 1)
            {
                printf("%12s\n", "MACHO");
                return i;
            }
            else
            {
                if(reg[i].sexo == 2)
                {
                    printf("%12s\n", "HEMBRA");
                    return i;
                }
                else
                {
                    printf("%12s\n", "HERMAFRODITA");
                    return i;
                }
            }
        }
    }
    return -1;
}



int main(char archivoIni[])
{
    
    menu(archivoIni);
    return 0;
}

