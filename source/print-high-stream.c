#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

#define MIN_LINE 64
#define MAX_LINE 4097

int get_line(char line[], int max_line);
void clear_line(char line[], int len_max_line);

/* Задача искуственная и очень неудобная для массивов... */

int main()
{
    printf("Вывод строк из входного потока длинной более или равной\n");
    printf("%d символам (ограничение на кол-во символов в строке - %d)\n\n", MIN_LINE, MAX_LINE - 1);

    int len_line;
    char line[MAX_LINE];

    len_line = 0;
    clear_line(line, MAX_LINE);

    printf("\n\nВведите строку: ");
    while ((len_line = get_line(line, MAX_LINE)) > 0)
    {

        if (len_line > MIN_LINE)
        {
            printf("\n%s - строка размером %d символов", line, len_line);
            clear_line(line, MAX_LINE);
            len_line = 0;
        }
        else printf("%d < %d символов", len_line, MIN_LINE);

        printf("\n\nВведите новую строку: ");
    }

    return SUCCESS;
}

/* Читаем строку в переданный нам массив
   и возвращаем их длину */ 
int get_line(char line[], int len_max_line)
{
    int ch, i;
    i = 0;

    while ((i < len_max_line - 1) && ((ch = getchar()) != EOF) && (ch != '\n')) 
    {
        line[i] = ch;
        ++i;
    }        

    if (ch == '\n')
    {
        line[i] = ch;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void clear_line(char line[], int len_max_line)
{
    int i;
    for (i = 0; i < len_max_line; ++i)
        line[i] = '\0';
}