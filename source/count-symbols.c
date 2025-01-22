#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main()
{
    printf("Подсчет символов во входном потоке,\n");
    printf("для прекращения ввода нажмите ctrl + D\n\n");
    
    long count = 0;
    while (getchar() != EOF)
    {
        ++count;
    }
    
    /* аналогичный алгоритм через цикл for */
    /* for (count = 0; getchar() != EOF; ++count) */
        /* Пустой оператор */ /* ; */

    printf("\nВсего %ld символов\n", count);
    
    return SUCCESS;
}
