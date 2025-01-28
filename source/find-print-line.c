#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

/* Интересное число, почему именно такое? */
/* Подумай :с */
#define MAX_LINE 4097

/* Все функции в языке C работают со аргументами
   которые пердаются по значению (смысловое исключение - указатели)
   Но массивы по природе при передаче в фунции вырождаются в
   указатели, так как имя массива - его адрес в памяти */

int get_line(char line[], int max_line);
void copy_line(char to[], char from[]);

int main()
{
    printf("Вывод самой длинной строки \n");
    printf("из входного потока       \n\n");

    int max_len;
    int len_line;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max_len = 0;
    while ((len_line = get_line(line, MAX_LINE)) > 0)
        if (len_line > max_len)
        {
            max_len = len_line;
            copy_line(longest, line);
        }

    if (max_len > 0)
        printf("\nСамая длинная строка (%d сим.):\n%s\n", max_len - 1, longest);
    
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

/* Копируем один массив в другой */ 
void copy_line(char to[], char from[])
{
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}