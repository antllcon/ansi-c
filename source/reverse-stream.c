#include <stdio.h>
#define SUCCESS 0
#define ERROR 1
#define MAX_LEN 4097

int get_line(char line[], int len_max_line);
void reverse_line(char line[], int len_max_line);

int main()
{
    printf("Переворот строки входного потока \n\n");
    
    int len_line;
    char line[MAX_LEN];

    while(len_line = get_line(line, MAX_LEN))
    {
        reverse_line(line, len_line);
        printf("[%s] - твоя строка наоборот (длина: %d)\n\n", line, len_line);    
    }

    if (!len_line)
    {
        printf("Вы ввели строку нулевой длины \n");
        return ERROR;
    }

    return SUCCESS;
}

int get_line(char line[], int len_max_line)
{
    int ch, i;
    i = 0;

    while ((i < len_max_line - 1) && ((ch = getchar()) != EOF) && (ch != '\n')) 
    {
        line[i] = ch;
        ++i;
    } 

    while (i - 1 >= 0 && (line[i - 1] == '\t' || line[i - 1] == ' '))
        --i;

    line[i] = '\0';

    return i;    
}

void reverse_line(char line[], int len_max_line)
{
    int i, ch;

    for(i = 0; i < len_max_line / 2; ++i)
    {
        ch = line[i];
        line[i] = line[len_max_line - 1 - i];
        line[len_max_line - 1 - i] = ch;
    }
}