#include <stdio.h>

int main()
{
    int angka;
    int output[10];
    printf("masukkan angka : ");
    scanf("%d", &angka);
    for (size_t i = 0; i < angka; i++)
    {
        output[i] = i + 1;
    }
    printf("ouput : \n");
    for (size_t i = 0; i < angka; i++)
    {
        for (size_t i = 0; i < angka; i++)
        {
            printf("%d", output[i]);
        }
        printf("\n");
    }
}