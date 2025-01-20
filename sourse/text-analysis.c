#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main()
{
    printf("Анализ текста - подсчет свойств,\n");
    printf("для прекращения ввода нажмите ctrl + D\n\n");

    int ch;
    /* Именуем переменные в snake_case */ 
    long char_count = 0;
    long blank_count = 0;
    long tab_count = 0;
    long line_count = 1;
    
    while ((ch = getchar()) != EOF)
    {
        ++char_count;
        if (ch == ' ')
            ++blank_count;
        if (ch == '\t')
            ++tab_count;
        if (ch == '\n')
            ++line_count;
    }

    if (!char_count) 
        line_count = 0;

    printf("\nРезультат подсчета:\n");
    printf("%ld - пробелов\n", blank_count);
    printf("%ld - табов\n", tab_count);
    printf("%ld - строк\n", line_count);

    return SUCCESS;
}