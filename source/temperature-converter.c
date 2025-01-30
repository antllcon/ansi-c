#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define UPPER 10
#define LOWER 0
#define STEP 2

void cels_to_fahr(float cels);

int main() 
{
    printf("Программа конвертер температур     \n"); 
    printf("по Цельсию в шкалу по Фаренгейту \n\n"); 
 
    float cels;

    do
    {
        printf("Введите значение по Цельсию (float): ");
        if (scanf("%f", &cels) != 1)
        {
            printf("не уадлось считать число.\n\n");
            return ERROR;
        }
        cels_to_fahr(cels);
    }
    while (cels != EOF);

    return SUCCESS;
}

void cels_to_fahr(float cels)
{
    printf("%5.1f - температура по Фаренгейту\n\n", cels * 1.8 + 32.0);   
}