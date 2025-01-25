#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define NUMBER_OF_DIGITS 10

int main()
{
    printf("Подсчет цифр, символов пустого пространства\n");
    printf("и чего-то там еще\n\n");

    int ch, i;
    int count_blanks;
    int count_other;
    int count_digit[NUMBER_OF_DIGITS];
    
    count_blanks = count_other = 0;
    for (i = 0; i <= 9; ++i)
        count_digit[i] = 0;

    /* Идея работы с массивом в вычислении номера цифры,
       это и номер элемента массива, и его значение */

    /* Не очень красивая конструкция else-if
       позволяет нам делать многовариантное 
       сравнение без написания грромоздких 
       однотипных условий - будущая 
       альтернатива switch */

    /* Выяснить правила форматирования кода,
       задача описана в дополнительных вопросах */

    while ((ch = getchar()) != EOF)
        
        if (ch >= '0' && ch <= '9')
            ++count_digit[ch - '0'];
        else if (ch == ' ' || ch == '\n' || ch == '\t')
            ++count_blanks;
        else
            ++count_other;

    printf("\nРезультаты подсчета:\n");
    printf("==================\n");
    printf("| Цифра | Кол-во |\n");
    printf("==================\n");
    for (i = 0; i <= 9; ++i)
        printf("| %5d | %6d |\n", i, count_digit[i]);
    printf("==================\n");
    printf("%d - кол-во пробельных символов\n", count_blanks);
    printf("%d - остальные символы\n", count_other);

    return SUCCESS;
}