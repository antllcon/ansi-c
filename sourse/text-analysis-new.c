#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

/* Внутри и снаружи слова */ 
#define IN 1 
#define OUT 0

int main()
{
    printf("Анализ текста во входном потоке\n");
    printf("(используйте ctrl + D для прекращения ввода)\n\n");

    /* Потенциальная ошибка в программе может быть
       в не точности определения количества строк */

    int ch, state = OUT;
    long char_count = 0;
    long word_count = 0;
    long line_count = 1;

    while ((ch = getchar()) != EOF)
    {
        ++char_count;
        
        if (ch == '\n')
            ++line_count;

        if (ch == ' ' || ch == '\n' || ch == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++word_count;    
        }
    }   

    if (!char_count)
        line_count = 0;

    printf("\nРезультат анализа:\n");
    printf("%ld - символов\n", char_count);
    printf("%ld - слов\n", word_count);
    printf("%ld - строк\n", line_count);


    return SUCCESS;
}