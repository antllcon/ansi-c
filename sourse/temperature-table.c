#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main() 
{
    /* Заголовок программы */
    printf("Программа вывода таблицы температур по Цельсию\n"); 
    printf("и их соответствие по шкале Фаренгейта\n\n"); 
 
    /* Оьъявление переменных */
    float fahr, celsius;
    int lower, upper, step;
    
    /* Границы и шаг */
    step = 2;
    lower = 0;
    upper = step * 7;
    
    /* Присваивание значений */
    celsius = lower;

    /* Аннотированный вывод */
    printf("Cels   Fahr\n");
    printf("-----------\n");

    /* Вычисление значений и вывод таблицы*/
    while (celsius <= upper)
    {
        fahr = celsius * 1.8 + 32.0;
        printf("%5.1f %5.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
    /* Статус программы */ 
    return SUCCESS;
}

