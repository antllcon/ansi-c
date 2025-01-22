#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

/* Состояния нахожедния каретки в слове */ 
#define IN 1
#define OUT 0


int main() 
{
    printf("Программа деления текста на строки\n");
    printf("состоящие из одного слова (ctrl + D - прекратить ввод)\n\n");

    int ch, state = OUT;
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
            state = OUT; 
        else if (state == OUT)
        {
            state = IN;
            putchar('\n');
        }

        if (state == IN)
            putchar(ch);
    }
    
    putchar('\n');
    return SUCCESS;
}