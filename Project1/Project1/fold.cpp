#include <stdio.h>


int main()
{
    int i, j = 0;
    printf("Multiplication table up to 11: \n");
    for (i = 1; i <= 11; i++)
    { 
        for (j = 1; j <= 11; j++)
        {
            printf("%d " , i * j);
        }
        printf("\n");
    }
    return 0;
}