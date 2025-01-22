#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main() 
{
    printf("Подсчет строк во входном потоке,\n");
    printf("для прекращения ввода нажмите ctrl + D\n\n");
    
    int countLines = 0;
    int ch;
    while ((ch = getchar()) != EOF)
        /* Строковая константа - хранится как ASCII-символ */ 
        if (ch == '\n')
            ++countLines;
    printf("Всего %d строк\n", countLines);

    return SUCCESS;
}