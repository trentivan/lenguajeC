#include <stdio.h>


int main()
{
    int num, i, j;
    int acum=0;
    printf("dame un numero positivo");
    scanf("%d", &num);

    for(i=2; i<num; i++)
    {
        acum=0;
        for(j=1; j<i; j++)
        {
            
            if(i%j==0)
            {
                acum= acum + j;
            }
        }
        if(j==acum)
        {
            printf("\n");
            printf("[%d]= ", i);
            for(int k=1; k<j; k++)
            {
                if(j%k==0)
                {
                    printf("%d + ", k);
                }
            }
            printf("\n");
        }
    }
    return 0;
}