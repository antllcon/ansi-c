#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main()
{
    printf("Эхо текста с отображением\n");
    printf("управляющих символов\n\n");

    /* Управляющих символов может быть больше,
       пробел не управляющий символ, но так программа выглядит
       полезнее. Мы можем посмотреть какие символы использовались */

    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\t')
            printf("\\t");
        if (ch == '\n')
            printf("\\n");
        if (ch == '\\')
            printf("\\\\");
        if (ch == ' ')
            printf("_");
        if ((ch != '\t') && (ch != '\\') && (ch != ' '))
            putchar(ch);
    }
    return SUCCESS; 
}