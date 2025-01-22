#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define UPPER 10
#define LOWER 0
#define STEP 2

int main() 
{
    /* Заголовок программы */
    printf("Программа вывода таблицы температур по Цельсию\n"); 
    printf("и их соответствие по шкале Фаренгейта\n\n"); 
 
    /* Оьъявление переменной */
    float fahr;
    
    /* Аннотированный вывод */
    printf("Cels   Fahr\n");
    printf("-----------\n");

    /* Вычисление значений и вывод таблицы*/
    for (fahr = UPPER; fahr >= LOWER; fahr - STEP)
        printf("%5.1f %5.1f\n", fahr, fahr * 1.8 + 32.0);
     
    /* Статус программы */ 
    return SUCCESS;
}