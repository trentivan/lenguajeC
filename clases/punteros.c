#include <stdio.h>
#include <string.h>

int main()
{

    int n = 75;

    int *p = &n;

    printf("n = %d\n&n = %p\np = %p\n", n,&n,p);

    printf("&p = %p\n",&p);

    return 0;

}